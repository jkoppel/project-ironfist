/*
* Portions of this code is from: https://github.com/vnaum/h2cdplay
* Author: Vladislav Naumov
* Descriptoin: Basic HOMM2 player
*/

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "lib/bass/bass.h"

#include "base.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "sound/sound.h"
#include "manager.h"
#include "prefs.h"
#include <iostream>

extern int gbNoSound;
extern int CDPlaying;
extern int useOpera;
extern DWORD Data; //should really be named 'musicVolume'

#define MAXTRACK 64

int currentChan = 0;
const char *trkpath = "./MUSIC";
int now_playing = 0;
int *t_savepos;               // "save position" flag
QWORD *t_position;            // saved position
float global_volume = 1.0f;
bool setup_bass = false;

signed char townTheme[MAX_FACTIONS] = { 8, 9, 5, 6, 10, 7, -1, -1, -1, -1, -1, -1, 44 };

extern void __fastcall Process1WindowsMessage();

void reset_town_saved_music_positions() {
  for (int i = 5; i < 11; i++)
    t_savepos[i] = 0;
}

bool init_bass() {
  if (HIWORD(BASS_GetVersion()) != BASSVERSION) {
    std::cerr << "An incorrect version of BASS was loaded.\n";
    return false;
  }

  if (!BASS_Init(-1, 44100, 0, 0, NULL)) {
    std::cerr << "Can't initialize device (BASS).\n";
    return false;
  }

  // initialize t_savepos / t_position, set to zero
  t_savepos = (int*)calloc(MAXTRACK, sizeof(t_savepos[0]));
  t_position = (QWORD*)calloc(MAXTRACK, sizeof(t_position[0]));

  return true;
}

void cleanup_bass() {
  reset_town_saved_music_positions();
  setup_bass = false;
  BASS_Free();
}

void bass_stop_chan(int chan) {
  if (!BASS_ChannelIsActive(chan))
    return;

  if (t_savepos[now_playing]) {
    t_position[now_playing] =
      BASS_ChannelGetPosition(chan, BASS_POS_BYTE);
  }
  // fadeout and stop
  BASS_ChannelSlideAttribute(chan, BASS_ATTRIB_VOL, -1, 200);
  while (BASS_ChannelIsSliding(chan, 0))
    Sleep(1);

  BASS_ChannelStop(chan);
  now_playing = 0;
}

void bass_set_volume(int chan, float volume) {
  global_volume = volume;
  if (BASS_ChannelIsActive(chan))
    BASS_ChannelSetAttribute(chan, BASS_ATTRIB_VOL, volume);
}

void bass_set_volume(float volume) {
  bass_set_volume(currentChan, volume);
}

void bass_play_track(int trknum) {
  char trkbuf[1024];
  trknum--;

  if (trknum < 1)
    return;

  if (trknum == now_playing)
    return; //this track is already being played

  if (!useOpera && trknum >= 4 && trknum <= 9)
    snprintf(trkbuf, sizeof(trkbuf), "%s/sw/homm2_%02d.ogg", trkpath, trknum);
  else // use opera versions for town screens
    snprintf(trkbuf, sizeof(trkbuf), "%s/homm2_%02d.ogg", trkpath, trknum);

  // preload next chan
  int next = BASS_StreamCreateFile(FALSE, trkbuf, 0, 0, BASS_STREAM_AUTOFREE);
  if (!next) {
    std::cerr << "Error while opening track #" << trknum << std::endl;
    return;
  }

  // check length
  QWORD pos = BASS_ChannelGetLength(next, BASS_POS_BYTE);
  int next_len = -1;
  if (pos != -1)
    next_len = static_cast<int>(BASS_ChannelBytes2Seconds(next, pos));

  // "jingle"? play it and forget it
  if (next_len <= 10) {
    BASS_ChannelPlay(next, FALSE);
    return;
  }

  // okay, it's not a jingle. do full-fledged processing (stop, restore, etc).
  bass_stop_chan(currentChan);
  currentChan = next;
  now_playing = trknum;

  // set looping (that's okay, we checked for length):
  BASS_ChannelFlags(currentChan, BASS_SAMPLE_LOOP, BASS_SAMPLE_LOOP);

  // set volume:
  BASS_ChannelSetAttribute(currentChan, BASS_ATTRIB_VOL, global_volume);

  // seek to start:
  if (t_savepos[now_playing] && t_position[now_playing] > 0) {
    if (!BASS_ChannelSetPosition(currentChan, t_position[now_playing], BASS_POS_BYTE))
      std::cerr << "Seek failed";
    else {
      // we're starting from the middle of track, do fade-in:
      BASS_ChannelSetAttribute(currentChan, BASS_ATTRIB_VOL, 0.0);
      BASS_ChannelSlideAttribute(currentChan, BASS_ATTRIB_VOL, global_volume, 2000);
    }
  }

  BASS_ChannelPlay(currentChan, FALSE);
}

void soundManager::CDStop() {
  bass_stop_chan(currentChan);
}

int soundManager::ConvertVolume(int weight, int is_music_flag) { //this does not seem to work
  int volume = this->volRelated;
  if (volume < 0 || volume > 10) {
    std::cerr << "volume out of bounds";
    return ConvertVolume_orig(weight, is_music_flag);
  }
  return ConvertVolume_orig(weight, is_music_flag);
}

void soundManager::CDStartup() {
  usingCDAudio = true;
}

void soundManager::CDShutdown() {
}

int soundManager::CDIsPlaying() {
  return (now_playing != 0);
}

void soundManager::CDSetVolume(int unknown_control_code, int unknown) {
  float volume = ((11 - Data) / 10.0f);
  if (Data == 0) {
    global_volume = 0;
    CDStop();
    return;
  }

  if (global_volume == 0 && Data == 1) { //going from 'Off' to 'On' 
    bass_set_volume(volume);
    bass_play_track(currentTrack);
    return;
  }

  bass_set_volume(volume);
}

void soundManager::CDPlay(int track_number, signed int a3, int a4, int a5) {
  CDSetVolume(0, 0);
  if (!setup_bass) {
    init_bass();
    setup_bass = true;
  }

  if (!gbNoSound && this->usingCDAudio) {
    if (track_number == -1) {
      soundManager::CDStop();
    } else if (this->currentTrack != track_number || !CDPlaying || a5) {
      Process1WindowsMessage();
      soundManager::ServiceSound();
      this->field_694 = track_number;
      this->field_698 = a4;

      bass_play_track(track_number);
      t_savepos[track_number] = 1;

      Process1WindowsMessage();
      soundManager::ServiceSound();
      if (this->volRelated <= 0) {
        if (a4 != -1) {
          soundManager::CDSetVolume(-1, 0);
        }
      } else {
        this->volRelated = 10;
        int volume = soundManager::ConvertVolume(1, 101);
        soundManager::CDSetVolume(volume, 1);
      }
      this->currentTrack = track_number;
    }
  }
}

int soundManager::Open(int foo) {
  const DWORD volume = read_pref<DWORD>("Sound Volume");
  const int origResult = Open_orig(foo);

  // The original code works on OS earlier than Windows 10.
  if (hdidriver) {
    return origResult;
  }
  
  // The following does the same thing the original sound initialization code
  // did. But for some reason it works here when it didn't before.
  const int useWaveout = 15;
  AIL_set_preference(useWaveout, 0);

  WAVEFORMATEX fmt;
  fmt.wFormatTag = WAVE_FORMAT_PCM;
  fmt.nChannels = 1;
  fmt.nSamplesPerSec = 22050;
  fmt.nAvgBytesPerSec = fmt.nSamplesPerSec;
  fmt.nBlockAlign = 1;
  fmt.wBitsPerSample = 8;
  fmt.cbSize = 0;
  HDIGDRIVER driver = 0;
  const int status = AIL_waveOutOpen(&driver, 0, 0, &fmt);
  if (status == 0) {
    hdidriver = driver;
    AllocateSampleHandles();
  } else {
    std::string msg = "{Sound Error}\n\n";
    msg += AIL_last_error();
    H2MessageBox(msg);
  }

  if (volume > 0 && volume <= 10) {
    const int soundEffectsVol0 = 40028;
    HandleAppSpecificMenuCommands(soundEffectsVol0 + volume);
  }

  return origResult;
}
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
#include "sound/sound.h"
#include "manager.h"
#include <iostream>

extern BOOL gbNoSound;
extern BOOL CDPlaying;
extern int useOpera;
#define MAXTRACK 64
HANDLE evt[MAXTRACK];

DWORD chan = 0;
char *trkpath = "./tracks";
int now_playing = 0;
int *t_savepos;               // "save position" flag
QWORD *t_position;            // saved position
float global_volume = 1.0f;

bool actually_use_opera = true; //this is a hack, need a better way to implement this

extern void __fastcall Process1WindowsMessage();

void reset_town_saved_music_positions();


//SystemOptionsHandler is called when the 'System Options' dialog is shown/interacted with
//
//int __fastcall SystemOptionsHandler_orig(struct tag_message &msg);
//int __fastcall SystemOptionsHandler(struct tag_message &msg)
//	{
//
//	//this is a hack to get the 'useOpera' setting to do something different
//	//if(msg.xCoordOrKeycode == 12 && msg.yCoordOrFieldID == 13)
//	//	{
//	//	if(actually_use_opera == false && useOpera == true)
//	//		useOpera = false;
//
//	//	DWORD use_opera_before = useOpera;
//	//	int ret = SystemOptionsHandler_orig(msg);
//	//	DWORD use_opera_after = useOpera;
//
//	//	if(use_opera_before == false && use_opera_after == true)
//	//		actually_use_opera = true;
//
//	//	if(use_opera_before == true && use_opera_after == false)
//	//		{
//	//		actually_use_opera = false;
//	//		useOpera = true;
//	//		reset_town_saved_music_positions();
//	//		}
//
//	//	return ret;
//	//	}
//
//	int ret = SystemOptionsHandler_orig(msg);
//	return ret;
//	}

void reset_town_saved_music_positions() {
  for (int i = 5; i < 11; i++)
    t_savepos[i] = 0;
}


bool init_bass() //maybe put this in soundManager ctor? //soundManager::CDStartup(soundManager *this)
{
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

void cleanup_bass() //put in soundManager dtor? //soundManager::CDShutdown(soundManager *this)
{
  BASS_Free();
}

void bass_stop_chan(int chan) {
  // stop the track that is been playing
  if (!BASS_ChannelIsActive(chan))
    return;

  if (t_savepos[now_playing]) {
    t_position[now_playing] =
      BASS_ChannelGetPosition(chan, BASS_POS_BYTE);
    //log_str("Saved position for track #%02d (%08ld bytes)\n",
    //		now_playing, t_position[now_playing]);
  }
  // fadeout and stop
  //log_str("Stopping %02d playback...\n", now_playing);
  BASS_ChannelSlideAttribute(chan, BASS_ATTRIB_VOL, -1, 200);
  while (BASS_ChannelIsSliding(chan, 0))
    Sleep(1);
  //usleep(100);

  BASS_ChannelStop(chan);
  now_playing = 0;
}

void bass_set_volume(int chan, float volume) {
  global_volume = volume;
  if (BASS_ChannelIsActive(chan))
    BASS_ChannelSetAttribute(chan, BASS_ATTRIB_VOL, volume);
}

void bass_set_volume(float volume) {
  bass_set_volume(chan, volume);
}

void bass_play_track(int trknum) {
  char trkbuf[1024];
  if (trknum >= 1 && trknum <= 49) {
    if (trknum == now_playing)
      return; //this track is already being played

          // preload next chan
    DWORD next = 0;
    int next_len = -1;

    if (!actually_use_opera && trknum >= 5 && trknum <= 10)  //only for the town screen
      sprintf(trkbuf, "%s/track%02d_no_opera.mp3", trkpath, trknum);
    else
      sprintf(trkbuf, "%s/track%02d.mp3", trkpath, trknum);

    next =
      BASS_StreamCreateFile(FALSE, trkbuf, 0, 0, BASS_STREAM_AUTOFREE);
    if (!next) {
      //log_str("Error while opening track #%d\n", trknum);
      return;
    }

    // check length
    {
      QWORD pos = BASS_ChannelGetLength(next, BASS_POS_BYTE);
      if (pos != -1)
        next_len = (DWORD)BASS_ChannelBytes2Seconds(next, pos);
    }
    // "jingle"? play it and forget it
    if (next_len <= 10) {
      //log_str
      //	("Track #%02d is a jingle (%d sec), playing in background\n",
      //	 trknum, next_len);
      BASS_ChannelPlay(next, FALSE);
      return;
    }

    // okay, it's not a jingle. do full-fledged processing (stop, restore, etc).
    bass_stop_chan(chan);
    chan = next;
    now_playing = trknum;


    // set looping (that's okay, we checked for length):
    BASS_ChannelFlags(chan, BASS_SAMPLE_LOOP, BASS_SAMPLE_LOOP);

    // set volume:
    BASS_ChannelSetAttribute(chan, BASS_ATTRIB_VOL, global_volume);

    // seek to start:
    if (t_savepos[now_playing] && t_position[now_playing] > 0) {
      //log_str
      //	("Playing track %s, volume = %.2f (saved position = %08ld)\n",
      //	 trkbuf, volume, t_position[now_playing]);
      if (!BASS_ChannelSetPosition
      (chan, t_position[now_playing], BASS_POS_BYTE))
        std::cerr << "Seek failed";
      else {
        // we're starting from the middle of track, do fade-in:
        BASS_ChannelSetAttribute(chan, BASS_ATTRIB_VOL, 0.0);
        BASS_ChannelSlideAttribute(chan, BASS_ATTRIB_VOL, global_volume, 2000);
      }
    } else {
      //log_str("Playing track %s, volume = %.2f\n", trkbuf, volume);
    }

    BASS_ChannelPlay(chan, FALSE);
    return;
  }
}

void soundManager::CDStop() {
  bass_stop_chan(chan);
}

int soundManager::ConvertVolume(int weight, int is_music_flag) { //this does not seem to work
  int volume = this->volRelated;
  if (volume < 0 || volume > 10) {
    std::cerr << "volume out of bounds";
    return ConvertVolume_orig(weight, is_music_flag);
  }

  return ConvertVolume_orig(weight, is_music_flag);
}

extern DWORD Data; //should really be named 'musicVolume'
extern DWORD soundVolume;
extern char aMusicVolume_0;
extern char aMusicVolume_1;

void soundManager::CDStartup() {
  usingCDAudio = true;
}

void soundManager::CDShutdown() {
}

int soundManager::CDIsPlaying() {
  return (now_playing != 0);
}

void soundManager::CDSetVolume(int unknown_control_code, int unknown) {
  //int volume = this->volRelated;

  //int a = soundVolume;
  //int b = aMusicVolume_0;
  //int c = aMusicVolume_1;
  float volume = ((11 - Data) / 10.0f);
  if (Data == 0) {
    global_volume = 0;
    CDStop();
    return;
  }

  if (global_volume == 0 && Data == 1) //going from 'Off' to 'On'
  {
    bass_set_volume(volume);
    bass_play_track(currentTrack);
    return;
  }

  bass_set_volume(volume);
}

void soundManager::CDPlay(int track_number, signed int a3, int a4, int a5) {
  int volume; // eax@20
  unsigned __int32 startmsec; // [sp+10h] [bp-18h]@14

  CDSetVolume(0, 0);

  static bool setup_bass = false;
  if (!setup_bass) {
    init_bass();
    setup_bass = true;
  }

  //if(!gbNoSound && this->field_69E && *(_DWORD *)&Data)
  if (!gbNoSound && this->usingCDAudio)//this->field_69E)// && *(_DWORD *)&Data)
  {
    if (track_number == -1) {
      soundManager::CDStop();
    } else if (this->currentTrack != track_number || !CDPlaying || a5) {
      Process1WindowsMessage();
      soundManager::ServiceSound();
      this->field_694 = track_number;
      this->field_698 = a4;

      bass_play_track(track_number);
      t_savepos[track_number] = 1;

      /*
      if(*((_BYTE *)&bSaveMusicPosition + a2))
      a3 = 1;
      soundManager::StopAllSamples(thisa, 1);
      soundManager::CDStop();
      if(!a5 && a3 && *((_DWORD *)dword_4ED0B8 + a2))
      startmsec = *((_DWORD *)dword_4ED0B8 + a2);
      else
      startmsec = *((_DWORD *)ptr + track_number);
      this->redbookStatus = AIL_redbook_play(aStatusCdPositi, startmsec, *((_DWORD *)dword_4ED0B4 + a2));
      if(thisa->redbookStatus != REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION)
      {
      DelayMilli(100);
      thisa->redbookStatus = AIL_redbook_status(aStatusCdPositi);
      if(thisa->redbookStatus != REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION)
      thisa->redbookStatus = AIL_redbook_play(aStatusCdPositi, startmsec, *((_DWORD *)dword_4ED0B4 + a2));
      }*/
      //CDPlaying = 1;
      Process1WindowsMessage();
      soundManager::ServiceSound();
      if (this->volRelated <= 0) {
        if (a4 != -1) {
          soundManager::CDSetVolume(-1, 0);
        }
      } else {
        this->volRelated = 10;
        //dword_524BF8 = KBTickCount() + 600;
        volume = soundManager::ConvertVolume(1, 101);
        soundManager::CDSetVolume(volume, 1);
      }
      this->currentTrack = track_number;
    }
  }
}
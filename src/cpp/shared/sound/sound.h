#ifndef SOUND_H
#define SOUND_H

#include "manager.h"

typedef void* HDIGDRIVER;

#pragma pack(push,1)

class soundManager : public baseManager {
public:
  int redbookStatus;
  HDIGDRIVER hdidriver;
  int field_3E;
  char _0[22];
  void * hsamples[14];  //HSAMPLE hsamples[14];
  int field_90;
  int field_94;
  int numSamplesAllocated;
  char _1[84];
  char _2[1152];
  int field_570;
  int _3;
  int field_578;
  char currentTrack;
  char _4[267];
  int aiMusicOff;
  int volRelated;
  int _5;
  int field_694;
  int field_698;
  __int16 outputDeviceID;
  int usingCDAudio;// int field_69E;
  int usingRedbookRelated;
  int field_6A6;
  float field_6AA;
  int someTick;
  soundManager();

  void SwitchAmbientMusic(int track);
  struct _SAMPLE * MemorySample(sample*);
  int CDIsPlaying();
  int CDIsPlaying_orig();
  void CDStartup();
  void CDStartup_orig();
  void CDShutdown();
  void CDShutdown_orig();
  void CDPlay(int track_number, signed int a3, int a4, int a5);
  void CDStop();
  void CDSetVolume(int, int);
  void CDSetVolume_orig(int, int);
  int ConvertVolume(int, int);
  int ConvertVolume_orig(int, int);
  void ServiceSound();
  void AllocateSampleHandles();
  int Open(int);
  int Open_orig(int);
  void PlayAmbientMusic(int,long,int);
  void AdjustSoundVolumes();
};

#pragma pack(pop)

extern soundManager *gpSoundManager;

extern unsigned char giTerrainToMusicTrack[];
extern signed char townTheme[];
extern _SAMPLE *hNewWalkSample;
extern _SAMPLE *hOldWalkSample;

extern struct SAMPLE2 __fastcall LoadPlaySample(char *);
extern void __fastcall WaitEndSample(struct SAMPLE2, int);

struct SmackTag;
struct SmackSumTag;

// Audio Interface Library calls in mss32.dll
extern "C" {
  int __stdcall AIL_get_preference(unsigned int number);
  int __stdcall AIL_set_preference(unsigned int number, int value);
  int __stdcall AIL_waveOutOpen(HDIGDRIVER *drv, void *phWaveOut, int wDeviceID, WAVEFORMATEX *pFormat);
  char * __stdcall AIL_last_error();
  
  int __stdcall SmackSummary(SmackTag*, SmackSumTag*);
  int __stdcall SmackSoundUseDirectSound(int);
  int __stdcall SmackSoundUseMSS(HDIGDRIVER);
  int __stdcall SmackToBuffer(struct SmackTag*, int, int, int, int, void*, int);
  int __stdcall SmackWait(SmackTag*);
  int __stdcall SmackClose(SmackTag*);
  SmackTag * __stdcall SmackOpen(HANDLE *SmackFile, UINT32 flags, INT32 unknown);
}

#endif
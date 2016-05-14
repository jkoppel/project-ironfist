#ifndef SOUND_H
#define SOUND_H

typedef void* HDIGDRIVER;

class soundManager
	{
	public:
		virtual int Open(int);
		virtual void Close();
		virtual int Main(tag_message&);

		baseManager *next;
		baseManager *prev;
		int type;
		int idx;
		char name[30];
		int ready;
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
		int field_69E;
		int usingRedbookRelated;
		int field_6A6;
		float field_6AA;
		int someTick;
		soundManager();

		void SwitchAmbientMusic(int track);
		void CDPlay(int track_number, signed int a3, int a4, int a5);
		void CDStop();
		void CDSetVolume(int, int);
		void CDSetVolume_orig(int, int);
		int ConvertVolume(int, int);
		int ConvertVolume_orig(int, int);
		void ServiceSound();
	};

extern soundManager *gpSoundManager;

extern unsigned char giTerrainToMusicTrack[];

#endif
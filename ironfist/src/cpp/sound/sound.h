#ifndef SOUND_H
#define SOUND_H


class soundManager {
public:
	char _[1714];
	soundManager();

	void SwitchAmbientMusic(int track);
	sample* MemorySample(sample*);
	
};

extern soundManager *gpSoundManager;

extern unsigned char giTerrainToMusicTrack[];

#endif
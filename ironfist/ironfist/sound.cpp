#include "sound/sound.h"
#include "resource/resources.h"
#include "resource/resourceManager.h"

//void __thiscall WaitEndSample(void *this, resource *res, HSAMPLE samp)
extern void __fastcall WaitEndSample_orig(SAMPLE2 res, int samp);
void __fastcall WaitEndSample(SAMPLE2 res, int samp)
	{
	return WaitEndSample_orig(res, samp);
	//void *delaya; // [sp+Ch] [bp-8h]@1
	//int v4; // [sp+10h] [bp-4h]@3

	//delaya = this;
	//if((signed int)this < 0)
	//	delaya = (void *)4000;
	//v4 = (int)((char *)delaya + KBTickCount());
	//if(samp)
	//	{
	//	while(soundManager::DigitalReport((soundManager *)gpSoundManager, samp, 4) && KBTickCount() < v4)
	//		{
	//		Process1WindowsMessage();
	//		PollSound();
	//		}
	//	}


	//if(res)
	//	resourceManager::Dispose(gpResourceManager, res);

	if(res.file)
		gpResourceManager->Dispose(res.file);
	}
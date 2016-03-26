#include "base.h"
#include "game/game.h"

//adding a call to Sleep() during event processing will reduce excessive cpu usage
//on my machine, 10ms seems to reduce cpu load to <1% while not having any effect
//on the speed/responsiveness of the game

const int SLEEP_DURATION = 10;

void __fastcall Process1WindowsMessage_orig();
void __fastcall Process1WindowsMessage()
	{
	Sleep(SLEEP_DURATION);
	Process1WindowsMessage_orig();
	}

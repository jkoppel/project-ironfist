#include "base.h"
#include "game/game.h"
#include "prefs.h"

//adding a call to Sleep() during event processing will reduce excessive cpu usage
//on CyberPhreak's machine, 10ms seems to reduce cpu load to <1% while not having any effect
//on the speed/responsiveness of the game

static const int MAX_SLEEP_VALUE = 1000; //sanity check

void __fastcall Process1WindowsMessage_orig();
void __fastcall Process1WindowsMessage() {
  static int SLEEP_DURATION = read_pref<DWORD>("Sleep Event Loop");

  if (SLEEP_DURATION >= 0 && SLEEP_DURATION <= MAX_SLEEP_VALUE) {
    Sleep(SLEEP_DURATION);
  }

  Process1WindowsMessage_orig();
}



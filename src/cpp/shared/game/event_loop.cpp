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

/*
 * This is a slightly hacky fix to the bug described in https://www.celestialheavens.com/forum/7/16792 ,
 * where a signed overflow of GetTickCount() can cause the game to wait for up to 25 days
 * 
 * My preferred fix would involve eliminating all calls to DelayTilMilli to use DelayTil instead,
 * as DelayTilMilli can't be sure that you don't really want to wait for 25 days. However, properly
 * using unsigned ints here means that, in the event that a caller of DelayTilMilli inadvertently passes
 * in a very small number, it will never wait for very long.
 */
void __fastcall DelayTilMilli(long tick) {
  const unsigned long uTick = static_cast<unsigned long>(tick);
  while (static_cast<unsigned long>(KBTickCount()) < uTick) {
    Process1WindowsMessage();
    PollSound();
  }
}
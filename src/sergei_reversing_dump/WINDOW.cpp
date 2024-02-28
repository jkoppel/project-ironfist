#include "../../include2023/patcher_x86.hpp"
#include "../../include2023/gui.h"
#include "../../include2023/managers.h"
#include "../../include2023/map.h"
#include "../../include2023/game.h"
#include "../../include2023/combat.h"

#include <math.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

extern SWinSetup gWinSetup[73];

heroWindow* heroWindow_heroWindow(heroWindow* ecx0, int xOff, int yOff, char* filnam)
{
  heroWindow* heroWindow_1;
  return heroWindow_1;
 
}

int heroWindow_BroadcastMessage(heroWindow* hw, tag_message *evt)
{

  return 1;
}

void heroWindowManager_DoDialog(heroWindowManager* hwm, heroWindow* window, int (*a3)(tag_message *), int a4)
{
	
}

void SetWinText(heroWindow* window, int screenIdx)
{
  int numAffected = 0;
  GUIMessage evt;
  for(int  i = 0; i < 73; i++)
  {
    if(gWinSetup[i].screenIdx == screenIdx)
    {
      ++numAffected;
      evt.eventCode = INPUT_GUI_MESSAGE_CODE;
      evt.messageType = GUI_MESSAGE_SET_TEXT;
      evt.fieldID = gWinSetup[i].fieldID;
      evt.payload = gWinSetup[i].label;
      heroWindow_BroadcastMessage(window, (tag_message*)&evt);
    }
  }
}

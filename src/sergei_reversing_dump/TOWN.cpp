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

void town_CalcNumLevelArchers(town* town_1, int* numArchers, int* attack)
{

}

void town_GiveSpells(town* town_1, hero* captain)
{

}

int town_HasGarrison(town* town_1)
{
  for(int i = 0; i < 5; i++)
  {
    if(town_1->garrison.creatureTypes[i] != -1)
      return 1;
  }
  return 0;
}

bool CanBuild(town* castle, int buildingCode)
{

  return true;
}

signed int CanBuy(town* a1, int a2)
{

  return 1;
}

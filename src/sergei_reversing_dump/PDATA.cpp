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

extern game* gpGame;

int playerData_BuildingsOwned(playerData* plData, int faction, int building, int magicGuildLevel)
{
  int nBuildings = 0;
  for(int i = 0; i < plData->numCastles; i++)
  {
    if(building < BUILDING_DWELLING_1 || gpGame->castles[plData->castlesOwned[i]].factionID == faction)
    {
      if(building)
      {
        if((1 << building) & gpGame->castles[plData->castlesOwned[i]].buildingsBuiltFlags )
          ++nBuildings;
      }
      else if(gpGame->castles[plData->castlesOwned[i]].buildingsBuiltFlags & 1)
      {
        if(gpGame->castles[plData->castlesOwned[i]].mageGuildLevel == magicGuildLevel)
          ++nBuildings;
      }
    }
  }
  return nBuildings;
}

int playerData_HasMobileHero(playerData* pd)
{

  return 1;
}

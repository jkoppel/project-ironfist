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

int hero_HasSpell(hero* hero_1, int spell)
{
	// здесь должен быть код
	
	return 1;
}

int hero_HasArtifact(hero* hero_1, int artifact)
{
    // здесь должен быть код

	return 1;
}

char hero_Stats(hero* hero_1, int skill)
{
	char x;

	return x;
}

char hero_GetSSLevel(hero* hero_1, int secondary_skill)
{
	// здесь должен быть код

	return 1;
}

town* hero_GetOccupiedTown(hero* hero_1)
{
	town* town_1;

	return town_1;
}

void hero_CheckLevel(hero* hero_1)
{
	// здесь должен быть код

}

int hero_ApplyBattleWinTemps(hero* hero_1)
{
	int x;
	// здесь должен быть код

	return x;
}

int hero_ApplyBattleLossTemps(hero* hero_1)
{
	int x;
	// здесь должен быть код

	return x;
}

void hero_UseSpell(hero* hero_1, int spell)
{

}

int hero_NumArtifacts(hero* hero_1)
{
  int numArtifacts = 0;
  for(int i = 0; i < MAX_HERO_ARTIFACTS; i++)
  {
    if(hero_1->artifacts[i] >= 0)
      ++numArtifacts;
  }
  return numArtifacts;
}

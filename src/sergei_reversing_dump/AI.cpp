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

extern bool* gaiEnemyHeroReachable;
extern short* gaiLiveChanceOfPos;
extern short* gaiHeroStrategicRVOfPos;
extern short* gaiHeroEventStratRVOfPos;
extern char* gaiTurnValueOfMine;
extern int gaiHeroLiveChance[54];
extern searchArray SVSearchArray;
extern int MAP_HEIGHT;
extern int MAP_WIDTH;
extern game* gpGame;

void searchArray_Init(searchArray* sa);
void searchArray_Close(searchArray* sa);

void CloseAIMapVars()
{
  if( gaiLiveChanceOfPos)
    free(gaiLiveChanceOfPos);
  if(gaiHeroStrategicRVOfPos)
    free(gaiHeroStrategicRVOfPos);
  if(gaiHeroEventStratRVOfPos)
    free(gaiHeroEventStratRVOfPos);
  if(gaiTurnValueOfMine)
    free(gaiTurnValueOfMine);
  if(gaiEnemyHeroReachable)
    free(gaiEnemyHeroReachable);
  gaiLiveChanceOfPos = 0;
  gaiHeroStrategicRVOfPos = 0;
  gaiHeroEventStratRVOfPos = 0;
  gaiTurnValueOfMine = 0;
  gaiEnemyHeroReachable = 0;
  searchArray_Close(&SVSearchArray);
}

void InitAIMapVars()
{
  CloseAIMapVars();
  searchArray_Init(&SVSearchArray);
  gaiLiveChanceOfPos = (short*)(malloc(2 * MAP_HEIGHT * MAP_WIDTH));
  gaiHeroStrategicRVOfPos = (short*)(malloc(2 * MAP_HEIGHT * MAP_WIDTH));
  gaiHeroEventStratRVOfPos = (short*)(malloc(2 * MAP_HEIGHT * MAP_WIDTH));
  gaiTurnValueOfMine = (char*)(malloc(MAP_HEIGHT * MAP_WIDTH));
  gaiEnemyHeroReachable = (bool*)(malloc(MAP_HEIGHT * MAP_WIDTH));

}

void ResetHeroRVs(int a1, int x, int y)
{
  int incompleteMapCalculation = a1;
  int yDist;

  if(x != -1 && y != -1)
  {
    for(int i = 0; i < MAP_WIDTH; i++)
    {
      for(int j = 0; j < MAP_HEIGHT; j++)
      {
        if(incompleteMapCalculation)
        {
          yDist = abs(y - j);
          if(abs(x - i) + yDist < 10)
            gaiHeroStrategicRVOfPos[i + MAP_WIDTH * j] = -32001;
        }
        else
        {
		  gaiHeroStrategicRVOfPos[i + MAP_WIDTH * j] = -32001;
		  gaiHeroEventStratRVOfPos[i + MAP_WIDTH * j] = -32001;
        }
      }
    }
    gaiHeroEventStratRVOfPos[x + y * MAP_WIDTH] = -32001;
    for(int k = 0; k < 54; k++)
    {
      if(incompleteMapCalculation)
      {
        yDist = abs(y - gpGame->heroes[k].x);
        if(abs(x - gpGame->heroes[k].x) + yDist >= 10)
          continue;
      }
      gaiHeroLiveChance[k] = -32001;
    }
  }
}


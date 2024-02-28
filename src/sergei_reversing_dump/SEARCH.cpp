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

extern int MAP_WIDTH;
extern int MAP_HEIGHT;
extern char normalDirTable[32];
extern game* gpGame;
extern advManager* gpAdvManager;
extern int giCurPlayer;
extern char giCurPlayerBit;
extern bool gbHumanPlayer[6];
extern char *mapRevealed;
extern int giFullySeeded;
extern int giSeedingValid;
extern int giCurTempMobility;
extern char giGroundToTerrain[32 * 8];
extern playerData* gpCurPlayer;
extern int giTerrainCost[80];
extern bool bIsMoatSlowed[116];
extern combatManager* gpCombatManager;
extern unsigned char moatHexIdxInRow[9];

char StopOnTrigger(mapCell* cell);
mapCell* advManager_GetCell(advManager* am, int col, int row);
BOOL advManager_FindAdjacentMonster(advManager* advM, int xPoint, int yPoint, int* xMonster, int* yMonster, int xUnwanted, int yUnwanted);
bool ValidHex(int hexIdx);
int army_GetAttackMask(army* army_1, int hexIdx, int focusLevel, int targetHexIdx);
int army_GetMoveMask(army* army_1, int hexIdx);
int army_GetAdjacentCellIndex(army* army_1, int hexIdx, int direction);
int OppositeDirection(int direction);
int CalcTerrainCost(int terrain, char direction, int remainingMobility, int pathfindingSSLevel, int fromRoad, int toRoad);

searchArray* searchArray_searchArray(searchArray *sa)
{
  sa->pointMap = 0;
  sa->field_4 = 0;
  return sa;
}

// ������ �� ��, ��� � searchArray_Close
void searchArray_underline_searchArray(searchArray *sa)
{
  pointInfo* pi = sa->pointMap;
  if(pi)
    free(pi);
  sa->pointMap = 0;
}

void searchArray_Init(searchArray* sa)
{
  pointInfo* pf = sa->pointMap;
  if(pf)
    free(pf);
  sa->pointMap = 0;
  sa->pointMap = (pointInfo*)(malloc(sizeof(pointInfo) * MAP_HEIGHT * MAP_WIDTH));
}

void searchArray_Close(searchArray* sa)
{
  pointInfo* pf = sa->pointMap;
  if(pf)
    free(pf);
  sa->pointMap = 0;
}

// ���������� ����� �����. ���� 0 - ������ �� ������ ����
int searchArray_BuildPath(searchArray* sa, int startX, int startY, int targetX, int targetY, int remainingMobility)
{
  int pathIdx = 0;
  sa->nSteps = 0;
  int currentX = targetX;
  int currentY = targetY;
  pointInfo* pfInfo;
  int newDirection;

  // ���������, ��� ������������ ��� ����� ��������������� (��� 1)
  do
  {
    pfInfo = &sa->pointMap[currentX + currentY * MAP_WIDTH];
    if(pfInfo->x != currentX && pfInfo->y != currentY)
      return 0;
    if(pfInfo->distanceFromSourcePoint <= remainingMobility)
    {
      sa->directionToTarget[pathIdx] = pfInfo->field_4 >> 4;
	  pathIdx++;
      sa->nSteps += 1;
      if(sa->nSteps >= 256)
      {
        sa->nSteps = 0;
        return sa->nSteps;
      }
    }
    newDirection = ((pfInfo->field_4 >> 4) + 4) & 7;
    currentX += normalDirTable[4 * newDirection];
	currentY += normalDirTable[4 * newDirection + 1];
  }
  while(startX != currentX || startY != currentY);

  return sa->nSteps;
}

void searchArray_PushPoint(searchArray* sa, int x, int y, int directionFacing, int pointDistance, int limitDistance, BOOL isAnyEventPoint, BOOL isDangerPoint, char xDanger, char yDanger, BOOL isSecondDayPoint, char xFirstDayStop, char yFirstDayStop)
{
  pointInfo* pPointOnMap; // dword_526B78;
  int currentInsertIndex; //dword_526B90;
  int minInsertIndex; // dword_526B94;
  int maxInsertIndex; // dword_526B98;
  char* pInsertPoint; // dword_526C1C;

  // ���� ������� ���������� �� ��������� �������������
  // ��� ������������ ���������� ����������, �� "��������"
  if(pointDistance <= limitDistance || limitDistance <= 0)
  {
    if(x >= 0)
    {
      if(x <= MAP_WIDTH - 1)
      {
        if(y >= 0)
        {
          if(y <= MAP_HEIGHT - 1)
          {
		    // field_0 - ������ � ������� ? ������, ��� ������ ��������
            if(sa->nQueuePoints < 1024)
            {
              minInsertIndex = 0;
              maxInsertIndex = sa->nQueuePoints;
              pPointOnMap = (pointInfo*)&sa->pointMap[x + y * MAP_WIDTH];			  
			   // �� ���� ���� ����� �����
              if(!(sa->pointMap[x + y * MAP_WIDTH].field_4 & 1)
			    // ���� ���� �� ����� �������� ����� ��� ������� ��-�� �� ������������ �����
			    // �� ������ �� ������� � ��� ����� � ������ ���� � �����, ��� ��������� �� �����
			    // ���� ���				  
                || (sa->pointMap[x + y * MAP_WIDTH].field_4 & 4 || !isDangerPoint)
                && (pointDistance < pPointOnMap->distanceFromSourcePoint ||
				(sa->pointMap[x + y * MAP_WIDTH].field_4 & 4) && !isDangerPoint))
              {
                while(1)
                {
                  currentInsertIndex = (maxInsertIndex + minInsertIndex) / 2;
				  pInsertPoint = (char*)&sa->pointQueue[currentInsertIndex];
                  if(maxInsertIndex >= minInsertIndex)
                    break;
                  if(sa->pointQueue[currentInsertIndex].distanceFromSourcePoint <= pointDistance)
                    maxInsertIndex = currentInsertIndex;
                  else
                    minInsertIndex = currentInsertIndex + 1;
                }
                if(sa->nQueuePoints > currentInsertIndex)
				  memmove(pInsertPoint+9, pInsertPoint, 9 * (sa->nQueuePoints - currentInsertIndex));
                sa->nQueuePoints += 1;
				
				// 4-� ��� - ���������� 1 ���� ��� ��� ���� ����� 1-�� ���
				// xFirstDayStop, yFirstDayStop - ��������� ���������� 1-�� ��� ����
				// ����� 4-� ��� ��� � �������� ��������, xFirstDayStop � yFirstDayStop ����� ����� �� ��������
                if(pointDistance <= giCurTempMobility || isSecondDayPoint)
                {
                  sa->pointQueue[currentInsertIndex].field_4 ^=
					  sa->pointQueue[currentInsertIndex].field_4 ^ (isSecondDayPoint << 3) & 8;
                  sa->pointQueue[currentInsertIndex].xFirstDayStop = xFirstDayStop;
                  sa->pointQueue[currentInsertIndex].yFirstDayStop = yFirstDayStop;
                }
                else
                {
                  sa->pointQueue[currentInsertIndex].field_4 |= 8u;
                  sa->pointQueue[currentInsertIndex].xFirstDayStop = x - normalDirTable[4 * directionFacing];
                  sa->pointQueue[currentInsertIndex].yFirstDayStop = y - normalDirTable[4 * directionFacing + 1];
                }
                sa->pointQueue[currentInsertIndex].x = x;
                sa->pointQueue[currentInsertIndex].y = y;

				// ����� ���������� ������� 4 ���� field_4 - ����������� ��������
				sa->pointQueue[currentInsertIndex].field_4 = (directionFacing << 4) ^
					((directionFacing << 4) ^ sa->pointQueue[currentInsertIndex].field_4) & 0xF;
                sa->pointQueue[currentInsertIndex].distanceFromSourcePoint = pointDistance;
                sa->pointQueue[currentInsertIndex].field_4 ^= 
					(sa->pointQueue[currentInsertIndex].field_4 ^ (isAnyEventPoint << 1)) & 2; // 2-� ���
                sa->pointQueue[currentInsertIndex].field_4 ^=
					sa->pointQueue[currentInsertIndex].field_4 ^ (isDangerPoint << 2) & 4; // 3-� ���
                sa->pointQueue[currentInsertIndex].xDanger = xDanger;
                sa->pointQueue[currentInsertIndex].yDanger = yDanger;
				// ������ �������� ����� ��� ������������
                sa->pointQueue[currentInsertIndex].field_4 |= 1u; // 1-� ���

				sa->pointMap[x + y * MAP_WIDTH].x = sa->pointQueue[currentInsertIndex].x;
				sa->pointMap[x + y * MAP_WIDTH].y = sa->pointQueue[currentInsertIndex].y;
				sa->pointMap[x + y * MAP_WIDTH].distanceFromSourcePoint = sa->pointQueue[currentInsertIndex].distanceFromSourcePoint;
				sa->pointMap[x + y * MAP_WIDTH].field_4 = sa->pointQueue[currentInsertIndex].field_4;
				sa->pointMap[x + y * MAP_WIDTH].xDanger = sa->pointQueue[currentInsertIndex].xDanger;
				sa->pointMap[x + y * MAP_WIDTH].yDanger = sa->pointQueue[currentInsertIndex].yDanger;
				sa->pointMap[x + y * MAP_WIDTH].xFirstDayStop = sa->pointQueue[currentInsertIndex].xFirstDayStop;
				sa->pointMap[x + y * MAP_WIDTH].yFirstDayStop = sa->pointQueue[currentInsertIndex].yFirstDayStop;
              }
            }
          }
        }
      }
    }
  }
  return;
}

void searchArray_TestPossibleDirections(searchArray* sa, int x, int y, char* terrainDirection, char* eventDirection, BOOL doNotCheckEvent, BOOL heroAtSea)
{
  mapCell* cell = advManager_GetCell(gpAdvManager, x, y); // dword_526B9C
  mapCell* newCell; // dword_526B80
  int direction = 0; // dword_526B8C
  int newX; // dword_526B88
  int newY; // dword_526B7C
  int terrain; // dword_526C18
  int dx;
  int dy;
  mapCell* tmpCell; // result
  
  for(int i = 0; i < 8; i++)
    eventDirection[i] = 0; 
  
  do
  {
    newX = x + normalDirTable[4 * direction];
    newY = y + normalDirTable[4 * direction + 1];
    if(newX < 0
      || newX >= MAP_WIDTH
      || newY < 0
      || newY >= MAP_HEIGHT
      || (newCell = advManager_GetCell(gpAdvManager, newX, newY),
          newCell->flags & MAP_CELL_UNPASSABLE)
      || gbHumanPlayer[giCurPlayer]
      && !(mapRevealed[newX + newY * MAP_WIDTH] & giCurPlayerBit))
    {
      terrain = -1;
	  direction += 1;
      terrainDirection[direction] = terrain;
	  if(direction < 8)
	    continue;
	  else
		break;
    }	
    if(newCell->objType & TILE_HAS_EVENT)
    {
	  // �� �������� doNotCheckEvent(a5) ������ 1
      if(doNotCheckEvent)
      {
        eventDirection[direction] = 1;
      }
      else
      {
        if(sa->desiredEventX != newX || sa->desiredEventY != newY)
		{
          terrain = -1;
	      direction += 1;
          terrainDirection[direction] = terrain;
	      if(direction < 8)
	        continue;
	      else
		    break;
		}	
      }
    }
    terrain = giGroundToTerrain[newCell->groundIndex];
    if(terrain != TERRAIN_IDX_WATER)
    { // � ���� �� ���� ����� ������ �� �����
      if(heroAtSea)
      {
        if(newCell->objType != LOCATION_SHORE)
		{
          terrain = -1;
	      direction += 1;
          terrainDirection[direction] = terrain;
	      if(direction < 8)
	        continue;
	      else
		    break;			
		}
      }
    }
    else // �������� ������ �� ����
    {
      if(heroAtSea)
      {
		// ������ ����� �� ����������
        if(newCell->objType == (LOCATION_HERO | TILE_HAS_EVENT))
        {
		  terrain = -1;
	      direction += 1;
          terrainDirection[direction] = terrain;
	      if(direction < 8)
	        continue;
	      else
		    break;
		}

        // �������� ������ ����� �� ����
        if(giGroundToTerrain[cell->groundIndex] == TERRAIN_IDX_WATER)
        {
          dx = normalDirTable[4 * direction];
		  dy = normalDirTable[4 * direction + 1];
		  
          if(dx)
          {
            if(dy)
            { 
		      // �������� � �������� ������ - ����, ������ ������ ���� ����������� ��������
		      // �� ���� - ������ ���������� �� ��������� ���� ����, ����� �� ������ �������
              if(giGroundToTerrain[advManager_GetCell(gpAdvManager,x,y + dy)->groundIndex] ||
			    giGroundToTerrain[advManager_GetCell(gpAdvManager,x + dx,y)->groundIndex])
              {
		        terrain = -1;
	            direction += 1;
                terrainDirection[direction] = terrain;
	            if(direction < 8)
	              continue;
	            else
		          break;
		      }	  
            }
          }
        }
      }
      else // �������� ������ �� ����, �� ��������� �� ����
      {
        if(newCell->objType != (LOCATION_HERO | TILE_HAS_EVENT) &&
		  newCell->objType != (LOCATION_BOAT | TILE_HAS_EVENT) &&
		  newCell->objType != (LOCATION_SHIPWRECK | TILE_HAS_EVENT))
        {
		  terrain = -1;
	      direction += 1;
          terrainDirection[direction] = terrain;
	      if(direction < 8)
	        continue;
	      else
		    break;
		}	
      }
    }

	// ����� ��� ����� �� ���������
    if((1 << direction) & 0x83)
    {
      if(cell->objectIndex != -1 )
      {
        if(cell->objTileset != TILESET_OBJECT_DUMMY)
        {
          if(!(cell->flags & 0x80)) // ���� 0x80 - ������ ���� ������� ������ ?
          {
		    terrain = -1;
	        direction += 1;
            terrainDirection[direction] = terrain;
	        if(direction < 8)
	          continue;
	        else
		      break;
		  }
        }
      }
      if(newCell->overlayIndex != -1)
      {
        tmpCell = advManager_GetCell(gpAdvManager, newX, newY + 1); // ������� �������� �� +1
        if(tmpCell->objectIndex != -1)
        {
          if(tmpCell->objTileset != TILESET_OBJECT_DUMMY && !(tmpCell->flags & 0x80))
          {
		    terrain = -1;
	        direction += 1;
            terrainDirection[direction] = terrain;
	        if(direction < 8)
	          continue;
	        else
		      break;
		  }
        }
      }
    }
    // ���� ��� ���� �� ���������	
    else if((1 << direction) & 0x38)
    {
      if(newCell->objectIndex != -1)
      {
        if(newCell->objTileset != TILESET_OBJECT_DUMMY)
        {
          if(!(newCell->flags & 0x80))
          {
            if(!(newCell->objType & TILE_HAS_EVENT) || !StopOnTrigger(newCell))
            {
		      terrain = -1;
	          direction += 1;
              terrainDirection[direction] = terrain;
	          if(direction < 8)
	            continue;
	          else
		        break;
		    }
            //dword_526B84 = v12 & 0x7F;
          }
        }
      }
      if(cell->overlayIndex != -1)
      {
        tmpCell = advManager_GetCell(gpAdvManager, x, y + 1); // ������� �������� �� +1
        if(tmpCell->objectIndex != -1)
        {
          if((tmpCell->objTileset != TILESET_OBJECT_DUMMY) && !(tmpCell->flags & 0x80))
          {
		    terrain = -1;
	        direction += 1;
            terrainDirection[direction] = terrain;
	        if(direction < 8)
	          continue;
	        else
		      break;
		  }
        }
      }
    }
	direction += 1;
    terrainDirection[direction] = terrain;
  }
  while(direction < 8);
  
  return;
}	   

void searchArray_Clear(searchArray* sa)
{

  return;
}

void searchArray_SeedPosition(searchArray* sa, int x0, int y0, int directionFacing, int limitDistance, BOOL heroAtSea, BOOL proceedAfterWeakEvent, int mobility, int pathfindingSSLevel, int xTarget, int yTarget, BOOL useOldSearch, int toggleEventsAroundMonsters)
{
  int finalDistanceTargetPoint; // dword_526C80 �������� ����� ���� �� ������� �����
  BOOL isTarget;  // dword_526C28
  BOOL isDanger; // dword_526C2C
  BOOL isSecondDay;
  mapCell* targetCell; //dword_526C70;
  BOOL targetIsRoad; // int dword_526C44;

  char frontier_x; // byte_526C58
  char frontier_y; // byte_526C59
  short pointDistance; // word_526C5A
  char frontier_field_4; // byte_526C5C;
  char frontier_xDanger; // byte_526C5D;
  char frontier_yDanger; // byte_526C5E;
  char frontier_xFirstDayStop; // byte_526C5F;
  char frontier_yFirstDayStop; // byte_526C60;

  int xDanger; // dword_526C94
  int yDanger; // dword_526CAC

  hero* currentHero; // dword_526CB4
  int queueCounter; // dword_526CA0; - ��������� �������
  int mobilityAfterPoint; // dword_526C3C
  int directionAtFrontierPoint; // dword_526C9C
  int frontierNewX; // dword_526C38
  int frontierNewY; // dword_526C6C
  pointInfo* pNewFrontierPoint; // dword_526CA4
  int xFirstDayStop; // byte_526C5F;
  int yFirstDayStop; // byte_526C60;
  char terrainDirection[8]; // byte_526C30
  char eventDirection[8]; // byte_526C78
  int bestTargetDistance; // dword_526CA8

  mapCell* frontierCell;
  mapCell* frontierNewCell;

  int frontierPointIndex;

  int objTypeFrontierEvent;

  bool skipCheckMonsters;
  bool isNotShore;

  int frontierTerrain; // dword_526CB0
  BOOL isRoadFrontier; // dword_526C4C

  int moveCost;
  int moveCostToTarget;

  // toggleEventsAroundMonsters ����� 1 ��� advManager_SeedTo, �������, ������, ������������ ������ ���������

  if(!useOldSearch)
  {
    giFullySeeded = 0;
    giCurTempMobility = mobility;
    searchArray_Clear(sa);
    sa->desiredEventY = -1;
    sa->desiredEventX = -1;
    finalDistanceTargetPoint = 0;
  }

  giSeedingValid = 1;
  if(xTarget < 0)
  {
    isTarget = 0;
  }
  else
  {
	// ���� ������� ������ ����� �� �������, ������ �� �����
    if(!(giCurPlayerBit & mapRevealed[xTarget + yTarget * MAP_WIDTH]))
      return;
    targetCell = advManager_GetCell(gpAdvManager, xTarget, yTarget);
	// ���� ������� ������ �� ���������, ������ �� �����
    if(targetCell->flags & MAP_CELL_UNPASSABLE)
      return;
	// ���� ������� ������� ������
    if(giGroundToTerrain[targetCell->groundIndex] == TERRAIN_IDX_WATER)
    {

      // ������ ? �������, ������ ��� ����� �� ���������,
	  // � � searchArray_SeedPosition �������� ����� ���� ������ � ��� �������,
	  // ������� ����� ������
	  // ��� ������� �� ���� �������� ����������� ��, ��� ����� ����� ���� ����
	  // � ������ ���������
      if(heroAtSea)
      {
		if(targetCell->objType == (LOCATION_HERO | TILE_HAS_EVENT))
          return;
      }
      // ���� �� �� �� ����, �� ������ ���������/����������������� ������ ��� ������� �������
      else
      {
        if(targetCell->objType != (LOCATION_HERO | TILE_HAS_EVENT) && targetCell->objType != (LOCATION_BOAT | TILE_HAS_EVENT)
			&& targetCell->objType != (LOCATION_SHIPWRECK | TILE_HAS_EVENT))
          return;
      }
    }
    isTarget = 1;
    bestTargetDistance = 999999;
	targetIsRoad = targetCell->isRoad;
  }
  if(isTarget)
  {
	// �� �������� �� ��� � ��� �� ����� �����
    if(useOldSearch)
	{
		// ���������� ���������� ������� ������
		frontier_x = sa->pointMap[xTarget + yTarget * MAP_WIDTH].x;
		frontier_y = sa->pointMap[xTarget + yTarget * MAP_WIDTH].y;
		pointDistance = sa->pointMap[xTarget + yTarget * MAP_WIDTH].distanceFromSourcePoint;
		frontier_field_4 = sa->pointMap[xTarget + yTarget * MAP_WIDTH].field_4;
		frontier_xDanger = sa->pointMap[xTarget + yTarget * MAP_WIDTH].xDanger;
		frontier_yDanger = sa->pointMap[xTarget + yTarget * MAP_WIDTH].yDanger;
		frontier_xFirstDayStop = sa->pointMap[xTarget + yTarget * MAP_WIDTH].xFirstDayStop;
		frontier_yFirstDayStop = sa->pointMap[xTarget + yTarget * MAP_WIDTH].yFirstDayStop;
		if(frontier_field_4 & 1) // ���� ����� ��� ���������������
		{
		  if(finalDistanceTargetPoint + 75 >= pointDistance)
			return;
		}
	}
  }
  if(!useOldSearch)
  {
    searchArray_PushPoint(sa, x0, y0, directionFacing, 0, limitDistance, 0, 0, 0, 0, 0, 0, 0);    
  }

  // � ���� ��� ��������� �������� ��� ����� ����� ? ������, ��� ���
  // ���� ������-�� ��� - ����� ���� ��������� ����� �� ������������
  currentHero = (hero*)&gpGame->heroes[gpCurPlayer->curHeroIdx];
  while(sa->nQueuePoints)
  {
    frontierPointIndex = sa->nQueuePoints - 1;
	sa->nQueuePoints -= 1;
	frontier_x = sa->pointQueue[frontierPointIndex].x;
	frontier_y = sa->pointQueue[frontierPointIndex].y;
	pointDistance = sa->pointQueue[frontierPointIndex].distanceFromSourcePoint;
	frontier_field_4 = sa->pointQueue[frontierPointIndex].field_4;
	frontier_xDanger = sa->pointQueue[frontierPointIndex].xDanger;
	frontier_yDanger = sa->pointQueue[frontierPointIndex].yDanger;
	frontier_xFirstDayStop = sa->pointQueue[frontierPointIndex].xFirstDayStop;
	frontier_yFirstDayStop = sa->pointQueue[frontierPointIndex].yFirstDayStop;

	// ���� ��������� �� ������� ������ ��� ��������, ��� bestTargetDistance, ������, ������ ����� �����������
	// (���� ���������� ������� ����� �� ��� ������)
	// �������� �� ������������ X � Y ������� ����� ���� ���� - ��� ������ ���� ��������
    if(isTarget && bestTargetDistance < 999999 && pointDistance + 75 >= bestTargetDistance)
    {
      finalDistanceTargetPoint = pointDistance; // dword_526C80 - �������� ����� ���� ?? ��
      sa->nQueuePoints += 1;
      return;
    }
	// ���� �� � �������� ������ ��������� ���� ��������� ��������������
    if(pointDistance <= limitDistance || limitDistance <= 0)
    {
      if(frontier_field_4 & 4) // 3-� ��� (������� ������������� �����)
      {
        isDanger = 1;
        xDanger = frontier_xDanger;
        yDanger = frontier_yDanger;
      }
      else
      {
        isDanger = 0;
      }
      if(frontier_field_4 & 2) // 2-� ��� (������� ������� � ������)
      {
        objTypeFrontierEvent = advManager_GetCell(gpAdvManager, frontier_x, frontier_y)->objType & (TILE_HAS_EVENT - 1);
        if(objTypeFrontierEvent == LOCATION_ARMY_CAMP || objTypeFrontierEvent == LOCATION_HERO || objTypeFrontierEvent == LOCATION_BOAT)
        {
          if(!proceedAfterWeakEvent)
		  {
			  ++queueCounter;
			  continue;
		  }

          if(frontier_field_4 & 4)
		  {
			  ++queueCounter;
			  continue;
		  }
		  // �� ���� xDanger � yDanger ��������� � x � y ����� ������
          xDanger = frontier_x;
          yDanger = frontier_y;
          isDanger = 1;
          if(objTypeFrontierEvent == LOCATION_HERO)
          {
			  if(gpGame->heroOwner[advManager_GetCell(gpAdvManager, frontier_x, frontier_y)->extraInfo] == giCurPlayer)
			  {
				  ++queueCounter;
				  continue;
			  }
          }
        }
        else
        {
          if(objTypeFrontierEvent == LOCATION_STONE_LITHS)
		  {
			  ++queueCounter;
			  continue;
		  }
          if(objTypeFrontierEvent == LOCATION_WHIRLPOOL)
		  {
			  ++queueCounter;
			  continue;
		  }
          if(!proceedAfterWeakEvent)
		  {
			  ++queueCounter;
			  continue;
		  }
		  // ���� 3-� ��� ����� 1 �� �������� ������ ����������
          if(frontier_field_4 & 4)
		  {
			  ++queueCounter;
			  continue;
		  }
          frontierCell = advManager_GetCell(gpAdvManager, frontier_x, frontier_y);
		  // stopOnTrigger ����� 1 ���� ����� �������� ����� � ��������, �������������� � ���
          if(StopOnTrigger(frontierCell))
		  {
			  ++queueCounter;
			  continue;
		  }
        }
      }

      isNotShore = false;
      if(heroAtSea)
      {
        objTypeFrontierEvent = advManager_GetCell(gpAdvManager, frontier_x, frontier_y)->objType;
        if(objTypeFrontierEvent != LOCATION_SHORE)
          isNotShore = true;
      }

      if(!heroAtSea)
      {
        if(!(mapRevealed[frontier_y * MAP_WIDTH + frontier_x] & 0x80) // ��� �������� �����
          || x0 == frontier_x && y0 == frontier_y) // ���� ��� ���. �����
          skipCheckMonsters = true;
      }

      if(!heroAtSea && !skipCheckMonsters && !isNotShore)
      {
        if(proceedAfterWeakEvent && !(frontier_field_4 & 4)) // 3-� ���
        {
		  // xDanger,yDanger - ���������� �������
		  // ���� �������� �����, ��� ����� ����, ����� �� ����
          if(advManager_FindAdjacentMonster(
                 gpAdvManager,
                 frontier_x,
                 frontier_y,
                 &xDanger,
                 &yDanger,
                 -1,
                 -1))
            isDanger = 1;
		}
      }

      if(!heroAtSea || isNotShore)
	  {
          searchArray_TestPossibleDirections(sa, frontier_x, frontier_y, terrainDirection, eventDirection, 1, heroAtSea);
          frontierTerrain = giGroundToTerrain[advManager_GetCell(
                                                              gpAdvManager,
                                                              frontier_x,
															  frontier_y)->groundIndex];
          isRoadFrontier = advManager_GetCell(
                                    gpAdvManager,
                                    frontier_x,
									frontier_y)->isRoad;
          directionAtFrontierPoint = 0;
          mobilityAfterPoint = giCurTempMobility - pointDistance;

          do
          {
            if(terrainDirection[directionAtFrontierPoint] != -1)
            {
              frontierNewX = frontier_x + normalDirTable[4 * directionAtFrontierPoint];
              frontierNewY = frontier_y + normalDirTable[4 * directionAtFrontierPoint + 1];
              pNewFrontierPoint = (pointInfo*)&sa->pointMap[frontierNewX + frontierNewY * MAP_WIDTH];
			  // ��� ���������� ������ �� ���� ������� ����� ����� �������� ����� ("������� ��������")
              if(!proceedAfterWeakEvent
                || frontier_field_4 & 4
                || !(mapRevealed[frontierNewX + frontierNewY * MAP_WIDTH] & 0x80)
                || !(pNewFrontierPoint->field_4 & 1)
                || !(pNewFrontierPoint->field_4 & 4)
                || pNewFrontierPoint->distanceFromSourcePoint >= pointDistance + 300
                || !advManager_FindAdjacentMonster(
                      gpAdvManager,
                      frontierNewX,
                      frontierNewY,
                      &xDanger,
                      &yDanger,
                      -1,
                      -1)
                || pNewFrontierPoint->xDanger != xDanger
                || pNewFrontierPoint->yDanger != yDanger)
              {
                xFirstDayStop = frontier_xFirstDayStop;
                yFirstDayStop = frontier_yFirstDayStop;
			    // 4-� ���
                isSecondDay = (frontier_field_4 & 8) >> 3;
                frontierNewCell = advManager_GetCell(gpAdvManager, frontierNewX, frontierNewY);
                moveCost = CalcTerrainCost(
                        frontierTerrain,
                        directionAtFrontierPoint,
                        mobilityAfterPoint,
                        pathfindingSSLevel,
                        isRoadFrontier,
                        frontierNewCell->isRoad);
                searchArray_PushPoint(
                  sa,
                  frontierNewX,
                  frontierNewY,
                  directionAtFrontierPoint,
                  pointDistance + moveCost,
                  limitDistance,
                  eventDirection[directionAtFrontierPoint],
                  isDanger,
                  xDanger,
                  yDanger,
                  isSecondDay,
                  xFirstDayStop,
                  yFirstDayStop);
                if(isTarget)
                {
                  if(frontierNewX == xTarget && frontierNewY == yTarget)
                  {
                    if(!(frontier_field_4 & 4)) // 3-� ���
                    {
                      frontierNewCell = advManager_GetCell(gpAdvManager, frontierNewX, frontierNewY);
                      moveCostToTarget = CalcTerrainCost(
                                       terrainDirection[directionAtFrontierPoint],
                                       directionAtFrontierPoint,
                                       giCurTempMobility - pointDistance,
                                       pathfindingSSLevel,
                                       frontierNewCell->isRoad,
                                       targetIsRoad);
                      if(moveCostToTarget + pointDistance < bestTargetDistance)
                        bestTargetDistance = moveCostToTarget + pointDistance;
                    }
                  }
                }
              }
            }
            ++directionAtFrontierPoint;
          }
          while(directionAtFrontierPoint < 8);
		  //
		  ++queueCounter;
		  continue;
	  }
	}
	// ���� �� ����������� ������� pointDistance <= limitDistance || limitDistance <= 0, ����� ������� ������ ����� (�� ���������) - ���� ����� �� �������
	// ��, ����� �������������, �� ���� � ��� ����� ���� � ���������� �������� pointDistance
    ++queueCounter;
  }

  int xSearch; //dword_526C8C
  int ySearch; // dword_526C64
  int newXSearch; // dword_526C50
  int newYSearch; // dword_526C88
  mapCell* newTargetCell; // dword_526C84
  BOOL movementEnabled; // dword_526C68
  int newCellTerrain; // dword_526CB0
  int newCellDistanceFromSourcePoint; // dword_526C48
  int stepCost;
  
  // ������ - ��������� ���� "event" ��� ������ ����� ����� � ��������� ?
  if(toggleEventsAroundMonsters)
  {
    xSearch = 0;
    if(MAP_WIDTH > 0)
    {
      do
      {
        for(ySearch = 0; ySearch < MAP_WIDTH; ySearch++)
        {
          if((advManager_GetCell(gpAdvManager, xSearch, ySearch)->objType & 0x7F) == LOCATION_ARMY_CAMP)
          {
            targetCell = advManager_GetCell(gpAdvManager, xSearch, ySearch);
            directionAtFrontierPoint = 0;
            do
            {
              newXSearch = xSearch + normalDirTable[4 * directionAtFrontierPoint];
              newYSearch = ySearch + normalDirTable[4 * directionAtFrontierPoint + 1];
              if(newXSearch >= 0 && newXSearch < MAP_WIDTH && newYSearch >= 0 && MAP_HEIGHT > newYSearch)
              {
                newTargetCell = advManager_GetCell(gpAdvManager, newXSearch, newYSearch);
                movementEnabled = 1;
                if((1 << directionAtFrontierPoint) & 0x38 // ����� ��� ����� �� ���������
                  && newTargetCell->objectIndex != -1
                  && ((newTargetCell->objTileset & 0xFC) != TILESET_OBJECT_DUMMY)
                  && !(newTargetCell->flags & 0x80))
                  movementEnabled = 0;
                if(movementEnabled)
                {
                  if(sa->pointMap[newXSearch + newYSearch * MAP_WIDTH].field_4 & 1)
                  {
                    if(!(newTargetCell->objType & TILE_HAS_EVENT))
                    {
                      newCellTerrain = giGroundToTerrain[newTargetCell->groundIndex];
                      newCellDistanceFromSourcePoint = sa->pointMap[newXSearch + newYSearch * MAP_WIDTH].distanceFromSourcePoint;
                      stepCost = CalcTerrainCost(
                              newCellTerrain,
                              directionAtFrontierPoint,
                              giCurTempMobility - newCellDistanceFromSourcePoint,
                              pathfindingSSLevel,
                              newTargetCell->isRoad,
                              targetCell->isRoad);
                      searchArray_PushPoint(
                        sa,
                        xSearch,
                        ySearch,
                        ((char)directionAtFrontierPoint + 4) & 7, // ����������� �������� �� ���������������
                        stepCost + newCellDistanceFromSourcePoint,
                        limitDistance,
                        1, // isAnyEventPoint
                        0, // isDangerPoint
                        -1, // xDanger
                        -1, // yDanger
                        0, // isSecondDayPoint
                        -1, // xFirstDayStop
                        -1); // yFirstDayStop
                    }
                  }
                }
              }
              ++directionAtFrontierPoint;
            }
            while(directionAtFrontierPoint < 8);
          }
        }
        xSearch += 1;
      }
      while(xSearch < MAP_WIDTH);
    }
  }
  giFullySeeded = 1;
  return;
}

int searchArray_QuickDistance(int x1, int y1, int x2, int y2)
{
  int xDist;
  int yDist;
  int result;

  xDist = abs(x1 - x2);
  yDist = abs(y1 - y2);
  if(xDist < yDist)
    result = yDist + xDist / 2;
  else
    result = xDist + yDist / 2;
  return result;
}

void searchArray_PushCombatPoint(searchGridArray* sa, int hexIdx, char neighborIdx, int pointDistance, int speed)
{
  int maxInsertIndex;
  int minInsertIndex;
  int currentInsertIndex;
  
  pointGridInfo* gridHexPoint;
  pointGridInfo* queueHexPoint;
  
  if(ValidHex(hexIdx))
  {
    maxInsertIndex = sa->nQueuePoints;
    minInsertIndex = 0;
	// ���� ����� � �������� �������� �������� ���� �������� <= 0 - ������ �������� �������� �� ���������
    if(speed <= 0 || speed >= pointDistance)
    {
      gridHexPoint = &sa->pointGrid[hexIdx];
	  // ���� ��� ����� �����, ���� ����� �������� �� ��� ���� (����� ���� ������)
      if(!(gridHexPoint->field_4 & 1) || pointDistance < gridHexPoint->distanceFromSourcePoint)
      {
        if(sa->nQueuePoints < 0x400u)
        {
          while(1)
          {
            currentInsertIndex = (minInsertIndex + maxInsertIndex) / 2;
            queueHexPoint = &sa->pointQueue[currentInsertIndex];
            if(maxInsertIndex <= minInsertIndex)
              break;
            if(sa->pointQueue[currentInsertIndex].distanceFromSourcePoint <= pointDistance)
              maxInsertIndex = (minInsertIndex + maxInsertIndex) / 2;
            else
              minInsertIndex = currentInsertIndex + 1;
          }
          if(currentInsertIndex < sa->nQueuePoints)
		    memmove(queueHexPoint+9, queueHexPoint, 9 * (sa->nQueuePoints - currentInsertIndex));
		
          sa->nQueuePoints += 1;
		  
          if(sa->nQueuePoints > sa->maxQueuePoints)
            sa->maxQueuePoints = sa->nQueuePoints;
		
          queueHexPoint->hexIdx = hexIdx;
          queueHexPoint->field_1 = 0;
		  // ��������������� ����������� (5-� ��� � ������)
          queueHexPoint->field_4 = (neighborIdx << 4) ^ ((neighborIdx << 4) ^ queueHexPoint->field_4) & 0xF;
          queueHexPoint->distanceFromSourcePoint = pointDistance;
		  // �������� ��� ��� ��������
          gridHexPoint->field_4 = gridHexPoint->field_4 | 1;
		  // ��������������� ����������� (5-� ��� � ������)
          gridHexPoint->field_4 = (neighborIdx << 4) ^ (gridHexPoint->field_4 ^ (neighborIdx << 4)) & 0xF;
          gridHexPoint->distanceFromSourcePoint = pointDistance;
        }
      }
    }
  }
}

int searchArray_FindCombatPath(searchGridArray* sa, int sourceHexIdx, int targetHexIdx, army* stack, BOOL isTargetSearch, int twoHexer)
{

  bool doNotAttack = false;

  memset(bIsMoatSlowed, 0, 116u);
  // � ����� ����� memset ������ ���� ? :)
  bIsMoatSlowed[116] = 0;
  // ��� ����������� - ������ ���� �������� (������, ���� �������� ������� ������)
  int otherSourceHexIdx;
  int otherTargetHexIdx;
  int deltaX;
  int row;
  bool isBlockedRow[9];
  int result;
  
  if(gpCombatManager->hasMoat)
  {
    otherSourceHexIdx = -1;
    otherTargetHexIdx = -1;
	// ������� ���� creature_flags. ������, ������� ������������ ��� ������ ������, ������� - ��� "��������" ����
    if(*(int*)&stack->creature.creature_flags & TWO_HEXER)
    {
      deltaX = (stack->facingRight - 1) < 1 ? 1 : -1;
      otherSourceHexIdx = deltaX + stack->occupiedHex;
      otherTargetHexIdx = deltaX + targetHexIdx;
    }
    row = 0;
    do
    {
      isBlockedRow[row] = gpCombatManager->combatGrid[moatHexIdxInRow[row]].isBlocked;
	  
	  // ������ ��� ��������, ���� ������ �������� ��� �� ��������� ���
      if((row != 4 || gpCombatManager->drawBridgePosition == 4)
        && (targetHexIdx != moatHexIdxInRow[row] && otherTargetHexIdx != moatHexIdxInRow[row] || twoHexer)
        && stack->occupiedHex != moatHexIdxInRow[row]
        && otherSourceHexIdx != moatHexIdxInRow[row])
        bIsMoatSlowed[moatHexIdxInRow[row]] = 1;
      ++row;
    }
    while(row < 9);
  }

  int minRemainingPixelDistance = 640;
  int backwardPathHexIdx = -1;
  int target_HexIdx;
  if(!isTargetSearch)
    target_HexIdx = -1;
  else
	target_HexIdx = targetHexIdx;

  memset(sa->pointQueue, 0, sizeof(sa->pointQueue));
  memset(sa->pointGrid, 0, 9 * MAP_HEIGHT * MAP_WIDTH);
  sa->nQueuePoints = 0;
  sa->nSteps = 0;
  if(!ValidHex(sourceHexIdx) || !ValidHex(targetHexIdx) || !stack)
  {
    result = 0;
	// ����� ������� ��� �������� � combatGrid[hexIdx].isBlocked,
	// ���� �� ������ ����� ��� �������� � ������ ������� ?
    if(gpCombatManager->hasMoat)
    {
      row = 0;
      do
      {
        gpCombatManager->combatGrid[moatHexIdxInRow[row++]].isBlocked = isBlockedRow[row];
      }
      while(row < 9);
    }
    return result;	
  }

  int directionSequenceIdx = 0;
  // ����� ��������� �����
  searchArray_PushCombatPoint(sa, sourceHexIdx, stack->facingRight < 1u ? 4 : 1, 0, stack->creature.speed);
  if(!sa->nQueuePoints)
  {
	doNotAttack = true;
  }
  int dx, dy;
  int remainingPixelDistance;
  int attackMask;
  int moveMask;
  int frontierHexIdx;
  int moveDirection;
  int newFrontierHexIdx;
  int moatPenalty;
  int attackDirection;
  int backwardDirection;
  
  while(1)
  {
	if(doNotAttack)
	  break;
  
    sa->nQueuePoints -= 1;

    frontierHexIdx = sa->pointQueue[sa->nQueuePoints].hexIdx;
    if(stack->creature.speed < sa->pointQueue[sa->nQueuePoints].distanceFromSourcePoint)
	{
      if(!sa->nQueuePoints)
	  {
	    doNotAttack = true;
	    break;
	  }
	  else
	  {
		continue;
	  }
	}

    dx = abs(gpCombatManager->combatGrid[frontierHexIdx].centerX - gpCombatManager->combatGrid[targetHexIdx].centerX);
    dy = abs(gpCombatManager->combatGrid[frontierHexIdx].occupyingCreatureBottomY -
      gpCombatManager->combatGrid[targetHexIdx].occupyingCreatureBottomY);
	
	// ���� ���������� �� Y ������ ��� �� X �� s = dy + dx / 2
	// ����� s = dx + dy / 2. ����� ��� �������
    remainingPixelDistance = dx < dy ? dy + dx / 2 : dy / 2 + dx;
	
	// ���� ��������� ����� targetHexIdx, � �� ������ ����������� � targetHexIdx
    if(stack->targetOwner != -1)
    {
      attackMask = army_GetAttackMask(stack, frontierHexIdx, 0, target_HexIdx);
	  // ����� �������
      if(attackMask != 255)
        break;
    }
	
	// ��� ����� ����� ��� ��� �������, ����� �� ��������� � ����, �� ���� �� ������� �� ��� ?
	// ���� �� ��� ����� ��������, ��������� �� ����������� ����������� - �� ���� ���
	// ����� ������ �� ����� �� ����.
	// �� ��������� � ����� ��� ������ searchArray_FindCombatPath �������� ��������������� � 99
	// ��� ��� �������� ��� ������������� remainingPixelDistance - �������� ������� ������� �������������
	// �� ���� ������ ������ ��������.
    if(remainingPixelDistance < minRemainingPixelDistance)
    {
      minRemainingPixelDistance = remainingPixelDistance;
      backwardPathHexIdx = frontierHexIdx;
      if(!remainingPixelDistance)
	  {
	    doNotAttack = true;
	    break;
	  }		
    }
    moveDirection = 0;
    moveMask = army_GetMoveMask(stack, frontierHexIdx);
    do
    {
	  // ���� ����������� ���������
      if(!((1 << moveDirection) & moveMask))
      {
        newFrontierHexIdx = army_GetAdjacentCellIndex(stack, frontierHexIdx, moveDirection);
        moatPenalty = 0;
        if(bIsMoatSlowed[newFrontierHexIdx])
          moatPenalty = stack->speed + 2;
        searchArray_PushCombatPoint(sa, newFrontierHexIdx, moveDirection,
		  sa->pointQueue[sa->nQueuePoints].distanceFromSourcePoint + moatPenalty + 1, stack->creature.speed);
      }
      ++moveDirection;
    }
    while(moveDirection < 8);

    if(!sa->nQueuePoints)
	{
	  doNotAttack = true;
	  break;
	}
  }
  
  if(!doNotAttack)
  {
    attackDirection = 0;
    while((1 << attackDirection) & attackMask)
    {
      ++attackDirection;
      if(attackDirection >= 8)
	  {
	    doNotAttack = true;
	    break;
	  }
    }
  }

  if(!doNotAttack)
  {
	directionSequenceIdx = 1;
    sa->directionToTarget[0] = attackDirection;
    backwardPathHexIdx = frontierHexIdx;
    ++sa->nSteps;
  }

  bool doNotBuildPath = false;
  // ���� ��������� ������ ����������� � targetHexIdx
  // � ���� �� ��������� � ����, �� ���� �� ����� (�������� �� ���������)
  // �� doNotBuildPath ����� false - ��� ? ����� ������ ���� � ��������� � ����
  if(stack->targetOwner == -1)
  {
	// �� ����� ����
	if(backwardPathHexIdx != targetHexIdx)
	  doNotBuildPath = true;
  }
  if(!sa->nSteps)
    doNotBuildPath = true;

  if(!doNotBuildPath)
  {
    // ���� ������� :)
    while(backwardPathHexIdx != sourceHexIdx)
    {
      ++directionSequenceIdx;
	  sa->directionToTarget[directionSequenceIdx - 1] = sa->pointGrid[backwardPathHexIdx].field_4 >> 4;
      ++sa->nSteps;
      if(sa->nSteps >= 256)
        break;
      backwardDirection = OppositeDirection(sa->pointGrid[backwardPathHexIdx].field_4 >> 4);
      backwardPathHexIdx = army_GetAdjacentCellIndex(stack, backwardPathHexIdx, backwardDirection);
    }
    result = sa->nSteps;
  }
  else
  {
	result = 0;  
  }
  
  if(gpCombatManager->hasMoat)
  {
    row = 0;
    do
    {
      gpCombatManager->combatGrid[moatHexIdxInRow[row++]].isBlocked = isBlockedRow[row];
    }
    while(row < 9);
  }
  return result;  
}

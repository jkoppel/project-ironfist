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

extern combatManager* gpCombatManager;
extern searchGridArray* gpSearchGridArray;
extern tag_monsterInfo gMonsterDatabase[66];

bool ValidHex(int hexIdx);
int searchArray_FindCombatPath(searchGridArray* sa, int sourceHexIdx, int targetHexIdx, army* stack, BOOL isTargetSearch, int twoHexer);
int OppositeDirection(int direction);

int army_GetAdjacentCellIndex(army* army_1, int hexIdx, int direction)
{
  int result;

  if(hexIdx == -1)
  {
    result = -1;
  }
  else
  {
	// �����, ����� ����� ����� auxHexIdx ? +/-1 ����� ����
	// ��� ����� ��������� � gpCombatManager->hexNeighbors[hexIdx][direction]
	// 0 ������ 5, 5 ������ 0
    if(direction == 6)
    {
      if(army_1->facingRight == 1)
        direction = 5;
      else
        direction = 0;
    } // � ����� 2 � 3 ����� �������� �������
    else if(direction == 7)
    {
      if(army_1->facingRight == 1)
        direction = 3;
      else
        direction = 2;
    }
    result = gpCombatManager->hexNeighbors[hexIdx][direction];
  }
  return result;
}

// focus 0: Only check if hex contains target
// focus 1: Only check if hex contains hostile creature
// focus 2: Check if hex contains any creature
int army_ValidAttack(army* army_1, int hexIdx, int direction, int focusLevel, int targetHexIdx, int* neighborIdx)
{
  int neighborOwner;
  
  if(!ValidHex(hexIdx))
    return 0;

  int auxHexIdx = hexIdx;

  if(army_1->creature.creature_flags & TWO_HEXER)
  {
	// ���������, ��� �������� ���� ������������ �������� - ������
    if(direction == 6)
    {
      *neighborIdx = army_GetAdjacentCellIndex(army_1, hexIdx, army_1->facingRight < 1u ? 5 : 0);
    }
    else if(direction == 7)
    {
      *neighborIdx = army_GetAdjacentCellIndex(army_1, hexIdx, (army_1->facingRight < 1u) + 2);
    }
    else
    {
      if(army_1->facingRight)
      {
        if(army_1->facingRight == 1 && direction <= 2)
          auxHexIdx = army_GetAdjacentCellIndex(army_1, hexIdx, 1);
      }
      else if(direction >= 3)
      {
        auxHexIdx = army_GetAdjacentCellIndex(army_1, hexIdx, 4);
      }
      if(auxHexIdx == -1 )
        return 0;
      *neighborIdx = army_GetAdjacentCellIndex(army_1, auxHexIdx, direction);
    }
  }
  else
  {
    *neighborIdx = army_GetAdjacentCellIndex(army_1, hexIdx, direction);
  }
  if(!ValidHex(*neighborIdx))
    return 0;
  if(targetHexIdx != -1 && *neighborIdx != targetHexIdx)
    return 0;
  neighborOwner = gpCombatManager->combatGrid[*neighborIdx].unitOwner;
  if(focusLevel)
  {
    if( focusLevel == 1)
    {
	  // ����� ���� ����������
      if(1 - gpCombatManager->currentActionSide == neighborOwner)
        return 1;
    } // ����� ��� ��� ���-�� ����
    else if(focusLevel == 2 && neighborOwner != -1)
    {
      return 1;
    }
  } // ����� ����
  else if(army_1->targetOwner == neighborOwner &&
    gpCombatManager->combatGrid[*neighborIdx].stackIdx == army_1->targetStackIdx )
  {
    return 1;
  }
  return 0;
}

int army_GetAttackMask(army* army_1, int hexIdx, int focusLevel, int targetHexIdx)
{
  // �� ������������, ��������� � �������
  int attackMask;
  if(army_1->creature.creature_flags & TWO_HEXER)
    attackMask = 0;
  else
  // � ����� ��� �������� ���: 11000000
  // ��� ?
  //  5 6 0
  // 4  -  1
  //  3 7 2
  // �� ���� 2 �������� ��� 6 � 7 ������� - ����� ���������
  // ��������� ��� ������������� �������� ��� ����������� 6 � 7
  attackMask = 192; // -64
  int currentMaskBit = 1;
  int nNeighbors;
  if(army_1->creature.creature_flags & TWO_HEXER)
    nNeighbors = 8;
  else
    nNeighbors = 6;
  int neighborIdx;
  for(int direction = 0; direction < nNeighbors; direction++)
  {
    if(!army_ValidAttack(army_1, hexIdx, direction, focusLevel, targetHexIdx, &neighborIdx))
      attackMask |= currentMaskBit;
    currentMaskBit = currentMaskBit << 1;
  }
  return attackMask;
}

bool army_ValidMove(army* army_1, int hexIdx, int direction)
{

  return 1;
}

int army_GetMoveMask(army* army_1, int hexIdx)
{

  int moveMask = 0;
  int currentMaskBit = 1;
  for(int direction = 0; direction <= 5; direction++)
  {
    if(!army_ValidMove(army_1, hexIdx, direction))
      moveMask |= currentMaskBit;
    currentMaskBit = currentMaskBit << 1;
  }
  // � ����� ��� �������� ���: 11000000
  // ��� ������� 7 � 8 �������� ��������� (���� ����������� �������� �� ����� ������� �� 1 �����)
  // �� ��-�� ����� �� ��� � �������������� �������� ���� ��������� ���� �������� 1
  return moveMask | 0xC0;
}

BOOL army_FindPath(army* army_1, int hexIdx, int targetHexIdx, int speed, int flying, int flag)
{
  char savedSpeed;
  BOOL pathFound;

  if(ValidHex(hexIdx) && ValidHex(targetHexIdx))
  {
    savedSpeed = army_1->creature.speed;
    if(flying)
      army_1->creature.speed = 99;
    pathFound = searchArray_FindCombatPath(gpSearchGridArray, hexIdx, targetHexIdx, army_1, flag, 0);

	// c ������������ ��������� �����-�� �������� ? (!pathFound)
	// ��� ������ ��-�� ����������� ��� ����� ���� ?
    if(!pathFound && army_1->creature.creature_flags & TWO_HEXER && !flag)
    {
      if(army_1->facingRight)
      {
        if(army_1->facingRight == 1)
		  // ���� � ����� �� 1 �����
          targetHexIdx = army_GetAdjacentCellIndex(army_1, targetHexIdx, 4);
      }
      else
      {
		// ���� � ����� �� 1 ������
        targetHexIdx = army_GetAdjacentCellIndex(army_1, targetHexIdx, 1);
      }
      if(ValidHex(targetHexIdx))
        pathFound = searchArray_FindCombatPath(gpSearchGridArray, hexIdx, targetHexIdx, army_1, 0, 1);
      else
        pathFound = 0;
    }
    army_1->creature.speed = savedSpeed;
    pathFound = pathFound;
  }
  else
  {
    pathFound = 0;
  }
  return pathFound;
}

int army_GetBestDirection(int hexIdx, int targetHexIdx, char mask)
{

  if(!ValidHex(hexIdx) || !ValidHex(targetHexIdx))
    return -1;
  int row = hexIdx / 13;
  int destRow = targetHexIdx / 13;
  int goUp = 0;
  int goDown = 0;
  int goLeft = 0;
  int goRight = 0;
  if(hexIdx % 13 >= targetHexIdx % 13)
  {
    if(hexIdx % 13 != targetHexIdx % 13)
      goLeft = 1;
  }
  else
  {
    goRight = 1;
  }
  if(row >= destRow)
  {
    if(row != destRow)
      goUp = 1;
  }
  else
  {
    goDown = 1;
  }
  // ���� � �� � ������ ����
  if(goLeft == goRight)
  {
    if(goUp == 1)
    {
	  // ���� 1-�, 3-� � ��� ����� ��� (���� � ��������)
      if(row & 1)
      {
		// ������-�����, ���� ��� �����. ������� � ����� (������� - ������)
        if(!(mask & 0x20))
          return 5;
	    // �������-�����
        if(!(mask & 1))
          return 0;
	    // � ������ ��������, �� ����������� ��� ����
        if(!(mask & 0x10))
          return 4;
        if(!(mask & 2))
          return 1;
        if(!(mask & 8))
          return 3;
        if (!(mask & 4))
          return 2;
        if(!(mask & 0x40))
          return 6;
        if(!(mask & 0x80))
          return 7;
      }
      else
      {
        if(!(mask & 1))
          return 0;
        if(!(mask & 0x20))
          return 5;
        if(!(mask & 2))
          return 1;
        if(!(mask & 0x10))
          return 4;
        if(!(mask & 4))
          return 2;
        if(!(mask & 8))
          return 3;
        if(!(mask & 0x40))
          return 6;
        if(!(mask & 0x80))
          return 7;
      }
    } // ��������� - ����
    else if(row & 1)
    {
      if(!(mask & 8))
        return 3;
      if(!(mask & 4))
        return 2;
      if(!(mask & 0x10))
        return 4;
      if(!(mask & 2))
        return 1;
      if(!(mask & 0x20))
        return 5;
      if(!(mask & 1))
        return 0;
      if(!(mask & 0x80))
        return 7;
      if(!(mask & 0x40))
        return 6;
    }
    else
    {
      if(!(mask & 4))
        return 2;
      if(!(mask & 8))
        return 3;
      if(!(mask & 2))
        return 1;
      if(!(mask & 0x10))
        return 4;
      if(!(mask & 1))
        return 0;
      if(!(mask & 0x20))
        return 5;
      if(!(mask & 0x80))
        return 7;
      if(!(mask & 0x40))
        return 6;
    }
  }
  if(goLeft == 1)
  {
    if(goUp == 1)
    {
      if(!(mask & 0x20))
        return 5;
      if(!(mask & 0x10))
        return 4;
      if(!(mask & 1))
        return 0;
      if(!(mask & 8))
        return 3;
      if(!(mask & 2))
        return 1;
      if(!(mask & 4))
        return 2;
      if(!(mask & 0x40))
        return 6;
      if(!(mask & 0x80))
        return 7;
    }
    else if(goDown == 1)
    {
      if(!(mask & 8))
        return 3;
      if(!(mask & 0x10))
        return 4;
      if(!(mask & 4))
        return 2;
      if(!(mask & 0x20))
        return 5;
      if(!(mask & 2))
        return 1;
      if(!(mask & 1))
        return 0;
      if(!(mask & 0x80))
        return 7;
      if(!(mask & 0x40))
        return 6;
    }
    else
    {
      if(!(mask & 0x10))
        return 4;
      if(!(mask & 0x20))
        return 5;
      if(!(mask & 8))
        return 3;
      if(!(mask & 1))
        return 0;
      if(!(mask & 4))
        return 2;
      if(!(mask & 2))
        return 1;
      if(!(mask & 0x80))
        return 7;
      if(!(mask & 0x40))
        return 6;
    }
  }
  else if(goRight == 1)
  {
    if(goUp == 1)
    {
      if(!(mask & 1))
        return 0;
      if(!(mask & 2))
        return 1;
      if(!(mask & 0x20))
        return 5;
      if(!(mask & 4))
        return 2;
      if(!(mask & 0x10))
        return 4;
      if(!(mask & 8))
        return 3;
      if(!(mask & 0x40))
        return 6;
      if(!(mask & 0x80))
        return 7;
    }
    else if(goDown == 1)
    {
      if(!(mask & 4))
        return 2;
      if(!(mask & 2))
        return 1;
      if(!(mask & 8))
        return 3;
      if(!(mask & 1))
        return 0;
      if(!(mask & 0x20))
        return 5;
      if(!(mask & 0x10))
        return 4;
      if(!(mask & 0x80))
        return 7;
      if(!(mask & 0x40))
        return 6;
    }
    else
    {
      if(!(mask & 2))
        return 1;
      if(!(mask & 1))
        return 0;
      if(!(mask & 4))
        return 2;
      if(!(mask & 0x20))
        return 5;
      if(!(mask & 8))
        return 3;
      if(!(mask & 0x10))
        return 4;
      if(!(mask & 0x80))
        return 7;
      if(!(mask & 0x40))
        return 6;
    }
  }
  return -1;
}

bool army_CanFit(army* army_1, int hexIdx, int mayShiftTwoHexers, int* rearHexIdx)
{
  bool result;
  int secondHexIdx;
  int otherSecondHexIdx;

  hexcell* hexcell_1 = 0;

  // ���� ��������� rearHexIdx �� ����, �� �� ������ �������� � rearHexIdx ���� ��������
  // rearHexIdx ����� ���� �������������� �����, ���� �� ����� �� ������ ����� ��� ��������
  if(rearHexIdx)
    *rearHexIdx = hexIdx;
  // ���� �� ������� (���������) �������
  if(ValidHex(hexIdx) && hexIdx % 13 && hexIdx % 13 != 12)
  {
	// ���� ���� �����
    if(gpCombatManager->combatGrid[hexIdx].unitOwner != -1 || gpCombatManager->combatGrid[hexIdx].isBlocked)
    {
      result = 0;
    }
    else if(army_1->creature.creature_flags & TWO_HEXER)
    {
      secondHexIdx = army_GetAdjacentCellIndex(army_1, hexIdx, (army_1->facingRight - 1) < 1 ? 1 : 4);
      if(ValidHex(secondHexIdx) && secondHexIdx % 13 && secondHexIdx % 13 != 12)
        hexcell_1 = &gpCombatManager->combatGrid[secondHexIdx];
      if(!ValidHex(secondHexIdx) || (hexcell_1->unitOwner != -1 && 
	  (hexcell_1->unitOwner != gpCombatManager->activeStackOwner || hexcell_1->stackIdx != gpCombatManager->activeStack))
        || hexcell_1->isBlocked)
      {
        if(mayShiftTwoHexers)
        {
          otherSecondHexIdx = army_GetAdjacentCellIndex(army_1, hexIdx, (army_1->facingRight - 1) < 1 ? 4 : 1);
          if(ValidHex(otherSecondHexIdx))
          {
            if(gpCombatManager->combatGrid[otherSecondHexIdx].unitOwner != -1
              && (gpCombatManager->combatGrid[otherSecondHexIdx].unitOwner != gpCombatManager->activeStackOwner
               || gpCombatManager->combatGrid[otherSecondHexIdx].stackIdx != gpCombatManager->activeStack)
              || gpCombatManager->combatGrid[otherSecondHexIdx].isBlocked)
            {
              result = 0;
            }
            else
            {
              if(rearHexIdx)
                *rearHexIdx = otherSecondHexIdx;
              result = 1;
            }
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = 1;
      }
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

// isConstTargetHex - �������� ����� ������������ ����������� ��� 2-�������� ����
// �� ������ ������� ++targetHexIdx, � ����� --targetHexIdx
// �� ����� --targetHexIdx targetHexIdx �� ���� ������������ �������, �� ���� ���������
// �������������� ��� ������ ������� ��� ������������� � ������� !isConstTargetHex
int army_ValidFlight(army* army_1, int hexIdx, int isConstTargetHex)
{
  int result;
  int rearHex;
  int direction;
  int neighborIdx;
  int mask;
  army* targetArmy;
  int nextNeighborDirection;
  int nextNeighborIdx;
  int targetHexIdx;
  int targetMask;

  if(ValidHex(hexIdx))
  {
    if(army_1->targetOwner >= 0 && army_1->targetOwner <= 1 && army_1->targetStackIdx >= 0 && army_1->targetStackIdx <= 19)
    {
      targetArmy = &gpCombatManager->creatures[army_1->targetOwner][army_1->targetStackIdx];
      if(isConstTargetHex)
        targetHexIdx = hexIdx;
      else
        targetHexIdx = targetArmy->occupiedHex;
      if(ValidHex(targetHexIdx))
      {
		// ���������, �� ���������� �� ���� �����
		// ������� ��� ����������� �� ���������� ��������
        for(mask = army_GetAttackMask(army_1, army_1->occupiedHex, 0, -1); mask != 255; mask |= 1 << direction)
        {
          direction = army_GetBestDirection(army_1->occupiedHex, targetHexIdx, (char)mask);
		  // ���������� focus 0 - ������ �� ���� ������ army_1->targetStackIdx
          if(army_ValidAttack(army_1, army_1->occupiedHex, direction, 0, -1, &neighborIdx))
          {
            army_1->targetNeighborDirection = direction;
            army_1->targetHex = army_1->occupiedHex;
            return 1;
          }
        }
		
		// ����� ���� �� �����, ���� ������
        targetMask = 0;
		// ���� ���� 2-��������, �� ������� ��������� �������� ����
        if(targetArmy->creature.creature_flags & TWO_HEXER && !isConstTargetHex)
        {
          if(targetArmy->facingRight == 1)
            ++targetHexIdx;
          else
            --targetHexIdx;
          if(targetArmy->facingRight == 1)
            targetMask = 16; // ����������� 5 ���������
          else
            targetMask = 2; // ����������� 1 ���������
        }
		// ��� ��� ���������� ��� ��� 1-�������� ��� � ��� 2-�������� ����
        while(targetMask != 63) // ��� 6 ����������� ��������� (����������)
        {
          nextNeighborDirection = army_GetBestDirection(targetHexIdx, army_1->occupiedHex, targetMask);
          nextNeighborIdx = army_GetAdjacentCellIndex(army_1, targetHexIdx, nextNeighborDirection);
          if(ValidHex(nextNeighborIdx) && army_CanFit(army_1, nextNeighborIdx, 1 - isConstTargetHex, &rearHex) )
          {
            army_1->targetHex = rearHex;
            if(army_1->creature.creature_flags & TWO_HEXER)
            {
			  // � ���� ����� �������� - ���� 1, �� ����� ���������
			  // army_1->targetHex ����� rearHex
              mask = ~army_GetAttackMask(army_1, army_1->targetHex, 0, -1);
              for(int i = 0; i < 8; i++)
              {
                if((1 << i) & mask)
                  army_1->targetNeighborDirection = i;
              }
            }
			// ���� ���� ��������� �������� ������������ �� ��� ������
            else
            {
              army_1->targetNeighborDirection = OppositeDirection(nextNeighborDirection);
            }
            return 1;
          }
          targetMask |= 1 << nextNeighborDirection;
        }
		// ���� ������� ��� �� ����� �� ��� ������ (�� ������� 1)
		// �� ������� ��������� ������ ����, ���� ���� 2-��������		
        if(targetArmy->creature.creature_flags & TWO_HEXER && !isConstTargetHex)
        {
          if(targetArmy->facingRight == 1)
            --targetHexIdx;
          else
            ++targetHexIdx;
          if(targetArmy->facingRight == 1)
            targetMask = 2; // ����������� 1 ���������
          else
            targetMask = 16; // ����������� 5 ���������
          while(targetMask != 63)
          {
            nextNeighborDirection = army_GetBestDirection(targetHexIdx, army_1->occupiedHex, targetMask);
            nextNeighborIdx = army_GetAdjacentCellIndex(army_1, targetHexIdx, nextNeighborDirection);
			// ����� ����� ���� �������� �� ��� � ���� - ��� ����� � ��� ������ 2-��������� ��������
			// � ��� ������ 1-���������
			// ������ ��� ������			
            if(ValidHex(nextNeighborIdx) && army_CanFit(army_1, nextNeighborIdx, 0, 0))
            {
              army_1->targetHex = nextNeighborIdx;
              army_1->targetNeighborDirection = army_GetBestDirection(army_1->targetHex, targetHexIdx, 0);
              return 1;
            }
            targetMask |= 1 << nextNeighborDirection;
          }
        }
        result = 0;
      }
      else
      {
        result = 0;
      }
    }
    else if(army_CanFit(army_1, hexIdx, 0, 0) )
    {
      army_1->targetHex = hexIdx;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

BOOL army_ValidPath(army* stack, int hexIdx, int flag)
{
  BOOL result;

  if(ValidHex(hexIdx))
  {
    if(stack->creature.creature_flags & FLYER)
    {
      result = army_ValidFlight(stack, hexIdx, flag);
    }
    else if(army_FindPath(stack, stack->occupiedHex, hexIdx, stack->creature.speed, 0, flag))
    {
      stack->targetHex = hexIdx;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

unsigned int army_Strength(army* army_1)
{
  return army_1->quantity * gMonsterDatabase[army_1->creatureIdx].fight_value;
}

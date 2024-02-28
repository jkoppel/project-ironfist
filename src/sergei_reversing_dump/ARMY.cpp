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
	// может, здесь лучше брать auxHexIdx ? +/-1 вдоль ряда
	// или сразу указывать в gpCombatManager->hexNeighbors[hexIdx][direction]
	// 0 вместо 5, 5 вместо 0
    if(direction == 6)
    {
      if(army_1->facingRight == 1)
        direction = 5;
      else
        direction = 0;
    } // а здесь 2 и 3 нужно поменять местами
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
	// считается, что основной гекс двугексового существа - задний
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
	  // нашли стек противника
      if(1 - gpCombatManager->currentActionSide == neighborOwner)
        return 1;
    } // нашли что там кто-то есть
    else if(focusLevel == 2 && neighborOwner != -1)
    {
      return 1;
    }
  } // нашли цель
  else if(army_1->targetOwner == neighborOwner &&
    gpCombatManager->combatGrid[*neighborIdx].stackIdx == army_1->targetStackIdx )
  {
    return 1;
  }
  return 0;
}

int army_GetAttackMask(army* army_1, int hexIdx, int focusLevel, int targetHexIdx)
{
  // по направлениям, насколько я понимаю
  int attackMask;
  if(army_1->creature.creature_flags & TWO_HEXER)
    attackMask = 0;
  else
  // в битах это выглядит так: 11000000
  // Так ?
  //  5 6 0
  // 4  -  1
  //  3 7 2
  // то есть 2 единички для 6 и 7 позиции - атака запрещена
  // поскольку для одногексового существа нет направлений 6 и 7
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
  // в битах это выглядит так: 11000000
  // для позиций 7 и 8 движение запрещено (типа двугексовое существо не может сжаться до 1 гекса)
  // не из-за этого ли баг с невозможностью движения гидр наискосок если скорость 1
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

	// c двугексовыми возникают какие-то проблемы ? (!pathFound)
	// или просто из-за препятствий так может быть ?
    if(!pathFound && army_1->creature.creature_flags & TWO_HEXER && !flag)
    {
      if(army_1->facingRight)
      {
        if(army_1->facingRight == 1)
		  // идем к гексу на 1 левее
          targetHexIdx = army_GetAdjacentCellIndex(army_1, targetHexIdx, 4);
      }
      else
      {
		// идем к гексу на 1 правее
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
  // если и то и другое ноль
  if(goLeft == goRight)
  {
    if(goUp == 1)
    {
	  // если 1-й, 3-й и так далее ряд (счет с нулевого)
      if(row & 1)
      {
		// налево-вверх, если нет соотв. единицы в маске (единица - запрет)
        if(!(mask & 0x20))
          return 5;
	    // направо-вверх
        if(!(mask & 1))
          return 0;
	    // и другие варианты, но приоритетом был верх
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
    } // приоритет - вниз
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

  // если указатель rearHexIdx не ноль, то мы должны записать в rearHexIdx гекс существа
  // rearHexIdx может быть скорректирован далее, если мы сразу не найдем место для существа
  if(rearHexIdx)
    *rearHexIdx = hexIdx;
  // гекс не крайней (невидимой) колонки
  if(ValidHex(hexIdx) && hexIdx % 13 && hexIdx % 13 != 12)
  {
	// если гекс занят
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

// isConstTargetHex - возможно здесь используется неправильно для 2-гексовой цели
// мы делаем сначала ++targetHexIdx, а затем --targetHexIdx
// но после --targetHexIdx targetHexIdx по сути возвращается обратно, то есть неизменно
// соответственно для второй попытки нет необходимости в условии !isConstTargetHex
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
		// проверяем, не находиться ли цель рядом
		// обходим все направления от атакующего существа
        for(mask = army_GetAttackMask(army_1, army_1->occupiedHex, 0, -1); mask != 255; mask |= 1 << direction)
        {
          direction = army_GetBestDirection(army_1->occupiedHex, targetHexIdx, (char)mask);
		  // передается focus 0 - значит мы ищем именно army_1->targetStackIdx
          if(army_ValidAttack(army_1, army_1->occupiedHex, direction, 0, -1, &neighborIdx))
          {
            army_1->targetNeighborDirection = direction;
            army_1->targetHex = army_1->occupiedHex;
            return 1;
          }
        }
		
		// рядом цель не нашли, ищем дальше
        targetMask = 0;
		// Если цель 2-гексовая, то пробуем атаковать передний гекс
        if(targetArmy->creature.creature_flags & TWO_HEXER && !isConstTargetHex)
        {
          if(targetArmy->facingRight == 1)
            ++targetHexIdx;
          else
            --targetHexIdx;
          if(targetArmy->facingRight == 1)
            targetMask = 16; // направление 5 запрещено
          else
            targetMask = 2; // направление 1 запрещено
        }
		// это код отработает как для 1-гексовой так и для 2-гексовой цели
        while(targetMask != 63) // все 6 направлений запрещены (отработаны)
        {
          nextNeighborDirection = army_GetBestDirection(targetHexIdx, army_1->occupiedHex, targetMask);
          nextNeighborIdx = army_GetAdjacentCellIndex(army_1, targetHexIdx, nextNeighborDirection);
          if(ValidHex(nextNeighborIdx) && army_CanFit(army_1, nextNeighborIdx, 1 - isConstTargetHex, &rearHex) )
          {
            army_1->targetHex = rearHex;
            if(army_1->creature.creature_flags & TWO_HEXER)
            {
			  // в этой маске наоборот - если 1, то можно атаковать
			  // army_1->targetHex равен rearHex
              mask = ~army_GetAttackMask(army_1, army_1->targetHex, 0, -1);
              for(int i = 0; i < 8; i++)
              {
                if((1 << i) & mask)
                  army_1->targetNeighborDirection = i;
              }
            }
			// если наше атакующее существо одногексовое то все просто
            else
            {
              army_1->targetNeighborDirection = OppositeDirection(nextNeighborDirection);
            }
            return 1;
          }
          targetMask |= 1 << nextNeighborDirection;
        }
		// Если прошлый раз не нашли то что искали (не вернули 1)
		// то пробуем атаковать задний гекс, если цель 2-гексовая		
        if(targetArmy->creature.creature_flags & TWO_HEXER && !isConstTargetHex)
        {
          if(targetArmy->facingRight == 1)
            --targetHexIdx;
          else
            ++targetHexIdx;
          if(targetArmy->facingRight == 1)
            targetMask = 2; // направление 1 запрещено
          else
            targetMask = 16; // направление 5 запрещено
          while(targetMask != 63)
          {
            nextNeighborDirection = army_GetBestDirection(targetHexIdx, army_1->occupiedHex, targetMask);
            nextNeighborIdx = army_GetAdjacentCellIndex(army_1, targetHexIdx, nextNeighborDirection);
			// здесь нужно было вставить то что и выше - обе ветки и для нашего 2-гексового существа
			// и для нашего 1-гексового
			// короче это ошибка			
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

signed int __thiscall sub_4012C0(CreatureStack *this, int hex, int flag)
{
  signed int result; // eax@2
  CreatureStack *thisa; // [sp+Ch] [bp-38h]@1
  int i; // [sp+10h] [bp-34h]@33
  int rearHex; // [sp+14h] [bp-30h]@30
  int neighbor; // [sp+18h] [bp-2Ch]@17
  int neighborIdx; // [sp+1Ch] [bp-28h]@17
  int mask; // [sp+20h] [bp-24h]@15
  CreatureStack *target; // [sp+2Ch] [bp-18h]@10
  signed int nextNeighborIdx; // [sp+30h] [bp-14h]@29
  int a1; // [sp+34h] [bp-10h]@29
  int targHex; // [sp+3Ch] [bp-8h]@11
  int targMask; // [sp+40h] [bp-4h]@20

  thisa = this;
  if ( checkHexGridIdxBounds(hex) )
  {
    if ( thisa->targetOwner >= 0 && thisa->targetOwner <= 1 && thisa->targetStackIdx >= 0 && thisa->targetStackIdx <= 19 )
    {
      target = &combatManager->creatures[thisa->targetOwner][thisa->targetStackIdx];
      if ( flag )
        targHex = hex;
      else
        targHex = target->occupiedHex;
      if ( checkHexGridIdxBounds(targHex) )
      {
        for ( mask = CreatureStack::getFreeNeighborBitmask(thisa, thisa->occupiedHex, 0, -1);
              mask != 255;
              mask |= 1 << neighbor )
        {
          neighbor = getNeighborOnPath(thisa->occupiedHex, targHex, mask);
          if ( CreatureStack::neighboringHexOccupied(thisa, thisa->occupiedHex, neighbor, 0, -1, &neighborIdx) )
          {
            thisa->targetNeighborIdx = neighbor;
            thisa->targetHex = thisa->occupiedHex;
            return 1;
          }
        }
        targMask = 0;
        if ( target->creature.creature_flags & TWO_HEXER && !flag )
        {
          if ( target->facingRight == 1 )
            ++targHex;
          else
            --targHex;
          if ( target->facingRight == 1 )
            targMask = 16;
          else
            targMask = 2;
        }
        while ( targMask != 63 )
        {
          nextNeighborIdx = getNeighborOnPath(targHex, thisa->occupiedHex, targMask);
          a1 = CreatureStack::getHexNeighbor(thisa, targHex, nextNeighborIdx);
          if ( checkHexGridIdxBounds(a1) && CreatureStack::canPlaceCreature(thisa, a1, 1 - flag, &rearHex) )
          {
            thisa->targetHex = rearHex;
            if ( thisa->creature.creature_flags & TWO_HEXER )
            {
              mask = ~CreatureStack::getFreeNeighborBitmask(thisa, thisa->targetHex, 0, -1);
              for ( i = 0; i < 8; ++i )
              {
                if ( (1 << i) & mask )
                  thisa->targetNeighborIdx = i;
              }
            }
            else
            {
              thisa->targetNeighborIdx = mirrorNeighborIdx(nextNeighborIdx);
            }
            return 1;
          }
          targMask |= 1 << nextNeighborIdx;
        }
        if ( target->creature.creature_flags & 1 && !flag )
        {
          if ( target->facingRight == 1 )
            --targHex;
          else
            ++targHex;
          if ( target->facingRight == 1 )
            targMask = 2;
          else
            targMask = 16;
          while ( targMask != 63 )
          {
            nextNeighborIdx = getNeighborOnPath(targHex, thisa->occupiedHex, targMask);
            a1 = CreatureStack::getHexNeighbor(thisa, targHex, nextNeighborIdx);
            if ( checkHexGridIdxBounds(a1) && CreatureStack::canPlaceCreature(thisa, a1, 0, 0) )
            {
              thisa->targetHex = a1;
              thisa->targetNeighborIdx = getNeighborOnPath(thisa->targetHex, targHex, 0);
              return 1;
            }
            targMask |= 1 << nextNeighborIdx;
          }
        }
        result = 0;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      if ( CreatureStack::canPlaceCreature(thisa, hex, 0, 0) )
      {
        thisa->targetHex = hex;
        result = 1;
      }
      else
      {
        result = 0;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

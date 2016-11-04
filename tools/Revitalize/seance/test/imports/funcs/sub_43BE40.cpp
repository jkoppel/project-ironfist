{
  signed int v4; // ST14_4@13
  CombatManager *thisa; // [sp+14h] [bp-2Ch]@1
  signed int a2a; // [sp+18h] [bp-28h]@71
  CreatureStack *v7; // [sp+1Ch] [bp-24h]@37
  signed int v8; // [sp+20h] [bp-20h]@37
  float v9; // [sp+24h] [bp-1Ch]@13
  int v10; // [sp+28h] [bp-18h]@37
  signed int v11; // [sp+30h] [bp-10h]@6
  int v12; // [sp+34h] [bp-Ch]@6
  int v13; // [sp+38h] [bp-8h]@37
  int v14; // [sp+3Ch] [bp-4h]@4
  int v15; // [sp+3Ch] [bp-4h]@6

  thisa = this;
  if ( !this->notHandlingInputEvent && (*(_DWORD *)&this->_15[64] > 1 || *(_DWORD *)&this->_15[60] < 0) )
  {
    v14 = a2 - 44 * (a4 % 13 - 1) - 67;
    if ( !(a4 / 13 & 1) )
      v14 = a2 - 44 * (a4 % 13 - 1) - 89;
    v15 = v14 - 22;
    v12 = a3 - 63 - 42 * (a4 / 13) - 26;
    v11 = 0;
    if ( v15 >= 0 )
    {
      if ( v12 >= 0 )
        v11 = 6;
    }
    else
    {
      if ( v12 >= 0 )
        v11 = 12;
      else
        v11 = 18;
    }
    v4 = abs(v15);
    v9 = (double)v4 / (double)abs(v12);
    if ( v11 && v11 != 12 )
    {
      if ( v9 >= 0.27 )
      {
        if ( v9 >= 0.58 )
        {
          if ( v9 >= 1.0 )
          {
            if ( v9 >= 1.73 )
            {
              if ( v9 < 3.73 )
                ++v11;
            }
            else
            {
              v11 += 2;
            }
          }
          else
          {
            v11 += 3;
          }
        }
        else
        {
          v11 += 4;
        }
      }
      else
      {
        v11 += 5;
      }
    }
    else
    {
      if ( v9 <= 3.73 )
      {
        if ( v9 <= 1.73 )
        {
          if ( v9 <= 1.0 )
          {
            if ( v9 <= 0.58 )
            {
              if ( v9 > 0.27 )
                ++v11;
            }
            else
            {
              v11 += 2;
            }
          }
          else
          {
            v11 += 3;
          }
        }
        else
        {
          v11 += 4;
        }
      }
      else
      {
        v11 += 5;
      }
    }
    if ( thisa->_15[v11 + 36] != *(_DWORD *)&thisa->_15[60] )
    {
      *(_DWORD *)&thisa->_15[60] = thisa->_15[v11 + 36];
      v13 = mirrorNeighborIdx(thisa->_15[v11 + 36]);
      v10 = v13;
      v8 = -1;
      v7 = &thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx];
      if ( v13 != 6 && v13 != 7 )
      {
        if ( thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].facingRight == 1
          && thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].creature.creature_flags & 1 )
        {
          if ( v13 == 5 || v13 == 4 || v13 == 3 )
            --a4;
        }
        else
        {
          if ( !thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].facingRight
            && thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].creature.creature_flags & 1
            && (!v13 || v13 == 1 || v13 == 2) )
            ++a4;
        }
      }
      else
      {
        if ( thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].creature.creature_flags & 1 )
        {
          if ( thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].facingRight != 1 || v13 != 6 )
          {
            if ( thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].facingRight != 1 || v13 != 7 )
            {
              if ( thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].facingRight || v13 != 6 )
              {
                v13 = 2;
                v8 = 3;
              }
              else
              {
                v13 = 0;
                v8 = 5;
              }
            }
            else
            {
              v13 = 3;
              v8 = 2;
            }
          }
          else
          {
            v13 = 5;
            v8 = 0;
          }
        }
        else
        {
          if ( thisa->combatGrid[a4 - 1].unitOwner == thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].targetOwner
            && thisa->combatGrid[a4 - 1].stackIdx == thisa->creatures[thisa->otherCurrentSideThing][thisa->someSortOfStackIdx].targetStackIdx )
            --a4;
          if ( v13 == 6 )
            v13 = 0;
          else
            v13 = 2;
        }
      }
      thisa->field_F2C7 = thisa->hexNeighbors[a4][v13];
      a2a = -2;
      if ( !v7->facingRight && v7->creature.creature_flags & 1 )
        a2a = thisa->field_F2C7 - 1;
      if ( v7->facingRight == 1 && v7->creature.creature_flags & 1 )
        a2a = thisa->field_F2C7 + 1;
      if ( !sub_43B400(thisa, thisa->field_F2C7) || !sub_43B400(thisa, a2a) )
      {
        if ( v7->creature.creature_flags & 1 && (v10 == 6 || v10 == 7) )
        {
          if ( v7->facingRight == 1 )
            ++thisa->field_F2C7;
          else
            --thisa->field_F2C7;
        }
        else
        {
          if ( v8 != -1 )
            thisa->field_F2C7 = thisa->hexNeighbors[a4][v8];
        }
      }
      MouseManager::setSpriteIdx(mouseManager, *(_DWORD *)&thisa->_15[60] + 7);
    }
  }
}

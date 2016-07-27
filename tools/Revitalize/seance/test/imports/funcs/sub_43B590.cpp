{
  CombatManager *result; // eax@1
  CombatManager *thisa; // [sp+Ch] [bp-7Ch]@1
  int v4; // [sp+10h] [bp-78h]@2
  int v5[8]; // [sp+14h] [bp-74h]@31
  int v6; // [sp+34h] [bp-54h]@108
  CreatureStack *thisb; // [sp+38h] [bp-50h]@2
  int v8; // [sp+3Ch] [bp-4Ch]@108
  int i; // [sp+40h] [bp-48h]@2
  char v10[6]; // [sp+44h] [bp-44h]@53
  char v11; // [sp+4Ah] [bp-3Eh]@71
  int v12; // [sp+4Ch] [bp-3Ch]@103
  int v13; // [sp+50h] [bp-38h]@2
  int v14; // [sp+54h] [bp-34h]@74
  CreatureStack *v15; // [sp+58h] [bp-30h]@2
  int a2[8]; // [sp+5Ch] [bp-2Ch]@9
  int v17; // [sp+7Ch] [bp-Ch]@75
  char v18[8]; // [sp+80h] [bp-8h]@47

  thisa = this;
  result = this;
  if ( !this->notHandlingInputEvent )
  {
    thisb = &this->creatures[this->otherCurrentSideThing][this->someSortOfStackIdx];
    v4 = thisb->targetOwner;
    v13 = thisb->targetStackIdx;
    thisb->targetOwner = -1;
    thisb->targetStackIdx = -1;
    v15 = &this->creatures[v4][v13];
    for ( i = 0; i < 8; ++i )
    {
      if ( i != 6 && i != 7 )
      {
        a2[i] = thisa->hexNeighbors[hexIdx][i];
      }
      else
      {
        if ( thisb->creature.creature_flags & 1 )
        {
          if ( thisb->facingRight == 1 )
          {
            if ( i == 6 )
              a2[6] = thisa->hexNeighbors[hexIdx][5];
            if ( i == 7 )
              a2[7] = thisa->hexNeighbors[hexIdx][3];
          }
          else
          {
            if ( i == 6 )
              a2[6] = thisa->hexNeighbors[hexIdx][0];
            if ( i == 7 )
              a2[7] = thisa->hexNeighbors[hexIdx][2];
          }
        }
        else
        {
          a2[i] = -1;
        }
      }
      if ( thisb->creature.creature_flags & 1 && a2[i] != -1 )
      {
        if ( thisb->facingRight == 1 )
        {
          if ( i == 5 || i == 4 || i == 3 )
          {
            if ( a2[i] % 13 == 1 )
              a2[i] = -1;
            else
              --a2[i];
          }
          if ( a2[i] % 13 == 11 )
            v5[i] = -1;
          else
            v5[i] = a2[i] + 1;
        }
        else
        {
          if ( !i || i == 1 || i == 2 )
          {
            if ( a2[i] % 13 == 11 )
              a2[i] = -1;
            else
              ++a2[i];
          }
          if ( a2[i] % 13 == 1 )
            v5[i] = -1;
          else
            v5[i] = a2[i] - 1;
        }
      }
      else
      {
        v5[i] = -2;
      }
      v18[i] = sub_43B400(thisa, a2[i]) && sub_43B400(thisa, v5[i]);
    }
    if ( thisb->creature.creature_flags & 2 )
    {
      for ( i = 0; i < 8; ++i )
        v10[i] = v18[i];
    }
    else
    {
      for ( i = 0; i < 8; ++i )
      {
        if ( v18[i] )
          v10[i] = a2[i] == thisb->occupiedHex || sub_405F00(thisb, a2[i], 1);
        else
          v10[i] = 0;
      }
    }
    *(_DWORD *)&thisa->_15[64] = 0;
    for ( i = 0; i < 8; ++i )
    {
      if ( v10[i] )
        ++*(_DWORD *)&thisa->_15[64];
    }
    if ( !*(_DWORD *)&thisa->_15[64] )
      v11 = 1;
    memset(&thisa->_15[36], -1, 0x18u);
    for ( i = 0; i < 8; ++i )
    {
      v14 = i;
      if ( i >= 6 )
      {
        if ( i == 6 )
          v17 = 7;
        else
          v17 = 6;
      }
      else
      {
        v17 = (i + 3) % 6;
      }
      if ( v10[v17] )
      {
        if ( v15->creature.creature_flags & 1 )
        {
          if ( i || thisa->combatGrid[hexIdx - 1].unitOwner != v4 || thisa->combatGrid[hexIdx - 1].stackIdx != v13 )
          {
            if ( i != 5
              || thisa->combatGrid[hexIdx + 1].unitOwner != v4
              || thisa->combatGrid[hexIdx + 1].stackIdx != v13 )
            {
              if ( i != 2
                || thisa->combatGrid[hexIdx - 1].unitOwner != v4
                || thisa->combatGrid[hexIdx - 1].stackIdx != v13 )
              {
                if ( i == 3
                  && thisa->combatGrid[hexIdx + 1].unitOwner == v4
                  && thisa->combatGrid[hexIdx + 1].stackIdx == v13 )
                  v14 = 7;
              }
              else
              {
                v14 = 7;
              }
            }
            else
            {
              v14 = 6;
            }
          }
          else
          {
            v14 = 6;
          }
        }
        if ( i >= 6 )
        {
          if ( i == 6 )
          {
            thisa->_15[47] = v14;
            thisa->_15[48] = v14;
            thisa->_15[49] = v14;
          }
          else
          {
            thisa->_15[36] = v14;
            thisa->_15[37] = v14;
            thisa->_15[59] = v14;
          }
        }
        else
        {
          memset(&thisa->_15[4 * v17 + 36], v14, 4u);
        }
      }
    }
    v12 = 24;
    while ( v12 > 0 )
    {
      for ( i = 0; i < 24; ++i )
      {
        if ( thisa->_15[i + 36] == -1 )
        {
          v6 = (i + 1) % 24;
          v8 = (i + 23) % 24;
          if ( thisa->_15[(i + 1) % 24 + 36] < 0 || thisa->_15[v6 + 36] > 7 )
          {
            if ( thisa->_15[v8 + 36] >= 0 && thisa->_15[v8 + 36] <= 7 )
              thisa->_15[i + 36] = thisa->_15[v8 + 36] + 10;
          }
          else
          {
            thisa->_15[i + 36] = thisa->_15[v6 + 36] + 10;
          }
        }
      }
      v12 = 0;
      for ( i = 0; i < 24; ++i )
      {
        if ( thisa->_15[i + 36] < 10 )
        {
          if ( thisa->_15[i + 36] == -1 )
            ++v12;
        }
        else
        {
          thisa->_15[i + 36] -= 10;
        }
      }
    }
    thisb->targetOwner = v4;
    result = (CombatManager *)v13;
    thisb->targetStackIdx = v13;
  }
  return result;
}

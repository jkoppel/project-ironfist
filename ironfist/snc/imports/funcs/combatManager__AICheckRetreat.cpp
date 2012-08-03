{
  bool result; // eax@2
  int v2; // esi@16
  __int16 v3; // fps@62
  unsigned __int8 v4; // c0@62
  unsigned __int8 v5; // c3@62
  int v6; // [sp+2Ch] [bp-148h]@1
  signed int v7; // [sp+34h] [bp-140h]@21
  signed int i; // [sp+38h] [bp-13Ch]@13
  int v9; // [sp+40h] [bp-134h]@43
  float v10; // [sp+44h] [bp-130h]@62
  signed int j; // [sp+48h] [bp-12Ch]@18
  signed int k; // [sp+48h] [bp-12Ch]@21
  signed int l; // [sp+48h] [bp-12Ch]@36
  char v14; // [sp+4Ch] [bp-128h]@13
  hero *hro; // [sp+5Ch] [bp-118h]@16
  armyGroup *armyGrp; // [sp+60h] [bp-114h]@16
  int v17[2]; // [sp+64h] [bp-110h]@35
  int v18[2]; // [sp+6Ch] [bp-108h]@33
  float v19; // [sp+74h] [bp-100h]@46
  hero this; // [sp+78h] [bp-FCh]@13

  v6 = ecx0;
  if ( *(_DWORD *)(ecx0 + 4 * *(_DWORD *)(ecx0 + 62127) + 12927) )
  {
    result = 0;
  }
  else if ( *(_DWORD *)(ecx0 + 4 * *(_DWORD *)(ecx0 + 62127) + 12935) )
  {
    if ( *(_BYTE *)(*(_DWORD *)(ecx0 + 4 * *(_DWORD *)(ecx0 + 62127) + 12935) + 231) )
    {
      result = 0;
    }
    else if ( gpGame->winConditionType != 2
  || *(_BYTE *)(*(_DWORD *)(ecx0 + 4 * *(_DWORD *)(ecx0 + 62127) + 12935) + 2) != gpGame->winConditionArgument )
    {
      if ( gpGame->players[*(_BYTE *)(*(_DWORD *)(ecx0 + 4 * *(_DWORD *)(ecx0 + 62127) + 12935) + 3)].numCastles
        || gpGame->players[*(_BYTE *)(*(_DWORD *)(ecx0 + 4 * *(_DWORD *)(ecx0 + 62127) + 12935) + 3)].numHeroes != 1 )
      {
        hero::hero(&this);
        armyGroup::armyGroup((armyGroup *)&v14);
        for ( i = 0; i < 2; ++i )
        {
          if ( *(_DWORD *)(v6 + 4 * i + 12935) )
          {
            v2 = *(_DWORD *)(v6 + 4 * i + 12935);
            memcpy(&this, (const void *)v2, 0xF8u);
            *(_WORD *)&this.scrollSpell[12] = *(_WORD *)(v2 + 248);
            hro = &this;
            armyGrp = &this.army;
          }
          else
          {
            armyGrp = (armyGroup *)&v14;
            hro = 0;
          }
          for ( j = 0; j < 5; ++j )
          {
            armyGrp->creatureTypes[j] = -1;
            armyGrp->quantities[j] = 0;
          }
          v7 = 0;
          for ( k = 0; k < 20; ++k )
          {
            if ( *(_DWORD *)(1154 * k + 24234 * i + v6 + 13765) >= 0
              && *(_DWORD *)(1154 * k + 24234 * i + v6 + 13797) > 0 )
            {
              armyGrp->creatureTypes[v7] = *(_BYTE *)(1154 * k + 24234 * i + v6 + 13765);
              if ( *(_BYTE *)(1154 * k + 24234 * i + v6 + 13855) & 0x80 )
                armyGrp->quantities[v7] = *(_DWORD *)(1154 * k + 24234 * i + v6 + 13797);
              else
                armyGrp->quantities[v7] = (signed __int64)((double)*(signed int *)(1154 * k + 24234 * i + v6 + 13797)
                                                         * 1.2);
              ++v7;
            }
            if ( v7 >= 5 )
              k = 999;
          }
          v18[i] = philAI::FightValueOfStack(armyGrp, hro, 1, 0, 0, 0);
          if ( *(_DWORD *)(v6 + 4 * i + 12927) )
            v18[i] = (signed __int64)((double)v18[i] * 1.1);
          v17[i] = 0;
          if ( hro )
          {
            for ( l = 0; l < 14; ++l )
            {
              if ( hro->artifacts[l] >= 0 && hro->artifacts[l] < 37 )
                v17[i] += gArtifactBaseRV[hro->artifacts[l]];
            }
          }
        }
        v18[1 - *(_DWORD *)(v6 + 62127)] = (signed __int64)((double)v18[1 - *(_DWORD *)(v6 + 62127)] * 1.1);
        v9 = v17[*(_DWORD *)(v6 + 62127)];
        if ( v17[*(_DWORD *)(v6 + 62127)] >= 1000
          || *(_DWORD *)(*(_DWORD *)(v6 + 4 * *(_DWORD *)(v6 + 62127) + 12935) + 57) >= 2000 )
        {
          v19 = 0.16;
          if ( v9 <= 10000 )
          {
            if ( v9 <= 5000 )
            {
              if ( v9 > 0 )
                v19 = v19 + 0.04;
            }
            else
            {
              v19 = v19 + 0.05;
            }
          }
          else
          {
            v19 = v19 + 0.06;
          }
          if ( v18[*(_DWORD *)(v6 + 62127)] <= 40000 )
          {
            if ( v18[*(_DWORD *)(v6 + 62127)] <= 30000 )
            {
              if ( v18[*(_DWORD *)(v6 + 62127)] <= 15000 )
              {
                if ( v18[*(_DWORD *)(v6 + 62127)] <= 5000 )
                {
                  if ( v18[*(_DWORD *)(v6 + 62127)] > 2500 )
                    v19 = v19 - 0.02;
                }
                else
                {
                  v19 = v19 - 0.04;
                }
              }
              else
              {
                v19 = v19 - 0.06;
              }
            }
            else
            {
              v19 = v19 - 0.08;
            }
          }
          else
          {
            v19 = v19 - (double)(v18[*(_DWORD *)(v6 + 62127)] / 20000);
          }
          v19 = v19 - (double)(4 - (signed int)gpGame->difficulty) * 0.015;
          UNDEF(v3);
          v10 = (double)(*(_DWORD *)(*(_DWORD *)(v6 + 4 * *(_DWORD *)(v6 + 62127) + 12935) + 57) / 200000);
          if ( !(v4 | v5) )
            v10 = 0.029999999;
          v19 = v19 + v10;
          if ( !*(_DWORD *)(v6 + 62127) )
            v19 = v19 - 0.06;
          if ( v19 > 0.16 )
            v19 = 0.16;
          result = (double)v18[*(_DWORD *)(v6 + 62127)] / (double)(v18[0] + v18[1]) < v19;
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
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
void __thiscall sub_4ADEA0(void *this, int a2, int a3)
{
  int v3; // eax@3
  double v4; // st7@17
  double v5; // st7@19
  void *v6; // [sp+20h] [bp-270h]@1
  float v7; // [sp+24h] [bp-26Ch]@1
  int v8[72]; // [sp+28h] [bp-268h]@3
  int i; // [sp+148h] [bp-148h]@1
  float v10; // [sp+14Ch] [bp-144h]@1
  int v11; // [sp+150h] [bp-140h]@9
  int v12; // [sp+154h] [bp-13Ch]@3
  int v13[72]; // [sp+158h] [bp-138h]@11
  char v14; // [sp+278h] [bp-18h]@17
  int v15; // [sp+27Ch] [bp-14h]@18
  int v16; // [sp+280h] [bp-10h]@18
  int v17; // [sp+284h] [bp-Ch]@18
  int v18; // [sp+288h] [bp-8h]@1
  int v19; // [sp+28Ch] [bp-4h]@1

  v6 = this;
  v10 = 1.0;
  v7 = -99.0;
  v18 = 0;
  v19 = 0;
  for ( i = 0; curPlayer->numCastles > i; ++i )
  {
    v12 = (int)&gameObject->castles[curPlayer->castlesOwned[i]];
    v3 = getArmyStrength((ArmyInfo *)(v12 + 8), 0, 0, 0, 0, 0);
    v8[i] = v3 + 400;
    v18 += v8[i];
    if ( *(_BYTE *)(v12 + 24) & 0x40 )
      v19 += 10;
    else
      v19 += 7;
  }
  if ( v19 < 1 )
    v19 = 1;
  v11 = v18 / v19;
  for ( i = 0; curPlayer->numCastles > i; ++i )
  {
    v12 = (int)&gameObject->castles[curPlayer->castlesOwned[i]];
    v13[i] = v11 * ((*(_DWORD *)(v12 + 24) & 0x40u) < 1 ? 7 : 10) + 400;
  }
  for ( i = 0; curPlayer->numCastles > i; ++i )
  {
    v12 = (int)&gameObject->castles[curPlayer->castlesOwned[i]];
    logUpTo7Ints((int)"Turns Owned", *(_WORD *)(v12 + 85), -999, -999, -999, -999, -999, -999);
    if ( dword_532C54 <= 3 || (signed int)*(_WORD *)(v12 + 85) >= 3 )
    {
      sub_4AA7B0(0, 0);
      sub_4B03D0(v6, v12, (int)&v14, (int)&v10);
      v4 = (double)(100 - unseededNextRand(0, 10)) / 100.0 * v10;
      v10 = v4;
      if ( v4 > v7 )
      {
        v7 = v10;
        *(_DWORD *)a3 = *(_DWORD *)&v14;
        *(_DWORD *)(a3 + 4) = v15;
        *(_DWORD *)(a3 + 8) = v16;
        *(_DWORD *)(a3 + 12) = v17;
      }
      sub_4AA7B0(0, 0);
      sub_4B0860(v12, (int)&v14, (int)&v10);
      v10 = ((double)v13[i] / (double)v8[i] / 3.0 + 0.66) * v10;
      v5 = (double)(100 - unseededNextRand(0, 10)) / 100.0 * v10;
      v10 = v5;
      if ( v5 > v7 )
      {
        v7 = v10;
        *(_DWORD *)a3 = *(_DWORD *)&v14;
        *(_DWORD *)(a3 + 4) = v15;
        *(_DWORD *)(a3 + 8) = v16;
        *(_DWORD *)(a3 + 12) = v17;
      }
      sub_4AA7B0(0, 0);
      if ( curPlayer->numHeroes < dword_532CE4 && *(_BYTE *)(v12 + 24) & 0x40 )
      {
        sub_4B0F70(v12, (int)&v14, (int)&v10);
        v10 = (double)(100 - unseededNextRand(0, 10)) / 100.0 * v10;
        if ( dword_532C58 || dword_532C54 <= 5 || v10 <= 0.0 )
        {
          if ( !curPlayer->numHeroes )
            v10 = v10 + 500.0;
        }
        else
        {
          if ( (*(_DWORD *)&curPlayer->_4[84] < 1250 || curPlayer->numHeroes >= dword_532CE4 - 2)
            && curPlayer->numHeroes > 1 )
          {
            if ( *(_DWORD *)&curPlayer->_4[84] >= 1500 && curPlayer->numHeroes < dword_532CE4 - 1 )
              v10 = v10 * 1.3;
          }
          else
          {
            v10 = v10 + 500.0;
          }
        }
        if ( v7 < (double)v10 )
        {
          v7 = v10;
          *(_DWORD *)a3 = *(_DWORD *)&v14;
          *(_DWORD *)(a3 + 4) = v15;
          *(_DWORD *)(a3 + 8) = v16;
          *(_DWORD *)(a3 + 12) = v17;
        }
      }
    }
  }
  logUpTo7Ints(
    (int)"BestBHC ",
    *(_DWORD *)(a3 + 4),
    (signed __int64)(v7 * 100.0),
    *(_DWORD *)(a3 + 8),
    0,
    0,
    -999,
    -999);
  if ( v7 < 0.02 )
    *(_DWORD *)(a3 + 4) = -1;
}

void __stdcall sub_4B4C50(int a1, void *a2, int a3, int a4, int a5, int a6, signed int a7)
{
  int quantity; // [sp+30h] [bp-24h]@39
  signed int v8; // [sp+34h] [bp-20h]@21
  signed int v9; // [sp+3Ch] [bp-18h]@22
  signed int v10; // [sp+40h] [bp-14h]@10
  signed int k; // [sp+44h] [bp-10h]@13
  signed int i; // [sp+48h] [bp-Ch]@4
  signed int j; // [sp+48h] [bp-Ch]@10
  signed int l; // [sp+48h] [bp-Ch]@24
  signed int v15; // [sp+4Ch] [bp-8h]@1
  signed int v16; // [sp+50h] [bp-4h]@0

  v15 = 1;
  dword_532C50 = 0;
  while ( v15 )
  {
    if ( a3 )
    {
      v16 = 0;
      for ( i = 0; i < 5; ++i )
      {
        if ( *(_BYTE *)(i + a1) != -1 )
          v16 += *(_WORD *)(a1 + 2 * i + 5);
      }
      if ( v16 <= 1 )
        break;
    }
    v10 = -1;
    for ( j = 0; j < 5; ++j )
    {
      if ( v10 == -1 )
      {
        for ( k = 0; k < 5; ++k )
        {
          if ( *(_BYTE *)(j + a1) != -1 && *((_BYTE *)a2 + k) == *(_BYTE *)(j + a1) )
          {
            v10 = j;
            break;
          }
        }
      }
    }
    if ( v10 == -1 )
    {
      v8 = -9999;
      if ( a4 )
        v9 = 1;
      else
        v9 = 9;
      for ( l = 0; l < 5; ++l )
      {
        if ( *(_BYTE *)(l + a1) != -1 )
        {
          if ( (!a4 || creature_table[*(_BYTE *)(l + a1)].speed <= v9)
            && (a4 || creature_table[*(_BYTE *)(l + a1)].speed >= v9) )
          {
            if ( creature_table[*(_BYTE *)(l + a1)].speed == v9
              && *(_WORD *)(a1 + 2 * l + 5) * creature_table[*(_BYTE *)(l + a1)].fight_value > v8 )
            {
              v8 = *(_WORD *)(a1 + 2 * l + 5) * creature_table[*(_BYTE *)(l + a1)].fight_value;
              v10 = l;
            }
          }
          else
          {
            v9 = creature_table[*(_BYTE *)(l + a1)].speed;
            v8 = *(_WORD *)(a1 + 2 * l + 5) * creature_table[*(_BYTE *)(l + a1)].fight_value;
            v10 = l;
          }
        }
      }
    }
    if ( v10 == -1 )
    {
      v15 = 0;
    }
    else
    {
      if ( ArmyInfo::hasRoomForCreatureType((ArmyInfo *)a2, *(_BYTE *)(v10 + a1)) )
      {
        quantity = (signed __int64)((double)a7 / (double)creature_table[*(_BYTE *)(v10 + a1)].fight_value + 0.5);
        if ( quantity <= 0 )
        {
          v15 = 0;
        }
        else
        {
          if ( *(_WORD *)(a1 + 2 * v10 + 5) >= quantity )
          {
            v15 = 0;
            if ( ((double)quantity >= (double)*(_WORD *)(a1 + 2 * v10 + 5) * 0.65
               || *(_WORD *)(a1 + 2 * v10 + 5) - 1 <= quantity)
              && (double)(((signed int)*(_WORD *)(a1 + 2 * v10 + 5) - quantity)
                        * creature_table[*(_BYTE *)(v10 + a1)].fight_value) < (double)(a5 - a7) * 0.2 )
              quantity = *(_WORD *)(a1 + 2 * v10 + 5);
          }
          else
          {
            quantity = *(_WORD *)(a1 + 2 * v10 + 5);
          }
          if ( a3 && v16 <= quantity )
          {
            quantity = v16 - 1;
            v15 = 0;
          }
          if ( (double)a7 >= (double)(quantity * creature_table[*(_BYTE *)(v10 + a1)].fight_value) * 1.2 )
            a7 -= quantity * creature_table[*(_BYTE *)(a1 + v10)].fight_value;
          else
            v15 = 0;
          ArmyInfo::addCreatures((ArmyInfo *)a2, *(_BYTE *)(v10 + a1), quantity, -1);
          *(_WORD *)(a1 + 2 * v10 + 5) -= quantity;
          if ( !*(_WORD *)(a1 + 2 * v10 + 5) )
            *(_BYTE *)(v10 + a1) = -1;
        }
      }
      else
      {
        v15 = 0;
      }
    }
  }
}

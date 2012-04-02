int __stdcall sub_4B36D0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax@6
  signed int i; // [sp+14h] [bp-10h]@8
  int v8; // [sp+18h] [bp-Ch]@7
  signed int v9; // [sp+1Ch] [bp-8h]@1

  *(_DWORD *)a4 = 0;
  *(_DWORD *)a5 = 0;
  *(_DWORD *)a6 = -1;
  v9 = 999999;
  if ( a3 )
    *(_DWORD *)a4 = a2;
  else
    *(_DWORD *)a4 = sub_4B0C50(a1);
  if ( *(_DWORD *)a4 > a2 )
    *(_DWORD *)a4 = a2;
  result = a4;
  if ( *(_DWORD *)a4 )
  {
    v8 = *(_DWORD *)a4 * creature_table[a1].fight_value;
    if ( !ArmyInfo::hasRoomForCreatureType(&dword_51D5BC->army, a1) )
    {
      for ( i = 0; i < 5; ++i )
      {
        if ( dword_51D5BC->army.creatureTypes[i] == a1 )
        {
          *(_DWORD *)a6 = -1;
          i = 5;
        }
        else
        {
          if ( creature_table[i].fight_value * dword_51D5BC->army.quantities[i] < v9 )
          {
            v9 = creature_table[i].fight_value * dword_51D5BC->army.quantities[i];
            *(_DWORD *)a6 = i;
          }
        }
      }
    }
    if ( *(_DWORD *)a6 != -1 )
      v8 -= v9;
    *(_DWORD *)a5 = (signed __int64)((double)v8 * *(float *)&gameObject->players[dword_51D5BC->probablyOwnerIdx]._4[100]);
    if ( !a3 )
    {
      getCreatureCosts(a1, &arr);
      *(_DWORD *)a5 -= *(_DWORD *)a4 * (unsigned __int64)sub_4B13F0((int)&arr);
    }
    result = a5;
    if ( *(_DWORD *)a5 < 0 )
    {
      *(_DWORD *)a5 = 0;
      result = a4;
      *(_DWORD *)a4 = 0;
    }
  }
  return result;
}

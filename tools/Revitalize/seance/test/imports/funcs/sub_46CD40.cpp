{
  signed int result; // eax@2
  void *v3; // [sp+Ch] [bp-20h]@1
  int v4; // [sp+10h] [bp-1Ch]@3
  signed int v5; // [sp+14h] [bp-18h]@3
  int neighbor; // [sp+18h] [bp-14h]@6
  signed int neighborIdx; // [sp+1Ch] [bp-10h]@3
  int v8; // [sp+24h] [bp-8h]@11
  int v9; // [sp+28h] [bp-4h]@1

  v3 = this;
  v9 = ~CreatureStack::getFreeNeighborBitmask((CreatureStack *)a2, *(_DWORD *)(a2 + 122), 1, -1);
  if ( v9 )
  {
    v5 = 1;
    v4 = 0;
    for ( neighborIdx = 0; neighborIdx < 8; ++neighborIdx )
    {
      if ( v5 & v9
        && CreatureStack::neighboringHexOccupied(
             (CreatureStack *)a2,
             *(_DWORD *)(a2 + 122),
             neighborIdx,
             1,
             -1,
             &neighbor) )
      {
        if ( neighbor >= 0 )
          v4 |= 1 << *((_BYTE *)v3 + 98 * neighbor + 1317);
      }
      v5 *= 2;
    }
    if ( *(_DWORD *)(a2 + 118) == 59 )
      v8 = sub_46C870(v3, 1 - *(_DWORD *)((char *)v3 + 62127), v4);
    else
      v8 = sub_46C670(v3, 1 - *(_DWORD *)((char *)v3 + 62127), v4);
    if ( v8 == -1 )
    {
      result = 0;
    }
    else
    {
      couldBeCreatureActionType = 2;
      notTargetForAISpell = *(_DWORD *)((char *)v3 + 24234 * (1 - *(_DWORD *)((char *)v3 + 62127)) + 1154 * v8 + 13769);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

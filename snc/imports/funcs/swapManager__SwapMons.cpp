{
  int v1; // [sp+Ch] [bp-14h]@1
  armyGroup *thisa; // [sp+10h] [bp-10h]@7
  signed int i; // [sp+14h] [bp-Ch]@1
  int v4; // [sp+18h] [bp-8h]@1
  armyGroup *oth; // [sp+1Ch] [bp-4h]@7

  v1 = this;
  v4 = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( *(_BYTE *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + i + 101) != -1 )
    {
      if ( (signed int)*(_WORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + 2 * i + 106) > 0 )
        ++v4;
    }
  }
  thisa = (armyGroup *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + 101);
  oth = (armyGroup *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 74) + 62) + 101);
  if ( thisa->creatureTypes[*(_DWORD *)(this + 78)] == oth->creatureTypes[*(_DWORD *)(this + 82)] )
  {
    if ( armyGroup::GetNumArmies(thisa) != 1 )
    {
      oth->quantities[*(_DWORD *)(v1 + 82)] += thisa->quantities[*(_DWORD *)(v1 + 78)];
      thisa->creatureTypes[*(_DWORD *)(v1 + 78)] = -1;
      thisa->quantities[*(_DWORD *)(v1 + 78)] = 0;
    }
  }
  else if ( thisa == oth || armyGroup::GetNumArmies(thisa) != 1 || oth->creatureTypes[*(_DWORD *)(v1 + 82)] != -1 )
  {
    armyGroup::Swap(thisa, *(_DWORD *)(v1 + 78), oth, *(_DWORD *)(v1 + 82));
  }
}
{
  army *thisa; // [sp+Ch] [bp-1Ch]@1
  signed int neighbor; // [sp+10h] [bp-18h]@6
  signed int neighbora; // [sp+10h] [bp-18h]@14
  int hex; // [sp+18h] [bp-10h]@1
  int secondHex; // [sp+1Ch] [bp-Ch]@2
  int knownHex; // [sp+20h] [bp-8h]@12
  signed int hexIdx; // [sp+24h] [bp-4h]@4
  signed int hexIdxa; // [sp+24h] [bp-4h]@12

  thisa = this;
  hex = gpCombatManager->creatures[side][idx].occupiedHex;
  if ( gpCombatManager->creatures[side][idx].creature.creature_flags & TWO_HEXER )
    secondHex = hex + (gpCombatManager->creatures[side][idx].owningSide < 1u ? 1 : -1);
  else
    secondHex = -1;
  for ( hexIdx = 0; hexIdx < 6; ++hexIdx )
  {
    neighbor = army::GetAdjacentCellIndex(thisa, thisa->occupiedHex, hexIdx);
    if ( hex == neighbor || neighbor != -1 && secondHex == neighbor )
      return 1;
  }
  if ( thisa->creature.creature_flags & TWO_HEXER )
  {
    knownHex = thisa->occupiedHex + (thisa->owningSide < 1u ? 1 : -1);
    for ( hexIdxa = 0; hexIdxa < 6; ++hexIdxa )
    {
      neighbora = army::GetAdjacentCellIndex(thisa, knownHex, hexIdxa);
      if ( hex == neighbora || neighbora != -1 && secondHex == neighbora )
        return 1;
    }
  }
  return 0;
}
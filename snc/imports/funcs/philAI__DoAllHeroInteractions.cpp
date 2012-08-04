{
  int result; // eax@2
  signed int v2; // ST20_4@4
  int i; // [sp+14h] [bp-4h]@1

  for ( i = 0; ; ++i )
  {
    result = gpCurPlayer->numCastles;
    if ( result <= i )
      break;
    if ( gpGame->castles[gpCurPlayer->castlesOwned[i]].visitingHeroIdx != -1 )
    {
      v2 = (signed int)&gpGame->castles[gpCurPlayer->castlesOwned[i]];
      philAI::HeroInteractionAtTown((int)&gpGame->heroes[*(_BYTE *)(v2 + 23)], v2, 0, (int)&unk_5305C8);
    }
  }
  return result;
}
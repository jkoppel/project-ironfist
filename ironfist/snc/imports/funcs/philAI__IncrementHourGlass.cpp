{
  playerData *result; // eax@1
  signed int v1; // [sp+10h] [bp-4h]@1

  result = (playerData *)gpCurPlayer->numHeroes;
  v1 = gpCurPlayer->numHeroes;
  if ( v1 < 4 )
  {
    result = gpCurPlayer;
    if ( gpCurPlayer->resources[6] >= 2500 )
    {
      if ( !bHeroBuiltThisTurn )
        ++v1;
    }
  }
  LODWORD(iCurHourGlassPhase) = iCurHourGlassPhase + 1;
  if ( v1 == 1 )
  {
    LODWORD(iCurHourGlassPhase) = iCurHourGlassPhase + 1;
    LODWORD(iCurHourGlassPhase) = iCurHourGlassPhase + 1;
  }
  if ( v1 == 2 && (_DWORD)iCurHourGlassPhase != 1 )
    LODWORD(iCurHourGlassPhase) = iCurHourGlassPhase + 1;
  if ( v1 == 3 && ((_DWORD)iCurHourGlassPhase == 3 || (_DWORD)iCurHourGlassPhase == 6) )
    LODWORD(iCurHourGlassPhase) = iCurHourGlassPhase + 1;
  if ( (signed int)iCurHourGlassPhase > 9 )
    LODWORD(iCurHourGlassPhase) = 9;
  return result;
}
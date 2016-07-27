{
  bool result; // eax@2
  char *v3; // eax@3
  int v4; // ST24_4@3
  int v5; // ST20_4@3

  if ( a2 == -1 )
  {
    result = 0;
  }
  else
  {
    v3 = (char *)this + 250 * a2;
    v4 = (int)(v3 + 10180);
    v5 = usedToCheckForBoatByCastle(advManager, *(_DWORD *)(v3 + 10205), *(_DWORD *)(v3 + 10209));
    result = sub_464D00(
               (unsigned __int8)tileToTerrainType[*(_WORD *)v5],
               1,
               *(_DWORD *)(v4 + 53),
               *(_BYTE *)(v4 + 116),
               (*(_BYTE *)(v5 + 2) >> 1) & 1,
               0) <= *(_DWORD *)(v4 + 53);
  }
  return result;
}

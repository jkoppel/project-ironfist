{
  bool result; // eax@2
  char *v3; // eax@3
  int v4; // ST24_4@3
  mapCell *v5; // ST20_4@3

  if ( a2 == -1 )
  {
    result = 0;
  }
  else
  {
    v3 = (char *)this + 250 * a2;
    v4 = (int)(v3 + 10180);
    v5 = advManager::GetCell(gpAdvManager, *(_DWORD *)(v3 + 10205), *(_DWORD *)(v3 + 10209));
    result = CalcTerrainCost(
               (unsigned __int8)giGroundToTerrain[v5->tileType],
               1,
               *(_DWORD *)(v4 + 53),
               *(_BYTE *)(v4 + 116),
               (LOBYTE(v5->field_2) >> 1) & 1,
               0) <= *(_DWORD *)(v4 + 53);
  }
  return result;
}
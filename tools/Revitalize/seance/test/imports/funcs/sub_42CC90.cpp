{
  unsigned int v6; // eax@7
  MapTile *v8; // [sp+10h] [bp-4h]@2

  if ( a4 )
    v8 = (MapTile *)a4;
  else
    v8 = (MapTile *)usedToCheckForBoatByCastle(advManager, a1, a);
  if ( a <= 0 || a2 != 163 || *(_BYTE *)(usedToCheckForBoatByCastle(advManager, a1, a - 1) + 9) == 35 )
  {
    v8->objType = a2;
    LOWORD(v6) = 8 * a3 | v8->flags & 7;
    v8->flags = v6;
  }
  else
  {
    v8->objType = 0;
    v6 = (unsigned int)v8;
    *(_WORD *)(v6 + 4) &= 7u;
  }
  return v6;
}

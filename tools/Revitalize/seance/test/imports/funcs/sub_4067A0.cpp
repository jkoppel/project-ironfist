{
  bool result; // eax@2
  int v3; // [sp+Ch] [bp-10h]@9
  void *this; // [sp+10h] [bp-Ch]@1
  int knownHex; // [sp+14h] [bp-8h]@4
  int knownHexa; // [sp+14h] [bp-8h]@11
  int knownHexb; // [sp+14h] [bp-8h]@16
  int knownHexc; // [sp+14h] [bp-8h]@26
  int knownHexd; // [sp+14h] [bp-8h]@32
  int knownHexe; // [sp+14h] [bp-8h]@38
  int knownHexf; // [sp+14h] [bp-8h]@49
  signed int hexIdx; // [sp+18h] [bp-4h]@10
  signed int hexIdxa; // [sp+18h] [bp-4h]@15
  signed int hexIdxb; // [sp+18h] [bp-4h]@31
  signed int hexIdxc; // [sp+18h] [bp-4h]@37

  this = ecx0;
  if ( !checkHexGridIdxBounds(destHex) )
    return 0;
  *(_DWORD *)((char *)this + 98) = *(_DWORD *)((char *)this + 122);
  if ( !(*((_BYTE *)this + 208) & 1) )
  {
    *(_DWORD *)((char *)this + 90) = getNeighborOnPath(*(_DWORD *)((char *)this + 122), destHex, -64);
    knownHex = CreatureStack::getHexNeighbor(
                 (CreatureStack *)this,
                 *(_DWORD *)((char *)this + 122),
                 *(_DWORD *)((char *)this + 90));
    if ( knownHex == destHex )
      return 1;
    if ( CreatureStack::getHexNeighbor((CreatureStack *)this, knownHex, *(_DWORD *)((char *)this + 90)) == destHex )
      return 1;
    return 0;
  }
  v3 = *(_DWORD *)((char *)this + 134);
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      hexIdx = getNeighborOnPath(*(_DWORD *)((char *)this + 122), destHex, -64);
      if ( hexIdx > 2 )
      {
        *(_DWORD *)((char *)this + 90) = hexIdx;
        knownHexa = CreatureStack::getHexNeighbor((CreatureStack *)this, *(_DWORD *)((char *)this + 122), hexIdx);
        if ( knownHexa == destHex )
          return 1;
        if ( CreatureStack::getHexNeighbor((CreatureStack *)this, knownHexa, hexIdx) == destHex )
          return 1;
      }
      hexIdxa = getNeighborOnPath(*(_DWORD *)((char *)this + 122) + 1, destHex, -64);
      if ( hexIdxa < 3 )
      {
        *(_DWORD *)((char *)this + 90) = hexIdxa;
        knownHexb = CreatureStack::getHexNeighbor((CreatureStack *)this, *(_DWORD *)((char *)this + 122) + 1, hexIdxa);
        if ( knownHexb == destHex )
          return 1;
        if ( CreatureStack::getHexNeighbor((CreatureStack *)this, knownHexb, hexIdxa) == destHex )
          return 1;
      }
      if ( hexIdxa == 4 )
        return 0;
      if ( hexIdxa == 5 )
      {
        *(_DWORD *)((char *)this + 90) = 6;
      }
      else
      {
        if ( hexIdxa == 3 )
          *(_DWORD *)((char *)this + 90) = 7;
      }
      knownHexc = CreatureStack::getHexNeighbor((CreatureStack *)this, *(_DWORD *)((char *)this + 122) + 1, hexIdxa);
      if ( knownHexc == destHex )
        return 1;
      if ( CreatureStack::getHexNeighbor((CreatureStack *)this, knownHexc, hexIdxa) == destHex )
        return 1;
    }
    return 0;
  }
  hexIdxb = getNeighborOnPath(*(_DWORD *)((char *)this + 122), destHex, -64);
  if ( hexIdxb >= 3 )
  {
    hexIdxc = getNeighborOnPath(*(_DWORD *)((char *)this + 122) - 1, destHex, -64);
    if ( hexIdxc <= 2 )
    {
      if ( hexIdxc == 1 )
        return 0;
      if ( hexIdxc )
      {
        if ( hexIdxc == 2 )
          *(_DWORD *)((char *)this + 90) = 7;
      }
      else
      {
        *(_DWORD *)((char *)this + 90) = 6;
      }
      knownHexf = CreatureStack::getHexNeighbor((CreatureStack *)this, *(_DWORD *)((char *)this + 122) - 1, hexIdxc);
      if ( knownHexf == destHex )
        return 1;
      if ( CreatureStack::getHexNeighbor((CreatureStack *)this, knownHexf, hexIdxc) == destHex )
        return 1;
      return 0;
    }
    *(_DWORD *)((char *)this + 90) = hexIdxc;
    knownHexe = CreatureStack::getHexNeighbor((CreatureStack *)this, *(_DWORD *)((char *)this + 122) - 1, hexIdxc);
    if ( knownHexe == destHex )
      result = 1;
    else
      result = CreatureStack::getHexNeighbor((CreatureStack *)this, knownHexe, hexIdxc) == destHex;
  }
  else
  {
    *(_DWORD *)((char *)this + 90) = hexIdxb;
    knownHexd = CreatureStack::getHexNeighbor((CreatureStack *)this, *(_DWORD *)((char *)this + 122), hexIdxb);
    if ( knownHexd == destHex )
      result = 1;
    else
      result = CreatureStack::getHexNeighbor((CreatureStack *)this, knownHexd, hexIdxb) == destHex;
  }
  return result;
}

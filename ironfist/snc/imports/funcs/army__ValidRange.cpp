{
  bool result; // eax@2
  int v3; // [sp+Ch] [bp-10h]@9
  void *this; // [sp+10h] [bp-Ch]@1
  int knownHex; // [sp+14h] [bp-8h]@4
  int knownHexa; // [sp+14h] [bp-8h]@11
  int knownHexb; // [sp+14h] [bp-8h]@16
  int knownHexc; // [sp+14h] [bp-8h]@26
  int knownHexd; // [sp+14h] [bp-8h]@32
  int knownHexe; // [sp+14h] [bp-8h]@36
  int knownHexf; // [sp+14h] [bp-8h]@45
  signed int hexIdx; // [sp+18h] [bp-4h]@10
  signed int hexIdxa; // [sp+18h] [bp-4h]@15
  signed int hexIdxb; // [sp+18h] [bp-4h]@31
  signed int hexIdxc; // [sp+18h] [bp-4h]@35

  this = ecx0;
  if ( !ValidHex(destHex) )
    return 0;
  *(_DWORD *)((char *)this + 98) = *(_DWORD *)((char *)this + 122);
  if ( !(*((_BYTE *)this + 208) & 1) )
  {
    *(_DWORD *)((char *)this + 90) = army::GetBestDirection(*(_DWORD *)((char *)this + 122), destHex, -64);
    knownHex = army::GetAdjacentCellIndex((army *)this, *(_DWORD *)((char *)this + 122), *(_DWORD *)((char *)this + 90));
    if ( knownHex == destHex )
      return 1;
    if ( army::GetAdjacentCellIndex((army *)this, knownHex, *(_DWORD *)((char *)this + 90)) == destHex )
      return 1;
    return 0;
  }
  v3 = *(_DWORD *)((char *)this + 134);
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      hexIdx = army::GetBestDirection(*(_DWORD *)((char *)this + 122), destHex, -64);
      if ( hexIdx > 2 )
      {
        *(_DWORD *)((char *)this + 90) = hexIdx;
        knownHexa = army::GetAdjacentCellIndex((army *)this, *(_DWORD *)((char *)this + 122), hexIdx);
        if ( knownHexa == destHex )
          return 1;
        if ( army::GetAdjacentCellIndex((army *)this, knownHexa, hexIdx) == destHex )
          return 1;
      }
      hexIdxa = army::GetBestDirection(*(_DWORD *)((char *)this + 122) + 1, destHex, -64);
      if ( hexIdxa < 3 )
      {
        *(_DWORD *)((char *)this + 90) = hexIdxa;
        knownHexb = army::GetAdjacentCellIndex((army *)this, *(_DWORD *)((char *)this + 122) + 1, hexIdxa);
        if ( knownHexb == destHex )
          return 1;
        if ( army::GetAdjacentCellIndex((army *)this, knownHexb, hexIdxa) == destHex )
          return 1;
      }
      if ( hexIdxa == 4 )
        return 0;
      if ( hexIdxa == 5 )
      {
        *(_DWORD *)((char *)this + 90) = 6;
      }
      else if ( hexIdxa == 3 )
      {
        *(_DWORD *)((char *)this + 90) = 7;
      }
      knownHexc = army::GetAdjacentCellIndex((army *)this, *(_DWORD *)((char *)this + 122) + 1, hexIdxa);
      if ( knownHexc == destHex )
        return 1;
      if ( army::GetAdjacentCellIndex((army *)this, knownHexc, hexIdxa) == destHex )
        return 1;
    }
    return 0;
  }
  hexIdxb = army::GetBestDirection(*(_DWORD *)((char *)this + 122), destHex, -64);
  if ( hexIdxb >= 3 )
  {
    hexIdxc = army::GetBestDirection(*(_DWORD *)((char *)this + 122) - 1, destHex, -64);
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
      knownHexf = army::GetAdjacentCellIndex((army *)this, *(_DWORD *)((char *)this + 122) - 1, hexIdxc);
      if ( knownHexf == destHex )
        return 1;
      if ( army::GetAdjacentCellIndex((army *)this, knownHexf, hexIdxc) == destHex )
        return 1;
      return 0;
    }
    *(_DWORD *)((char *)this + 90) = hexIdxc;
    knownHexe = army::GetAdjacentCellIndex((army *)this, *(_DWORD *)((char *)this + 122) - 1, hexIdxc);
    if ( knownHexe == destHex )
      result = 1;
    else
      result = army::GetAdjacentCellIndex((army *)this, knownHexe, hexIdxc) == destHex;
  }
  else
  {
    *(_DWORD *)((char *)this + 90) = hexIdxb;
    knownHexd = army::GetAdjacentCellIndex((army *)this, *(_DWORD *)((char *)this + 122), hexIdxb);
    if ( knownHexd == destHex )
      result = 1;
    else
      result = army::GetAdjacentCellIndex((army *)this, knownHexd, hexIdxb) == destHex;
  }
  return result;
}
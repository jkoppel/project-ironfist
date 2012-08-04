{
  signed int result; // eax@5
  int v4; // [sp+14h] [bp-14h]@1
  int v5; // [sp+18h] [bp-10h]@1
  int v6; // [sp+24h] [bp-4h]@6

  v5 = normalDirTable[4 * a3] + *(_DWORD *)(a2 + 25);
  v4 = byte_4F1DC1[4 * a3] + *(_DWORD *)(a2 + 29);
  if ( v5 >= 0 && MAP_WIDTH - 1 >= v5 && v4 >= 0 && MAP_HEIGHT - 1 >= v4 )
  {
    v6 = **(_DWORD **)(this + 174) + 12 * v4 * *(_DWORD *)(*(_DWORD *)(this + 174) + 8) + 12 * v5;
    if ( (*(_BYTE *)(v6 + 9) & 0x7F) == 42 )
    {
      if ( *(_BYTE *)(a2 + 227) & 0x80 )
        result = (gpGame->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v6 + 4) >> 8) >> -5)].flags1 & 0x80) != 0;
      else
        result = 1;
    }
    else
    {
      result = advManager::ValidMove(this, a3, 1);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
signed int __thiscall sub_4C1CB0(int this, int a2, int a3)
{
  signed int result; // eax@5
  int v4; // [sp+14h] [bp-14h]@1
  int v5; // [sp+18h] [bp-10h]@1
  int v6; // [sp+24h] [bp-4h]@6

  v5 = byte_4F1DC0[4 * a3] + *(_DWORD *)(a2 + 25);
  v4 = byte_4F1DC1[4 * a3] + *(_DWORD *)(a2 + 29);
  if ( v5 >= 0 && mapWidth - 1 >= v5 && v4 >= 0 && mapHeight - 1 >= v4 )
  {
    v6 = **(_DWORD **)(this + 174) + 12 * v4 * *(_DWORD *)(*(_DWORD *)(this + 174) + 8) + 12 * v5;
    if ( (*(_BYTE *)(v6 + 9) & 0x7F) == 42 )
    {
      if ( *(_BYTE *)(a2 + 227) & 0x80 )
      {
        if ( gameObject->heroes[(unsigned __int8)((unsigned __int8)(*(_WORD *)(v6 + 4) >> 8) >> -5)].flags1 & 0x80 )
          result = 1;
        else
          result = 0;
      }
      else
      {
        result = 1;
      }
    }
    else
    {
      result = sub_4C1E00(this, a3, 1);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

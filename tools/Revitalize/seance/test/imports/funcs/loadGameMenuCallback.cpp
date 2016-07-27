{
  CREATURE_FLAGS v2; // [sp+14h] [bp-Ch]@4
  void *v3; // [sp+18h] [bp-8h]@1
  signed int v4; // [sp+1Ch] [bp-4h]@4

  v3 = (void *)this;
  if ( *(_BYTE *)(this + 13) & 2 && (*(_DWORD *)(this + 4) == 12 || *(_DWORD *)(this + 4) == 14) )
  {
    v4 = -1;
    v2 = *(_DWORD *)(this + 8);
    if ( v2 <= (CREATURE_PETRIFIED|CREATURE_BROWN|TWO_HEXER|0x1800) )
    {
      switch ( v2 )
      {
        case 30721:
          v4 = 3;
          break;
        case 1:
          v4 = 0;
          break;
        case 2:
          v4 = 1;
          break;
        case 3:
          v4 = 2;
          break;
      }
    }
    if ( v4 >= 0 )
      display_message_window((&off_4F6858)[4 * v4], TRANSIENT_FOR_RIGHT_CLICKS, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  return sub_4BC6C0(v3);
}

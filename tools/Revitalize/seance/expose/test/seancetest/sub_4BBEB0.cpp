signed int __thiscall sub_4BBEB0(int this)
{
  signed int v2; // [sp+Ch] [bp-Ch]@4
  void *v3; // [sp+10h] [bp-8h]@1
  signed int v4; // [sp+14h] [bp-4h]@4

  v3 = (void *)this;
  if ( *(_BYTE *)(this + 13) & 2 && (*(_DWORD *)(this + 4) == 12 || *(_DWORD *)(this + 4) == 14) )
  {
    v4 = -1;
    v2 = *(_DWORD *)(this + 8);
    if ( v2 <= 30721 )
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
    {
      if ( dword_4F7478 )
        display_message_window((&off_4F6810)[4 * v4], 4, -1, -1, -1, 0, -1, 0, -1, 0);
      else
        display_message_window((&off_4F6800)[4 * v4], 4, -1, -1, -1, 0, -1, 0, -1, 0);
    }
  }
  return sub_4BC6C0(v3);
}

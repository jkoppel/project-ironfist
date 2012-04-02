signed int __thiscall sub_4BC0F0(int this)
{
  int v2; // [sp+Ch] [bp-Ch]@4
  void *v3; // [sp+10h] [bp-8h]@1
  signed int v4; // [sp+14h] [bp-4h]@4

  v3 = (void *)this;
  if ( *(_BYTE *)(this + 13) & 2 && (*(_DWORD *)(this + 4) == 12 || *(_DWORD *)(this + 4) == 14) )
  {
    v4 = -1;
    v2 = *(_DWORD *)(this + 8);
    switch ( v2 )
    {
      case 1:
        v4 = 0;
        break;
      case 2:
        v4 = 1;
        break;
      case 30721:
        v4 = 2;
        break;
    }
    if ( v4 >= 0 )
      display_message_window((&off_4F6838)[4 * v4], 4, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  return sub_4BC6C0(v3);
}

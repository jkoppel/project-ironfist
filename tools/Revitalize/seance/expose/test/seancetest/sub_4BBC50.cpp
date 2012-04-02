signed int __thiscall sub_4BBC50(int this)
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
      if ( v2 == 30721 )
      {
        v4 = 4;
      }
      else
      {
        switch ( v2 )
        {
          case 1:
            v4 = 0;
            break;
          case 2:
            v4 = 1;
            break;
          case 3:
            v4 = 2;
            break;
          case 4:
            v4 = 3;
            break;
          default:
            break;
        }
      }
    }
    if ( v4 >= 0 )
    {
      if ( dword_4F7478 )
        display_message_window((&off_4F67B8)[4 * v4], 4, -1, -1, -1, 0, -1, 0, -1, 0);
      else
        display_message_window((&off_4F6788)[4 * v4], 4, -1, -1, -1, 0, -1, 0, -1, 0);
    }
  }
  return sub_4BC6C0(v3);
}

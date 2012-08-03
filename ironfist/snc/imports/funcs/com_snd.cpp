{
  __int16 v5; // [sp+10h] [bp-Ch]@1
  int v6; // [sp+18h] [bp-4h]@8

  v5 = this;
  if ( dword_532CF0[24 * this] == -1 )
    return 1;
  if ( a2 )
  {
    v6 = (int)BaseAlloc(a2 + 10, "F:\\h2xsrc\\Source\\comwin.cpp", word_51DFF8 + 16);
    if ( v6 )
    {
      *(_WORD *)(v6 + 8) = a2;
      memcpy((void *)(v6 + 10), a3, a2);
      if ( a4 )
        add_node((int)&dword_532D48[24 * v5], v6);
      else
        add_node((int)&dword_532D40[24 * v5], v6);
      return 0;
    }
    return 1;
  }
  if ( !SetCommBreak((HANDLE)dword_532CF0[24 * this]) )
    ShutdownComError("Set communications break");
  Sleep(0x1F4u);
  if ( !ClearCommBreak((HANDLE)dword_532CF0[24 * v5]) )
    ShutdownComError("Clear communications break");
  return 0;
}
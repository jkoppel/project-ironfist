signed __int16 __thiscall sub_4BD1A0(__int16 this, unsigned __int16 a2, const void *a3, int a4)
{
  __int16 v5; // [sp+10h] [bp-Ch]@1
  int v6; // [sp+18h] [bp-4h]@8

  v5 = this;
  if ( dword_532CF0[24 * this] == -1 )
    return 1;
  if ( a2 )
  {
    v6 = (int)KBAlloc(a2 + 10, "F:\\h2xsrc\\Source\\comwin.cpp", word_51DFF8 + 16);
    if ( v6 )
    {
      *(_WORD *)(v6 + 8) = a2;
      memcpy((void *)(v6 + 10), a3, a2);
      if ( a4 )
        sub_4BC7B0((int)&dword_532D48[24 * v5], v6);
      else
        sub_4BC7B0((int)&dword_532D40[24 * v5], v6);
      return 0;
    }
    return 1;
  }
  if ( !SetCommBreak((HANDLE)dword_532CF0[24 * this]) )
    sub_4BC8B0("Set communications break");
  Sleep(0x1F4u);
  if ( !ClearCommBreak((HANDLE)dword_532CF0[24 * v5]) )
    sub_4BC8B0("Clear communications break");
  return 0;
}

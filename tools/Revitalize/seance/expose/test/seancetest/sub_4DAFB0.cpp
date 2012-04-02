void __thiscall sub_4DAFB0(int this)
{
  int v1; // esi@1
  __int16 v2; // dx@2
  int v3; // eax@3

  v1 = this;
  Icon::drawToScreen(
    *(Icon **)(v1 + 36),
    *(_DWORD *)(*(_DWORD *)(this + 4) + 40) + *(_WORD *)(v1 + 108),
    *(_DWORD *)(*(_DWORD *)(this + 4) + 44) + *(_WORD *)(v1 + 110),
    *(_WORD *)(this + 72),
    0);
  Icon::drawToScreen(
    *(Icon **)(v1 + 36),
    *(_DWORD *)(*(_DWORD *)(v1 + 4) + 40) + *(_WORD *)(v1 + 100),
    *(_DWORD *)(*(_DWORD *)(v1 + 4) + 44) + *(_WORD *)(v1 + 102),
    *(_WORD *)(v1 + 74),
    0);
  if ( *(_WORD *)(v1 + 60) > 0 )
  {
    v2 = *(_WORD *)(v1 + 62);
    if ( v2 >= 0 )
    {
      v3 = 3;
      if ( !(*(_BYTE *)(v1 + 22) & 8) )
        v3 = *(_WORD *)(v1 + 52);
      Font::drawString(
        *(Font **)(v1 + 32),
        *(const char **)(*(_DWORD *)(v1 + 64) + 4 * v2),
        *(_DWORD *)(*(_DWORD *)(v1 + 4) + 40) + *(_WORD *)(v1 + 40),
        *(_DWORD *)(*(_DWORD *)(v1 + 4) + 44) + *(_WORD *)(v1 + 42),
        *(_WORD *)(v1 + 44),
        *(_WORD *)(v1 + 46),
        v3,
        *(_WORD *)(v1 + 58));
    }
  }
}

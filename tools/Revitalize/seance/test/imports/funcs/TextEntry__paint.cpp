{
  int v1; // ebp@1
  unsigned int i; // esi@2
  int v3; // eax@5
  char v4; // [sp+Fh] [bp-259h]@3
  char str; // [sp+10h] [bp-258h]@2

  v1 = this;
  if ( *(_WORD *)(this + 73) == 3 )
  {
    strcpy(&str, (const char *)(*(_DWORD *)(this + 32) + *(_WORD *)(this + 75)));
    for ( i = strlen(&str); Font::getFlattenedStringWidth(*(Font **)(v1 + 36), &str) > *(_WORD *)(v1 + 61); --i )
      *(&v4 + i) = 0;
    Icon::drawToScreen(
      *(Icon **)(v1 + 43),
      *(_DWORD *)(*(_DWORD *)(v1 + 4) + 40) + *(_WORD *)(v1 + 53),
      *(_DWORD *)(*(_DWORD *)(v1 + 4) + 44) + *(_WORD *)(v1 + 55),
      *(_WORD *)(v1 + 47),
      0);
    Font::drawString(
      *(Font **)(v1 + 36),
      &str,
      *(_DWORD *)(*(_DWORD *)(v1 + 4) + 40) + *(_WORD *)(v1 + 65),
      *(_DWORD *)(*(_DWORD *)(v1 + 4) + 44) + *(_WORD *)(v1 + 67),
      *(_WORD *)(v1 + 61),
      *(_WORD *)(v1 + 63),
      *(_WORD *)(v1 + 40),
      *(_BYTE *)(v1 + 42));
  }
  else
  {
    Icon::drawToScreen(
      *(Icon **)(this + 43),
      *(_DWORD *)(*(_DWORD *)(this + 4) + 40) + *(_WORD *)(this + 53),
      *(_DWORD *)(*(_DWORD *)(this + 4) + 44) + *(_WORD *)(this + 55),
      *(_WORD *)(this + 47),
      0);
    v3 = 3;
    if ( !(*(_BYTE *)(v1 + 22) & 8) )
      v3 = *(_WORD *)(v1 + 40);
    Font::drawString(
      *(Font **)(v1 + 36),
      *(const char **)(v1 + 32),
      *(_DWORD *)(*(_DWORD *)(v1 + 4) + 40) + *(_WORD *)(v1 + 65),
      *(_DWORD *)(*(_DWORD *)(v1 + 4) + 44) + *(_WORD *)(v1 + 67),
      *(_WORD *)(v1 + 61),
      *(_WORD *)(v1 + 63),
      v3,
      *(_BYTE *)(v1 + 42));
  }
}

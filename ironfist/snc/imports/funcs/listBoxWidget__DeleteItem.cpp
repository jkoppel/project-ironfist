{
  __int16 v2; // dx@1
  int v3; // ebx@1
  int v4; // ecx@1
  __int16 v5; // ax@4
  unsigned __int8 v6; // sf@7
  __int16 v7; // ax@11
  void *v8; // ecx@17
  __int16 v9; // ax@20
  unsigned __int8 v10; // zf@20
  void *v11; // [sp+10h] [bp-4h]@15

  v2 = *(_WORD *)(this + 50);
  v3 = this;
  v4 = *(_WORD *)(this + 50);
  if ( v4 > a2 )
  {
    if ( *(_WORD *)(v3 + 52) == a2 )
      *(_WORD *)(v3 + 52) = -1;
    v5 = *(_WORD *)(v3 + 64);
    if ( *(_WORD *)(v3 + 64) == a2 && *(_WORD *)(v3 + 66) <= v5 )
      *(_WORD *)(v3 + 64) = v5 - 1;
    v6 = (signed __int16)((*(_WORD *)(v3 + 66))-- - 1) < 0;
    if ( v6 )
      *(_WORD *)(v3 + 66) = 0;
    if ( *(_WORD *)(v3 + 64) < 0 )
      *(_WORD *)(v3 + 64) = 0;
    v7 = *(_WORD *)(v3 + 66);
    if ( *(_WORD *)(v3 + 64) > v7 )
      *(_WORD *)(v3 + 64) = v7;
    if ( v2 == 1 )
    {
      BaseFree(**(void ***)(v3 + 60), (int)"F:\\h2xsrc\\Base\\listbox.cpp", 156);
      BaseFree(*(void **)(v3 + 60), (int)"F:\\h2xsrc\\Base\\listbox.cpp", 157);
      *(_DWORD *)(v3 + 60) = 0;
    }
    else
    {
      v11 = BaseAlloc(4 * v4 - 4, "F:\\h2xsrc\\Base\\listbox.cpp", 162);
      memcpy(v11, *(const void **)(v3 + 60), 4 * ((unsigned int)(4 * *(_WORD *)(v3 + 50) - 4) >> 2));
      if ( *(_WORD *)(v3 + 50) - a2 - 1 > 0 )
        memcpy(
          (char *)v11 + 4 * a2,
          (const void *)(*(_DWORD *)(v3 + 60) + 4 * a2 + 4),
          4 * ((unsigned int)(4 * (*(_WORD *)(v3 + 50) - a2 - 1)) >> 2));
      v8 = *(void **)(v3 + 60);
      if ( v8 )
        BaseFree(v8, (int)"F:\\h2xsrc\\Base\\listbox.cpp", 169);
      *(_DWORD *)(v3 + 60) = v11;
    }
    v9 = *(_WORD *)(v3 + 50) - 1;
    v10 = *(_WORD *)(v3 + 66) == 0;
    v6 = *(_WORD *)(v3 + 66) < 0;
    *(_WORD *)(v3 + 50) = v9;
    if ( v6 | v10 )
      *(_WORD *)(v3 + 42) = v9;
    else
      *(_WORD *)(v3 + 42) = *(_WORD *)(v3 + 40);
  }
}
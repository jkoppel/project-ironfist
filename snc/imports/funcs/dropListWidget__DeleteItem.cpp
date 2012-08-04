{
  int v2; // ebp@1
  __int16 v3; // ax@1
  int v4; // esi@1
  void *v5; // ecx@8
  void *v6; // [sp+10h] [bp-4h]@6

  v2 = this;
  v3 = *(_WORD *)(this + 60);
  v4 = *(_WORD *)(this + 60);
  if ( a2 < v4 )
  {
    if ( *(_WORD *)(this + 62) == a2 )
      *(_WORD *)(this + 62) = -1;
    if ( v3 == 1 )
    {
      BaseFree(**(void ***)(this + 64), (int)"F:\\h2xsrc\\Base\\droplist.cpp", 111);
      BaseFree(*(void **)(v2 + 64), (int)"F:\\h2xsrc\\Base\\droplist.cpp", 112);
      *(_DWORD *)(v2 + 64) = 0;
    }
    else
    {
      v6 = BaseAlloc(4 * v4 - 4, "F:\\h2xsrc\\Base\\droplist.cpp", 117);
      memcpy(v6, *(const void **)(v2 + 64), 4 * ((unsigned int)(4 * *(_WORD *)(v2 + 60) - 4) >> 2));
      if ( *(_WORD *)(v2 + 60) - a2 - 1 > 0 )
        memcpy(
          (char *)v6 + 4 * a2,
          (const void *)(*(_DWORD *)(v2 + 64) + 4 * a2 + 4),
          4 * ((unsigned int)(4 * (*(_WORD *)(v2 + 60) - a2 - 1)) >> 2));
      v5 = *(void **)(v2 + 64);
      if ( v5 )
        BaseFree(v5, (int)"F:\\h2xsrc\\Base\\droplist.cpp", 123);
      *(_DWORD *)(v2 + 64) = v6;
    }
    --*(_WORD *)(v2 + 60);
  }
}
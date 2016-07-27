{
  int result; // eax@7
  int v2; // [sp+Ch] [bp-1Ch]@1

  v2 = this;
  if ( *(_DWORD *)(this + 670) )
    operator delete(*(void **)(this + 670));
  *(_DWORD *)(v2 + 670) = 0;
  if ( *(_DWORD *)(v2 + 674) )
    operator delete(*(void **)(v2 + 674));
  *(_DWORD *)(v2 + 674) = 0;
  if ( *(_DWORD *)(v2 + 678) )
    operator delete(*(void **)(v2 + 678));
  result = v2;
  *(_DWORD *)(v2 + 678) = 0;
  return result;
}

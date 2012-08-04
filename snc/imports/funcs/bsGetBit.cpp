{
  int result; // eax@2
  int v2; // [sp+Ch] [bp-8h]@1
  signed int v3; // [sp+10h] [bp-4h]@3

  v2 = this;
  if ( *(_DWORD *)(this + 8) <= 0 )
  {
    v3 = getc(*(_DWORD *)this);
    if ( v3 == -1 )
      compressedStreamEOF();
    *(_DWORD *)(v2 + 8) = 7;
    *(_DWORD *)(v2 + 4) = v3;
    if ( *(_DWORD *)(v2 + 4) == -1 )
      bitStreamEOF();
    result = (*(_DWORD *)(v2 + 4) >> 7) & 1;
  }
  else
  {
    --*(_DWORD *)(this + 8);
    result = (*(_DWORD *)(this + 4) >> *(_BYTE *)(this + 8)) & 1;
  }
  return result;
}
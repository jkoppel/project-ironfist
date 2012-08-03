{
  int result; // eax@4
  char v3; // [sp+Ch] [bp-Ch]@1
  int v4; // [sp+10h] [bp-8h]@1

  v3 = a2;
  v4 = a1;
  if ( *(_DWORD *)(a1 + 8) == 8 )
  {
    if ( putc(*(_BYTE *)(a1 + 4), *(_DWORD *)a1) == -1 )
      ioError();
    ++bytesOut;
    *(_DWORD *)(v4 + 8) = 1;
    result = v3 & 1;
    *(_DWORD *)(v4 + 4) = result;
  }
  else
  {
    *(_DWORD *)(a1 + 4) = a2 & 1 | 2 * *(_DWORD *)(a1 + 4);
    result = a1;
    ++*(_DWORD *)(result + 8);
  }
  return result;
}
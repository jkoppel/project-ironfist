{
  void *v1; // [sp+Ch] [bp-8h]@1

  v1 = this;
  if ( !bsInUse )
    panic();
  bsInUse = 0;
  if ( *((_BYTE *)v1 + 12) == 119 )
  {
    while ( *((_DWORD *)v1 + 2) < 8 )
    {
      ++*((_DWORD *)v1 + 2);
      *((_DWORD *)v1 + 1) *= 2;
    }
    if ( putc(*((_BYTE *)v1 + 4), *(_DWORD *)v1) == -1 )
      ioError();
    ++bytesOut;
    if ( fflush(*(_DWORD *)v1) == -1 )
      ioError();
  }
  if ( *(_BYTE *)(*(_DWORD *)v1 + 12) & 0x20 )
    ioError();
  if ( fclose(*(_DWORD *)v1) == -1 )
    ioError();
}
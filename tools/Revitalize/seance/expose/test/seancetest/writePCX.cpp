void __fastcall writePCX(const char *filename, _BYTE *bmpContents, int width, int height, _BYTE *palContents)
{
  _BYTE *bmpContentsa; // esi@1
  _BYTE *row; // ebp@2
  int v7; // eax@4
  unsigned int v8; // ebx@4
  char v9; // cl@5
  int i; // edi@5
  int v11; // edi@9
  _BYTE *denormalizedPalletteContents; // esi@15
  signed int v13; // ecx@15
  char v14; // dl@16
  char v15; // [sp+13h] [bp-89h]@15
  int fd; // [sp+14h] [bp-88h]@1
  int v17; // [sp+18h] [bp-84h]@3
  char pcxHeader[128]; // [sp+1Ch] [bp-80h]@1

  bmpContentsa = bmpContents;
  memset(pcxHeader, 0, sizeof(pcxHeader));
  pcxHeader[0] = 10;
  *(_WORD *)&pcxHeader[8] = width - 1;
  pcxHeader[2] = 1;
  *(_WORD *)&pcxHeader[66] = width;
  *(_WORD *)&pcxHeader[10] = height - 1;
  pcxHeader[65] = 1;
  *(_WORD *)&pcxHeader[68] = 1;
  pcxHeader[1] = 5;
  pcxHeader[3] = 8;
  fd = _open(filename, 33537, 128);
  if ( fd != -1 )
  {
    _write(fd, pcxHeader, 0x80u);
    row = KBAlloc(2 * width, "F:\\h2xsrc\\Base\\Misc.cpp", 1480);
    if ( height > 0 )
    {
      v17 = height;
      do
      {
        v7 = 0;
        v8 = 0;
        while ( v7 < width )
        {
          v9 = bmpContentsa[v7];
          for ( i = v7; i < width; ++i )
          {
            if ( bmpContentsa[i] != v9 )
              break;
            if ( i - v7 + 1 >= 64 )
              break;
          }
          v11 = i - v7;
          if ( v11 > 1 || (v9 & 0xC0) == -64 )
          {
            v8 += 2;
            v7 += v11;
            row[v8 - 2] = v11 | 0xC0;
            row[v8 - 1] = v9;
          }
          else
          {
            row[v8++] = v9;
            ++v7;
          }
        }
        _write(fd, row, v8);
        bmpContentsa += width;
        --v17;
      }
      while ( v17 );
    }
    KBFree(row, (int)"F:\\h2xsrc\\Base\\Misc.cpp", 1520);
    v15 = 12;
    _write(fd, &v15, 1u);
    denormalizedPalletteContents = KBAlloc(0x300u, "F:\\h2xsrc\\Base\\Misc.cpp", 1526);
    v13 = 0;
    do
    {
      v14 = palContents[v13++];
      denormalizedPalletteContents[v13 - 1] = 4 * v14;
    }
    while ( v13 < 768 );
    _write(fd, denormalizedPalletteContents, 0x300u);
    KBFree(denormalizedPalletteContents, (int)"F:\\h2xsrc\\Base\\Misc.cpp", 1531);
    _close(fd);
  }
}

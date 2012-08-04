{
  bitmap *bmpa; // ebp@1
  unsigned __int8 *row; // ecx@1
  void *offsetRow; // ecx@1
  int v9; // edi@2
  int v10; // eax@2

  bmpa = bmp;
  row = &bmp->contents[y * bmp->width];
  dword_537948 = 0;
  offsetRow = &row[x];
  dword_53794C = (int)offsetRow;
  if ( height > 0 )
  {
    do
    {
      v9 = dword_53794C;
      BYTE1(offsetRow) = a6;
      LOBYTE(offsetRow) = a6;
      v10 = (_DWORD)offsetRow << 16;
      LOWORD(v10) = (_WORD)offsetRow;
      memset32((void *)dword_53794C, v10, width >> 2);
      memset((void *)(v9 + 4 * (width >> 2)), a6, width & 3);
      offsetRow = (void *)(dword_537948 + 1);
      dword_53794C += bmpa->width;
      dword_537948 = (int)offsetRow;
    }
    while ( (signed int)offsetRow < height );
  }
}
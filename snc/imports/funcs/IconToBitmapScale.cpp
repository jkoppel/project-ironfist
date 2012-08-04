{
  int v11; // esi@1
  int result; // eax@2
  bitmap *v13; // eax@3
  signed int v14; // edx@6
  int v15; // edx@8
  int v16; // edi@10
  int v17; // esi@10
  signed int v18; // eax@11
  char v19; // zf@15
  bitmap *bmp; // [sp+10h] [bp-18h]@4
  int icn; // [sp+14h] [bp-14h]@1
  signed int icna; // [sp+14h] [bp-14h]@9
  unsigned __int8 *v23; // [sp+18h] [bp-10h]@6
  int v24; // [sp+18h] [bp-10h]@8
  int v25; // [sp+1Ch] [bp-Ch]@8

  icn = a1;
  v11 = a2;
  if ( a11 == 32 )
  {
    result = IconToBitmap((icon *)a1, (bitmap *)a2, a3, a4, a5, a6, a7, a8, a9, a10, 0);
  }
  else
  {
    v13 = (bitmap *)operator new(26);
    if ( v13 )
      bmp = bitmap::bitmap(v13, 0, 64, 64);
    else
      bmp = 0;
    v14 = 0;
    v23 = bmp->contents;
    do
    {
      memset(&v23[v14], 0, 0x20u);
      v14 += 32;
    }
    while ( v14 < 2048 );
    IconToBitmap((icon *)icn, bmp, 0, 0, a5, 1, 0, 0, 0x20u, 32, 0);
    v24 = *(_WORD *)(v11 + 18);
    v25 = *(_DWORD *)(v11 + 22) + *(_WORD *)(v11 + 18) * a4 + a3;
    v15 = (int)&bmp->contents[65 * ((32 / a11 * (1 - a11) + 32) >> 1)];
    if ( a11 > 0 )
    {
      icna = a11;
      do
      {
        v16 = v15;
        v17 = v25;
        if ( a11 > 0 )
        {
          v18 = a11;
          do
          {
            if ( *(_BYTE *)v16 )
              *(_BYTE *)v17 = *(_BYTE *)v16;
            ++v17;
            v16 += 32 / a11;
            --v18;
          }
          while ( v18 );
        }
        v15 += 32 / a11 << 6;
        v19 = icna == 1;
        v25 += v24;
        --icna;
      }
      while ( !v19 );
    }
    result = (int)bmp;
    if ( bmp )
      result = ((int (__fastcall *)(bitmap *, int, signed int))bmp->vtable->cleanUp)(bmp, v15, 1);
  }
  return result;
}
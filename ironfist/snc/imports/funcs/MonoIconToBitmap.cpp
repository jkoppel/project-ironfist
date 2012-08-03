{
  ICNHeader *v11; // esi@1
  int v12; // ecx@1
  int v13; // eax@1
  int v14; // esi@1
  int v15; // edi@1
  int v16; // esi@1
  int v17; // eax@5
  int v18; // ecx@5
  unsigned int v19; // ecx@9
  int v20; // ebp@9
  int result; // eax@10
  unsigned int v22; // edx@10
  int v23; // edx@11
  int v24; // eax@15
  int v25; // edi@15
  int v26; // eax@18
  int v27; // ST10_4@23
  int v28; // ecx@25
  unsigned int v29; // ecx@25
  int v30; // [sp+14h] [bp-4h]@9

  v11 = a1->headersAndImageData;
  v12 = (int)&v11[a5];
  dword_537A18 = v12;
  v13 = (int)((char *)v11 + *(_DWORD *)(v12 + 9));
  v14 = *(_WORD *)v12;
  v15 = *(_WORD *)(v12 + 2);
  dword_537A08 = v13;
  v16 = v14 + a3;
  dword_537A04 = v16;
  dword_537A00 = v15 + a4;
  if ( !a7 )
    goto LABEL_9;
  if ( a8 > dword_537A04 || dword_537A04 + *(_WORD *)(v12 + 4) > (signed int)(a8 + a10) || dword_537A00 < a9 )
  {
    v18 = a11;
    goto LABEL_8;
  }
  v17 = dword_537A00 + *(_WORD *)(v12 + 6);
  v18 = a11;
  if ( v17 > a11 + a9 )
  {
LABEL_8:
    a7 = 1;
    dword_537A10 = a8 + a10 - 1;
    dword_537A14 = a9 + v18 - 1;
    goto LABEL_9;
  }
  a7 = 0;
LABEL_9:
  v19 = (unsigned int)a2->contents;
  v20 = v19 + a2->width * dword_537A00;
  v30 = a2->width;
  while ( 1 )
  {
    while ( 1 )
    {
      result = dword_537A08 + 1;
      dword_5379F8 = v16;
      dword_537A08 = result;
      v22 = *(_BYTE *)(result - 1);
      if ( (char)v22 < 0 )
        break;
      dword_5379FC = *(_BYTE *)(result - 1);
      if ( v22 )
      {
        if ( !a7 )
        {
          BYTE1(v19) = a6;
          LOBYTE(v19) = a6;
          v24 = v19 << 16;
          LOWORD(v24) = v19;
          memset32((void *)(v20 + v16), v24, v22 >> 2);
          v25 = v20 + v16 + 4 * (v22 >> 2);
          LOBYTE(v19) = v22;
LABEL_27:
          memset((void *)v25, v24, v19 & 3);
          HIWORD(v19) = 0;
          goto LABEL_28;
        }
        HIWORD(v19) = HIWORD(a9);
        if ( dword_537A00 >= a9 )
        {
          HIWORD(v19) = HIWORD(dword_537A14);
          if ( dword_537A00 <= dword_537A14 )
          {
            v26 = v22 + v16;
            HIWORD(v19) = HIWORD(a8);
            if ( a8 < (signed int)(v22 + v16) )
            {
              HIWORD(v19) = HIWORD(dword_537A10);
              if ( v16 <= dword_537A10 )
              {
                HIWORD(v19) = HIWORD(dword_537A10);
                if ( v16 < a8 )
                {
                  if ( v26 > dword_537A10 )
                  {
                    BYTE1(v19) = a6;
                    LOBYTE(v19) = a6;
                    v24 = v19 << 16;
                    LOWORD(v24) = v19;
                    memset32((void *)(v20 + a8), v24, a10 >> 2);
                    v25 = v20 + a8 + 4 * (a10 >> 2);
                    LOBYTE(v19) = a10;
                  }
                  else
                  {
                    v28 = v22 + v16 - a8;
                    BYTE1(v28) = a6;
                    LOBYTE(v28) = a6;
                    v24 = v28 << 16;
                    LOWORD(v24) = v28;
                    v29 = (v22 + v16 - a8) >> 2;
                    memset32((void *)(v20 + a8), v24, v29);
                    v25 = v20 + a8 + 4 * v29;
                    v19 = v22 + v16 - a8;
                  }
                }
                else if ( v26 > dword_537A10 )
                {
                  BYTE1(v19) = a6;
                  LOBYTE(v19) = a6;
                  v27 = dword_537A10 - v16 + 1;
                  v24 = v19 << 16;
                  LOWORD(v24) = v19;
                  v19 = (unsigned int)(dword_537A10 - v16 + 1) >> 2;
                  memset32((void *)(v20 + v16), v24, v19);
                  v25 = v20 + v16 + 4 * v19;
                  LOBYTE(v19) = v27;
                }
                else
                {
                  BYTE1(v19) = a6;
                  LOBYTE(v19) = a6;
                  v24 = v19 << 16;
                  LOWORD(v24) = v19;
                  memset32((void *)(v20 + v16), v24, v22 >> 2);
                  v25 = v20 + v16 + 4 * (v22 >> 2);
                  LOBYTE(v19) = v22;
                }
                goto LABEL_27;
              }
            }
          }
        }
LABEL_28:
        v16 += v22;
        dword_5379FC = v22;
      }
      else
      {
        v16 = dword_537A04;
        v20 += v30;
        v19 = dword_537A00++ + 1;
      }
    }
    dword_537A0C = v20;
    dword_5379FC = v22;
    v23 = v22 & 0x7F;
    if ( !v23 )
      return result;
    v16 += v23;
  }
}
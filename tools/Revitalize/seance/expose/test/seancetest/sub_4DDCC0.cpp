int __fastcall sub_4DDCC0(int a1, int a2, int a3, int a4, int a5, char a6, signed int a7, int a8, int a9, int a10, int a11)
{
  int v11; // edi@1
  int v12; // ecx@1
  int v13; // esi@1
  int v14; // eax@1
  int v15; // edi@1
  int v16; // eax@1
  int v17; // ebx@1
  int v18; // edi@1
  int v19; // eax@1
  int v20; // eax@5
  int v21; // esi@5
  int v22; // ecx@9
  int v23; // esi@9
  int result; // eax@10
  int v25; // edx@10
  int v26; // edx@11
  unsigned int v27; // ebp@15
  int v28; // eax@15
  int v29; // edi@15
  int v30; // eax@18
  int v31; // ecx@20
  int v32; // [sp+10h] [bp-4h]@9

  v11 = *(_DWORD *)(a1 + 18);
  v12 = *(_WORD *)(13 * a5 + v11 + 4);
  v13 = 13 * a5 + v11;
  v14 = v11 + *(_DWORD *)(13 * a5 + v11 + 9);
  dword_537B64 = v13;
  v15 = *(_WORD *)v13;
  dword_537B7C = v14;
  v16 = a3 - v15 - v12;
  v17 = *(_WORD *)(v13 + 2);
  v18 = a3 - v15 + 1;
  v19 = v16 + 1;
  dword_537B68 = v19;
  dword_537B6C = v18 - 1;
  dword_537B70 = v18 - 1;
  dword_537B60 = v17 + a4;
  if ( !a7 )
    goto LABEL_9;
  if ( a8 > v19 || a8 + a10 < v18 || dword_537B60 < a9 )
  {
    v21 = a11;
    goto LABEL_8;
  }
  v20 = dword_537B60 + *(_WORD *)(v13 + 6);
  v21 = a11;
  if ( v20 > a11 + a9 )
  {
LABEL_8:
    a7 = 1;
    dword_537B80 = a8 + a10 - 1;
    dword_537B84 = a9 + v21 - 1;
    goto LABEL_9;
  }
  a7 = 0;
LABEL_9:
  v22 = *(_DWORD *)(a2 + 22);
  v23 = v22 + *(_WORD *)(a2 + 18) * dword_537B60;
  v32 = *(_WORD *)(a2 + 18);
  while ( 1 )
  {
    while ( 1 )
    {
      result = dword_537B7C + 1;
      dword_537B7C = result;
      v25 = *(_BYTE *)(result - 1);
      if ( (char)v25 < 0 )
        break;
      dword_537B78 = *(_BYTE *)(result - 1);
      if ( v25 )
      {
        if ( !a7 )
        {
          v27 = v25;
          BYTE1(v22) = a6;
          LOBYTE(v22) = a6;
          v28 = v22 << 16;
          LOWORD(v28) = v22;
          v29 = dword_537B70 - v25 + v23 + 1;
LABEL_23:
          memset32((void *)v29, v28, v27 >> 2);
          memset((void *)(v29 + 4 * (v27 >> 2)), v28, v27 & 3);
          HIWORD(v22) = 0;
          goto LABEL_24;
        }
        HIWORD(v22) = HIWORD(dword_537B60);
        if ( dword_537B60 >= a9 )
        {
          if ( dword_537B60 <= dword_537B84 )
          {
            v27 = v25;
            HIWORD(v22) = HIWORD(a8);
            v30 = dword_537B70 - v25 + 1;
            if ( a8 <= v30 )
            {
              HIWORD(v22) = HIWORD(dword_537B70);
              if ( dword_537B70 <= dword_537B80 )
              {
                HIWORD(v31) = HIWORD(a8);
                if ( a8 > v30 )
                {
                  v27 = dword_537B70 - a8 + 1;
                  BYTE1(v31) = a6;
                  LOBYTE(v31) = a6;
                  v29 = v23 + a8;
                  v28 = v31 << 16;
                  LOWORD(v28) = v31;
                }
                else
                {
                  BYTE1(v31) = a6;
                  LOBYTE(v31) = a6;
                  v28 = v31 << 16;
                  LOWORD(v28) = v31;
                  v29 = dword_537B70 - v25 + v23 + 1;
                }
                goto LABEL_23;
              }
            }
          }
        }
LABEL_24:
        dword_537B78 = v25;
        dword_537B70 -= v25;
      }
      else
      {
        HIWORD(v22) = HIWORD(dword_537B6C);
        v23 += v32;
        dword_537B70 = dword_537B6C;
        ++dword_537B60;
      }
    }
    dword_537B74 = v23;
    dword_537B78 = v25;
    v26 = v25 & 0x7F;
    if ( !v26 )
      return result;
    dword_537B70 -= v26;
  }
}

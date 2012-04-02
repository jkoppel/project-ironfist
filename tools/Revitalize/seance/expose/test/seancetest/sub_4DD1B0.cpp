int __fastcall sub_4DD1B0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  int v12; // eax@2
  int result; // eax@4
  int v14; // eax@11
  int v15; // eax@11
  char v16; // si@20
  int v17; // ecx@20
  int v18; // eax@23
  void *v19; // edi@23
  unsigned int v20; // ecx@23
  int v21; // edi@23
  char v22; // cl@23
  int v23; // esi@24
  int v24; // edi@24
  unsigned int v25; // ecx@24
  int v26; // ecx@31
  int v27; // eax@34
  int v28; // esi@43
  int v29; // eax@48
  int v30; // eax@55
  int v31; // ecx@58

  dword_537AD8 = *(_DWORD *)(a1 + 18) + 13 * a5;
  dword_537AE0 = *(_DWORD *)(a1 + 18) + *(_DWORD *)(dword_537AD8 + 9);
  dword_537B14 = a3 - *(_WORD *)(dword_537AD8 + 4) - *(_WORD *)dword_537AD8 + 1;
  dword_537AE4 = dword_537B14 + *(_WORD *)(dword_537AD8 + 4) - 1;
  dword_537B00 = a4 + *(_WORD *)(dword_537AD8 + 2);
  dword_537AE8 = dword_537AE4 - *(_BYTE *)(dword_537B00 + a12);
  dword_537AEC = a7 + a9 - 1;
  dword_537B1C = a10 + a8 - 1;
  dword_537B04 = *(_DWORD *)(a2 + 22) + dword_537B00 * *(_WORD *)(a2 + 18);
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v12 = *(_BYTE *)dword_537AE0;
        dword_537AFC = v12;
        ++dword_537AE0;
        if ( (char)v12 < 0 )
          break;
        if ( dword_537AFC )
        {
          if ( *(_BYTE *)(dword_537B00 + a12) == 127
            || a8 > dword_537B00
            || dword_537B1C < dword_537B00
            || (v28 = dword_537AE8 - dword_537AFC + 1, dword_537AEC < v28)
            || dword_537AE8 < a7 )
          {
            v30 = dword_537AFC;
            goto LABEL_57;
          }
          if ( dword_537AE8 > dword_537AEC )
          {
            dword_537AE0 += dword_537AE8 - dword_537AEC;
            dword_537B0C = dword_537B04 + dword_537AEC;
            if ( a7 > dword_537AE8 - dword_537AFC )
            {
              dword_537B10 = a9;
              v29 = dword_537AFC + dword_537AEC - a9 - dword_537AE8;
              goto LABEL_52;
            }
            dword_537AF8 = 0;
            dword_537B10 = dword_537AEC + dword_537AFC - dword_537AE8;
          }
          else
          {
            dword_537B0C = dword_537AE8 + dword_537B04;
            if ( a7 > v28 )
            {
              dword_537B10 = dword_537AE8 - a7 + 1;
              v29 = dword_537AFC - dword_537B10;
LABEL_52:
              dword_537AF8 = v29;
              goto LABEL_53;
            }
            dword_537AF8 = 0;
            dword_537B10 = dword_537AFC;
          }
LABEL_53:
          for ( dword_537ADC = 0; dword_537B10 > dword_537ADC; ++dword_537ADC )
            *(_BYTE *)dword_537B0C-- = *(_BYTE *)dword_537AE0++;
          v30 = dword_537AF8;
LABEL_57:
          dword_537AE0 += v30;
          dword_537AE8 -= dword_537AFC;
        }
        else
        {
          v31 = dword_537AE4 - *(_BYTE *)(dword_537B00++ + 1 + a12 - 1);
          dword_537AE8 = v31;
          dword_537B04 += *(_WORD *)(a2 + 18);
        }
      }
      if ( !(v12 & 0x40) )
        break;
      if ( dword_537AFC & 0x3F )
      {
        if ( dword_537AFC == 193 )
          dword_537AFC = *(_BYTE *)dword_537AE0++;
        else
          dword_537AFC &= 0x3Fu;
        byte_537B18 = *(_BYTE *)dword_537AE0++;
LABEL_17:
        if ( *(_BYTE *)(dword_537B00 + a12) != 127 )
        {
          if ( a8 <= dword_537B00 )
          {
            if ( dword_537B1C >= dword_537B00 )
            {
              v16 = dword_537AFC;
              v17 = dword_537AE8 - dword_537AFC + 1;
              if ( a7 <= v17 )
              {
                if ( dword_537AE8 <= dword_537AEC )
                {
                  if ( a7 > v17 )
                  {
                    v23 = dword_537AE8 - a7 + 1;
                    LOBYTE(v17) = byte_537B18;
                    BYTE1(v17) = byte_537B18;
                    v24 = a7 + dword_537B04;
                    v18 = v17 << 16;
                    LOWORD(v18) = v17;
                    v25 = (unsigned int)(dword_537AE8 - a7 + 1) >> 2;
                    memset32((void *)(a7 + dword_537B04), v18, v25);
                    v21 = v24 + 4 * v25;
                    v22 = v23;
                  }
                  else
                  {
                    LOBYTE(v17) = byte_537B18;
                    BYTE1(v17) = byte_537B18;
                    v18 = v17 << 16;
                    LOWORD(v18) = v17;
                    v19 = (void *)(dword_537AE8 - dword_537AFC + dword_537B04 + 1);
                    v20 = (unsigned int)dword_537AFC >> 2;
                    memset32(v19, v18, (unsigned int)dword_537AFC >> 2);
                    v21 = (int)((char *)v19 + 4 * v20);
                    v22 = v16;
                  }
                  memset((void *)v21, v18, v22 & 3);
                }
              }
            }
          }
        }
        dword_537AE8 -= dword_537AFC;
      }
      else
      {
        v14 = *(_BYTE *)dword_537AE0;
        dword_537AFC = v14;
        v15 = v14 & 3;
        ++dword_537AE0;
        if ( v15 )
          dword_537B10 = v15;
        else
          dword_537B10 = *(_BYTE *)dword_537AE0++;
        dword_537AF4 = dword_537B10;
        if ( a11 && dword_537AFC & 0x80 )
        {
          byte_537B18 = a11;
          dword_537AFC = dword_537B10;
          goto LABEL_17;
        }
        if ( dword_537AFC & 0x40 )
        {
          dword_537B08 = (int)((char *)globalColorSubstitutionThing + 64 * (dword_537AFC & 0x3C));
          if ( *(_BYTE *)(dword_537B00 + a12) != 127 )
          {
            if ( a8 <= dword_537B00 )
            {
              if ( dword_537B1C >= dword_537B00 )
              {
                v26 = dword_537AE8 - dword_537B10 + 1;
                if ( a7 <= v26 )
                {
                  if ( dword_537AE8 <= dword_537AEC )
                  {
                    if ( a7 > v26 )
                    {
                      dword_537B10 = dword_537AE8 - a7 + 1;
                      v27 = a7 + dword_537B04;
                    }
                    else
                    {
                      v27 = dword_537B04 + dword_537AE8 - dword_537B10 + 1;
                    }
                    dword_537ADC = 0;
                    for ( dword_537AF0 = v27; dword_537B10 > dword_537ADC; ++dword_537ADC )
                    {
                      *(_BYTE *)dword_537AF0 = *(_BYTE *)(*(_BYTE *)dword_537AF0 + dword_537B08);
                      ++dword_537AF0;
                    }
                  }
                }
              }
            }
          }
        }
        dword_537AE8 -= dword_537AF4;
      }
    }
    result = v12 & 0x3F;
    if ( !result )
      return result;
    dword_537AE8 -= result;
  }
}

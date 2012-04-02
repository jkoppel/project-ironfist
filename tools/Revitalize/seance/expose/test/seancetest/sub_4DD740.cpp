int __fastcall sub_4DD740(Icon *a1, Bitmap *a2, int offX, int offY, int idx, int one, int zero1, int zero2, unsigned int width, int height, int a11, int a12)
{
  int v12; // ecx@2
  int result; // eax@4
  int v14; // ecx@11
  char v15; // dl@20
  int v16; // eax@20
  int v17; // ecx@22
  int v18; // edi@24
  int v19; // eax@24
  unsigned int v20; // ecx@24
  int v21; // edi@24
  char v22; // cl@24
  int v23; // edx@25
  int v24; // edi@25
  unsigned int v25; // ecx@25
  int v26; // esi@27
  int v27; // edi@27
  unsigned int v28; // ecx@27
  int v29; // edi@28
  int v30; // eax@35
  int v31; // eax@40
  char v32; // dl@52
  int v33; // eax@52
  unsigned int v34; // ecx@56
  int v35; // edi@56
  int v36; // esi@56
  int v37; // edi@56
  int v38; // esi@56
  char v39; // cl@56
  int v40; // eax@57
  int v41; // edi@57
  int v42; // esi@57
  unsigned int v43; // ecx@57
  int v44; // eax@59
  int v45; // edi@59
  const void *v46; // esi@59
  unsigned int v47; // ecx@59
  int v48; // edi@60
  const void *v49; // esi@60

  dword_537B3C = (int)&a1->headersAndImageData[idx];
  dword_537B40 = (int)((char *)a1->headersAndImageData + *(_DWORD *)(dword_537B3C + 9));
  dword_537B2C = offX + *(_WORD *)dword_537B3C;
  dword_537B5C = a2->width;
  dword_537B20 = offY + *(_WORD *)(dword_537B3C + 2);
  dword_537B28 = dword_537B2C + *(_BYTE *)(dword_537B20 + a12);
  dword_537B24 = height + zero2 - 1;
  dword_537B4C = zero1 + width - 1;
  dword_537B34 = (int)&a2->contents[dword_537B20 * dword_537B5C];
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v12 = *(_BYTE *)dword_537B40;
        dword_537B58 = v12;
        ++dword_537B40;
        if ( (char)v12 < 0 )
          break;
        if ( dword_537B58 )
        {
          if ( *(_BYTE *)(dword_537B20 + a12) != 127 )
          {
            if ( zero2 <= dword_537B20 )
            {
              if ( dword_537B24 >= dword_537B20 )
              {
                v32 = dword_537B58;
                v33 = dword_537B58 + dword_537B28;
                if ( zero1 < dword_537B58 + dword_537B28 )
                {
                  if ( dword_537B28 <= dword_537B4C )
                  {
                    if ( dword_537B28 < zero1 )
                    {
                      if ( dword_537B4C < v33 )
                      {
                        v48 = zero1 + dword_537B34;
                        v49 = (const void *)(dword_537B40 - dword_537B28 + zero1);
                        memcpy((void *)(zero1 + dword_537B34), v49, 4 * (width >> 2));
                        v38 = (int)((char *)v49 + 4 * (width >> 2));
                        v37 = v48 + 4 * (width >> 2);
                        v39 = width;
                      }
                      else
                      {
                        v44 = dword_537B58 + dword_537B28 - zero1;
                        v45 = zero1 + dword_537B34;
                        v46 = (const void *)(dword_537B40 - dword_537B28 + zero1);
                        v47 = (unsigned int)(dword_537B58 + dword_537B28 - zero1) >> 2;
                        memcpy((void *)(zero1 + dword_537B34), v46, 4 * v47);
                        v38 = (int)((char *)v46 + 4 * v47);
                        v37 = v45 + 4 * v47;
                        v39 = v44;
                      }
                    }
                    else
                    {
                      if ( dword_537B4C < v33 )
                      {
                        v40 = dword_537B4C - dword_537B28 + 1;
                        v41 = dword_537B28 + dword_537B34;
                        v42 = dword_537B40;
                        v43 = (unsigned int)(dword_537B4C - dword_537B28 + 1) >> 2;
                        memcpy((void *)(dword_537B28 + dword_537B34), (const void *)dword_537B40, 4 * v43);
                        v38 = v42 + 4 * v43;
                        v37 = v41 + 4 * v43;
                        v39 = v40;
                      }
                      else
                      {
                        v34 = (unsigned int)dword_537B58 >> 2;
                        v35 = dword_537B28 + dword_537B34;
                        v36 = dword_537B40;
                        memcpy(
                          (void *)(dword_537B28 + dword_537B34),
                          (const void *)dword_537B40,
                          4 * ((unsigned int)dword_537B58 >> 2));
                        v38 = v36 + 4 * v34;
                        v37 = v35 + 4 * v34;
                        v39 = v32;
                      }
                    }
                    memcpy((void *)v37, (const void *)v38, v39 & 3);
                  }
                }
              }
            }
          }
          dword_537B28 += dword_537B58;
          dword_537B40 += dword_537B58;
        }
        else
        {
          dword_537B28 = dword_537B2C + *(_BYTE *)(dword_537B20 + a12);
          dword_537B34 += dword_537B5C;
          ++dword_537B20;
        }
      }
      if ( !(v12 & 0x40) )
        break;
      if ( dword_537B58 & 0x3F )
      {
        if ( dword_537B58 == 193 )
          dword_537B58 = *(_BYTE *)dword_537B40++;
        else
          dword_537B58 &= 0x3Fu;
        byte_537B38 = *(_BYTE *)dword_537B40++;
LABEL_17:
        if ( *(_BYTE *)(dword_537B20 + a12) != 127 )
        {
          if ( zero2 <= dword_537B20 )
          {
            if ( dword_537B24 >= dword_537B20 )
            {
              v15 = dword_537B58;
              v16 = dword_537B58 + dword_537B28;
              if ( zero1 < dword_537B58 + dword_537B28 )
              {
                if ( dword_537B28 <= dword_537B4C )
                {
                  HIWORD(v17) = HIWORD(dword_537B4C);
                  if ( dword_537B28 < zero1 )
                  {
                    if ( dword_537B4C < v16 )
                    {
                      LOBYTE(v17) = byte_537B38;
                      v29 = zero1 + dword_537B34;
                      BYTE1(v17) = byte_537B38;
                      v19 = v17 << 16;
                      LOWORD(v19) = v17;
                      memset32((void *)(zero1 + dword_537B34), v19, width >> 2);
                      v21 = v29 + 4 * (width >> 2);
                      v22 = width;
                    }
                    else
                    {
                      v26 = dword_537B58 + dword_537B28 - zero1;
                      LOBYTE(v17) = byte_537B38;
                      BYTE1(v17) = byte_537B38;
                      v27 = zero1 + dword_537B34;
                      v19 = v17 << 16;
                      LOWORD(v19) = v17;
                      v28 = (unsigned int)(dword_537B58 + dword_537B28 - zero1) >> 2;
                      memset32((void *)(zero1 + dword_537B34), v19, v28);
                      v21 = v27 + 4 * v28;
                      v22 = v26;
                    }
                  }
                  else
                  {
                    if ( dword_537B4C < v16 )
                    {
                      v23 = dword_537B4C - dword_537B28 + 1;
                      LOBYTE(v17) = byte_537B38;
                      BYTE1(v17) = byte_537B38;
                      v19 = v17 << 16;
                      LOWORD(v19) = v17;
                      v24 = dword_537B34 + dword_537B28;
                      v25 = (unsigned int)(dword_537B4C - dword_537B28 + 1) >> 2;
                      memset32((void *)(dword_537B34 + dword_537B28), v19, v25);
                      v21 = v24 + 4 * v25;
                      v22 = v23;
                    }
                    else
                    {
                      LOBYTE(v17) = byte_537B38;
                      v18 = dword_537B28 + dword_537B34;
                      BYTE1(v17) = byte_537B38;
                      v19 = v17 << 16;
                      LOWORD(v19) = v17;
                      v20 = (unsigned int)dword_537B58 >> 2;
                      memset32((void *)(dword_537B28 + dword_537B34), v19, (unsigned int)dword_537B58 >> 2);
                      v21 = v18 + 4 * v20;
                      v22 = v15;
                    }
                  }
                  memset((void *)v21, v19, v22 & 3);
                }
              }
            }
          }
        }
        dword_537B28 += dword_537B58;
      }
      else
      {
        v14 = *(_BYTE *)dword_537B40;
        dword_537B58 = v14;
        ++dword_537B40;
        if ( v14 & 3 )
          dword_537B44 = v14 & 3;
        else
          dword_537B44 = *(_BYTE *)dword_537B40++;
        dword_537B48 = dword_537B44;
        if ( a11 && dword_537B58 & 0x80 )
        {
          byte_537B38 = a11;
          dword_537B58 = dword_537B44;
          goto LABEL_17;
        }
        if ( dword_537B58 & 0x40 )
        {
          dword_537B30 = (int)((char *)globalColorSubstitutionThing + 64 * (dword_537B58 & 0x3C));
          if ( *(_BYTE *)(dword_537B20 + a12) != 127 )
          {
            if ( zero2 <= dword_537B20 )
            {
              if ( dword_537B24 >= dword_537B20 )
              {
                v30 = dword_537B44 + dword_537B28;
                if ( zero1 < dword_537B44 + dword_537B28 )
                {
                  if ( dword_537B28 <= dword_537B4C )
                  {
                    if ( dword_537B28 < zero1 )
                    {
                      if ( dword_537B4C < v30 )
                        dword_537B44 = width;
                      else
                        dword_537B44 += dword_537B28 - zero1;
                      v31 = zero1 + dword_537B34;
                    }
                    else
                    {
                      if ( dword_537B4C < v30 )
                        dword_537B44 = dword_537B4C - dword_537B28 + 1;
                      v31 = dword_537B34 + dword_537B28;
                    }
                    dword_537B54 = 0;
                    for ( dword_537B50 = v31; dword_537B44 > dword_537B54; ++dword_537B54 )
                    {
                      *(_BYTE *)dword_537B50 = *(_BYTE *)(*(_BYTE *)dword_537B50 + dword_537B30);
                      ++dword_537B50;
                    }
                  }
                }
              }
            }
          }
        }
        dword_537B28 += dword_537B48;
      }
    }
    result = v12 & 0x3F;
    if ( !(v12 & 0x3F) )
      return result;
    dword_537B28 += result;
  }
}

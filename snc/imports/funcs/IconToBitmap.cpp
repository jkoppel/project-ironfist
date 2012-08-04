{
  ICNHeader *imgData; // edi@1
  int header; // ecx@1
  int v13; // esi@1
  int v14; // eax@1
  int v15; // ebx@1
  int v16; // eax@5
  int v17; // esi@5
  unsigned __int8 *v18; // ebp@9
  int v19; // ecx@10
  int v20; // eax@10
  int result; // eax@12
  int v22; // edx@14
  int v23; // ecx@17
  int v24; // eax@18
  int v25; // eax@24
  int v26; // edi@24
  int v27; // eax@27
  unsigned int v28; // esi@27
  int v29; // ecx@29
  int v30; // edi@31
  int v31; // ecx@34
  unsigned int v32; // ecx@34
  int v33; // eax@40
  char *v34; // esi@40
  int v35; // ecx@41
  int v36; // eax@43
  int v37; // eax@47
  int v38; // ecx@52
  int v39; // eax@59
  unsigned int v40; // edx@63
  int v41; // edi@63
  int v42; // esi@63
  int v43; // ecx@66
  const void *v44; // esi@73
  unsigned int v45; // ecx@73
  int v46; // edi@73
  int v47; // esi@73
  int v48; // ecx@73

  imgData = icn->headersAndImageData;
  header = imgData[spriteIdx].offsetX;
  v13 = (int)&imgData[spriteIdx];
  v14 = (int)((char *)imgData + imgData[spriteIdx].off);
  dword_534784 = v13;
  dword_534760 = v14;
  v15 = header + a3;
  dword_534764 = header + a3;
  dword_53476C = bmp->width;
  dword_534788 = a4 + *(_WORD *)(v13 + 2);
  if ( !a6 )
    goto LABEL_9;
  if ( a7 > header + a3 || dword_534764 + *(_WORD *)(v13 + 4) > (signed int)(a7 + a9) || dword_534788 < a8 )
  {
    v17 = a10;
    goto LABEL_8;
  }
  v16 = dword_534788 + *(_WORD *)(v13 + 6);
  v17 = a10;
  if ( v16 > a10 + a8 )
  {
LABEL_8:
    a6 = 1;
    dword_53478C = a7 + a9 - 1;
    dword_534790 = a8 + v17 - 1;
    goto LABEL_9;
  }
  a6 = 0;
LABEL_9:
  v18 = &bmp->contents[dword_53476C * dword_534788];
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v19 = dword_534760 + 1;
        dword_534760 = v19;
        v20 = *(_BYTE *)(v19 - 1);
        if ( (char)v20 < 0 )
          break;
        dword_534780 = v15;
        dword_534770 = v20;
        if ( v20 )
        {
          if ( !a6 )
          {
            v40 = v20;
            v41 = (int)&v18[v15];
            v42 = dword_534760;
            goto LABEL_75;
          }
          if ( dword_534788 >= a8 )
          {
            if ( dword_534788 <= dword_534790 )
            {
              v43 = v20 + v15;
              v40 = v20;
              if ( a7 < v20 + v15 )
              {
                if ( v15 <= dword_53478C )
                {
                  if ( v15 < a7 )
                  {
                    if ( v43 > dword_53478C )
                    {
                      v40 = a9;
                      v41 = (int)&v18[a7];
                      v42 = dword_534760 - v15 + a7;
                      goto LABEL_75;
                    }
                    v44 = (const void *)(dword_534760 - v15 + a7);
                    v45 = (unsigned int)(v20 + v15 - a7) >> 2;
                    memcpy(&v18[a7], v44, 4 * v45);
                    v47 = (int)((char *)v44 + 4 * v45);
                    v46 = (int)(&v18[4 * v45] + a7);
                    v48 = v20 + v15 - a7;
                  }
                  else
                  {
                    if ( v43 > dword_53478C )
                    {
                      v41 = (int)&v18[v15];
                      v42 = dword_534760;
                      v40 = dword_53478C - v15 + 1;
                    }
                    else
                    {
                      v41 = (int)&v18[v15];
                      v42 = dword_534760;
                    }
LABEL_75:
                    memcpy((void *)v41, (const void *)v42, 4 * (v40 >> 2));
                    v47 = v42 + 4 * (v40 >> 2);
                    v46 = v41 + 4 * (v40 >> 2);
                    LOBYTE(v48) = v40;
                  }
                  memcpy((void *)v46, (const void *)v47, v48 & 3);
                  goto LABEL_77;
                }
              }
            }
          }
LABEL_77:
          v15 += v20;
          dword_534770 = v20;
          dword_534760 += v20;
        }
        else
        {
          v15 = dword_534764;
          v18 += dword_53476C;
          ++dword_534788;
        }
      }
      if ( !(v20 & 0x40) )
        break;
      dword_534770 = *(_BYTE *)(v19 - 1);
      v22 = v20 & 0x3F;
      if ( v20 & 0x3F )
      {
        if ( v20 == 193 )
        {
          ++dword_534760;
          v22 = *(_BYTE *)(dword_534760 - 1);
        }
        v23 = dword_534760 + 1;
        dword_534760 = v23;
        byte_534778 = *(_BYTE *)(v23 - 1);
LABEL_23:
        if ( !a6 )
        {
          LOBYTE(v23) = byte_534778;
          BYTE1(v23) = byte_534778;
          v25 = v23 << 16;
          LOWORD(v25) = v23;
          memset32(&v18[v15], v25, (unsigned int)v22 >> 2);
          v26 = (int)(&v18[4 * ((unsigned int)v22 >> 2)] + v15);
          LOBYTE(v23) = v22;
          goto LABEL_37;
        }
        if ( dword_534788 >= a8 )
        {
          if ( dword_534788 <= dword_534790 )
          {
            v27 = v22 + v15;
            v28 = v22;
            if ( a7 < v22 + v15 )
            {
              if ( v15 <= dword_53478C )
              {
                HIWORD(v29) = HIWORD(dword_53478C);
                if ( v15 < a7 )
                {
                  if ( v27 > dword_53478C )
                  {
                    v28 = a9;
                    LOBYTE(v29) = byte_534778;
                    v30 = (int)&v18[a7];
                    BYTE1(v29) = byte_534778;
                    v25 = v29 << 16;
                    LOWORD(v25) = v29;
                    goto LABEL_36;
                  }
                  HIWORD(v31) = HIWORD(a7);
                  LOBYTE(v31) = byte_534778;
                  BYTE1(v31) = byte_534778;
                  v25 = v31 << 16;
                  LOWORD(v25) = v31;
                  v32 = (unsigned int)(v22 + v15 - a7) >> 2;
                  memset32(&v18[a7], v25, v32);
                  v26 = (int)(&v18[4 * v32] + a7);
                  v23 = v22 + v15 - a7;
                }
                else
                {
                  if ( v27 > dword_53478C )
                  {
                    v28 = dword_53478C - v15 + 1;
                    LOBYTE(v29) = byte_534778;
                    BYTE1(v29) = byte_534778;
                    v30 = (int)&v18[v15];
                    v25 = v29 << 16;
                    LOWORD(v25) = v29;
                  }
                  else
                  {
                    v30 = (int)&v18[v15];
                    LOBYTE(v29) = byte_534778;
                    BYTE1(v29) = byte_534778;
                    v25 = v29 << 16;
                    LOWORD(v25) = v29;
                  }
LABEL_36:
                  memset32((void *)v30, v25, v28 >> 2);
                  v26 = v30 + 4 * (v28 >> 2);
                  LOBYTE(v23) = v28;
                }
LABEL_37:
                memset((void *)v26, v25, v23 & 3);
                goto LABEL_38;
              }
            }
          }
        }
LABEL_38:
        v15 += v22;
        dword_534770 = v22;
      }
      else
      {
        ++dword_534760;
        v24 = *(_BYTE *)(dword_534760 - 1);
        v22 = *(_BYTE *)(dword_534760 - 1) & 3;
        if ( !(*(_BYTE *)(dword_534760 - 1) & 3) )
        {
          ++dword_534760;
          v22 = *(_BYTE *)(dword_534760 - 1);
        }
        HIWORD(v23) = HIWORD(a11);
        dword_53477C = v22;
        if ( a11 )
        {
          dword_534770 = v24;
          if ( v24 & 0x80 )
          {
            dword_534794 = v22;
            byte_534778 = a11;
            goto LABEL_23;
          }
        }
        dword_534770 = v24;
        dword_534794 = v22;
        if ( v24 & 0x40 )
        {
          v33 = (v24 & 0x3C) << 6;
          v34 = (char *)uDimPal + v33;
          dword_534768 = (int)((char *)uDimPal + v33);
          if ( a6 )
          {
            dword_534794 = v22;
            if ( dword_534788 >= a8 )
            {
              if ( dword_534788 <= dword_534790 )
              {
                v37 = v22 + v15;
                if ( a7 < v22 + v15 )
                {
                  if ( v15 <= dword_53478C )
                  {
                    if ( v15 < a7 )
                    {
                      dword_534794 = v22;
                      if ( v37 > dword_53478C )
                        v22 = a9;
                      else
                        v22 = v15 + v22 - a7;
                      v38 = (int)&v18[a7];
                    }
                    else
                    {
                      if ( v37 > dword_53478C )
                        v22 = dword_53478C - v15 + 1;
                      v38 = (int)&v18[v15];
                    }
                    dword_534774 = v38;
                    dword_534768 = (int)v34;
                    dword_534794 = v22;
                    dword_53475C = 0;
                    if ( v22 > 0 )
                    {
                      dword_53475C = v22;
                      do
                      {
                        ++v38;
                        v39 = *(_BYTE *)(v38 - 1);
                        dword_534774 = v38;
                        --v22;
                        dword_534768 = (int)v34;
                        *(_BYTE *)(v38 - 1) = v34[v39];
                      }
                      while ( v22 );
                    }
                  }
                }
              }
            }
          }
          else
          {
            v35 = (int)&v18[v15];
            dword_534774 = (int)&v18[v15];
            dword_53475C = 0;
            if ( v22 > 0 )
            {
              dword_53475C = v22;
              do
              {
                ++v35;
                v36 = *(_BYTE *)(v35 - 1);
                dword_534774 = v35;
                --v22;
                dword_534768 = (int)v34;
                *(_BYTE *)(v35 - 1) = v34[v36];
              }
              while ( v22 );
            }
          }
        }
        v15 += dword_53477C;
      }
    }
    dword_534780 = v15;
    dword_534798 = (int)v18;
    dword_534770 = v20;
    result = v20 & 0x3F;
    if ( !result )
      return result;
    v15 += result;
  }
}
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
  int v27; // ecx@24
  int v28; // eax@27
  unsigned int v29; // esi@27
  int v30; // ecx@29
  int v31; // edi@31
  int v32; // ecx@34
  unsigned int v33; // ecx@34
  int v34; // eax@40
  char *v35; // esi@40
  int v36; // ecx@41
  int v37; // eax@43
  int v38; // eax@47
  int v39; // ecx@52
  int v40; // eax@59
  unsigned int v41; // edx@63
  int v42; // edi@63
  int v43; // esi@63
  int v44; // ecx@66
  const void *v45; // esi@73
  unsigned int v46; // ecx@73
  int v47; // edi@73
  int v48; // esi@73
  int v49; // ecx@73

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
            v41 = v20;
            v42 = (int)&v18[v15];
            v43 = dword_534760;
            goto LABEL_75;
          }
          if ( dword_534788 >= a8 )
          {
            if ( dword_534788 <= dword_534790 )
            {
              v44 = v20 + v15;
              v41 = v20;
              if ( a7 < v20 + v15 )
              {
                if ( v15 <= dword_53478C )
                {
                  if ( v15 < a7 )
                  {
                    if ( v44 > dword_53478C )
                    {
                      v41 = a9;
                      v42 = (int)&v18[a7];
                      v43 = dword_534760 - v15 + a7;
                      goto LABEL_75;
                    }
                    v45 = (const void *)(dword_534760 - v15 + a7);
                    v46 = (unsigned int)(v20 + v15 - a7) >> 2;
                    memcpy(&v18[a7], v45, 4 * v46);
                    v48 = (int)((char *)v45 + 4 * v46);
                    v47 = (int)(&v18[4 * v46] + a7);
                    v49 = v20 + v15 - a7;
                  }
                  else
                  {
                    if ( v44 > dword_53478C )
                    {
                      v42 = (int)&v18[v15];
                      v43 = dword_534760;
                      v41 = dword_53478C - v15 + 1;
                    }
                    else
                    {
                      v42 = (int)&v18[v15];
                      v43 = dword_534760;
                    }
LABEL_75:
                    memcpy((void *)v42, (const void *)v43, 4 * (v41 >> 2));
                    v48 = v43 + 4 * (v41 >> 2);
                    v47 = v42 + 4 * (v41 >> 2);
                    LOBYTE(v49) = v41;
                  }
                  memcpy((void *)v47, (const void *)v48, v49 & 3);
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
          LOBYTE(v27) = v22;
          goto LABEL_37;
        }
        if ( dword_534788 >= a8 )
        {
          if ( dword_534788 <= dword_534790 )
          {
            v28 = v22 + v15;
            v29 = v22;
            if ( a7 < v22 + v15 )
            {
              if ( v15 <= dword_53478C )
              {
                HIWORD(v30) = HIWORD(dword_53478C);
                if ( v15 < a7 )
                {
                  if ( v28 > dword_53478C )
                  {
                    v29 = a9;
                    LOBYTE(v30) = byte_534778;
                    v31 = (int)&v18[a7];
                    BYTE1(v30) = byte_534778;
                    v25 = v30 << 16;
                    LOWORD(v25) = v30;
                    goto LABEL_36;
                  }
                  HIWORD(v32) = HIWORD(a7);
                  LOBYTE(v32) = byte_534778;
                  BYTE1(v32) = byte_534778;
                  v25 = v32 << 16;
                  LOWORD(v25) = v32;
                  v33 = (unsigned int)(v22 + v15 - a7) >> 2;
                  memset32(&v18[a7], v25, v33);
                  v26 = (int)(&v18[4 * v33] + a7);
                  v27 = v22 + v15 - a7;
                }
                else
                {
                  if ( v28 > dword_53478C )
                  {
                    v29 = dword_53478C - v15 + 1;
                    LOBYTE(v30) = byte_534778;
                    BYTE1(v30) = byte_534778;
                    v31 = (int)&v18[v15];
                    v25 = v30 << 16;
                    LOWORD(v25) = v30;
                  }
                  else
                  {
                    v31 = (int)&v18[v15];
                    LOBYTE(v30) = byte_534778;
                    BYTE1(v30) = byte_534778;
                    v25 = v30 << 16;
                    LOWORD(v25) = v30;
                  }
LABEL_36:
                  memset32((void *)v31, v25, v29 >> 2);
                  v26 = v31 + 4 * (v29 >> 2);
                  LOBYTE(v27) = v29;
                }
LABEL_37:
                memset((void *)v26, v25, v27 & 3);
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
          v34 = (v24 & 0x3C) << 6;
          v35 = (char *)globalColorSubstitutionThing + v34;
          dword_534768 = (int)((char *)globalColorSubstitutionThing + v34);
          if ( a6 )
          {
            dword_534794 = v22;
            if ( dword_534788 >= a8 )
            {
              if ( dword_534788 <= dword_534790 )
              {
                v38 = v22 + v15;
                if ( a7 < v22 + v15 )
                {
                  if ( v15 <= dword_53478C )
                  {
                    if ( v15 < a7 )
                    {
                      dword_534794 = v22;
                      if ( v38 > dword_53478C )
                        v22 = a9;
                      else
                        v22 = v15 + v22 - a7;
                      v39 = (int)&v18[a7];
                    }
                    else
                    {
                      if ( v38 > dword_53478C )
                        v22 = dword_53478C - v15 + 1;
                      v39 = (int)&v18[v15];
                    }
                    dword_534774 = v39;
                    dword_534768 = (int)v35;
                    dword_534794 = v22;
                    dword_53475C = 0;
                    if ( v22 > 0 )
                    {
                      dword_53475C = v22;
                      do
                      {
                        ++v39;
                        v40 = *(_BYTE *)(v39 - 1);
                        dword_534774 = v39;
                        --v22;
                        dword_534768 = (int)v35;
                        *(_BYTE *)(v39 - 1) = v35[v40];
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
            v36 = (int)&v18[v15];
            dword_534774 = (int)&v18[v15];
            dword_53475C = 0;
            if ( v22 > 0 )
            {
              dword_53475C = v22;
              do
              {
                ++v36;
                v37 = *(_BYTE *)(v36 - 1);
                dword_534774 = v36;
                --v22;
                dword_534768 = (int)v35;
                *(_BYTE *)(v36 - 1) = v35[v37];
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

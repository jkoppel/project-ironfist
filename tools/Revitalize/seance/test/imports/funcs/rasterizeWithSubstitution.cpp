{
  ICNHeader *v13; // esi@1
  int v14; // ecx@1
  int v15; // edi@1
  int v16; // eax@1
  int v17; // esi@1
  int v18; // eax@5
  int v19; // edi@5
  unsigned __int8 *v20; // ebp@9
  int v21; // edx@9
  int v22; // ecx@10
  int v23; // eax@10
  int result; // eax@12
  int v25; // ebx@14
  int v26; // ecx@17
  int v27; // eax@18
  int v28; // eax@24
  int v29; // edi@24
  int v30; // ecx@24
  int v31; // eax@27
  int v32; // ecx@29
  int v33; // ST10_4@32
  int v34; // ecx@34
  unsigned int v35; // ecx@34
  int v36; // eax@39
  char *v37; // edi@39
  int v38; // eax@48
  int v39; // ebx@66
  int v40; // ecx@69
  unsigned __int8 *v41; // edi@83

  v13 = a1->headersAndImageData;
  v14 = v13[a5].offsetX;
  v15 = (int)&v13[a5];
  v16 = (int)((char *)v13 + v13[a5].off);
  dword_5379D4 = v15;
  dword_5379E4 = v16;
  v17 = v14 + a3;
  dword_5379B4 = v14 + a3;
  dword_5379F4 = buf->width;
  dword_5379D0 = a4 + *(_WORD *)(v15 + 2);
  if ( !a6 )
    goto LABEL_9;
  if ( a7 > v14 + a3 || dword_5379B4 + *(_WORD *)(v15 + 4) > (signed int)(a7 + a9) || a8 > dword_5379D0 )
  {
    v19 = a10;
    goto LABEL_8;
  }
  v18 = dword_5379D0 + *(_WORD *)(v15 + 6);
  v19 = a10;
  if ( v18 > a10 + a8 )
  {
LABEL_8:
    a6 = 1;
    dword_5379B8 = a7 + a9 - 1;
    dword_5379E0 = a8 + v19 - 1;
    goto LABEL_9;
  }
  a6 = 0;
LABEL_9:
  v20 = &buf->contents[dword_5379D0 * dword_5379F4];
  v21 = dword_5379C8;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v22 = dword_5379E4 + 1;
        dword_5379E4 = v22;
        v23 = *(_BYTE *)(v22 - 1);
        if ( (char)v23 < 0 )
          break;
        dword_5379DC = v17;
        dword_5379D8 = v23;
        if ( v23 )
        {
          dword_5379C8 = v21;
          dword_5379F0 = (unsigned __int8 *)dword_5379E4;
          if ( a6 )
          {
            if ( a8 > dword_5379D0
              || dword_5379E0 < dword_5379D0
              || (v40 = v23 + v17, a7 >= v23 + v17)
              || (dword_5379C8 = v21, v17 > dword_5379B8) )
            {
              v39 = 0;
            }
            else
            {
              if ( v17 < a7 )
              {
                if ( dword_5379B8 < v40 )
                {
                  v21 = (int)&v20[a7];
                  v39 = a9;
                }
                else
                {
                  v21 = (int)&v20[a7];
                  v39 = v17 - a7 + v23;
                }
                dword_5379F0 = (unsigned __int8 *)(a7 + dword_5379E4 - v17);
              }
              else
              {
                v21 = (int)&v20[v17];
                if ( dword_5379B8 < v40 )
                  v39 = dword_5379B8 - v17 + 1;
                else
                  v39 = v23;
              }
            }
          }
          else
          {
            v21 = (int)&v20[v17];
            v39 = v23;
          }
          dword_5379E8 = v39;
          if ( v39 )
          {
            dword_5379EC = 0;
            if ( v39 > 0 )
            {
              dword_5379EC = v39;
              do
              {
                ++v21;
                v41 = dword_5379F0 + 1;
                *(_BYTE *)(v21 - 1) = paletteSubstitution[*dword_5379F0];
                --v39;
                dword_5379F0 = v41;
              }
              while ( v39 );
            }
          }
          v17 += v23;
          dword_5379D8 = v23;
          dword_5379E4 += v23;
        }
        else
        {
          v17 = dword_5379B4;
          v20 += dword_5379F4;
          ++dword_5379D0;
        }
      }
      if ( !(v23 & 0x40) )
        break;
      dword_5379D8 = *(_BYTE *)(v22 - 1);
      v25 = v23 & 0x3F;
      if ( v23 & 0x3F )
      {
        if ( v23 == 193 )
        {
          ++dword_5379E4;
          v25 = *(_BYTE *)(dword_5379E4 - 1);
        }
        v26 = dword_5379E4 + 1;
        dword_5379E4 = v26;
        byte_5379C0 = paletteSubstitution[*(_BYTE *)(v26 - 1)];
LABEL_23:
        if ( !a6 )
        {
          LOBYTE(v26) = byte_5379C0;
          BYTE1(v26) = byte_5379C0;
          v28 = v26 << 16;
          LOWORD(v28) = v26;
          memset32(&v20[v17], v28, (unsigned int)v25 >> 2);
          v29 = (int)(&v20[4 * ((unsigned int)v25 >> 2)] + v17);
          LOBYTE(v30) = v25;
LABEL_36:
          memset((void *)v29, v28, v30 & 3);
          goto LABEL_37;
        }
        if ( a8 <= dword_5379D0 )
        {
          if ( dword_5379E0 >= dword_5379D0 )
          {
            v31 = v25 + v17;
            if ( a7 < v25 + v17 )
            {
              if ( v17 <= dword_5379B8 )
              {
                HIWORD(v32) = HIWORD(dword_5379B8);
                if ( v17 < a7 )
                {
                  if ( dword_5379B8 < v31 )
                  {
                    LOBYTE(v30) = byte_5379C0;
                    BYTE1(v30) = byte_5379C0;
                    v28 = v30 << 16;
                    LOWORD(v28) = v30;
                    memset32(&v20[a7], v28, a9 >> 2);
                    v29 = (int)(&v20[4 * (a9 >> 2)] + a7);
                    LOBYTE(v30) = a9;
                  }
                  else
                  {
                    HIWORD(v34) = HIWORD(a7);
                    LOBYTE(v34) = byte_5379C0;
                    BYTE1(v34) = byte_5379C0;
                    v28 = v34 << 16;
                    LOWORD(v28) = v34;
                    v35 = (unsigned int)(v25 + v17 - a7) >> 2;
                    memset32(&v20[a7], v28, v35);
                    v29 = (int)(&v20[4 * v35] + a7);
                    v30 = v25 + v17 - a7;
                  }
                }
                else
                {
                  if ( dword_5379B8 < v31 )
                  {
                    v33 = dword_5379B8 - v17 + 1;
                    LOBYTE(v32) = byte_5379C0;
                    BYTE1(v32) = byte_5379C0;
                    v28 = v32 << 16;
                    LOWORD(v28) = v32;
                    v30 = (unsigned int)(dword_5379B8 - v17 + 1) >> 2;
                    memset32(&v20[v17], v28, v30);
                    v29 = (int)(&v20[4 * v30] + v17);
                    LOBYTE(v30) = v33;
                  }
                  else
                  {
                    LOBYTE(v30) = byte_5379C0;
                    BYTE1(v30) = byte_5379C0;
                    v28 = v30 << 16;
                    LOWORD(v28) = v30;
                    memset32(&v20[v17], v28, (unsigned int)v25 >> 2);
                    v29 = (int)(&v20[4 * ((unsigned int)v25 >> 2)] + v17);
                    LOBYTE(v30) = v25;
                  }
                }
                goto LABEL_36;
              }
            }
          }
        }
LABEL_37:
        v17 += v25;
        dword_5379D8 = v25;
      }
      else
      {
        ++dword_5379E4;
        v27 = *(_BYTE *)(dword_5379E4 - 1);
        v25 = *(_BYTE *)(dword_5379E4 - 1) & 3;
        if ( !(*(_BYTE *)(dword_5379E4 - 1) & 3) )
        {
          ++dword_5379E4;
          v25 = *(_BYTE *)(dword_5379E4 - 1);
        }
        HIWORD(v26) = HIWORD(a11);
        dword_5379C4 = v25;
        if ( a11 )
        {
          dword_5379D8 = v27;
          if ( v27 & 0x80 )
          {
            dword_5379E8 = v25;
            byte_5379C0 = a11;
            goto LABEL_23;
          }
        }
        dword_5379E8 = v25;
        dword_5379D8 = v27;
        if ( v27 & 0x40 )
        {
          v36 = (v27 & 0x3C) << 6;
          dword_5379C8 = v21;
          v37 = (char *)globalColorSubstitutionThing + v36;
          dword_5379BC = (int)((char *)globalColorSubstitutionThing + v36);
          if ( a6 )
          {
            dword_5379E8 = v25;
            if ( a8 <= dword_5379D0 )
            {
              if ( dword_5379E0 >= dword_5379D0 )
              {
                v38 = v25 + v17;
                if ( a7 < v25 + v17 )
                {
                  dword_5379C8 = v21;
                  if ( v17 <= dword_5379B8 )
                  {
                    if ( v17 < a7 )
                    {
                      dword_5379E8 = v25;
                      if ( dword_5379B8 < v38 )
                        v25 = a9;
                      else
                        v25 = v17 + v25 - a7;
                      v21 = (int)&v20[a7];
                    }
                    else
                    {
                      if ( dword_5379B8 < v38 )
                        v25 = dword_5379B8 - v17 + 1;
                      v21 = (int)&v20[v17];
                    }
                    dword_5379BC = (int)v37;
                    dword_5379E8 = v25;
                    dword_5379EC = 0;
                    if ( v25 > 0 )
                    {
                      dword_5379EC = v25;
                      do
                      {
                        if ( a13 )
                          *(_BYTE *)v21 = v37[*(_BYTE *)v21];
                        ++v21;
                        dword_5379BC = (int)v37;
                        --v25;
                      }
                      while ( v25 );
                    }
                  }
                }
              }
            }
          }
          else
          {
            v21 = (int)&v20[v17];
            dword_5379EC = 0;
            if ( v25 > 0 )
            {
              dword_5379EC = v25;
              do
              {
                if ( a13 )
                  *(_BYTE *)v21 = v37[*(_BYTE *)v21];
                ++v21;
                dword_5379BC = (int)((char *)globalColorSubstitutionThing + v36);
                --v25;
              }
              while ( v25 );
            }
          }
        }
        v17 += dword_5379C4;
      }
    }
    dword_5379DC = v17;
    dword_5379CC = (int)v20;
    dword_5379C8 = v21;
    dword_5379D8 = v23;
    result = v23 & 0x3F;
    if ( !result )
      return result;
    v17 += result;
  }
}

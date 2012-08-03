{
  ICNHeader *data; // esi@1
  ICNHeader *header; // ebx@1
  int width; // edi@1
  unsigned __int8 *contents; // esi@1
  int leftX; // ecx@1
  int v17; // ebx@1
  int v18; // eax@1
  int v19; // ecx@1
  int v20; // ebp@1
  int v21; // ecx@5
  int v22; // eax@9
  int v23; // eax@9
  int byte; // ecx@10
  int v25; // ecx@12
  int v26; // edx@14
  int v27; // eax@17
  int v28; // eax@18
  void *v29; // edi@24
  int v30; // edi@24
  void *v31; // edi@30
  int v32; // ecx@31
  int v33; // edi@31
  unsigned int v34; // ecx@31
  int v35; // eax@35
  char *v36; // ecx@35
  int v37; // edi@36
  int v38; // eax@38
  int v39; // eax@42
  int v40; // edi@45
  int v41; // eax@49
  int v42; // ebx@53
  int v43; // edx@54
  int v44; // ebx@62
  int v45; // eax@63
  int v46; // edx@64
  int v47; // edx@71
  int v49; // [sp+14h] [bp-4h]@9

  data = icn->headersAndImageData;
  header = &data[idx];
  width = header->width;
  contents = (unsigned __int8 *)((char *)data + header->off);
  leftX = offX - header->offsetX - width;
  dword_537A98 = header;
  v17 = header->offsetY;
  v18 = width + leftX;
  v19 = leftX + 1;
  v20 = v18;
  dword_537AC8 = v19;
  dword_537AA0 = v18;
  dword_537AA4 = v17 + offY;
  if ( !a6 )
    goto LABEL_9;
  if ( v19 < a7 || a7 + a9 < v19 + width || a8 > dword_537AA4 )
  {
    v21 = a10;
    goto LABEL_8;
  }
  v21 = a10;
  if ( dword_537AA4 + dword_537A98->height > a10 + a8 )
  {
LABEL_8:
    a6 = 1;
    dword_537A94 = a7 + a9 - 1;
    dword_537AB4 = a8 + v21 - 1;
    goto LABEL_9;
  }
  a6 = 0;
LABEL_9:
  v22 = bmp->width;
  v49 = v22;
  v23 = (int)&bmp->contents[dword_537AA4 * v22];
  dword_537AB8 = v23;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        byte = *contents++;
        if ( (char)byte < 0 )
          break;
        dword_537AC0 = v20;
        dword_537ACC = byte;
        if ( byte )
        {
          LOBYTE(v23) = a6;
          if ( !a6 )
          {
            dword_537A90 = 0;
            v42 = v20 + dword_537AB8;
            dword_537ABC = v20 + dword_537AB8;
            if ( byte > 0 )
            {
              v43 = byte;
              dword_537A90 = byte;
              do
              {
                v23 = *contents++;
                --v42;
                --v43;
                LOBYTE(v23) = paletteSubstitution[v23];
                dword_537ABC = v42;
                *(_BYTE *)(v42 + 1) = v23;
              }
              while ( v43 );
            }
            goto LABEL_74;
          }
          LOBYTE(v23) = dword_537AA4;
          if ( a8 > dword_537AA4
            || dword_537AB4 < dword_537AA4
            || (v23 = v20 - byte + 1, dword_537A94 < v23)
            || v20 < a7 )
          {
            contents += byte;
            goto LABEL_74;
          }
          if ( v20 > dword_537A94 )
          {
            v44 = dword_537A94 + dword_537AB8;
            contents = &contents[v20] - dword_537A94;
            if ( a7 > v20 - byte )
            {
              v45 = a9;
              v46 = byte + dword_537A94 - a9 - v20;
              goto LABEL_68;
            }
            dword_537AA8 = 0;
            v45 = byte - v20 + dword_537A94;
          }
          else
          {
            v44 = v20 + dword_537AB8;
            if ( a7 > v23 )
            {
              v45 = v20 - a7 + 1;
              v46 = byte - v45;
LABEL_68:
              dword_537AA8 = v46;
              goto LABEL_69;
            }
            dword_537AA8 = 0;
            v45 = byte;
          }
LABEL_69:
          dword_537AD0 = v45;
          dword_537ABC = v44;
          dword_537A90 = 0;
          if ( v45 > 0 )
          {
            dword_537A90 = v45;
            do
            {
              v47 = *contents++;
              --v44;
              --v45;
              LOBYTE(v47) = paletteSubstitution[v47];
              dword_537ABC = v44;
              *(_BYTE *)(v44 + 1) = v47;
            }
            while ( v45 );
          }
          LOBYTE(v23) = dword_537AA8;
          contents += dword_537AA8;
LABEL_74:
          v20 -= byte;
          dword_537ACC = byte;
        }
        else
        {
          v20 = dword_537AA0;
          LOBYTE(v23) = dword_537AA4++ + 1;
          dword_537AB8 += v49;
        }
      }
      if ( !(byte & 0x40) )
        break;
      dword_537ACC = byte;
      v26 = byte & 0x3F;
      if ( byte & 0x3F )
      {
        if ( byte == 193 )
          v26 = *contents++;
        v27 = *contents++;
        byte_537AD4 = paletteSubstitution[v27];
LABEL_23:
        if ( !a6 )
        {
          LOBYTE(byte) = byte_537AD4;
          BYTE1(byte) = byte_537AD4;
          v23 = byte << 16;
          LOWORD(v23) = byte;
          v29 = (void *)(v20 - v26 + dword_537AB8 + 1);
          memset32(v29, v23, (unsigned int)v26 >> 2);
          v30 = (int)((char *)v29 + 4 * ((unsigned int)v26 >> 2));
          LOBYTE(byte) = v26;
LABEL_32:
          memset((void *)v30, v23, byte & 3);
          goto LABEL_33;
        }
        LOBYTE(v23) = dword_537AA4;
        if ( a8 <= dword_537AA4 )
        {
          if ( dword_537AB4 >= dword_537AA4 )
          {
            v23 = v20 - v26 + 1;
            if ( a7 <= v23 )
            {
              if ( v20 <= dword_537A94 )
              {
                HIWORD(byte) = HIWORD(a7);
                if ( a7 > v23 )
                {
                  v32 = v20 - a7 + 1;
                  LOBYTE(v32) = byte_537AD4;
                  BYTE1(v32) = byte_537AD4;
                  v33 = dword_537AB8 + a7;
                  v23 = v32 << 16;
                  LOWORD(v23) = v32;
                  v34 = (unsigned int)(v20 - a7 + 1) >> 2;
                  memset32((void *)(dword_537AB8 + a7), v23, v34);
                  v30 = v33 + 4 * v34;
                  byte = v20 - a7 + 1;
                }
                else
                {
                  LOBYTE(byte) = byte_537AD4;
                  BYTE1(byte) = byte_537AD4;
                  v23 = byte << 16;
                  LOWORD(v23) = byte;
                  v31 = (void *)(v20 - v26 + dword_537AB8 + 1);
                  memset32(v31, v23, (unsigned int)v26 >> 2);
                  v30 = (int)((char *)v31 + 4 * ((unsigned int)v26 >> 2));
                  LOBYTE(byte) = v26;
                }
                goto LABEL_32;
              }
            }
          }
        }
LABEL_33:
        v20 -= v26;
        dword_537ACC = v26;
      }
      else
      {
        v28 = *contents++;
        v26 = v28 & 3;
        if ( !(v28 & 3) )
          v26 = *contents++;
        HIWORD(byte) = HIWORD(a11);
        dword_537AB0 = v26;
        if ( a11 )
        {
          dword_537ACC = v28;
          if ( v28 & 0x80 )
          {
            dword_537AD0 = v26;
            byte_537AD4 = a11;
            goto LABEL_23;
          }
        }
        dword_537AD0 = v26;
        dword_537ACC = v28;
        if ( v28 & 0x40 )
        {
          v35 = (v28 & 0x3C) << 6;
          v36 = (char *)uDimPal + v35;
          if ( a6 )
          {
            dword_537AD0 = v26;
            dword_537A9C = (int)((char *)uDimPal + v35);
            if ( a8 <= dword_537AA4 )
            {
              if ( dword_537AB4 >= dword_537AA4 )
              {
                v39 = v20 - v26 + 1;
                if ( a7 <= v39 )
                {
                  if ( v20 <= dword_537A94 )
                  {
                    if ( a7 > v39 )
                    {
                      v26 = v20 - a7 + 1;
                      v40 = a7 + dword_537AB8;
                    }
                    else
                    {
                      v40 = v20 - v26 + dword_537AB8 + 1;
                    }
                    dword_537AD0 = v26;
                    dword_537A9C = (int)v36;
                    dword_537AAC = v40;
                    dword_537A90 = 0;
                    if ( v26 > 0 )
                    {
                      dword_537A90 = v26;
                      do
                      {
                        ++v40;
                        v41 = *(_BYTE *)(v40 - 1);
                        dword_537AAC = v40;
                        --v26;
                        dword_537A9C = (int)v36;
                        *(_BYTE *)(v40 - 1) = v36[v41];
                      }
                      while ( v26 );
                    }
                  }
                }
              }
            }
          }
          else
          {
            dword_537A9C = (int)((char *)uDimPal + v35);
            dword_537A90 = 0;
            v37 = v20 - v26 + dword_537AB8 + 1;
            dword_537AAC = v20 - v26 + dword_537AB8 + 1;
            if ( v26 > 0 )
            {
              dword_537A90 = v26;
              do
              {
                ++v37;
                v38 = *(_BYTE *)(v37 - 1);
                dword_537AAC = v37;
                --v26;
                dword_537A9C = (int)v36;
                *(_BYTE *)(v37 - 1) = v36[v38];
              }
              while ( v26 );
            }
          }
        }
        LOBYTE(v23) = dword_537AB0;
        v20 -= dword_537AB0;
      }
    }
    dword_537AC0 = v20;
    dword_537AC4 = (int)contents;
    dword_537ACC = byte;
    v25 = byte & 0x3F;
    if ( !v25 )
      return v23;
    v20 -= v25;
  }
}
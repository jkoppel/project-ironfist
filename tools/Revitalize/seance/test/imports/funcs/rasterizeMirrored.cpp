{
  ICNHeader *iconContents; // esi@1
  ICNHeader *header; // ebx@1
  int spriteWidth; // edi@1
  char *nextBytePtr; // esi@1
  int leftX; // ebp@1
  int secondColX; // ebp@1
  int curPixelX; // ebx@1
  int v18; // ecx@5
  void *v19; // ecx@9
  char *bufBotRow; // ebp@9
  int firstByte; // eax@11
  int result; // eax@13
  int v23; // edx@15
  char v24; // al@18
  int v25; // eax@19
  int v26; // eax@25
  void *v27; // edi@25
  void *v28; // edi@25
  int v29; // ecx@25
  void *v30; // edi@31
  int v31; // ecx@32
  unsigned int v32; // ecx@32
  int v33; // eax@36
  char *v34; // edi@36
  int v35; // eax@39
  int v36; // eax@43
  int v37; // eax@50
  char *pixel; // edx@54
  int nPixels; // edi@55
  char color; // cl@56
  int v41; // edi@60
  char *v42; // edx@63
  int v43; // edi@64
  int v44; // ecx@65
  char v45; // cl@72
  void *imgWidth; // [sp+14h] [bp-4h]@9

  iconContents = icn->headersAndImageData;
  header = &iconContents[spriteIdx];
  spriteWidth = header->width;
  nextBytePtr = (char *)iconContents + header->off;
  leftX = x - header->offsetX - spriteWidth;
  rasterizeRightAlignedHeader = header;
  secondColX = leftX + 1;
  rasterizeRightAlignedSecondColX = secondColX;
  curPixelX = spriteWidth + secondColX - 1;
  rasterizeRightAlignedLastColX = spriteWidth + secondColX - 1;
  rasterizeRightTopY = y + rasterizeRightAlignedHeader->offsetY;
  if ( flag )
  {
    if ( secondColX < a7 || a7 + width < secondColX + spriteWidth || rasterizeRightTopY < a8 )
    {
      v18 = height;
    }
    else
    {
      v18 = height;
      if ( rasterizeRightTopY + rasterizeRightAlignedHeader->height <= height + a8 )
      {
        flag = 0;
        goto LABEL_9;
      }
    }
    flag = 1;
    dword_537990 = a7 + width - 1;
    dword_53799C = a8 + v18 - 1;
  }
LABEL_9:
  v19 = buf->contents;
  bufBotRow = (char *)(buf->width * rasterizeRightTopY);
  imgWidth = (void *)buf->width;
LABEL_10:
  bufBotRow = &bufBotRow[(_DWORD)v19];
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        firstByte = (unsigned __int8)*nextBytePtr++;
        if ( (char)firstByte < 0 )
          break;
        rasterizeRightLastColX = curPixelX;
        rasterizeRightFirstByte = firstByte;
        if ( !firstByte )                       // 0 is end of line
        {
          curPixelX = rasterizeRightAlignedLastColX;
          v19 = imgWidth;
          ++rasterizeRightTopY;
          goto LABEL_10;
        }
        HIWORD(v19) = HIWORD(flag);
        if ( !flag )
        {
          pixel = &bufBotRow[curPixelX];
          dword_5379B0 = 0;
          rasterizeRightCurPixel = (int)&bufBotRow[curPixelX];
          if ( firstByte > 0 )                  // Between 0 and 0x80, just copy next bytes
          {
            nPixels = firstByte;
            dword_5379B0 = firstByte;
            do
            {
              color = *nextBytePtr++;
              *pixel-- = color;
              --nPixels;
              rasterizeRightCurPixel = (int)pixel;
            }
            while ( nPixels );
          }
          goto LABEL_75;
        }
        HIWORD(v19) = HIWORD(rasterizeRightTopY);
        if ( rasterizeRightTopY < a8
          || rasterizeRightTopY > dword_53799C
          || (v19 = (void *)(curPixelX - firstByte), v41 = curPixelX - firstByte + 1, v41 > dword_537990)
          || curPixelX < a7 )
        {
          nextBytePtr += firstByte;
          goto LABEL_75;
        }
        if ( curPixelX > dword_537990 )
        {
          v42 = &bufBotRow[dword_537990];
          nextBytePtr = &nextBytePtr[curPixelX] - dword_537990;
          if ( a7 > (signed int)v19 )
          {
            v43 = width;
            v44 = firstByte + dword_537990 - width - curPixelX;
            goto LABEL_69;
          }
          dword_537994 = 0;
          v43 = firstByte - curPixelX + dword_537990;
        }
        else
        {
          v42 = &bufBotRow[curPixelX];
          if ( a7 > v41 )
          {
            v43 = curPixelX - a7 + 1;
            v44 = firstByte - v43;
LABEL_69:
            dword_537994 = v44;
            goto LABEL_70;
          }
          dword_537994 = 0;
          v43 = firstByte;
        }
LABEL_70:
        rasterizeRightCurPixel = (int)v42;
        dword_537984 = v43;
        dword_5379B0 = 0;
        if ( v43 > 0 )
        {
          dword_5379B0 = v43;
          do
          {
            v45 = *nextBytePtr++;
            *v42-- = v45;
            --v43;
            rasterizeRightCurPixel = (int)v42;
          }
          while ( v43 );
        }
        HIWORD(v19) = HIWORD(dword_537994);
        nextBytePtr += dword_537994;
LABEL_75:
        curPixelX -= firstByte;
        rasterizeRightFirstByte = firstByte;
      }
      if ( !(firstByte & 0x40) )
        break;
      rasterizeRightFirstByte = firstByte;
      v23 = firstByte & 0x3F;
      if ( firstByte & 0x3F )
      {
        if ( firstByte == 193 )
          v23 = (unsigned __int8)*nextBytePtr++;
        v24 = *nextBytePtr++;
        byte_5379A8 = v24;
LABEL_24:
        if ( !flag )
        {
          LOBYTE(v19) = byte_5379A8;
          BYTE1(v19) = byte_5379A8;
          v26 = (_DWORD)v19 << 16;
          LOWORD(v26) = (_WORD)v19;
          v27 = &bufBotRow[curPixelX - v23 + 1];
          memset32(v27, v26, (unsigned int)v23 >> 2);
          v28 = (char *)v27 + 4 * ((unsigned int)v23 >> 2);
          LOBYTE(v29) = v23;
LABEL_33:
          memset(v28, v26, (unsigned __int8)v19 & 3);
          HIWORD(v19) = 0;
          goto LABEL_34;
        }
        HIWORD(v19) = HIWORD(rasterizeRightTopY);
        if ( rasterizeRightTopY >= a8 )
        {
          if ( rasterizeRightTopY <= dword_53799C )
          {
            v19 = (void *)(curPixelX - v23 + 1);
            if ( a7 <= (signed int)v19 )
            {
              if ( curPixelX <= dword_537990 )
              {
                if ( a7 > (signed int)v19 )
                {
                  v31 = curPixelX - a7 + 1;
                  LOBYTE(v31) = byte_5379A8;
                  BYTE1(v31) = byte_5379A8;
                  v26 = v31 << 16;
                  LOWORD(v26) = v31;
                  v32 = (unsigned int)(curPixelX - a7 + 1) >> 2;
                  memset32(&bufBotRow[a7], v26, v32);
                  v28 = &bufBotRow[4 * v32] + a7;
                  v29 = curPixelX - a7 + 1;
                }
                else
                {
                  LOBYTE(v19) = byte_5379A8;
                  BYTE1(v19) = byte_5379A8;
                  v26 = (_DWORD)v19 << 16;
                  LOWORD(v26) = (_WORD)v19;
                  v30 = &bufBotRow[curPixelX - v23 + 1];
                  memset32(v30, v26, (unsigned int)v23 >> 2);
                  v28 = (char *)v30 + 4 * ((unsigned int)v23 >> 2);
                  LOBYTE(v29) = v23;
                }
                goto LABEL_33;
              }
            }
          }
        }
LABEL_34:
        curPixelX -= v23;
        rasterizeRightFirstByte = v23;
      }
      else
      {
        v25 = (unsigned __int8)*nextBytePtr++;
        v23 = v25 & 3;
        if ( !(v25 & 3) )
          v23 = (unsigned __int8)*nextBytePtr++;
        HIWORD(v19) = HIWORD(a11);
        dword_537978 = v23;
        if ( a11 )
        {
          rasterizeRightFirstByte = v25;
          if ( v25 & 0x80 )
          {
            dword_537984 = v23;
            byte_5379A8 = a11;
            goto LABEL_24;
          }
        }
        rasterizeRightFirstByte = v25;
        dword_537984 = v23;
        if ( v25 & 0x40 )
        {
          v33 = (v25 & 0x3C) << 6;
          v34 = (char *)globalColorSubstitutionThing + v33;
          dword_537988 = (int)((char *)globalColorSubstitutionThing + v33);
          if ( flag )
          {
            HIWORD(v19) = HIWORD(rasterizeRightTopY);
            dword_537984 = v23;
            if ( rasterizeRightTopY >= a8 )
            {
              if ( rasterizeRightTopY <= dword_53799C )
              {
                HIWORD(v19) = HIWORD(a7);
                v36 = curPixelX - v23 + 1;
                if ( a7 <= v36 )
                {
                  HIWORD(v19) = HIWORD(dword_537990);
                  if ( curPixelX <= dword_537990 )
                  {
                    if ( a7 > v36 )
                    {
                      v23 = curPixelX - a7 + 1;
                      v19 = &bufBotRow[a7];
                    }
                    else
                    {
                      v19 = &bufBotRow[curPixelX - v23 + 1];
                    }
                    dword_537988 = (int)v34;
                    dword_5379A4 = (int)v19;
                    dword_537984 = v23;
                    dword_5379B0 = 0;
                    if ( v23 > 0 )
                    {
                      dword_5379B0 = v23;
                      do
                      {
                        v19 = (char *)v19 + 1;
                        v37 = *((_BYTE *)v19 - 1);
                        dword_5379A4 = (int)v19;
                        --v23;
                        dword_537988 = (int)v34;
                        *((_BYTE *)v19 - 1) = v34[v37];
                      }
                      while ( v23 );
                    }
                  }
                }
              }
            }
          }
          else
          {
            dword_5379B0 = 0;
            v19 = &bufBotRow[curPixelX - v23 + 1];
            dword_5379A4 = (int)&bufBotRow[curPixelX - v23 + 1];
            if ( v23 > 0 )
            {
              dword_5379B0 = v23;
              do
              {
                v19 = (char *)v19 + 1;
                v35 = *((_BYTE *)v19 - 1);
                dword_5379A4 = (int)v19;
                --v23;
                dword_537988 = (int)v34;
                *((_BYTE *)v19 - 1) = v34[v35];
              }
              while ( v23 );
            }
          }
        }
        curPixelX -= dword_537978;
      }
    }
    rasterizeRightLastColX = curPixelX;
    dword_5379A0 = (int)nextBytePtr;
    dword_53796C = (int)bufBotRow;
    rasterizeRightFirstByte = firstByte;
    result = firstByte & 0x3F;
    if ( !result )
      return result;
    curPixelX -= result;
  }
}

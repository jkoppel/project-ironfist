{
  int result; // eax@3
  int v3; // ebx@48
  int v4; // [sp+1Ch] [bp-38h]@1
  int j; // [sp+20h] [bp-34h]@14
  int v6; // [sp+24h] [bp-30h]@1
  int i; // [sp+28h] [bp-2Ch]@1
  int v8; // [sp+2Ch] [bp-28h]@12
  int v9; // [sp+34h] [bp-20h]@1
  int v10; // [sp+38h] [bp-1Ch]@12
  unsigned __int8 v11; // [sp+3Ch] [bp-18h]@34
  int v12; // [sp+48h] [bp-Ch]@1
  int v13; // [sp+4Ch] [bp-8h]@26
  int v14; // [sp+50h] [bp-4h]@48

  v9 = (signed __int64)*(float *)(a1 + 36);
  v4 = (signed __int64)*(float *)(a1 + 40);
  v6 = *(_DWORD *)(a1 + 76);
  v12 = *(_DWORD *)(a1 + 80);
  Random(7, 12);
  for ( i = 0; ; ++i )
  {
    result = a2;
    if ( i >= a2 )
      break;
    *(float *)(a1 + 36) = sin(*(float *)(a1 + 56)) + *(float *)(a1 + 36);
    *(float *)(a1 + 40) = cos(*(float *)(a1 + 56)) + *(float *)(a1 + 40);
    *(_DWORD *)(a1 + 44) = (signed __int64)*(float *)(a1 + 36);
    *(_DWORD *)(a1 + 48) = (signed __int64)*(float *)(a1 + 40);
    if ( *(_DWORD *)(a1 + 44) < 0 )
    {
      *(_DWORD *)(a1 + 44) = 0;
      *(_DWORD *)(a1 + 36) = 0;
    }
    if ( *(_DWORD *)(a1 + 44) > 639 )
    {
      *(_DWORD *)(a1 + 44) = 639;
      *(_DWORD *)(a1 + 36) = 1142931456;
    }
    if ( *(_DWORD *)(a1 + 48) < 0 )
    {
      *(_DWORD *)(a1 + 48) = 0;
      *(_DWORD *)(a1 + 40) = 0;
    }
    if ( *(_DWORD *)(a1 + 48) > 442 )
    {
      *(_DWORD *)(a1 + 48) = 442;
      *(_DWORD *)(a1 + 40) = 1138556928;
    }
    v10 = *(_DWORD *)(a1 + 44);
    v8 = *(_DWORD *)(a1 + 48);
    if ( *(_DWORD *)(a1 + 44) != v9 || *(_DWORD *)(a1 + 48) != v4 )
    {
      v9 = *(_DWORD *)(a1 + 44);
      v4 = *(_DWORD *)(a1 + 48);
      for ( j = v6; v12 >= j; ++j )
      {
        if ( *(_DWORD *)(a1 + 52) )
          v8 = j + *(_DWORD *)(a1 + 48);
        else
          v10 = j + *(_DWORD *)(a1 + 44);
        if ( v10 >= 0 && v10 < 640 && v8 >= 0 && v8 < 443 )
        {
          if ( j >= 0 )
            v13 = v12 - j;
          else
            v13 = -(v6 - j);
          switch ( *(_DWORD *)(a1 + 24) )
          {
            case 0x101:
              *(&gpWindowManager->screenBuffer->contents[640 * v8] + v10) = gColorTableRed[*(&gpWindowManager->screenBuffer->contents[640 * v8]
                                                                                           + v10)];
              break;
            case 0x12E:
              *(&gpWindowManager->screenBuffer->contents[640 * v8] + v10) = uRedBeam[v13];
              break;
            case 0x12C:
              *(&gpWindowManager->screenBuffer->contents[640 * v8] + v10) = uRainbow[j - v6];
              break;
            case 0x12F:
              *(&gpWindowManager->screenBuffer->contents[640 * v8] + v10) = uRainbow[14 - (j - v6)];
              break;
            case 0x12D:
              if ( v13 )
              {
                switch ( v13 )
                {
                  case 1:
                    v11 = 116;
                    break;
                  case 2:
                    v11 = 117;
                    break;
                  case 3:
                    v11 = -52;
                    break;
                  case 4:
                    v11 = -50;
                    break;
                  default:
                    v11 = -42;
                    break;
                }
              }
              else
              {
                v11 = 114;
              }
              *(&gpWindowManager->screenBuffer->contents[640 * v8] + v10) = v11;
              break;
            default:
              *(&gpWindowManager->screenBuffer->contents[640 * v8] + v10) = *(_BYTE *)(a1 + 24);
              break;
          }
        }
      }
      v3 = abs(*(_DWORD *)(a1 + 8) - *(_DWORD *)(a1 + 44));
      v14 = abs(*(_DWORD *)(a1 + 12) - *(_DWORD *)(a1 + 48)) + v3;
      if ( *(_DWORD *)(a1 + 68) )
      {
        if ( *(_DWORD *)(a1 + 72) + 1 < v14 || v14 <= 2 )
        {
          result = a1;
          *(_DWORD *)(a1 + 64) = 1;
          return result;
        }
        if ( *(_DWORD *)(a1 + 72) > v14 )
          *(_DWORD *)(a1 + 72) = v14;
      }
      else if ( v14 < 15 )
      {
        *(_DWORD *)(a1 + 68) = 1;
        *(_DWORD *)(a1 + 72) = v14;
      }
    }
  }
  return result;
}
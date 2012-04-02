int __stdcall sub_4A2440(int a1, int a2)
{
  int result; // eax@3
  double v3; // st7@4
  double v4; // st7@4
  int v5; // ebx@48
  int v6; // [sp+1Ch] [bp-38h]@1
  int j; // [sp+20h] [bp-34h]@14
  int v8; // [sp+24h] [bp-30h]@1
  int i; // [sp+28h] [bp-2Ch]@1
  int v10; // [sp+2Ch] [bp-28h]@12
  int v11; // [sp+34h] [bp-20h]@1
  int v12; // [sp+38h] [bp-1Ch]@12
  unsigned __int8 v13; // [sp+3Ch] [bp-18h]@34
  int v14; // [sp+48h] [bp-Ch]@1
  int v15; // [sp+4Ch] [bp-8h]@26
  int v16; // [sp+50h] [bp-4h]@48

  v11 = (signed __int64)*(float *)(a1 + 36);
  v6 = (signed __int64)*(float *)(a1 + 40);
  v8 = *(_DWORD *)(a1 + 76);
  v14 = *(_DWORD *)(a1 + 80);
  unseededNextRand(7, 12);
  for ( i = 0; ; ++i )
  {
    result = a2;
    if ( i >= a2 )
      break;
    v3 = *(float *)(a1 + 56);
    sub_4DEFC0();
    *(float *)(a1 + 36) = v3 + *(float *)(a1 + 36);
    v4 = *(float *)(a1 + 56);
    sub_4DEFCA();
    *(float *)(a1 + 40) = v4 + *(float *)(a1 + 40);
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
    v12 = *(_DWORD *)(a1 + 44);
    v10 = *(_DWORD *)(a1 + 48);
    if ( *(_DWORD *)(a1 + 44) != v11 || *(_DWORD *)(a1 + 48) != v6 )
    {
      v11 = *(_DWORD *)(a1 + 44);
      v6 = *(_DWORD *)(a1 + 48);
      for ( j = v8; v14 >= j; ++j )
      {
        if ( *(_DWORD *)(a1 + 52) )
          v10 = j + *(_DWORD *)(a1 + 48);
        else
          v12 = j + *(_DWORD *)(a1 + 44);
        if ( v12 >= 0 && v12 < 640 && v10 >= 0 && v10 < 443 )
        {
          if ( j >= 0 )
            v15 = v14 - j;
          else
            v15 = -(v8 - j);
          switch ( *(_DWORD *)(a1 + 24) )
          {
            case 0x101:
              *(&HeroWindowManager::instance->screenBuffer->contents[640 * v10] + v12) = bloodlustPaletteTransform[*(&HeroWindowManager::instance->screenBuffer->contents[640 * v10] + v12)];
              break;
            case 0x12E:
              *(&HeroWindowManager::instance->screenBuffer->contents[640 * v10] + v12) = byte_51A3E0[v15];
              break;
            case 0x12C:
              *(&HeroWindowManager::instance->screenBuffer->contents[640 * v10] + v12) = byte_51A3E8[j - v8];
              break;
            case 0x12F:
              *(&HeroWindowManager::instance->screenBuffer->contents[640 * v10] + v12) = byte_51A3E8[14 - (j - v8)];
              break;
            case 0x12D:
              if ( v15 )
              {
                switch ( v15 )
                {
                  case 1:
                    v13 = 116;
                    break;
                  case 2:
                    v13 = 117;
                    break;
                  case 3:
                    v13 = -52;
                    break;
                  case 4:
                    v13 = -50;
                    break;
                  default:
                    v13 = -42;
                    break;
                }
              }
              else
              {
                v13 = 114;
              }
              *(&HeroWindowManager::instance->screenBuffer->contents[640 * v10] + v12) = v13;
              break;
            default:
              *(&HeroWindowManager::instance->screenBuffer->contents[640 * v10] + v12) = *(_BYTE *)(a1 + 24);
              break;
          }
        }
      }
      v5 = abs(*(_DWORD *)(a1 + 8) - *(_DWORD *)(a1 + 44));
      v16 = abs(*(_DWORD *)(a1 + 12) - *(_DWORD *)(a1 + 48)) + v5;
      if ( *(_DWORD *)(a1 + 68) )
      {
        if ( *(_DWORD *)(a1 + 72) + 1 < v16 || v16 <= 2 )
        {
          result = a1;
          *(_DWORD *)(a1 + 64) = 1;
          return result;
        }
        if ( *(_DWORD *)(a1 + 72) > v16 )
          *(_DWORD *)(a1 + 72) = v16;
      }
      else
      {
        if ( v16 < 15 )
        {
          *(_DWORD *)(a1 + 68) = 1;
          *(_DWORD *)(a1 + 72) = v16;
        }
      }
    }
  }
  return result;
}

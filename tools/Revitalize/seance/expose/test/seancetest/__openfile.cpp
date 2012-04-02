int __cdecl _openfile(const char *a1, int a2, int a3, int a4)
{
  signed int v4; // ebx@1
  int v5; // eax@1
  signed int v6; // edi@1
  int result; // eax@4
  signed int v8; // edx@5
  int v9; // esi@6
  signed int v10; // ebp@9
  int i; // ecx@9
  int v12; // eax@11
  int v13; // edx@42

  v4 = 0;
  v5 = *(_BYTE *)a2;
  v6 = 0;
  if ( v5 == 97 )
  {
    v8 = 265;
LABEL_8:
    v9 = dword_5224E0 | 2;
    goto LABEL_9;
  }
  if ( v5 != 114 )
  {
    if ( v5 != 119 )
      return 0;
    v8 = 769;
    goto LABEL_8;
  }
  v8 = 0;
  v9 = dword_5224E0 | 1;
LABEL_9:
  v10 = 1;
  for ( i = a2 + 1; *(_BYTE *)i; ++i )
  {
    if ( !v10 )
      break;
    v12 = *(_BYTE *)i - 43;
    if ( (unsigned int)v12 > 0x49 )
    {
LABEL_13:
      v10 = 0;
    }
    else
    {
      switch ( byte_4E4374[v12] )
      {
        default:
          goto LABEL_13;
        case 0:
          if ( v8 & 2 )
          {
            v10 = 0;
          }
          else
          {
            v8 = (v8 | 2) & 0xFFFFFFFE;
            v9 = (v9 | 0x80) & 0xFFFFFFFC;
          }
          break;
        case 0x19:
          if ( v8 & 0x40 )
            v10 = 0;
          else
            v8 |= 0x40u;
          break;
        case 0x27:
          if ( v4 )
          {
            v10 = 0;
          }
          else
          {
            v4 = 1;
            v8 |= 0x10u;
          }
          break;
        case 0x28:
          if ( v4 )
          {
            v10 = 0;
          }
          else
          {
            v4 = 1;
            v8 |= 0x20u;
          }
          break;
        case 0x29:
          if ( BYTE1(v8) & 0x10 )
            v10 = 0;
          else
            v8 |= 0x1000u;
          break;
        case 0x37:
          if ( BYTE1(v8) & 0xC0 )
            v10 = 0;
          else
            v8 |= 0x8000u;
          break;
        case 0x38:
          if ( v6 )
          {
            v10 = 0;
          }
          else
          {
            v6 = 1;
            v9 |= 0x4000u;
          }
          break;
        case 0x43:
          if ( v6 )
          {
            v10 = 0;
          }
          else
          {
            v6 = 1;
            v9 &= 0xFFFFBFFFu;
          }
          break;
        case 0x49:
          if ( BYTE1(v8) & 0xC0 )
            v10 = 0;
          else
            v8 |= 0x4000u;
          break;
      }
    }
  }
  v13 = _sopen(a1, v8, a3, 420);
  if ( v13 >= 0 )
  {
    result = a4;
    ++dword_521AB8;
    *(_DWORD *)(a4 + 12) = v9;
    *(_DWORD *)(a4 + 4) = 0;
    *(_DWORD *)a4 = 0;
    *(_DWORD *)(a4 + 8) = 0;
    *(_DWORD *)(a4 + 28) = 0;
    *(_DWORD *)(a4 + 16) = v13;
  }
  else
  {
    result = 0;
  }
  return result;
}

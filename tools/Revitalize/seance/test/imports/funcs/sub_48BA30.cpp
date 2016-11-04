{
  int thisa; // [sp+10h] [bp-50h]@1
  __int64 v6; // [sp+18h] [bp-48h]@43
  signed int i; // [sp+28h] [bp-38h]@1
  signed int j; // [sp+28h] [bp-38h]@35
  signed int k; // [sp+28h] [bp-38h]@71
  signed int l; // [sp+28h] [bp-38h]@87
  char v11; // [sp+2Ch] [bp-34h]@1
  int v12; // [sp+30h] [bp-30h]@75
  int v13; // [sp+30h] [bp-30h]@91
  int v14; // [sp+34h] [bp-2Ch]@1
  int v15[4]; // [sp+38h] [bp-28h]@3
  int v16; // [sp+48h] [bp-18h]@81
  int v17[4]; // [sp+4Ch] [bp-14h]@3
  int v18; // [sp+5Ch] [bp-4h]@1

  thisa = this;
  v18 = 0;
  v14 = -1;
  v11 = 0;
  for ( i = 0; i < 4; ++i )
  {
    v15[i] = 0;
    v17[i] = 0;
  }
  v18 = 1;
  if ( ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) == 11 )
    v14 = *(_BYTE *)(a2 + 3) - 1;
  if ( ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) == 63 )
    v14 = *(_BYTE *)(a2 + 3) - 1;
  if ( ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) == 62 && *(_BYTE *)(a2 + 3) == 9 )
  {
    v14 = 9;
    v11 = 1;
  }
  if ( ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) == 59 && *(_BYTE *)(a2 + 3) == 131 )
    v14 = 124;
  if ( ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) == 55 && *(_BYTE *)(a2 + 3) == 61 )
    v14 = 54;
  if ( ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) == 50 && *(_BYTE *)(a2 + 3) == 45 )
    v14 = 38;
  if ( ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) == 50 && *(_BYTE *)(a2 + 3) == 19 )
    v14 = 12;
  if ( ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) == 46 )
  {
    switch ( *(_BYTE *)(a2 + 3) )
    {
      case 1:
        v14 = 0;
        break;
      case 3:
        v14 = 2;
        break;
      case 5:
        v14 = 4;
        break;
      case 7:
        v14 = 6;
        break;
      case 9:
        v14 = 8;
        break;
      case 0xB:
        v14 = 10;
        break;
      case 0xD:
        v14 = 12;
        break;
      case 0xF:
        v14 = 14;
        break;
      case 0x13:
        v14 = 18;
        break;
      default:
        break;
    }
  }
  for ( j = 0; j < 4; ++j )
  {
    if ( v11 )
    {
      --v14;
    }
    else
    {
      if ( j > 0 )
        break;
    }
    if ( v14 != -1 )
    {
      if ( v11 )
      {
        HIDWORD(v6) = v14 <= 6 ? a3 + v14 - 6 : a3 + v14 - 9;
        LODWORD(v6) = v14 <= 6 ? a4 - 1 : a4;
      }
      else
      {
        HIDWORD(v6) = a3 - 1;
        LODWORD(v6) = a4;
      }
      if ( v6 >= 0 )
      {
        v15[j] = (int)(&gameObject->map.tiles[v6 * gameObject->map.width] + HIDWORD(v6));
        if ( j <= 1 )
        {
          if ( *(_BYTE *)(v15[j] + 3) != 255 )
          {
            if ( *(_BYTE *)(v15[j] + 3) == v14
              && ((*(_BYTE *)(v15[j] + 2) >> 2) & 0x3F) == ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) )
            {
              *(_BYTE *)(v15[j] + 3) = 0;
              *(_BYTE *)(v15[j] + 2) = *(_BYTE *)(v15[j] + 2) & 3 | 0xBC;
              *(_BYTE *)(v15[j] + 2) &= 0xFEu;
            }
            if ( *(_WORD *)(v15[j] + 10)
              && *(_BYTE *)(7 * *(_WORD *)(v15[j] + 10) + *(_DWORD *)(*(_DWORD *)(this + 174) + 4) + 3) != 255 )
              v17[j] = *(_DWORD *)(*(_DWORD *)(this + 174) + 4) + 7 * *(_WORD *)(v15[j] + 10);
            else
              v17[j] = 0;
            while ( v17[j] )
            {
              if ( *(_BYTE *)(v17[j] + 3) == v14
                && ((*(_BYTE *)(v17[j] + 2) >> 1) & 0x7F) == ((*(_BYTE *)(a2 + 2) >> 2) & 0x3F) )
              {
                *(_BYTE *)(v17[j] + 3) = 0;
                *(_BYTE *)(v17[j] + 2) = *(_BYTE *)(v17[j] + 2) & 1 | 0x5E;
                *(_BYTE *)(v17[j] + 2) &= 0xFEu;
              }
              if ( *(_WORD *)v17[j]
                && *(_BYTE *)(7 * *(_WORD *)v17[j] + *(_DWORD *)(*(_DWORD *)(this + 174) + 4) + 3) != 255 )
                v17[j] = *(_DWORD *)(*(_DWORD *)(this + 174) + 4) + 7 * *(_WORD *)v17[j];
              else
                v17[j] = 0;
            }
          }
        }
        else
        {
          *(_BYTE *)(v15[j] + 6) &= 3u;
          *(_BYTE *)(v15[j] + 7) = -1;
        }
      }
    }
  }
  *(_BYTE *)(a2 + 9) = 0;
  *(_BYTE *)(a2 + 3) = 0;
  *(_BYTE *)(a2 + 2) = *(_BYTE *)(a2 + 2) & 3 | 0xBC;
  *(_BYTE *)(a2 + 2) &= 0xFEu;
  for ( k = 0; k < 5; ++k )
  {
    if ( k )
      v12 = *(&v14 + k);
    else
      v12 = a2;
    if ( v12 )
    {
      if ( ((*(_BYTE *)(v12 + 2) >> 2) & 0x3F) == 47 )
      {
        if ( *(_WORD *)(v12 + 10) )
        {
          if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 174) + 4) - *(_WORD *)(v12 + 10) + 8 * *(_WORD *)(v12 + 10) + 3) != 255 )
          {
            v16 = *(_DWORD *)(*(_DWORD *)(this + 174) + 4) - *(_WORD *)(v12 + 10) + 8 * *(_WORD *)(v12 + 10);
            if ( ((*(_BYTE *)(v16 + 2) >> 1) & 0x7F) != 47 && *(_BYTE *)(v16 + 3) != 255 )
            {
              *(_BYTE *)(v12 + 3) = *(_BYTE *)(v16 + 3);
              *(_BYTE *)(v12 + 2) = *(_BYTE *)(v12 + 2) & 3 | 4 * (*(_BYTE *)(v16 + 2) >> 1);
              *(_BYTE *)(v12 + 2) = *(_BYTE *)(v12 + 2) & 0xFE | *(_BYTE *)(v16 + 2) & 1;
              *(_WORD *)(v12 + 4) = *(_WORD *)(v12 + 4) & 0xFFFE | *(_BYTE *)(v16 + 4) & 1;
              *(_WORD *)(v12 + 4) = *(_WORD *)(v12 + 4) & 0xFFFD | 2 * ((*(_BYTE *)(v16 + 4) >> 1) & 1);
              *(_BYTE *)(v16 + 3) = 0;
              *(_BYTE *)(v16 + 2) = *(_BYTE *)(v16 + 2) & 1 | 0x5E;
              *(_BYTE *)(v16 + 2) &= 0xFEu;
            }
          }
        }
      }
    }
  }
  for ( l = 0; l < 5; ++l )
  {
    if ( l )
      v13 = *(&v14 + l);
    else
      v13 = a2;
    if ( v13
      && (((*(_BYTE *)(v13 + 2) >> 2) & 0x3F) == 47 || *(_BYTE *)(v13 + 3) == 255 || (*(_WORD *)(v13 + 4) >> 1) & 1) )
    {
      if ( *(_WORD *)(v13 + 10)
        && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 174) + 4) - *(_WORD *)(v13 + 10) + 8 * *(_WORD *)(v13 + 10) + 3) != 255 )
        v16 = *(_DWORD *)(*(_DWORD *)(this + 174) + 4) - *(_WORD *)(v13 + 10) + 8 * *(_WORD *)(v13 + 10);
      else
        v16 = 0;
      while ( v16 )
      {
        if ( ((*(_BYTE *)(v16 + 2) >> 1) & 0x7F) != 47
          && *(_BYTE *)(v16 + 3) != 255
          && !((*(_BYTE *)(v16 + 4) >> 1) & 1) )
          goto LABEL_88;
        if ( *(_WORD *)v16
          && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 174) + 4) - *(_WORD *)v16 + 8 * *(_WORD *)v16 + 3) != 255 )
          v16 = *(_DWORD *)(*(_DWORD *)(this + 174) + 4) - *(_WORD *)v16 + 8 * *(_WORD *)v16;
        else
          v16 = 0;
      }
      *(_BYTE *)(v13 + 8) |= 0x80u;
    }
LABEL_88:
    ;
  }
  sub_4C3190(5, 0, a3, a4, -999, 0, 0);
  sub_452F60((void *)thisa, *(_DWORD *)(thisa + 470) + 7, *(_DWORD *)(thisa + 474) + 7, 1);
  return sub_4292B0();
}

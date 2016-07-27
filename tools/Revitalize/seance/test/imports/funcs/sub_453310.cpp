{
  signed int result; // eax@3
  int v6; // [sp+Ch] [bp-18h]@58
  int v7; // [sp+1Ch] [bp-8h]@1

  v7 = **(_DWORD **)(this + 174) + 12 * a3 * *(_DWORD *)(*(_DWORD *)(this + 174) + 8) + 12 * a2;
  if ( !tileToTerrainType[*(_WORD *)v7] && byte_4F0150[*(_WORD *)v7] & 0xF )
    return 20;
  if ( *(_BYTE *)(v7 + 9) & 0x80 )
  {
    switch ( *(_BYTE *)(v7 + 9) & 0x7F )
    {
      case 0xD:
        result = 25;
        break;
      case 0xF:
        result = 25;
        break;
      case 0x10:
        result = 25;
        break;
      case 0x11:
        result = 25;
        break;
      case 0x41:
        result = 25;
        break;
      case 0x3D:
        result = 24;
        break;
      case 0x5B:
        result = 23;
        break;
      case 0x3F:
        result = 22;
        break;
      case 0x1F:
        result = 18;
        break;
      case 0x4A:
        result = 18;
        break;
      case 0x4B:
        result = 18;
        break;
      case 3:
        result = 0;
        break;
      case 0x20:
        result = 1;
        break;
      case 0x27:
        result = 2;
        break;
      case 8:
        result = 10;
        break;
      case 0x28:
        result = 11;
        break;
      case 9:
        result = 12;
        break;
      case 0x52:
        result = 12;
        break;
      case 0x54:
        result = 13;
        break;
      case 0x24:
        result = 4;
        break;
      case 0x1E:
        result = 3;
        break;
      case 0x16:
        result = 9;
        break;
      case 1:
        if ( !(*(_BYTE *)(v7 + 9) & 0x80) )
          goto LABEL_66;
        result = 8;
        break;
      case 0x17:
        if ( !(*(_BYTE *)(v7 + 9) & 0x80) )
          goto LABEL_66;
        result = 15;
        break;
      case 0x40:
        if ( !(*(_BYTE *)(v7 + 9) & 0x80) )
          goto LABEL_66;
        result = 26;
        break;
      case 0x1D:
        if ( !(*(_BYTE *)(v7 + 9) & 0x80) )
          goto LABEL_66;
        result = 16;
        break;
      case 5:
        if ( !(*(_BYTE *)(v7 + 9) & 0x80) )
          goto LABEL_66;
        result = 17;
        break;
      default:
        goto LABEL_66;
    }
  }
  else
  {
    switch ( *(_BYTE *)(v7 + 9) )
    {
      case 0x51:
        return 21;
      case 0x70:
        if ( (signed int)*(_BYTE *)(v7 + 3) < 39 || (signed int)*(_BYTE *)(v7 + 3) > 44 )
          result = 6;
        else
          result = 7;
        return result;
      case 0x65:
        if ( ((*(_BYTE *)(v7 + 2) >> 2) & 0x3F) != 58 && ((*(_BYTE *)(v7 + 2) >> 2) & 0x3F) != 60 )
          result = 5;
        else
          result = 27;
        return result;
      case 0x68:
        if ( ((*(_BYTE *)(v7 + 2) >> 2) & 0x3F) == 52 )
          goto LABEL_58;
        return 13;
      default:
LABEL_58:
        v6 = (*(_BYTE *)(v7 + 2) >> 2) & 0x3F;
        if ( v6 == 40 )
        {
          if ( *(_BYTE *)(v7 + 3) == 182 || *(_BYTE *)(v7 + 3) == 183 )
            return 19;
        }
        else
        {
          if ( v6 == 45 )
            return 14;
        }
LABEL_66:
        result = -1;
        break;
    }
  }
  return result;
}

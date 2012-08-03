{
  signed int result; // eax@3
  int v4; // [sp+Ch] [bp-18h]@58
  mapCell *tile; // [sp+1Ch] [bp-8h]@1

  tile = &this->map->tiles[y * this->map->width] + x;
  if ( !giGroundToTerrain[tile->tileType] && giGroundShape[tile->tileType] & 0xF )
    return 20;
  if ( tile->objType & 0x80 )
  {
    switch ( tile->objType & 0x7F )
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
        if ( !(tile->objType & 0x80) )
          goto LABEL_66;
        result = 8;
        break;
      case 0x17:
        if ( !(tile->objType & 0x80) )
          goto LABEL_66;
        result = 15;
        break;
      case 0x40:
        if ( !(tile->objType & 0x80) )
          goto LABEL_66;
        result = 26;
        break;
      case 0x1D:
        if ( !(tile->objType & 0x80) )
          goto LABEL_66;
        result = 16;
        break;
      case 5:
        if ( !(tile->objType & 0x80) )
          goto LABEL_66;
        result = 17;
        break;
      default:
        goto LABEL_66;
    }
  }
  else
  {
    switch ( tile->objType )
    {
      case 0x51:
        return 21;
      case 0x70:
        if ( (signed int)HIBYTE(tile->field_2) < 39 || (signed int)HIBYTE(tile->field_2) > 44 )
          result = 6;
        else
          result = 7;
        return result;
      case 0x65:
        if ( ((LOBYTE(tile->field_2) >> 2) & 0x3F) != 58 && ((LOBYTE(tile->field_2) >> 2) & 0x3F) != 60 )
          result = 5;
        else
          result = 27;
        return result;
      case 0x68:
        if ( ((LOBYTE(tile->field_2) >> 2) & 0x3F) == 52 )
          goto LABEL_58;
        return 13;
      default:
LABEL_58:
        v4 = (LOBYTE(tile->field_2) >> 2) & 0x3F;
        if ( v4 == 40 )
        {
          if ( HIBYTE(tile->field_2) == 182 || HIBYTE(tile->field_2) == 183 )
            return 19;
        }
        else if ( v4 == 45 )
        {
          return 14;
        }
LABEL_66:
        result = -1;
        break;
    }
  }
  return result;
}
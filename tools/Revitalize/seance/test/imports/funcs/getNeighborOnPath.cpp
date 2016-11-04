{
  signed int goRight; // [sp+10h] [bp-20h]@4
  int curRow; // [sp+14h] [bp-1Ch]@4
  int destRow; // [sp+18h] [bp-18h]@4
  signed int goUp; // [sp+1Ch] [bp-14h]@4
  signed int goLeft; // [sp+20h] [bp-10h]@4
  signed int goDown; // [sp+2Ch] [bp-4h]@4

  if ( !checkHexGridIdxBounds(curHex) || !checkHexGridIdxBounds(destHex) )
    return -1;
  curRow = curHex / 13;
  destRow = destHex / 13;
  goUp = 0;
  goDown = 0;
  goLeft = 0;
  goRight = 0;
  if ( curHex % 13 >= destHex % 13 )
  {
    if ( curHex % 13 != destHex % 13 )
      goLeft = 1;
  }
  else
  {
    goRight = 1;
  }
  if ( curRow >= destRow )
  {
    if ( curRow != destRow )
      goUp = 1;
  }
  else
  {
    goDown = 1;
  }
  if ( goLeft == goRight )
  {
    if ( goUp == 1 )
    {
      if ( curRow & 1 )
      {
        if ( !(mask & 0x20) )
          return 5;
        if ( !(mask & 1) )
          return 0;
        if ( !(mask & 0x10) )
          return 4;
        if ( !(mask & 2) )
          return 1;
        if ( !(mask & 8) )
          return 3;
        if ( !(mask & 4) )
          return 2;
        if ( !(mask & 0x40) )
          return 6;
        if ( !(mask & 0x80) )
          return 7;
      }
      else
      {
        if ( !(mask & 1) )
          return 0;
        if ( !(mask & 0x20) )
          return 5;
        if ( !(mask & 2) )
          return 1;
        if ( !(mask & 0x10) )
          return 4;
        if ( !(mask & 4) )
          return 2;
        if ( !(mask & 8) )
          return 3;
        if ( !(mask & 0x40) )
          return 6;
        if ( !(mask & 0x80) )
          return 7;
      }
    }
    else
    {
      if ( curRow & 1 )
      {
        if ( !(mask & 8) )
          return 3;
        if ( !(mask & 4) )
          return 2;
        if ( !(mask & 0x10) )
          return 4;
        if ( !(mask & 2) )
          return 1;
        if ( !(mask & 0x20) )
          return 5;
        if ( !(mask & 1) )
          return 0;
        if ( !(mask & 0x80) )
          return 7;
        if ( !(mask & 0x40) )
          return 6;
      }
      else
      {
        if ( !(mask & 4) )
          return 2;
        if ( !(mask & 8) )
          return 3;
        if ( !(mask & 2) )
          return 1;
        if ( !(mask & 0x10) )
          return 4;
        if ( !(mask & 1) )
          return 0;
        if ( !(mask & 0x20) )
          return 5;
        if ( !(mask & 0x80) )
          return 7;
        if ( !(mask & 0x40) )
          return 6;
      }
    }
  }
  if ( goLeft == 1 )
  {
    if ( goUp == 1 )
    {
      if ( !(mask & 0x20) )
        return 5;
      if ( !(mask & 0x10) )
        return 4;
      if ( !(mask & 1) )
        return 0;
      if ( !(mask & 8) )
        return 3;
      if ( !(mask & 2) )
        return 1;
      if ( !(mask & 4) )
        return 2;
      if ( !(mask & 0x40) )
        return 6;
      if ( !(mask & 0x80) )
        return 7;
    }
    else
    {
      if ( goDown == 1 )
      {
        if ( !(mask & 8) )
          return 3;
        if ( !(mask & 0x10) )
          return 4;
        if ( !(mask & 4) )
          return 2;
        if ( !(mask & 0x20) )
          return 5;
        if ( !(mask & 2) )
          return 1;
        if ( !(mask & 1) )
          return 0;
        if ( !(mask & 0x80) )
          return 7;
        if ( !(mask & 0x40) )
          return 6;
      }
      else
      {
        if ( !(mask & 0x10) )
          return 4;
        if ( !(mask & 0x20) )
          return 5;
        if ( !(mask & 8) )
          return 3;
        if ( !(mask & 1) )
          return 0;
        if ( !(mask & 4) )
          return 2;
        if ( !(mask & 2) )
          return 1;
        if ( !(mask & 0x80) )
          return 7;
        if ( !(mask & 0x40) )
          return 6;
      }
    }
  }
  else
  {
    if ( goRight == 1 )
    {
      if ( goUp == 1 )
      {
        if ( !(mask & 1) )
          return 0;
        if ( !(mask & 2) )
          return 1;
        if ( !(mask & 0x20) )
          return 5;
        if ( !(mask & 4) )
          return 2;
        if ( !(mask & 0x10) )
          return 4;
        if ( !(mask & 8) )
          return 3;
        if ( !(mask & 0x40) )
          return 6;
        if ( !(mask & 0x80) )
          return 7;
      }
      else
      {
        if ( goDown == 1 )
        {
          if ( !(mask & 4) )
            return 2;
          if ( !(mask & 2) )
            return 1;
          if ( !(mask & 8) )
            return 3;
          if ( !(mask & 1) )
            return 0;
          if ( !(mask & 0x20) )
            return 5;
          if ( !(mask & 0x10) )
            return 4;
          if ( !(mask & 0x80) )
            return 7;
          if ( !(mask & 0x40) )
            return 6;
        }
        else
        {
          if ( !(mask & 2) )
            return 1;
          if ( !(mask & 1) )
            return 0;
          if ( !(mask & 4) )
            return 2;
          if ( !(mask & 0x20) )
            return 5;
          if ( !(mask & 8) )
            return 3;
          if ( !(mask & 0x10) )
            return 4;
          if ( !(mask & 0x80) )
            return 7;
          if ( !(mask & 0x40) )
            return 6;
        }
      }
    }
  }
  return -1;
}

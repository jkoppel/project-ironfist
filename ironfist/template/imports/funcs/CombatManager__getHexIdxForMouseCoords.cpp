{
  int result; // eax@20
  CombatManager *thisa; // [sp+Ch] [bp-20h]@1
  signed int v5; // [sp+14h] [bp-18h]@1
  signed int v6; // [sp+18h] [bp-14h]@1
  int v7; // [sp+1Ch] [bp-10h]@1
  int v8; // [sp+20h] [bp-Ch]@3

  thisa = this;
  v5 = y - 63;
  v7 = (y - 63) / 42;
  v6 = x - 23;
  if ( !(v7 & 1) )
    v6 = x - 45;
  v8 = v6 / 44;
  if ( v6 / 44 < 0 )
    goto LABEL_37;
  if ( v5 % 42 < 10 && v5 % 42 < abs(v6 % 44 - 22) / 2 )
  {
    --v7;
    if ( v6 % 44 >= 22 )
    {
      if ( v7 & 1 )
        ++v8;
    }
    else
    {
      if ( !(v7 & 1) )
        --v8;
    }
  }
  if ( v8 > 0 && v8 < 12 && v7 < 9 && v7 >= 0 )
  {
    result = v8 + 13 * v7;
  }
  else
  {
LABEL_37:
    if ( x < 0 || x > 74 || y < 80 || y > 196 )
    {
      if ( x < 566 || x > 639 || y < 37 || y > 153 )
      {
        if ( x >= 566 && x <= 639 && y >= 154 && y <= 310 && thisa->isCastleBattle )
          result = 77;
        else
          result = -1;
      }
      else
      {
        result = 25;
      }
    }
    else
    {
      result = 26;
    }
  }
  return result;
}

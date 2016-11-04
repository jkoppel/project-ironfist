{
  bool result; // eax@2
  int v3; // ST20_4@53
  signed int v4; // [sp+Ch] [bp-10h]@1
  unsigned int *this; // [sp+10h] [bp-Ch]@1
  unsigned int v6; // [sp+14h] [bp-8h]@41

  v4 = a2;
  this = a1;
  if ( sub_4D05D8((int)&gameObject->_7[72], *(_BYTE *)a1) )
  {
    result = 0;
  }
  else
  {
    if ( v4 == 6 || *((_BYTE *)this + 24) & 0x40 )
    {
      if ( inExpansion || v4 != 2 || *((_BYTE *)this + 3) != 5 )
      {
        if ( v4 == 3 )
        {
          result = Castle::adjacentToWater((Castle *)this) != 0;
        }
        else
        {
          if ( v4 || (signed int)*((_BYTE *)this + 28) < 5 )
          {
            if ( v4 != 5 && v4 != 14 && v4 != 16 && v4 != 17 && v4 != 18 && v4 != 31 )
            {
              if ( v4 >= 19 && v4 <= 30 )
              {
                if ( v4 == 20 && *((_BYTE *)this + 27) & 2
                  || v4 == 21 && *((_BYTE *)this + 27) & 4
                  || v4 == 22 && *((_BYTE *)this + 27) & 8
                  || v4 == 23 && *((_BYTE *)this + 27) & 0x10
                  || v4 == 24 && (*((_BYTE *)this + 27) & 0x20 || *((_BYTE *)this + 27) & 0x40)
                  || v4 == 29 && *((_BYTE *)this + 27) & 0x40 )
                {
                  result = 0;
                }
                else
                {
                  v6 = this[6];
                  if ( BYTE3(v6) & 2 )
                    v6 |= 0x100000u;
                  if ( BYTE3(v6) & 4 )
                    v6 |= 0x200000u;
                  if ( BYTE3(v6) & 8 )
                    v6 |= 0x400000u;
                  if ( BYTE3(v6) & 0x10 )
                    v6 |= 0x800000u;
                  if ( BYTE3(v6) & 0x40 )
                    v6 |= 0x20000000u;
                  if ( BYTE3(v6) & 0x20 )
                    v6 |= 0x1000000u;
                  v3 = *(&stru_4F4A14.ore + 12 * *((_BYTE *)this + 3) + v4);
                  if ( (v6 & v3) == v3 )
                    result = *((_BYTE *)this + 3) != 5 || v4 != 28 || (signed int)*((_BYTE *)this + 28) > 1;
                  else
                    result = 0;
                }
              }
              else
              {
                result = 1;
              }
            }
            else
            {
              result = 0;
            }
          }
          else
          {
            result = 0;
          }
        }
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

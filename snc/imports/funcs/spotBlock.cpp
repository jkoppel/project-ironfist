{
  int result; // eax@2
  void *v2; // [sp+10h] [bp-14h]@1
  int v3; // [sp+14h] [bp-10h]@4
  int v4; // [sp+18h] [bp-Ch]@1
  signed int v5; // [sp+1Ch] [bp-8h]@1
  signed int v6; // [sp+20h] [bp-4h]@17

  v2 = this;
  v4 = 8000;
  v5 = 1;
  while ( 1 )
  {
    result = v4;
    if ( last <= v4 )
      break;
    if ( v2 )
      v3 = (unsigned __int8)(*((_DWORD *)words + v4) >> 24) + 1;
    else
      v3 = *((_BYTE *)block + v4) - 1;
    if ( v3 == 256 )
    {
      v3 = 0;
    }
    else if ( v3 == -1 )
    {
      v3 = 255;
    }
    if ( v3 < 0 || v3 > 255 )
      panic();
    if ( v2 )
      SETFIRST(v4, v3);
    else
      *((_BYTE *)block + v4) = v3;
    switch ( v5 )
    {
      case 3:
        v6 = 1;
        break;
      case 1:
        v6 = 4;
        break;
      case 4:
        v6 = 5;
        break;
      case 5:
        v6 = 9;
        break;
      case 9:
        v6 = 2;
        break;
      case 2:
        v6 = 6;
        break;
      case 6:
        v6 = 7;
        break;
      case 8:
        v6 = 8;
        break;
      case 7:
        v6 = 3;
        break;
      default:
        v6 = 1;
        break;
    }
    v5 = v6;
    v4 += 17 * (v6 - 5) + 8000;
  }
  return result;
}
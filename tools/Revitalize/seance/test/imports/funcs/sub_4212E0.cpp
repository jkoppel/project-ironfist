{
  signed int v3; // eax@16
  void *v5; // [sp+14h] [bp-14h]@1
  signed int v6; // [sp+18h] [bp-10h]@2
  int a2a; // [sp+1Ch] [bp-Ch]@15
  int a4; // [sp+20h] [bp-8h]@9
  int a3a; // [sp+24h] [bp-4h]@9

  v5 = this;
  sub_4C3190(8, a2, 0, 0, a3, 0, 0);
  *((_BYTE *)v5 + 7 * a2 + 23735) = a3;
  *((_BYTE *)v5 + a2 + 24742) = a3;
  switch ( *((_BYTE *)v5 + 7 * a2 + 23736) )
  {
    case 101:
      v6 = 35;
      break;
    case 100:
      v6 = 42;
      break;
    case 0:
      v6 = 28;
      break;
    case 1:
      v6 = 21;
      break;
    default:
      v6 = 14;
      break;
  }
  switch ( v5 )
  {
    case 1u:
      a3a = *((_BYTE *)v5 + 7 * a2 + 23739);
      a4 = *((_BYTE *)v5 + 7 * a2 + 23740) - 1;
      break;
    case 0u:
      a3a = *((_BYTE *)v5 + 7 * a2 + 23739) + 1;
      a4 = *((_BYTE *)v5 + 7 * a2 + 23740) - 1;
      break;
    case 0x65u:
      a3a = *((_BYTE *)v5 + 7 * a2 + 23739) - 1;
      a4 = *((_BYTE *)v5 + 7 * a2 + 23740) - 3;
      break;
    case 0x64u:
      a3a = *((_BYTE *)v5 + 7 * a2 + 23739);
      a4 = *((_BYTE *)v5 + 7 * a2 + 23740);
      break;
    default:
      a3a = *((_BYTE *)v5 + 7 * a2 + 23739);
      a4 = *((_BYTE *)v5 + 7 * a2 + 23740);
      break;
  }
  a2a = *(_DWORD *)((char *)v5 + 2878) + 12 * a4 * *(_DWORD *)((char *)v5 + 2886) + 12 * a3a;
  if ( a3 == -1 )
  {
    LOBYTE(v3) = sub_470100((MapTiles *)((char *)v5 + 2878), a2a, a3a, a4, 14, 255, 1, -1);
  }
  else
  {
    sub_470100((MapTiles *)((char *)v5 + 2878), a2a, a3a, a4, 14, v6 + *((_BYTE *)v5 + 283 * (char)a3 + 1180), 1, -1);
    v3 = *((_BYTE *)v5 + 7 * a2 + 23736);
    if ( v3 == 1 )
    {
      LOBYTE(v3) = sub_429810((int)v5, a3a, a4);
    }
    else
    {
      if ( a4 > 0 )
      {
        if ( *((_BYTE *)v5 + 7 * a2 + 23736) == 2
          || *((_BYTE *)v5 + 7 * a2 + 23736) == 6
          || *((_BYTE *)v5 + 7 * a2 + 23736) == 5
          || *((_BYTE *)v5 + 7 * a2 + 23736) == 3
          || (v3 = *((_BYTE *)v5 + 7 * a2 + 23736), v3 == 4) )
        {
          v3 = sub_429700((int)v5, a3a, a4 - 1);
          if ( v3 )
            LOBYTE(v3) = sub_429810((int)v5, a3a, a4);
        }
      }
    }
  }
  return v3;
}

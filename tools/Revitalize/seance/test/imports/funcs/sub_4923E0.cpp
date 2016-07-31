{
  Player *v2; // eax@4
  int xp; // [sp+1Ch] [bp-34h]@29
  int v5; // [sp+20h] [bp-30h]@31
  signed int v6; // [sp+24h] [bp-2Ch]@32
  signed int i; // [sp+34h] [bp-1Ch]@2
  signed int j; // [sp+34h] [bp-1Ch]@9
  signed int k; // [sp+34h] [bp-1Ch]@29
  int v10; // [sp+44h] [bp-Ch]@1
  signed int v11; // [sp+4Ch] [bp-4h]@18

  v10 = 0;
  LOBYTE(v2) = ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 0x3F;
  switch ( ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 0x3F )
  {
    case 0:
      for ( i = 0; i < 14; ++i )
      {
        v2 = (Player *)artifactHasNegatives((ARTIFACT)*(_BYTE *)(i + a2 + 213));
        if ( v2 )
          ++v10;
      }
      if ( v10 )
      {
        LOBYTE(v2) = (_BYTE)curPlayer;
        if ( curPlayer->resources[6] >= 1500 )
        {
          for ( j = 0; j < 14; ++j )
          {
            if ( artifactHasNegatives((ARTIFACT)*(_BYTE *)(j + a2 + 213)) )
              *(_BYTE *)(j + a2 + 213) = -1;
          }
          v2 = curPlayer;
          v2->resources[6] -= 750;
        }
      }
      break;
    case 1:
      LOBYTE(v2) = a2;
      if ( !(*(_BYTE *)(a2 + 229) & 0x40) )
      {
        *(_DWORD *)(a2 + 227) |= 0x400000u;
        switch ( *(_BYTE *)(a2 + 23) )
        {
          case 2:
          case 3:
          case 4:
          case 5:
            v11 = 2;
            break;
          case 1:
            v11 = 0;
            break;
          case 0:
            v11 = 1;
            break;
          default:
            v11 = 0;
            break;
        }
        v2 = (Player *)v11;
        ++v2->_3[a2 + 44];
      }
      break;
    case 5:
      LOBYTE(v2) = a2;
      if ( !(*(_BYTE *)(a2 + 229) & 0x10) )
      {
        *(_DWORD *)(a2 + 227) |= 0x100000u;
        LOBYTE(v2) = *(_BYTE *)(a2 + 69) + 1;
        *(_BYTE *)(a2 + 69) = (_BYTE)v2;
      }
      break;
    case 6:
      LOBYTE(v2) = a2;
      if ( !(*(_BYTE *)(a2 + 229) & 0x20) )
      {
        xp = 0;
        for ( k = 0; k < 5; ++k )
        {
          v5 = *(_BYTE *)(k + a2 + 101);
          if ( v5 != -1 )
          {
            v6 = *(_WORD *)(a2 + 2 * k + 106);
            if ( v6 > 1 )
            {
              *(_WORD *)(a2 + 2 * k + 106) = (signed __int64)((double)v6 * 0.7);
              xp += creature_table[v5].hp * (v6 - *(_WORD *)(a2 + 2 * k + 106));
            }
          }
        }
        if ( xp )
          giveXPToHero((Hero *)a2, xp, 1);
        v2 = (Player *)(*(_DWORD *)(a2 + 227) | 0x200000);
        *(_DWORD *)(a2 + 227) = v2;
      }
      break;
    case 4:
      if ( !(*(_BYTE *)(a2 + 229) & 0x80) )
      {
        *(_DWORD *)(a2 + 227) |= 0x800000u;
        *(_DWORD *)(a2 + 49) += 400;
        *(_DWORD *)(a2 + 53) += 400;
      }
      v2 = (Player *)Hero::numStacksOfCreatureType((Hero *)a2, 7);
      if ( v2 )
        LOBYTE(v2) = Hero::transmuteStacks((Hero *)a2, 7, 8);
      break;
    case 2:
    case 3:
      return (char)v2;
  }
  return (char)v2;
}

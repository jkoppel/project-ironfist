int __cdecl sub_4AAA50()
{
  int result; // eax@2
  signed int v1; // [sp+10h] [bp-30h]@26
  int v2; // [sp+14h] [bp-2Ch]@25
  int v3; // [sp+18h] [bp-28h]@26
  char *v4; // [sp+1Ch] [bp-24h]@3
  signed int l; // [sp+20h] [bp-20h]@35
  signed int k; // [sp+24h] [bp-1Ch]@14
  signed int j; // [sp+28h] [bp-18h]@10
  signed int i; // [sp+2Ch] [bp-14h]@3
  int v9; // [sp+30h] [bp-10h]@1
  signed int v10; // [sp+34h] [bp-Ch]@14
  int v11; // [sp+38h] [bp-8h]@7
  int v12; // [sp+3Ch] [bp-4h]@1

  v12 = -1;
  v9 = 0;
LABEL_2:
  result = curPlayer->numCastles;
  if ( result > v9 )
  {
    v4 = (char *)&gameObject->castles[curPlayer->castlesOwned[v9]];
    for ( i = 0; ; ++i )
    {
      if ( i >= 2 )
      {
        ++v9;
        goto LABEL_2;
      }
      if ( i )
      {
        if ( v4[23] == -1 )
          continue;
        v11 = (int)&gameObject->heroes[v4[23]].army;
      }
      else
      {
        v11 = (int)(v4 + 8);
      }
      for ( j = 0; j < 5; ++j )
      {
        if ( *(_BYTE *)(j + v11) != -1 )
        {
          v10 = 0;
          for ( k = 20; k <= 24; ++k )
          {
            if ( LOBYTE((&buildingShortNames[3 * v4[3] + 27])[k + 1]) == *(_BYTE *)(j + v11) )
            {
              if ( (1 << (k + 5)) & *((_DWORD *)v4 + 6) )
              {
                v10 = 1;
                v12 = *(_BYTE *)(j + v11) + 1;
              }
            }
          }
          if ( (*(_BYTE *)(j + v11) == 35 || *(_BYTE *)(j + v11) == 36) && v4[27] & 0x40 )
          {
            v10 = 1;
            v12 = 37;
          }
          if ( v10 )
          {
            v2 = 2 * *(_WORD *)(v11 + 2 * j + 5) * (creature_table[v12].cost - creature_table[*(_BYTE *)(j + v11)].cost);
            if ( v12 == 37 )
            {
              v1 = 3;
              v3 = 2 * *(_WORD *)(v11 + 2 * j + 5);
            }
            else
            {
              if ( v12 == 46 )
              {
                v1 = 5;
                v3 = 2 * *(_WORD *)(v11 + 2 * j + 5);
              }
              else
              {
                v1 = -1;
                v3 = 0;
              }
            }
            if ( curPlayer->resources[6] >= v2 && (v1 == -1 || curPlayer->resources[v1] >= v3) )
            {
              curPlayer->resources[6] -= v2;
              if ( v1 != -1 )
                curPlayer->resources[v1] -= v3;
              *(_BYTE *)(j + v11) = v12;
              for ( l = 0; l < 5; ++l )
              {
                if ( l != j && *(_BYTE *)(l + v11) == *(_BYTE *)(j + v11) && (signed int)*(_WORD *)(v11 + 2 * l + 5) > 0 )
                {
                  *(_WORD *)(v11 + 2 * l + 5) += *(_WORD *)(v11 + 2 * j + 5);
                  *(_WORD *)(v11 + 2 * j + 5) = 0;
                  *(_BYTE *)(j + v11) = -1;
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}

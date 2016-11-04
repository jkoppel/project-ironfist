{
  int result; // eax@52
  int v3; // [sp+Ch] [bp-1Ch]@1
  int v4; // [sp+10h] [bp-18h]@1
  int v5; // [sp+14h] [bp-14h]@1
  signed int i; // [sp+1Ch] [bp-Ch]@3
  signed int j; // [sp+1Ch] [bp-Ch]@13
  signed int k; // [sp+1Ch] [bp-Ch]@18
  signed int l; // [sp+1Ch] [bp-Ch]@24
  signed int m; // [sp+1Ch] [bp-Ch]@37
  signed int n; // [sp+1Ch] [bp-Ch]@42
  int v12; // [sp+20h] [bp-8h]@1
  char v13; // [sp+24h] [bp-4h]@35

  v3 = this;
  v5 = 0;
  v12 = 0;
  v4 = 0;
  if ( *(_BYTE *)(this + 1146) && *(_BYTE *)(this + 1147) == dword_5235D4 )
  {
    for ( i = 0; *(_BYTE *)(this + 707) > i; ++i )
    {
      if ( *(_BYTE *)(i + this + 1119) == 10 || *(_BYTE *)(i + this + 1119) >= dword_5235D4 )
        *(_BYTE *)(i + this + 1113) = *(_BYTE *)(*(_BYTE *)(i + this + 1101) + this + 719);
    }
  }
  else
  {
    *(_BYTE *)(this + 1147) = dword_5235D4;
    if ( a2 )
      memcpy((void *)(this + 681), a2, 0x1A4u);
    else
      sub_40B430(this + 1126, (void *)(this + 681));
    for ( j = 0; j < 6; ++j )
    {
      if ( *(_BYTE *)(j + v3 + 689) )
        *(_BYTE *)(v5++ + v3 + 1101) = j;
    }
    for ( k = 0; k < 6; ++k )
    {
      if ( *(_BYTE *)(v3 + 707) > k )
      {
        *(_BYTE *)(k + v3 + 1107) = 0;
        *(_BYTE *)(k + v3 + 1113) = *(_BYTE *)(*(_BYTE *)(k + v3 + 1101) + v3 + 719);
        *(_BYTE *)(k + v3 + 1119) = -1;
        *(_BYTE *)(k + v3 + 1139) = -1;
      }
      else
      {
        *(_BYTE *)(k + v3 + 1139) = -1;
        *(_BYTE *)(k + v3 + 1119) = *(_BYTE *)(k + v3 + 1139);
        *(_BYTE *)(k + v3 + 1113) = *(_BYTE *)(k + v3 + 1119);
        *(_BYTE *)(k + v3 + 1107) = *(_BYTE *)(k + v3 + 1113);
      }
    }
    for ( l = 0; *(_BYTE *)(v3 + 707) > l; ++l )
    {
      if ( !*(_BYTE *)(*(_BYTE *)(l + v3 + 1101) + v3 + 695) || *(_BYTE *)(*(_BYTE *)(l + v3 + 1101) + v3 + 701) )
      {
        if ( !*(_BYTE *)(*(_BYTE *)(l + v3 + 1101) + v3 + 695) && *(_BYTE *)(*(_BYTE *)(l + v3 + 1101) + v3 + 701) )
        {
          *(_BYTE *)(l + v3 + 1119) = 10;
          *(_BYTE *)(l + v3 + 1139) = 0;
          ++v4;
        }
      }
      else
      {
        *(_BYTE *)(l + v3 + 1139) = 0;
        *(_BYTE *)(l + v3 + 1119) = v12++;
      }
    }
    v13 = v12 < dword_5235D4 && *(_BYTE *)(v3 + 707) - dword_5235D4 > v4;
    for ( m = 0; *(_BYTE *)(v3 + 707) > m; ++m )
    {
      if ( *(_BYTE *)(m + v3 + 1139) == -1 )
        *(_BYTE *)(m + v3 + 1139) = v13;
    }
    for ( n = 0; *(_BYTE *)(v3 + 707) > n; ++n )
    {
      if ( *(_BYTE *)(n + v3 + 1119) == -1 )
      {
        if ( v12 < dword_5235D4 && *(_BYTE *)(*(_BYTE *)(n + v3 + 1101) + v3 + 695) )
          *(_BYTE *)(n + v3 + 1119) = v12++;
        else
          *(_BYTE *)(n + v3 + 1119) = 10;
      }
    }
    *(_BYTE *)(v3 + 1125) = 1;
    *(_BYTE *)(v3 + 1146) = 1;
  }
  result = v3;
  *(_BYTE *)(v3 + 1145) = -1;
  return result;
}

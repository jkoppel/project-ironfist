{
  unsigned int v2; // eax@1
  int v3; // edx@1
  int v4; // esi@4
  int v6; // [sp+0h] [bp-24h]@1
  int v7; // [sp+4h] [bp-20h]@1
  int v8; // [sp+8h] [bp-1Ch]@1
  int v9; // [sp+Ch] [bp-18h]@1
  int v10; // [sp+10h] [bp-14h]@1
  int v11; // [sp+14h] [bp-10h]@1
  int v12; // [sp+18h] [bp-Ch]@1
  int v13; // [sp+1Ch] [bp-8h]@1

  v2 = 0;
  v13 = 0;
  v12 = 0;
  v11 = 0;
  v10 = 0;
  v9 = 0;
  v8 = 0;
  v7 = 0;
  v6 = 0;
  v3 = a2;
  while ( 1 )
  {
    LOBYTE(v2) = *(_BYTE *)v3;
    if ( !*(_BYTE *)v3 )
      break;
    ++v3;
    _bittestandset((signed __int32 *)&v6, v2);
  }
  v4 = a1;
  while ( 1 )
  {
    LOBYTE(v2) = *(_BYTE *)v4;
    if ( !*(_BYTE *)v4 )
      break;
    ++v4;
    if ( _bittest((signed __int32 *)&v6, v2) )
    {
      LOBYTE(v2) = v4 - 1;
      return v2;
    }
  }
  return v2;
}
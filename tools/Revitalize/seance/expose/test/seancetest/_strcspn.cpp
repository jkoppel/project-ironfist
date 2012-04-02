signed int __cdecl strcspn(int a1, int a2)
{
  unsigned int v2; // eax@1
  int v3; // edx@1
  int v4; // esi@4
  signed int v5; // ecx@4
  int v7; // [sp+0h] [bp-24h]@1
  int v8; // [sp+4h] [bp-20h]@1
  int v9; // [sp+8h] [bp-1Ch]@1
  int v10; // [sp+Ch] [bp-18h]@1
  int v11; // [sp+10h] [bp-14h]@1
  int v12; // [sp+14h] [bp-10h]@1
  int v13; // [sp+18h] [bp-Ch]@1
  int v14; // [sp+1Ch] [bp-8h]@1

  v2 = 0;
  v14 = 0;
  v13 = 0;
  v12 = 0;
  v11 = 0;
  v10 = 0;
  v9 = 0;
  v8 = 0;
  v7 = 0;
  v3 = a2;
  while ( 1 )
  {
    LOBYTE(v2) = *(_BYTE *)v3;
    if ( !*(_BYTE *)v3 )
      break;
    ++v3;
    _bittestandset((signed __int32 *)&v7, v2);
  }
  v4 = a1;
  v5 = -1;
  do
  {
    ++v5;
    LOBYTE(v2) = *(_BYTE *)v4;
    if ( !*(_BYTE *)v4 )
      break;
    ++v4;
  }
  while ( !_bittest((signed __int32 *)&v7, v2) );
  return v5;
}

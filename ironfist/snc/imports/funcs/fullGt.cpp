{
  bool result; // eax@2
  int v3; // [sp+Ch] [bp-14h]@1
  int v4; // [sp+Ch] [bp-14h]@5
  int v5; // [sp+Ch] [bp-14h]@7
  int v6; // [sp+Ch] [bp-14h]@9
  int v7; // [sp+10h] [bp-10h]@1
  int v8; // [sp+10h] [bp-10h]@5
  int v9; // [sp+10h] [bp-10h]@7
  int v10; // [sp+10h] [bp-10h]@9
  int v11; // [sp+14h] [bp-Ch]@3
  int v12; // [sp+14h] [bp-Ch]@5
  int v13; // [sp+14h] [bp-Ch]@7
  int v14; // [sp+14h] [bp-Ch]@9
  int v15; // [sp+18h] [bp-8h]@3
  int v16; // [sp+18h] [bp-8h]@5
  int v17; // [sp+18h] [bp-8h]@7
  int v18; // [sp+18h] [bp-8h]@9
  int v19; // [sp+1Ch] [bp-4h]@1

  v3 = a2;
  v7 = a1;
  v19 = a1;
  if ( a2 == a1 )
  {
    result = 0;
  }
  else
  {
    do
    {
      v15 = GETALL(v7);
      v11 = GETALL(v3);
      if ( v11 != v15 )
        return v11 < (unsigned int)v15;
      v8 = v7 + 4;
      v4 = v3 + 4;
      v16 = GETALL(v8);
      v12 = GETALL(v4);
      if ( v12 != v16 )
        return v12 < (unsigned int)v16;
      v9 = v8 + 4;
      v5 = v4 + 4;
      v17 = GETALL(v9);
      v13 = GETALL(v5);
      if ( v13 != v17 )
        return v13 < (unsigned int)v17;
      v10 = v9 + 4;
      v6 = v5 + 4;
      v18 = GETALL(v10);
      v14 = GETALL(v6);
      if ( v14 != v18 )
        return v14 < (unsigned int)v18;
      v7 = NORMALISEHI(v10 + 4);
      v3 = NORMALISEHI(v6 + 4);
    }
    while ( v7 != v19 );
    result = 0;
  }
  return result;
}
bool __fastcall sub_4D4390(int a1, int a2)
{
  bool result; // eax@2
  int v3; // [sp+Ch] [bp-14h]@1
  int v4; // [sp+Ch] [bp-14h]@8
  int v5; // [sp+Ch] [bp-14h]@13
  int v6; // [sp+Ch] [bp-14h]@18
  int v7; // [sp+10h] [bp-10h]@1
  int v8; // [sp+10h] [bp-10h]@8
  int v9; // [sp+10h] [bp-10h]@13
  int v10; // [sp+10h] [bp-10h]@18
  int v11; // [sp+14h] [bp-Ch]@3
  int v12; // [sp+14h] [bp-Ch]@8
  int v13; // [sp+14h] [bp-Ch]@13
  int v14; // [sp+14h] [bp-Ch]@18
  int v15; // [sp+18h] [bp-8h]@3
  int v16; // [sp+18h] [bp-8h]@8
  int v17; // [sp+18h] [bp-8h]@13
  int v18; // [sp+18h] [bp-8h]@18
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
    while ( 1 )
    {
      v15 = sub_4D3B10(v7);
      v11 = sub_4D3B10(v3);
      if ( v11 != v15 )
        return v11 < (unsigned int)v15;
      v8 = v7 + 4;
      v4 = v3 + 4;
      v16 = sub_4D3B10(v8);
      v12 = sub_4D3B10(v4);
      if ( v12 != v16 )
        return v12 < (unsigned int)v16;
      v9 = v8 + 4;
      v5 = v4 + 4;
      v17 = sub_4D3B10(v9);
      v13 = sub_4D3B10(v5);
      if ( v13 != v17 )
        return v13 < (unsigned int)v17;
      v10 = v9 + 4;
      v6 = v5 + 4;
      v18 = sub_4D3B10(v10);
      v14 = sub_4D3B10(v6);
      if ( v14 != v18 )
        break;
      v7 = sub_4D3C90(v10 + 4);
      v3 = sub_4D3C90(v6 + 4);
      if ( v7 == v19 )
        return 0;
    }
    result = v14 < (unsigned int)v18;
  }
  return result;
}

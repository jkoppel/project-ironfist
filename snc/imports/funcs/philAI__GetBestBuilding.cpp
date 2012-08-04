{
  double v4; // st7@9
  double v5; // ST18_8@12
  double v6; // ST10_8@12
  char *v7; // eax@12
  int result; // eax@14
  int v9; // [sp+10h] [bp-34h]@0
  int v10; // [sp+14h] [bp-30h]@0
  int v11; // [sp+18h] [bp-2Ch]@0
  int v12; // [sp+1Ch] [bp-28h]@0
  int v13; // [sp+20h] [bp-24h]@0
  int v14; // [sp+24h] [bp-20h]@1
  int v15; // [sp+28h] [bp-1Ch]@7
  int v16; // [sp+2Ch] [bp-18h]@7
  float v17; // [sp+30h] [bp-14h]@1
  signed int building; // [sp+34h] [bp-10h]@1
  int v19; // [sp+38h] [bp-Ch]@7
  int v20; // [sp+3Ch] [bp-8h]@1
  int v21; // [sp+40h] [bp-4h]@1

  v14 = (int)this;
  v21 = -1027211264;
  v17 = -99.0;
  v20 = -1;
  for ( building = 0; building < 32; ++building )
  {
    if ( (!((1 << building) & *(_DWORD *)(a2 + 24)) || !building && (signed int)*(_BYTE *)(a2 + 28) < 5)
      && CanBuild((unsigned int *)a2, building) )
    {
      philAI::ValueOfBuyingBuilding(
        a2,
        building,
        (int)&v15,
        (int)&v19,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        SLODWORD(v17),
        building,
        v19);
      if ( gpCurPlayer->personality == 1 )
      {
        v13 = v15;
        v15 = (signed __int64)((double)v15 * 1.3);
      }
      v12 = Random(1, 5) + 95;
      v4 = (double)v12 * *(float *)&v19 / 100.0;
      *(float *)&v16 = v4;
      if ( v4 > v17 )
      {
        v20 = building;
        v21 = v19;
        v17 = *(float *)&v16;
      }
      if ( giDebugLevel >= 5 )
      {
        v5 = *(float *)&v16;
        v6 = *(float *)&v19;
        v7 = GetBuildingName(*(_BYTE *)(a2 + 3), building);
        sprintf(
          gText,
          "Town:%2d  Building: % 18s   Raw BC = %8.2f,  RandBC = %8.2f.",
          *(_BYTE *)a2,
          v7,
          *(_QWORD *)&v6,
          *(_QWORD *)&v5);
        LogStr(gText);
      }
    }
  }
  *(_DWORD *)a3 = a2;
  *(_DWORD *)(a3 + 4) = 0;
  *(_DWORD *)(a3 + 8) = v20;
  result = a4;
  *(_DWORD *)a4 = v21;
  return result;
}
{
  int v1; // eax@1
  int v2; // esi@1
  int v3; // edi@1
  __int16 v4; // dx@1
  int v5; // eax@2
  int v6; // ebx@4
  int v7; // edi@4
  int v8; // edx@6
  int v9; // eax@7
  int v10; // edx@10
  int v11; // eax@12
  int v12; // eax@17
  int v13; // edi@19
  int v14; // ebx@20
  int v15; // eax@22
  int v16; // ecx@24
  int v17; // edi@24
  signed int v18; // ebx@24
  int v19; // ecx@24
  signed int v20; // eax@24
  int v21; // eax@24
  int v22; // edx@24
  int v23; // eax@24
  int v24; // edx@24

  v1 = *(_DWORD *)(this + 4);
  v2 = this;
  v3 = *(_DWORD *)(v1 + 44) + *(_WORD *)(this + 132);
  icon::DrawToBuffer(
    *(icon **)(this + 36),
    *(_WORD *)(this + 130) + *(_DWORD *)(v1 + 40),
    *(_DWORD *)(v1 + 44) + *(_WORD *)(this + 132),
    *(_WORD *)(this + 78),
    0);
  v4 = *(_WORD *)(v2 + 68);
  if ( *(_WORD *)(v2 + 62) == v4 )
    v5 = *(_WORD *)(v2 + 54);
  else
    v5 = *(_WORD *)(v2 + 52);
  v6 = 1;
  font::DrawBoundedString(
    *(font **)(v2 + 32),
    *(const char **)(*(_DWORD *)(v2 + 64) + 4 * v4),
    *(_WORD *)(v2 + 130) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 40) + 5,
    v3 + 4,
    *(_WORD *)(v2 + 134) - 10,
    *(_DWORD *)(*(_DWORD *)(v2 + 32) + 16) + 1,
    v5,
    *(_WORD *)(v2 + 58));
  v7 = *(_WORD *)(v2 + 116) + v3;
  if ( *(_WORD *)(v2 + 50) - 1 > 1 )
  {
    do
    {
      if ( v6 + *(_WORD *)(v2 + 68) >= *(_WORD *)(v2 + 60) )
        break;
      icon::DrawToBuffer(
        *(icon **)(v2 + 36),
        *(_WORD *)(v2 + 130) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 40),
        v7,
        *(_WORD *)(v2 + 80),
        0);
      v8 = *(_WORD *)(v2 + 68) + v6;
      v9 = *(_WORD *)(v2 + 62) == v8 ? *(_WORD *)(v2 + 54) : (signed int)*(_WORD *)(v2 + 52);
      ++v6;
      font::DrawBoundedString(
        *(font **)(v2 + 32),
        *(const char **)(*(_DWORD *)(v2 + 64) + 4 * v8),
        *(_WORD *)(v2 + 130) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 40) + 5,
        v7 + 2,
        *(_WORD *)(v2 + 134) - 10,
        *(_DWORD *)(*(_DWORD *)(v2 + 32) + 16) + 1,
        v9,
        *(_WORD *)(v2 + 58));
      v7 += *(_WORD *)(v2 + 118);
    }
    while ( *(_WORD *)(v2 + 50) - 1 > v6 );
  }
  icon::DrawToBuffer(
    *(icon **)(v2 + 36),
    *(_WORD *)(v2 + 130) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 40),
    v7,
    *(_WORD *)(v2 + 82),
    0);
  v10 = *(_WORD *)(v2 + 68) + v6;
  if ( *(_WORD *)(v2 + 60) > v10 )
  {
    if ( *(_WORD *)(v2 + 62) == v10 )
      v11 = *(_WORD *)(v2 + 54);
    else
      v11 = *(_WORD *)(v2 + 52);
    font::DrawBoundedString(
      *(font **)(v2 + 32),
      *(const char **)(*(_DWORD *)(v2 + 64) + 4 * v10),
      *(_WORD *)(v2 + 130) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 40) + 5,
      v7 + 2,
      *(_WORD *)(v2 + 134) - 10,
      *(_DWORD *)(*(_DWORD *)(v2 + 32) + 16) + 1,
      v11,
      *(_WORD *)(v2 + 58));
  }
  if ( *(_WORD *)(v2 + 70) > 0 )
  {
    if ( *(_BYTE *)(v2 + 172) )
      v12 = *(_WORD *)(v2 + 86);
    else
      v12 = *(_WORD *)(v2 + 84);
    icon::DrawToBuffer(
      *(icon **)(v2 + 36),
      *(_DWORD *)(*(_DWORD *)(v2 + 4) + 40) + *(_WORD *)(v2 + 138),
      *(_DWORD *)(*(_DWORD *)(v2 + 4) + 44) + *(_WORD *)(v2 + 140),
      v12,
      0);
    v13 = 2;
    icon::DrawToBuffer(
      *(icon **)(v2 + 36),
      *(_WORD *)(v2 + 146) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 40),
      *(_WORD *)(v2 + 148) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 44),
      *(_WORD *)(v2 + 92),
      0);
    if ( *(_WORD *)(v2 + 50) - 2 > 2 )
    {
      do
      {
        v14 = v13++ - 1;
        icon::DrawToBuffer(
          *(icon **)(v2 + 36),
          *(_WORD *)(v2 + 146) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 40),
          *(_WORD *)(v2 + 148) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 44) + v14 * *(_WORD *)(v2 + 118),
          *(_WORD *)(v2 + 94),
          0);
      }
      while ( *(_WORD *)(v2 + 50) - 2 > v13 );
    }
    icon::DrawToBuffer(
      *(icon **)(v2 + 36),
      *(_WORD *)(v2 + 146) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 40),
      *(_WORD *)(v2 + 148) + *(_DWORD *)(*(_DWORD *)(v2 + 4) + 44) + (v13 - 1) * *(_WORD *)(v2 + 118),
      *(_WORD *)(v2 + 96),
      0);
    if ( *(_BYTE *)(v2 + 173) )
      v15 = *(_WORD *)(v2 + 90);
    else
      v15 = *(_WORD *)(v2 + 88);
    icon::DrawToBuffer(
      *(icon **)(v2 + 36),
      *(_DWORD *)(*(_DWORD *)(v2 + 4) + 40) + *(_WORD *)(v2 + 154),
      *(_DWORD *)(*(_DWORD *)(v2 + 4) + 44) + *(_WORD *)(v2 + 156),
      v15,
      0);
    LOWORD(v16) = *(_WORD *)(v2 + 146);
    v17 = *(_DWORD *)(v2 + 4);
    v18 = *(_WORD *)(v2 + 70);
    v19 = *(_DWORD *)(v17 + 40) + v16 + 5;
    v20 = *(_WORD *)(v2 + 68) * *(_WORD *)(v2 + 170);
    *(_WORD *)(v2 + 162) = v19;
    v21 = v20 / v18;
    v22 = *(_DWORD *)(v17 + 44);
    LOWORD(v22) = v21 + v22;
    LOWORD(v21) = *(_WORD *)(v2 + 148);
    v23 = v22 + v21 + 3;
    v24 = *(_WORD *)(v2 + 98);
    *(_WORD *)(v2 + 164) = v23;
    icon::DrawToBuffer(*(icon **)(v2 + 36), (signed __int16)v19, (signed __int16)v23, v24, 0);
  }
  heroWindowManager::UpdateScreenRegion(
    gpWindowManager,
    *(_WORD *)(v2 + 24),
    *(_WORD *)(v2 + 26),
    *(_WORD *)(v2 + 28),
    *(_WORD *)(v2 + 30) + *(_WORD *)(v2 + 128));
}
{
  int a1a; // ebx@1
  int v2; // eax@12
  int v3; // esi@14
  unsigned int v4; // ecx@14
  int v5; // edx@15
  char *v6; // edx@15
  void *v7; // ecx@17
  int v8; // eax@22
  char *v9; // edx@24
  int v10; // edx@26
  int v11; // ecx@27
  int a1; // [sp+10h] [bp-Ch]@17
  char v13; // [sp+14h] [bp-8h]@14
  char v14; // [sp+15h] [bp-7h]@14
  char v15; // [sp+16h] [bp-6h]@14
  char v16; // [sp+17h] [bp-5h]@14
  char v17; // [sp+18h] [bp-4h]@14
  char v18; // [sp+19h] [bp-3h]@14
  char v19; // [sp+1Ah] [bp-2h]@14
  char v20; // [sp+1Bh] [bp-1h]@14

  ++iCycle1Count;
  a1a = this;
  if ( gpWindowManager && gpBufferPalette && gpWindowManager->ready == 1 && (gpWindowManager->field_56 || this) )
  {
    if ( giCycleType )
      gbEveryOtherCycle = 1 - gbEveryOtherCycle;
    else
      gbEveryOtherCycle = 1;
    if ( gbEveryOtherCycle )
    {
      if ( giCycleType == 2 )
      {
        iCombatCycleFrame = (((unsigned __int64)(iCombatCycleFrame + 1) >> 32) ^ abs(iCombatCycleFrame + 1) & 7)
                          - ((unsigned __int64)(iCombatCycleFrame + 1) >> 32);
        if ( iCombatCycleFrame < 5 )
          v2 = iCombatCycleFrame;
        else
          v2 = 8 - iCombatCycleFrame;
        v13 = -104;
        v14 = 67;
        v15 = 89;
        v16 = -75;
        v17 = 112;
        v3 = 0;
        v4 = (unsigned int)&gCyclePal;
        v18 = -37;
        v19 = -121;
        v20 = 16;
        do
        {
          v4 += 3;
          v5 = 3 * v2 + (unsigned __int8)*(&v13 + v3++);
          v6 = (char *)gpBufferPalette->contents + 3 * v5;
          *(_WORD *)(v4 - 3) = *(_WORD *)v6;
          *(_BYTE *)(v4 - 1) = v6[2];
        }
        while ( v4 < (unsigned int)((char *)&gCyclePal + 24) );
        goto LABEL_31;
      }
      v7 = (char *)&gCyclePal + 9;
      LOWORD(a1) = *(_WORD *)((char *)&gCyclePal + 9);
      BYTE2(a1) = *((_BYTE *)&gCyclePal + 11);
      LOBYTE(v7) = BYTE2(a1);
      memmove(v7, (unsigned __int16)&a1, (char *)&gCyclePal + 3, &gCyclePal, 9u);
      *(_WORD *)&gCyclePal = a1;
      *((_BYTE *)&gCyclePal + 2) = BYTE2(a1);
      LOWORD(a1) = *(_WORD *)((char *)&gCyclePal + 21);
      BYTE2(a1) = *((_BYTE *)&gCyclePal + 23);
      memmove(&a1, *(_WORD *)((char *)&gCyclePal + 21), (char *)&gCyclePal + 15, (char *)&gCyclePal + 12, 9u);
      *((_WORD *)&gCyclePal + 6) = a1;
      *((_BYTE *)&gCyclePal + 14) = BYTE2(a1);
      LOWORD(a1) = *(_WORD *)((char *)&gCyclePal + 51);
      BYTE2(a1) = *((_BYTE *)&gCyclePal + 53);
      memmove(&a1, *(_WORD *)((char *)&gCyclePal + 51), (char *)&gCyclePal + 51, (char *)&gCyclePal + 54, 0xCu);
      *(_WORD *)((char *)&gCyclePal + 63) = a1;
      *((_BYTE *)&gCyclePal + 65) = BYTE2(a1);
      LOWORD(a1) = *(_WORD *)((char *)&gCyclePal + 81);
      BYTE2(a1) = *((_BYTE *)&gCyclePal + 83);
      memmove(&a1, *(_WORD *)((char *)&gCyclePal + 81), (char *)&gCyclePal + 75, (char *)&gCyclePal + 72, 9u);
      *((_WORD *)&gCyclePal + 36) = a1;
      *((_BYTE *)&gCyclePal + 74) = BYTE2(a1);
      LOWORD(a1) = *(_WORD *)((char *)&gCyclePal + 93);
      BYTE2(a1) = *((_BYTE *)&gCyclePal + 95);
      memmove(&a1, *(_WORD *)((char *)&gCyclePal + 93), (char *)&gCyclePal + 87, (char *)&gCyclePal + 84, 9u);
      *((_WORD *)&gCyclePal + 42) = a1;
      *((_BYTE *)&gCyclePal + 86) = BYTE2(a1);
    }
    if ( !giCycleType )
    {
      LOWORD(a1) = *(_WORD *)((char *)&gCyclePal + 69);
      BYTE2(a1) = *((_BYTE *)&gCyclePal + 71);
      memmove(&a1, *(_WORD *)((char *)&gCyclePal + 69), (char *)&gCyclePal + 69, (char *)&gCyclePal + 66, 3u);
      *((_WORD *)&gCyclePal + 33) = a1;
      *((_BYTE *)&gCyclePal + 68) = BYTE2(a1);
      goto LABEL_31;
    }
    if ( giCycleType == 1 )
    {
      iCombatCycleFrame = (((unsigned __int64)(iCombatCycleFrame + 1) >> 32) ^ abs(iCombatCycleFrame + 1) & 7)
                        - ((unsigned __int64)(iCombatCycleFrame + 1) >> 32);
      if ( iCombatCycleFrame < 5 )
        v8 = iCombatCycleFrame;
      else
        v8 = 8 - iCombatCycleFrame;
      v9 = (char *)&gpBufferPalette->contents->colors[4 * v8 + 110];
    }
    else
    {
      if ( giCycleType != 3 )
        goto LABEL_31;
      v10 = (iCombatCycleFrame + 1) % 6;
      iCombatCycleFrame = v10;
      if ( v10 < 4 )
        v11 = iCombatCycleFrame;
      else
        v11 = 6 - v10;
      v9 = (char *)&gpBufferPalette->contents->colors[7 * v11 + 108];
    }
    *((_WORD *)&gCyclePal + 33) = *(_WORD *)v9;
    *((_BYTE *)&gCyclePal + 68) = v9[2];
LABEL_31:
    memcpy(&gpBufferPalette->contents->colors[214], &gCyclePal, 0x54u);
    ++iCycle2Count;
    if ( !a1a )
    {
      ++iCycle3Count;
      UpdatePalette(gpBufferPalette->contents);
    }
  }
}
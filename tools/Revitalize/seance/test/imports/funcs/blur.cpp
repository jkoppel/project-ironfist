{
  Bitmap *v6; // ecx@1
  char (*v7)[3]; // ecx@4
  signed int v8; // eax@4
  ResourceManager *v9; // esi@6
  int v10; // eax@6
  unsigned __int8 *v11; // ecx@10
  int v12; // eax@11
  int v13; // ST40_4@11
  int v14; // ST44_4@11
  int v15; // ST48_4@11
  int v16; // ST4C_4@11
  int v17; // ST50_4@11
  int v18; // ST54_4@11
  int v19; // ST58_4@11
  int v20; // ST5C_4@11
  int v21; // ST60_4@11
  int v22; // ST64_4@11
  int v23; // ST68_4@11
  int v24; // ST6C_4@11
  unsigned int v25; // edi@11
  void *v26; // eax@13
  void *v27; // edi@13
  int v28; // ebx@13
  void *v29; // ebp@13
  int v30; // eax@13
  void *v31; // esi@13
  signed int v32; // ecx@13
  int v33; // ebx@27
  Bitmap *newBMP; // [sp+10h] [bp-C5Ch]@2
  signed int v35; // [sp+14h] [bp-C58h]@7
  int v36; // [sp+18h] [bp-C54h]@6
  Bitmap *toBmpa; // [sp+1Ch] [bp-C50h]@1
  unsigned __int8 *v38; // [sp+54h] [bp-C18h]@10
  unsigned int npixels; // [sp+58h] [bp-C14h]@4
  unsigned __int8 (*a1a)[32]; // [sp+5Ch] [bp-C10h]@4
  Bitmap *fromBmpa; // [sp+60h] [bp-C0Ch]@1
  signed int v42; // [sp+64h] [bp-C08h]@10
  int a7[3][256]; // [sp+68h] [bp-C04h]@5

  toBmpa = toBmp;
  fromBmpa = fromBmp;
  yieldToGlobalUpdater();
  MouseManager::disableCursor(mouseManager);
  HeroWindowManager::resetSomeBMP(HeroWindowManager::instance, 0, 0, 640, height);
  v6 = (Bitmap *)operator new(0x1Au);
  if ( v6 )
    newBMP = Bitmap_constructor(v6, 0, 640, height);
  else
    newBMP = 0;
  npixels = 640 * height;
  memcpy(newBMP->contents, toBmpa->contents, 640 * height);
  a1a = (unsigned __int8 (*)[32])KBAlloc(0x8000u, "F:\\h2xsrc\\Base\\Blur.cpp", 25);
  v7 = (char (*)[3])palette->contents;
  v8 = 0;
  do
  {
    ++v7;
    ++v8;
    a7[2][v8] = (*v7)[-3];
    a7[0][v8] = (*v7)[-2];
    a7[1][v8] = (*v7)[-1];
  }
  while ( v8 < 256 );
  v9 = resourceManager;
  v10 = ResourceManager::setResource(resourceManager, "RGBLOOKP.BIN", 1);
  ResourceManager::pointToFile(v9, v10);
  ResourceManager::readFromCurrentFile(resourceManager, a1a, 0x8000u);
  memcpy(fromBmpa->contents, toBmpa->contents, npixels);
  yieldToGlobalUpdater();
  v36 = 4;
  a7[0][0] = height - 4;
  if ( height - 4 > 4 )
  {
    v35 = 2560;
    do
    {
      if ( (v36 & 0x3F) == 63 )
        yieldToGlobalUpdater();
      v42 = 632;
      v11 = &fromBmpa->contents[v35 + 4];
      v38 = &toBmpa->contents[v35 + 4];
      do
      {
        v12 = (v11++)[2];
        v13 = v11[1919];
        v14 = v11[2];
        v15 = *(v11 - 3);
        v16 = *(v11 - 1921);
        v17 = v11[3];
        v18 = *(v11 - 4);
        v19 = *(v11 - 5);
        v20 = v11[639];
        v21 = v11[2559];
        v22 = *(v11 - 641);
        v23 = *(v11 - 2561);
        v24 = *(v11 - 2);
        v25 = ((unsigned int)(a7[1][*v11 + 1]
                            + a7[1][*(v11 - 1281) + 1]
                            + a7[1][v11[1279] + 1]
                            + a7[1][v24 + 1]
                            + a7[1][v23 + 1]
                            + a7[1][v22 + 1]
                            + a7[1][v21 + 1]
                            + a7[1][v20 + 1]
                            + a7[1][v19 + 1]
                            + a7[1][v18 + 1]
                            + a7[1][v17 + 1]
                            + a7[1][v14 + 1]
                            + a7[1][v16 + 1]
                            + a7[1][v15 + 1]
                            + a7[1][v13 + 1]
                            + a7[1][v12 + 1]) >> 5)
            + ((a7[0][*v11 + 1]
              + a7[0][*(v11 - 1281) + 1]
              + a7[0][v11[1279] + 1]
              + a7[0][v24 + 1]
              + a7[0][v23 + 1]
              + a7[0][v22 + 1]
              + a7[0][v21 + 1]
              + a7[0][v20 + 1]
              + a7[0][v19 + 1]
              + a7[0][v18 + 1]
              + a7[0][v17 + 1]
              + a7[0][v16 + 1]
              + a7[0][v15 + 1]
              + a7[0][v14 + 1]
              + a7[0][v13 + 1]
              + a7[0][v12 + 1]) & 0xFFFFFFE0);
        *v38++ = a1a[(a7[2][*(v11 - 1281) + 1]
                    + a7[2][*v11 + 1]
                    + a7[2][v11[1279] + 1]
                    + a7[2][v24 + 1]
                    + a7[2][v23 + 1]
                    + a7[2][v22 + 1]
                    + a7[2][v21 + 1]
                    + a7[2][v20 + 1]
                    + a7[2][v19 + 1]
                    + a7[2][v18 + 1]
                    + a7[2][v17 + 1]
                    + a7[2][v16 + 1]
                    + a7[2][v15 + 1]
                    + a7[2][v14 + 1]
                    + a7[2][v13 + 1]
                    + a7[2][v12 + 1]) & 0xFFFFFFE0][v25];
        --v42;
      }
      while ( v42 );
      v35 += 640;
      ++v36;
    }
    while ( v36 < a7[0][0] );
  }
  yieldToGlobalUpdater();
  v26 = KBAlloc(0x300u, "F:\\h2xsrc\\Base\\Blur.cpp", 139);
  v27 = v26;
  v28 = (int)v26;
  v29 = KBAlloc(0x300u, "F:\\h2xsrc\\Base\\Blur.cpp", 140);
  memcpy(v27, dword_524234->contents, 0x300u);
  v30 = v28;
  v31 = v29;
  v32 = 256;
  a7[0][1] = v28;
  do
  {
    *(_BYTE *)v31 = a4 + *(_BYTE *)v30;
    *((_BYTE *)v31 + 1) = a5 + *(_BYTE *)(v30 + 1);
    *((_BYTE *)v31 + 2) = a6 + *(_BYTE *)(v30 + 2);
    if ( *(_BYTE *)v31 > 63 )
      *(_BYTE *)v31 = 63;
    if ( *(_BYTE *)v31 < 0 )
      *(_BYTE *)v31 = 0;
    if ( *((_BYTE *)v31 + 1) > 63 )
      *((_BYTE *)v31 + 1) = 63;
    if ( *((_BYTE *)v31 + 1) < 0 )
      *((_BYTE *)v31 + 1) = 0;
    if ( *((_BYTE *)v31 + 2) > 63 )
      *((_BYTE *)v31 + 2) = 63;
    if ( *((_BYTE *)v31 + 2) < 0 )
      *((_BYTE *)v31 + 2) = 0;
    v30 += 3;
    v31 = (char *)v31 + 3;
    --v32;
  }
  while ( v32 );
  v33 = a7[0][1];
  sub_4C7E00(HeroWindowManager::instance, 0, 0, 640, height, 150, (const void *)a7[0][1], (int)v29);
  sleep((signed __int64)(combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 350.0));
  HeroWindowManager::resetSomeBMP(HeroWindowManager::instance, 0, 0, 640, height);
  memcpy(toBmpa->contents, newBMP->contents, npixels);
  sub_4C7E00(HeroWindowManager::instance, 0, 0, 640, height, 150, v29, v33);
  KBFree(a1a, (int)"F:\\h2xsrc\\Base\\Blur.cpp", 168);
  if ( newBMP )
    ((void (__stdcall *)(signed int))newBMP->vtable->cleanUp)(1);
  MouseManager::enableCursor(mouseManager);
  KBFree((void *)v33, (int)"F:\\h2xsrc\\Base\\Blur.cpp", 173);
  KBFree(v29, (int)"F:\\h2xsrc\\Base\\Blur.cpp", 174);
}

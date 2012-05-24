{
  PaletteContents *v18; // ST2C_4@9
  void *v19; // eax@9
  int v20; // STB8_4@18
  signed int v21; // eax@19
  int v22; // ebx@64
  int v23; // ebx@68
  PaletteContents *v24; // eax@88
  HeroWindowManager *result; // eax@90
  CombatManager *v26; // [sp+40h] [bp-80h]@1
  Palette *v27; // [sp+54h] [bp-6Ch]@4
  int a7; // [sp+5Ch] [bp-64h]@74
  signed int v29; // [sp+60h] [bp-60h]@71
  float v30; // [sp+64h] [bp-5Ch]@69
  signed int a4; // [sp+6Ch] [bp-54h]@73
  float v32; // [sp+70h] [bp-50h]@71
  PaletteContents *a1; // [sp+74h] [bp-4Ch]@9
  signed int v34; // [sp+78h] [bp-48h]@3
  Palette *v35; // [sp+7Ch] [bp-44h]@3
  int *v36; // [sp+80h] [bp-40h]@19
  signed int v37; // [sp+84h] [bp-3Ch]@21
  int j; // [sp+88h] [bp-38h]@23
  signed int i; // [sp+8Ch] [bp-34h]@9
  int k; // [sp+8Ch] [bp-34h]@25
  int l; // [sp+8Ch] [bp-34h]@53
  int m; // [sp+8Ch] [bp-34h]@60
  int n; // [sp+8Ch] [bp-34h]@79
  signed int screenY; // [sp+98h] [bp-28h]@25
  int screenYa; // [sp+98h] [bp-28h]@45
  signed int v46; // [sp+9Ch] [bp-24h]@25
  int v47; // [sp+9Ch] [bp-24h]@45
  int thisa; // [sp+A0h] [bp-20h]@3
  int v49; // [sp+A4h] [bp-1Ch]@3
  int screenX; // [sp+A8h] [bp-18h]@25
  int v51; // [sp+ACh] [bp-14h]@25
  Palette *pal; // [sp+B0h] [bp-10h]@3
  int v53; // [sp+B4h] [bp-Ch]@60
  int v54; // [sp+B8h] [bp-8h]@21
  int v55; // [sp+BCh] [bp-4h]@64

  v26 = (CombatManager *)this;
  if ( clearAfterwards )
    MouseManager::disableCursor(mouseManager);
  v49 = divergeFreq;
  v34 = 0;
  thisa = getTickCount();
  HeroWindowManager::instance->field_56 = 0;
  pal = 0;
  v35 = 0;
  if ( a18 )
  {
    pal = ResourceManager::getPal(resourceManager, "kb.pal");
    v27 = (Palette *)operator new(0x14u);
    if ( v27 )
      v35 = Palette_constructor(v27);
    else
      v35 = 0;
    if ( !v35 )
      fatalOutOfMemoryError();
    v18 = Palette::getContents(pal);
    v19 = Palette::getContents(v35);
    memcpy(v19, v18, 0x300u);
    a1 = Palette::getContents(v35);
    for ( i = 0; i < 768; ++i )
    {
      *(&a1->colors[0].red + i) += 16;
      if ( *(&a1->colors[0].red + i) > 63 )
        *(&a1->colors[0].red + i) = 63;
    }
    someSortOfPaletteSwap(a1, 1);
  }
  if ( endX < startX )
  {
    minRandomDiverge = -minRandomDiverge;
    maxRandomDiverge = -maxRandomDiverge;
  }
  if ( maxRandomDiverge < minRandomDiverge )
  {
    v20 = maxRandomDiverge;
    maxRandomDiverge = minRandomDiverge;
    minRandomDiverge = v20;
  }
  v36 = (int *)operator new(0xBB8u);
  v21 = endWidth;
  if ( endWidth <= startWidth )
    v21 = startWidth;
  v37 = v21 >> 1;
  sub_4A2930(
    v36,
    startX,
    startY,
    endX,
    endY,
    forkControl1,
    startWidth,
    endWidth,
    colorController,
    minRandomDiverge,
    maxRandomDiverge,
    divergeFreq,
    a13);
  v54 = 1;
  while ( !v34 )
  {
    for ( j = 0; (divergeFreq - 1) / divergeFreq + 1 > j; ++j )
    {
      v34 = 1;
      screenY = 9999;
      screenX = 9999;
      v51 = -1;
      v46 = -1;
      for ( k = 0; v54 > k; ++k )
      {
        if ( !v36[30 * k + 16] )
        {
          if ( v36[30 * k + 11] > v46 )
            v46 = v36[30 * k + 11];
          if ( v36[30 * k + 11] < screenX )
            screenX = v36[30 * k + 11];
          if ( v36[30 * k + 12] > v51 )
            v51 = v36[30 * k + 12];
          if ( v36[30 * k + 12] < screenY )
            screenY = v36[30 * k + 12];
          sub_4A2440((int)&v36[30 * k], v49);
          if ( v36[30 * k + 11] > v46 )
            v46 = v36[30 * k + 11];
          if ( v36[30 * k + 11] < screenX )
            screenX = v36[30 * k + 11];
          if ( v36[30 * k + 12] > v51 )
            v51 = v36[30 * k + 12];
          if ( v36[30 * k + 12] < screenY )
            screenY = v36[30 * k + 12];
        }
      }
      v47 = v37 + v46;
      screenX -= v37;
      v51 += v37;
      screenYa = screenY - v37;
      if ( screenX < 0 )
        screenX = 0;
      if ( screenYa < 0 )
        screenYa = 0;
      if ( v47 > 639 )
        v47 = 639;
      if ( v51 > 442 )
        v51 = 442;
      sleepUntilPointer(&thisa);
      thisa = (signed __int64)((double)getTickCount() + (double)a17 * combatSpeedPercentages[*(_DWORD *)&combatSpeed]);
      renderBitmapToScreenWithWinG(
        HeroWindowManager::instance->screenBuffer,
        screenX,
        screenYa,
        v47 - screenX + 1,
        v51 - screenYa + 1,
        screenX,
        screenYa);
      yieldToGlobalUpdater();
      for ( l = 0; v54 > l; ++l )
      {
        if ( !v36[30 * l + 16] )
          v34 = 0;
      }
      if ( v34 )
        goto LABEL_85;
      if ( forkControl1 )
      {
        v53 = v54;
        for ( m = 0; v53 > m; ++m )
        {
          if ( !v36[30 * m + 16] )
          {
            v22 = abs(v36[30 * m + 2] - v36[30 * m + 11]);
            v55 = abs(v36[30 * m + 3] - v36[30 * m + 12]) + v22;
            if ( v54 < 25 )
            {
              if ( 2 * divergeFreq < v55 )
              {
                if ( unseededNextRand(0, 100 * forkControl1 / divergeFreq) < 100 )
                {
                  if ( !v36[30 * m + 21]
                    || (v23 = abs(v36[30 * m + 22] - v36[30 * m + 12]),
                        (double)(abs(v36[30 * m + 21] - v36[30 * m + 11]) + v23) >= (double)forkControl1 * 0.75) )
                  {
                    v36[30 * m + 21] = v36[30 * m + 11];
                    v36[30 * m + 22] = v36[30 * m + 12];
                    v30 = (double)unseededNextRand(50, 80) / 100.0;
                    if ( unseededNextRand(0, 1) )
                      v30 = -v30;
                    v32 = v30 + *(float *)&v36[30 * m + 15];
                    v29 = unseededNextRand(forkControl2 >> 1, forkControl2);
                    if ( v55 >> 1 < v29 )
                      v29 = v55 >> 1;
                    sub_4DEFC0();
                    a4 = (signed __int64)(v32 * (double)v29 + (double)v36[30 * m + 11]);
                    sub_4DEFCA();
                    if ( v36[30 * m + 23] <= v36[30 * m + 24] )
                      a7 = v36[30 * m + 5];
                    else
                      a7 = v36[30 * m + 5] - 1;
                    sub_4A2930(
                      &v36[30 * v54++],
                      v36[30 * m + 11],
                      v36[30 * m + 12],
                      a4,
                      (signed __int64)(v32 * (double)v29 + (double)v36[30 * m + 12]),
                      forkControl1,
                      a7,
                      1,
                      colorController,
                      (signed __int64)((double)minRandomDiverge * 0.66 + -20.0),
                      (signed __int64)((double)maxRandomDiverge * 0.66 + 20.0),
                      divergeFreq,
                      v36[30 * m + 29]);
                  }
                }
              }
            }
          }
        }
      }
    }
    for ( n = 0; v54 > n; ++n )
    {
      if ( !v36[30 * n + 16] )
        sub_4A2190((int)&v36[30 * n]);
    }
  }
LABEL_85:
  operator delete(v36);
  if ( clearAfterwards )
  {
    CombatManager::drawBattlefield(v26, 1, 0, 0, 0, 75, 1, 1);
    MouseManager::enableCursor(mouseManager);
  }
  if ( a18 )
  {
    v24 = Palette::getContents(pal);
    someSortOfPaletteSwap(v24, 1);
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)pal);
    if ( v35 )
      ((void (__thiscall *)(Palette *))v35->vtable->cleanUp)(v35);
  }
  result = HeroWindowManager::instance;
  HeroWindowManager::instance->field_56 = 1;
  return result;
}

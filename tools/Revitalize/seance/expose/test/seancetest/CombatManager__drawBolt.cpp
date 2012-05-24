HeroWindowManager *__userpurge CombatManager::drawBolt<eax>(CombatManager *ecx0<ecx>, int a2<ebx>, double a3<st1>, int clearAfterwards, signed int startX, signed int startY, signed int endX, signed int endY, int forkControl1, int forkControl2, int startWidth, int endWidth, int colorController, int minRandomDiverge, int maxRandomDiverge, int divergeFreq, int a17, int a13, signed int a19, int a20)
{
  PaletteContents *v20; // ST2C_4@9
  void *v21; // eax@9
  int v22; // STB8_4@18
  int v23; // eax@19
  int v24; // ST68_4@53
  int v25; // ebx@64
  int v26; // ebx@68
  PaletteContents *v27; // eax@88
  HeroWindowManager *result; // eax@90
  CombatManager *v29; // [sp+40h] [bp-80h]@1
  Palette *v30; // [sp+54h] [bp-6Ch]@4
  int a7; // [sp+5Ch] [bp-64h]@74
  signed int v32; // [sp+60h] [bp-60h]@71
  float v33; // [sp+64h] [bp-5Ch]@69
  signed int a4; // [sp+6Ch] [bp-54h]@73
  float v35; // [sp+70h] [bp-50h]@71
  PaletteContents *a1; // [sp+74h] [bp-4Ch]@9
  signed int v37; // [sp+78h] [bp-48h]@3
  Palette *v38; // [sp+7Ch] [bp-44h]@3
  int *v39; // [sp+80h] [bp-40h]@19
  int v40; // [sp+84h] [bp-3Ch]@21
  int j; // [sp+88h] [bp-38h]@23
  signed int i; // [sp+8Ch] [bp-34h]@9
  int k; // [sp+8Ch] [bp-34h]@25
  int l; // [sp+8Ch] [bp-34h]@53
  int m; // [sp+8Ch] [bp-34h]@60
  int n; // [sp+8Ch] [bp-34h]@79
  signed int screenY; // [sp+98h] [bp-28h]@25
  int screenYa; // [sp+98h] [bp-28h]@45
  signed int v49; // [sp+9Ch] [bp-24h]@25
  int v50; // [sp+9Ch] [bp-24h]@45
  int thisa; // [sp+A0h] [bp-20h]@3
  int v52; // [sp+A4h] [bp-1Ch]@3
  int screenX; // [sp+A8h] [bp-18h]@25
  int v54; // [sp+ACh] [bp-14h]@25
  Palette *pal; // [sp+B0h] [bp-10h]@3
  int v56; // [sp+B4h] [bp-Ch]@60
  int v57; // [sp+B8h] [bp-8h]@21
  int v58; // [sp+BCh] [bp-4h]@64

  v29 = ecx0;
  if ( clearAfterwards )
    MouseManager::disableCursor(mouseManager);
  v52 = divergeFreq;
  v37 = 0;
  thisa = getTickCount();
  HeroWindowManager::instance->field_56 = 0;
  pal = 0;
  v38 = 0;
  if ( a20 )
  {
    pal = ResourceManager::getPal(resourceManager, "kb.pal");
    v30 = (Palette *)operator new(20);
    if ( v30 )
      v38 = Palette_constructor(v30);
    else
      v38 = 0;
    if ( !v38 )
      fatalOutOfMemoryError();
    v20 = Palette::getContents(pal);
    v21 = Palette::getContents(v38);
    memcpy(v21, v20, 0x300u);
    a1 = Palette::getContents(v38);
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
    v22 = maxRandomDiverge;
    maxRandomDiverge = minRandomDiverge;
    minRandomDiverge = v22;
  }
  v39 = (int *)operator new(0xBB8u);
  v23 = endWidth;
  if ( endWidth <= startWidth )
    v23 = startWidth;
  v40 = v23 >> 1;
  sub_4A2930(
    (unsigned __int8)a2,
    a3,
    v39,
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
  v57 = 1;
  while ( !v37 )
  {
    for ( j = 0; (divergeFreq - 1) / divergeFreq + 1 > j; ++j )
    {
      v37 = 1;
      screenY = 9999;
      screenX = 9999;
      v54 = -1;
      v49 = -1;
      for ( k = 0; v57 > k; ++k )
      {
        if ( !v39[30 * k + 16] )
        {
          if ( v39[30 * k + 11] > v49 )
            v49 = v39[30 * k + 11];
          if ( v39[30 * k + 11] < screenX )
            screenX = v39[30 * k + 11];
          if ( v39[30 * k + 12] > v54 )
            v54 = v39[30 * k + 12];
          if ( v39[30 * k + 12] < screenY )
            screenY = v39[30 * k + 12];
          sub_4A2440((int)&v39[30 * k], v52);
          if ( v39[30 * k + 11] > v49 )
            v49 = v39[30 * k + 11];
          if ( v39[30 * k + 11] < screenX )
            screenX = v39[30 * k + 11];
          if ( v39[30 * k + 12] > v54 )
            v54 = v39[30 * k + 12];
          if ( v39[30 * k + 12] < screenY )
            screenY = v39[30 * k + 12];
        }
      }
      v50 = v40 + v49;
      screenX -= v40;
      v54 += v40;
      screenYa = screenY - v40;
      if ( screenX < 0 )
        screenX = 0;
      if ( screenYa < 0 )
        screenYa = 0;
      if ( v50 > 639 )
        v50 = 639;
      if ( v54 > 442 )
        v54 = 442;
      sleepUntilPointer(&thisa);
      v24 = getTickCount();
      a3 = (double)a19 * combatSpeedPercentages[*(_DWORD *)&combatSpeed];
      thisa = (signed __int64)((double)v24 + a3);
      renderBitmapToScreenWithWinG(
        HeroWindowManager::instance->screenBuffer,
        screenX,
        screenYa,
        v50 - screenX + 1,
        v54 - screenYa + 1,
        screenX,
        screenYa);
      yieldToGlobalUpdater();
      for ( l = 0; v57 > l; ++l )
      {
        if ( !v39[30 * l + 16] )
          v37 = 0;
      }
      if ( v37 )
        goto LABEL_85;
      if ( forkControl1 )
      {
        v56 = v57;
        for ( m = 0; v56 > m; ++m )
        {
          if ( !v39[30 * m + 16] )
          {
            v25 = abs(v39[30 * m + 2] - v39[30 * m + 11]);
            a2 = abs(v39[30 * m + 3] - v39[30 * m + 12]) + v25;
            v58 = a2;
            if ( v57 < 25 )
            {
              if ( 2 * divergeFreq < v58 )
              {
                if ( unseededNextRand(0, 100 * forkControl1 / divergeFreq) < 100 )
                {
                  if ( !v39[30 * m + 21]
                    || (v26 = abs(v39[30 * m + 22] - v39[30 * m + 12]),
                        a2 = abs(v39[30 * m + 21] - v39[30 * m + 11]) + v26,
                        a3 = (double)a2,
                        a3 >= (double)forkControl1 * 0.75) )
                  {
                    v39[30 * m + 21] = v39[30 * m + 11];
                    v39[30 * m + 22] = v39[30 * m + 12];
                    v33 = (double)unseededNextRand(50, 80) / 100.0;
                    if ( unseededNextRand(0, 1) )
                      v33 = -v33;
                    v35 = v33 + *(float *)&v39[30 * m + 15];
                    v32 = unseededNextRand(forkControl2 >> 1, forkControl2);
                    if ( v58 >> 1 < v32 )
                      v32 = v58 >> 1;
                    sub_4DEFC0();
                    a4 = (signed __int64)(v35 * (double)v32 + (double)v39[30 * m + 11]);
                    sub_4DEFCA();
                    a3 = (double)v39[30 * m + 12];
                    LOBYTE(a2) = (_BYTE)v39;
                    if ( v39[30 * m + 23] <= v39[30 * m + 24] )
                      a7 = v39[30 * m + 5];
                    else
                      a7 = v39[30 * m + 5] - 1;
                    sub_4A2930(
                      (unsigned __int8)v39,
                      a3,
                      &v39[30 * v57++],
                      v39[30 * m + 11],
                      v39[30 * m + 12],
                      a4,
                      (signed __int64)(v35 * (double)v32 + a3),
                      forkControl1,
                      a7,
                      1,
                      colorController,
                      (signed __int64)((double)minRandomDiverge * 0.66 + -20.0),
                      (signed __int64)((double)maxRandomDiverge * 0.66 + 20.0),
                      divergeFreq,
                      v39[30 * m + 29]);
                  }
                }
              }
            }
          }
        }
      }
    }
    for ( n = 0; v57 > n; ++n )
    {
      if ( !v39[30 * n + 16] )
        sub_4A2190(a2, a3, (int)&v39[30 * n]);
    }
  }
LABEL_85:
  operator delete(v39);
  if ( clearAfterwards )
  {
    CombatManager::drawBattlefield(v29, 1, 0, 0, 0, 75, 1, 1);
    MouseManager::enableCursor(mouseManager);
  }
  if ( a20 )
  {
    v27 = Palette::getContents(pal);
    someSortOfPaletteSwap(v27, 1);
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)pal);
    if ( v38 )
      ((void (__thiscall *)(Palette *))v38->vtable->cleanUp)(v38);
  }
  result = HeroWindowManager::instance;
  HeroWindowManager::instance->field_56 = 1;
  return result;
}

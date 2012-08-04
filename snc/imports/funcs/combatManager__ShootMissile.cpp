{
  float v6; // ST40_4@10
  float v7; // ST3C_4@10
  bitmap *this; // [sp+30h] [bp-64h]@18
  int deltaY; // [sp+3Ch] [bp-58h]@3
  int v10; // [sp+40h] [bp-54h]@21
  int deltaX; // [sp+44h] [bp-50h]@1
  int v12; // [sp+4Ch] [bp-48h]@21
  int offsetY; // [sp+50h] [bp-44h]@21
  signed int i; // [sp+54h] [bp-40h]@8
  int j; // [sp+54h] [bp-40h]@21
  bitmap *oldRect; // [sp+58h] [bp-3Ch]@19
  int offsetX; // [sp+5Ch] [bp-38h]@21
  int stepY; // [sp+68h] [bp-2Ch]@16
  int y; // [sp+6Ch] [bp-28h]@18
  signed int v20; // [sp+70h] [bp-24h]@1
  int stepX; // [sp+74h] [bp-20h]@16
  int x; // [sp+78h] [bp-1Ch]@18
  signed int v23; // [sp+7Ch] [bp-18h]@1
  char mirror; // [sp+80h] [bp-14h]@1
  int probablyNumFrames; // [sp+84h] [bp-10h]@15
  int oldY; // [sp+88h] [bp-Ch]@21
  int spriteIdx; // [sp+8Ch] [bp-8h]@5
  int oldX; // [sp+90h] [bp-4h]@21

  v20 = xTarg - xFrom;
  v23 = yTarg - yFrom;
  deltaX = xTarg - xFrom;
  mirror = 0;
  if ( xTarg - xFrom < 0 )
  {
    mirror = 1;
    deltaX = -deltaX;
  }
  deltaY = yTarg - yFrom;
  if ( deltaX )
  {
    atan();
    for ( i = 1; ; ++i )
    {
      if ( i < 9 )
      {
        v6 = (double)-deltaY / (double)deltaX;
        v7 = v6 * 180.0 / 3.14159;
        if ( (anglesOfImgIdxs[i - 1] + anglesOfImgIdxs[i]) / 2.0 >= v7 )
          continue;
      }
      break;
    }
    if ( i >= 9 )
      spriteIdx = 8;
    else
      spriteIdx = i - 1;
  }
  else if ( deltaY <= 0 )
  {
    spriteIdx = 0;
  }
  else
  {
    spriteIdx = 8;
  }
  probablyNumFrames = (signed int)((unsigned __int64)(signed __int64)sqrt((double)(v23 * v23 + v20 * v20)) + 15) / 31;
  if ( probablyNumFrames <= 1 )
  {
    stepX = xTarg - xFrom;
    stepY = yTarg - yFrom;
  }
  else
  {
    stepX = v20 / (probablyNumFrames - 1);
    stepY = v23 / (probablyNumFrames - 1);
  }
  x = xFrom;
  y = yFrom;
  this = (bitmap *)operator new(26);
  if ( this )
    oldRect = bitmap::bitmap(this, 33, 50, 50);
  else
    oldRect = 0;
  bitmap::GrabBitmapCareful(oldRect, gpWindowManager->screenBuffer, xFrom - 25, yFrom - 25);
  oldX = xFrom;
  oldY = yFrom;
  offsetX = 639;
  v12 = 0;
  offsetY = 480;
  v10 = 0;
  for ( j = 0; probablyNumFrames > j; ++j )
  {
    if ( oldX - 25 < offsetX )
      offsetX = oldX - 25;
    if ( offsetX < 0 )
      offsetX = 0;
    if ( oldX + 25 > v12 )
      v12 = oldX + 25;
    if ( v12 > 639 )
      v12 = 639;
    if ( oldY - 25 < offsetY )
      offsetY = oldY - 25;
    if ( offsetY < 0 )
      offsetY = 0;
    if ( oldY + 25 > v10 )
      v10 = oldY + 25;
    if ( v10 > 442 )
      v10 = 442;
    if ( j )
    {
      bitmap::DrawToBufferCareful(oldRect, oldX - 25, oldY - 25);
      bitmap::GrabBitmapCareful(oldRect, gpWindowManager->screenBuffer, x - 25, y - 25);
    }
    else
    {
      if ( offsetX < giMinExtentX )
        giMinExtentX = offsetX;
      if ( v12 > giMaxExtentX )
        giMaxExtentX = v12;
      if ( offsetY < giMinExtentY )
        giMinExtentY = offsetY;
      if ( giMaxExtentY < v10 )
        giMaxExtentY = v10;
    }
    icon::DrawToBuffer(icn, x, y, spriteIdx, mirror);
    if ( j )
    {
      DelayTil(&glTimers);
      heroWindowManager::UpdateScreenRegion(gpWindowManager, offsetX, offsetY, v12 - offsetX + 1, v10 - offsetY + 1);
    }
    else
    {
      heroWindowManager::UpdateScreenRegion(
        gpWindowManager,
        giMinExtentX,
        giMinExtentY,
        giMaxExtentX - giMinExtentX + 1,
        giMaxExtentY - giMinExtentY + 1);
    }
    glTimers = (signed __int64)((double)KBTickCount() + gfCombatSpeedMod[*(_DWORD *)&combatSpeed] * 25.0);
    oldX = x;
    oldY = y;
    x += stepX;
    y += stepY;
    offsetX = x - 25;
    v12 = x + 25;
    offsetY = y - 25;
    v10 = y + 25;
  }
  bitmap::DrawToBuffer(oldRect, oldX - 25, oldY - 25);
  heroWindowManager::UpdateScreenRegion(gpWindowManager, oldX - 25, oldY - 25, 0x32u, 50);
  if ( oldRect )
    oldRect->vtable->cleanUp((resource *)oldRect, 1);
}
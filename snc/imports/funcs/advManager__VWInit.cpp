{
  int v3; // [sp+Ch] [bp-4h]@1

  v3 = (int)this;
  if ( giViewWorldScale == 4 )
  {
    giViewWorldScaleLookup = 0;
  }
  else if ( giViewWorldScale == 6 )
  {
    giViewWorldScaleLookup = 1;
  }
  else
  {
    giViewWorldScaleLookup = 2;
  }
  iVWViewableCells = 448 / giViewWorldScale;
  if ( MAP_WIDTH < 448 / giViewWorldScale )
    iVWViewableCells = MAP_WIDTH;
  iVWCenterOffset = iVWViewableCells >> 1;
  iVWMapOriginY = 0;
  iVWMapOriginX = 0;
  if ( MAP_WIDTH != iVWViewableCells )
  {
    iVWMapOriginX = a2 - (iVWViewableCells >> 1);
    if ( iVWMapOriginX < 0 )
      iVWMapOriginX = 0;
    if ( iVWViewableCells + iVWMapOriginX >= MAP_WIDTH )
      iVWMapOriginX = MAP_WIDTH - iVWViewableCells;
    iVWMapOriginY = a3 - (iVWViewableCells >> 1);
    if ( iVWMapOriginY < 0 )
      iVWMapOriginY = 0;
    if ( iVWMapOriginY + iVWViewableCells >= MAP_HEIGHT )
      iVWMapOriginY = MAP_HEIGHT - iVWViewableCells;
  }
  iVWXPixelOffset = (480 - iVWViewableCells * giViewWorldScale) >> 1;
  iVWYPixelOffset = (480 - iVWViewableCells * giViewWorldScale) >> 1;
  mouseManager::SetPointer(gpMouseManager, "advmice.mse", 0, -999);
  sprintf(gText, "ground%d.icn", giViewWorldScale);
  pVWGround = resourceManager::GetIcon(gpResourceManager, gText);
  sprintf(gText, "vwflag%d.icn", giViewWorldScale);
  pVWFlags = resourceManager::GetIcon(gpResourceManager, gText);
  sprintf(gText, "misc%d.icn", giViewWorldScale);
  pVWMisc = resourceManager::GetIcon(gpResourceManager, gText);
  sprintf(gText, "letter%d.icn", giViewWorldScale);
  pVWLetters = resourceManager::GetIcon(gpResourceManager, gText);
  advManager::UpdateRadar(v3, 1, 0);
}
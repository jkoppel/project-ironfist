void __thiscall sub_499220(void *this, int a2, int a3)
{
  int v3; // [sp+Ch] [bp-4h]@1

  v3 = (int)this;
  if ( dword_51923C == 4 )
  {
    dword_519240 = 0;
  }
  else
  {
    if ( dword_51923C == 6 )
      dword_519240 = 1;
    else
      dword_519240 = 2;
  }
  dword_52FF68 = 448 / dword_51923C;
  if ( mapWidth < 448 / dword_51923C )
    dword_52FF68 = mapWidth;
  dword_52FF64 = dword_52FF68 >> 1;
  dword_52FF60 = 0;
  dword_52FF5C = 0;
  if ( mapWidth != dword_52FF68 )
  {
    dword_52FF5C = a2 - (dword_52FF68 >> 1);
    if ( dword_52FF5C < 0 )
      dword_52FF5C = 0;
    if ( dword_52FF68 + dword_52FF5C >= mapWidth )
      dword_52FF5C = mapWidth - dword_52FF68;
    dword_52FF60 = a3 - (dword_52FF68 >> 1);
    if ( dword_52FF60 < 0 )
      dword_52FF60 = 0;
    if ( dword_52FF60 + dword_52FF68 >= mapHeight )
      dword_52FF60 = mapHeight - dword_52FF68;
  }
  dword_52FF4C = (480 - dword_52FF68 * dword_51923C) >> 1;
  dword_52FF50 = (480 - dword_52FF68 * dword_51923C) >> 1;
  MouseManager::loadMSE(mouseManager, "advmice.mse", 0, -999);
  sprintf(globBuf, "ground%d.icn", dword_51923C);
  dword_52FF48 = ResourceManager::getIconByFilename(resourceManager, globBuf);
  sprintf(globBuf, "vwflag%d.icn", dword_51923C);
  dword_52FF54 = ResourceManager::getIconByFilename(resourceManager, globBuf);
  sprintf(globBuf, "misc%d.icn", dword_51923C);
  dword_52FF58 = ResourceManager::getIconByFilename(resourceManager, globBuf);
  sprintf(globBuf, "letter%d.icn", dword_51923C);
  dword_52FF38 = ResourceManager::getIconByFilename(resourceManager, globBuf);
  sub_44AA80(v3, 1, 0);
}

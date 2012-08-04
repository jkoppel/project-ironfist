{
  BuildingDisplay *thisa; // [sp+Ch] [bp-30h]@1
  border *thisb; // [sp+10h] [bp-2Ch]@2
  char v7; // [sp+18h] [bp-24h]@1
  int y; // [sp+28h] [bp-14h]@1
  int x; // [sp+30h] [bp-Ch]@1
  int height; // [sp+34h] [bp-8h]@1
  int width; // [sp+38h] [bp-4h]@1

  thisa = this;
  this->animationIdx = 0;
  this->icon = 0;
  this->guiElement = 0;
  this->built = 1;
  this->animationLength = sBuildingInfo[faction][buildingCode].animationLength;
  x = sBuildingInfo[faction][buildingCode].x;
  y = sBuildingInfo[faction][buildingCode].y;
  width = sBuildingInfo[faction][buildingCode].width;
  height = sBuildingInfo[faction][buildingCode].height;
  this->buildingCode = buildingCode;
  sprintf(&v7, "%s.icn", filename);
  thisa->icon = resourceManager::GetIcon(gpResourceManager, &v7);
  if ( buildingCode != -1 )
  {
    thisb = (border *)operator new(42);
    if ( thisb )
      thisa->guiElement = border::border(thisb, x, y, width, height, buildingCode, 1, 0, 0);
    else
      thisa->guiElement = 0;
    if ( !thisa->guiElement )
      MemError();
  }
  return thisa;
}
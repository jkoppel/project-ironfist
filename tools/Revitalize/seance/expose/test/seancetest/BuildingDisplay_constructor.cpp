BuildingDisplay *__thiscall BuildingDisplay_constructor(BuildingDisplay *this, int faction, int buildingCode, char *filename)
{
  BuildingDisplay *thisa; // [sp+Ch] [bp-30h]@1
  BackgroundGUI *thisb; // [sp+10h] [bp-2Ch]@2
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
  this->animationLength = building_positions[faction][buildingCode].animationLength;
  x = building_positions[faction][buildingCode].x;
  y = building_positions[faction][buildingCode].y;
  width = building_positions[faction][buildingCode].width;
  height = building_positions[faction][buildingCode].height;
  this->buildingCode = buildingCode;
  sprintf(&v7, "%s.icn", filename);
  thisa->icon = ResourceManager::getIconByFilename(resourceManager, &v7);
  if ( buildingCode != -1 )
  {
    thisb = (BackgroundGUI *)operator new(0x2Au);
    if ( thisb )
      thisa->guiElement = BackgroundGUI_constructor(thisb, x, y, width, height, buildingCode, 1, 0, 0);
    else
      thisa->guiElement = 0;
    if ( !thisa->guiElement )
      fatalOutOfMemoryError();
  }
  return thisa;
}

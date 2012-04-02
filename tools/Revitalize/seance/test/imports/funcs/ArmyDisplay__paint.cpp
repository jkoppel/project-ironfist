{
  ArmyDisplay *thisa; // [sp+Ch] [bp-38h]@1
  int creatureType; // [sp+10h] [bp-34h]@25
  Icon *oldCreaturePortraits[5]; // [sp+14h] [bp-30h]@14
  int oldCreatureTypes[5]; // [sp+28h] [bp-1Ch]@14
  int i; // [sp+3Ch] [bp-8h]@5
  int upToDate; // [sp+40h] [bp-4h]@5

  thisa = this;
  Icon::drawToScreen(this->portraitIcon, this->x + 5, this->y + 6, this->portraitIconIdx, 0);
  if ( thisa->field_7C != -1 )
    Icon::drawToScreen(thisa->portraitFlagIcon, thisa->x + 5, thisa->y + 6, thisa->field_7C, 0);
  if ( thisa->army )
  {
    upToDate = 1;
    for ( i = 0; i < 5; ++i )
    {
      if ( thisa->army->creatureTypes[i] != -1 )
      {
        if ( thisa->army->creatureTypes[i] != thisa->creatureTypes[i] )
          upToDate = 0;
      }
    }
    if ( !upToDate )
    {
      for ( i = 0; i < 5; ++i )
      {
        oldCreaturePortraits[i] = thisa->creaturePortraits[i];
        oldCreatureTypes[i] = thisa->creatureTypes[i];
        if ( thisa->army->creatureTypes[i] == -1 )
        {
          thisa->creaturePortraits[i] = NULL;
          thisa->creatureTypes[i] = -1;
        }
        else
        {
          sprintf(globBuf, "monh%04d.icn", thisa->army->creatureTypes[i]);
          thisa->creaturePortraits[i] = ResourceManager::getIconByFilename(resourceManager, globBuf);
          thisa->creatureTypes[i] = thisa->army->creatureTypes[i];
        }
      }
      for ( i = 0; i < 5; ++i )
      {
        if ( oldCreatureTypes[i] )
          ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)oldCreaturePortraits[i]);
      }
    }
    for ( i = 0; i < 5; ++i )
    {
      creatureType = thisa->army->creatureTypes[i];
      if ( creatureType == -1 )
      {
        Icon::drawToScreen(thisa->stripIcon, thisa->x + 88 * i + 112, thisa->y + 6, 2, 0);
      }
      else
      {
        Icon::drawToScreen(
          thisa->stripIcon,
          thisa->x + 88 * i + 112,
          thisa->y + 6,
          creature_table[creatureType].faction + 4,
          0);
        Icon::drawToScreen(thisa->creaturePortraits[i], thisa->x + 88 * i + 112, thisa->y + 6, 0, 0);
        sprintf(globBuf, "%d", thisa->army->quantities[i]);
        Font::drawString(smallFont, globBuf, thisa->x + 88 * i + 112, thisa->y + 86, 77, 13, 1, 2);
      }
    }
    GUIWindow::repaint(thisa->window, updateScreen);
    if ( thisa->drawBorder != -1 )
      Icon::drawToScreen(thisa->stripIcon, thisa->x + 88 * thisa->drawBorder + 112, thisa->y + 6, 1, 0);
  }
  else
  {
    Icon::drawToScreen(thisa->stripIcon, thisa->x + 112, thisa->y + 6, 11, 0);
    GUIWindow::repaint(thisa->window, updateScreen);
  }
}

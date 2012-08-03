{
  strip *thisa; // [sp+Ch] [bp-38h]@1
  int creatureType; // [sp+10h] [bp-34h]@25
  icon *oldCreaturePortraits[5]; // [sp+14h] [bp-30h]@14
  int oldCreatureTypes[5]; // [sp+28h] [bp-1Ch]@14
  int i; // [sp+3Ch] [bp-8h]@5
  int upToDate; // [sp+40h] [bp-4h]@5

  thisa = this;
  icon::DrawToBuffer(this->portraitIcon, this->x + 5, this->y + 6, this->portraitIconIdx, 0);
  if ( thisa->field_7C != -1 )
    icon::DrawToBuffer(thisa->portraitFlagIcon, thisa->x + 5, thisa->y + 6, thisa->field_7C, 0);
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
          sprintf(gText, "monh%04d.icn", thisa->army->creatureTypes[i]);
          thisa->creaturePortraits[i] = resourceManager::GetIcon(gpResourceManager, gText);
          thisa->creatureTypes[i] = thisa->army->creatureTypes[i];
        }
      }
      for ( i = 0; i < 5; ++i )
      {
        if ( oldCreatureTypes[i] )
          resourceManager::Dispose(gpResourceManager, (resource *)oldCreaturePortraits[i]);
      }
    }
    for ( i = 0; i < 5; ++i )
    {
      creatureType = thisa->army->creatureTypes[i];
      if ( creatureType == -1 )
      {
        icon::DrawToBuffer(thisa->stripIcon, thisa->x + 88 * i + 112, thisa->y + 6, 2, 0);
      }
      else
      {
        icon::DrawToBuffer(
          thisa->stripIcon,
          thisa->x + 88 * i + 112,
          thisa->y + 6,
          gMonsterDatabase[creatureType].faction + 4,
          0);
        icon::DrawToBuffer(thisa->creaturePortraits[i], thisa->x + 88 * i + 112, thisa->y + 6, 0, 0);
        sprintf(gText, "%d", thisa->army->quantities[i]);
        font::DrawBoundedString(smallFont, gText, thisa->x + 88 * i + 112, thisa->y + 86, 77, 13, 1, 2);
      }
    }
    heroWindow::DrawWindow(thisa->window, updateScreen);
    if ( thisa->drawBorder != -1 )
      icon::DrawToBuffer(thisa->stripIcon, thisa->x + 88 * thisa->drawBorder + 112, thisa->y + 6, 1, 0);
  }
  else
  {
    icon::DrawToBuffer(thisa->stripIcon, thisa->x + 112, thisa->y + 6, 11, 0);
    heroWindow::DrawWindow(thisa->window, updateScreen);
  }
}
{
  MouseManager *thisa; // esi@1
  signed int category; // eax@2
  char firstLetter; // al@4
  int v7; // edi@13
  Icon *oldIcon; // eax@13
  MOUSE_CURSOR_CATEGORY v9; // eax@15
  int spriteIdxa; // ebx@20
  const char *v11; // [sp-4h] [bp-20h]@16
  char filename[1]; // [sp+Ch] [bp-10h]@20

  thisa = this;
  if ( !this->field_7E )
  {
    ++mouseSemaphore1;
    ResourceManager::pushCurrentFileAndOffsetOntoStack(resourceManager);
    category = protoCategory;
    if ( protoCategory == -999 )
    {
      if ( gameOrEditorIdx == 1 || (firstLetter = *mse, *mse == 'a') || firstLetter == 'A' )
      {
        category = MOUSE_CURSOR_CATEGORY_ADVENTURE;
      }
      else
      {
        if ( firstLetter == 's' || firstLetter == 'S' )
          category = MOUSE_CURSOR_CATEGORY_SPELL;
        else
          category = MOUSE_CURSOR_CATEGORY_COMBAT;
      }
    }
    if ( thisa->cursorCategory != category && (thisa->cursorCategory = category, dword_4F19B0) )
    {
      v7 = thisa->couldBeShowMouse;
      oldIcon = thisa->cursorIcon;
      thisa->couldBeShowMouse = 0;
      if ( oldIcon )
        ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)oldIcon);
      v9 = thisa->cursorCategory;
      if ( v9 )
      {
        if ( v9 == MOUSE_CURSOR_CATEGORY_SPELL )
          v11 = "SPELCO.ICN";
        else
          v11 = "CMSECO.ICN";
      }
      else
      {
        v11 = "ADVMCO.ICN";
      }
      sprintf(filename, v11);
      spriteIdxa = spriteIdx;
      thisa->cursorIcon = ResourceManager::getIconByFilename(resourceManager, filename);
      assertTrue(spriteIdx != 1000, "F:\\h2xsrc\\Base\\MOUSEMGR.CPP", 410);
      thisa->spriteIdx = -1;
      thisa->couldBeShowMouse = v7;
    }
    else
    {
      spriteIdxa = spriteIdx;
    }
    MouseManager::setSpriteIdx(thisa, spriteIdxa);
    ResourceManager::popFileAndOffsetOffStack(resourceManager);
    --mouseSemaphore1;
  }
}

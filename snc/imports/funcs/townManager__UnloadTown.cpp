{
  townManager *result; // eax@15
  townManager *thisa; // [sp+Ch] [bp-28h]@1
  BuildingDisplay *v3; // [sp+14h] [bp-20h]@12
  strip *v4; // [sp+1Ch] [bp-18h]@8
  strip *v5; // [sp+24h] [bp-10h]@5
  bankBox *thisb; // [sp+2Ch] [bp-8h]@2
  int i; // [sp+30h] [bp-4h]@10

  thisa = this;
  if ( this->bankbox )
  {
    thisb = this->bankbox;
    if ( thisb )
    {
      bankBox::_bankBox(thisb);
      operator delete(thisb);
    }
  }
  thisa->bankbox = 0;
  if ( thisa->visitingArmyDisplay )
  {
    v5 = thisa->visitingArmyDisplay;
    if ( v5 )
    {
      strip::_strip(v5);
      operator delete(v5);
    }
  }
  thisa->visitingArmyDisplay = 0;
  if ( thisa->garrisonDisplay )
  {
    v4 = thisa->garrisonDisplay;
    if ( v4 )
    {
      strip::_strip(v4);
      operator delete(v4);
    }
  }
  thisa->garrisonDisplay = 0;
  for ( i = 0; thisa->curBuilding > i; ++i )
  {
    heroWindow::RemoveWidget(thisa->townScreen, (widget *)thisa->buildingDisplays[i]->guiElement);
    v3 = thisa->buildingDisplays[i];
    if ( v3 )
    {
      townObject::_townObject(v3);
      operator delete(v3);
    }
    thisa->buildingDisplays[i] = 0;
  }
  result = thisa;
  if ( thisa->couldBeBackground )
  {
    resourceManager::Dispose(gpResourceManager, (resource *)thisa->couldBeBackground);
    result = thisa;
    thisa->couldBeBackground = 0;
  }
  return result;
}
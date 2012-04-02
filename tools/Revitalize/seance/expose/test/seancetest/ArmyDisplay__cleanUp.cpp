void __thiscall ArmyDisplay::cleanUp(ArmyDisplay *this)
{
  ArmyDisplay *thisa; // [sp+Ch] [bp-20h]@1
  AbstractGUIComponent *v2; // [sp+1Ch] [bp-10h]@7
  AbstractGUIComponent *v3; // [sp+24h] [bp-8h]@4
  signed int i; // [sp+28h] [bp-4h]@2
  signed int j; // [sp+28h] [bp-4h]@9

  thisa = this;
  HeroWindowManager::removeWindow(HeroWindowManager::instance, this->window);
  if ( thisa->army )
  {
    for ( i = 0; i < 5; ++i )
    {
      v3 = (AbstractGUIComponent *)thisa->field_2C[i];
      if ( v3 )
        v3->vtable->cleanUp(v3, 1);
    }
    v2 = (AbstractGUIComponent *)thisa->field_2C[5];
    if ( v2 )
      v2->vtable->cleanUp(v2, 1);
  }
  operator delete(thisa->window);
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)thisa->stripIcon);
  for ( j = 0; j < 5; ++j )
  {
    if ( thisa->creaturePortraits[j] )
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)thisa->creaturePortraits[j]);
  }
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)thisa->portraitIcon);
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)thisa->portraitFlagIcon);
}

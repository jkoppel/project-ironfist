void __thiscall CombatManager::releaseStaticObjectIcons(CombatManager *this)
{
  CombatManager *v1; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1
  signed int j; // [sp+10h] [bp-4h]@6
  signed int k; // [sp+10h] [bp-4h]@11

  v1 = this;
  for ( i = 0; i < 15; ++i )
  {
    if ( v1->combatScreenIcons[i] )
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v1->combatScreenIcons[i]);
  }
  for ( j = 0; j < 8; ++j )
  {
    if ( v1->combatObjIcons[j] )
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v1->combatObjIcons[j]);
  }
  for ( k = 0; k < 2; ++k )
  {
    if ( v1->heroIcon[k] )
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v1->heroIcon[k]);
    if ( v1->heroFlagIcon[k] )
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v1->heroFlagIcon[k]);
  }
}

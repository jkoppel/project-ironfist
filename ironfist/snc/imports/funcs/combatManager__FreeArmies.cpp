{
  int v1; // [sp+0h] [bp-14h]@0
  combatManager *thisa; // [sp+Ch] [bp-8h]@1
  int i; // [sp+10h] [bp-4h]@1
  int j; // [sp+10h] [bp-4h]@4

  thisa = this;
  soundManager::StopAllSamples(gpSoundManager, 1, v1);
  for ( i = 0; thisa->numCreatures[0] > i; ++i )
    army::FreeResources((army *)thisa->creatures + i);
  for ( j = 0; thisa->numCreatures[1] > j; ++j )
    army::FreeResources(&thisa->creatures[1][j]);
  if ( gCurLoadedSpellIcon )
    resourceManager::Dispose(gpResourceManager, (resource *)gCurLoadedSpellIcon);
  gCurLoadedSpellIcon = 0;
  gCurLoadedSpellEffect = -1;
}
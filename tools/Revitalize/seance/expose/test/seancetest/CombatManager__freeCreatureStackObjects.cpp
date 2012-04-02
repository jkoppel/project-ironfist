void __thiscall CombatManager::freeCreatureStackObjects(CombatManager *this)
{
  int v1; // [sp+0h] [bp-14h]@0
  CombatManager *thisa; // [sp+Ch] [bp-8h]@1
  int i; // [sp+10h] [bp-4h]@1
  int j; // [sp+10h] [bp-4h]@4

  thisa = this;
  sub_4035A0(soundManager, 1, v1);
  for ( i = 0; thisa->numCreatures[0] > i; ++i )
    CreatureStack::cleanUp((CreatureStack *)thisa->creatures + i);
  for ( j = 0; thisa->numCreatures[1] > j; ++j )
    CreatureStack::cleanUp(&thisa->creatures[1][j]);
  if ( nextCreatureEffectAnimation )
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)nextCreatureEffectAnimation);
  nextCreatureEffectAnimation = 0;
  nextCreatureEffectAnimationIdx = -1;
}

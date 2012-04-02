{
  CreatureStack *result; // eax@4
  CreatureStack *v2; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@6

  v2 = this;
  if ( !combatGraphicsOff )
  {
    if ( this->missileIcon )
    {
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)this->missileIcon);
      v2->missileIcon = 0;
    }
    result = v2;
    if ( v2->creatureIcon )
    {
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v2->creatureIcon);
      result = v2;
      v2->creatureIcon = 0;
    }
    for ( i = 0; i < 7; ++i )
    {
      result = (CreatureStack *)i;
      if ( v2->combatSounds[i] )
      {
        ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v2->combatSounds[i]);
        result = (CreatureStack *)i;
        v2->combatSounds[i] = 0;
      }
    }
  }
  return result;
}

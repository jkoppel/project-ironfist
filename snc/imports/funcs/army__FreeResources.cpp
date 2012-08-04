{
  army *result; // eax@4
  army *v2; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@6

  v2 = this;
  if ( !gbNoShowCombat )
  {
    if ( this->missileIcon )
    {
      resourceManager::Dispose(gpResourceManager, (resource *)this->missileIcon);
      v2->missileIcon = 0;
    }
    result = v2;
    if ( v2->creatureIcon )
    {
      resourceManager::Dispose(gpResourceManager, (resource *)v2->creatureIcon);
      result = v2;
      v2->creatureIcon = 0;
    }
    for ( i = 0; i < 7; ++i )
    {
      result = (army *)i;
      if ( v2->combatSounds[i] )
      {
        resourceManager::Dispose(gpResourceManager, (resource *)v2->combatSounds[i]);
        result = (army *)i;
        v2->combatSounds[i] = 0;
      }
    }
  }
  return result;
}
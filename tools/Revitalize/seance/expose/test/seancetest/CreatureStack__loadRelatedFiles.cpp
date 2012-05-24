void __thiscall CreatureStack::loadRelatedFiles(CreatureStack *this)
{
  int formFileID; // eax@2
  CreatureStack *thisa; // [sp+Ch] [bp-28h]@1
  signed int i; // [sp+30h] [bp-4h]@34

  thisa = this;
  if ( !combatGraphicsOff )
  {
    formFileID = ResourceManager::setResource(resourceManager, creature_form_table[this->creatureIdx], 1);
    ResourceManager::pointToFile(resourceManager, formFileID);
    ResourceManager::readFromCurrentFile(resourceManager, &thisa->form, 821u);
    CreatureForm::adjustSpeeds(&thisa->form, thisa->creatureIdx);
    thisa->field_B2 = thisa->form.stepTime;
    sprintf(globBuf, "%smove.82M", thisa->creature.short_name);
    thisa->combatSounds[0] = ResourceManager::getSampleByFilename(resourceManager, globBuf);
    sprintf(globBuf, "%sattk.82M", thisa->creature.short_name);
    thisa->combatSounds[1] = ResourceManager::getSampleByFilename(resourceManager, globBuf);
    sprintf(globBuf, "%swnce.82M", thisa->creature.short_name);
    thisa->combatSounds[2] = ResourceManager::getSampleByFilename(resourceManager, globBuf);
    sprintf(globBuf, "%skill.82M", thisa->creature.short_name);
    thisa->combatSounds[4] = ResourceManager::getSampleByFilename(resourceManager, globBuf);
    if ( thisa->creature.creature_flags & SHOOTER )
    {
      sprintf(globBuf, "%sshot.82M", thisa->creature.short_name);
      thisa->combatSounds[3] = ResourceManager::getSampleByFilename(resourceManager, globBuf);
    }
    if ( thisa->creatureIdx == CREATURE_VAMPIRE || thisa->creatureIdx == CREATURE_VAMPIRE_LORD )
    {
      sprintf(globBuf, "%sext1.82M", thisa->creature.short_name);
      thisa->combatSounds[5] = ResourceManager::getSampleByFilename(resourceManager, globBuf);
      sprintf(globBuf, "%sext2.82M", thisa->creature.short_name);
      thisa->combatSounds[6] = ResourceManager::getSampleByFilename(resourceManager, globBuf);
    }
    if ( thisa->creatureIdx == CREATURE_LICH || thisa->creatureIdx == CREATURE_POWER_LICH )
    {
      sprintf(globBuf, "%sexpl.82M", thisa->creature.short_name);
      thisa->combatSounds[5] = ResourceManager::getSampleByFilename(resourceManager, globBuf);
    }
    thisa->creatureIcon = ResourceManager::getIconByFilename(resourceManager, creatureIconNames[thisa->creatureIdx]);
    if ( thisa->creature.creature_flags & SHOOTER )
    {
      if ( thisa->creatureIdx != CREATURE_GIANT && thisa->creatureIdx != CREATURE_TITAN )
      {
        if ( thisa->creatureIdx == CREATURE_HALFLING )
        {
          sprintf(globBuf, "halflmsl.icn");
        }
        else
        {
          if ( thisa->creatureIdx != CREATURE_ARCHER && thisa->creatureIdx != CREATURE_RANGER )
          {
            if ( thisa->creatureIdx != CREATURE_LICH && thisa->creatureIdx != CREATURE_POWER_LICH )
            {
              if ( thisa->creatureIdx != CREATURE_ORC && thisa->creatureIdx != CREATURE_ORC_CHIEF )
              {
                if ( thisa->creatureIdx != CREATURE_DRUID && thisa->creatureIdx != CREATURE_GREATER_DRUID )
                {
                  if ( thisa->creatureIdx != CREATURE_TROLL && thisa->creatureIdx != CREATURE_WAR_TROLL )
                    sprintf(globBuf, "elf__msl.icn");
                  else
                    sprintf(globBuf, "trollmsl.icn");
                }
                else
                {
                  sprintf(globBuf, "druidmsl.icn");
                }
              }
              else
              {
                sprintf(globBuf, "orc__msl.icn");
              }
            }
            else
            {
              sprintf(globBuf, "lich_msl.icn");
            }
          }
          else
          {
            sprintf(globBuf, "arch_msl.icn");
          }
        }
      }
      else
      {
        sprintf(globBuf, "titanmsl.icn");
      }
      thisa->missileIcon = ResourceManager::getIconByFilename(resourceManager, globBuf);
    }
    else
    {
      thisa->combatSounds[3] = 0;
      thisa->missileIcon = 0;
    }
    for ( i = 0; i < 5; ++i )
    {
      if ( thisa->combatSounds[i] )
      {
        thisa->combatSounds[i]->field_28 = 64;
        thisa->combatSounds[i]->codeThing = 3;
        thisa->combatSounds[i]->loopCount = 1;
      }
    }
  }
}

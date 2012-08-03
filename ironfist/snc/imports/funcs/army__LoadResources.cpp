{
  int formFileID; // eax@2
  army *thisa; // [sp+Ch] [bp-28h]@1
  signed int i; // [sp+30h] [bp-4h]@34

  thisa = this;
  if ( !gbNoShowCombat )
  {
    formFileID = resourceManager::MakeId(gpResourceManager, cArmyFrameFileNames[this->creatureIdx], 1);
    resourceManager::PointToFile(gpResourceManager, formFileID);
    resourceManager::ReadBlock(gpResourceManager, thisa->gap_129, 821u);
    ModifyFrameInfo((SMonFrameInfo *)thisa->gap_129, thisa->creatureIdx);
    thisa->field_B2 = *(_DWORD *)&thisa->gap_129[162];
    sprintf(gText, "%smove.82M", thisa->creature.short_name);
    thisa->combatSounds[0] = resourceManager::GetSample(gpResourceManager, gText);
    sprintf(gText, "%sattk.82M", thisa->creature.short_name);
    thisa->combatSounds[1] = resourceManager::GetSample(gpResourceManager, gText);
    sprintf(gText, "%swnce.82M", thisa->creature.short_name);
    thisa->combatSounds[2] = resourceManager::GetSample(gpResourceManager, gText);
    sprintf(gText, "%skill.82M", thisa->creature.short_name);
    thisa->combatSounds[4] = resourceManager::GetSample(gpResourceManager, gText);
    if ( thisa->creature.creature_flags & SHOOTER )
    {
      sprintf(gText, "%sshot.82M", thisa->creature.short_name);
      thisa->combatSounds[3] = resourceManager::GetSample(gpResourceManager, gText);
    }
    if ( thisa->creatureIdx == CREATURE_VAMPIRE || thisa->creatureIdx == CREATURE_VAMPIRE_LORD )
    {
      sprintf(gText, "%sext1.82M", thisa->creature.short_name);
      thisa->combatSounds[5] = resourceManager::GetSample(gpResourceManager, gText);
      sprintf(gText, "%sext2.82M", thisa->creature.short_name);
      thisa->combatSounds[6] = resourceManager::GetSample(gpResourceManager, gText);
    }
    if ( thisa->creatureIdx == CREATURE_LICH || thisa->creatureIdx == CREATURE_POWER_LICH )
    {
      sprintf(gText, "%sexpl.82M", thisa->creature.short_name);
      thisa->combatSounds[5] = resourceManager::GetSample(gpResourceManager, gText);
    }
    thisa->creatureIcon = resourceManager::GetIcon(gpResourceManager, cMonFilename[thisa->creatureIdx]);
    if ( thisa->creature.creature_flags & SHOOTER )
    {
      if ( thisa->creatureIdx != CREATURE_GIANT && thisa->creatureIdx != CREATURE_TITAN )
      {
        if ( thisa->creatureIdx == CREATURE_HALFLING )
        {
          sprintf(gText, "halflmsl.icn");
        }
        else if ( thisa->creatureIdx != CREATURE_ARCHER && thisa->creatureIdx != CREATURE_RANGER )
        {
          if ( thisa->creatureIdx != CREATURE_LICH && thisa->creatureIdx != CREATURE_POWER_LICH )
          {
            if ( thisa->creatureIdx != CREATURE_ORC && thisa->creatureIdx != CREATURE_ORC_CHIEF )
            {
              if ( thisa->creatureIdx != CREATURE_DRUID && thisa->creatureIdx != CREATURE_GREATER_DRUID )
              {
                if ( thisa->creatureIdx != CREATURE_TROLL && thisa->creatureIdx != CREATURE_WAR_TROLL )
                  sprintf(gText, "elf__msl.icn");
                else
                  sprintf(gText, "trollmsl.icn");
              }
              else
              {
                sprintf(gText, "druidmsl.icn");
              }
            }
            else
            {
              sprintf(gText, "orc__msl.icn");
            }
          }
          else
          {
            sprintf(gText, "lich_msl.icn");
          }
        }
        else
        {
          sprintf(gText, "arch_msl.icn");
        }
      }
      else
      {
        sprintf(gText, "titanmsl.icn");
      }
      thisa->missileIcon = resourceManager::GetIcon(gpResourceManager, gText);
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
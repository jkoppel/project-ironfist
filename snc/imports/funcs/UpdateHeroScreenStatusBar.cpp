{
  town *v1; // eax@4
  town *v2; // eax@6
  town *v3; // eax@10
  town *v4; // eax@12
  char *v5; // ST0C_4@59
  signed int v6; // eax@59
  signed int v7; // [sp+Ch] [bp-10h]@1
  int a2; // [sp+14h] [bp-8h]@51
  int v9; // [sp+18h] [bp-4h]@20

  v7 = *(_DWORD *)&this->_2[4];
  if ( v7 > 84 )
  {
    if ( v7 > 106 )
    {
      if ( v7 > 205 )
      {
        if ( v7 > 212 )
        {
          if ( v7 > 30720 )
          {
            if ( v7 != 30723 )
              goto LABEL_49;
            sprintf(gText, off_4F63B8, gpHVHero->name, (&gAlignmentNames)[4 * gpHVHero->factionID]);
          }
          else if ( v7 == 30720 )
          {
            strcpy(gText, off_4F63BC);
          }
          else if ( v7 == 214 )
          {
            sprintf(gText, off_4F63D4);
          }
          else
          {
            if ( v7 != 216 )
              goto LABEL_49;
            sprintf(gText, off_4F63D8);
          }
          goto LABEL_87;
        }
        if ( v7 >= 211 )
        {
          sprintf(gText, off_4F63D0);
          goto LABEL_87;
        }
        if ( v7 >= 206 && v7 <= 207 )
        {
          sprintf(gText, off_4F639C);
          goto LABEL_87;
        }
      }
      else
      {
        if ( v7 >= 203 )
        {
          v3 = hero::GetOccupiedTown(gpHVHero);
          if ( game::GetLuck(gpHVHero, 0, v3) <= 0 )
          {
            v4 = hero::GetOccupiedTown(gpHVHero);
            if ( game::GetLuck(gpHVHero, 0, v4) )
              sprintf(gText, off_4F6398);
            else
              sprintf(gText, off_4F6394);
          }
          else
          {
            sprintf(gText, off_4F6390);
          }
          goto LABEL_87;
        }
        if ( v7 >= 200 && v7 <= 202 )
        {
          v1 = hero::GetOccupiedTown(gpHVHero);
          if ( armyGroup::GetMorale(&gpHVHero->army, gpHVHero, v1, 0) <= 0 )
          {
            v2 = hero::GetOccupiedTown(gpHVHero);
            if ( armyGroup::GetMorale(&gpHVHero->army, gpHVHero, v2, 0) )
              sprintf(gText, off_4F638C);
            else
              sprintf(gText, off_4F6388);
          }
          else
          {
            sprintf(gText, off_4F6384);
          }
          goto LABEL_87;
        }
      }
LABEL_49:
      if ( *(_DWORD *)&this->_2[4] < 400 || *(_DWORD *)&this->_2[4] >= 408 )
      {
        if ( *(_DWORD *)&this->_2[4] < 408 || *(_DWORD *)&this->_2[4] >= 416 )
        {
          if ( *(_DWORD *)&this->_2[4] < 416 || *(_DWORD *)&this->_2[4] >= 424 )
            goto LABEL_60;
          a2 = *(_DWORD *)&this->_2[4] - 416;
        }
        else
        {
          a2 = *(_DWORD *)&this->_2[4] - 408;
        }
      }
      else
      {
        a2 = *(_DWORD *)&this->_2[4] - 400;
      }
      if ( gpHVHero->numSecSkillsKnown > a2 )
      {
        v5 = gSecondarySkills[hero::GetNthSS(gpHVHero, a2)];
        v6 = hero::GetNthSS(gpHVHero, a2);
        sprintf(gText, off_4F63CC, secondarySkillLevels[gpHVHero->secondarySkillLevel[v6]], v5);
        goto LABEL_87;
      }
LABEL_60:
      strcpy(gText, off_4F63C0);
      goto LABEL_87;
    }
    if ( v7 >= 102 )
    {
      v9 = *(_DWORD *)&this->_2[4] - 102;
      if ( giHeroScreenSrcIndex == -1 )
      {
        if ( gpHVHero->army.creatureTypes[v9] == -1 )
          strcpy(gText, off_4F63A4);
        else
          sprintf(gText, off_4F63A0, gArmyNames[gpHVHero->army.creatureTypes[v9]]);
      }
      else if ( giHeroScreenSrcIndex == v9 )
      {
        sprintf(gText, off_4F63A0, gArmyNames[gpHVHero->army.creatureTypes[v9]]);
      }
      else if ( gpTownManager->field_15A )
      {
        if ( gpHVHero->army.creatureTypes[v9] == -1 )
          strcpy(gText, off_4F63A4);
        else
          sprintf(gText, off_4F63A0, gArmyNames[gpHVHero->army.creatureTypes[v9]]);
      }
      else if ( gpHVHero->army.creatureTypes[v9] == -1 )
      {
        if ( this->name[2] & 3 )
          sprintf(gText, off_4F63C8, gArmyNamesPlural[gpHVHero->army.creatureTypes[giHeroScreenSrcIndex]]);
        else
          sprintf(gText, off_4F63A8, gArmyNames[gpHVHero->army.creatureTypes[giHeroScreenSrcIndex]]);
      }
      else if ( gpHVHero->army.creatureTypes[v9] == gpHVHero->army.creatureTypes[giHeroScreenSrcIndex] )
      {
        sprintf(gText, off_4F63C4, gArmyNamesPlural[gpHVHero->army.creatureTypes[v9]]);
      }
      else
      {
        sprintf(
          gText,
          off_4F63AC,
          gArmyNames[gpHVHero->army.creatureTypes[giHeroScreenSrcIndex]],
          gArmyNames[gpHVHero->army.creatureTypes[v9]]);
      }
    }
    else
    {
      if ( v7 != 85 )
        goto LABEL_49;
      sprintf(gText, off_4F6380);
    }
  }
  else if ( v7 >= 81 )
  {
    sprintf(gText, off_4F637C, off_4F5994[*(_DWORD *)&this->_2[4]]);
  }
  else
  {
    if ( v7 < 20 || v7 > 33 )
      goto LABEL_49;
    if ( gpHVHero->spellsLearned[*(_DWORD *)&this->_2[4] + 45] == -1 )
    {
      sprintf(gText, off_4F63A4);
    }
    else if ( gpHVHero->spellsLearned[*(_DWORD *)&this->_2[4] + 45] == 81 )
    {
      strcpy(gText, off_4F63B0);
    }
    else
    {
      sprintf(gText, off_4F63B4, gArtifactNames[gpHVHero->spellsLearned[*(_DWORD *)&this->_2[4] + 45]]);
    }
  }
LABEL_87:
  HeroMessageUpdate(gText);
}
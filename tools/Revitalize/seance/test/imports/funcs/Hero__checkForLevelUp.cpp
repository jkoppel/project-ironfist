{
  Hero *thisa; // [sp+Ch] [bp-118h]@1
  int nextSkill; // [sp+18h] [bp-10Ch]@28
  signed int tries; // [sp+1Ch] [bp-108h]@28
  signed int randNum; // [sp+20h] [bp-104h]@7
  int randNuma; // [sp+20h] [bp-104h]@9
  int v6; // [sp+24h] [bp-100h]@28
  char v7; // [sp+28h] [bp-FCh]@4
  int secSkillOptions[2]; // [sp+F0h] [bp-34h]@22
  bool lvl10Plus; // [sp+F8h] [bp-2Ch]@5
  int j; // [sp+FCh] [bp-28h]@14
  int newLevel; // [sp+100h] [bp-24h]@1
  int levelsGained; // [sp+104h] [bp-20h]@2
  int i; // [sp+108h] [bp-1Ch]@2
  sample_resource res; // [sp+10Ch] [bp-18h]@2
  int skillsLearned[4]; // [sp+114h] [bp-10h]@4

  thisa = this;
  newLevel = levelForXP(this->experience);
  if ( thisa->oldLevel != newLevel )
  {
    res = stru_5230F8;
    levelsGained = newLevel - thisa->oldLevel;
    for ( i = thisa->oldLevel + 1; i <= newLevel; ++i )
    {
      sprintf(globBuf, off_4F65E0, thisa->name);
      sprintf(&v7, off_4F65E4);
      strcat(globBuf, &v7);
      skillsLearned[0] = 0;
      skillsLearned[1] = 0;
      skillsLearned[2] = 0;
      skillsLearned[3] = 0;
      lvl10Plus = i > 9;
      setRandomSeed(30 * i + thisa->_5[32]);
      randNum = nextRandomInt(1, 100);
      if ( hero_prim_skill_probs[thisa->factionID].chancesForBeforeOrAfterLvl10[lvl10Plus].attackChance <= randNum )
      {
        randNuma = randNum
                 - hero_prim_skill_probs[thisa->factionID].chancesForBeforeOrAfterLvl10[lvl10Plus].attackChance;
        if ( *(&byte_4F2E41[8 * thisa->factionID] + 4 * lvl10Plus) <= randNuma )
        {
          if ( *(&byte_4F2E42[8 * thisa->factionID] + 4 * lvl10Plus) <= randNuma
                                                                      - *(&byte_4F2E41[8 * thisa->factionID]
                                                                        + 4 * lvl10Plus) )
            ++skillsLearned[3];
          else
            ++skillsLearned[2];
        }
        else
        {
          ++skillsLearned[1];
        }
      }
      else
      {
        ++skillsLearned[0];
      }
      for ( j = 0; j < 4; ++j )
      {
        if ( skillsLearned[j] > 0 )
        {
          thisa->primarySkills[j] += LOBYTE(skillsLearned[j]);
          sprintf(&v7, "\n%s +%d", primarySkillNames[j], skillsLearned[j]);
          strcat(globBuf, &v7);
        }
      }
      for ( j = 0; j < 2; ++j )
      {
        secSkillOptions[j] = -1;
        if ( j
          || thisa->factionID == 1
          || !thisa->factionID
          || thisa->secondarySkillLevel[7] >= 3
          || i - thisa->wisdomLastOffered < 3 )
        {
          tries = 0;
          v6 = unseededNextRand(0, 200);
          nextSkill = 0;
          while ( tries < 5000 )
          {
            ++tries;
            if ( (!j || secSkillOptions[0] != nextSkill)
              && (thisa->secondarySkillLevel[nextSkill] && thisa->secondarySkillLevel[nextSkill] < 3
               || !thisa->secondarySkillLevel[nextSkill] && thisa->numSecSkillsKnown < 8) )
            {
              v6 -= sec_skill_chances[nextSkill].skill_chances[thisa->factionID];
              if ( v6 <= 0 )
              {
                secSkillOptions[j] = nextSkill;
                break;
              }
            }
            nextSkill = (nextSkill + 1) % 14;
          }
        }
        else
        {
          secSkillOptions[j] = SECONDARY_SKILL_WISDOM;
        }
      }
      if ( secSkillOptions[0] == SECONDARY_SKILL_WISDOM || secSkillOptions[1] == SECONDARY_SKILL_WISDOM )
        thisa->wisdomLastOffered = i;
      if ( dword_523F1C || thisa->probablyOwnerIdx < 0 || !*(&byte_524758 + thisa->probablyOwnerIdx) )
      {
        if ( secSkillOptions[0] != -1 )
        {
          if ( secSkillOptions[1] == -1 )
          {
            Hero::learnSecondarySkill(thisa, secSkillOptions[0], 1);
          }
          else
          {
            if ( dword_4F1F40[3 * secSkillOptions[1]] >= dword_4F1F40[3 * secSkillOptions[0]] )
              Hero::learnSecondarySkill(thisa, secSkillOptions[1], 1);
            else
              Hero::learnSecondarySkill(thisa, secSkillOptions[0], 1);
          }
        }
      }
      else
      {
        res = playSample("nwherolv.82m");
        if ( secSkillOptions[0] == -1 )
        {
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
        else
        {
          if ( secSkillOptions[1] == -1 )
          {
            sprintf(
              &v7,
              "\n\nYou have learned %s %s.",
              secondarySkillLevels[thisa->secondarySkillLevel[secSkillOptions[0]] + 1],
              secondary_skill_names[secSkillOptions[0]]);
            strcat(globBuf, &v7);
            display_message_window(
              globBuf,
              1,
              -1,
              -1,
              17,
              3 * secSkillOptions[0] + thisa->secondarySkillLevel[secSkillOptions[0]],
              -1,
              0,
              -1,
              0);
            Hero::learnSecondarySkill(thisa, secSkillOptions[0], 1);
          }
          else
          {
            sprintf(
              &v7,
              "\n\nYou may learn either %s %s or %s %s.",
              secondarySkillLevels[thisa->secondarySkillLevel[secSkillOptions[0]] + 1],
              secondary_skill_names[secSkillOptions[0]],
              secondarySkillLevels[thisa->secondarySkillLevel[secSkillOptions[1]] + 1],
              secondary_skill_names[secSkillOptions[1]]);
            strcat(globBuf, &v7);
            display_message_window(
              globBuf,
              7,
              -1,
              -1,
              17,
              3 * secSkillOptions[0] + thisa->secondarySkillLevel[secSkillOptions[0]],
              17,
              3 * secSkillOptions[1] + thisa->secondarySkillLevel[secSkillOptions[1]],
              -1,
              0);
            if ( HeroWindowManager::instance->buttonPressedCode == 30727 )
              Hero::learnSecondarySkill(thisa, secSkillOptions[0], 1);
            else
              Hero::learnSecondarySkill(thisa, secSkillOptions[1], 1);
          }
        }
      }
    }
    thisa->oldLevel = newLevel;
    waitForSampleToFinish(-1, res);
  }
}

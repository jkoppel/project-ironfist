{
  hero *thisa; // [sp+Ch] [bp-118h]@1
  int nextSkill; // [sp+18h] [bp-10Ch]@25
  signed int tries; // [sp+1Ch] [bp-108h]@25
  signed int randNum; // [sp+20h] [bp-104h]@4
  int randNuma; // [sp+20h] [bp-104h]@6
  int v6; // [sp+24h] [bp-100h]@25
  char v7; // [sp+28h] [bp-FCh]@4
  int secSkillOptions[2]; // [sp+F0h] [bp-34h]@19
  bool lvl10Plus; // [sp+F8h] [bp-2Ch]@4
  int j; // [sp+FCh] [bp-28h]@11
  int newLevel; // [sp+100h] [bp-24h]@1
  int levelsGained; // [sp+104h] [bp-20h]@2
  int i; // [sp+108h] [bp-1Ch]@2
  sample_resource res; // [sp+10Ch] [bp-18h]@2
  int skillsLearned[4]; // [sp+114h] [bp-10h]@4

  thisa = this;
  newLevel = hero::GetLevel(this->experience);
  if ( thisa->oldLevel != newLevel )
  {
    res = NULL_SAMPLE2;
    levelsGained = newLevel - thisa->oldLevel;
    for ( i = thisa->oldLevel + 1; i <= newLevel; ++i )
    {
      sprintf(gText, cHeroLevel, thisa->name);
      sprintf(&v7, off_4F65E4);
      strcat(gText, &v7);
      skillsLearned[0] = 0;
      skillsLearned[1] = 0;
      skillsLearned[2] = 0;
      skillsLearned[3] = 0;
      lvl10Plus = i > 9;
      SRand(30 * i + thisa->_5[32]);
      randNum = SRandom(1, 100);
      if ( gHeroSkillBonus[thisa->factionID].chancesForBeforeOrAfterLvl10[lvl10Plus].attackChance <= randNum )
      {
        randNuma = randNum - gHeroSkillBonus[thisa->factionID].chancesForBeforeOrAfterLvl10[lvl10Plus].attackChance;
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
          sprintf(&v7, "\n%s +%d", gStatNames[j], skillsLearned[j]);
          strcat(gText, &v7);
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
          v6 = Random(0, 200);
          nextSkill = 0;
          while ( tries < 5000 )
          {
            ++tries;
            if ( (!j || secSkillOptions[0] != nextSkill)
              && (thisa->secondarySkillLevel[nextSkill] && thisa->secondarySkillLevel[nextSkill] < 3
               || !thisa->secondarySkillLevel[nextSkill] && thisa->numSecSkillsKnown < 8) )
            {
              v6 -= iGetSSByAlignment[nextSkill].skill_chances[thisa->factionID];
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
      if ( gbInNewGameSetup || thisa->probablyOwnerIdx < 0 || !*(&gbThisNetHumanPlayer + thisa->probablyOwnerIdx) )
      {
        if ( secSkillOptions[0] != -1 )
        {
          if ( secSkillOptions[1] == -1 )
          {
            hero::GiveSS(thisa, secSkillOptions[0], 1);
          }
          else if ( gSSValues[3 * secSkillOptions[1]] >= gSSValues[3 * secSkillOptions[0]] )
          {
            hero::GiveSS(thisa, secSkillOptions[1], 1);
          }
          else
          {
            hero::GiveSS(thisa, secSkillOptions[0], 1);
          }
        }
      }
      else
      {
        res = LoadPlaySample("nwherolv.82m");
        if ( secSkillOptions[0] == -1 )
        {
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
        else if ( secSkillOptions[1] == -1 )
        {
          sprintf(
            &v7,
            "\n\nYou have learned %s %s.",
            secondarySkillLevels[thisa->secondarySkillLevel[secSkillOptions[0]] + 1],
            gSecondarySkills[secSkillOptions[0]]);
          strcat(gText, &v7);
          NormalDialog(
            gText,
            1,
            -1,
            -1,
            17,
            3 * secSkillOptions[0] + thisa->secondarySkillLevel[secSkillOptions[0]],
            -1,
            0,
            -1,
            0);
          hero::GiveSS(thisa, secSkillOptions[0], 1);
        }
        else
        {
          sprintf(
            &v7,
            "\n\nYou may learn either %s %s or %s %s.",
            secondarySkillLevels[thisa->secondarySkillLevel[secSkillOptions[0]] + 1],
            gSecondarySkills[secSkillOptions[0]],
            secondarySkillLevels[thisa->secondarySkillLevel[secSkillOptions[1]] + 1],
            gSecondarySkills[secSkillOptions[1]]);
          strcat(gText, &v7);
          NormalDialog(
            gText,
            7,
            -1,
            -1,
            17,
            3 * secSkillOptions[0] + thisa->secondarySkillLevel[secSkillOptions[0]],
            17,
            3 * secSkillOptions[1] + thisa->secondarySkillLevel[secSkillOptions[1]],
            -1,
            0);
          if ( gpWindowManager->buttonPressedCode == 30727 )
            hero::GiveSS(thisa, secSkillOptions[0], 1);
          else
            hero::GiveSS(thisa, secSkillOptions[1], 1);
        }
      }
    }
    thisa->oldLevel = newLevel;
    WaitEndSample(-1, res);
  }
}
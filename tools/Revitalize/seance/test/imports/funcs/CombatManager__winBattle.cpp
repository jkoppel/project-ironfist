{
  int result; // eax@113
  CombatManager *thisa; // [sp+18h] [bp-F8h]@1
  GUIWindow *v4; // [sp+24h] [bp-ECh]@76
  char v5; // [sp+28h] [bp-E8h]@90
  int numArtifactsToSteal; // [sp+C0h] [bp-50h]@53
  int evt; // [sp+C4h] [bp-4Ch]@98
  int v8; // [sp+C8h] [bp-48h]@98
  int v9; // [sp+CCh] [bp-44h]@98
  char *v10; // [sp+DCh] [bp-34h]@98
  int i; // [sp+E0h] [bp-30h]@4
  int v12; // [sp+E8h] [bp-28h]@4
  int tick; // [sp+ECh] [bp-24h]@39
  int k; // [sp+F0h] [bp-20h]@39
  int v15; // [sp+F4h] [bp-1Ch]@1
  int v16; // [sp+F8h] [bp-18h]@6
  int v17; // [sp+FCh] [bp-14h]@6
  int j; // [sp+100h] [bp-10h]@6
  int creaturesKilled; // [sp+104h] [bp-Ch]@4
  CreatureStack *stack; // [sp+108h] [bp-8h]@8
  int v21; // [sp+10Ch] [bp-4h]@37

  thisa = this;
  v15 = 0;
  if ( this->heroes[1] && this->heroes[1]->field_E7[0] )
    this->heroes[1] = 0;
  dword_524C90 = 0;
  dword_524C70 = 1;
  dword_524C88 = 0;
  *(_DWORD *)&skeletonsToRaise = 0;
  numStolenArtifacts = 0;
  dword_524C8C = -1;
  dword_524C6C = 0;
  creaturesKilled = 0;
  v12 = 0;
  for ( i = 0; i < 2; ++i )
  {
    v16 = 0;
    v17 = -1;
    for ( j = 0; combatManager->numCreatures[i] > j; ++j )
    {
      stack = &this->creatures[i][j];
      if ( this->creatures[i][j].quantity > 0 )
      {
        v17 = j;
        if ( stack->anAmountToLose > 0 )
          stack->quantity -= stack->anAmountToLose;
        if ( stack->quantity < 0 )
          stack->quantity = 0;
        v16 += stack->quantity;
      }
      if ( i == side
        && stack->quantity > 0
        && !(HIBYTE(stack->creature.creature_flags) & ATTR_MIRROR_IMAGE)
        && stack->creatureIdx != CREATURE_EARTH_ELEMENTAL
        && stack->creatureIdx != CREATURE_AIR_ELEMENTAL
        && stack->creatureIdx != CREATURE_FIRE_ELEMENTAL
        && stack->creatureIdx != CREATURE_WATER_ELEMENTAL
        && stack->creatureIdx != CREATURE_SKELETON )
        ++v12;
      if ( 1 - i == side )
        creaturesKilled += stack->initialQuantity - stack->quantity;
    }
    if ( !v16 && v17 != -1 )
      this->creatures[i][v17].quantity = 1;
  }
  if ( side != -1 )
  {
    if ( v12 < 5 )
    {
      if ( this->heroes[side] )
      {
        if ( Hero::getSecondarySkillLevelWithBonii(this->heroes[side], SECONDARY_SKILL_NECROMANCY) )
        {
          *(_DWORD *)&skeletonsToRaise = (signed __int64)((double)Hero::getSecondarySkillLevelWithBonii(
                                                                    thisa->heroes[side],
                                                                    SECONDARY_SKILL_NECROMANCY)
                                                        * 0.1
                                                        * (double)creaturesKilled);
          if ( *(_DWORD *)&skeletonsToRaise <= 0 )
          {
            if ( creaturesKilled )
              *(_DWORD *)&skeletonsToRaise = 1;
          }
        }
      }
    }
  }
  thisa->field_F357 = 1;
  CombatManager::freeCreatureStackObjects(thisa);
  CombatManager::displayCombatMessage(thisa, byte_50E6F8, 1, 1, 0);
  MouseManager::setSpriteIdx(mouseManager, 6);
  v21 = 8;
  if ( thisa->terrainType == 7 )
    v21 = 5;
  tick = getTickCount();
  for ( k = 0; v21 > k; ++k )
  {
    yieldToGlobalUpdater();
    sleepUntilPointer(&tick);
    tick = getTickCount() + 60;
    Bitmap::colorSubstituteRectangle(HeroWindowManager::instance->screenBuffer, 0, 0, 640, 480, 3);
    yieldToGlobalUpdater();
    HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 0, 0, 0x27Fu, 479);
    yieldToGlobalUpdater();
  }
  if ( side == -1 )
  {
    SoundManager::couldBePlayCDTrack(soundManager, 30);
    CombatManager::informLostBattle(thisa);
  }
  else
  {
    if ( side >= 0 && side <= 1 )
    {
      if ( thisa->heroes[side] )
      {
        if ( thisa->eagleEyeSpellLearned[side] != -1 )
          thisa->heroes[side]->spellsLearned[thisa->eagleEyeSpellLearned[side]] = 1;
        thisa->experienceForDefeating[1 - side] = CombatManager::getExperiencePointsForDefeatingHero(thisa, 1 - side);
        if ( isRetreating )
          thisa->experienceForDefeating[1 - side] -= 500;
        if ( thisa->castles[1] && !side )
          thisa->experienceForDefeating[1] += 500;
        v15 = giveXPToHero(
                thisa->heroes[side],
                thisa->experienceForDefeating[1 - side],
                (unsigned int)*(&byte_524758 + thisa->heroes[side]->probablyOwnerIdx) < 1);
        if ( !isRetreating )
        {
          numArtifactsToSteal = 0;
          if ( thisa->heroes[0] )
          {
            if ( thisa->heroes[1] )
            {
              for ( k = 0; k < 14; ++k )
              {
                if ( thisa->heroes[side]->artifacts[k] == -1 )
                  ++numArtifactsToSteal;
              }
              for ( k = 0; k < 14; ++k )
              {
                if ( thisa->heroes[1 - side]->artifacts[k] >= 8
                  && thisa->heroes[1 - side]->artifacts[k] != ARTIFACT_MAGIC_BOOK
                  && numStolenArtifacts < numArtifactsToSteal )
                {
                  stolenArtifacts[numStolenArtifacts] = thisa->heroes[1 - side]->artifacts[k];
                  stolenScrollTypes[numStolenArtifacts++] = thisa->heroes[1 - side]->scrollSpell[k];
                }
              }
            }
          }
        }
      }
      if ( curPlayerIdx != -1 && *(&byte_524758 + curPlayerIdx) && thisa->playerID[side] == curPlayerIdx
        || curPlayerIdx != -1
        && thisa->playerID[side] != -1
        && !*(&byte_524758 + curPlayerIdx)
        && *(&byte_524758 + thisa->playerID[side])
        || thisa->playerID[side] != -1 && *(&byte_524758 + thisa->playerID[side]) )
      {
        SoundManager::couldBePlayCDTrack(soundManager, 29);
        v4 = (GUIWindow *)operator new(0x44u);
        if ( v4 )
          thisa->combatEndWindow = GUIWindow_constructorFromFile(v4, 143, 10, "wincmbt.bin");
        else
          thisa->combatEndWindow = 0;
        if ( !thisa->combatEndWindow )
          fatalOutOfMemoryError();
        if ( thisa->heroes[side] )
        {
          if ( isSurrendering )
          {
            sprintf(globBuf, off_4F6868);
          }
          else
          {
            if ( isRetreating )
              sprintf(globBuf, off_4F686C);
            else
              sprintf(globBuf, off_4F6870);
          }
          if ( v15 <= 0 || side != 1 || dword_5235D4 <= 1 )
            sprintf(&v5, off_4F6874, thisa->heroes[side]->name, thisa->experienceForDefeating[1 - side]);
          else
            sprintf(&v5, off_4F6890, thisa->heroes[1]->name, thisa->experienceForDefeating[0], v15);
          strcat(globBuf, &v5);
          sub_495CC0(thisa->heroes[side]);
        }
        else
        {
          if ( isSurrendering )
          {
            sprintf(globBuf, off_4F6868);
          }
          else
          {
            if ( isRetreating )
              sprintf(globBuf, off_4F686C);
            else
              sprintf(globBuf, off_4F6870);
          }
        }
        evt = 512;
        v8 = 3;
        v9 = 101;
        v10 = globBuf;
        GUIWindow::processMessage(thisa->combatEndWindow, (Event *)&evt);
        CombatManager::addCasualtyInfoToWindow(thisa, thisa->combatEndWindow);
        if ( dword_4F7494 && !dword_523ED4 )
          dword_4F1CB4 = getTickCount() + 15000;
        HeroWindowManager::displayWindow(
          HeroWindowManager::instance,
          thisa->combatEndWindow,
          (int (__fastcall *)(InputEvent *))sub_43DE80,
          0);
        dword_4F1CB4 = 0;
        operator delete(thisa->combatEndWindow);
        if ( thisa->heroes[1 - side] )
          sub_495F20(thisa->heroes[1 - side]);
      }
      else
      {
        if ( thisa->heroes[side] )
          sub_495CC0(thisa->heroes[side]);
        if ( thisa->heroes[1 - side] )
          sub_495F20(thisa->heroes[1 - side]);
        SoundManager::couldBePlayCDTrack(soundManager, 30);
        CombatManager::informLostBattle(thisa);
      }
    }
  }
  dword_524214 = advManager->viewX;
  result = advManager->viewY;
  dword_524218 = advManager->viewY;
  return result;
}

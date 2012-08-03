{
  int result; // eax@113
  combatManager *thisa; // [sp+18h] [bp-F8h]@1
  heroWindow *v4; // [sp+24h] [bp-ECh]@76
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
  army *stack; // [sp+108h] [bp-8h]@8
  int v21; // [sp+10Ch] [bp-4h]@37

  thisa = this;
  v15 = 0;
  if ( this->heroes[1] && this->heroes[1]->field_E7[0] )
    this->heroes[1] = 0;
  dword_524C90 = 0;
  gbWhichAnimationPlaying = 1;
  giWinCmbtFrame = 0;
  *(_DWORD *)&giSkeletonsCreated = 0;
  iMaxTransferArtifacts = 0;
  iCurTransferArtifact = -1;
  bSkeletonsShown = 0;
  creaturesKilled = 0;
  v12 = 0;
  for ( i = 0; i < 2; ++i )
  {
    v16 = 0;
    v17 = -1;
    for ( j = 0; gpCombatManager->numCreatures[i] > j; ++j )
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
        if ( hero::GetSSLevel(this->heroes[side], SECONDARY_SKILL_NECROMANCY) )
        {
          *(_DWORD *)&giSkeletonsCreated = (signed __int64)((double)hero::GetSSLevel(
                                                                      thisa->heroes[side],
                                                                      SECONDARY_SKILL_NECROMANCY)
                                                          * 0.1
                                                          * (double)creaturesKilled);
          if ( *(_DWORD *)&giSkeletonsCreated <= 0 )
          {
            if ( creaturesKilled )
              *(_DWORD *)&giSkeletonsCreated = 1;
          }
        }
      }
    }
  }
  thisa->field_F357 = 1;
  combatManager::FreeArmies(thisa);
  combatManager::CombatMessage(thisa, byte_50E6F8, 1, 1, 0);
  mouseManager::SetPointer(gpMouseManager, 6);
  v21 = 8;
  if ( thisa->terrainType == 7 )
    v21 = 5;
  tick = KBTickCount();
  for ( k = 0; v21 > k; ++k )
  {
    PollSound();
    DelayTil(&tick);
    tick = KBTickCount() + 60;
    DimBitmapArea(gpWindowManager->screenBuffer, 0, 0, 640, 480, 3);
    PollSound();
    heroWindowManager::UpdateScreenRegion(gpWindowManager, 0, 0, 0x27Fu, 479);
    PollSound();
  }
  if ( side == -1 )
  {
    soundManager::SwitchAmbientMusic(gpSoundManager, 30);
    combatManager::DoLoseWindow(thisa);
  }
  else if ( side >= 0 && side <= 1 )
  {
    if ( thisa->heroes[side] )
    {
      if ( thisa->eagleEyeSpellLearned[side] != -1 )
        thisa->heroes[side]->spellsLearned[thisa->eagleEyeSpellLearned[side]] = 1;
      thisa->experienceForDefeating[1 - side] = combatManager::ExperienceValueOfStack(thisa, 1 - side);
      if ( gbRetreatWin )
        thisa->experienceForDefeating[1 - side] -= 500;
      if ( thisa->castles[1] && !side )
        thisa->experienceForDefeating[1] += 500;
      v15 = advManager::GiveExperience(
              thisa->heroes[side],
              thisa->experienceForDefeating[1 - side],
              (unsigned int)*(&gbThisNetHumanPlayer + thisa->heroes[side]->probablyOwnerIdx) < 1);
      if ( !gbRetreatWin )
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
                && iMaxTransferArtifacts < numArtifactsToSteal )
              {
                iTransferArtifacts[iMaxTransferArtifacts] = thisa->heroes[1 - side]->artifacts[k];
                iTransferArtifactsInfo[iMaxTransferArtifacts++] = thisa->heroes[1 - side]->scrollSpell[k];
              }
            }
          }
        }
      }
    }
    if ( giCurPlayer != -1 && *(&gbThisNetHumanPlayer + giCurPlayer) && thisa->playerID[side] == giCurPlayer
      || giCurPlayer != -1
      && thisa->playerID[side] != -1
      && !*(&gbThisNetHumanPlayer + giCurPlayer)
      && *(&gbThisNetHumanPlayer + thisa->playerID[side])
      || thisa->playerID[side] != -1 && *(&gbThisNetHumanPlayer + thisa->playerID[side]) )
    {
      soundManager::SwitchAmbientMusic(gpSoundManager, 29);
      v4 = (heroWindow *)operator new(68);
      if ( v4 )
        thisa->combatEndWindow = heroWindow::heroWindow(v4, 143, 10, "wincmbt.bin");
      else
        thisa->combatEndWindow = 0;
      if ( !thisa->combatEndWindow )
        MemError();
      if ( thisa->heroes[side] )
      {
        if ( gbCombatSurrender )
        {
          sprintf(gText, cBattleResults);
        }
        else if ( gbRetreatWin )
        {
          sprintf(gText, off_4F686C);
        }
        else
        {
          sprintf(gText, off_4F6870);
        }
        if ( v15 <= 0 || side != 1 || iLastMsgNumHumanPlayers <= 1 )
          sprintf(&v5, off_4F6874, thisa->heroes[side]->name, thisa->experienceForDefeating[1 - side]);
        else
          sprintf(&v5, off_4F6890, thisa->heroes[1]->name, thisa->experienceForDefeating[0], v15);
        strcat(gText, &v5);
        hero::ApplyBattleWinTemps(thisa->heroes[side]);
      }
      else if ( gbCombatSurrender )
      {
        sprintf(gText, cBattleResults);
      }
      else if ( gbRetreatWin )
      {
        sprintf(gText, off_4F686C);
      }
      else
      {
        sprintf(gText, off_4F6870);
      }
      evt = 512;
      v8 = 3;
      v9 = 101;
      v10 = gText;
      heroWindow::BroadcastMessage(thisa->combatEndWindow, (Event *)&evt);
      combatManager::ShowDeadArmies(thisa, thisa->combatEndWindow);
      if ( gbRemoteOn && !gbThisNetGotAdventureControl )
        giDialogTimeout = KBTickCount() + 15000;
      heroWindowManager::DoDialog(
        gpWindowManager,
        thisa->combatEndWindow,
        (int (__fastcall *)(tag_message *))WinCombatHandler,
        0);
      giDialogTimeout = 0;
      operator delete(thisa->combatEndWindow);
      if ( thisa->heroes[1 - side] )
        hero::ApplyBattleLossTemps(thisa->heroes[1 - side]);
    }
    else
    {
      if ( thisa->heroes[side] )
        hero::ApplyBattleWinTemps(thisa->heroes[side]);
      if ( thisa->heroes[1 - side] )
        hero::ApplyBattleLossTemps(thisa->heroes[1 - side]);
      soundManager::SwitchAmbientMusic(gpSoundManager, 30);
      combatManager::DoLoseWindow(thisa);
    }
  }
  gMapX = gpAdvManager->viewX;
  result = gpAdvManager->viewY;
  gMapY = gpAdvManager->viewY;
  return result;
}
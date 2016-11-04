{
  int v4; // eax@14
  signed int v5; // ST5C_4@18
  void *v6; // [sp+Ch] [bp-24h]@1
  RecruitManager *thisa; // [sp+18h] [bp-18h]@48
  AbstractManager *a2a; // [sp+1Ch] [bp-14h]@49
  int v9; // [sp+20h] [bp-10h]@3
  char *hero; // [sp+24h] [bp-Ch]@6
  int castle; // [sp+28h] [bp-8h]@28
  ARTIFACT a1; // [sp+2Ch] [bp-4h]@21
  int a1a; // [sp+2Ch] [bp-4h]@46
  int v14; // [sp+38h] [bp+8h]@5

  v6 = this;
  if ( a2 >= 200 && a2 <= 999 )
  {
    v9 = (a2 - 200) / 200;
    if ( v9 + dword_511E68[dword_511E64] > dword_525208[dword_511E64] )
      return 0;
    v14 = (a2 - 200) % 200;
    if ( !dword_511E64 )
    {
      hero = (char *)this + 250 * *(&curPlayer->heroesOwned[v9] + dword_511E68[dword_511E64]) + 10180;
      if ( v14 >= 100 && v14 <= 103 )
      {
        dword_524238 = 1;
        dword_5247B4 = *(&curPlayer->heroesOwned[v9] + dword_511E68[dword_511E64]);
        return 1;
      }
      if ( v14 >= 109 && v14 <= 113 )
        v14 -= 5;
      if ( v14 >= 104 )
      {
        if ( v14 <= 108 )
        {
          v4 = ArmyInfo::getNumStacks((ArmyInfo *)((char *)this
                                                 + 250 * *(&curPlayer->heroesOwned[v9] + dword_511E68[dword_511E64])
                                                 + 10281));
          GameInfo::showStackInfo(
            gameObject,
            119,
            20,
            (CREATURES)hero[v14 - 3],
            *(_WORD *)&hero[2 * (v14 - 104) + 106],
            0,
            v4 == 1,
            1u,
            a3,
            (Hero *)hero,
            0,
            (ArmyInfo *)(hero + 101),
            v14 - 104);
          if ( !a3 )
            sub_45FF60(v6, 1, 1, 1);
        }
      }
      if ( v14 >= 146 && v14 <= 153 )
      {
        v5 = sub_498B10((Hero *)hero, v14 - 146);
        Hero::showSecondarySkillDecription((Hero *)hero, (SECONDARY_SKILL)v5, a3);
      }
      if ( v14 >= 114 && v14 <= 127 )
      {
        a1 = hero[v14 + 99];
        if ( a1 == 81 )
          GameInfo::open_spellbook(gameObject, (Hero *)hero, SPELL_CATEGORY_ALL, (int)sub_422530, 1);
        else
          displayArtifactDescription(a1, a3, hero[v14 + 122]);
      }
      if ( v14 >= 170 && v14 <= 173 )
        display_message_window(primary_skill_descriptions[v14 - 170], a3 < 1 ? 1 : 4, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    if ( dword_511E64 == 1 )
    {
      castle = (int)((char *)v6 + 100 * *(&curPlayer->castlesOwned[v9] + dword_511E68[dword_511E64]) + 2899);
      if ( v14 == 4 )
      {
        dword_524238 = 2;
        dword_5247B4 = *(&curPlayer->castlesOwned[v9] + dword_511E68[dword_511E64]);
        return 1;
      }
      if ( v14 >= 39
        && v14 <= 43
        && *((_BYTE *)v6 + 100 * *(&curPlayer->castlesOwned[v9] + dword_511E68[dword_511E64]) + 2922) != -1 )
      {
        dword_524238 = 1;
        dword_5247B4 = *(_BYTE *)(castle + 23);
        return 1;
      }
      if ( v14 >= 10 && v14 <= 14 )
        v14 -= 5;
      if ( v14 >= 5 )
      {
        if ( v14 <= 9 )
        {
          GameInfo::showStackInfo(
            gameObject,
            119,
            20,
            (CREATURES)*((_BYTE *)v6 + 100 * *(&curPlayer->castlesOwned[v9] + dword_511E68[dword_511E64]) + v14 + 2902),
            *((_WORD *)v6 + 50 * *(&curPlayer->castlesOwned[v9] + dword_511E68[dword_511E64]) + v14 - 5 + 1456),
            (int)((char *)v6 + 100 * *(&curPlayer->castlesOwned[v9] + dword_511E68[dword_511E64]) + 2899),
            0,
            1u,
            a3,
            0,
            0,
            (ArmyInfo *)((char *)v6 + 100 * *(&curPlayer->castlesOwned[v9] + dword_511E68[dword_511E64]) + 2907),
            v14 - 5);
          if ( !a3 )
            sub_45FF60(v6, 1, 1, 1);
        }
      }
      if ( v14 >= 27 && v14 <= 38 )
        v14 -= 12;
      if ( v14 >= 15 && v14 <= 26 )
      {
        a1a = v14 - 15;
        if ( a3 )
        {
          dwellingRightClicked((Castle *)castle, a1a);
        }
        else
        {
          thisa = (RecruitManager *)operator new(0x7Eu);
          if ( thisa )
            a2a = (AbstractManager *)RecruitManager_constructor2(thisa, castle, a1a, 0);
          else
            a2a = 0;
          if ( !a2a )
            fatalOutOfMemoryError();
          ManagerManager::weirdAddAndRemoveManagerThing(managerManager, a2a);
          operator delete(a2a);
          ResourceManager::dumpImageToScreen(
            resourceManager,
            "overback.icn",
            HeroWindowManager::instance->screenBuffer,
            1);
          sub_4624F0();
          sub_45FF60(v6, 0, 1, 1);
          GUIWindow::repaintAndUpdateScreen(dword_511E58);
        }
      }
    }
  }
  return 0;
}

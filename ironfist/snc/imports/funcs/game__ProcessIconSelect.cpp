{
  int v4; // eax@14
  signed int v5; // ST5C_4@18
  void *v6; // [sp+Ch] [bp-24h]@1
  recruitUnit *thisa; // [sp+18h] [bp-18h]@48
  baseManager *a2a; // [sp+1Ch] [bp-14h]@49
  int v9; // [sp+20h] [bp-10h]@3
  char *hro; // [sp+24h] [bp-Ch]@6
  int castle; // [sp+28h] [bp-8h]@28
  ARTIFACT a1; // [sp+2Ch] [bp-4h]@21
  int a1a; // [sp+2Ch] [bp-4h]@46
  int v14; // [sp+38h] [bp+8h]@5

  v6 = this;
  if ( a2 >= 200 && a2 <= 999 )
  {
    v9 = (a2 - 200) / 200;
    if ( v9 + giOverviewTop[giOverviewType] > giOverviewItems[giOverviewType] )
      return 0;
    v14 = (a2 - 200) % 200;
    if ( !giOverviewType )
    {
      hro = (char *)this + 250 * *(&gpCurPlayer->heroesOwned[v9] + giOverviewTop[giOverviewType]) + 10180;
      if ( v14 >= 100 && v14 <= 103 )
      {
        giOverviewReturnAction = 1;
        giOverviewReturnActionExtra = *(&gpCurPlayer->heroesOwned[v9] + giOverviewTop[giOverviewType]);
        return 1;
      }
      if ( v14 >= 109 && v14 <= 113 )
        v14 -= 5;
      if ( v14 >= 104 )
      {
        if ( v14 <= 108 )
        {
          v4 = armyGroup::GetNumArmies((armyGroup *)((char *)this
                                                   + 250
                                                   * *(&gpCurPlayer->heroesOwned[v9] + giOverviewTop[giOverviewType])
                                                   + 10281));
          game::ViewArmy(
            gpGame,
            119,
            20,
            (CREATURES)hro[v14 - 3],
            *(_WORD *)&hro[2 * (v14 - 104) + 106],
            0,
            v4 == 1,
            1u,
            a3,
            (hero *)hro,
            0,
            (armyGroup *)(hro + 101),
            v14 - 104);
          if ( !a3 )
            game::SetupDynamicStuff(v6, 1, 1, 1);
        }
      }
      if ( v14 >= 146 && v14 <= 153 )
      {
        v5 = hero::GetNthSS((hero *)hro, v14 - 146);
        hero::DoSSLevelDialog((hero *)hro, (SECONDARY_SKILL)v5, a3);
      }
      if ( v14 >= 114 && v14 <= 127 )
      {
        a1 = hro[v14 + 99];
        if ( a1 == 81 )
          game::ViewSpells(gpGame, (hero *)hro, 2, (int (__fastcall *)(struct tag_message *))ViewSpecialHandler, 1);
        else
          hero::ViewArtifact(a1, a3, hro[v14 + 122]);
      }
      if ( v14 >= 170 && v14 <= 173 )
        NormalDialog(gStatDesc[v14 - 170], a3 < 1 ? 1 : 4, -1, -1, -1, 0, -1, 0, -1, 0);
    }
    if ( giOverviewType == 1 )
    {
      castle = (int)((char *)v6 + 100 * *(&gpCurPlayer->castlesOwned[v9] + giOverviewTop[giOverviewType]) + 2899);
      if ( v14 == 4 )
      {
        giOverviewReturnAction = 2;
        giOverviewReturnActionExtra = *(&gpCurPlayer->castlesOwned[v9] + giOverviewTop[giOverviewType]);
        return 1;
      }
      if ( v14 >= 39
        && v14 <= 43
        && *((_BYTE *)v6 + 100 * *(&gpCurPlayer->castlesOwned[v9] + giOverviewTop[giOverviewType]) + 2922) != -1 )
      {
        giOverviewReturnAction = 1;
        giOverviewReturnActionExtra = *(_BYTE *)(castle + 23);
        return 1;
      }
      if ( v14 >= 10 && v14 <= 14 )
        v14 -= 5;
      if ( v14 >= 5 )
      {
        if ( v14 <= 9 )
        {
          game::ViewArmy(
            gpGame,
            119,
            20,
            (CREATURES)*((_BYTE *)v6
                       + 100 * *(&gpCurPlayer->castlesOwned[v9] + giOverviewTop[giOverviewType])
                       + v14
                       + 2902),
            *((_WORD *)v6 + 50 * *(&gpCurPlayer->castlesOwned[v9] + giOverviewTop[giOverviewType]) + v14 - 5 + 1456),
            (int)((char *)v6 + 100 * *(&gpCurPlayer->castlesOwned[v9] + giOverviewTop[giOverviewType]) + 2899),
            0,
            1u,
            a3,
            0,
            0,
            (armyGroup *)((char *)v6 + 100 * *(&gpCurPlayer->castlesOwned[v9] + giOverviewTop[giOverviewType]) + 2907),
            v14 - 5);
          if ( !a3 )
            game::SetupDynamicStuff(v6, 1, 1, 1);
        }
      }
      if ( v14 >= 27 && v14 <= 38 )
        v14 -= 12;
      if ( v14 >= 15 && v14 <= 26 )
      {
        a1a = v14 - 15;
        if ( a3 )
        {
          QuickViewRecruit((town *)castle, a1a);
        }
        else
        {
          thisa = (recruitUnit *)operator new(126);
          if ( thisa )
            a2a = (baseManager *)recruitUnit::recruitUnit(thisa, castle, a1a, 0);
          else
            a2a = 0;
          if ( !a2a )
            MemError();
          executive::DoDialog(gpExec, a2a);
          operator delete(a2a);
          resourceManager::GetBackdrop(gpResourceManager, "overback.icn", gpWindowManager->screenBuffer, 1);
          game::SetupResources();
          game::SetupDynamicStuff(v6, 0, 1, 1);
          heroWindow::DrawWindow(overWin);
        }
      }
    }
  }
  return 0;
}
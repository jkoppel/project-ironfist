{
  icon *v1; // ST3C_4@3
  icon *v2; // ST3C_4@4
  int v3; // edx@18
  combatManager *thisa; // [sp+Ch] [bp-10h]@1
  icon *res; // [sp+18h] [bp-4h]@6
  icon *resa; // [sp+18h] [bp-4h]@11

  thisa = this;
  if ( !gbNoShowCombat && !this->zeroedAfterAnimatingDeathAndHolySpells )
  {
    v1 = resourceManager::GetIcon(gpResourceManager, this->combatBackgroundFilename);
    IconToBitmap(v1, thisa->probablyBitmapForCombatScreen, 0, 0, 0, 1, 0, 0, 0x280u, 443, 0);
    resourceManager::Dispose(gpResourceManager, (resource *)v1);
    if ( thisa->combatFieldCoverID )
    {
      sprintf(gText, "covr%04d.icn", thisa->combatFieldCoverID);
      v2 = resourceManager::GetIcon(gpResourceManager, gText);
      IconToBitmap(v2, thisa->probablyBitmapForCombatScreen, 0, 0, 0, 0, 0, 0, 0x280u, 443, 0);
      resourceManager::Dispose(gpResourceManager, (resource *)v2);
    }
    if ( thisa->combatFieldFringeID != -1 )
    {
      sprintf(gText, "frng%04d.icn", thisa->combatFieldFringeID);
      res = resourceManager::GetIcon(gpResourceManager, gText);
      if ( thisa->isCastleBattle )
        IconToBitmap(res, thisa->probablyBitmapForCombatScreen, 0, 0, 0, 1, 0, 0, 0x140u, 443, 0);
      else
        IconToBitmap(res, thisa->probablyBitmapForCombatScreen, 0, 0, 0, 0, 0, 0, 0x280u, 443, 0);
      resourceManager::Dispose(gpResourceManager, (resource *)res);
    }
    if ( thisa->isCastleBattle )
    {
      sprintf(gText, "castbkg%c.icn", cHeroTypeInitial[thisa->castles[1]->factionID]);
      resa = resourceManager::GetIcon(gpResourceManager, gText);
      IconToBitmap(resa, thisa->probablyBitmapForCombatScreen, 0, 0, 1, 0, 0, 0, 0x280u, 443, 0);
      if ( thisa->hasMoat )
        IconToBitmap(
          thisa->combatScreenIcons[14],
          thisa->probablyBitmapForCombatScreen,
          0,
          0,
          0,
          0,
          0,
          0,
          0x280u,
          443,
          0);
      if ( thisa->castles[1]->factionID || !(BYTE1(thisa->castles[1]->buildingsBuiltFlags) & 0x20) )
        IconToBitmap(resa, thisa->probablyBitmapForCombatScreen, 0, 0, 3, 0, 0, 0, 0x280u, 443, 0);
      else
        IconToBitmap(resa, thisa->probablyBitmapForCombatScreen, 0, 0, 4, 0, 0, 0, 0x280u, 443, 0);
      resourceManager::Dispose(gpResourceManager, (resource *)resa);
    }
    bitmap::CopyToCareful(
      thisa->probablyBitmapForCombatScreen,
      thisa->couldBeBitmapForFieldItself,
      0,
      0,
      67,
      63,
      507,
      380);
    combatManager::UpdateGrid(thisa, v3, 1, 0);
    bitmap::CopyToCareful(thisa->probablyBitmapForCombatScreen, gpWindowManager->screenBuffer, 0, 0, 0, 0, 640, 443);
    thisa->zeroedAfterAnimatingDeathAndHolySpells = 1;
  }
}
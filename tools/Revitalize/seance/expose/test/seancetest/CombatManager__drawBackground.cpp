void __thiscall CombatManager::drawBackground(CombatManager *this)
{
  Icon *v1; // ST3C_4@3
  Icon *v2; // ST3C_4@4
  int v3; // edx@18
  CombatManager *thisa; // [sp+Ch] [bp-10h]@1
  Icon *res; // [sp+18h] [bp-4h]@6
  Icon *resa; // [sp+18h] [bp-4h]@11

  thisa = this;
  if ( !combatGraphicsOff && !this->zeroedAfterAnimatingDeathAndHolySpells )
  {
    v1 = ResourceManager::getIconByFilename(resourceManager, this->combatBackgroundFilename);
    rasterize(v1, thisa->probablyBitmapForCombatScreen, 0, 0, 0, 1, 0, 0, 0x280u, 443, 0);
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v1);
    if ( thisa->combatFieldCoverID )
    {
      sprintf(globBuf, "covr%04d.icn", thisa->combatFieldCoverID);
      v2 = ResourceManager::getIconByFilename(resourceManager, globBuf);
      rasterize(v2, thisa->probablyBitmapForCombatScreen, 0, 0, 0, 0, 0, 0, 0x280u, 443, 0);
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v2);
    }
    if ( thisa->combatFieldFringeID != -1 )
    {
      sprintf(globBuf, "frng%04d.icn", thisa->combatFieldFringeID);
      res = ResourceManager::getIconByFilename(resourceManager, globBuf);
      if ( thisa->isCastleBattle )
        rasterize(res, thisa->probablyBitmapForCombatScreen, 0, 0, 0, 1, 0, 0, 0x140u, 443, 0);
      else
        rasterize(res, thisa->probablyBitmapForCombatScreen, 0, 0, 0, 0, 0, 0, 0x280u, 443, 0);
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res);
    }
    if ( thisa->isCastleBattle )
    {
      sprintf(globBuf, "castbkg%c.icn", asciiCharacterForFaction[thisa->castles[1]->factionID]);
      resa = ResourceManager::getIconByFilename(resourceManager, globBuf);
      rasterize(resa, thisa->probablyBitmapForCombatScreen, 0, 0, 1, 0, 0, 0, 0x280u, 443, 0);
      if ( thisa->hasMoat )
        rasterize(thisa->combatScreenIcons[14], thisa->probablyBitmapForCombatScreen, 0, 0, 0, 0, 0, 0, 0x280u, 443, 0);
      if ( thisa->castles[1]->factionID || !(BYTE1(thisa->castles[1]->buildingsBuiltFlags) & 0x20) )
        rasterize(resa, thisa->probablyBitmapForCombatScreen, 0, 0, 3, 0, 0, 0, 0x280u, 443, 0);
      else
        rasterize(resa, thisa->probablyBitmapForCombatScreen, 0, 0, 4, 0, 0, 0, 0x280u, 443, 0);
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)resa);
    }
    Bitmap::blitTo(thisa->probablyBitmapForCombatScreen, thisa->couldBeBitmapForFieldItself, 0, 0, 67, 63, 507, 380);
    sub_4C3FF0(thisa, v3, 1, 0);
    Bitmap::blitTo(
      thisa->probablyBitmapForCombatScreen,
      HeroWindowManager::instance->screenBuffer,
      0,
      0,
      0,
      0,
      640,
      443);
    thisa->zeroedAfterAnimatingDeathAndHolySpells = 1;
  }
}

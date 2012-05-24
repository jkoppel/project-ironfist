{
  int v4; // eax@1

  CombatManager::resetStuffHapenedToCreature(this);
  v4 = 80 * a2->owningSide + 4 * a2->stackIdx;
  ++*(signed int *)((char *)this->stuffHappenedToCreature[0] + v4);
  CombatManager::drawBattlefield(combatManager, 0, 1, 0, 1, 75, 1, 1);
  HeroWindowManager::resetSomeBMP(
    HeroWindowManager::instance,
    combatScreenRedrawRectLeft,
    combatScreenRedrawRectTop,
    combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
    combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
  CombatManager::drawBattlefield(this, 0, 1, 0, 1, 75, 1, 1);
  *(_DWORD *)&a2->creature.creature_flags |= flagAdditions;
  CombatManager::drawBattlefield(combatManager, 0, 0, 0, 0, 75, 1, 1);
  sub_4C7E00(
    HeroWindowManager::instance,
    combatScreenRedrawRectLeft,
    combatScreenRedrawRectTop,
    combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
    combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1,
    110,
    0,
    0);
  HeroWindowManager::resetSomeBMP(
    HeroWindowManager::instance,
    combatScreenRedrawRectLeft,
    combatScreenRedrawRectTop,
    combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
    combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
  *(_DWORD *)&a2->creature.creature_flags -= flagAdditions;
  CombatManager::drawBattlefield(combatManager, 0, 0, 0, 0, 75, 1, 1);
  sub_4C7E00(
    HeroWindowManager::instance,
    combatScreenRedrawRectLeft,
    combatScreenRedrawRectTop,
    combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
    combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1,
    110,
    0,
    0);
}

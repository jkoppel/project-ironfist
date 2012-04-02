void __thiscall CombatManager::castMedusaPetrify(CombatManager *this, CreatureStack *stack)
{
  CombatManager *thisa; // ST28_4@1
  int v3; // eax@1

  thisa = this;
  CombatManager::resetStuffHapenedToCreature(this);
  v3 = 80 * stack->owningSide + 4 * stack->stackIdx;
  ++*(signed int *)((char *)thisa->stuffHappenedToCreature[0] + v3);
  CombatManager::drawBattlefield(combatManager, 0, 1, 0, 1, 75, 1, 1);
  HeroWindowManager::resetSomeBMP(
    HeroWindowManager::instance,
    combatScreenRedrawRectLeft,
    combatScreenRedrawRectTop,
    combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
    combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1);
  CombatManager::drawBattlefield(thisa, 0, 1, 0, 1, 75, 1, 1);
  CreatureStack::receiveEffect(stack, EFFECT_PETRIFY, 3);
  CombatManager::drawBattlefield(combatManager, 0, 0, 0, 0, 75, 1, 1);
  sub_4C7E00(
    HeroWindowManager::instance,
    combatScreenRedrawRectLeft,
    combatScreenRedrawRectTop,
    combatScreenRedrawRectRight - combatScreenRedrawRectLeft + 1,
    combatScreenRedrawRectBot - combatScreenRedrawRectTop + 1,
    75,
    0,
    0);
}

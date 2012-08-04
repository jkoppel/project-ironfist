{
  combatManager *thisa; // ST28_4@1
  int v3; // eax@1

  thisa = this;
  combatManager::ResetLimitCreature(this);
  v3 = 80 * stack->owningSide + 4 * stack->stackIdx;
  ++*(signed int *)((char *)thisa->stuffHappenedToCreature[0] + v3);
  combatManager::DrawFrame(gpCombatManager, 0, 1, 0, 1, 75, 1, 1);
  heroWindowManager::SaveFizzleSource(
    gpWindowManager,
    giMinExtentX,
    giMinExtentY,
    giMaxExtentX - giMinExtentX + 1,
    giMaxExtentY - giMinExtentY + 1);
  combatManager::DrawFrame(thisa, 0, 1, 0, 1, 75, 1, 1);
  army::SetSpellInfluence(stack, EFFECT_PETRIFY, 3);
  combatManager::DrawFrame(gpCombatManager, 0, 0, 0, 0, 75, 1, 1);
  heroWindowManager::FizzleForward(
    gpWindowManager,
    giMinExtentX,
    giMinExtentY,
    giMaxExtentX - giMinExtentX + 1,
    giMaxExtentY - giMinExtentY + 1,
    75,
    0,
    0);
}
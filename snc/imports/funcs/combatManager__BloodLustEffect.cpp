{
  int v4; // eax@1

  combatManager::ResetLimitCreature(this);
  v4 = 80 * a2->owningSide + 4 * a2->stackIdx;
  ++*(signed int *)((char *)this->stuffHappenedToCreature[0] + v4);
  combatManager::DrawFrame(gpCombatManager, 0, 1, 0, 1, 75, 1, 1);
  heroWindowManager::SaveFizzleSource(
    gpWindowManager,
    giMinExtentX,
    giMinExtentY,
    giMaxExtentX - giMinExtentX + 1,
    giMaxExtentY - giMinExtentY + 1);
  combatManager::DrawFrame(this, 0, 1, 0, 1, 75, 1, 1);
  *(_DWORD *)&a2->creature.creature_flags |= flagAdditions;
  combatManager::DrawFrame(gpCombatManager, 0, 0, 0, 0, 75, 1, 1);
  heroWindowManager::FizzleForward(
    gpWindowManager,
    giMinExtentX,
    giMinExtentY,
    giMaxExtentX - giMinExtentX + 1,
    giMaxExtentY - giMinExtentY + 1,
    110,
    0,
    0);
  heroWindowManager::SaveFizzleSource(
    gpWindowManager,
    giMinExtentX,
    giMinExtentY,
    giMaxExtentX - giMinExtentX + 1,
    giMaxExtentY - giMinExtentY + 1);
  *(_DWORD *)&a2->creature.creature_flags -= flagAdditions;
  combatManager::DrawFrame(gpCombatManager, 0, 0, 0, 0, 75, 1, 1);
  heroWindowManager::FizzleForward(
    gpWindowManager,
    giMinExtentX,
    giMinExtentY,
    giMaxExtentX - giMinExtentX + 1,
    giMaxExtentY - giMinExtentY + 1,
    110,
    0,
    0);
}
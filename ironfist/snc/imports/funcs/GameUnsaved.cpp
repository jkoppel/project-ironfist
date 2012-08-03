{
  return gpAdvManager && gpAdvManager->ready == 1
      || gpCombatManager && gpCombatManager->ready == 1
      || gpTownManager && gpTownManager->ready == 1;
}
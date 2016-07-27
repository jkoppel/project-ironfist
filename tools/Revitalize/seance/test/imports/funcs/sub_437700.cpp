{
  return advManager && advManager->ready == 1
      || combatManager && combatManager->ready == 1
      || townManager && townManager->ready == 1;
}

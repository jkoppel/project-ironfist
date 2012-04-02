bool __cdecl sub_437700()
{
  return advManager && advManager->ready == 1
      || combatManager && combatManager->ready == 1
      || townManager && townManager->ready == 1;
}

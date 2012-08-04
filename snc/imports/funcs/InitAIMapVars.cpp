{
  void *result; // eax@1

  CloseAIMapVars();
  searchArray::Init(&SVSearchArray);
  gaiLiveChanceOfPos = BaseAlloc(2 * MAP_HEIGHT * MAP_WIDTH, "F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D840 + 8);
  gaiHeroStrategicRVOfPos = BaseAlloc(2 * MAP_HEIGHT * MAP_WIDTH, "F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D840 + 9);
  gaiHeroEventStratRVOfPos = BaseAlloc(2 * MAP_HEIGHT * MAP_WIDTH, "F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D840 + 10);
  gaiTurnValueOfMine = BaseAlloc(MAP_HEIGHT * MAP_WIDTH, "F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D840 + 11);
  result = BaseAlloc(MAP_HEIGHT * MAP_WIDTH, "F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D840 + 12);
  gaiEnemyHeroReachable = result;
  return result;
}
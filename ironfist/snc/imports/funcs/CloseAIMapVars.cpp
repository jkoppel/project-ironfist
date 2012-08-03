{
  if ( gaiLiveChanceOfPos )
    BaseFree(gaiLiveChanceOfPos, (int)"F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D8D0 + 1);
  if ( gaiHeroStrategicRVOfPos )
    BaseFree(gaiHeroStrategicRVOfPos, (int)"F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D8D0 + 2);
  if ( gaiHeroEventStratRVOfPos )
    BaseFree(gaiHeroEventStratRVOfPos, (int)"F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D8D0 + 3);
  if ( gaiTurnValueOfMine )
    BaseFree(gaiTurnValueOfMine, (int)"F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D8D0 + 4);
  if ( gaiEnemyHeroReachable )
    BaseFree(gaiEnemyHeroReachable, (int)"F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D8D0 + 5);
  gaiLiveChanceOfPos = 0;
  gaiHeroStrategicRVOfPos = 0;
  gaiHeroEventStratRVOfPos = 0;
  gaiTurnValueOfMine = 0;
  gaiEnemyHeroReachable = 0;
  searchArray::Close(&SVSearchArray);
}
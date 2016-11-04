{
  if ( mapHeight != a2 || mapWidth != a1 || !byte_4EFA40 )
  {
    byte_4EFA40 = 1;
    mapWidth = a1;
    mapHeight = a2;
    Pathfinder::resetSomething(pathfinder);
  }
  if ( tileExplored )
    KBFree(tileExplored, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA44 + 12);
  tileExplored = (byte *)KBAlloc(mapHeight * mapWidth, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA44 + 13);
  return memset(tileExplored, 0, mapHeight * mapWidth);
}

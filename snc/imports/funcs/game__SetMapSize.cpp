{
  if ( MAP_HEIGHT != a2 || MAP_WIDTH != a1 || !bMapInitialized )
  {
    bMapInitialized = 1;
    MAP_WIDTH = a1;
    MAP_HEIGHT = a2;
    searchArray::Init(gpSearchArray);
  }
  if ( mapExtra )
    BaseFree(mapExtra, (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA44 + 12);
  mapExtra = (byte *)BaseAlloc(MAP_HEIGHT * MAP_WIDTH, "F:\\h2xsrc\\Source\\GAME.CPP", word_4EFA44 + 13);
  return memset(mapExtra, 0, MAP_HEIGHT * MAP_WIDTH);
}
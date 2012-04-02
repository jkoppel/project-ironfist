void *__cdecl sub_4B8A90()
{
  void *result; // eax@1

  sub_4B8B90();
  Pathfinder::resetSomething(&aiPathfinder);
  dword_51D59C = KBAlloc(2 * mapHeight * mapWidth, "F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D840 + 8);
  dword_51D5A0 = KBAlloc(2 * mapHeight * mapWidth, "F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D840 + 9);
  dword_51D5A4 = KBAlloc(2 * mapHeight * mapWidth, "F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D840 + 10);
  dword_51D5A8 = KBAlloc(mapHeight * mapWidth, "F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D840 + 11);
  result = KBAlloc(mapHeight * mapWidth, "F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D840 + 12);
  dword_51D5AC = result;
  return result;
}

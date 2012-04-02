void __cdecl sub_4B8B90()
{
  if ( dword_51D59C )
    KBFree(dword_51D59C, (int)"F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D8D0 + 1);
  if ( dword_51D5A0 )
    KBFree(dword_51D5A0, (int)"F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D8D0 + 2);
  if ( dword_51D5A4 )
    KBFree(dword_51D5A4, (int)"F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D8D0 + 3);
  if ( dword_51D5A8 )
    KBFree(dword_51D5A8, (int)"F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D8D0 + 4);
  if ( dword_51D5AC )
    KBFree(dword_51D5AC, (int)"F:\\h2xsrc\\Source\\PHILAI.CPP", word_51D8D0 + 5);
  dword_51D59C = 0;
  dword_51D5A0 = 0;
  dword_51D5A4 = 0;
  dword_51D5A8 = 0;
  dword_51D5AC = 0;
  Pathfinder::cleanUpForAI(&aiPathfinder);
}

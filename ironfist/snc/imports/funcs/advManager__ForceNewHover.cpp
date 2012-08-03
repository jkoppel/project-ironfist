{
  signed int result; // eax@1
  void *v2; // [sp+Ch] [bp-Ch]@1
  int y; // [sp+10h] [bp-8h]@2
  int x; // [sp+14h] [bp-4h]@2

  v2 = this;
  result = *(&gbThisNetHumanPlayer + giCurPlayer);
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
  {
    mouseManager::MouseCoords(&x, &y);
    *(_DWORD *)((char *)v2 + 486) = -1;
    result = advManager::ProcessHover(v2, x, y);
  }
  return result;
}
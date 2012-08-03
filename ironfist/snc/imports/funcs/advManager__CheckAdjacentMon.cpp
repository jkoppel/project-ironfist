{
  char *v2; // eax@1
  signed int result; // eax@1
  void *thisa; // [sp+Ch] [bp-1Ch]@1
  int v5; // [sp+10h] [bp-18h]@2
  int v6; // [sp+14h] [bp-14h]@2
  int v7; // [sp+18h] [bp-10h]@1
  int v8; // [sp+1Ch] [bp-Ch]@1
  int row; // [sp+20h] [bp-8h]@1
  int col; // [sp+24h] [bp-4h]@1

  thisa = this;
  v2 = (char *)gpGame + 250 * gpCurPlayer->curHeroIdx;
  v8 = (int)(v2 + 10180);
  v7 = 0;
  result = advManager::FindAdjacentMonster(this, *(_QWORD *)(v2 + 10205), (int)&col, (int)&row, -1, -1);
  if ( result )
  {
    advManager::StopCursor((advManager *)thisa, 1);
    advManager::CompleteDraw(
      (advManager *)thisa,
      *(_DWORD *)((char *)thisa + 470),
      *(_DWORD *)((char *)thisa + 474),
      0,
      1);
    advManager::UpdateScreen((advManager *)thisa, 0, 0);
    v5 = (int)advManager::GetCell((advManager *)thisa, col, row);
    v6 = (int)advManager::GetCell((advManager *)thisa, *(_DWORD *)(v8 + 25), *(_DWORD *)(v8 + 29));
    if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
      advManager::PlayerMonsterInteract(thisa, v5, v6, v8, (signed int)&v7, *(_QWORD *)(v8 + 25), 1, __PAIR__(row, col));
    else
      advManager::ComputerMonsterInteract(v5, v8, (int)&v7);
    if ( v7 )
    {
      advManager::EraseObj((mapCell *)thisa, v5, col, row);
      if ( *(&gbThisNetHumanPlayer + giCurPlayer) )
        advManager::FizzleCenter(thisa, 0);
    }
    result = a2;
    *(_DWORD *)a2 = 1;
  }
  return result;
}
{
  int result; // eax@8
  int v1; // [sp+Ch] [bp-Ch]@4
  int v2; // [sp+Ch] [bp-Ch]@10
  signed int v3; // [sp+10h] [bp-8h]@3

  if ( gbRemoteOn )
  {
    v3 = -1;
    if ( gpGame->couldBePlayerAlive[giCurPlayer] )
    {
      v1 = (giCurPlayer + 1) % 6;
      while ( v1 != giCurPlayer )
      {
        if ( !gpGame->couldBePlayerAlive[v1] && gbHumanPlayer[v1] )
        {
          result = *(&gbThisNetHumanPlayer + v1);
          gbThisNetGotAdventureControl = *(&gbThisNetHumanPlayer + v1);
          return result;
        }
      }
    }
    v2 = (giCurPlayer + 1) % 6;
    while ( v2 != giCurPlayer )
    {
      v2 = (v2 + 1) % 6;
      if ( !gpGame->couldBePlayerAlive[v2] && gbHumanPlayer[v2] )
        v3 = v2;
    }
    result = *(&gbThisNetHumanPlayer + v3);
    gbThisNetGotAdventureControl = *(&gbThisNetHumanPlayer + v3);
  }
  else
  {
    gbThisNetGotAdventureControl = 1;
  }
  return result;
}
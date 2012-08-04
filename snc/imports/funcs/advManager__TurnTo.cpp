{
  int thisa; // [sp+10h] [bp-14h]@1
  signed int v3; // [sp+14h] [bp-10h]@7
  int v4; // [sp+18h] [bp-Ch]@1
  signed int v5; // [sp+1Ch] [bp-8h]@1
  int v6; // [sp+20h] [bp-4h]@7
  int v7; // [sp+20h] [bp-4h]@19

  thisa = this;
  v5 = 1;
  v4 = a2 - *(_DWORD *)(this + 638);
  if ( a2 != *(_DWORD *)(this + 638) )
  {
    if ( v4 < 0 && v4 >= -4 || v4 > 0 && v4 > 4 )
      v5 = -1;
    *(_DWORD *)(this + 654) = 1;
    v6 = 2 * *(_DWORD *)(this + 638);
    v3 = giStepDelay[*((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer))];
    if ( !*((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer)) )
      v3 *= 3;
    if ( *((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer)) == 1 )
      v3 = (signed __int64)((double)v3 * 1.5);
    do
    {
      *(_DWORD *)(thisa + 650) = 1;
      if ( *(_DWORD *)(thisa + 634) < 6 )
        *(_DWORD *)(thisa + 642) = horseFrameFlip[v6];
      else
        *(_DWORD *)(thisa + 642) = boatFrameFlip[v6];
      *(_DWORD *)(thisa + 646) = 0;
      animTimer = KBTickCount() + v3;
      if ( *((_DWORD *)&gConfig + *(&gbThisNetHumanPlayer + giCurPlayer)) != 4 )
      {
        if ( advManager::ComboDraw((advManager *)thisa, *(_DWORD *)(thisa + 470), *(_DWORD *)(thisa + 474), 0) )
          advManager::UpdateScreen((advManager *)thisa, 0, 0);
        if ( bShowIt )
          DelayTil(&animTimer);
      }
      v7 = v5 + v6;
      if ( v7 < 0 )
        v7 = 15;
      v6 = (((unsigned __int64)v7 >> 32) ^ abs(v7) & 0xF) - ((unsigned __int64)v7 >> 32);
    }
    while ( 2 * a2 != v6 );
    *(_DWORD *)(thisa + 638) = a2;
    advManager::StopCursor((advManager *)thisa, 1);
    if ( bShowIt )
      DelayTil(&animTimer);
    if ( advManager::ComboDraw((advManager *)thisa, *(_DWORD *)(thisa + 470), *(_DWORD *)(thisa + 474), 0) )
      advManager::UpdateScreen((advManager *)thisa, 0, 0);
  }
}
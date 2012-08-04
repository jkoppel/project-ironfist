{
  int result; // eax@1
  signed int v6; // [sp+14h] [bp-4h]@1

  v6 = 0;
  result = a2;
  gbForceUpdate = a2;
  if ( giBottomViewOverride == 6 )
    return result;
  if ( giBottomViewOverride > 0 )
  {
    if ( KBTickCount() <= giBottomViewOverrideEndTime )
    {
      switch ( giBottomViewOverride )
      {
        case 1:
          v6 = advManager::UpdBottomViewNewTurn(this);
          break;
        case 2:
          v6 = advManager::UpdBottomViewKingdom(this);
          break;
        case 5:
          v6 = advManager::UpdBottomViewResMsg(this);
          break;
      }
      goto LABEL_20;
    }
    giBottomViewOverride = 0;
  }
  if ( *(&gbThisNetHumanPlayer + giCurPlayer) && !gbAllBlack && gpGame->players[giCurPlayer].color == gpCurPlayer->color )
  {
    if ( gpCurPlayer->curHeroIdx == -1 )
      v6 = advManager::UpdBottomViewKingdom(this);
    else
      v6 = advManager::UpdBottomViewHero(this);
  }
  else
  {
    v6 = advManager::UpdBottomViewEnemyTurn(this);
  }
LABEL_20:
  if ( v6 && a3 )
  {
    heroWindow::DrawWindow(this->adventureScreen, 0, 2000, 2200);
    if ( a4 )
      heroWindowManager::UpdateScreenRegion(gpWindowManager, 480, 392, 0x8Fu, 71);
  }
  return gbForceUpdate;
}
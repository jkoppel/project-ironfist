{
  int v2; // [sp+Ch] [bp-4h]@1

  v2 = this;
  *(_BYTE *)(this + 1146) = 0;
  *(_BYTE *)(this + 1147) = iLastMsgNumHumanPlayers;
  if ( *(_DWORD *)(this + 25496) )
  {
    game::CleanUpNewGameWindow((void *)this);
    game::InitNewGame(v2, a2);
    game::InitNewGameWindow(v2);
    game::UpdateNewGameWindow(v2);
    heroWindow::DrawWindow(*(heroWindow **)(v2 + 25496));
  }
}
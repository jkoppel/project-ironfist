{
  char *v4; // eax@9

  if ( *(&gbThisNetHumanPlayer + giCurPlayer) || giDebugLevel && giShowComputerRoute )
  {
    if ( a4 )
      heroWindowManager::BroadcastMessage(gpWindowManager, INPUT_GUI_MESSAGE_CODE, 5, 2, 16392);
    if ( a3 && gpCurPlayer->curHeroIdx != -1 )
    {
      v4 = (char *)gpGame + 250 * gpCurPlayer->curHeroIdx;
      *(_DWORD *)(v4 + 10213) = -1;
      *(_DWORD *)(v4 + 10217) = -1;
    }
    if ( this->field_A2 )
    {
      this->field_A2 = 0;
      if ( a2 )
      {
        advManager::CompleteDraw(this, 0);
        advManager::UpdateScreen(this, 0, 0);
      }
    }
  }
}
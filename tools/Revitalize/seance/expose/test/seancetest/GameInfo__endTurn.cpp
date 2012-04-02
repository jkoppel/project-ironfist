signed int __thiscall GameInfo::endTurn(void *this)
{
  char *v1; // ST1C_4@18
  signed int result; // eax@45
  GameInfo *thisa; // [sp+Ch] [bp-28h]@1
  signed int i; // [sp+28h] [bp-Ch]@3
  signed int j; // [sp+28h] [bp-Ch]@16
  int v6; // [sp+2Ch] [bp-8h]@3

  thisa = (GameInfo *)this;
  *(_DWORD *)((char *)this + 250 * curPlayer->heroesForPurchase[0] + 10407) &= 0xFFFEFFFFu;
  *(_DWORD *)&thisa->heroes[curPlayer->heroesForPurchase[1]].flags1 &= 0xFFFEFFFFu;
  LODWORD(qword_50EAA8) = 0;
  if ( *(&byte_524758 + curPlayerIdx) && *(_DWORD *)&shouldAutosave )
  {
    v6 = 0;
    for ( i = 0; i < 6; ++i )
    {
      if ( !*((_BYTE *)this + i + 1168) )
      {
        if ( dword_524810[i] )
          ++v6;
      }
    }
    GameInfo::saveGame((GameInfo *)this, "AUTOSAVE", 1, 0);
  }
  advManager->field_376 = 0;
  if ( gameObject->players[curPlayerIdx].field_43 > 0 )
    --gameObject->players[curPlayerIdx].field_43;
  checkGameEnd(0, 0);
  sub_4507D0();
  sub_4507F0((int)advManager);
  do
  {
    ++curPlayerIdx;
    if ( thisa->numPlayers <= curPlayerIdx )
    {
      curPlayerIdx = 0;
      sub_424830(thisa);
    }
  }
  while ( gameObject->couldBePlayerAlive[curPlayerIdx] );
  curPlayer = &gameObject->players[curPlayerIdx];
  byte_532C5C = 1 << curPlayerIdx;
  for ( j = 0; thisa->players[curPlayerIdx].numHeroes > j; ++j )
  {
    v1 = (char *)&thisa->heroes[*(&thisa->players[0].heroesOwned[284 * curPlayerIdx] + j - curPlayerIdx)];
    *(_DWORD *)(v1 + 49) = Hero::getStartingMovementPoints((Hero *)v1);
    *(_DWORD *)(v1 + 53) = *(_DWORD *)(v1 + 49);
  }
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    sub_485C90(1);
    InputManager::resetInfoFields(inputManager);
    dword_4F7470 = 1;
    sub_444550(advManager, 1, curPlayerIdx);
    dword_4F7470 = 0;
    if ( dword_52473C && dword_5235D4 > 1 )
    {
      sprintf(globBuf, "%s's turn.", &dword_5235E0[21 * curPlayerIdx]);
      sub_4295B0((int)globBuf, curPlayerIdx);
    }
    if ( *(&byte_524758 + curPlayerIdx) )
      sub_4293B0();
    byte_5306F0 = byte_532C5C;
    dword_523EDC = curPlayerIdx;
  }
  else
  {
    MouseManager::setSpriteIdx(mouseManager, 1);
    sub_455030(advManager, 1, 0, 1);
    sub_4551D0();
    sub_423DE0();
    sub_485C90(0);
    dword_52405C = 6;
    sub_429420();
    dword_524C14 = 0;
    if ( dword_4F7494 )
    {
      if ( dword_524810[curPlayerIdx] )
      {
        dword_523ED4 = 0;
        if ( !sub_42B410(gameObject, *((_BYTE *)&byte_5247A0 + curPlayerIdx), 0, 0) )
          terminate(0);
      }
    }
    if ( dword_52405C == 6 )
      dword_52405C = 0;
  }
  if ( *(&byte_524758 + curPlayerIdx) && dword_4F7494 && thisa->day != 1 && dword_4F747C == -1 )
  {
    SoundManager::couldBePlayCDTrack(soundManager, 21);
    dword_4F747C = getTickCount();
    soundManager->field_688 = 0;
  }
  if ( thisa->day == 1 && dword_532C54 != 1 )
    soundManager->field_688 = 0;
  sub_42C420(thisa);
  checkGameEnd(0, 0);
  if ( *(&byte_524758 + curPlayerIdx) && !soundManager->field_688 && dword_4F747C == -1 )
  {
    soundManager->field_688 = 1;
    SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[advManager->field_A6]);
    sub_452F60(advManager, advManager->viewX + 7, advManager->viewY + 7, 1);
  }
  result = *(&byte_524758 + curPlayerIdx);
  if ( *(&byte_524758 + curPlayerIdx) )
    result = sub_455380(advManager);
  return result;
}

{
  int v1; // eax@9
  int v2; // [sp+0h] [bp-58h]@0
  GameInfo *thisa; // [sp+Ch] [bp-4Ch]@1
  int track; // [sp+10h] [bp-48h]@20
  char v5; // [sp+14h] [bp-44h]@23
  char v6; // [sp+48h] [bp-10h]@20

  thisa = this;
  sub_42E330(this);
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    dword_524798 = getTickCount() + 3000;
    dword_52405C = 1;
    sub_44D440(advManager, 1, 1, 1);
    sub_4557F0(advManager);
    sub_448110(advManager, 0);
    sub_447A00(advManager, 0, 0);
    checkGameEnd(0, 0);
    if ( curPlayer->field_43 >= 0 )
    {
      if ( curPlayer->field_43 == 1 )
        sprintf(globBuf, off_4F6544, &dword_5235E0[21 * curPlayerIdx]);
      else
        sprintf(globBuf, off_4F6540, &dword_5235E0[21 * curPlayerIdx], curPlayer->field_43);
      display_message_window(globBuf, 1, -1, -1, 9, gameObject->players[(char)curPlayerIdx].color, -1, 0, -1, 0);
    }
    if ( curPlayer->numHeroes <= 0 )
    {
      if ( curPlayer->numCastles > 0 )
        sub_4509F0(advManager, curPlayer->castlesOwned[0]);
    }
    else
    {
      v1 = sub_418CE0(curPlayer, 0);
      sub_450C10(advManager, v1, 0);
    }
    sub_4551D0();
    if ( thisa->day == 1 && (thisa->month != 1 || thisa->week != 1 || thisa->day != 1) )
    {
      if ( *(&byte_524758 + curPlayerIdx) )
        soundManager->field_688 = 1;
      if ( *(_DWORD *)&dword_523448 != -1 )
      {
        if ( thisa->week == 1 )
        {
          track = 21;
          strcpy(&v6, "newmonth.82m");
          if ( dword_524A74 )
          {
            if ( dword_524A74 == 1 )
            {
              strcpy(&v5, creatureSingularNames[*(_DWORD *)&dword_52343C]);
              v5 -= 32;
              sprintf(globBuf, off_4F654C, creatureSingularNames[*(_DWORD *)&dword_52343C], &v5);
            }
            else
            {
              sprintf(globBuf, off_4F6550);
            }
          }
          else
          {
            sprintf(globBuf, off_4F6548, off_4F6310[*(_DWORD *)&dword_52343C]);
          }
        }
        else
        {
          track = 20;
          strcpy(&v6, "newweek.82m");
          if ( *(_DWORD *)&dword_523448 )
          {
            strcpy(&v5, creatureSingularNames[*(_DWORD *)&dword_523F10]);
            v5 -= 32;
            sprintf(globBuf, off_4F6558, creatureSingularNames[*(_DWORD *)&dword_523F10], &v5);
          }
          else
          {
            sprintf(globBuf, off_4F6554, off_4F6338[*(_DWORD *)&dword_523F10]);
          }
        }
        SoundManager::otherPlayTrack(soundManager, track, 0, -1, v2);
        MouseManager::setSpriteIdx(mouseManager, 0);
        display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[advManager->field_A6]);
      }
    }
    SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[advManager->field_A6]);
    sub_452F60(advManager, advManager->viewX + 7, advManager->viewY + 7, 1);
  }
  else
  {
    checkGameEnd(0, 0);
  }
}

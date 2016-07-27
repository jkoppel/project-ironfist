{
  char *v1; // ST2C_4@3
  char *v2; // ST24_4@11
  char *v3; // ST20_4@13
  AdvManager *thisa; // [sp+Ch] [bp-18h]@1
  Player *v6; // [sp+18h] [bp-Ch]@8

  thisa = this;
  HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 5, 2, 16392);
  *(_DWORD *)&thisa->_2[12] = 0;
  *(_DWORD *)&thisa->_2[8] = *(_DWORD *)&thisa->_2[12];
  thisa->field_272 = 0;
  dword_4F3084 = 0;
  if ( *(&byte_524758 + curPlayerIdx) && LOBYTE(curPlayer->field_45) != -1 )
  {
    v1 = (char *)&gameObject->castles[LOBYTE(curPlayer->field_45)];
    thisa->viewX = gameObject->castles[LOBYTE(curPlayer->field_45)].field_4 - 7;
    thisa->viewY = (unsigned __int8)v1[5] - 7;
  }
  else
  {
    if ( *(&byte_524758 + curPlayerIdx) && curPlayer->_1[0] != -1 )
    {
      sub_450820((int)thisa, 0);
    }
    else
    {
      if ( *(&byte_524758 + curPlayerIdx) )
        v6 = curPlayer;
      else
        v6 = &gameObject->players[dword_524730];
      if ( v6->numHeroes <= 0 )
      {
        if ( v6->numCastles <= 0 )
        {
          thisa->viewX = 0;
          thisa->viewY = 0;
        }
        else
        {
          v3 = (char *)&gameObject->castles[v6->castlesOwned[0]];
          thisa->viewX = gameObject->castles[v6->castlesOwned[0]].field_4 - 7;
          thisa->viewY = (unsigned __int8)v3[5] - 7;
        }
      }
      else
      {
        v2 = (char *)&gameObject->heroes[v6->heroesOwned[0]];
        thisa->viewX = gameObject->heroes[v6->heroesOwned[0]].x - 7;
        thisa->viewY = *(_DWORD *)(v2 + 29) - 7;
      }
    }
  }
  thisa->field_A6 = (unsigned __int8)tileToTerrainType[*(_WORD *)usedToCheckForBoatByCastle(
                                                                   thisa,
                                                                   thisa->viewX + 7,
                                                                   thisa->viewY + 7)];
  SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[thisa->field_A6]);
  sub_452F60(thisa, thisa->viewX + 7, thisa->viewY + 7, 1);
  sub_4456D0(0, 0);
  return sub_4551D0();
}

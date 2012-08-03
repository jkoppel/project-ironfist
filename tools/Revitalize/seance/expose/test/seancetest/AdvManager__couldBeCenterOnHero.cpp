int __thiscall AdvManager::couldBeCenterOnHero(AdvManager *this)
{
  char *v1; // ST2C_4@3
  Hero *v2; // ST24_4@11
  char *v3; // ST20_4@13
  Player *v6; // [sp+18h] [bp-Ch]@8

  HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, 5, 2, 16392);
  *(_DWORD *)&this->_2[12] = 0;
  *(_DWORD *)&this->_2[8] = *(_DWORD *)&this->_2[12];
  this->field_272 = 0;
  dword_4F3084 = 0;
  if ( *(&byte_524758 + curPlayerIdx) && LOBYTE(curPlayer->field_45) != -1 )
  {
    v1 = (char *)&gameObject->castles[LOBYTE(curPlayer->field_45)];
    this->viewX = gameObject->castles[LOBYTE(curPlayer->field_45)].field_4 - 7;
    this->viewY = (unsigned __int8)v1[5] - 7;
  }
  else
  {
    if ( *(&byte_524758 + curPlayerIdx) && curPlayer->_1[0] != -1 )
    {
      sub_450820(this, 0);
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
          this->viewX = 0;
          this->viewY = 0;
        }
        else
        {
          v3 = (char *)&gameObject->castles[v6->castlesOwned[0]];
          this->viewX = gameObject->castles[v6->castlesOwned[0]].field_4 - 7;
          this->viewY = (unsigned __int8)v3[5] - 7;
        }
      }
      else
      {
        v2 = &gameObject->heroes[v6->heroesOwned[0]];
        this->viewX = gameObject->heroes[v6->heroesOwned[0]].x - 7;
        this->viewY = v2->y - 7;
      }
    }
  }
  this->currentTerrain = (unsigned __int8)tileToTerrainType[AdvManager::getTile(this, this->viewX + 7, this->viewY + 7)->tileType];
  SoundManager::playCDTrack(soundManager, (unsigned __int8)terrainTrackNumbers[this->currentTerrain]);
  sub_452F60(this, this->viewX + 7, this->viewY + 7, 1);
  sub_4456D0(0, 0);
  return sub_4551D0();
}

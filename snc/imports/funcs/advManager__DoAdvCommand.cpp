{
  mapCell *v1; // eax@58
  mapCell *v2; // eax@59
  char v5; // [sp+14h] [bp-78h]@32
  tag_message a2; // [sp+30h] [bp-5Ch]@25
  int i; // [sp+4Ch] [bp-40h]@18
  signed int a8; // [sp+50h] [bp-3Ch]@20
  int a6; // [sp+54h] [bp-38h]@20
  char v10; // [sp+58h] [bp-34h]@1
  int v11; // [sp+5Ch] [bp-30h]@25
  mapCell *loc; // [sp+78h] [bp-14h]@1
  int v13; // [sp+7Ch] [bp-10h]@12
  hero *v14; // [sp+80h] [bp-Ch]@2
  town *v15; // [sp+84h] [bp-8h]@50
  char v16; // [sp+88h] [bp-4h]@1

  loc = 0;
  v16 = 0;
  v10 = 0;
  if ( gpCurPlayer->curHeroIdx == -1 )
    v14 = 0;
  else
    v14 = &gpGame->heroes[gpCurPlayer->curHeroIdx];
  switch ( this->field_36 + 1 )
  {
    case 2:
      if ( v14 )
      {
        *(_DWORD *)&v14->field_21 = *(_DWORD *)&this->_2[16];
        *(_DWORD *)&v14->field_25 = *(_DWORD *)&this->_2[20];
        goto LABEL_7;
      }
      break;
    case 8:
LABEL_7:
      if ( v14 )
      {
        if ( *(_DWORD *)&v14->field_21 != -1 )
        {
          if ( *(_DWORD *)&v14->field_25 != -1 )
          {
            searchArray::BuildPath(
              gpSearchArray,
              v14->x,
              v14->y,
              *(_DWORD *)&v14->field_21,
              *(_DWORD *)&v14->field_25,
              59999);
            if ( gpSearchArray->field_8 > 0 )
            {
              v13 = this->field_A2;
              advManager::MobilizeCurrHero(this, 1);
              if ( *(_DWORD *)&showRoute || v13 )
              {
                advManager::ShowRoute(this, 0, 0, 0);
              }
              else if ( this->field_A2 && this->field_36 != 7 )
              {
                advManager::HideRoute(this, 1, 0, 1);
              }
              mouseManager::HideColorPointer(gpMouseManager);
              inputManager::Flush(gpInputManager);
              for ( i = gpSearchArray->field_8 - 1; i >= 0; --i )
              {
                loc = advManager::MoveHero(
                        this,
                        *((_BYTE *)&gpSearchArray->field_2418 + i),
                        (unsigned int)i < 1,
                        &TrigX,
                        &TrigX + 1,
                        (int)&a6,
                        0,
                        (signed int)&a8,
                        0);
                advManager::UpdateHeroLocator(this, -1, 1, 1);
                if ( loc || a6 || a8 || gbHitEvent )
                  break;
                memcpy(&v11, inputManager::GetEvent(gpInputManager, &a2), 0x1Cu);
                while ( v11 )
                {
                  if ( v11 == 1 || v11 == 8 || v11 == 32 || v11 == 512 )
                  {
                    v16 = 1;
                    advManager::StopCursor(this, 1);
                    goto LABEL_34;
                  }
                  Process1WindowsMessage();
                  memcpy(&v11, inputManager::GetEvent(gpInputManager, (tag_message *)&v5), 0x1Cu);
                }
              }
LABEL_34:
              if ( i <= 0 && v14->x == *(_DWORD *)&v14->field_21 && *(_DWORD *)&v14->field_25 == v14->y
                || v16 && !*(_DWORD *)&showRoute
                || loc )
              {
                advManager::HideRoute(this, 1, 1, 1);
              }
              else if ( this->field_36 == 7 || *(_DWORD *)&showRoute )
              {
                advManager::ShowRoute(this, 0, 1, 1);
              }
              while ( gpMouseManager->cursorDisabled )
                mouseManager::ShowColorPointer(gpMouseManager);
              soundManager::SwitchAmbientMusic(
                gpSoundManager,
                (unsigned __int8)giTerrainToMusicTrack[this->currentTerrain]);
              advManager::UpdBottomView(this, 1, 1, 1);
              if ( loc )
              {
                advManager::StopCursor(this, 1);
                advManager::DoEvent(this, loc, TrigX, *(&TrigX + 1));
                loc = 0;
              }
              advManager::Reseed(0, 0);
              v10 = 1;
              advManager::CheckDimHero(this);
            }
          }
        }
      }
      break;
    case 7:
      advManager::DemobilizeCurrHero(this);
      mouseManager::SetPointer(gpMouseManager, 0);
      v15 = &gpGame->castles[v14->occupiedObjVal];
      town::View(v15, 0);
      loc = 0;
      break;
    case 4:
      advManager::DemobilizeCurrHero(this);
      mouseManager::SetPointer(gpMouseManager, 0);
      loc = advManager::GetCell(
              this,
              gpGame->castles[LOBYTE(gpCurPlayer->field_45)].field_4,
              gpGame->castles[LOBYTE(gpCurPlayer->field_45)].field_5);
      town::View(&gpGame->castles[LOBYTE(gpCurPlayer->field_45)], 0);
      loc = 0;
      break;
    case 3:
      if ( v14 )
      {
        mouseManager::SetPointer(gpMouseManager, 0);
        if ( gbLowMemory )
          advManager::SetEnvironmentOrigin(this, -1, -1, 1);
        advManager::TrimLoopingSounds(this, 0);
        HeroView(gpCurPlayer->curHeroIdx, 0, 0);
        if ( gbLowMemory )
          advManager::SetEnvironmentOrigin(this, this->viewX + 7, this->viewY + 7, 1);
        advManager::RedrawAdvScreen(this, 1, 0);
        heroWindowManager::FadeScreen(gpWindowManager, 0, 8, 0);
      }
      break;
    case 5:
      v1 = advManager::GetCell(this, this->viewX + *(_DWORD *)&this->_2[8], this->viewY + *(_DWORD *)&this->_2[12]);
      advManager::SetHeroContext(this, (unsigned __int8)((unsigned __int8)(v1->flags >> 8) >> -5), 0);
      break;
    case 6:
      v2 = advManager::GetCell(this, this->viewX + *(_DWORD *)&this->_2[8], this->viewY + *(_DWORD *)&this->_2[12]);
      advManager::SetTownContext(this, (unsigned __int8)((unsigned __int8)(v2->flags >> 8) >> -5));
      break;
    case 0:
      break;
  }
  this->field_36 = -1;
  *(_DWORD *)&this->_2[12] = -1;
  *(_DWORD *)&this->_2[8] = *(_DWORD *)&this->_2[12];
  if ( v10 )
    advManager::ForceNewHover(this);
  return loc;
}
{
  int v2; // ebx@16
  void *v3; // [sp+Ch] [bp-40h]@1
  heroWindow *thisa; // [sp+18h] [bp-34h]@6
  signed int v5; // [sp+1Ch] [bp-30h]@1
  int evt; // [sp+20h] [bp-2Ch]@9
  int v7; // [sp+24h] [bp-28h]@9
  int v8; // [sp+28h] [bp-24h]@9
  char *v9; // [sp+38h] [bp-14h]@9
  int i; // [sp+3Ch] [bp-10h]@9
  int v11; // [sp+40h] [bp-Ch]@1
  int v12; // [sp+44h] [bp-8h]@16
  hero *v13; // [sp+48h] [bp-4h]@1

  v3 = this;
  v5 = 1000;
  v11 = -1;
  v13 = &gpGame->heroes[gpCurPlayer->curHeroIdx];
  if ( !gpCurPlayer->numCastles )
  {
    NormalDialog("No available town.  Spell Failed!!!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
    return;
  }
  if ( v13->flags1 & 0x80 )
  {
    NormalDialog("Spell Failed!!!  You must be on land for this spell to work.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
    return;
  }
  if ( a2 != 58 )
  {
    for ( i = 0; gpCurPlayer->numCastles > i; ++i )
    {
      v2 = abs(gpGame->castles[gpCurPlayer->castlesOwned[i]].field_4 - v13->x);
      v12 = abs(gpGame->castles[gpCurPlayer->castlesOwned[i]].field_5 - v13->y) + v2;
      if ( v12 < v5 )
      {
        v5 = v12;
        v11 = i;
      }
    }
    goto LABEL_19;
  }
  thisa = (heroWindow *)operator new(68);
  if ( thisa )
    townPortalWin = heroWindow::heroWindow(thisa, 159, 65, "townport.bin");
  else
    townPortalWin = 0;
  sprintf(gText, "{Town Portal}\n\nSelect town to port to.");
  evt = 512;
  v7 = 3;
  v8 = 1;
  v9 = gText;
  heroWindow::BroadcastMessage(townPortalWin, (Event *)&evt);
  for ( i = 0; gpCurPlayer->numCastles > i; ++i )
  {
    sprintf(gText, gpGame->castles[gpCurPlayer->castlesOwned[i]].name);
    evt = 512;
    v7 = 56;
    v8 = 100;
    v9 = gText;
    heroWindow::BroadcastMessage(townPortalWin, (Event *)&evt);
  }
  v7 = 54;
  v9 = 0;
  heroWindow::BroadcastMessage(townPortalWin, (Event *)&evt);
  heroWindowManager::DoDialog(gpWindowManager, townPortalWin, (int (__fastcall *)(tag_message *))TownPortalHandler, 0);
  v11 = giTownPortalChoice;
  operator delete(townPortalWin);
  if ( gpWindowManager->buttonPressedCode != 30721 )
  {
LABEL_19:
    if ( gpGame->castles[gpCurPlayer->castlesOwned[v11]].visitingHeroIdx == -1 )
    {
      soundManager::SwitchAmbientMusic(gpSoundManager, 1);
      advManager::TeleportTo(
        (advManager *)v3,
        v13,
        gpGame->castles[gpCurPlayer->castlesOwned[v11]].field_4,
        gpGame->castles[gpCurPlayer->castlesOwned[v11]].field_5,
        0,
        0);
      hero::UseSpell(v13, a2);
      gpGame->castles[gpCurPlayer->castlesOwned[v11]].visitingHeroIdx = v13->couldBeHeroIdx;
      town::GiveSpells(&gpGame->castles[gpCurPlayer->castlesOwned[v11]], 0);
      v13->occupiedObjType = 163;
      v13->occupiedObjVal = gpCurPlayer->castlesOwned[v11];
      soundManager::SwitchAmbientMusic(
        gpSoundManager,
        (unsigned __int8)giTerrainToMusicTrack[*(_DWORD *)((char *)v3 + 166)]);
    }
    else
    {
      NormalDialog("Nearest town occupied.  Spell Failed!!!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
    }
  }
}
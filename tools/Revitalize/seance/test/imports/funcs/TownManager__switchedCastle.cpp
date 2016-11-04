{
  TownManager *thisa; // [sp+Ch] [bp-20h]@1
  GUIMessage evt; // [sp+10h] [bp-1Ch]@1

  thisa = this;
  TownManager::buildCosmeticBuildings(this);
  TownManager::refreshFromCastle(thisa);
  evt.eventCode = 512;
  evt.fieldID = -1;
  TownManager::setMessageForMouseover(thisa, &evt);
  if ( *(_DWORD *)&useOpera || !*(_DWORD *)&useCDMusic )
  {
    if ( !*(_DWORD *)&useCDMusic )
      Sleep(0x64u);
    SoundManager::couldBePlayCDTrack(soundManager, factionTrackNumbers[thisa->castle->factionID]);
  }
}

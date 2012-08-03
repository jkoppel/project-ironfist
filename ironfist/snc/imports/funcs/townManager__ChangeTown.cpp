{
  townManager *thisa; // [sp+Ch] [bp-20h]@1
  GUIMessage evt; // [sp+10h] [bp-1Ch]@1

  thisa = this;
  townManager::SetupExtraStuff(this);
  townManager::SetupTown(thisa);
  evt.eventCode = 512;
  evt.fieldID = -1;
  townManager::SetCommandAndText(thisa, &evt);
  if ( *(_DWORD *)&useOpera || !*(_DWORD *)&useCDMusic )
  {
    if ( !*(_DWORD *)&useCDMusic )
      Sleep(0x64u);
    soundManager::SwitchAmbientMusic(gpSoundManager, townTheme[thisa->castle->factionID]);
  }
}
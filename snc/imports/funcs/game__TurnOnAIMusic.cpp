{
  int v0; // [sp+0h] [bp-10h]@0

  soundManager::StopAllSamples(gpSoundManager, 1, v0);
  soundManager::SwitchAmbientMusic(gpSoundManager, 28);
  gpSoundManager->aiMusicOff = 0;
}
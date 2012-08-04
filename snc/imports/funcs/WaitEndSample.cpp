{
  int delaya; // [sp+Ch] [bp-8h]@1
  int v3; // [sp+10h] [bp-4h]@3

  delaya = delay;
  if ( delay < 0 )
    delaya = 4000;
  v3 = KBTickCount() + delaya;
  if ( res.sample )
  {
    while ( soundManager::DigitalReport(gpSoundManager, res.sample, 4) && KBTickCount() < v3 )
    {
      Process1WindowsMessage();
      PollSound();
    }
  }
  if ( (_DWORD)res.file )
    resourceManager::Dispose(gpResourceManager, (resource *)res.file);
}
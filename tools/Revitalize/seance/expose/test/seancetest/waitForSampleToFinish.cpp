void __thiscall waitForSampleToFinish(int delay, sample_resource res)
{
  int delaya; // [sp+Ch] [bp-8h]@1
  int v3; // [sp+10h] [bp-4h]@3

  delaya = delay;
  if ( delay < 0 )
    delaya = 4000;
  v3 = getTickCount() + delaya;
  if ( res.sample )
  {
    while ( SoundManager::sampleStillPlaying(soundManager, res.sample, 4) && getTickCount() < v3 )
    {
      passOnMessages();
      yieldToGlobalUpdater();
    }
  }
  if ( (_DWORD)res.file )
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res.file);
}

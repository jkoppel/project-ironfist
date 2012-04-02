void __cdecl sub_42EF00()
{
  globalSoundUpdateTimer = getTickCount() - 1;
  yieldToGlobalUpdater();
}

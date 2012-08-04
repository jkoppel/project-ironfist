{
  int v2; // eax@4
  sample_resource v3; // ST3C_8@8
  void *thisa; // [sp+10h] [bp-18h]@1

  thisa = this;
  if ( bShowIt )
  {
    if ( a2 )
    {
      if ( a2 != 1 )
        return;
      v2 = Random(1, 7);
      sprintf(gText, "pickup%02d.82M", v2);
    }
    else
    {
      sprintf(gText, "killfade.82M");
    }
    v3 = LoadPlaySample(gText);
    mouseManager::HideColorPointer(gpMouseManager);
    heroWindowManager::SaveFizzleSource(gpWindowManager, 168, 160, 132, 132);
    advManager::CompleteDraw((advManager *)thisa, 0);
    heroWindowManager::FizzleForward(gpWindowManager, 168, 160, 132, 132, 65, 0, 0);
    mouseManager::ShowColorPointer(gpMouseManager);
    WaitEndSample(-1, v3);
  }
}
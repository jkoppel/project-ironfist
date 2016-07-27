{
  int v2; // eax@4
  sample_resource v3; // ST3C_8@8
  void *thisa; // [sp+10h] [bp-18h]@1

  thisa = this;
  if ( dword_524C14 )
  {
    if ( a2 )
    {
      if ( a2 != 1 )
        return;
      v2 = unseededNextRand(1, 7);
      sprintf(globBuf, "pickup%02d.82M", v2);
    }
    else
    {
      sprintf(globBuf, "killfade.82M");
    }
    v3 = playSample(globBuf);
    MouseManager::disableCursor(mouseManager);
    HeroWindowManager::resetSomeBMP(HeroWindowManager::instance, 168, 160, 132, 132);
    sub_448110((AdvManager *)thisa, 0);
    sub_4C7E00(HeroWindowManager::instance, 168, 160, 132, 132, 65, 0, 0);
    MouseManager::enableCursor(mouseManager);
    waitForSampleToFinish(-1, v3);
  }
}

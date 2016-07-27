{
  SoundManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( this->ready == 1 )
  {
    if ( !soundDisabled )
    {
      SoundManager::closeRedbook(this);
      SoundManager::closeMidiOutput(thisa);
      AIL_shutdown();
    }
    thisa->ready = 0;
    soundDisabled = 1;
  }
}

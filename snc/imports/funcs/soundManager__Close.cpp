{
  soundManager *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  if ( this->ready == 1 )
  {
    if ( !gbNoSound )
    {
      soundManager::CDShutdown(this);
      soundManager::MIDIShutdown(thisa);
      AIL_shutdown();
    }
    thisa->ready = 0;
    gbNoSound = 1;
  }
}
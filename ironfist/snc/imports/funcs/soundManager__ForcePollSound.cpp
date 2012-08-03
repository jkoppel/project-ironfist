{
  if ( !gbNoSound )
  {
    *(_BYTE *)(this + 1405) = 1;
    soundManager::PollSound((soundManager *)this);
  }
}
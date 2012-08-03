{
  soundManager *result; // eax@2

  if ( gpSoundManager )
  {
    gpSoundManager->_4[2] ^= 1u;
    result = (soundManager *)gpSoundManager->_4[2];
    if ( gpSoundManager->_4[2] )
    {
      result = gpSoundManager;
      gpSoundManager->_4[1] = 1;
    }
  }
  return result;
}
SoundManager *__stdcall sub_402D50(int a1)
{
  SoundManager *result; // eax@2

  if ( soundManager )
  {
    soundManager->_4[2] ^= 1u;
    result = (SoundManager *)soundManager->_4[2];
    if ( soundManager->_4[2] )
    {
      result = soundManager;
      soundManager->_4[1] = 1;
    }
  }
  return result;
}

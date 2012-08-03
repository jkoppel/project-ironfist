void __thiscall SoundManager::endSample(SoundManager *this, HSAMPLE a2)
{
  signed int i; // [sp+10h] [bp-8h]@3

  if ( !soundDisabled && this->hdidriver )
  {
    AIL_end_sample(a2);
    for ( i = 0; i < 10; ++i )
      sleep(5);
  }
}

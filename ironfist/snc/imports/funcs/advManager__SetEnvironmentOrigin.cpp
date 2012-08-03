{
  int v4; // [sp+0h] [bp-20h]@0
  __int16 v5; // [sp+4h] [bp-1Ch]@0
  int v6; // [sp+8h] [bp-18h]@0
  int j; // [sp+10h] [bp-10h]@11
  int i; // [sp+14h] [bp-Ch]@2
  int k; // [sp+14h] [bp-Ch]@15
  signed int l; // [sp+14h] [bp-Ch]@20
  signed int a3a; // [sp+1Ch] [bp-4h]@13

  if ( gpSoundManager->aiMusicOff )
  {
    for ( i = 0; i < 4; ++i )
    {
      if ( this->field_2C2[i][0] != -1 )
      {
        LogInt((int)"SEO a", i, -999, -999, -999, -999, -999, -999);
        if ( a4 )
        {
          LogInt((int)"SEO b", i, -999, -999, -999, -999, -999, -999);
          soundManager::StopSample(gpSoundManager, *((HSAMPLE *)this->loopSamples[this->field_2C2[i][0]] + 4));
          this->field_2C2[i][0] = -1;
          this->field_2C2[i][1] = 127;
        }
        else
        {
          this->field_2C2[i][1] = 127;
        }
      }
    }
    if ( a2 != -1 && *(_DWORD *)&soundVolume )
    {
      this->field_2BE = 0;
      for ( j = 1; j <= 2; ++j )
      {
        advManager::InsertSound(this, a2, a3, 0, j);
        for ( a3a = 0; a3a < 4; ++a3a )
        {
          for ( k = 0; 2 * a3a > k; ++k )
          {
            advManager::InsertSound(this, k + a2 - a3a, a3 - a3a, a3a, j);
            advManager::InsertSound(this, a3a + a2, k + a3 - a3a, a3a, j);
            advManager::InsertSound(this, a3a + a2 - k, a3a + a3, a3a, j);
            advManager::InsertSound(this, a2 - a3a, a3a + a3 - k, a3a, j);
          }
        }
      }
      for ( l = 0; l < 4; ++l )
      {
        if ( this->field_2C2[l][0] != -1 && this->field_2C2[l][1] > 5 )
        {
          soundManager::StopSample(gpSoundManager, *((HSAMPLE *)this->loopSamples[this->field_2C2[l][0]] + 4));
          this->field_2C2[l][0] = -1;
        }
        if ( this->field_2C2[l][0] != -1 && (1 << LOBYTE(this->field_2C2[l][0])) & this->field_2BE )
          soundManager::ModifySample(
            gpSoundManager,
            *((HSAMPLE *)this->loopSamples[this->field_2C2[l][0]] + 4),
            100,
            dword_4EA270[this->field_2C2[l][1]],
            v4,
            v5,
            v6);
      }
    }
  }
}
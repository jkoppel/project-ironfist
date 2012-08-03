{
  int a2a; // [sp+10h] [bp-10h]@5
  signed int i; // [sp+14h] [bp-Ch]@6
  signed int j; // [sp+14h] [bp-Ch]@14
  int v9; // [sp+18h] [bp-8h]@14
  signed int v10; // [sp+1Ch] [bp-4h]@14

  if ( (signed __int64)__PAIR__(_2C, a2) >= 0 )
  {
    if ( a2 < MAP_WIDTH )
    {
      if ( MAP_HEIGHT > _2C )
      {
        a2a = advManager::GetSoundId(this, a2, _2C);
        if ( a2a != -1 )
        {
          for ( i = 0; i < 4; ++i )
          {
            if ( this->field_2C2[i][0] == a2a )
            {
              if ( this->field_2C2[i][1] > a3 )
              {
                this->field_2C2[i][1] = a3;
                this->field_2BE |= 1 << LOBYTE(this->field_2C2[i][0]);
              }
              return;
            }
          }
          if ( a4 != 1 )
          {
            v9 = a3;
            v10 = -1;
            for ( j = 0; j < 4; ++j )
            {
              if ( this->field_2C2[j][1] > v9 )
              {
                v9 = this->field_2C2[j][1];
                v10 = j;
              }
            }
            if ( v10 != -1 )
            {
              if ( this->field_2C2[v10][0] != -1 )
                soundManager::StopSample(gpSoundManager, *((HSAMPLE *)this->loopSamples[this->field_2C2[v10][0]] + 4));
              this->field_2C2[v10][0] = a2a;
              this->field_2C2[v10][1] = a3;
              advManager::CheckLoadSample(this, a2a);
              *((_DWORD *)this->loopSamples[a2a] + 10) = dword_4EA270[a3];
              *((_DWORD *)this->loopSamples[a2a] + 11) = 0;
              *((_DWORD *)this->loopSamples[a2a] + 7) = 3;
              soundManager::MemorySample(gpSoundManager, (sample *)this->loopSamples[a2a]);
              this->field_2BE ^= 1 << LOBYTE(this->field_2C2[v10][0]);
            }
          }
        }
      }
    }
  }
}
void __thiscall AdvManager::playTerrainLoopSample(AdvManager *this, int a2, int _2C, int a3, int a4)
{
  int a2a; // [sp+10h] [bp-10h]@5
  signed int i; // [sp+14h] [bp-Ch]@6
  signed int j; // [sp+14h] [bp-Ch]@14
  int v9; // [sp+18h] [bp-8h]@14
  signed int v10; // [sp+1Ch] [bp-4h]@14

  if ( (signed __int64)__PAIR__(_2C, a2) >= 0 )
  {
    if ( a2 < mapWidth )
    {
      if ( mapHeight > _2C )
      {
        a2a = sub_453310(this, a2, _2C);
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
                SoundManager::endSample(soundManager, *((HSAMPLE *)this->loopSamples[this->field_2C2[v10][0]] + 4));
              this->field_2C2[v10][0] = a2a;
              this->field_2C2[v10][1] = a3;
              AdvManager::loadloopSample(this, a2a);
              *((_DWORD *)this->loopSamples[a2a] + 10) = dword_4EA270[a3];
              *((_DWORD *)this->loopSamples[a2a] + 11) = 0;
              *((_DWORD *)this->loopSamples[a2a] + 7) = 3;
              SoundManager::playSample(soundManager, (Sample *)this->loopSamples[a2a]);
              this->field_2BE ^= 1 << LOBYTE(this->field_2C2[v10][0]);
            }
          }
        }
      }
    }
  }
}

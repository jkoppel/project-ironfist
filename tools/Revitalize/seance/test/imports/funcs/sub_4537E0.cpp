{
  int v4; // [sp+0h] [bp-20h]@0
  int v5; // [sp+4h] [bp-1Ch]@0
  int v6; // [sp+Ch] [bp-14h]@1
  int v7; // [sp+10h] [bp-10h]@5
  signed int i; // [sp+14h] [bp-Ch]@6
  signed int j; // [sp+14h] [bp-Ch]@14
  int v10; // [sp+18h] [bp-8h]@14
  signed int v11; // [sp+1Ch] [bp-4h]@14

  v6 = this;
  if ( a2 >= 0 )
  {
    if ( (signed int)a2 < mapWidth )
    {
      if ( mapHeight > SHIDWORD(a2) )
      {
        v7 = sub_453310(this, a2, SHIDWORD(a2), v4, v5);
        if ( v7 != -1 )
        {
          for ( i = 0; i < 4; ++i )
          {
            if ( *(_DWORD *)(v6 + 8 * i + 706) == v7 )
            {
              if ( *(_DWORD *)(v6 + 8 * i + 710) > a3 )
              {
                *(_DWORD *)(v6 + 8 * i + 710) = a3;
                *(_DWORD *)(v6 + 702) |= 1 << *(_BYTE *)(v6 + 8 * i + 706);
              }
              return;
            }
          }
          if ( a4 != 1 )
          {
            v10 = a3;
            v11 = -1;
            for ( j = 0; j < 4; ++j )
            {
              if ( *(_DWORD *)(v6 + 8 * j + 710) > v10 )
              {
                v10 = *(_DWORD *)(v6 + 8 * j + 710);
                v11 = j;
              }
            }
            if ( v11 != -1 )
            {
              if ( *(_DWORD *)(v6 + 8 * v11 + 706) != -1 )
                sub_403760(
                  (int)soundManager,
                  *(_DWORD *)(*(_DWORD *)(v6 + 4 * *(_DWORD *)(v6 + 8 * v11 + 706) + 738) + 16));
              *(_DWORD *)(v6 + 8 * v11 + 706) = v7;
              *(_DWORD *)(v6 + 8 * v11 + 710) = a3;
              sub_4532A0((void *)v6, v7);
              *(_DWORD *)(*(_DWORD *)(v6 + 4 * v7 + 738) + 40) = dword_4EA270[a3];
              *(_DWORD *)(*(_DWORD *)(v6 + 4 * v7 + 738) + 44) = 0;
              *(_DWORD *)(*(_DWORD *)(v6 + 4 * v7 + 738) + 28) = 3;
              SoundManager::playSample(soundManager, *(Sample **)(v6 + 4 * v7 + 738));
              *(_DWORD *)(v6 + 702) ^= 1 << *(_BYTE *)(v6 + 8 * v11 + 706);
            }
          }
        }
      }
    }
  }
}

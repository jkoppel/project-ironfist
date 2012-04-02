char __thiscall CombatManager::initializeHexNeighbors(CombatManager *this)
{
  int v1; // eax@3
  signed int v3; // [sp+14h] [bp-10h]@1
  signed int j; // [sp+18h] [bp-Ch]@3
  signed int i; // [sp+1Ch] [bp-8h]@1
  int v6; // [sp+20h] [bp-4h]@3

  v3 = 0;
  for ( i = 0; i < 117; ++i )
  {
    v1 = i / 13;
    v6 = i / 13;
    for ( j = 0; j < 6; ++j )
    {
      if ( i % 13 && i % 13 != 12 )
      {
        switch ( j )
        {
          case 0:
            if ( v6 & 1 )
              v3 = i - 13;
            else
              v3 = i - 12;
            break;
          case 2:
            if ( v6 & 1 )
              v3 = i + 13;
            else
              v3 = i + 14;
            break;
          case 3:
            if ( v6 & 1 )
              v3 = i + 12;
            else
              v3 = i + 13;
            break;
          case 5:
            if ( v6 & 1 )
              v3 = i - 14;
            else
              v3 = i - 13;
            break;
          case 1:
            v3 = i + 1;
            break;
          case 4:
            v3 = i - 1;
            break;
          default:
            break;
        }
        if ( v3 % 13 && v3 % 13 != 12 && v3 >= 0 && v3 < 117 )
        {
          LOBYTE(v1) = v3;
          this->hexNeighbors[i][j] = v3;
        }
        else
        {
          v1 = j + 6 * i;
          this->hexNeighbors[0][v1] = -1;
        }
      }
      else
      {
        v1 = j + 6 * i;
        this->hexNeighbors[0][v1] = -1;
      }
    }
  }
  return v1;
}

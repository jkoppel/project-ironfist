{
  signed int result; // eax@2
  __int64 v5; // ST00_8@127
  __int64 v6; // ST00_8@135
  __int64 v7; // ST00_8@141
  __int64 v8; // ST00_8@148
  __int64 v9; // ST00_8@153
  __int64 v10; // ST00_8@162
  __int64 v11; // ST00_8@164
  __int64 v12; // ST00_8@170
  __int64 v13; // ST00_8@175
  __int64 v14; // ST00_8@182
  __int64 v15; // ST00_8@190
  int v17; // [sp+10h] [bp-18h]@19
  int v18; // [sp+10h] [bp-18h]@81
  signed int i; // [sp+14h] [bp-14h]@11
  signed int l; // [sp+14h] [bp-14h]@55
  signed int m; // [sp+14h] [bp-14h]@69
  signed int jj; // [sp+14h] [bp-14h]@79
  signed int kk; // [sp+14h] [bp-14h]@105
  signed int mm; // [sp+14h] [bp-14h]@122
  signed int i1; // [sp+14h] [bp-14h]@130
  signed int i4; // [sp+14h] [bp-14h]@143
  signed int i10; // [sp+14h] [bp-14h]@177
  signed int i12; // [sp+14h] [bp-14h]@185
  signed int i14; // [sp+14h] [bp-14h]@193
  signed int j; // [sp+18h] [bp-10h]@13
  signed int k; // [sp+18h] [bp-10h]@53
  signed int n; // [sp+18h] [bp-10h]@71
  signed int ii; // [sp+18h] [bp-10h]@77
  signed int ll; // [sp+18h] [bp-10h]@107
  signed int nn; // [sp+18h] [bp-10h]@124
  signed int i2; // [sp+18h] [bp-10h]@132
  signed int i3; // [sp+18h] [bp-10h]@138
  signed int i5; // [sp+18h] [bp-10h]@145
  signed int i6; // [sp+18h] [bp-10h]@150
  signed int i7; // [sp+18h] [bp-10h]@155
  signed int i8; // [sp+18h] [bp-10h]@167
  signed int i9; // [sp+18h] [bp-10h]@172
  signed int i11; // [sp+18h] [bp-10h]@179
  signed int i13; // [sp+18h] [bp-10h]@187
  signed int i15; // [sp+18h] [bp-10h]@195
  int v46; // [sp+1Ch] [bp-Ch]@111
  int v47; // [sp+20h] [bp-8h]@111
  int v48; // [sp+24h] [bp-4h]@193

  yieldToGlobalUpdater();
  if ( !dword_524C14 )
    return 0;
  if ( this->field_2AE )
  {
    sub_447C20(this, a2, a3, 0, 1);
    return 1;
  }
  if ( a4 )
  {
    dword_50F940 += dword_524CB4;
    if ( dword_50F940 < 12 )
    {
      passOnMessages();
      if ( getTickCount() > animationFrameSwitchTime )
        animationFrameSwitchTime = getTickCount() + 120;
      yieldToGlobalUpdater();
      return 0;
    }
    dword_50F940 = 0;
  }
  *(_DWORD *)&this->_2[0] = this->viewX;
  *(_DWORD *)&this->_2[4] = this->viewY;
  memset(&byte_524D30, 0, 0x100u);
  *(_DWORD *)&this->field_292[16] = 0;
  for ( i = 0; i < 15; ++i )
  {
    for ( j = 0; j < 15; ++j )
    {
      if ( a2 + j >= 0 && a2 + j < mapWidth && a3 + i >= 0 && a3 + i < mapHeight )
      {
        v17 = usedToCheckForBoatByCastle(this, a2 + j, a3 + i);
        if ( *(_BYTE *)(v17 + 2) & 1 || *(_BYTE *)(v17 + 6) & 1 )
          ++*((_BYTE *)&byte_524D30 + 18 * j + i);
        if ( (*(_BYTE *)(v17 + 9) & 0x7F) == 40 )
          ++*((_BYTE *)&byte_524D30 + 18 * j + i);
        if ( (*(_BYTE *)(v17 + 9) & 0x7F) == 1 )
          ++*((_BYTE *)&byte_524D30 + 18 * j + i);
        if ( *(_BYTE *)(v17 + 9) == 152 )
        {
          ++*((_BYTE *)&byte_524D30 + 18 * j + i);
          ++*((_BYTE *)&byte_524D30 + 9 * (2 * j - 2) + i);
          if ( sub_448150(a2 + j, a3 + i) )
          {
            *((_BYTE *)&byte_524D30 + 9 * (2 * j + 2) + i) += 10;
            if ( i >= 1 )
            {
              *((_BYTE *)&dword_524D2C + 18 * j + i + 3) += 10;
              *((_BYTE *)&dword_524D2C + 9 * (2 * j + 2) + i + 3) += 10;
            }
          }
          else
          {
            ++*((_BYTE *)&byte_524D30 + 9 * (2 * j + 2) + i);
            if ( i >= 1 )
            {
              ++*((_BYTE *)&dword_524D2C + 18 * j + i + 3);
              ++*((_BYTE *)&dword_524D2C + 9 * (2 * j + 2) + i + 3);
            }
          }
        }
        if ( *(_BYTE *)(v17 + 9) == 170 || *(_BYTE *)(v17 + 9) == 171 )
        {
          ++*((_BYTE *)&byte_524D30 + 18 * j + i);
          if ( sub_448150(a2 + j, a3 + i) )
          {
            *((_BYTE *)&byte_524D30 + 9 * (2 * j + 2) + i) += 10;
            *(&byte_524D31[18 * j] + i) += 10;
            *(&byte_524D31[9 * (2 * j + 2)] + i) += 10;
            *((_BYTE *)&byte_524D30 + 9 * (2 * j + 4) + i) += 10;
            if ( i >= 1 )
              *((_BYTE *)&dword_524D2C + 18 * j + i + 3) += 10;
            if ( j >= 1 )
            {
              *((_BYTE *)&byte_524D30 + 9 * (2 * j - 2) + i) += 10;
              *(&byte_524D31[9 * (2 * j - 2)] + i) += 10;
              if ( j >= 2 )
                *((_BYTE *)&byte_524D30 + 9 * (2 * j - 4) + i) += 10;
              if ( i >= 1 )
                ++*((_BYTE *)&dword_524D2C + 9 * (2 * j - 4) + i + 3);
            }
          }
          else
          {
            ++*((_BYTE *)&byte_524D30 + 9 * (2 * j + 2) + i);
            ++*(&byte_524D31[18 * j] + i);
            ++*(&byte_524D31[9 * (2 * j + 2)] + i);
            ++*((_BYTE *)&byte_524D30 + 9 * (2 * j + 4) + i);
            if ( i >= 1 )
              ++*((_BYTE *)&dword_524D2C + 18 * j + i + 3);
            if ( j >= 1 )
            {
              ++*((_BYTE *)&byte_524D30 + 9 * (2 * j - 2) + i);
              ++*(&byte_524D31[9 * (2 * j - 2)] + i);
              if ( j >= 2 )
                ++*((_BYTE *)&byte_524D30 + 9 * (2 * j - 4) + i);
              if ( i >= 1 )
                ++*((_BYTE *)&dword_524D2C + 9 * (2 * j - 4) + i + 3);
            }
          }
        }
      }
    }
  }
  for ( k = 0; k < 15; ++k )
  {
    for ( l = 0; l < 15; ++l )
    {
      if ( *((_BYTE *)&byte_524D30 + 18 * k + l) )
      {
        if ( a2 + k >= 0 && a2 + k < mapWidth && a3 + l >= 0 && a3 + l < mapHeight )
        {
          if ( (signed int)*((_BYTE *)&byte_524D30 + 18 * k + l) < 10 && !sub_448150(a2 + k, a3 + l) )
            *((_BYTE *)&byte_524D30 + 18 * k + l) = 0;
        }
        else
        {
          *((_BYTE *)&byte_524D30 + 18 * k + l) = 0;
        }
      }
    }
  }
  if ( this->field_2A6 )
  {
    for ( m = 6; m <= 8; ++m )
    {
      for ( n = 5; n <= 9; ++n )
        ++*((_BYTE *)&byte_524D30 + 18 * n + m);
    }
  }
  if ( this->field_27A == 6 )
  {
    ++byte_524DA1;
    ++byte_524DB3;
    ++byte_524DC5;
  }
  for ( ii = 0; ii < 15; ++ii )
  {
    for ( jj = 0; jj < 15; ++jj )
    {
      v18 = usedToCheckForBoatByCastle(this, a2 + ii, a3 + jj);
      if ( *(_BYTE *)(v18 + 9) == 151 )
      {
        if ( gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(*(_WORD *)(v18 + 4) >> 8) >> -5) + 3] == 59 )
        {
          ++*((_BYTE *)&byte_524D30 + 18 * ii + jj);
          ++*((_BYTE *)&byte_524D30 + 9 * (2 * ii + 2) + jj);
          if ( ii < 15 )
            ++*((_BYTE *)&byte_524D30 + 9 * (2 * ii + 4) + jj);
          if ( ii > 0 )
            ++*((_BYTE *)&byte_524D30 + 9 * (2 * ii - 2) + jj);
          if ( jj > 0 )
          {
            ++*((_BYTE *)&dword_524D2C + 18 * ii + jj + 3);
            ++*((_BYTE *)&dword_524D2C + 9 * (2 * ii + 2) + jj + 3);
            if ( ii < 15 )
              ++*((_BYTE *)&dword_524D2C + 9 * (2 * ii + 4) + jj + 3);
            if ( ii > 0 )
              ++*((_BYTE *)&dword_524D2C + 9 * (2 * ii - 2) + jj + 3);
          }
          if ( jj > 1 )
          {
            ++*((_BYTE *)&dword_524D2C + 18 * ii + jj + 2);
            ++*((_BYTE *)&dword_524D2C + 9 * (2 * ii + 2) + jj + 2);
            if ( ii < 15 )
              ++*((_BYTE *)&dword_524D2C + 9 * (2 * ii + 4) + jj + 2);
            if ( ii > 0 )
              ++*((_BYTE *)&dword_524D2C + 9 * (2 * ii - 2) + jj + 2);
          }
        }
        else
        {
          if ( jj > 0 && *((_BYTE *)&dword_524D2C + 18 * ii + jj + 3) )
            ++*((_BYTE *)&byte_524D30 + 18 * ii + jj);
        }
      }
    }
  }
  if ( this->field_A2 && this->field_9E )
  {
    for ( kk = 1; kk < 14; ++kk )
    {
      for ( ll = 0; ll < 15; ++ll )
      {
        if ( *((_BYTE *)&byte_524D30 + 18 * ll + kk) )
        {
          v47 = a2 + ll;
          v46 = a3 + kk;
          if ( a2 + ll >= 0 )
          {
            if ( mapWidth - 1 >= v47 && v46 >= 1 && mapHeight - 2 >= v46 )
            {
              if ( *(_WORD *)(2 * v47 + 2 * v46 * mapWidth + this->field_9E) )
                ++*(&byte_524D31[18 * ll] + kk);
              if ( *(_WORD *)(2 * v47 + 2 * mapWidth * (v46 - 1) + this->field_9E) )
                ++*((_BYTE *)&dword_524D2C + 18 * ll + kk + 3);
            }
          }
        }
      }
    }
  }
  mouseManager->couldBeShowMouse = 0;
  for ( mm = 0; mm < 15; ++mm )
  {
    for ( nn = 0; nn < 15; ++nn )
    {
      if ( *((_BYTE *)&byte_524D30 + 18 * nn + mm) )
      {
        HIDWORD(v5) = a3 + mm;
        LODWORD(v5) = a2 + nn;
        AdvManager::drawAdventureMap(this, v5, nn, mm, 1, 0);
      }
    }
  }
  for ( i1 = 0; i1 < 15; ++i1 )
  {
    for ( i2 = 0; i2 < 15; ++i2 )
    {
      if ( *((_BYTE *)&byte_524D30 + 18 * i2 + i1) )
      {
        HIDWORD(v6) = a3 + i1;
        LODWORD(v6) = a2 + i2;
        AdvManager::drawAdventureMap(this, v6, i2, i1, -128, 0);
      }
    }
  }
  for ( i3 = 0; i3 < 15; ++i3 )
  {
    if ( *((_BYTE *)&byte_524D30 + 18 * i3) )
    {
      HIDWORD(v7) = a3;
      LODWORD(v7) = a2 + i3;
      AdvManager::drawAdventureMap(this, v7, i3, 0, 2, 0);
    }
  }
  for ( i4 = 1; i4 < 15; ++i4 )
  {
    yieldToGlobalUpdater();
    for ( i5 = 0; i5 < 15; ++i5 )
    {
      if ( *((_BYTE *)&dword_524D2C + 18 * i5 + i4 + 3) )
      {
        HIDWORD(v8) = a3 + i4 - 1;
        LODWORD(v8) = a2 + i5;
        AdvManager::drawAdventureMap(this, v8, i5, i4 - 1, 8, 0);
      }
    }
    for ( i6 = 0; i6 < 15; ++i6 )
    {
      if ( *((_BYTE *)&dword_524D2C + 18 * i6 + i4 + 3) )
      {
        HIDWORD(v9) = a3 + i4 - 1;
        LODWORD(v9) = a2 + i6;
        AdvManager::drawAdventureMap(this, v9, i6, i4 - 1, 4, 0);
      }
    }
    for ( i7 = 0; i7 < 15; ++i7 )
    {
      if ( a2 + i7 != dword_4F4BC0 || a3 + i4 != dword_4F4BC4 )
      {
        if ( a2 + i7 == dword_4F4BC0 && a3 + i4 == dword_4F4BC4 + 1 )
        {
          HIDWORD(v10) = a3 + i4 - 1;
          LODWORD(v10) = a2 + i7;
          AdvManager::drawAdventureMap(this, v10, i7, i4 - 1, 2, 0);
        }
        if ( *((_BYTE *)&byte_524D30 + 18 * i7 + i4) )
        {
          HIDWORD(v11) = a3 + i4;
          LODWORD(v11) = a2 + i7;
          AdvManager::drawAdventureMap(this, v11, i7, i4, 2, 0);
        }
      }
    }
  }
  for ( i8 = 0; i8 < 15; ++i8 )
  {
    if ( byte_524D3E[18 * i8] )
    {
      HIDWORD(v12) = a3 + 14;
      LODWORD(v12) = a2 + i8;
      AdvManager::drawAdventureMap(this, v12, i8, 14, 8, 0);
    }
  }
  for ( i9 = 0; i9 < 15; ++i9 )
  {
    if ( byte_524D3E[18 * i9] )
    {
      HIDWORD(v13) = a3 + 14;
      LODWORD(v13) = a2 + i9;
      AdvManager::drawAdventureMap(this, v13, i9, 14, 4, 0);
    }
  }
  for ( i10 = 0; i10 < 15; ++i10 )
  {
    for ( i11 = 0; i11 < 15; ++i11 )
    {
      if ( *((_BYTE *)&byte_524D30 + 18 * i11 + i10) )
      {
        HIDWORD(v14) = a3 + i10;
        LODWORD(v14) = a2 + i11;
        AdvManager::drawAdventureMap(this, v14, i11, i10, 64, 0);
      }
    }
  }
  for ( i12 = 0; i12 < 15; ++i12 )
  {
    for ( i13 = 0; i13 < 15; ++i13 )
    {
      if ( *((_BYTE *)&byte_524D30 + 18 * i13 + i12) )
      {
        HIDWORD(v15) = a3 + i12;
        LODWORD(v15) = a2 + i13;
        AdvManager::drawAdventureMap(this, v15, i13, i12, 32, 0);
      }
    }
  }
  sub_4564F0((int)this);
  mouseManager->couldBeShowMouse = 1;
  yieldToGlobalUpdater();
  sub_44D440(this, 0, 1, 1);
  xOff = 15;
  yOff = 15;
  dword_524D18 = 0;
  dword_524D1C = 0;
  v48 = 0;
  for ( i14 = 0; i14 < 15; ++i14 )
  {
    for ( i15 = 0; i15 < 15; ++i15 )
    {
      if ( *((_BYTE *)&byte_524D30 + 18 * i15 + i14) )
      {
        ++v48;
        if ( xOff > i15 )
          xOff = i15;
        if ( i15 > dword_524D18 )
          dword_524D18 = i15;
        if ( yOff > i14 )
          yOff = i14;
        if ( dword_524D1C < i14 )
          dword_524D1C = i14;
      }
    }
  }
  xOff *= 32;
  yOff *= 32;
  dword_524D18 = 32 * (dword_524D18 + 1) - 1;
  dword_524D1C = 32 * (dword_524D1C + 1) - 1;
  if ( xOff < 16 )
    xOff = 16;
  if ( dword_524D18 > 463 )
    dword_524D18 = 463;
  if ( yOff < 16 )
    yOff = 16;
  if ( dword_524D1C > 463 )
    dword_524D1C = 463;
  if ( xOff <= dword_524D18 && dword_524D1C >= yOff )
  {
    result = 1;
  }
  else
  {
    xOff = dword_524D18 - 1;
    yOff = dword_524D1C - 1;
    result = 0;
  }
  return result;
}

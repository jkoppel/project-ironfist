{
  __int64 v5; // ST00_8@9
  __int64 v6; // ST00_8@15
  __int64 v7; // ST00_8@19
  __int64 v8; // ST00_8@25
  __int64 v9; // ST00_8@28
  __int64 v10; // ST00_8@32
  __int64 v11; // ST00_8@35
  __int64 v12; // ST00_8@38
  __int64 v13; // ST00_8@42
  __int64 v14; // ST00_8@45
  __int64 v15; // ST00_8@50
  __int64 v16; // ST00_8@56
  signed int i; // [sp+10h] [bp-8h]@5
  signed int k; // [sp+10h] [bp-8h]@11
  signed int n; // [sp+10h] [bp-8h]@20
  signed int i2; // [sp+10h] [bp-8h]@46
  signed int i4; // [sp+10h] [bp-8h]@52
  int j; // [sp+14h] [bp-4h]@7
  int l; // [sp+14h] [bp-4h]@13
  int m; // [sp+14h] [bp-4h]@17
  int kk; // [sp+14h] [bp-4h]@23
  int ll; // [sp+14h] [bp-4h]@26
  int ii; // [sp+14h] [bp-4h]@30
  int jj; // [sp+14h] [bp-4h]@33
  int mm; // [sp+14h] [bp-4h]@36
  int nn; // [sp+14h] [bp-4h]@40
  int i1; // [sp+14h] [bp-4h]@43
  int i3; // [sp+14h] [bp-4h]@48
  int i5; // [sp+14h] [bp-4h]@54

  yieldToGlobalUpdater();
  if ( a4 || dword_524C14 )
  {
    xOff = -1;
    *(_DWORD *)&this->_2[0] = this->viewX;
    *(_DWORD *)&this->_2[4] = this->viewY;
    if ( dword_4F7470 )
    {
      this->viewY = 0;
      this->viewX = this->viewY;
    }
    mouseManager->couldBeShowMouse = 0;
    *(_DWORD *)&this->field_292[16] = 0;
    this->field_2AE = 0;
    for ( i = 0; i < 15; ++i )
    {
      for ( j = 0; j < 15; ++j )
      {
        HIDWORD(v5) = a3 + i;
        LODWORD(v5) = j + a2;
        AdvManager::drawAdventureMap(this, v5, j, i, 1, a4);
      }
    }
    for ( k = 0; k < 15; ++k )
    {
      for ( l = 0; l < 15; ++l )
      {
        HIDWORD(v6) = a3 + k;
        LODWORD(v6) = l + a2;
        AdvManager::drawAdventureMap(this, v6, l, k, -128, a4);
      }
    }
    for ( m = 0; m < 15; ++m )
    {
      HIDWORD(v7) = a3;
      LODWORD(v7) = m + a2;
      AdvManager::drawAdventureMap(this, v7, m, 0, 2, a4);
    }
    for ( n = 1; n < 15; ++n )
    {
      yieldToGlobalUpdater();
      if ( this->field_27E <= 4 )
      {
        for ( ii = 14; ii >= 0; --ii )
        {
          HIDWORD(v10) = a3 + n - 1;
          LODWORD(v10) = ii + a2;
          AdvManager::drawAdventureMap(this, v10, ii, n - 1, 8, a4);
        }
        for ( jj = 14; jj >= 0; --jj )
        {
          HIDWORD(v11) = a3 + n - 1;
          LODWORD(v11) = jj + a2;
          AdvManager::drawAdventureMap(this, v11, jj, n - 1, 4, a4);
        }
      }
      else
      {
        for ( kk = 0; kk < 15; ++kk )
        {
          HIDWORD(v8) = a3 + n - 1;
          LODWORD(v8) = kk + a2;
          AdvManager::drawAdventureMap(this, v8, kk, n - 1, 8, a4);
        }
        for ( ll = 0; ll < 15; ++ll )
        {
          HIDWORD(v9) = a3 + n - 1;
          LODWORD(v9) = ll + a2;
          AdvManager::drawAdventureMap(this, v9, ll, n - 1, 4, a4);
        }
      }
      for ( mm = 0; mm < 15; ++mm )
      {
        HIDWORD(v12) = a3 + n;
        LODWORD(v12) = mm + a2;
        AdvManager::drawAdventureMap(this, v12, mm, n, 2, a4);
      }
    }
    for ( nn = 0; nn < 15; ++nn )
    {
      HIDWORD(v13) = a3 + 14;
      LODWORD(v13) = nn + a2;
      AdvManager::drawAdventureMap(this, v13, nn, 14, 8, a4);
    }
    for ( i1 = 0; i1 < 15; ++i1 )
    {
      HIDWORD(v14) = a3 + 14;
      LODWORD(v14) = i1 + a2;
      AdvManager::drawAdventureMap(this, v14, i1, 14, 4, a4);
    }
    for ( i2 = 0; i2 < 15; ++i2 )
    {
      for ( i3 = 0; i3 < 15; ++i3 )
      {
        HIDWORD(v15) = a3 + i2;
        LODWORD(v15) = i3 + a2;
        AdvManager::drawAdventureMap(this, v15, i3, i2, 64, a4);
      }
    }
    for ( i4 = 0; i4 < 15; ++i4 )
    {
      for ( i5 = 0; i5 < 15; ++i5 )
      {
        HIDWORD(v16) = a3 + i4;
        LODWORD(v16) = i5 + a2;
        AdvManager::drawAdventureMap(this, v16, i5, i4, 32, a4);
      }
    }
    sub_4564F0((int)this);
    mouseManager->couldBeShowMouse = 1;
    yieldToGlobalUpdater();
    if ( a5 )
      sub_44D440(this, 0, 1, 1);
    if ( dword_4F7470 )
    {
      this->viewX = *(_DWORD *)&this->_2[0];
      this->viewY = *(_DWORD *)&this->_2[4];
    }
  }
}

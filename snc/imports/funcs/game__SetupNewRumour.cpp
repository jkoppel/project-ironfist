{
  int v1; // ST80_4@4
  int v2; // ST7C_4@17
  int v3; // ecx@52
  signed int v5; // [sp+78h] [bp-9Ch]@31
  char playerIndices; // [sp+7Ch] [bp-98h]@18
  int playerStats; // [sp+84h] [bp-90h]@18
  int v8; // [sp+88h] [bp-8Ch]@18
  int v9; // [sp+9Ch] [bp-78h]@8
  int v10; // [sp+A0h] [bp-74h]@6
  int row; // [sp+108h] [bp-Ch]@18
  int v12; // [sp+10Ch] [bp-8h]@14
  int v13; // [sp+110h] [bp-4h]@3

  if ( *(_WORD *)&this->_10[346] && Random(0, 9) < *(_WORD *)&this->_10[346] )
  {
    v13 = 0;
    while ( 1 )
    {
      v1 = v13++;
      if ( v1 >= 200 )
        break;
      if ( (signed int)*(_WORD *)&this->_10[346] <= 1 )
        v10 = 0;
      else
        v10 = Random(0, *(_WORD *)&this->_10[346] - 1);
      v9 = *((_DWORD *)ppMapExtra + *(_WORD *)&this->_10[2 * v10 + 348]);
      if ( (unsigned int)strlen(v9 + 8) > 2 && *(_BYTE *)(v9 + 8) != 64 )
      {
        strcpy(&this->_10[45], (char *)(v9 + 8));
        *(_BYTE *)(v9 + 8) = 64;
        return;
      }
    }
  }
  if ( Random(0, 100) >= 30 )
  {
    v12 = Random(0, 100);
    if ( v12 < 80 && giCurTurn > 1 )
    {
      v13 = 0;
      while ( 1 )
      {
        v2 = v13++;
        if ( v2 >= 200 )
          break;
        row = Random(6, 9);
        GetCategoryStats(row, &playerStats, &playerIndices);
        SortStats(&playerStats, &playerIndices);
        if ( v8 != playerStats )
        {
          switch ( row )
          {
            case 6:
              sprintf(&this->_10[45], "%s has found the most obelisks.", &cPlayerNames[21 * playerIndices]);
              break;
            case 7:
              sprintf(&this->_10[45], "%s has found the most artifacts.", &cPlayerNames[21 * playerIndices]);
              break;
            case 8:
              sprintf(&this->_10[45], "%s has the most powerful forces.", &cPlayerNames[21 * playerIndices]);
              break;
            default:
              sprintf(&this->_10[45], "%s earns the most gold.", &cPlayerNames[21 * playerIndices]);
              break;
          }
          return;
        }
      }
    }
    row = Random(0, 100);
    if ( row >= 33 )
    {
      if ( row >= 66 )
      {
        if ( this->_10[26] == -1 )
          strcpy(
            &this->_10[45],
            (&cRandomTavernText)[4
                               * (((unsigned int)((unsigned __int64)(giCurTurn / 7) >> 32) ^ abs(giCurTurn / 7) & 7)
                                - ((unsigned __int64)(giCurTurn / 7) >> 32))]);
        else
          sprintf(&this->_10[45], "The ultimate artifact is really the %s.", gArtifactNames[this->_10[26]]);
      }
      else
      {
        v3 = advManager::GetCell(gpAdvManager, this->_10[24], this->_10[25])->tileType;
        sprintf(
          &this->_10[45],
          "The ultimate artifact may be found %s.",
          cRumourTerrainDescriptions[(unsigned __int8)giGroundToTerrain[v3]]);
      }
    }
    else
    {
      if ( (double)this->_10[24] >= (double)this->_1[682] * 0.33
        || (double)this->_10[24] >= (double)this->_1[683] * 0.33 )
      {
        if ( (double)this->_10[24] >= (double)this->_1[682] * 0.33
          || (double)this->_10[24] <= (double)this->_1[683] * 0.66 )
        {
          if ( (double)this->_10[24] >= (double)this->_1[682] * 0.33 )
          {
            if ( (double)this->_10[24] <= (double)this->_1[682] * 0.66
              || (double)this->_10[24] >= (double)this->_1[683] * 0.33 )
            {
              if ( (double)this->_10[24] <= (double)this->_1[682] * 0.66
                || (double)this->_10[24] <= (double)this->_1[683] * 0.66 )
              {
                if ( (double)this->_10[24] <= (double)this->_1[682] * 0.66 )
                {
                  if ( (double)this->_10[24] >= (double)this->_1[683] * 0.33 )
                  {
                    if ( (double)this->_10[24] <= (double)this->_1[683] * 0.66 )
                      v5 = 8;
                    else
                      v5 = 4;
                  }
                  else
                  {
                    v5 = 0;
                  }
                }
                else
                {
                  v5 = 2;
                }
              }
              else
              {
                v5 = 3;
              }
            }
            else
            {
              v5 = 1;
            }
          }
          else
          {
            v5 = 6;
          }
        }
        else
        {
          v5 = 5;
        }
      }
      else
      {
        v5 = 7;
      }
      sprintf(&this->_10[45], "The ultimate artifact may be found in the %s regions of the world.", cDirections[v5]);
    }
  }
  else
  {
    strcpy(
      &this->_10[45],
      (&cRandomTavernText)[4
                         * (((unsigned int)((unsigned __int64)(giCurTurn / 7) >> 32) ^ abs(giCurTurn / 7) & 7)
                          - ((unsigned __int64)(giCurTurn / 7) >> 32))]);
  }
}
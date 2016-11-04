{
  int v1; // ST80_4@4
  int result; // eax@10
  int v3; // ST7C_4@17
  int v4; // ecx@52
  int v5; // [sp+6Ch] [bp-A8h]@1
  signed int v6; // [sp+78h] [bp-9Ch]@31
  char playerIndices; // [sp+7Ch] [bp-98h]@18
  int playerStats; // [sp+84h] [bp-90h]@18
  int v9; // [sp+88h] [bp-8Ch]@18
  int v10; // [sp+9Ch] [bp-78h]@8
  int v11; // [sp+A0h] [bp-74h]@6
  int row; // [sp+108h] [bp-Ch]@18
  int v13; // [sp+10Ch] [bp-8h]@14
  int v14; // [sp+110h] [bp-4h]@3

  v5 = this;
  if ( *(_WORD *)(this + 25815) && unseededNextRand(0, 9) < *(_WORD *)(this + 25815) )
  {
    v14 = 0;
    while ( 1 )
    {
      v1 = v14++;
      if ( v1 >= 200 )
        break;
      if ( (signed int)*(_WORD *)(v5 + 25815) <= 1 )
        v11 = 0;
      else
        v11 = unseededNextRand(0, *(_WORD *)(v5 + 25815) - 1);
      v10 = *((_DWORD *)dword_524784 + *(_WORD *)(v5 + 2 * v11 + 25817));
      if ( strlen((const char *)(v10 + 8)) > 2 && *(_BYTE *)(v10 + 8) != 64 )
      {
        strcpy((char *)(v5 + 25514), (const char *)(v10 + 8));
        result = v10;
        *(_BYTE *)(v10 + 8) = 64;
        return result;
      }
    }
  }
  if ( unseededNextRand(0, 100) >= 30 )
  {
    v13 = unseededNextRand(0, 100);
    if ( v13 < 80 && dword_532C54 > 1 )
    {
      v14 = 0;
      while ( 1 )
      {
        v3 = v14++;
        if ( v3 >= 200 )
          break;
        row = unseededNextRand(6, 9);
        fetchPlayerStatsForThievesGuildRow(row, &playerStats, &playerIndices);
        sortPlayerStats(&playerStats, &playerIndices);
        if ( v9 != playerStats )
        {
          switch ( row )
          {
            case 6:
              result = sprintf(
                         (char *)(v5 + 25514),
                         "%s has found the most obelisks.",
                         &dword_5235E0[21 * playerIndices]);
              break;
            case 7:
              result = sprintf(
                         (char *)(v5 + 25514),
                         "%s has found the most artifacts.",
                         &dword_5235E0[21 * playerIndices]);
              break;
            case 8:
              result = sprintf(
                         (char *)(v5 + 25514),
                         "%s has the most powerful forces.",
                         &dword_5235E0[21 * playerIndices]);
              break;
            default:
              result = sprintf((char *)(v5 + 25514), "%s earns the most gold.", &dword_5235E0[21 * playerIndices]);
              break;
          }
          return result;
        }
      }
    }
    row = unseededNextRand(0, 100);
    if ( row >= 33 )
    {
      if ( row >= 66 )
      {
        if ( *(_BYTE *)(v5 + 25495) == -1 )
          result = (int)strcpy(
                          (char *)(v5 + 25514),
                          (&off_4F70A8)[4
                                      * (((unsigned int)((unsigned __int64)(dword_532C54 / 7) >> 32) ^ abs(dword_532C54 / 7) & 7)
                                       - ((unsigned __int64)(dword_532C54 / 7) >> 32))]);
        else
          result = sprintf(
                     (char *)(v5 + 25514),
                     "The ultimate artifact is really the %s.",
                     artifactNames[*(_BYTE *)(v5 + 25495)]);
      }
      else
      {
        v4 = *(_WORD *)usedToCheckForBoatByCastle(advManager, *(_BYTE *)(v5 + 25493), *(_BYTE *)(v5 + 25494));
        result = sprintf(
                   (char *)(v5 + 25514),
                   "The ultimate artifact may be found %s.",
                   off_4F6EF8[(unsigned __int8)tileToTerrainType[v4]]);
      }
    }
    else
    {
      if ( (double)*(_BYTE *)(v5 + 25493) >= (double)*(_BYTE *)(v5 + 687) * 0.33
        || (double)*(_BYTE *)(v5 + 25493) >= (double)*(_BYTE *)(v5 + 688) * 0.33 )
      {
        if ( (double)*(_BYTE *)(v5 + 25493) >= (double)*(_BYTE *)(v5 + 687) * 0.33
          || (double)*(_BYTE *)(v5 + 25493) <= (double)*(_BYTE *)(v5 + 688) * 0.66 )
        {
          if ( (double)*(_BYTE *)(v5 + 25493) >= (double)*(_BYTE *)(v5 + 687) * 0.33 )
          {
            if ( (double)*(_BYTE *)(v5 + 25493) <= (double)*(_BYTE *)(v5 + 687) * 0.66
              || (double)*(_BYTE *)(v5 + 25493) >= (double)*(_BYTE *)(v5 + 688) * 0.33 )
            {
              if ( (double)*(_BYTE *)(v5 + 25493) <= (double)*(_BYTE *)(v5 + 687) * 0.66
                || (double)*(_BYTE *)(v5 + 25493) <= (double)*(_BYTE *)(v5 + 688) * 0.66 )
              {
                if ( (double)*(_BYTE *)(v5 + 25493) <= (double)*(_BYTE *)(v5 + 687) * 0.66 )
                {
                  if ( (double)*(_BYTE *)(v5 + 25493) >= (double)*(_BYTE *)(v5 + 688) * 0.33 )
                  {
                    if ( (double)*(_BYTE *)(v5 + 25493) <= (double)*(_BYTE *)(v5 + 688) * 0.66 )
                      v6 = 8;
                    else
                      v6 = 4;
                  }
                  else
                  {
                    v6 = 0;
                  }
                }
                else
                {
                  v6 = 2;
                }
              }
              else
              {
                v6 = 3;
              }
            }
            else
            {
              v6 = 1;
            }
          }
          else
          {
            v6 = 6;
          }
        }
        else
        {
          v6 = 5;
        }
      }
      else
      {
        v6 = 7;
      }
      result = sprintf(
                 (char *)(v5 + 25514),
                 "The ultimate artifact may be found in the %s regions of the world.",
                 off_4F6ED0[v6]);
    }
  }
  else
  {
    result = (int)strcpy(
                    (char *)(v5 + 25514),
                    (&off_4F70A8)[4
                                * (((unsigned int)((unsigned __int64)(dword_532C54 / 7) >> 32) ^ abs(dword_532C54 / 7) & 7)
                                 - ((unsigned __int64)(dword_532C54 / 7) >> 32))]);
  }
  return result;
}

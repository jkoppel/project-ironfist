{
  int v4; // ST38_4@10
  int v5; // ST50_4@10
  signed int v6; // ST28_4@10
  void *thisa; // [sp+Ch] [bp-40h]@1
  int messageType; // [sp+10h] [bp-3Ch]@47
  int v9; // [sp+18h] [bp-34h]@10
  int i; // [sp+1Ch] [bp-30h]@8
  int row; // [sp+20h] [bp-2Ch]@8
  int col; // [sp+28h] [bp-24h]@8
  int v13; // [sp+30h] [bp-1Ch]@8
  signed __int16 v14; // [sp+34h] [bp-18h]@12
  int v15; // [sp+38h] [bp-14h]@10
  signed int v16; // [sp+40h] [bp-Ch]@1
  char *v17; // [sp+44h] [bp-8h]@4
  int v18; // [sp+48h] [bp-4h]@6

  thisa = this;
  v16 = 0;
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    if ( curPlayer->_1[0] == -1 )
    {
      sub_455030(this, a2, 0, 1);
    }
    else
    {
      v17 = (char *)&gameObject->heroes[curPlayer->_1[0]];
      if ( *(_DWORD *)&gameObject->heroes[curPlayer->_1[0]]._4[0] == -1 )
      {
        sub_455030(this, a2, 1, 1);
      }
      else
      {
        v18 = Pathfinder::doSomething6(
                pathfinder,
                gameObject->heroes[curPlayer->_1[0]].x,
                gameObject->heroes[curPlayer->_1[0]].y,
                *(_DWORD *)&gameObject->heroes[curPlayer->_1[0]]._4[0],
                *(_DWORD *)&gameObject->heroes[curPlayer->_1[0]]._4[4],
                59999);
        if ( pathfinder->field_8 <= 0 || v18 <= 0 )
        {
          sub_455030(thisa, a2, 1, 1);
        }
        else
        {
          memset(*(void **)((char *)thisa + 158), 0, 2 * mapHeight * mapWidth);
          *(_DWORD *)((char *)thisa + 162) = 1;
          v13 = *(_DWORD *)(v17 + 53);
          col = *(_DWORD *)(v17 + 25);
          row = *(_DWORD *)(v17 + 29);
          for ( i = pathfinder->field_8 - 1; i >= 0; --i )
          {
            v9 = *((_BYTE *)&pathfinder->field_2418 + i);
            v4 = usedToCheckForBoatByCastle((AdvManager *)thisa, col, row);
            col += byte_4F1DC0[4 * v9];
            row += byte_4F1DC1[4 * v9];
            v5 = usedToCheckForBoatByCastle((AdvManager *)thisa, col, row);
            v6 = (unsigned __int8)tileToTerrainType[*(_WORD *)v4];
            v15 = sub_464D00(
                    (unsigned __int8)tileToTerrainType[*(_WORD *)v5],
                    v9 & 1,
                    999999999,
                    v17[116],
                    (*(_BYTE *)(v4 + 2) >> 1) & 1,
                    (*(_BYTE *)(v5 + 2) >> 1) & 1);
            v13 -= sub_464D00(v6, v9 & 1, v13, v17[116], (*(_BYTE *)(v4 + 2) >> 1) & 1, (*(_BYTE *)(v5 + 2) >> 1) & 1);
            if ( v9 & 1 )
            {
              switch ( v15 )
              {
                case 112:
                  v14 = 0;
                  break;
                case 150:
                  v14 = 1;
                  break;
                case 187:
                  v14 = 2;
                  break;
                case 225:
                  v14 = 3;
                  break;
                case 262:
                  v14 = 4;
                  break;
                case 300:
                  v14 = 5;
                  break;
                default:
                  v14 = 1;
                  break;
              }
            }
            else
            {
              switch ( v15 )
              {
                case 75:
                  v14 = 0;
                  break;
                case 100:
                  v14 = 1;
                  break;
                case 125:
                  v14 = 2;
                  break;
                case 150:
                  v14 = 3;
                  break;
                case 175:
                  v14 = 4;
                  break;
                case 200:
                  v14 = 5;
                  break;
                default:
                  v14 = 1;
                  break;
              }
            }
            if ( i )
              *(_WORD *)(*(_DWORD *)((char *)thisa + 158) + 2 * (col + row * mapWidth)) = *(&byte_4F2AE8[8 * *((_BYTE *)&pathfinder->field_2414 + i + 3)]
                                                                                          + v9)
                                                                                        + 24 * v14
                                                                                        + 2;
            else
              *(_WORD *)(*(_DWORD *)((char *)thisa + 158) + 2 * (col + row * mapWidth)) = 1;
            if ( v13 >= 0 )
              v16 = 1;
            else
              *(_WORD *)(*(_DWORD *)((char *)thisa + 158) + 2 * (col + row * mapWidth)) += 256;
          }
          if ( a4 )
          {
            if ( v16 )
              messageType = 6;
            else
              messageType = 5;
            HeroWindowManager::sendMessage(HeroWindowManager::instance, INPUT_GUI_MESSAGE_CODE, messageType, 2, 16392);
          }
        }
        if ( a2 )
        {
          sub_448110((AdvManager *)thisa, 0);
          sub_447A00(thisa, 0, 0);
        }
      }
    }
  }
}

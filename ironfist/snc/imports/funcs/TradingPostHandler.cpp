{
  signed int result; // eax@44
  int v2; // [sp-1Ch] [bp-48h]@10
  int v3; // [sp-18h] [bp-44h]@10
  int v4; // [sp-14h] [bp-40h]@10
  int v5; // [sp-10h] [bp-3Ch]@10
  int v6; // [sp-Ch] [bp-38h]@10
  int v7; // [sp-8h] [bp-34h]@10
  int v8; // [sp-4h] [bp-30h]@10
  int v9; // [sp+Ch] [bp-20h]@20
  int v10; // [sp+10h] [bp-1Ch]@3
  int v11; // [sp+14h] [bp-18h]@2
  tag_message *v12; // [sp+18h] [bp-14h]@1
  int v13; // [sp+1Ch] [bp-10h]@1
  int v14; // [sp+20h] [bp-Ch]@11
  int v15; // [sp+24h] [bp-8h]@5
  int v16; // [sp+28h] [bp-4h]@1

  v12 = this;
  v16 = 0;
  v13 = 0;
  if ( this->eventCode == 512 )
  {
    v11 = v12->xCoordOrKeycode;
    if ( v11 == 12 )
    {
      v10 = v12->yCoord - 27;
      switch ( v10 )
      {
        case 0:
          if ( iMaxUnitsToTrade )
          {
            v15 = v12->altXCoord - tpX - 75;
            qtyToTrade = v15 * (iMaxUnitsToTrade + 1) / 187;
            if ( qtyToTrade < 0 )
              qtyToTrade = 0;
            if ( iMaxUnitsToTrade < qtyToTrade )
              qtyToTrade = iMaxUnitsToTrade;
            v13 = 1;
          }
          break;
        case 4:
          memcpy(&v2, v12, 0x1Cu);
          DoTradeKnob(v2, v3, v4, v5, v6, v7, v8);
          break;
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
          v14 = v12->yCoord - 70;
          if ( leftResource != v14 )
          {
            leftResource = v14;
            v13 = 1;
            SetupNewTrade();
          }
          break;
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
          v14 = v12->yCoord - 110;
          if ( rightResource != v14 )
          {
            rightResource = v14;
            v13 = 1;
            if ( leftResource != -1 )
              SetupNewTrade();
          }
          break;
        default:
          break;
      }
    }
    else if ( v11 == 13 )
    {
      v9 = v12->yCoord;
      if ( v9 <= 30722 )
      {
        switch ( v9 )
        {
          case 30722:
            v16 = 1;
            break;
          case 25:
            if ( qtyToTrade > 0 )
            {
              --qtyToTrade;
              v13 = 1;
            }
            break;
          case 26:
            if ( iMaxUnitsToTrade > qtyToTrade )
            {
              ++qtyToTrade;
              v13 = 1;
            }
            break;
          default:
            if ( v9 == 29 && qtyToTrade )
            {
              if ( bLeftDenominated )
              {
                gpCurPlayer->resources[leftResource] -= qtyToTrade;
                gpCurPlayer->resources[rightResource] += iTradeRatio * qtyToTrade;
              }
              else
              {
                gpCurPlayer->resources[leftResource] -= iTradeRatio * qtyToTrade;
                gpCurPlayer->resources[rightResource] += qtyToTrade;
              }
              bTradeMade = 1;
              rightResource = -1;
              leftResource = -1;
              v13 = 1;
            }
            break;
        }
      }
    }
  }
  if ( v13 )
    UpdateTradingPost((void *)1);
  if ( v16 )
  {
    v12->yCoord = 10;
    v12->xCoordOrKeycode = v12->yCoord;
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}
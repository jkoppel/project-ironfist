{
  int v2; // [sp+14h] [bp-1B4h]@1
  int evt; // [sp+24h] [bp-1A4h]@1
  int v4; // [sp+28h] [bp-1A0h]@5
  int v5; // [sp+2Ch] [bp-19Ch]@5
  int v6; // [sp+3Ch] [bp-18Ch]@5
  int i; // [sp+1B4h] [bp-14h]@3
  int v8; // [sp+1C4h] [bp-4h]@1

  v2 = this;
  evt = 512;
  v8 = 0;
  if ( *(_DWORD *)(this + 66) == 1 || *(_DWORD *)(this + 66) == 4 )
  {
    for ( i = 0; i < 5; ++i )
    {
      v4 = 4;
      v5 = i + 100;
      v6 = (i == dword_4EDE90) + 2 * i + 9;
      GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
    }
    if ( *(_DWORD *)(v2 + 1050) == -1 && *(_DWORD *)(v2 + 1042) > 0 )
      *(_DWORD *)(v2 + 1050) = 0;
    sub_40C570(v2, 1);
    v4 = 4;
    v5 = 82;
    switch ( *(_BYTE *)(420 * *(_DWORD *)(v2 + 1050) + *(_DWORD *)(v2 + 678) + 6) )
    {
      case 0x24:
        v6 = 26;
        break;
      case 0x48:
        v6 = 27;
        break;
      case 0x6C:
        v6 = 28;
        break;
      default:
        v6 = 29;
        break;
    }
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
    v5 = 81;
    v6 = *(_BYTE *)(420 * *(_DWORD *)(v2 + 1050) + *(_DWORD *)(v2 + 678) + 26) + 19;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
    v5 = 86;
    v6 = *(_BYTE *)(420 * *(_DWORD *)(v2 + 1050) + *(_DWORD *)(v2 + 678) + 29) + 30;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
    v5 = 87;
    v6 = *(_BYTE *)(420 * *(_DWORD *)(v2 + 1050) + *(_DWORD *)(v2 + 678) + 34) + 36;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
    v4 = 3;
    v6 = (int)globBuf;
    sprintf(globBuf, "%s", *(_DWORD *)(v2 + 678) + 420 * *(_DWORD *)(v2 + 1050) + 58);
    v5 = 80;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
    sprintf(globBuf, "%s", off_4F6928[*(_BYTE *)(420 * *(_DWORD *)(v2 + 1050) + *(_DWORD *)(v2 + 678) + 4)]);
    v5 = 84;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
    sprintf(globBuf, "%s", *(_DWORD *)(v2 + 678) + 420 * *(_DWORD *)(v2 + 1050) + 118);
    v5 = 85;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
  }
  for ( i = 0; i < dword_522BF4; ++i )
  {
    if ( i + *(_DWORD *)(v2 + 1046) < *(_DWORD *)(v2 + 1042) )
    {
      v5 = i + 20;
      v4 = 5;
      v6 = 4;
      GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
      if ( *(_DWORD *)(v2 + 66) == 4 || *(_DWORD *)(v2 + 66) == 1 )
      {
        v5 = i + 200;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
        v5 = i + 220;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
        v5 = i + 240;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
        v5 = i + 260;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
        v4 = 4;
        v5 = i + 200;
        switch ( *(_BYTE *)(420 * (i + *(_DWORD *)(v2 + 1046)) + *(_DWORD *)(v2 + 678) + 6) )
        {
          case 0x24:
            v6 = 26;
            break;
          case 0x48:
            v6 = 27;
            break;
          case 0x6C:
            v6 = 28;
            break;
          default:
            v6 = 29;
            break;
        }
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
        v5 = i + 220;
        v6 = *(_BYTE *)(420 * (i + *(_DWORD *)(v2 + 1046)) + *(_DWORD *)(v2 + 678) + 26) + 19;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
        v5 = i + 240;
        v6 = *(_BYTE *)(420 * (i + *(_DWORD *)(v2 + 1046)) + *(_DWORD *)(v2 + 678) + 29) + 30;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
        v5 = i + 260;
        v6 = *(_BYTE *)(420 * (i + *(_DWORD *)(v2 + 1046)) + *(_DWORD *)(v2 + 678) + 34) + 36;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
      }
      v4 = 3;
      if ( *(_DWORD *)(v2 + 66) != 4 && *(_DWORD *)(v2 + 66) != 1 )
        sprintf(globBuf, "%s", *(_DWORD *)(v2 + 670) + 351 * (i + *(_DWORD *)(v2 + 1046)));
      else
        sprintf(globBuf, "%s", *(_DWORD *)(v2 + 678) + 420 * (i + *(_DWORD *)(v2 + 1046)) + 58);
      v6 = (int)globBuf;
      v5 = i + 20;
      GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
    }
    else
    {
      v4 = 6;
      v6 = 4;
      v5 = i + 20;
      GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
      if ( *(_DWORD *)(v2 + 66) == 4 || *(_DWORD *)(v2 + 66) == 1 )
      {
        v5 = i + 200;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
        v5 = i + 220;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
        v5 = i + 240;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
        v5 = i + 260;
        GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
      }
    }
    v5 = i + 20;
    v4 = 8;
    if ( i + *(_DWORD *)(v2 + 1046) == *(_DWORD *)(v2 + 1050) )
      v6 = 2;
    else
      v6 = 1;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
  }
  v5 = 15;
  v4 = 5;
  v6 = 2;
  GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
  if ( *(_DWORD *)(v2 + 1050) != -1 )
  {
    v4 = 3;
    if ( *(_DWORD *)(v2 + 66) != 1 && *(_DWORD *)(v2 + 66) != 4 )
      sprintf(globBuf, "%s", *(_DWORD *)(v2 + 670) + 351 * *(_DWORD *)(v2 + 1050));
    else
      sprintf(globBuf, "%s", *(_DWORD *)(v2 + 678) + 420 * *(_DWORD *)(v2 + 1050) + 58);
    v6 = (int)globBuf;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
  }
  if ( *(_DWORD *)(v2 + 66) == 1 || *(_DWORD *)(v2 + 66) == 2 || *(_DWORD *)(v2 + 66) == 4 )
  {
    v4 = 6;
    v6 = 2;
    GUIWindow::processMessage(*(GUIWindow **)(v2 + 54), (Event *)&evt);
  }
  if ( *(_DWORD *)(v2 + 1042) > dword_522BF4 )
    *(_WORD *)(*(_DWORD *)(v2 + 1067) + 26) = (signed __int64)((double)*(signed int *)(v2 + 1046)
                                                             * (*(float *)&dword_522BF0
                                                              / (double)(*(_DWORD *)(v2 + 1042) - dword_522BF4))
                                                             + *(float *)&dword_522BEC);
  else
    *(_WORD *)(*(_DWORD *)(v2 + 1067) + 26) = (signed __int64)(*(float *)&dword_522BF0 / 2.0 + *(float *)&dword_522BEC);
  if ( a2 )
    GUIWindow::repaintComponentsInRange(*(GUIWindow **)(v2 + 54), 1, 0, 32767);
}

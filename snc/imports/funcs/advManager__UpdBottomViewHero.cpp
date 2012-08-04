{
  signed int result; // eax@3
  __int16 v2; // ST1C_2@36
  char *v3; // ST10_4@36
  __int16 v4; // bx@36
  __int16 v5; // ax@36
  textWidget *thisa; // [sp+10h] [bp-8Ch]@35
  iconWidget *v8; // [sp+14h] [bp-88h]@30
  iconWidget *v9; // [sp+18h] [bp-84h]@4
  char v10[41]; // [sp+1Ch] [bp-80h]@18
  ICNHeader *v11; // [sp+4Ch] [bp-50h]@21
  __int16 imgIdx[2]; // [sp+50h] [bp-4Ch]@17
  int v13; // [sp+54h] [bp-48h]@28
  int v14; // [sp+58h] [bp-44h]@28
  int v15; // [sp+5Ch] [bp-40h]@15
  int v16; // [sp+60h] [bp-3Ch]@21
  icon *res; // [sp+64h] [bp-38h]@15
  int v18; // [sp+6Ch] [bp-30h]@21
  char str[20]; // [sp+70h] [bp-2Ch]@18
  int i; // [sp+84h] [bp-18h]@9
  hero *v21; // [sp+88h] [bp-14h]@4
  int v22; // [sp+8Ch] [bp-10h]@21
  int v23; // [sp+90h] [bp-Ch]@21
  int v24; // [sp+94h] [bp-8h]@4
  int v25; // [sp+98h] [bp-4h]@30

  if ( gbForceUpdate || iCurBottomView != 3 )
  {
    advManager::ClearBottomView(this);
    iCurBottomView = 3;
    v21 = &gpGame->heroes[gpCurPlayer->curHeroIdx];
    v24 = 0;
    v9 = (iconWidget *)operator new(45);
    if ( v9 )
      this->someComponents[0][0] = (widget *)iconWidget::iconWidget(
                                               v9,
                                               480,
                                               392,
                                               143,
                                               71,
                                               "stonback.icn",
                                               0,
                                               0,
                                               2000,
                                               16,
                                               1);
    else
      this->someComponents[0][0] = 0;
    if ( !this->someComponents[0][0] )
      MemError();
    heroWindow::AddWidget(this->adventureScreen, this->someComponents[0][0], -1);
    for ( i = 0; i < 5; ++i )
    {
      if ( v21->army.creatureTypes[i] != -1 )
        ++v24;
    }
    if ( v24 )
    {
      v15 = 0;
      res = resourceManager::GetIcon(gpResourceManager, "mons32.icn");
      for ( i = 0; i < 5; ++i )
      {
        *(_DWORD *)imgIdx = v21->army.creatureTypes[i];
        if ( *(_DWORD *)imgIdx != -1 )
        {
          v10[0] = 50;
          v10[1] = 3;
          v10[2] = 96;
          v10[3] = 3;
          v10[4] = 50;
          v10[5] = 17;
          v10[6] = 73;
          v10[7] = 17;
          v10[8] = 96;
          v10[9] = 17;
          v10[10] = 27;
          v10[11] = 32;
          v10[12] = 73;
          v10[13] = 32;
          v10[14] = 119;
          v10[15] = 32;
          v10[16] = 3;
          v10[17] = -1;
          v10[18] = -1;
          v10[19] = -1;
          v10[20] = -1;
          v10[21] = 2;
          v10[22] = 4;
          v10[23] = -1;
          v10[24] = -1;
          v10[25] = -1;
          v10[26] = 0;
          v10[27] = 1;
          v10[28] = 6;
          v10[29] = -1;
          v10[30] = -1;
          v10[31] = 0;
          v10[32] = 1;
          v10[33] = 5;
          v10[34] = 6;
          v10[35] = -1;
          v10[36] = 0;
          v10[37] = 1;
          v10[38] = 5;
          v10[39] = 6;
          v10[40] = 7;
          *(_DWORD *)&str[4 * v15] = BaseAlloc(6u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F5A0 + 68);
          if ( v21->army.quantities[i] <= 1999 )
            sprintf(*(char **)&str[4 * v15], "%d", v21->army.quantities[i]);
          else
            sprintf(*(char **)&str[4 * v15], "%dk", v21->army.quantities[i] / 1000);
          v16 = *(&v10[5 * v24 + 11] + v15);
          v23 = (unsigned __int8)v10[2 * v16];
          v22 = (unsigned __int8)v10[2 * v16 + 1];
          v18 = v22 + 25;
          v11 = &res->headersAndImageData[*(_DWORD *)imgIdx];
          if ( v16 && v16 != 1 )
          {
            if ( v11->height < 37 )
              v22 += 37 - v11->height;
          }
          else
          {
            v18 -= 2;
            if ( v11->height < 35 )
              v22 += 35 - v11->height;
          }
          v13 = font::LineWidth(smallFont, *(const char **)&str[4 * v15]);
          v14 = v13 + v11->width;
          if ( v14 > 45 )
            v14 = 45;
          v23 -= (v14 + 1) / 2;
          v25 = v23 + v14 - 1 - (v13 - 1);
          v8 = (iconWidget *)operator new(45);
          if ( v8 )
            this->someComponents[0][v15 + 2] = (widget *)iconWidget::iconWidget(
                                                           v8,
                                                           v23 + 480,
                                                           v22 + 392,
                                                           32,
                                                           28,
                                                           "mons32.icn",
                                                           imgIdx[0],
                                                           0,
                                                           v15 + 2002,
                                                           16,
                                                           1);
          else
            this->someComponents[0][v15 + 2] = 0;
          if ( !this->someComponents[0][v15 + 2] )
            MemError();
          thisa = (textWidget *)operator new(43);
          if ( thisa )
          {
            v2 = v15 + 2101;
            v3 = *(char **)&str[4 * v15];
            v4 = v21->army.quantities[i] <= 1999 ? 0 : 4;
            v5 = strlen(*(_DWORD *)&str[4 * v15]);
            this->someComponents[1][v15 + 1] = (widget *)textWidget::textWidget(
                                                           thisa,
                                                           v25 + 480,
                                                           v18 + 392,
                                                           5 * v5 + v4,
                                                           12,
                                                           v3,
                                                           "smalfont.fnt",
                                                           1,
                                                           v2,
                                                           512,
                                                           1);
          }
          else
          {
            this->someComponents[1][v15 + 1] = 0;
          }
          if ( !this->someComponents[1][v15 + 1] )
            MemError();
          heroWindow::AddWidget(this->adventureScreen, this->someComponents[0][v15 + 2], -1);
          heroWindow::AddWidget(this->adventureScreen, this->someComponents[1][v15++ + 1], -1);
        }
      }
      resourceManager::Dispose(gpResourceManager, (resource *)res);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
{
  signed int result; // eax@3
  int v2; // ST24_4@11
  int v3; // eax@11
  textWidget *v5; // [sp+10h] [bp-28h]@25
  iconWidget *v6; // [sp+14h] [bp-24h]@20
  textWidget *thisa; // [sp+18h] [bp-20h]@11
  iconWidget *v8; // [sp+1Ch] [bp-1Ch]@4
  char *v9; // [sp+20h] [bp-18h]@25
  __int16 height; // [sp+24h] [bp-14h]@18
  int v11; // [sp+2Ch] [bp-Ch]@9
  signed int width; // [sp+30h] [bp-8h]@18
  char *content; // [sp+34h] [bp-4h]@11

  if ( gbForceUpdate || iCurBottomView != 5 )
  {
    advManager::ClearBottomView(this);
    iCurBottomView = 5;
    v8 = (iconWidget *)operator new(45);
    if ( v8 )
      this->someComponents[0][0] = (widget *)iconWidget::iconWidget(
                                               v8,
                                               480,
                                               392,
                                               159,
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
    LOWORD(v11) = 0;
    if ( *(_DWORD *)&giBottomViewResource < 0 )
      v11 = 32 - 6 * font::LineLength(smallFont, gcBottomViewText, 143);
    v2 = word_50F4C4 + 38;
    v3 = strlen((int)gcBottomViewText);
    content = (char *)BaseAlloc(v3 + 1, "F:\\h2xsrc\\Source\\ADVMGR.CPP", v2);
    sprintf(content, gcBottomViewText);
    thisa = (textWidget *)operator new(43);
    if ( thisa )
      this->someComponents[1][0] = (widget *)textWidget::textWidget(
                                               thisa,
                                               480,
                                               v11 + 398,
                                               143,
                                               36,
                                               content,
                                               "smalfont.fnt",
                                               1,
                                               2100,
                                               512,
                                               1);
    else
      this->someComponents[1][0] = 0;
    if ( !this->someComponents[1][0] )
      MemError();
    heroWindow::AddWidget(this->adventureScreen, this->someComponents[1][0], -1);
    if ( *(_DWORD *)&giBottomViewResource >= 0 )
    {
      if ( *(_DWORD *)&giBottomViewResource == 6 )
      {
        width = 76;
        height = 26;
      }
      else
      {
        width = 38;
        height = 32;
      }
      v6 = (iconWidget *)operator new(45);
      if ( v6 )
        this->someComponents[0][1] = (widget *)iconWidget::iconWidget(
                                                 v6,
                                                 (143 - width) / 2 + 480,
                                                 463 - height - 14,
                                                 width,
                                                 height,
                                                 "resource.icn",
                                                 giBottomViewResource,
                                                 0,
                                                 2001,
                                                 16,
                                                 1);
      else
        this->someComponents[0][1] = 0;
      if ( !this->someComponents[0][1] )
        MemError();
      heroWindow::AddWidget(this->adventureScreen, this->someComponents[0][1], -1);
      v9 = (char *)BaseAlloc(8u, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F4C4 + 80);
      sprintf(v9, "%d", giBottomViewResourceQty);
      v5 = (textWidget *)operator new(43);
      if ( v5 )
        this->someComponents[1][1] = (widget *)textWidget::textWidget(
                                                 v5,
                                                 511,
                                                 453,
                                                 80,
                                                 12,
                                                 v9,
                                                 "smalfont.fnt",
                                                 1,
                                                 2101,
                                                 512,
                                                 1);
      else
        this->someComponents[1][1] = 0;
      if ( !this->someComponents[1][1] )
        MemError();
      heroWindow::AddWidget(this->adventureScreen, this->someComponents[1][1], -1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
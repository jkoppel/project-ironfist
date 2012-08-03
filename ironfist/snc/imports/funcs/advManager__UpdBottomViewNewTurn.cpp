{
  signed int result; // eax@3
  textWidget *v3; // [sp+10h] [bp-20h]@24
  textWidget *thisa; // [sp+14h] [bp-1Ch]@19
  iconWidget *v5; // [sp+18h] [bp-18h]@14
  iconWidget *v6; // [sp+1Ch] [bp-14h]@9
  char *content; // [sp+20h] [bp-10h]@19
  char *v8; // [sp+24h] [bp-Ch]@24
  __int16 imgIdx; // [sp+2Ch] [bp-4h]@1

  imgIdx = 0;
  if ( gbForceUpdate || iCurBottomView != 1 )
  {
    advManager::ClearBottomView(this);
    iCurBottomView = 1;
    if ( gpGame->day == 1 && (gpGame->month != 1 || gpGame->week != 1 || gpGame->day != 1) )
      imgIdx = gpGame->week;
    v6 = (iconWidget *)operator new(45);
    if ( v6 )
      this->someComponents[0][0] = (widget *)iconWidget::iconWidget(
                                               v6,
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
    v5 = (iconWidget *)operator new(45);
    if ( v5 )
      this->someComponents[0][1] = (widget *)iconWidget::iconWidget(
                                               v5,
                                               480,
                                               392,
                                               143,
                                               71,
                                               "sunmoon.icn",
                                               imgIdx,
                                               0,
                                               2001,
                                               16,
                                               1);
    else
      this->someComponents[0][1] = 0;
    if ( !this->someComponents[0][1] )
      MemError();
    heroWindow::AddWidget(this->adventureScreen, this->someComponents[0][1], -1);
    content = (char *)BaseAlloc(0x1Eu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F424 + 41);
    sprintf(content, "%s: %d  %s: %d", "Month", gpGame->month, "Week", gpGame->week);
    thisa = (textWidget *)operator new(43);
    if ( thisa )
      this->someComponents[1][0] = (widget *)textWidget::textWidget(
                                               thisa,
                                               479,
                                               424,
                                               145,
                                               12,
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
    v8 = (char *)BaseAlloc(0x1Eu, "F:\\h2xsrc\\Source\\ADVMGR.CPP", word_50F424 + 67);
    sprintf(v8, "%s: %d", "Day", gpGame->day);
    v3 = (textWidget *)operator new(43);
    if ( v3 )
      this->someComponents[1][0] = (widget *)textWidget::textWidget(
                                               v3,
                                               479,
                                               438,
                                               145,
                                               25,
                                               v8,
                                               "bigfont.fnt",
                                               1,
                                               2100,
                                               512,
                                               1);
    else
      this->someComponents[1][0] = 0;
    if ( !this->someComponents[1][0] )
      MemError();
    heroWindow::AddWidget(this->adventureScreen, this->someComponents[1][0], -1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
{
  void *v2; // [sp+Ch] [bp-38h]@1
  iconWidget *v3; // [sp+10h] [bp-34h]@45
  iconWidget *v4; // [sp+14h] [bp-30h]@32
  iconWidget *v5; // [sp+18h] [bp-2Ch]@20
  iconWidget *v6; // [sp+1Ch] [bp-28h]@7
  iconWidget *thisa; // [sp+20h] [bp-24h]@2
  int evt; // [sp+24h] [bp-20h]@1
  int v9; // [sp+28h] [bp-1Ch]@19
  int v10; // [sp+2Ch] [bp-18h]@19
  int v11; // [sp+3Ch] [bp-8h]@19
  int v12; // [sp+40h] [bp-4h]@1

  v2 = this;
  v12 = 0;
  evt = 512;
  if ( iCurBottomView != 4 )
  {
    v12 = 1;
    gbForceUpdate = 1;
    advManager::ClearBottomView((advManager *)this);
    iCurBottomView = 4;
    thisa = (iconWidget *)operator new(45);
    if ( thisa )
      *(_DWORD *)((char *)v2 + 58) = iconWidget::iconWidget(thisa, 480, 392, 143, 71, "stonback.icn", 0, 0, 2000, 16, 1);
    else
      *(_DWORD *)((char *)v2 + 58) = 0;
    if ( !*(_DWORD *)((char *)v2 + 58) )
      MemError();
    heroWindow::AddWidget(*(heroWindow **)((char *)v2 + 154), *(widget **)((char *)v2 + 58), 1000);
    v6 = (iconWidget *)operator new(45);
    if ( v6 )
      *(_DWORD *)((char *)v2 + 62) = iconWidget::iconWidget(v6, 493, 403, 118, 51, "hourglas.icn", 0, 0, 2001, 16, 1);
    else
      *(_DWORD *)((char *)v2 + 62) = 0;
    if ( !*(_DWORD *)((char *)v2 + 62) )
      MemError();
    heroWindow::AddWidget(*(heroWindow **)((char *)v2 + 154), *(widget **)((char *)v2 + 62), 1010);
  }
  if ( gbForceUpdate || KBTickCount() - iLastSandAnimTime > 300 )
  {
    iLastSandAnimTime = KBTickCount();
    iLastAnimFrame = *(_DWORD *)((char *)v2 + 510);
    if ( KBTickCount() - iLastNewSandAnimTime > 300 )
    {
      iLastNewSandAnimTime = KBTickCount();
      ++iSandAnim;
      if ( iSandAnim >= 20 )
        iSandAnim = 16;
      v12 = 1;
      if ( *(_DWORD *)((char *)v2 + 70) )
      {
        v9 = 4;
        v10 = 2003;
        v11 = iSandAnim + 11;
        heroWindow::BroadcastMessage(*(heroWindow **)((char *)v2 + 154), (Event *)&evt);
      }
      else
      {
        v5 = (iconWidget *)operator new(45);
        if ( v5 )
          *(_DWORD *)((char *)v2 + 70) = iconWidget::iconWidget(
                                           v5,
                                           559,
                                           405,
                                           50,
                                           47,
                                           "hourglas.icn",
                                           iSandAnim + 11,
                                           0,
                                           2003,
                                           16,
                                           1);
        else
          *(_DWORD *)((char *)v2 + 70) = 0;
        if ( !*(_DWORD *)((char *)v2 + 70) )
          MemError();
        heroWindow::AddWidget(*(heroWindow **)((char *)v2 + 154), *(widget **)((char *)v2 + 70), 1020);
      }
    }
  }
  if ( gbForceUpdate || dword_50EAA4 != giCurPlayer )
  {
    v12 = 1;
    dword_50EAA4 = giCurPlayer;
    if ( giCurPlayer != giCurPlayer )
      LODWORD(iCurHourGlassPhase) = 0;
    if ( *(_DWORD *)((char *)v2 + 66) )
    {
      v9 = 4;
      v10 = 2002;
      v11 = gpGame->players[(char)giCurPlayer].color;
      heroWindow::BroadcastMessage(*(heroWindow **)((char *)v2 + 154), (Event *)&evt);
    }
    else
    {
      v4 = (iconWidget *)operator new(45);
      if ( v4 )
        *(_DWORD *)((char *)v2 + 66) = iconWidget::iconWidget(
                                         v4,
                                         495,
                                         405,
                                         50,
                                         47,
                                         "brcrest.icn",
                                         gpGame->players[(char)giCurPlayer].color,
                                         0,
                                         2002,
                                         16,
                                         1);
      else
        *(_DWORD *)((char *)v2 + 66) = 0;
      if ( !*(_DWORD *)((char *)v2 + 66) )
        MemError();
      heroWindow::AddWidget(*(heroWindow **)((char *)v2 + 154), *(widget **)((char *)v2 + 66), 1030);
    }
  }
  if ( gbForceUpdate
    || SHIDWORD(iCurHourGlassPhase) > (signed int)iCurHourGlassPhase
    || SHIDWORD(iCurHourGlassPhase) < 0
    || SHIDWORD(iCurHourGlassPhase) < (signed int)iCurHourGlassPhase && KBTickCount() - giLastHourGlassUpdateTime >= 700 )
  {
    v12 = 1;
    HIDWORD(iCurHourGlassPhase) = iCurHourGlassPhase;
    giLastHourGlassUpdateTime = KBTickCount();
    if ( *(_DWORD *)((char *)v2 + 74) )
    {
      v9 = 4;
      v10 = 2004;
      v11 = iCurHourGlassPhase + 1;
      heroWindow::BroadcastMessage(*(heroWindow **)((char *)v2 + 154), (Event *)&evt);
    }
    else
    {
      v3 = (iconWidget *)operator new(45);
      if ( v3 )
        *(_DWORD *)((char *)v2 + 74) = iconWidget::iconWidget(
                                         v3,
                                         559,
                                         405,
                                         50,
                                         47,
                                         "hourglas.icn",
                                         iCurHourGlassPhase + 1,
                                         0,
                                         2004,
                                         16,
                                         1);
      else
        *(_DWORD *)((char *)v2 + 74) = 0;
      if ( !*(_DWORD *)((char *)v2 + 74) )
        MemError();
      heroWindow::AddWidget(*(heroWindow **)((char *)v2 + 154), *(widget **)((char *)v2 + 74), 1040);
    }
  }
  return v12;
}
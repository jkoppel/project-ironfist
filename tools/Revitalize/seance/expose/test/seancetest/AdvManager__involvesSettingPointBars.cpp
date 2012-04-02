void __thiscall AdvManager::involvesSettingPointBars(AdvManager *this, int a2, int a3, int a4)
{
  int v4; // ST20_4@24
  int v5; // ST24_4@24
  AdvManager *v6; // [sp+Ch] [bp-3Ch]@1
  char *v7; // [sp+18h] [bp-30h]@21
  int v8; // [sp+1Ch] [bp-2Ch]@3
  GUIMessage evt; // [sp+20h] [bp-28h]@10
  int i; // [sp+3Ch] [bp-Ch]@4
  int v11; // [sp+40h] [bp-8h]@10
  signed int lowID; // [sp+44h] [bp-4h]@10

  v6 = this;
  if ( *(&byte_524758 + curPlayerIdx) )
  {
    if ( a2 != -1 )
      goto LABEL_30;
    v8 = curPlayer->_1[0];
    if ( v8 != -1 )
    {
      for ( i = 0; i < 4; ++i )
      {
        if ( *(&curPlayer->heroesOwned[i] + curPlayer->_1[1]) == v8 )
          a2 = i;
      }
      if ( a2 != -1 )
      {
LABEL_30:
        lowID = 7 * a2 + 100;
        evt.eventCode = INPUT_GUI_MESSAGE_CODE;
        v11 = *(&curPlayer->heroesOwned[a2] + curPlayer->_1[1]);
        evt.messageType = 8;
        evt.fieldID = 7 * a2 + 106;
        if ( curPlayer->_1[0] != v11 || curPlayer->_1[0] == -1 || dword_4F7470 )
          evt.payload = (void *)36;
        else
          evt.payload = (void *)153;
        GUIWindow::processMessage(this->adventureScreen, (Event *)&evt);
        if ( v11 == -1 || dword_4F7470 )
        {
          evt.fieldID = lowID + 5;
          evt.messageType = 4;
          evt.payload = (void *)(a2 + 1);
          GUIWindow::processMessage(v6->adventureScreen, (Event *)&evt);
          evt.messageType = 6;
          evt.payload = (void *)4;
          for ( i = 0; i <= 3; ++i )
          {
            evt.fieldID = lowID + i;
            GUIWindow::processMessage(v6->adventureScreen, (Event *)&evt);
          }
        }
        else
        {
          v7 = (char *)&gameObject->heroes[v11];
          evt.fieldID = lowID + 5;
          evt.messageType = 4;
          evt.payload = (void *)21;
          GUIWindow::processMessage(v6->adventureScreen, (Event *)&evt);
          evt.messageType = 5;
          evt.payload = (void *)6;
          for ( i = 0; i <= 6; ++i )
          {
            evt.fieldID = lowID + i;
            GUIWindow::processMessage(v6->adventureScreen, (Event *)&evt);
          }
          v4 = sub_4586A0(*(_DWORD *)(v7 + 53));
          evt.fieldID = lowID + 1;
          evt.messageType = 4;
          evt.payload = (void *)v4;
          GUIWindow::processMessage(v6->adventureScreen, (Event *)&evt);
          v5 = sub_458720(*(_WORD *)v7);
          evt.fieldID = lowID + 3;
          evt.messageType = 4;
          evt.payload = (void *)v5;
          GUIWindow::processMessage(v6->adventureScreen, (Event *)&evt);
          evt.fieldID = lowID + 2;
          evt.messageType = 4;
          evt.payload = (void *)(unsigned __int8)v7[24];
          GUIWindow::processMessage(v6->adventureScreen, (Event *)&evt);
        }
        if ( a3 )
        {
          GUIWindow::repaintComponentsInRange(v6->adventureScreen, 0, lowID, lowID + 6);
          if ( a4 )
            HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 481, 32 * a2 + 177, 0x36u, 30);
        }
      }
    }
  }
}

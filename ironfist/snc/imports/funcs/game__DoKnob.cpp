{
  void *v1; // [sp+1Ch] [bp-D0h]@1
  char v2; // [sp+20h] [bp-CCh]@21
  char v3; // [sp+3Ch] [bp-B0h]@20
  char v4; // [sp+58h] [bp-94h]@17
  tag_message a2; // [sp+74h] [bp-78h]@2
  int v6; // [sp+90h] [bp-5Ch]@18
  int v7; // [sp+94h] [bp-58h]@20
  int v8; // [sp+B0h] [bp-3Ch]@10
  float v9; // [sp+B4h] [bp-38h]@2
  int y; // [sp+B8h] [bp-34h]@2
  int v11; // [sp+BCh] [bp-30h]@2
  int v12; // [sp+C4h] [bp-28h]@6
  int x; // [sp+D8h] [bp-14h]@2
  float v14; // [sp+DCh] [bp-10h]@2
  int v15; // [sp+E0h] [bp-Ch]@2
  double v16; // [sp+E4h] [bp-8h]@2

  v1 = this;
  if ( giOverviewItems[giOverviewType] > 4 )
  {
    v14 = 304.0;
    v9 = 18.0;
    v15 = giOverviewTop[giOverviewType];
    v16 = 304.0 / (double)(giOverviewItems[giOverviewType] - 3);
    mouseManager::MouseCoords(&x, &y);
    inputManager::Flush(gpInputManager);
    memcpy(&v11, inputManager::GetEvent(gpInputManager, &a2), 0x1Cu);
    while ( v11 != 16 && v11 != 64 )
    {
      if ( v11 == 4 )
      {
        if ( (double)v12 < v9 )
          v12 = (signed __int64)v9;
        if ( (double)v12 > v9 + v14 - 1.0 )
          v12 = (signed __int64)(v9 + v14 - 1.0);
        (*(void (__thiscall **)(mouseManager *))(LODWORD(gpMouseManager->vtable) + 8))(gpMouseManager);
        OVScrollKnob->offsetY = v12 - 9;
        v8 = (signed __int64)(((double)OVScrollKnob->offsetY - v9) / v16);
        if ( v15 == v8 )
        {
          heroWindow::DrawWindow(overWin, 1, 0, 32767);
        }
        else
        {
          if ( giOverviewItems[giOverviewType] - 4 < v8 )
            v8 = giOverviewItems[giOverviewType] - 4;
          if ( v8 < 0 )
            v8 = 0;
          giOverviewTop[giOverviewType] = v8;
          OVScrollKnob->offsetY = v12 - 9;
          game::SetupDynamicStuff(v1, 1, 0, 0);
          v15 = v8;
        }
      }
      Process1WindowsMessage();
      memcpy(&v11, inputManager::GetEvent(gpInputManager, (tag_message *)&v4), 0x1Cu);
      if ( v11 == 4 )
      {
        v6 = 1;
        while ( v6 )
        {
          memcpy(&v7, inputManager::PeekEvent(gpInputManager, &v3), 0x1Cu);
          if ( v7 == 4 )
            memcpy(&v11, inputManager::GetEvent(gpInputManager, (tag_message *)&v2), 0x1Cu);
          else
            v6 = 0;
        }
      }
    }
    OVScrollKnob->field_16 &= 0xFFFEu;
    game::SetupDynamicStuff(v1, 0, 1, 0);
    heroWindow::DrawWindow(overWin, 0, 110, 111);
    heroWindowManager::UpdateScreenRegion(gpWindowManager, 627, 17, 0xBu, 322);
  }
}
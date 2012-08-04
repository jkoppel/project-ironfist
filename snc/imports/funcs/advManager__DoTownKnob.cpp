{
  void *v1; // [sp+14h] [bp-78h]@1
  char v2; // [sp+18h] [bp-74h]@14
  tag_message a2; // [sp+34h] [bp-58h]@1
  int v4; // [sp+50h] [bp-3Ch]@10
  int y; // [sp+54h] [bp-38h]@1
  int v6; // [sp+58h] [bp-34h]@1
  int v7; // [sp+60h] [bp-2Ch]@5
  int x; // [sp+74h] [bp-18h]@1
  int v9; // [sp+78h] [bp-14h]@1
  int v10; // [sp+7Ch] [bp-10h]@1
  int v11; // [sp+80h] [bp-Ch]@1
  double v12; // [sp+84h] [bp-8h]@1

  v1 = this;
  v11 = HIBYTE(gpCurPlayer->field_45);
  v10 = gpCurPlayer->numCastles;
  v12 = 73.0 / (double)(v10 - 4);
  mouseManager::MouseCoords(&x, &y);
  v9 = y - *(_WORD *)(*(_DWORD *)((char *)v1 + 182) + 26);
  inputManager::Flush(gpInputManager);
  memcpy(&v6, inputManager::GetEvent(gpInputManager, &a2), 0x1Cu);
  while ( v6 != 16 && v6 != 64 )
  {
    if ( v6 == 4 )
    {
      if ( v9 + 195 > v7 )
        v7 = v9 + 195;
      if ( v9 + 268 < v7 )
        v7 = v9 + 268;
      (*(void (__thiscall **)(mouseManager *))(LODWORD(gpMouseManager->vtable) + 8))(gpMouseManager);
      *(_WORD *)(*(_DWORD *)((char *)v1 + 182) + 26) = v7 - v9;
      heroWindow::DrawWindow(*(heroWindow **)((char *)v1 + 154));
      if ( v10 > 4 )
      {
        v4 = (signed __int64)((double)((signed int)*(_WORD *)(*(_DWORD *)((char *)v1 + 182) + 26) - 195) / v12);
        if ( v4 != v11 )
        {
          HIBYTE(gpCurPlayer->field_45) = v4;
          if ( v10 - 3 < v4 )
            v4 = v10 - 3;
          advManager::UpdateTownLocators(v1, 0, 1);
          *(_WORD *)(*(_DWORD *)((char *)v1 + 182) + 26) = v7 - v9;
          heroWindow::DrawWindow(*(heroWindow **)((char *)v1 + 154));
          v11 = v4;
        }
      }
    }
    Process1WindowsMessage();
    memcpy(&v6, inputManager::GetEvent(gpInputManager, (tag_message *)&v2), 0x1Cu);
  }
  *(_WORD *)(*(_DWORD *)((char *)v1 + 182) + 22) &= 0xFFFEu;
  advManager::UpdateTownLocators(v1, 1, 1);
}
{
  int v1; // [sp+2Ch] [bp-74h]@1
  char v2; // [sp+30h] [bp-70h]@19
  InputEvent a2; // [sp+4Ch] [bp-54h]@1
  int v4; // [sp+68h] [bp-38h]@10
  int y; // [sp+6Ch] [bp-34h]@1
  int v6; // [sp+70h] [bp-30h]@1
  int v7; // [sp+78h] [bp-28h]@5
  int x; // [sp+8Ch] [bp-14h]@1
  int v9; // [sp+90h] [bp-10h]@1
  int v10; // [sp+94h] [bp-Ch]@1
  double v11; // [sp+98h] [bp-8h]@1

  v1 = this;
  v10 = *(_DWORD *)(this + 1046);
  v11 = *(float *)&dword_522BF0 / (double)(*(_DWORD *)(this + 1042) - (dword_522BF4 - 1));
  retrieveVirtualCursorCoordinates(&x, &y);
  v9 = y - *(_WORD *)(*(_DWORD *)(v1 + 1067) + 26);
  InputManager::resetInfoFields(inputManager);
  memcpy(&v6, InputManager::nextInputEvent(inputManager, &a2), 0x1Cu);
  while ( v6 != 16 && v6 != 64 )
  {
    if ( v6 == 4 )
    {
      if ( (double)v7 < (double)v9 + *(float *)&dword_522BEC )
        v7 = (signed __int64)((double)v9 + *(float *)&dword_522BEC);
      if ( (double)v7 > (double)v9 + *(float *)&dword_522BEC + *(float *)&dword_522BF0 )
        v7 = (signed __int64)((double)v9 + *(float *)&dword_522BEC + *(float *)&dword_522BF0);
      (*(void (__thiscall **)(MouseManager *))(LODWORD(mouseManager->vtable) + 8))(mouseManager);
      *(_WORD *)(*(_DWORD *)(v1 + 1067) + 26) = v7 - v9;
      if ( *(_DWORD *)(v1 + 1042) <= dword_522BF4 )
      {
        GUIWindow::repaintComponentsInRange(*(GUIWindow **)(v1 + 54), 1, 0, 32767);
      }
      else
      {
        v4 = (signed __int64)(((double)*(_WORD *)(*(_DWORD *)(v1 + 1067) + 26) - *(float *)&dword_522BEC) / v11);
        if ( v4 == v10 )
        {
          GUIWindow::repaintComponentsInRange(*(GUIWindow **)(v1 + 54), 1, 0, 32767);
        }
        else
        {
          if ( *(_DWORD *)(v1 + 1042) - dword_522BF4 < v4 )
            v4 = *(_DWORD *)(v1 + 1042) - dword_522BF4;
          if ( v4 < 0 )
            v4 = 0;
          *(_DWORD *)(v1 + 1046) = v4;
          sub_40DA80(v1, 0);
          *(_WORD *)(*(_DWORD *)(v1 + 1067) + 26) = v7 - v9;
          GUIWindow::repaintComponentsInRange(*(GUIWindow **)(v1 + 54), 1, 0, 32767);
          v10 = v4;
        }
      }
    }
    passOnMessages();
    memcpy(&v6, InputManager::nextInputEvent(inputManager, (InputEvent *)&v2), 0x1Cu);
  }
  *(_WORD *)(*(_DWORD *)(v1 + 1067) + 22) &= 0xFFFEu;
  sub_40DA80(v1, 1);
}

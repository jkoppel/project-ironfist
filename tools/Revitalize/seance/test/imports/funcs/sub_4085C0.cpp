{
  int result; // eax@1
  int v2; // [sp+Ch] [bp-34h]@1
  int evt; // [sp+10h] [bp-30h]@1
  int v4; // [sp+14h] [bp-2Ch]@1
  int v5; // [sp+18h] [bp-28h]@1
  char *v6; // [sp+28h] [bp-18h]@1

  v2 = this;
  evt = 512;
  v4 = 3;
  sprintf(globBuf, "%s%d", "Available: ", **(_WORD **)(this + 106));
  v5 = 67;
  v6 = globBuf;
  GUIWindow::processMessage(*(GUIWindow **)(v2 + 82), (Event *)&evt);
  sprintf(globBuf, "%d", *(_DWORD *)(v2 + 122));
  v5 = 68;
  GUIWindow::processMessage(*(GUIWindow **)(v2 + 82), (Event *)&evt);
  *(_DWORD *)(v2 + 114) = *(_DWORD *)(v2 + 66) * *(_DWORD *)(v2 + 122);
  sprintf(globBuf, "%d", *(_DWORD *)(v2 + 114));
  v5 = 77;
  GUIWindow::processMessage(*(GUIWindow **)(v2 + 82), (Event *)&evt);
  result = v2;
  if ( *(_DWORD *)(v2 + 70) != -1 )
  {
    *(_DWORD *)(v2 + 118) = *(_DWORD *)(v2 + 74) * *(_DWORD *)(v2 + 122);
    sprintf(globBuf, "%d", *(_DWORD *)(v2 + 118));
    v5 = 79;
    result = GUIWindow::processMessage(*(GUIWindow **)(v2 + 82), (Event *)&evt);
  }
  return result;
}

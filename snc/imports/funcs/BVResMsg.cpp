{
  int v3; // ST18_4@1
  char *v4; // ST1C_4@1

  v3 = a2;
  v4 = (char *)a1;
  giBottomViewOverride = 5;
  giBottomViewOverrideEndTime = KBTickCount() + 5000;
  *(_DWORD *)&giBottomViewResource = v3;
  giBottomViewResourceQty = a3;
  strcpy(gcBottomViewText, v4);
  return advManager::UpdBottomView(gpAdvManager, 1, 1, 1);
}
{
  int v1; // ST1C_4@1

  v1 = this;
  strip::DrawIcons((strip *)this, 1);
  heroWindowManager::UpdateScreenRegion(gpWindowManager, *(_DWORD *)(v1 + 28), *(_DWORD *)(v1 + 32), 0x228u, 105);
}
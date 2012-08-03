{
  int v2; // ST1C_4@1
  int v3; // ST20_4@1

  v2 = giMapSizeFilter;
  giMapSizeFilter = a2;
  v3 = fileRequester::InitializeFiles(this, (int)((char *)this + 370), (int)((char *)this + 70), 1);
  giMapSizeFilter = v2;
  return v3 > 0;
}
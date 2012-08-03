{
  int v1; // ST18_4@1

  v1 = this;
  fileRequester::CleanUpData(this);
  *(_DWORD *)(v1 + 1042) = 0;
  *(_DWORD *)(v1 + 1046) = 0;
  *(_DWORD *)(v1 + 1054) = -2;
  *(_DWORD *)(v1 + 1050) = -1;
  return fileRequester::InitializeFiles((void *)v1, v1 + 370, v1 + 70, 0);
}
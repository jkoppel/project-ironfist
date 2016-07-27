{
  int v3; // ST18_4@1
  const char *v4; // ST1C_4@1

  v3 = a2;
  v4 = a1;
  dword_52405C = 5;
  dword_524798 = getTickCount() + 5000;
  *(_DWORD *)&a7 = v3;
  dword_5249E4 = a3;
  strcpy(byte_524A00, v4);
  return sub_44D440(advManager, 1, 1, 1);
}

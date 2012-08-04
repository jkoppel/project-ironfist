{
  unsigned int v2; // ST0C_4@1
  void *v3; // ST10_4@1

  v2 = a2;
  v3 = a1;
  putUChar(a1, BYTE3(a2));
  putUChar(v3, v2 >> 16);
  putUChar(v3, BYTE1(v2));
  return putUChar(v3, v2);
}
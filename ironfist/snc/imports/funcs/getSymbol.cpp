{
  int v2; // ST10_4@1
  int v3; // ST14_4@1

  v2 = a1;
  v3 = arithDecodeSymbol(a2, a1);
  updateModel(v2, v3);
  return v3;
}
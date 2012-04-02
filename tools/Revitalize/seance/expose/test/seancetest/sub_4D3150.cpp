int __fastcall sub_4D3150(void *a1, unsigned int a2)
{
  unsigned int v2; // ST0C_4@1
  void *v3; // ST10_4@1

  v2 = a2;
  v3 = a1;
  sub_4D30B0(a1, BYTE3(a2));
  sub_4D30B0(v3, v2 >> 16);
  sub_4D30B0(v3, BYTE1(v2));
  return sub_4D30B0(v3, v2);
}

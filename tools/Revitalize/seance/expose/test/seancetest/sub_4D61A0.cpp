int __thiscall sub_4D61A0(const char *this)
{
  int v1; // ST20_4@1
  void *v2; // ST24_4@1

  strcpy(byte_5353F8, this);
  strcpy(byte_534FF8, this);
  *(_DWORD *)&byte_534FF8[strlen(byte_534FF8)] = dword_520628;
  v1 = (int)fopen(byte_5353F8, "rb");
  v2 = fopen(byte_534FF8, "wb");
  *_errno() = 0;
  dword_534BE0 = (int)v2;
  sub_4D5960(v1, v2);
  dword_534BE0 = 0;
  return remove(byte_5353F8);
}

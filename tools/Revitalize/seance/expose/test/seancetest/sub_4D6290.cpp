void __thiscall sub_4D6290(const char *this)
{
  void *v1; // ST24_4@3
  int v2; // ST28_4@3

  strcpy(byte_5353F8, this);
  strcpy(byte_534FF8, this);
  if ( sub_4D6110(byte_5353F8) )
    *((_BYTE *)&dword_534FF4 + strlen(byte_534FF8) + 1) = 0;
  v1 = fopen(byte_5353F8, "rb");
  v2 = (int)fopen(byte_534FF8, "wb");
  *_errno() = 0;
  dword_534BE0 = v2;
  sub_4D5C10(v1, v2);
  dword_534BE0 = 0;
  if ( remove(byte_5353F8) )
    sub_4D5F60();
}

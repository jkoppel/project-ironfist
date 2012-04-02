int __cdecl setSBCS()
{
  int result; // eax@1

  result = 0;
  memset(&unk_521580, 0, 0x100u);
  *((_BYTE *)&unk_521580 + 256) = 0;
  dword_521690 = 0;
  dword_521684 = 0;
  dword_521688 = 0;
  *(&dword_521690 + 1) = 0;
  *(&dword_521690 + 2) = 0;
  return result;
}

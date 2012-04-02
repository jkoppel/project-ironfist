int __thiscall sub_4A9500(int this, char a2)
{
  int v2; // ST18_4@1
  int result; // eax@1

  v2 = this;
  memset((void *)(this + 2), 0, 0x147u);
  *(_BYTE *)(v2 + 2) = a2;
  *(_BYTE *)(v2 + 3) = a2;
  result = v2;
  *(_BYTE *)(v2 + 4) = -1;
  return result;
}

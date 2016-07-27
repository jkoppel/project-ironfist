{
  char result; // al@2
  int v2; // [sp+Ch] [bp-10h]@3
  int v3; // [sp+18h] [bp-4h]@1

  v3 = *(_BYTE *)(this + 9) & 0x7F;
  if ( v3 == 122 )
  {
    v2 = ((unsigned __int8)(*(_WORD *)(this + 4) >> 8) >> -5) & 0x3F;
    result = v2 >= 5 && v2 <= 6;
  }
  else
  {
    result = byte_4F3C78[v3];
  }
  return result;
}

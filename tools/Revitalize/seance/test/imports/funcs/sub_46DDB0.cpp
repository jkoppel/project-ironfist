{
  signed int result; // eax@3
  void *v2; // [sp+10h] [bp-DCh]@1
  size_t v3; // [sp+14h] [bp-D8h]@4
  char msg; // [sp+18h] [bp-D4h]@3
  int v5; // [sp+E0h] [bp-Ch]@1
  int v6; // [sp+E8h] [bp-4h]@4

  v2 = this;
  LOWORD(v5) = 0;
  if ( byte_526DC9 == dword_523F14 || byte_526DC9 == 127 )
  {
    v3 = (unsigned __int8)byte_526DCB;
    LOWORD(v6) = word_526DCC;
    word_526DCC = 0;
    sub_46DCF0((int)&v5, (int)byte_526DC8, (unsigned __int8)byte_526DCB + 6);
    if ( (unsigned __int16)v6 == (unsigned __int16)v5 )
    {
      memcpy(v2, &byte_526DC8[6], v3);
      result = 1;
    }
    else
    {
      sprintf(&msg, "CRC Check Failed CRC 1 %d CRC 2 %d\n", (unsigned __int16)v6, (unsigned __int16)v5);
      debugLog(&msg);
      result = 0;
    }
  }
  else
  {
    sprintf(&msg, "not mine %d\n", byte_526DC9);
    debugLog(&msg);
    result = 0;
  }
  return result;
}

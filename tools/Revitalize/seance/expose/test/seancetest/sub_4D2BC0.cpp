int __thiscall sub_4D2BC0(void *this)
{
  int result; // eax@3
  int v2; // [sp+Ch] [bp-4h]@1

  v2 = (int)this;
  while ( (unsigned int)dword_534FF4 <= 0x1000000 )
  {
    result = dword_534FF0 + dword_534FF4;
    if ( (unsigned int)(dword_534FF0 + dword_534FF4) > 0x2000000 )
    {
      if ( (unsigned int)dword_534FF0 < 0x2000000 )
      {
        ++dword_5347AC;
        dword_534FF0 -= 16777216;
      }
      else
      {
        result = sub_4D2A50(v2, 1);
        dword_534FF0 -= 33554432;
      }
    }
    else
    {
      result = sub_4D2A50(v2, 0);
    }
    dword_534FF0 *= 2;
    dword_534FF4 *= 2;
  }
  return result;
}

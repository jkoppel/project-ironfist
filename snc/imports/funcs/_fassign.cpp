{
  int result; // eax@2
  int v4; // ecx@2
  _CRT_DOUBLE Result; // [sp+0h] [bp-Ch]@2
  int v6; // [sp+8h] [bp-4h]@2

  if ( a1 )
  {
    sub_4E5170((int)((char *)&Result.x + 4), a3);
    result = HIDWORD(Result.x);
    v4 = v6;
    *(_DWORD *)a2 = HIDWORD(Result.x);
    *(_DWORD *)(a2 + 4) = v4;
  }
  else
  {
    result = _atodbl(&Result, (char *)a3);
    *(_DWORD *)a2 = (_DWORD)Result.x;
  }
  return result;
}
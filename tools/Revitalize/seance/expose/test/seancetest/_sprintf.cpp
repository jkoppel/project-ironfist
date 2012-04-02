int sprintf(char *a1, const char *a2, ...)
{
  int result; // eax@1
  int v3; // esi@1
  FILE v4; // [sp+4h] [bp-20h]@1
  va_list va; // [sp+30h] [bp+Ch]@1

  va_start(va, a2);
  v4._flag = 66;
  v4._base = a1;
  v4._ptr = a1;
  v4._cnt = 2147483647;
  result = _output(&v4, (int)a2, (int)va);
  v3 = result;
  --v4._cnt;
  if ( v4._cnt < 0 )
  {
    _flsbuf(0, &v4);
    result = v3;
  }
  else
  {
    *v4._ptr = 0;
    ++v4._ptr;
  }
  return result;
}

double __stdcall sqrt(double x)
{
  int v1; // ebp@0
  double result; // st7@1
  int v3; // [sp-4h] [bp-4h]@1

  v3 = v1;
  result = unknown_libname_32(COERCE_DOUBLE(__PAIR__(HIDWORD(x), LODWORD(x))));
  doNotDecompile();
  sub_4E0AC3((int)&v3, result);
  return result;
}

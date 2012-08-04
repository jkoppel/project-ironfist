{
  int v1; // ebp@0
  double result; // st7@1
  int v3; // [sp-4h] [bp-4h]@1

  v3 = v1;
  result = _fload(COERCE_DOUBLE(__PAIR__(HIDWORD(x), LODWORD(x))));
  _trandisp1();
  ctranexit((int)&v3, result);
  return result;
}
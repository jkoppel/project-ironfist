{
  double result; // st7@1

  _ST7 = a1;
  __asm { frndint }
  return result;
}

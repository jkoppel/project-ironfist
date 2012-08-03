{
  signed int result; // eax@2
  hero *thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  NormalDialog(byte_518DDC, 2, -1, -1, -1, 0, -1, 0, -1, 0);
  if ( gpWindowManager->buttonPressedCode == 30725 )
  {
    hero::Deallocate(thisa, 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
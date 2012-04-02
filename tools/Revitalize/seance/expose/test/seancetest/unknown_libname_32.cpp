// Microsoft VisualC 2-8/net runtime
double __cdecl unknown_libname_32(double a1)
{
  double v1; // ST06_8@2
  double result; // st7@2

  if ( (WORD3(a1) & 0x7FF0) == 32752 )
  {
    HIDWORD(v1) = *(_QWORD *)&a1 >> 21;
    LODWORD(v1) = LODWORD(a1);
    result = v1;
  }
  else
  {
    result = a1;
  }
  return result;
}

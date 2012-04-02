double __fastcall sub_4E27B5(__int16 a1)
{
  double result; // st7@2

  if ( !(_BYTE)a1 )
    JUMPOUT(unknown_libname_93);
  result = 3.141592653589793116;
  if ( HIBYTE(a1) )
    result = -3.141592653589793116;
  return result;
}

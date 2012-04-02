double __usercall sub_4E2740<st0>(long double a1<st1>, long double a2<st0>)
{
  char v2; // cl@1
  double result; // st7@1
  char v4; // ch@1

  sub_4E277C();
  result = atan2(a1, a2);
  if ( v4 )
    result = 3.141592653589793116 - result;
  if ( v2 )
    result = -result;
  return result;
}

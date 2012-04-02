// Microsoft VisualC 2-8/net runtime
double __usercall unknown_libname_75<st0>(double result<st0>)
{
  _ST6 = result;
  __asm { frndint }
  if ( _ST6 == result )
  {
    _ST5 = result * dbl_521422;
    __asm { frndint }
  }
  return result;
}

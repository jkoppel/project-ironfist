{
  __asm { fstp    st }
  if ( !(_BYTE)a1 )
    JUMPOUT(unknown_libname_93);
  __asm
  {
    fstp    st
    fldpi
  }
  if ( HIBYTE(a1) )
    __asm { fchs }
}
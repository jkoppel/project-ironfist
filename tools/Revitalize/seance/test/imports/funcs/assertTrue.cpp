{
  char *v3; // esi@1

  v3 = a2;
  if ( !a1 )
  {
    sub_4CEB90(mouseManager, 0);
    sub_49D030(0);
    sprintf(globBuf, "Assert statement failed in module %s, line %d.  Do you wish to abort the program?", v3, lineno);
    if ( MessageBoxA(windowHandle, globBuf, "Assert Failure", 0x14u) != 7 )
      terminate(0);
  }
}

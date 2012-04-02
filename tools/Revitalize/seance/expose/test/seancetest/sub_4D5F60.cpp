void __cdecl sub_4D5F60()
{
  sprintf(globBuf, "\n%s: I/O or other error, bailing out.  Possible reason follows.\n", dword_5357F8);
  debugLog(globBuf);
  perror(dword_5357F8);
  unknown_libname_25();
  unknown_libname_26();
}

void __cdecl sub_4D6030()
{
  sprintf(
    globBuf,
    "\n%s: read past the end of compressed data,\n\twhich probably means it is corrupted.\n",
    dword_5357F8);
  debugLog(globBuf);
  unknown_libname_25();
  unknown_libname_26();
}

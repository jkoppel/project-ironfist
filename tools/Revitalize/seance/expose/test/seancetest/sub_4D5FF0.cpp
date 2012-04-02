void __cdecl sub_4D5FF0()
{
  sprintf(
    globBuf,
    "\n%s: compressed file didn't unblock correctly,\n\twhich probably means it is corrupted.\n",
    dword_5357F8);
  debugLog(globBuf);
  unknown_libname_25();
  unknown_libname_26();
}

void __cdecl sub_4D5F10()
{
  sprintf(
    globBuf,
    "\n%s: Compressed file ends unexpectedly;\n\tperhaps it is corrupted?  *Possible* reason follows.\n",
    dword_5357F8);
  debugLog(globBuf);
  perror(dword_5357F8);
  unknown_libname_25();
  unknown_libname_26();
}

void __fastcall sub_4D60C0(int a1, int a2)
{
  sprintf(
    globBuf,
    "\n%s: Can't allocate enough memory for compression.\n\tRequested %d bytes for a block size of %d.\n\tReduce the block size, and/or use the -e flag.\n",
    dword_5357F8,
    a1,
    a2);
  debugLog(globBuf);
  unknown_libname_25();
  unknown_libname_26();
}

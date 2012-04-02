void __fastcall sub_4D6070(int a1, int a2)
{
  sprintf(
    globBuf,
    "\n%s: Can't allocate enough memory for decompression.\n\tRequested %d bytes for a block size of %d.\n\tFind a machine with more memory, perhaps?\n",
    dword_5357F8,
    a1,
    a2);
  debugLog(globBuf);
  unknown_libname_25();
  unknown_libname_26();
}

void __fastcall sub_4D5EC0(int a1, int a2)
{
  sprintf(
    globBuf,
    "\n%s: Data integrity error when decompressing.\n\tStored CRC = 0x%x, computed CRC = 0x%x\n\tThis could be a bug -- please report it to me at:\n\tsewardj@cs.man.ac.uk.\n",
    dword_5357F8,
    a1,
    a2);
  debugLog(globBuf);
  unknown_libname_25();
  unknown_libname_26();
}

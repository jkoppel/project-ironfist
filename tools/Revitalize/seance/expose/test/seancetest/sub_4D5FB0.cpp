void __cdecl sub_4D5FB0()
{
  sprintf(
    globBuf,
    "\n%s: block overrun during decompression,\n\twhich probably means the compressed file\n\tis corrupted.\n",
    dword_5357F8);
  debugLog(globBuf);
  unknown_libname_25();
  unknown_libname_26();
}

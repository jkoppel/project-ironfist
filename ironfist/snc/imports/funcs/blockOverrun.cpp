{
  sprintf(
    gText,
    "\n%s: block overrun during decompression,\n\twhich probably means the compressed file\n\tis corrupted.\n",
    progName);
  LogStr(gText);
  showFileNames();
  cleanUpAndFail();
}
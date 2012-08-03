{
  sprintf(
    gText,
    "\n%s: Can't allocate enough memory for compression.\n\tRequested %d bytes for a block size of %d.\n\tReduce the block size, and/or use the -e flag.\n",
    progName,
    a1,
    a2);
  LogStr(gText);
  showFileNames();
  cleanUpAndFail();
}
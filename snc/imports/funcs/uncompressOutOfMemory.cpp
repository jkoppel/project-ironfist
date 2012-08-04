{
  sprintf(
    gText,
    "\n%s: Can't allocate enough memory for decompression.\n\tRequested %d bytes for a block size of %d.\n\tFind a machine with more memory, perhaps?\n",
    progName,
    a1,
    a2);
  LogStr(gText);
  showFileNames();
  cleanUpAndFail();
}
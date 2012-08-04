{
  sprintf(
    gText,
    "\n%s: Data integrity error when decompressing.\n\tStored CRC = 0x%x, computed CRC = 0x%x\n\tThis could be a bug -- please report it to me at:\n\tsewardj@cs.man.ac.uk.\n",
    progName,
    a1,
    a2);
  LogStr(gText);
  showFileNames();
  cleanUpAndFail();
}
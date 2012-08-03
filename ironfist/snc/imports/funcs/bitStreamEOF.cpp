{
  sprintf(gText, "\n%s: read past the end of compressed data,\n\twhich probably means it is corrupted.\n", progName);
  LogStr(gText);
  showFileNames();
  cleanUpAndFail();
}
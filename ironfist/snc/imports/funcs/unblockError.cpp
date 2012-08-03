{
  sprintf(gText, "\n%s: compressed file didn't unblock correctly,\n\twhich probably means it is corrupted.\n", progName);
  LogStr(gText);
  showFileNames();
  cleanUpAndFail();
}
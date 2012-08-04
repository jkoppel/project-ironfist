{
  sprintf(gText, "\n%s: I/O or other error, bailing out.  Possible reason follows.\n", progName);
  LogStr(gText);
  perror(progName);
  showFileNames();
  cleanUpAndFail();
}
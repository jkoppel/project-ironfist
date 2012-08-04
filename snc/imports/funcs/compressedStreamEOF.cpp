{
  sprintf(
    gText,
    "\n%s: Compressed file ends unexpectedly;\n\tperhaps it is corrupted?  *Possible* reason follows.\n",
    progName);
  LogStr(gText);
  perror(progName);
  showFileNames();
  cleanUpAndFail();
}
{
  char *v2; // ST30_4@1

  v2 = (char *)a1;
  iLastActionTime = 0;
  iModemCommandPos = 0;
  giWaitType = 5;
  strcpy(cModemCommand, (char *)a2);
  NormalDialog(v2, 6, -1, -1, -1, 0, -1, 0, -1, 0);
  if ( !gbFunctionComplete )
    ShutDown(0);
}
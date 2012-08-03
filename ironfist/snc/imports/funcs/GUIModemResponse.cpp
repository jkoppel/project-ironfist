{
  char *v2; // ST2C_4@1
  char *v3; // ST30_4@1

  v2 = (char *)a2;
  v3 = (char *)a1;
  memset(&GUIMRresponse, 0, 0x50u);
  GUIMRrespptr = 0;
  strcpy(GUIMRresp, v2);
  giWaitType = 6;
  NormalDialog(v3, 6, -1, -1, -1, 0, -1, 0, -1, 0);
  if ( !gbFunctionComplete )
    ShutDown(0);
  return 0;
}
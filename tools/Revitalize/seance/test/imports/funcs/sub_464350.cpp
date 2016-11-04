{
  const char *v2; // ST2C_4@1
  char *v3; // ST30_4@1

  v2 = a2;
  v3 = (char *)a1;
  memset(&byte_526318, 0, 0x50u);
  dword_526300 = 0;
  strcpy(byte_5262B0, v2);
  dword_524750 = 6;
  display_message_window(v3, 6, -1, -1, -1, 0, -1, 0, -1, 0);
  if ( !dword_523018 )
    terminate(0);
  return 0;
}

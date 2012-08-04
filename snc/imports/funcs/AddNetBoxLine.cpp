{
  char result; // al@4
  char v3; // [sp+Ch] [bp-8h]@1
  char *a2a; // [sp+10h] [bp-4h]@1

  v3 = a2;
  a2a = (char *)a1;
  if ( a2 < 0 || a2 > 6 )
    v3 = 6;
  strcpy(cNetBoxLine, &cNetBoxLine[140]);
  strcpy(&cNetBoxLine[140], &cNetBoxLine[280]);
  strcpy(&cNetBoxLine[280], &cNetBoxLine[420]);
  strcpy(&cNetBoxLine[420], a2a);
  cNetBoxColor = byte_524C41;
  byte_524C41 = byte_524C42;
  byte_524C42 = byte_524C43;
  result = v3;
  byte_524C43 = v3;
  return result;
}
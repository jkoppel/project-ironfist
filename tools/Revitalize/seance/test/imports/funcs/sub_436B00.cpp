{
  char result; // al@4
  char v3; // [sp+Ch] [bp-8h]@1
  const char *v4; // [sp+10h] [bp-4h]@1

  v3 = a2;
  v4 = a1;
  if ( a2 < 0 || a2 > 6 )
    v3 = 6;
  strcpy(byte_524240, &byte_524240[140]);
  strcpy(&byte_524240[140], &byte_524240[280]);
  strcpy(&byte_524240[280], &byte_524240[420]);
  strcpy(&byte_524240[420], v4);
  byte_524C40 = byte_524C41;
  byte_524C41 = byte_524C42;
  byte_524C42 = byte_524C43;
  result = v3;
  byte_524C43 = v3;
  return result;
}

void __fastcall sub_4641B0(const char *a1, const char *a2)
{
  char *v2; // ST30_4@1

  v2 = (char *)a1;
  dword_52630C = 0;
  dword_526308 = 0;
  dword_524750 = 5;
  strcpy(byte_525268, a2);
  display_message_window(v2, 6, -1, -1, -1, 0, -1, 0, -1, 0);
  if ( !dword_523018 )
    terminate(0);
}

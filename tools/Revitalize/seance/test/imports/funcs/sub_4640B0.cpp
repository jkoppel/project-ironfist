{
  signed int result; // eax@2
  char v1; // [sp+Ch] [bp-28h]@1

  dword_525298 = 0;
  sprintf(&v1, "ATDT%s", &unk_525240);
  sprintf(globBuf, "%s %s", "Dialing...", &unk_525240);
  sub_4641B0(globBuf, &v1);
  sprintf(globBuf, "%s %s", "Dialing...", &unk_525240);
  if ( sub_464350(globBuf, "CONNECT") )
    result = 1;
  else
    result = 0;
  return result;
}

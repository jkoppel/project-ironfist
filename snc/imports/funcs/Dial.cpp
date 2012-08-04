{
  char v1; // [sp+Ch] [bp-28h]@1

  iLastDialPos = 0;
  sprintf(&v1, "ATDT%s", &numbuf);
  sprintf(gText, "%s %s", "Dialing...", &numbuf);
  GUIModemCommand(gText, &v1);
  sprintf(gText, "%s %s", "Dialing...", &numbuf);
  return GUIModemResponse(gText, "CONNECT") != 0;
}
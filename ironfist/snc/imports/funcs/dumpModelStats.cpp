{
  sprintf(gText, "model %s:\t scalings %d\n", *((_DWORD *)this + 6), *(_DWORD *)this);
  LogStr(gText);
}
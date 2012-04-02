void __thiscall sub_4D2F20(void *this)
{
  sprintf(globBuf, "model %s:\t scalings %d\n", *((_DWORD *)this + 6), *(_DWORD *)this);
  debugLog(globBuf);
}

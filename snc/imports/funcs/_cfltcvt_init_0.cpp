{
  void *(__cdecl *result)(int, int, int, int, int); // eax@1

  off_520D44 = _cropzeros;
  off_520D48[0] = (int (*)())_fassign;
  off_520D4C = (int (__cdecl *)(_DWORD))_forcdecpt;
  off_520D50[0] = (int (*)())_positive;
  result = _cfltcvt;
  _cfltcvt_tab = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_cfltcvt;
  off_520D54 = (int (*)())_cfltcvt;
  return result;
}
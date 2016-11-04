{
  int (__cdecl *result)(int, int, int, int, int); // eax@1

  off_520D44[0] = (int (*)())_cropzeros;
  off_520D48[0] = (int (*)())_fassign;
  off_520D4C[0] = (int (*)())_forcdecpt;
  off_520D50[0] = (int (*)())_positive;
  result = _cfltcvt;
  off_520D40[0] = (int (*)())_cfltcvt;
  off_520D54 = (int (*)())_cfltcvt;
  return result;
}

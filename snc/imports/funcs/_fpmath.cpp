{
  unsigned int result; // eax@1

  _cfltcvt_init_0();
  _adjust_fdiv = _ms_p5_mp_test_fdiv();
  result = _setdefaultprecision();
  __asm { fnclex }
  return result;
}
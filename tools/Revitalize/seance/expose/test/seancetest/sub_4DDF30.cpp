int __cdecl sub_4DDF30()
{
  int result; // eax@1

  _cfltcvt_init_0();
  dword_520B2C = _ms_p5_mp_test_fdiv();
  result = _setdefaultprecision();
  __asm { fnclex }
  return result;
}

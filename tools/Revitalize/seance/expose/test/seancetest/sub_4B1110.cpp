int __stdcall sub_4B1110(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int result; // eax@1

  *(_DWORD *)a3 = 1041865114;
  *(_DWORD *)a4 = 1058642330;
  *(_DWORD *)a5 = 3000;
  *(_DWORD *)a6 = (signed __int64)((double)*(signed int *)a5 * *(float *)a3);
  *(_DWORD *)a7 = 6;
  result = a8;
  *(float *)a8 = *(float *)a4 * *(float *)a3;
  return result;
}

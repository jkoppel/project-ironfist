int __usercall _clrfp<eax>(__int16 a1<fpstat>, char a2, char a3, char a4)
{
  __asm { fnclex }
  return a1;
}

void __usercall _alloca_probe(unsigned int a1<eax>, int a2)
{
  int *i; // ecx@1
  void *v3; // [sp+0h] [bp+0h]@3

  for ( i = &a2; a1 >= 0x1000; a1 -= 4096 )
    i -= 1024;
  JUMPOUT(__CS__, v3);
}

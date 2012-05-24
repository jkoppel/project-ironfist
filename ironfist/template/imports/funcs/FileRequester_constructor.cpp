{
  int thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  AbstractManager_constructor((AbstractManager *)this);
  *(_DWORD *)thisa = &FileRequester_vtable;
  strcpy((char *)(thisa + 70), a5);
  strcpy((char *)(thisa + 370), a6);
  *(_DWORD *)(thisa + 1050) = -1;
  *(_DWORD *)(thisa + 1042) = 0;
  *(_DWORD *)(thisa + 1046) = 0;
  *(_DWORD *)(thisa + 670) = 0;
  *(_DWORD *)(thisa + 674) = 0;
  *(_DWORD *)(thisa + 678) = 0;
  *(_DWORD *)(thisa + 58) = a2;
  *(_DWORD *)(thisa + 62) = a3;
  *(_DWORD *)(thisa + 66) = a4;
  strcpy((char *)(thisa + 686), a7);
  if ( a4 != 1 && a4 != 4 )
  {
    dword_522BF0 = 1126367232;
    dword_522BEC = 1116864512;
    dword_522BF4 = 11;
  }
  else
  {
    dword_522BF0 = 1123418112;
    dword_522BEC = 1116864512;
    dword_522BF4 = 9;
  }
  if ( !sub_40BEC0((void *)thisa, dword_4EDE90) )
    dword_4EDE90 = 4;
  sub_40B5B0((void *)thisa, thisa + 370, thisa + 70, 0);
  *(_DWORD *)(thisa + 1054) = -2;
  return thisa;
}

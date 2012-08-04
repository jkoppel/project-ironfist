{
  int thisa; // [sp+Ch] [bp-4h]@1

  thisa = this;
  baseManager::baseManager((baseManager *)this);
  *(_DWORD *)thisa = &fileRequester::_vftable_;
  strcpy((char *)(thisa + 70), (char *)a5);
  strcpy((char *)(thisa + 370), (char *)a6);
  *(_DWORD *)(thisa + 1050) = -1;
  *(_DWORD *)(thisa + 1042) = 0;
  *(_DWORD *)(thisa + 1046) = 0;
  *(_DWORD *)(thisa + 670) = 0;
  *(_DWORD *)(thisa + 674) = 0;
  *(_DWORD *)(thisa + 678) = 0;
  *(_DWORD *)(thisa + 58) = a2;
  *(_DWORD *)(thisa + 62) = a3;
  *(_DWORD *)(thisa + 66) = a4;
  strcpy((char *)(thisa + 686), (char *)a7);
  if ( a4 != 1 && a4 != 4 )
  {
    fGutterMinY = 1126367232;
    fGutterTravelLength = 1116864512;
    iMaxListSize = 11;
  }
  else
  {
    fGutterMinY = 1123418112;
    fGutterTravelLength = 1116864512;
    iMaxListSize = 9;
  }
  if ( !fileRequester::MapExistsForFilter((void *)thisa, giMapSizeFilter) )
    giMapSizeFilter = 4;
  fileRequester::InitializeFiles((void *)thisa, thisa + 370, thisa + 70, 0);
  *(_DWORD *)(thisa + 1054) = -2;
  return thisa;
}
{
  void *v1; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  v1 = this;
  for ( i = 0; i < 54; ++i )
  {
    *(_DWORD *)((char *)v1 + 250 * i + 10237) = unseededNextRand(0, 50) + 40;
    sub_4281E0(v1, i, 0);
    *(_DWORD *)((char *)v1 + 250 * i + 10233) = Hero::getStartingMovementPoints((Hero *)((char *)v1 + 250 * i + 10180));
    *(_DWORD *)((char *)v1 + 250 * i + 10229) = *(_DWORD *)((char *)v1 + 250 * i + 10233);
    *((_BYTE *)v1 + 250 * i + 10279) = unseededNextRand(1, 255);
    *((_BYTE *)v1 + 250 * i + 10280) = 1;
    switch ( *((_BYTE *)v1 + 250 * i + 10203) )
    {
      case 2:
        *((_BYTE *)v1 + 250 * i + 10342) = 1;
        break;
      case 3:
        *((_BYTE *)v1 + 250 * i + 10346) = 1;
        break;
      case 5:
        *((_BYTE *)v1 + 250 * i + 10337) = 1;
        break;
      case 4:
        *((_BYTE *)v1 + 250 * i + 10344) = 1;
        break;
    }
  }
}

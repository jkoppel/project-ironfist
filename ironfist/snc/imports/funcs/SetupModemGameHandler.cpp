{
  int v2; // [sp+Ch] [bp-Ch]@4
  void *v3; // [sp+10h] [bp-8h]@1
  signed int v4; // [sp+14h] [bp-4h]@4

  v3 = this;
  if ( *((_BYTE *)this + 13) & 2 && (*((_DWORD *)this + 1) == 12 || *((_DWORD *)this + 1) == 14) )
  {
    v4 = -1;
    v2 = *((_DWORD *)this + 2);
    if ( v2 <= 30721 )
    {
      switch ( v2 )
      {
        case 30721:
          v4 = 3;
          break;
        case 1:
          v4 = 0;
          break;
        case 2:
          v4 = 1;
          break;
        case 3:
          v4 = 2;
          break;
      }
    }
    if ( v4 >= 0 )
    {
      if ( gbDirectConnect )
        NormalDialog((&gSetupDCGameHelp)[4 * v4], 4, -1, -1, -1, 0, -1, 0, -1, 0);
      else
        NormalDialog((&gSetupModemGameHelp)[4 * v4], 4, -1, -1, -1, 0, -1, 0, -1, 0);
    }
  }
  return BaseSetupHandler(v3);
}
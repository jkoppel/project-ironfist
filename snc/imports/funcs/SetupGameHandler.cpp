{
  int v2; // [sp+14h] [bp-Ch]@4
  void *v3; // [sp+18h] [bp-8h]@1
  signed int v4; // [sp+1Ch] [bp-4h]@4

  v3 = this;
  if ( *((_BYTE *)this + 13) & 2 && (*((_DWORD *)this + 1) == 12 || *((_DWORD *)this + 1) == 14) )
  {
    v4 = -1;
    v2 = *((_DWORD *)this + 2);
    if ( v2 <= (CREATURE_PETRIFIED|CREATURE_BROWN|TWO_HEXER|0x1800) )
    {
      switch ( v2 )
      {
        case CREATURE_PETRIFIED|CREATURE_BROWN|TWO_HEXER|0x1800:
          v4 = 3;
          break;
        case TWO_HEXER:
          v4 = 0;
          break;
        case FLYER:
          v4 = 1;
          break;
        case FLYER|TWO_HEXER:
          v4 = 2;
          break;
      }
    }
    if ( v4 >= 0 )
      NormalDialog((&xSetupStandardGameHelp)[4 * v4], TRANSIENT_FOR_RIGHT_CLICKS, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  return BaseSetupHandler(v3);
}
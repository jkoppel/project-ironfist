{
  signed int v2; // [sp+14h] [bp-4h]@1

  v2 = 0;
  if ( *(_BYTE *)(this + 1125) )
  {
    switch ( *(_BYTE *)(this + 1125) )
    {
      case 1:
        v2 = 80;
        break;
      case 2:
        v2 = 100;
        break;
      case 3:
        v2 = 120;
        break;
      case 4:
        v2 = 140;
        break;
    }
  }
  else
  {
    v2 = 50;
  }
  if ( *(_BYTE *)(this + 685) )
  {
    switch ( *(_BYTE *)(this + 685) )
    {
      case 1:
        v2 += 20;
        break;
      case 2:
        v2 += 40;
        break;
      case 3:
        v2 += 80;
        break;
    }
  }
  return v2;
}

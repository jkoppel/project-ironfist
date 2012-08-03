{
  heroWindowManager *result; // eax@48

  if ( a2 )
  {
    switch ( a3 )
    {
      case 0:
        PlaySmacker(19);
        break;
      case 1:
        PlaySmacker(20);
        break;
      case 2:
        PlaySmacker(21);
        break;
      case 3:
        PlaySmacker(22);
        break;
      case 4:
        if ( *(_BYTE *)(this + 12 * *(_BYTE *)(this + 3) + 8) )
          PlaySmacker(24);
        else
          PlaySmacker(23);
        PlaySmacker(25);
        break;
      case 5:
        if ( *(_BYTE *)(this + 3) == 1 )
          PlaySmacker(26);
        else
          PlaySmacker(27);
        break;
      case 6:
        PlaySmacker(28);
        break;
      case 7:
        if ( *(_BYTE *)(this + 12 * *(_BYTE *)(this + 2) + 11) )
          PlaySmacker(30);
        else
          PlaySmacker(29);
        break;
      case 8:
        PlaySmacker(31);
        break;
      case 9:
        PlaySmacker(32);
        break;
      case 10:
        PlaySmacker(33);
        break;
      case 11:
      case 12:
        if ( *(_BYTE *)(this + 12 * *(_BYTE *)(this + 3) + 8) )
          PlaySmacker(24);
        else
          PlaySmacker(23);
        PlaySmacker(25);
        break;
      default:
        break;
    }
  }
  else
  {
    switch ( a3 )
    {
      case 0:
        PlaySmacker(5);
        break;
      case 1:
        PlaySmacker(6);
        break;
      case 2:
        PlaySmacker(7);
        break;
      case 3:
        if ( *(_BYTE *)(this + 12 * *(_BYTE *)(this + 3) + 7) )
          PlaySmacker(9);
        else
          PlaySmacker(8);
        break;
      case 4:
        PlaySmacker(10);
        break;
      case 5:
        if ( *(_BYTE *)(this + 3) )
          PlaySmacker(12);
        else
          PlaySmacker(11);
        break;
      case 6:
        PlaySmacker(13);
        break;
      case 7:
        PlaySmacker(14);
        break;
      case 8:
        PlaySmacker(15);
        break;
      case 9:
        PlaySmacker(16);
        break;
      case 11:
      case 12:
        PlaySmacker(10);
        break;
      default:
        break;
    }
  }
  result = gpWindowManager;
  gpWindowManager->field_56 = 1;
  return result;
}
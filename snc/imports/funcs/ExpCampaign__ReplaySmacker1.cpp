{
  int result; // eax@2

  result = *(_DWORD *)(this + 67);
  switch ( *(_DWORD *)(this + 67) )
  {
    case 0:
      result = PlaySmacker(39);
      break;
    case 1:
      result = PlaySmacker(40);
      break;
    case 2:
      result = PlaySmacker(41);
      break;
    case 3:
      result = PlaySmacker(41);
      break;
    case 4:
      result = PlaySmacker(42);
      break;
    case 5:
      result = PlaySmacker(43);
      break;
    case 6:
      result = PlaySmacker(44);
      break;
    case 7:
      if ( *(_BYTE *)(this + 26) )
        result = PlaySmacker(45);
      else
        result = PlaySmacker(44);
      break;
    default:
      return result;
  }
  return result;
}
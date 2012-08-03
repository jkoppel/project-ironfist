{
  int result; // eax@2

  result = *(_DWORD *)(this + 67);
  switch ( *(_DWORD *)(this + 67) )
  {
    case 0:
      result = PlaySmacker(47);
      break;
    case 1:
      result = PlaySmacker(48);
      break;
    case 2:
      result = PlaySmacker(49);
      break;
    case 3:
      result = PlaySmacker(49);
      break;
    case 4:
      result = PlaySmacker(50);
      break;
    case 5:
      result = PlaySmacker(51);
      break;
    case 6:
      result = PlaySmacker(51);
      break;
    case 7:
      result = PlaySmacker(52);
      break;
    default:
      return result;
  }
  return result;
}
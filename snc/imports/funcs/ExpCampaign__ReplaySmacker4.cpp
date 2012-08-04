{
  int result; // eax@2

  result = *(_DWORD *)(this + 67);
  switch ( *(_DWORD *)(this + 67) )
  {
    case 0:
      result = PlaySmacker(59);
      break;
    case 1:
      result = PlaySmacker(60);
      break;
    case 2:
      result = PlaySmacker(61);
      break;
    case 3:
      result = PlaySmacker(61);
      break;
    default:
      return result;
  }
  return result;
}
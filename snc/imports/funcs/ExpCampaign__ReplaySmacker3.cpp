{
  int result; // eax@2

  result = *(_DWORD *)(this + 67);
  switch ( *(_DWORD *)(this + 67) )
  {
    case 0:
      result = PlaySmacker(54);
      break;
    case 1:
      result = PlaySmacker(55);
      break;
    case 2:
      result = PlaySmacker(56);
      break;
    case 3:
      if ( *(_BYTE *)(this + 22) )
        result = PlaySmacker(57);
      else
        result = PlaySmacker(56);
      break;
    default:
      return result;
  }
  return result;
}
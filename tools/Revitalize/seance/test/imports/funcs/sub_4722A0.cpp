{
  int result; // eax@2

  result = *(_DWORD *)(this + 67);
  switch ( *(_DWORD *)(this + 67) )
  {
    case 0:
      result = sub_45A2A0(54);
      break;
    case 1:
      result = sub_45A2A0(55);
      break;
    case 2:
      result = sub_45A2A0(56);
      break;
    case 3:
      if ( *(_BYTE *)(this + 22) )
        result = sub_45A2A0(57);
      else
        result = sub_45A2A0(56);
      break;
    default:
      return result;
  }
  return result;
}

{
  int result; // eax@2

  result = *(_DWORD *)(this + 67);
  switch ( *(_DWORD *)(this + 67) )
  {
    case 0:
      result = sub_45A2A0(59);
      break;
    case 1:
      result = sub_45A2A0(60);
      break;
    case 2:
      result = sub_45A2A0(61);
      break;
    case 3:
      result = sub_45A2A0(61);
      break;
    default:
      return result;
  }
  return result;
}

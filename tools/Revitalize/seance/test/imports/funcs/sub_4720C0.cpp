{
  int result; // eax@2

  result = *(_DWORD *)(this + 67);
  switch ( *(_DWORD *)(this + 67) )
  {
    case 0:
      result = sub_45A2A0(39);
      break;
    case 1:
      result = sub_45A2A0(40);
      break;
    case 2:
      result = sub_45A2A0(41);
      break;
    case 3:
      result = sub_45A2A0(41);
      break;
    case 4:
      result = sub_45A2A0(42);
      break;
    case 5:
      result = sub_45A2A0(43);
      break;
    case 6:
      result = sub_45A2A0(44);
      break;
    case 7:
      if ( *(_BYTE *)(this + 26) )
        result = sub_45A2A0(45);
      else
        result = sub_45A2A0(44);
      break;
    default:
      return result;
  }
  return result;
}

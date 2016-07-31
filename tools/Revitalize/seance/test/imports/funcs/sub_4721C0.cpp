{
  int result; // eax@2

  result = *(_DWORD *)(this + 67);
  switch ( *(_DWORD *)(this + 67) )
  {
    case 0:
      result = sub_45A2A0(47);
      break;
    case 1:
      result = sub_45A2A0(48);
      break;
    case 2:
      result = sub_45A2A0(49);
      break;
    case 3:
      result = sub_45A2A0(49);
      break;
    case 4:
      result = sub_45A2A0(50);
      break;
    case 5:
      result = sub_45A2A0(51);
      break;
    case 6:
      result = sub_45A2A0(51);
      break;
    case 7:
      result = sub_45A2A0(52);
      break;
    default:
      return result;
  }
  return result;
}

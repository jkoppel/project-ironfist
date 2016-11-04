{
  signed int result; // eax@3

  if ( (unsigned int)(a1 - 932) > 0x12 )
  {
LABEL_3:
    result = 0;
  }
  else
  {
    switch ( a1 )
    {
      default:
        goto LABEL_3;
      case 932:
        result = 1041;
        break;
      case 936:
        result = 2052;
        break;
      case 949:
        result = 1042;
        break;
      case 950:
        result = 1028;
        break;
    }
  }
  return result;
}

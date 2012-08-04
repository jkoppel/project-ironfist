{
  int result; // eax@3

  if ( a1 <= 4 )
  {
    result = 9 * a1;
  }
  else
  {
    switch ( a1 )
    {
      case 5:
        result = 155;
        break;
      case 6:
        result = 146;
        break;
      case 7:
        result = 137;
        break;
      default:
        result = 0;
        break;
    }
  }
  return result;
}
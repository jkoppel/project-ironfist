{
  int v2; // eax@1
  __int16 v3; // ax@5
  int v4; // eax@5
  int v5; // ecx@7
  int v6; // ecx@7
  int v7; // eax@8

  v2 = evt->xCoordOrKeycode;
  if ( v2 >= 59 && v2 <= 68 || v2 == 87 || v2 == 88 )
  {
    v4 = this->keycodeRelated[v2];
  }
  else
  {
    v3 = this->keycodeRelated[v2];
    v4 = (unsigned __int8)v3;
  }
  v5 = evt->inputTypeBitmask;
  evt->xCoordOrKeycode = v4;
  v6 = v5 & 3;
  if ( !v6 )
  {
    v7 = evt->xCoordOrKeycode;
    if ( v7 > 64 )
    {
      if ( v7 < 91 )
        evt->xCoordOrKeycode = v7 + 32;
    }
  }
  if ( v6 )
  {
    switch ( evt->xCoordOrKeycode )
    {
      case '\'':
        evt->xCoordOrKeycode = '"';
        break;
      case ',':
        evt->xCoordOrKeycode = '<';
        break;
      case '-':
        evt->xCoordOrKeycode = '_';
        break;
      case '.':
        evt->xCoordOrKeycode = '>';
        break;
      case '/':
        evt->xCoordOrKeycode = '?';
        break;
      case '0':
        evt->xCoordOrKeycode = ')';
        break;
      case '1':
        evt->xCoordOrKeycode = '!';
        break;
      case '2':
        evt->xCoordOrKeycode = '@';
        break;
      case '3':
        evt->xCoordOrKeycode = '#';
        break;
      case '4':
        evt->xCoordOrKeycode = '$';
        break;
      case '5':
        evt->xCoordOrKeycode = '%';
        break;
      case '6':
        evt->xCoordOrKeycode = '^';
        break;
      case '7':
        evt->xCoordOrKeycode = '&';
        break;
      case '8':
        evt->xCoordOrKeycode = '*';
        break;
      case '9':
        evt->xCoordOrKeycode = '(';
        break;
      case ';':
        evt->xCoordOrKeycode = ':';
        break;
      case '=':
        evt->xCoordOrKeycode = '+';
        break;
      case '[':
        evt->xCoordOrKeycode = '{';
        break;
      case '\\':
        evt->xCoordOrKeycode = '|';
        break;
      case ']':
        evt->xCoordOrKeycode = '}';
        break;
      default:
        return;
    }
  }
}

{
  void *v1; // [sp+10h] [bp-260h]@1
  char thisa; // [sp+14h] [bp-25Ch]@22
  DWORD v3; // [sp+208h] [bp-68h]@1
  char a1; // [sp+20Ch] [bp-64h]@2

  v1 = this;
  v3 = GetLastError();
  switch ( v3 )
  {
    case 1u:
      strcpy(&a1, "ERROR_INVALID_FUNCTION    ");
      break;
    case 2u:
      strcpy(&a1, "ERROR_FILE_NOT_FOUND      ");
      break;
    case 3u:
      strcpy(&a1, "ERROR_PATH_NOT_FOUND      ");
      break;
    case 4u:
      strcpy(&a1, "ERROR_TOO_MANY_OPEN_FILES ");
      break;
    case 5u:
      strcpy(&a1, "ERROR_ACCESS_DENIED       ");
      break;
    case 6u:
      strcpy(&a1, "ERROR_INVALID_HANDLE      ");
      break;
    case 7u:
      strcpy(&a1, "ERROR_ARENA_TRASHED       ");
      break;
    case 8u:
      strcpy(&a1, "ERROR_NOT_ENOUGH_MEMORY   ");
      break;
    case 9u:
      strcpy(&a1, "ERROR_INVALID_BLOCK       ");
      break;
    case 0xAu:
      strcpy(&a1, "ERROR_BAD_ENVIRONMENT     ");
      break;
    case 0xBu:
      strcpy(&a1, "ERROR_BAD_FORMAT          ");
      break;
    case 0xCu:
      strcpy(&a1, "ERROR_INVALID_ACCESS      ");
      break;
    case 0xDu:
      strcpy(&a1, "ERROR_INVALID_DATA        ");
      break;
    case 0xFu:
      strcpy(&a1, "ERROR_INVALID_DRIVE       ");
      break;
    case 0x10u:
      strcpy(&a1, "ERROR_CURRENT_DIRECTORY   ");
      break;
    case 0x11u:
      strcpy(&a1, "ERROR_NOT_SAME_DEVICE     ");
      break;
    case 0x12u:
      strcpy(&a1, "ERROR_NO_MORE_FILES       ");
      break;
    case 0xB7u:
      strcpy(&a1, "ERROR_ALREADY_EXISTS      ");
      break;
    default:
      strcpy(&a1, "UNKNOWN_ERROR             ");
      break;
  }
  sprintf(&thisa, cWinComError, v1, v3, &a1);
  strcat(&thisa, off_4F6FAC);
  strcat(&thisa, off_4F6FB0);
  strcat(&thisa, off_4F6FB4);
  strcat(&thisa, off_4F6FB8);
  strcat(&thisa, off_4F6FBC);
  ShutDown(&thisa);
}
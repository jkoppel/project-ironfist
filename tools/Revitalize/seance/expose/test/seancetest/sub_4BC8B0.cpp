void __thiscall sub_4BC8B0(void *this)
{
  void *v1; // [sp+10h] [bp-260h]@1
  char thisa; // [sp+14h] [bp-25Ch]@22
  DWORD v3; // [sp+208h] [bp-68h]@1
  char v4; // [sp+20Ch] [bp-64h]@2

  v1 = this;
  v3 = GetLastError();
  switch ( v3 )
  {
    case 1u:
      strcpy(&v4, "ERROR_INVALID_FUNCTION    ");
      break;
    case 2u:
      strcpy(&v4, "ERROR_FILE_NOT_FOUND      ");
      break;
    case 3u:
      strcpy(&v4, "ERROR_PATH_NOT_FOUND      ");
      break;
    case 4u:
      strcpy(&v4, "ERROR_TOO_MANY_OPEN_FILES ");
      break;
    case 5u:
      strcpy(&v4, "ERROR_ACCESS_DENIED       ");
      break;
    case 6u:
      strcpy(&v4, "ERROR_INVALID_HANDLE      ");
      break;
    case 7u:
      strcpy(&v4, "ERROR_ARENA_TRASHED       ");
      break;
    case 8u:
      strcpy(&v4, "ERROR_NOT_ENOUGH_MEMORY   ");
      break;
    case 9u:
      strcpy(&v4, "ERROR_INVALID_BLOCK       ");
      break;
    case 0xAu:
      strcpy(&v4, "ERROR_BAD_ENVIRONMENT     ");
      break;
    case 0xBu:
      strcpy(&v4, "ERROR_BAD_FORMAT          ");
      break;
    case 0xCu:
      strcpy(&v4, "ERROR_INVALID_ACCESS      ");
      break;
    case 0xDu:
      strcpy(&v4, "ERROR_INVALID_DATA        ");
      break;
    case 0xFu:
      strcpy(&v4, "ERROR_INVALID_DRIVE       ");
      break;
    case 0x10u:
      strcpy(&v4, "ERROR_CURRENT_DIRECTORY   ");
      break;
    case 0x11u:
      strcpy(&v4, "ERROR_NOT_SAME_DEVICE     ");
      break;
    case 0x12u:
      strcpy(&v4, "ERROR_NO_MORE_FILES       ");
      break;
    case 0xB7u:
      strcpy(&v4, "ERROR_ALREADY_EXISTS      ");
      break;
    default:
      strcpy(&v4, "UNKNOWN_ERROR             ");
      break;
  }
  sprintf(&thisa, off_4F6FA8, v1, v3, &v4);
  strcat(&thisa, off_4F6FAC);
  strcat(&thisa, off_4F6FB0);
  strcat(&thisa, off_4F6FB4);
  strcat(&thisa, off_4F6FB8);
  strcat(&thisa, off_4F6FBC);
  terminate(&thisa);
}

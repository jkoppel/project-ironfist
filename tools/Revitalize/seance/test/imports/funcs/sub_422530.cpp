{
  signed int result; // eax@3
  signed int v2; // [sp+Ch] [bp-8h]@4

  if ( *(_DWORD *)this == 4 )
  {
    if ( HeroWindowManager::instance->field_5E == *(_DWORD *)(this + 8) )
    {
      result = 1;
    }
    else
    {
      HeroWindowManager::instance->field_5E = *(_DWORD *)(this + 8);
      v2 = *(_DWORD *)(this + 8);
      if ( v2 > 30720 )
      {
LABEL_11:
        strcpy(globBuf, off_4F64A4);
      }
      else
      {
        if ( v2 == 30720 )
        {
          strcpy(globBuf, off_4F64A0);
        }
        else
        {
          switch ( v2 )
          {
            case 2:
              strcpy(globBuf, off_4F6490);
              break;
            case 3:
              strcpy(globBuf, off_4F6494);
              break;
            case 4:
              strcpy(globBuf, off_4F6498);
              break;
            case 5:
              strcpy(globBuf, off_4F649C);
              break;
            case 6:
            case 7:
            case 8:
            case 9:
              sprintf(globBuf, off_4F64B0, dword_522FB0->spellpoints);
              break;
            default:
              goto LABEL_11;
          }
        }
      }
      sub_495160(globBuf);
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

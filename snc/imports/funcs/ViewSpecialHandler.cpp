{
  signed int result; // eax@3
  signed int v2; // [sp+Ch] [bp-8h]@4

  if ( *(_DWORD *)this == 4 )
  {
    if ( gpWindowManager->field_5E == *((_DWORD *)this + 2) )
    {
      result = 1;
    }
    else
    {
      gpWindowManager->field_5E = *((_DWORD *)this + 2);
      v2 = *((_DWORD *)this + 2);
      if ( v2 > 30720 )
      {
LABEL_11:
        strcpy(gText, off_4F64A4);
      }
      else if ( v2 == 30720 )
      {
        strcpy(gText, off_4F64A0);
      }
      else
      {
        switch ( v2 )
        {
          case 2:
            strcpy(gText, cSpellHelp);
            break;
          case 3:
            strcpy(gText, off_4F6494);
            break;
          case 4:
            strcpy(gText, off_4F6498);
            break;
          case 5:
            strcpy(gText, off_4F649C);
            break;
          case 6:
          case 7:
          case 8:
          case 9:
            sprintf(gText, off_4F64B0, viewSpellsHero->spellpoints);
            break;
          default:
            goto LABEL_11;
        }
      }
      HeroMessageUpdate(gText);
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}
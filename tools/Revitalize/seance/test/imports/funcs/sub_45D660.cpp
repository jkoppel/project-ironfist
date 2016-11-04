{
  signed int result; // eax@3
  char v2; // [sp+20h] [bp-70h]@24
  char v3; // [sp+8Ch] [bp-4h]@24

  if ( dword_5235D4 != 1 && dword_524778 != 2 )
  {
    switch ( *(_DWORD *)(a1 + 4) )
    {
      case 1:
        if ( dword_4F199C )
          strcpy(dword_524F34, byte_511444);
        goto LABEL_46;
      case 0x53:
        if ( strlen(dword_524F34) > dword_524F20 )
        {
          strcpy(globBuf, &dword_524F34[dword_524F20 + 1]);
          strcpy(&dword_524F34[dword_524F20], globBuf);
        }
        goto LABEL_46;
      case 0x4B:
        if ( dword_524F20 > 0 )
          --dword_524F20;
        goto LABEL_46;
      case 0x4D:
        if ( strlen(dword_524F34) > dword_524F20 )
          ++dword_524F20;
        goto LABEL_46;
      default:
        InputManager::stuffInvolvingNormalizingKeycode(inputManager, (InputEvent *)a1);
        if ( *(_DWORD *)(a1 + 4) == 10 )
        {
          result = 1;
        }
        else
        {
          if ( *(_DWORD *)(a1 + 4) == 127 )
          {
            if ( dword_524F20 > 0 )
            {
              strcpy(globBuf, &dword_524F34[dword_524F20]);
              strcpy(&dword_524F34[dword_524F20-- - 1], globBuf);
            }
          }
          else
          {
            if ( strlen(dword_524F34) + 1 < 0x64 && *(_DWORD *)(a1 + 4) )
            {
              strcpy(&v2, dword_524F34);
              v3 = 0;
              if ( *(_DWORD *)(a1 + 4) < 256 )
              {
                v3 = *(_BYTE *)(a1 + 4);
                if ( v3 == 123 || v3 == 125 )
                  v3 = 0;
              }
              else
              {
                switch ( *(_BYTE *)(a1 + 5) )
                {
                  case 0x52:
                    v3 = 48;
                    break;
                  case 0x4F:
                    v3 = 49;
                    break;
                  case 0x50:
                    v3 = 50;
                    break;
                  case 0x51:
                    v3 = 51;
                    break;
                  case 0x4B:
                    v3 = 52;
                    break;
                  case 0x4C:
                    v3 = 53;
                    break;
                  case 0x4D:
                    v3 = 54;
                    break;
                  case 0x47:
                    v3 = 55;
                    break;
                  case 0x48:
                    v3 = 56;
                    break;
                  case 0x49:
                    v3 = 57;
                    break;
                  default:
                    break;
                }
              }
              if ( v3 )
              {
                strcpy(globBuf, dword_524F34);
                globBuf[dword_524F20] = v3;
                globBuf[dword_524F20 + 1] = 0;
                strcat(globBuf, &dword_524F34[dword_524F20]);
                strcpy(dword_524F34, globBuf);
                ++dword_524F20;
                sub_45DA80(dword_524F34, dword_524F20);
                if ( Font::numLinesNeededToDisplay(smallFont, dword_524F3C, 348) > 1 )
                {
                  strcpy(dword_524F34, &v2);
                  --dword_524F20;
                }
              }
            }
          }
LABEL_46:
          sub_45DBA0(1);
          result = 0;
        }
        break;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

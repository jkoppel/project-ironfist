{
  signed int result; // eax@3
  char a2; // [sp+20h] [bp-70h]@24
  char v3; // [sp+8Ch] [bp-4h]@24
  int evt; // [sp+98h] [bp+8h]@24

  if ( iLastMsgNumHumanPlayers != 1 && iMPBaseType != 2 )
  {
    switch ( *(_DWORD *)(a1 + 4) )
    {
      case 1:
        if ( gbAllowTextEntryEscape )
          strcpy(cNGKPCore, byte_511444);
        goto LABEL_46;
      case 0x53:
        if ( strlen((int)cNGKPCore) > (unsigned int)NGKPcursorIndex )
        {
          strcpy(gText, &cNGKPCore[NGKPcursorIndex + 1]);
          strcpy(&cNGKPCore[NGKPcursorIndex], gText);
        }
        goto LABEL_46;
      case 0x4B:
        if ( NGKPcursorIndex > 0 )
          --NGKPcursorIndex;
        goto LABEL_46;
      case 0x4D:
        if ( strlen((int)cNGKPCore) > (unsigned int)NGKPcursorIndex )
          ++NGKPcursorIndex;
        goto LABEL_46;
      default:
        inputManager::AsciiConvert(gpInputManager, (tag_message *)a1);
        if ( *(_DWORD *)(a1 + 4) == 10 )
        {
          result = 1;
        }
        else
        {
          if ( *(_DWORD *)(a1 + 4) == 127 )
          {
            if ( NGKPcursorIndex > 0 )
            {
              strcpy(gText, &cNGKPCore[NGKPcursorIndex]);
              strcpy(&cNGKPCore[NGKPcursorIndex-- - 1], gText);
            }
          }
          else if ( (unsigned int)(strlen((int)cNGKPCore) + 1) < 0x64 && *(_DWORD *)(a1 + 4) )
          {
            strcpy(&a2, cNGKPCore);
            v3 = 0;
            if ( *(_DWORD *)(evt + 4) < 256 )
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
              strcpy(gText, cNGKPCore);
              gText[NGKPcursorIndex] = v3;
              gText[NGKPcursorIndex + 1] = 0;
              strcat(gText, &cNGKPCore[NGKPcursorIndex]);
              strcpy(cNGKPCore, gText);
              ++NGKPcursorIndex;
              game::NGKPSetupDisplayString(cNGKPCore, NGKPcursorIndex);
              if ( font::LineLength(smallFont, cNGKPDisplay, 348) > 1 )
              {
                strcpy(cNGKPCore, &a2);
                --NGKPcursorIndex;
              }
            }
          }
LABEL_46:
          game::DrawNGKPDisplayString(1);
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
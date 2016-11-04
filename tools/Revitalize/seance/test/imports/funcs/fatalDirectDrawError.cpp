{
  char *filea; // [sp+10h] [bp-D8h]@1
  MACRO_DDERR errorCodea; // [sp+14h] [bp-D4h]@1
  char errorStr[200]; // [sp+18h] [bp-D0h]@3
  int v6; // [sp+E0h] [bp-8h]@2
  int v7; // [sp+E4h] [bp-4h]@2

  filea = file;
  errorCodea = errorCode;
  if ( !directDrawErrorFound )
  {
    directDrawErrorFound = 1;
    v6 = ((int (__cdecl *)(LPDIRECTDRAW *))(*directDrawObject)[19].lpVtbl)(directDrawObject);
    v7 = 0;
    if ( errorCodea > DDERR_GENERIC )
    {
      if ( errorCodea > DDERR_INVALIDPARAMS )
      {
        if ( errorCodea > DDERR_INVALIDCLIPLIST )
        {
          if ( errorCodea > DDERR_INVALIDRECT )
          {
            if ( errorCodea > DDERR_NOALPHAHW )
            {
              if ( errorCodea > DDERR_NOEXCLUSIVEMODE )
              {
                if ( errorCodea > DDERR_NORASTEROPHW )
                {
                  if ( errorCodea > DDERR_NOSTRETCHHW )
                  {
                    if ( errorCodea > DDERR_NOZBUFFERHW )
                    {
                      if ( errorCodea > DDERR_SURFACELOST )
                      {
                        if ( errorCodea <= DDERR_WRONGMODE )
                        {
                          if ( errorCodea == DDERR_WRONGMODE )
                          {
                            strcpy(errorStr, "DDERR_WRONGMODE          ");
                          }
                          else
                          {
                            switch ( errorCodea + 2005532105 )
                            {
                              case 8:
                                strcpy(errorStr, "DDERR_NOBLTHW\t         ");
                                break;
                              case 9:
                                strcpy(errorStr, "DDERR_NODDROPSHW\t      ");
                                break;
                              case 0:
                                strcpy(errorStr, "DDERR_CLIPPERISUSINGHWND ");
                                break;
                              case 5:
                                strcpy(errorStr, "DDERR_NOPALETTEATTACHED  ");
                                break;
                              case 6:
                                strcpy(errorStr, "DDERR_NOPALETTEHW\t      ");
                                break;
                              case 1:
                                strcpy(errorStr, "DDERR_NOCLIPPERATTACHED  ");
                                break;
                              default:
                                goto LABEL_31;
                            }
                          }
                          goto LABEL_78;
                        }
                        if ( errorCodea != -2005532084 )
                        {
                          if ( !errorCodea )
                            return;
                          goto LABEL_31;
                        }
                        strcpy(errorStr, "DDERR_IMPLICITLYCREATED  ");
                      }
                      else
                      {
                        if ( errorCodea == DDERR_SURFACELOST )
                        {
                          strcpy(errorStr, "DDERR_SURFACELOST        ");
                        }
                        else
                        {
                          if ( errorCodea != DDERR_SURFACEBUSY )
                            goto LABEL_31;
                          strcpy(errorStr, "DDERR_SURFACEBUSY        ");
                        }
                      }
                    }
                    else
                    {
                      if ( errorCodea == DDERR_NOZBUFFERHW )
                      {
                        strcpy(errorStr, "DDERR_NOZBUFFERHW        ");
                      }
                      else
                      {
                        if ( errorCodea != -2005532352 )
                          goto LABEL_31;
                        strcpy(errorStr, "DDERR_NOT8BITCOLOR       ");
                      }
                    }
                  }
                  else
                  {
                    if ( errorCodea == DDERR_NOSTRETCHHW )
                    {
                      strcpy(errorStr, "DDERR_NOSTRETCHHW\t      ");
                    }
                    else
                    {
                      if ( errorCodea != -2005532382 )
                        goto LABEL_31;
                      strcpy(errorStr, "DDERR_NOROTATIONHW       ");
                    }
                  }
                }
                else
                {
                  if ( errorCodea == DDERR_NORASTEROPHW )
                  {
                    strcpy(errorStr, "DDERR_NORASTEROPHW\t      ");
                  }
                  else
                  {
                    if ( errorCodea != -2005532422 )
                      goto LABEL_31;
                    strcpy(errorStr, "DDERR_NOMIRRORHW         ");
                  }
                }
              }
              else
              {
                if ( errorCodea == DDERR_NOEXCLUSIVEMODE )
                {
                  strcpy(errorStr, "DDERR_NOEXCLUSIVEMODE\t   ");
                }
                else
                {
                  if ( errorCodea != -2005532467 )
                    goto LABEL_31;
                  strcpy(errorStr, "DDERR_NOCLIPLIST         ");
                }
              }
            }
            else
            {
              if ( errorCodea == DDERR_NOALPHAHW )
              {
                strcpy(errorStr, "DDERR_NOALPHAHW          ");
              }
              else
              {
                if ( errorCodea != DDERR_LOCKEDSURFACES )
                  goto LABEL_31;
                strcpy(errorStr, "DDERR_LOCKEDSURFACES     ");
              }
            }
          }
          else
          {
            if ( errorCodea == DDERR_INVALIDRECT )
            {
              strcpy(errorStr, "DDERR_INVALIDRECT\t      ");
            }
            else
            {
              if ( errorCodea != DDERR_INVALIDOBJECT )
                goto LABEL_31;
              strcpy(errorStr, "DDERR_INVALIDOBJECT      ");
            }
          }
        }
        else
        {
          if ( errorCodea == DDERR_INVALIDCLIPLIST )
          {
            strcpy(errorStr, "DDERR_INVALIDCLIPLIST\t   ");
          }
          else
          {
            if ( errorCodea != DDERR_INCOMPATIBLEPRIMARY )
              goto LABEL_31;
            strcpy(errorStr, "DDERR_INCOMPATIBLEPRIMARY");
          }
        }
      }
      else
      {
        if ( errorCodea == DDERR_INVALIDPARAMS )
        {
          strcpy(errorStr, "DDERR_INVALIDPARAMS\t   ");
        }
        else
        {
          if ( errorCodea != DDERR_OUTOFMEMORY )
            goto LABEL_31;
          strcpy(errorStr, "DDERR_OUTOFMEMORY\t      ");
        }
      }
    }
    else
    {
      if ( errorCodea == DDERR_GENERIC )
      {
        strcpy(errorStr, "DDERR_GENERIC            ");
      }
      else
      {
        if ( errorCodea != -2147467263 )
        {
LABEL_31:
          strcpy(errorStr, "Error type unknown");
          goto LABEL_78;
        }
        strcpy(errorStr, "DDERR_UNSUPPORTED\t      ");
      }
    }
LABEL_78:
    MessageBeep(MB_OK);
    MessageBeep(MB_OK);
    MessageBeep(MB_OK);
    sprintf(globBuf, "DirectDraw Error:\n\n  '%s'\n\n  File: '%s'\n  Line: %d", errorStr, filea, lineno);
    debugLog(globBuf);
    terminate(globBuf);
  }
}

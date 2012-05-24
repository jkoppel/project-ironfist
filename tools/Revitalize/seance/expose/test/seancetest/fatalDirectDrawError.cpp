void __fastcall fatalDirectDrawError(MACRO_DDERR errorCode, char *file, int lineno)
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
                            strcpy((int)errorStr);
                          }
                          else
                          {
                            switch ( errorCodea + 2005532105 )
                            {
                              case 8:
                                strcpy((int)errorStr);
                                break;
                              case 9:
                                strcpy((int)errorStr);
                                break;
                              case 0:
                                strcpy((int)errorStr);
                                break;
                              case 5:
                                strcpy((int)errorStr);
                                break;
                              case 6:
                                strcpy((int)errorStr);
                                break;
                              case 1:
                                strcpy((int)errorStr);
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
                        strcpy((int)errorStr);
                      }
                      else
                      {
                        if ( errorCodea == DDERR_SURFACELOST )
                        {
                          strcpy((int)errorStr);
                        }
                        else
                        {
                          if ( errorCodea != DDERR_SURFACEBUSY )
                            goto LABEL_31;
                          strcpy((int)errorStr);
                        }
                      }
                    }
                    else
                    {
                      if ( errorCodea == DDERR_NOZBUFFERHW )
                      {
                        strcpy((int)errorStr);
                      }
                      else
                      {
                        if ( errorCodea != -2005532352 )
                          goto LABEL_31;
                        strcpy((int)errorStr);
                      }
                    }
                  }
                  else
                  {
                    if ( errorCodea == DDERR_NOSTRETCHHW )
                    {
                      strcpy((int)errorStr);
                    }
                    else
                    {
                      if ( errorCodea != -2005532382 )
                        goto LABEL_31;
                      strcpy((int)errorStr);
                    }
                  }
                }
                else
                {
                  if ( errorCodea == DDERR_NORASTEROPHW )
                  {
                    strcpy((int)errorStr);
                  }
                  else
                  {
                    if ( errorCodea != -2005532422 )
                      goto LABEL_31;
                    strcpy((int)errorStr);
                  }
                }
              }
              else
              {
                if ( errorCodea == DDERR_NOEXCLUSIVEMODE )
                {
                  strcpy((int)errorStr);
                }
                else
                {
                  if ( errorCodea != -2005532467 )
                    goto LABEL_31;
                  strcpy((int)errorStr);
                }
              }
            }
            else
            {
              if ( errorCodea == DDERR_NOALPHAHW )
              {
                strcpy((int)errorStr);
              }
              else
              {
                if ( errorCodea != DDERR_LOCKEDSURFACES )
                  goto LABEL_31;
                strcpy((int)errorStr);
              }
            }
          }
          else
          {
            if ( errorCodea == DDERR_INVALIDRECT )
            {
              strcpy((int)errorStr);
            }
            else
            {
              if ( errorCodea != DDERR_INVALIDOBJECT )
                goto LABEL_31;
              strcpy((int)errorStr);
            }
          }
        }
        else
        {
          if ( errorCodea == DDERR_INVALIDCLIPLIST )
          {
            strcpy((int)errorStr);
          }
          else
          {
            if ( errorCodea != DDERR_INCOMPATIBLEPRIMARY )
              goto LABEL_31;
            strcpy((int)errorStr);
          }
        }
      }
      else
      {
        if ( errorCodea == DDERR_INVALIDPARAMS )
        {
          strcpy((int)errorStr);
        }
        else
        {
          if ( errorCodea != DDERR_OUTOFMEMORY )
            goto LABEL_31;
          strcpy((int)errorStr);
        }
      }
    }
    else
    {
      if ( errorCodea == DDERR_GENERIC )
      {
        strcpy((int)errorStr);
      }
      else
      {
        if ( errorCodea != -2147467263 )
        {
LABEL_31:
          strcpy((int)errorStr);
          goto LABEL_78;
        }
        strcpy((int)errorStr);
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

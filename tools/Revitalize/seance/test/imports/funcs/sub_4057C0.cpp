{
  int v3; // [sp+10h] [bp-D4h]@1
  char v4; // [sp+18h] [bp-CCh]@3
  int v5; // [sp+E0h] [bp-4h]@2

  v3 = a2;
  if ( !dword_4ED30C )
  {
    dword_4ED30C = 1;
    v5 = 0;
    if ( a1 > -2147467259 )
    {
      if ( a1 > -2147024809 )
      {
        if ( a1 > -2005467126 )
        {
          if ( a1 > -2005467106 )
          {
            if ( a1 > -2005467086 )
            {
              if ( a1 > -2005467066 )
              {
                if ( a1 > -2005467046 )
                {
                  if ( a1 > -2005467006 )
                  {
                    if ( a1 > -2005466976 )
                    {
                      if ( a1 > -2005466946 )
                      {
                        if ( a1 > -2005466926 )
                        {
                          if ( a1 > -2005466906 )
                          {
                            if ( a1 > -2005466886 )
                            {
                              if ( a1 == -2005466866 )
                              {
                                strcpy(&v4, "DPERR_BUSY               ");
                              }
                              else
                              {
                                if ( a1 != -2005466856 )
                                {
                                  if ( !a1 )
                                    return;
                                  goto LABEL_31;
                                }
                                strcpy(&v4, "DPERR_USERCANCEL         ");
                              }
                            }
                            else
                            {
                              if ( a1 == -2005466886 )
                              {
                                strcpy(&v4, "DPERR_UNAVAILABLE        ");
                              }
                              else
                              {
                                if ( a1 != -2005466896 )
                                  goto LABEL_31;
                                strcpy(&v4, "DPERR_TIMEOUT            ");
                              }
                            }
                          }
                          else
                          {
                            if ( a1 == -2005466906 )
                            {
                              strcpy(&v4, "DPERR_SENDTOOBIG         ");
                            }
                            else
                            {
                              if ( a1 != -2005466916 )
                                goto LABEL_31;
                              strcpy(&v4, "DPERR_NOSESSIONS         ");
                            }
                          }
                        }
                        else
                        {
                          if ( a1 == -2005466926 )
                          {
                            strcpy(&v4, "DPERR_NOPLAYERS          ");
                          }
                          else
                          {
                            if ( a1 != -2005466936 )
                              goto LABEL_31;
                            strcpy(&v4, "DPERR_NONAMESERVERFOUND  ");
                          }
                        }
                      }
                      else
                      {
                        if ( a1 == -2005466946 )
                        {
                          strcpy(&v4, "DPERR_NOMESSAGES         ");
                        }
                        else
                        {
                          if ( a1 != -2005466966 )
                            goto LABEL_31;
                          strcpy(&v4, "DPERR_NOCONNECTION       ");
                        }
                      }
                    }
                    else
                    {
                      if ( a1 == -2005466976 )
                      {
                        strcpy(&v4, "DPERR_NOCAPS             ");
                      }
                      else
                      {
                        if ( a1 != -2005466986 )
                          goto LABEL_31;
                        strcpy(&v4, "DPERR_INVALIDPLAYER      ");
                      }
                    }
                  }
                  else
                  {
                    if ( a1 == -2005467006 )
                    {
                      strcpy(&v4, "DPERR_INVALIDOBJECT      ");
                    }
                    else
                    {
                      if ( a1 != -2005467016 )
                        goto LABEL_31;
                      strcpy(&v4, "DPERR_INVALIDFLAGS       ");
                    }
                  }
                }
                else
                {
                  if ( a1 == -2005467046 )
                  {
                    strcpy(&v4, "DPERR_EXCEPTION          ");
                  }
                  else
                  {
                    if ( a1 != -2005467056 )
                      goto LABEL_31;
                    strcpy(&v4, "DPERR_CAPSNOTAVAILABLEYET");
                  }
                }
              }
              else
              {
                if ( a1 == -2005467066 )
                {
                  strcpy(&v4, "DPERR_CANTCREATESESSION  ");
                }
                else
                {
                  if ( a1 != -2005467076 )
                    goto LABEL_31;
                  strcpy(&v4, "DPERR_CANTCREATEPLAYER   ");
                }
              }
            }
            else
            {
              if ( a1 == -2005467086 )
              {
                strcpy(&v4, "DPERR_CANTCREATEGROUP    ");
              }
              else
              {
                if ( a1 != -2005467096 )
                  goto LABEL_31;
                strcpy(&v4, "DPERR_CANTADDPLAYER      ");
              }
            }
          }
          else
          {
            if ( a1 == -2005467106 )
            {
              strcpy(&v4, "DPERR_BUFFERTOOSMALL     ");
            }
            else
            {
              if ( a1 != -2005467116 )
                goto LABEL_31;
              strcpy(&v4, "DPERR_ACTIVEPLAYERS      ");
            }
          }
        }
        else
        {
          if ( a1 == -2005467126 )
          {
            strcpy(&v4, "DPERR_ACCESSDENIED       ");
          }
          else
          {
            if ( a1 != -2005467131 )
              goto LABEL_31;
            strcpy(&v4, "DPERR_ALREADYINITIALIZED ");
          }
        }
      }
      else
      {
        if ( a1 == -2147024809 )
        {
          strcpy(&v4, "DPERR_INVALIDPARAMS      ");
        }
        else
        {
          if ( a1 != -2147024882 )
            goto LABEL_31;
          strcpy(&v4, "DPERR_OUTOFMEMORY        ");
        }
      }
    }
    else
    {
      if ( a1 == -2147467259 )
      {
        strcpy(&v4, "DPERR_GENERIC            ");
      }
      else
      {
        if ( a1 != -2147467263 )
        {
LABEL_31:
          strcpy(&v4, "Error type unknown");
          goto LABEL_88;
        }
        strcpy(&v4, "DPERR_UNSUPPORTED        ");
      }
    }
LABEL_88:
    MessageBeep(0);
    MessageBeep(0);
    MessageBeep(0);
    sprintf(globBuf, "DirectPlay Error:\n\n'%s'\n\n  File:'%s'\n Line# %d", &v4, v3, a3);
    debugLog(globBuf);
    terminate(globBuf);
  }
}

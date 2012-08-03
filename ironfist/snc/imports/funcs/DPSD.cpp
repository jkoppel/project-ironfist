{
  int v3; // [sp+10h] [bp-D4h]@1
  char a1a; // [sp+18h] [bp-CCh]@3
  int v5; // [sp+E0h] [bp-4h]@2

  v3 = a2;
  if ( !bInDPSD )
  {
    bInDPSD = 1;
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
                                strcpy(&a1a, "DPERR_BUSY               ");
                              }
                              else
                              {
                                if ( a1 != -2005466856 )
                                {
                                  if ( !a1 )
                                    return;
                                  goto LABEL_31;
                                }
                                strcpy(&a1a, "DPERR_USERCANCEL         ");
                              }
                            }
                            else if ( a1 == -2005466886 )
                            {
                              strcpy(&a1a, "DPERR_UNAVAILABLE        ");
                            }
                            else
                            {
                              if ( a1 != -2005466896 )
                                goto LABEL_31;
                              strcpy(&a1a, "DPERR_TIMEOUT            ");
                            }
                          }
                          else if ( a1 == -2005466906 )
                          {
                            strcpy(&a1a, "DPERR_SENDTOOBIG         ");
                          }
                          else
                          {
                            if ( a1 != -2005466916 )
                              goto LABEL_31;
                            strcpy(&a1a, "DPERR_NOSESSIONS         ");
                          }
                        }
                        else if ( a1 == -2005466926 )
                        {
                          strcpy(&a1a, "DPERR_NOPLAYERS          ");
                        }
                        else
                        {
                          if ( a1 != -2005466936 )
                            goto LABEL_31;
                          strcpy(&a1a, "DPERR_NONAMESERVERFOUND  ");
                        }
                      }
                      else if ( a1 == -2005466946 )
                      {
                        strcpy(&a1a, "DPERR_NOMESSAGES         ");
                      }
                      else
                      {
                        if ( a1 != -2005466966 )
                          goto LABEL_31;
                        strcpy(&a1a, "DPERR_NOCONNECTION       ");
                      }
                    }
                    else if ( a1 == -2005466976 )
                    {
                      strcpy(&a1a, "DPERR_NOCAPS             ");
                    }
                    else
                    {
                      if ( a1 != -2005466986 )
                        goto LABEL_31;
                      strcpy(&a1a, "DPERR_INVALIDPLAYER      ");
                    }
                  }
                  else if ( a1 == -2005467006 )
                  {
                    strcpy(&a1a, "DPERR_INVALIDOBJECT      ");
                  }
                  else
                  {
                    if ( a1 != -2005467016 )
                      goto LABEL_31;
                    strcpy(&a1a, "DPERR_INVALIDFLAGS       ");
                  }
                }
                else if ( a1 == -2005467046 )
                {
                  strcpy(&a1a, "DPERR_EXCEPTION          ");
                }
                else
                {
                  if ( a1 != -2005467056 )
                    goto LABEL_31;
                  strcpy(&a1a, "DPERR_CAPSNOTAVAILABLEYET");
                }
              }
              else if ( a1 == -2005467066 )
              {
                strcpy(&a1a, "DPERR_CANTCREATESESSION  ");
              }
              else
              {
                if ( a1 != -2005467076 )
                  goto LABEL_31;
                strcpy(&a1a, "DPERR_CANTCREATEPLAYER   ");
              }
            }
            else if ( a1 == -2005467086 )
            {
              strcpy(&a1a, "DPERR_CANTCREATEGROUP    ");
            }
            else
            {
              if ( a1 != -2005467096 )
                goto LABEL_31;
              strcpy(&a1a, "DPERR_CANTADDPLAYER      ");
            }
          }
          else if ( a1 == -2005467106 )
          {
            strcpy(&a1a, "DPERR_BUFFERTOOSMALL     ");
          }
          else
          {
            if ( a1 != -2005467116 )
              goto LABEL_31;
            strcpy(&a1a, "DPERR_ACTIVEPLAYERS      ");
          }
        }
        else if ( a1 == -2005467126 )
        {
          strcpy(&a1a, "DPERR_ACCESSDENIED       ");
        }
        else
        {
          if ( a1 != -2005467131 )
            goto LABEL_31;
          strcpy(&a1a, "DPERR_ALREADYINITIALIZED ");
        }
      }
      else if ( a1 == -2147024809 )
      {
        strcpy(&a1a, "DPERR_INVALIDPARAMS      ");
      }
      else
      {
        if ( a1 != -2147024882 )
          goto LABEL_31;
        strcpy(&a1a, "DPERR_OUTOFMEMORY        ");
      }
    }
    else if ( a1 == -2147467259 )
    {
      strcpy(&a1a, "DPERR_GENERIC            ");
    }
    else
    {
      if ( a1 != -2147467263 )
      {
LABEL_31:
        strcpy(&a1a, "Error type unknown");
        goto LABEL_88;
      }
      strcpy(&a1a, "DPERR_UNSUPPORTED        ");
    }
LABEL_88:
    MessageBeep(0);
    MessageBeep(0);
    MessageBeep(0);
    sprintf(gText, "DirectPlay Error:\n\n'%s'\n\n  File:'%s'\n Line# %d", &a1a, v3, a3);
    LogStr(gText);
    ShutDown(gText);
  }
}
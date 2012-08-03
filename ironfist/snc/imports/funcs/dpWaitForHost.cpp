{
  signed int result; // eax@3
  signed int v1; // [sp+10h] [bp-A4h]@5
  char v2; // [sp+14h] [bp-A0h]@1
  int v3; // [sp+34h] [bp-80h]@7
  int v4; // [sp+38h] [bp-7Ch]@4
  int v5; // [sp+3Ch] [bp-78h]@4
  int v6; // [sp+40h] [bp-74h]@4
  int v7; // [sp+44h] [bp-70h]@4
  int v8; // [sp+48h] [bp-6Ch]@4
  int v9; // [sp+4Ch] [bp-68h]@14
  int v10; // [sp+50h] [bp-64h]@14
  int v11; // [sp+58h] [bp-5Ch]@14
  char a1; // [sp+5Ch] [bp-58h]@14

  sprintf(&v2, "WFHS %d", iDPWaitForHostStatus);
  AiPrint(&v2);
  switch ( iDPWaitForHostStatus )
  {
    case 0:
      if ( iWaitForHostWaitCount )
      {
        --iWaitForHostWaitCount;
        DelayMilli(100);
        result = 0;
      }
      else
      {
        iSessionToTry = 0;
        memset(&v4, 0, 0x7Cu);
        v4 = 124;
        v5 = *(_DWORD *)g_lpGuid;
        v6 = *(_DWORD *)(g_lpGuid + 4);
        v7 = *(_DWORD *)(g_lpGuid + 8);
        v8 = *(_DWORD *)(g_lpGuid + 12);
        iMaxSession = 0;
        if ( ((unsigned int)((unsigned __int64)iEnumCount >> 32) ^ abs(iEnumCount) & 7)
           - ((unsigned __int64)iEnumCount >> 32) == 4 )
          v1 = 5000;
        else
          v1 = 2000;
        v3 = (*(int (__cdecl **)(int, int *, signed int, signed int (__stdcall *)(int, int, int, char), _DWORD, _DWORD))(*(_DWORD *)lpIDC + 56))(
               lpIDC,
               &v4,
               v1,
               dpEnumSession,
               0,
               0);
        ++iEnumCount;
        if ( v3 != -2005466916 )
        {
          if ( v3 )
            DPSD(v3, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED6E0 + 38);
          if ( iMaxSession > 0 )
          {
            iWaitForHostWaitCount = 30;
            ++iDPWaitForHostStatus;
          }
          goto LABEL_37;
        }
        iWaitForHostWaitCount = 30;
        result = 0;
      }
      return result;
    case 1:
      memset(&v4, 0, 0x7Cu);
      v4 = 124;
      v10 = 6;
      v5 = *(_DWORD *)g_lpGuid;
      v6 = *(_DWORD *)(g_lpGuid + 4);
      v7 = *(_DWORD *)(g_lpGuid + 8);
      v8 = *(_DWORD *)(g_lpGuid + 12);
      v11 = 1;
      v9 = lSessions[iSessionToTry];
      strcpy(&a1, "Heroes 2");
      v3 = (*(int (__cdecl **)(int, int *))(*(_DWORD *)lpIDC + 80))(lpIDC, &v4);
      if ( v3 )
        DPSD(v3, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED6E0 + 57);
      ++iDPWaitForHostStatus;
      goto LABEL_37;
    case 2:
      v3 = (*(int (__cdecl **)(int, int *, _DWORD, _DWORD, int *))(*(_DWORD *)lpIDC + 20))(
             lpIDC,
             &dcoID,
             "Dude",
             "Heroes Player",
             &dword_4ED2DC);
      if ( v3 )
        DPSD(v3, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED6E0 + 67);
      ++iDPWaitForHostStatus;
      goto LABEL_37;
    case 3:
      iLastHereIAmTickCount = KBTickCount();
      giHostAcceptStatus = 0;
      dpSendMessage(0, 2, 0x22u, &gsThisNetPlayerInfo);
      ++iDPWaitForHostStatus;
      goto LABEL_37;
    case 4:
      dpProcessMessages();
      if ( giHostAcceptStatus == 1 )
      {
        ++iDPWaitForHostStatus;
      }
      else if ( giHostAcceptStatus == 2 )
      {
        if ( iSessionToTry + 1 < iMaxSession )
        {
          iDPWaitForHostStatus = 1;
          ++iSessionToTry;
        }
        else
        {
          iDPWaitForHostStatus = 0;
        }
        v3 = (*(int (__cdecl **)(int))(*(_DWORD *)lpIDC + 16))(lpIDC);
        if ( v3 )
          DPSD(v3, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED6E0 + 93);
      }
      else if ( KBTickCount() > iLastHereIAmTickCount + 5000 )
      {
        --iDPWaitForHostStatus;
      }
      goto LABEL_37;
    case 5:
      dpProcessMessages();
      if ( !bStartUpInfoReceived )
        goto LABEL_37;
      result = 1;
      break;
    default:
LABEL_37:
      result = 0;
      break;
  }
  return result;
}
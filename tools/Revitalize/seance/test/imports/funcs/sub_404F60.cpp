{
  int v2; // [sp+14h] [bp-Ch]@1
  signed int i; // [sp+18h] [bp-8h]@4
  const void *v4; // [sp+1Ch] [bp-4h]@1

  v2 = a1;
  v4 = &buf[1];
  switch ( buf[0] )
  {
    case 1:
      *((_DWORD *)dword_4ED2E8 + dword_4ED2E0) = KBAlloc(a1 - 1, "F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED5D0 + 8);
      memcpy(*((void **)dword_4ED2E8 + dword_4ED2E0), &buf[1], v2 - 1);
      *((_DWORD *)dword_4ED2EC + dword_4ED2E0) = v2;
      dword_4ED2E0 = (dword_4ED2E0 + 1) % 200;
      break;
    case 2:
      if ( (unsigned __int8)byte_51257C == 1 )
      {
        for ( i = 1; i < dword_5235D4; ++i )
        {
          if ( *((_DWORD *)&dword_522B78 + i) == a2 )
          {
            sub_404C60(a2, 4, 0, 0);
            return;
          }
        }
        if ( dword_524A6C )
        {
          *((_DWORD *)&dword_522B78 + dword_5235D4) = a2;
          memcpy((char *)&dword_526CE0 + 34 * dword_5235D4, v4, 0x22u);
          if ( !byte_526CFC[34 * dword_5235D4] )
            byte_51AC64 = 1;
          sub_404C60(a2, 4, 0, 0);
          ++dword_5235D4;
        }
        else
        {
          sub_404C60(a2, 5, 0, 0);
        }
      }
      break;
    case 4:
      dword_522BC8 = 1;
      break;
    case 5:
      dword_522BC8 = 2;
      break;
    case 3:
      dword_5235D4 = *(_BYTE *)v4;
      dword_523F14 = buf[2];
      logUpTo7Ints((int)"DPMSGSTARTUP", dword_523F14, a2, -999, -999, -999, -999, -999);
      memcpy(&dword_522B78, &buf[3], 0x18u);
      dword_4ED2F0 = 1;
      break;
    default:
      sprintf(globBuf, "Unknown message: %d\n", buf[0]);
      debugLog(globBuf);
      break;
  }
}

{
  debugLog("RC1");
  if ( dword_4F7494 )
  {
    debugLog("RC2");
    if ( !dword_512584 )
    {
      if ( !dword_512588 )
      {
        dword_512588 = 1;
        debugLog("RC3");
        switch ( byte_51257C )
        {
          case 1:
          case 2:
            sub_46DBD0(1);
            break;
          case 3:
          case 4:
            sub_46DBD0(0);
            break;
          default:
            break;
        }
        dword_4F7494 = 0;
        byte_51AC64 = 0;
        dword_512570 = 0;
        dword_512574 = 0;
        dword_512578 = -1;
        byte_51257C = 0;
        dword_512580 = 0;
        dword_512584 = 0;
        dword_51258C = 0;
        dword_512590 = 0;
        dword_512598 = 0;
        dword_51259C = 0;
        byte_5125A0 = 0;
        dword_4F31B4 = 0;
        dword_4F31B8 = -2;
        dword_4F3094 = 0;
        dword_512588 = 0;
      }
    }
  }
}

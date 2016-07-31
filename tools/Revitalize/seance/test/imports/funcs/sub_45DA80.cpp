{
  if ( dword_5235D4 != 1 && dword_524778 != 2 )
  {
    if ( getTickCount() > animationFrameSwitchTime )
    {
      dword_5110D0 = 1 - dword_5110D0;
      animationFrameSwitchTime = getTickCount() + 360;
    }
    if ( (signed int)a2 > 0 )
      strncpy(dword_524F3C, a1, a2);
    if ( dword_5110D0 )
      dword_524F3C[a2] = 31;
    else
      dword_524F3C[a2] = 95;
    if ( strlen(a1) <= a2 )
      dword_524F3C[a2 + 1] = 0;
    else
      strcpy(&dword_524F3C[a2 + 1], &a1[a2]);
  }
}

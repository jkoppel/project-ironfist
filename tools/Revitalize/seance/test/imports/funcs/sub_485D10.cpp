{
  HMENU v2; // eax@4
  unsigned int a2a; // [sp+Ch] [bp-20h]@1
  HMENU hMenua; // [sp+10h] [bp-1Ch]@1
  UINT uIDEnableItem; // [sp+14h] [bp-18h]@3
  signed int i; // [sp+18h] [bp-14h]@7
  int nPos; // [sp+1Ch] [bp-10h]@1
  int v8; // [sp+20h] [bp-Ch]@4
  int v9; // [sp+24h] [bp-8h]@1
  signed int v10; // [sp+28h] [bp-4h]@7

  a2a = a2;
  hMenua = a1;
  v9 = GetMenuItemCount(a1);
  for ( nPos = 0; v9 > nPos; ++nPos )
  {
    uIDEnableItem = GetMenuItemID(hMenua, nPos);
    if ( uIDEnableItem == -1 )
    {
      v2 = GetSubMenu(hMenua, nPos);
      sub_485D10(v2, a2a);
      v8 = 0;
    }
    else
    {
      if ( a2a )
      {
        v8 = 1;
      }
      else
      {
        v10 = 0;
        for ( i = 0; i < 70; ++i )
        {
          if ( *(int *)((char *)&dword_4F2E90 + 7 * i) == uIDEnableItem )
            v10 = i;
        }
        if ( dword_4F307C )
          v8 = 1 - (unsigned __int8)byte_4F2E95[7 * v10];
        else
          v8 = 1 - (unsigned __int8)byte_4F2E94[7 * v10];
      }
    }
    if ( v8 )
      EnableMenuItem(hMenua, uIDEnableItem, a2a < 1);
  }
  disableTooLargeDisplayControls(hMenua);
}

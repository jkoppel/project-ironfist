{
  int result; // eax@6

  if ( !gbNoDialogMenusOn || a1 )
  {
    if ( gbNoDialogMenusOn || !a1 )
    {
      if ( hmnuApp )
      {
        gbNoDialogMenusOn = 1 - a1;
        SetMenus(hmnuApp, a1);
      }
    }
  }
  return result;
}
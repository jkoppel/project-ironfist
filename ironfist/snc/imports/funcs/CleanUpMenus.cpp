{
  BOOL result; // eax@2

  if ( hmnuApp )
  {
    result = SetMenu(hwndApp, 0);
    if ( hmnuAdv )
      result = DestroyMenu(hmnuAdv);
    if ( hmnuDflt )
      result = DestroyMenu(hmnuDflt);
    if ( hmnuCmbt )
      result = DestroyMenu(hmnuCmbt);
    if ( hmnuTown )
      result = DestroyMenu(hmnuTown);
  }
  hmnuApp = 0;
  return result;
}
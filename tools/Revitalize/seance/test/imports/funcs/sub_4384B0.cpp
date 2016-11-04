{
  BOOL result; // eax@2

  if ( globalMenu2 )
  {
    result = SetMenu(windowHandle, 0);
    if ( adventureMenu )
      result = DestroyMenu(adventureMenu);
    if ( dfltMenu )
      result = DestroyMenu(dfltMenu);
    if ( combatMenu )
      result = DestroyMenu(combatMenu);
    if ( townMenu )
      result = DestroyMenu(townMenu);
  }
  globalMenu2 = 0;
  return result;
}

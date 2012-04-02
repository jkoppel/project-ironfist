void __cdecl sub_49CE90()
{
  debugLog("IG1");
  sub_49CD00();
  debugLog("IG2");
  if ( *(&mainWindows + 7 * gameOrEditorIdx + 5) )
    graphicsLibraryToUse = 2;
  else
    graphicsLibraryToUse = 1;
  if ( graphicsLibraryToUse == 1 )
  {
    debugLog("IG3");
    sub_49C580();
    debugLog("IG4");
  }
  else
  {
    debugLog("IG5");
    sub_49AFB0();
    debugLog("IG6");
  }
}

{
  if ( !gbNewGameDialogOver && iLastMsgNumHumanPlayers != 1 && iMPBaseType != 2 )
  {
    icon::DrawToBuffer(NGKPBkg, 244, 406, 81, 0);
    font::DrawBoundedString(smallFont, cNGKPDisplay, 244, 406, 348, 12, 2, 0);
    if ( a1 )
      heroWindowManager::UpdateScreenRegion(gpWindowManager, 244, 406, 0x15Cu, 12);
  }
}
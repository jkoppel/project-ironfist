{
  int result; // eax@1
  int v4; // [sp-4h] [bp-Ch]@12

  result = bInCheckChangeCursor;
  if ( !bInCheckChangeCursor )
  {
    result = 28 * giCurExe;
    if ( !*(&bMenu + 7 * giCurExe + 5) || a3 )
    {
      if ( *(BOOL *)((char *)&bMenu + result + 24) )
      {
        bInCheckChangeCursor = 1;
        if ( a3 || a1 >= 0 && a1 < 640 && a2 >= 0 && a2 < 480 )
        {
          if ( bLastMouseOffscreen )
          {
            bLastMouseOffscreen = 0;
            mouseManager::SetPointer(gpMouseManager, 1000);
          }
          result = bLastOnscreenMouseColor;
          if ( bLastOnscreenMouseColor == gbColorMice )
            goto LABEL_18;
          v4 = 1;
        }
        else
        {
          result = bLastMouseOffscreen;
          if ( bLastMouseOffscreen )
            goto LABEL_18;
          bLastMouseOffscreen = 1;
          bLastOnscreenMouseColor = gbColorMice;
          if ( !gbColorMice )
            goto LABEL_18;
          v4 = 0;
        }
        result = mouseManager::SetColorMice(gpMouseManager, v4);
LABEL_18:
        bInCheckChangeCursor = 0;
        return result;
      }
    }
  }
  return result;
}
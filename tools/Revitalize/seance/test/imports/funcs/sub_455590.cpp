{
  int v1; // [sp+Ch] [bp-14h]@1
  int v2; // [sp+10h] [bp-10h]@2
  int v3; // [sp+14h] [bp-Ch]@2
  int y; // [sp+18h] [bp-8h]@2
  int x; // [sp+1Ch] [bp-4h]@2

  v1 = (int)this;
  if ( getTickCount() - dword_50EA8C > 70 )
  {
    dword_50EA8C = getTickCount();
    v2 = *(_DWORD *)(v1 + 470);
    v3 = *(_DWORD *)(v1 + 474);
    retrieveVirtualCursorCoordinates(&x, &y);
    if ( x >= 0 && x < 640 && y >= 0 && y < 480 )
    {
      if ( x >= 16 )
      {
        if ( x <= 623 )
        {
          if ( y >= 16 )
          {
            if ( y > 464 )
              sub_4553E0(v1, 4, 1);
          }
          else
          {
            sub_4553E0(v1, 0, 1);
          }
        }
        else
        {
          if ( y >= 16 )
          {
            if ( y <= 464 )
              sub_4553E0(v1, 2, 1);
            else
              sub_4553E0(v1, 3, 1);
          }
          else
          {
            sub_4553E0(v1, 1, 1);
          }
        }
      }
      else
      {
        if ( y >= 16 )
        {
          if ( y <= 464 )
            sub_4553E0(v1, 6, 1);
          else
            sub_4553E0(v1, 5, 1);
        }
        else
        {
          sub_4553E0(v1, 7, 1);
        }
      }
    }
    if ( mouseManager->spriteIdx >= 32 && mouseManager->spriteIdx < 40 && *(_DWORD *)(v1 + 470) == v2 )
    {
      if ( *(_DWORD *)(v1 + 474) == v3 )
        MouseManager::setSpriteIdx(mouseManager, 0);
    }
  }
}

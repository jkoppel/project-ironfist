{
  signed int result; // eax@36
  signed int v2; // [sp+10h] [bp-20h]@5
  int v3; // [sp+14h] [bp-1Ch]@4
  int v4; // [sp+18h] [bp-18h]@3
  void *v5; // [sp+1Ch] [bp-14h]@1
  int v6; // [sp+20h] [bp-10h]@31
  signed int v7; // [sp+24h] [bp-Ch]@3
  int v8; // [sp+24h] [bp-Ch]@21
  signed int v9; // [sp+28h] [bp-8h]@3
  int v10; // [sp+28h] [bp-8h]@21
  signed int v11; // [sp+2Ch] [bp-4h]@3

  v5 = this;
  if ( getTickCount() > animationFrameSwitchTime )
  {
    sub_447C20(advManager, advManager->viewX, advManager->viewY, 0, 1);
    sub_447A00(advManager, 0, 0);
  }
  v9 = *((_DWORD *)v5 + 4);
  v7 = *((_DWORD *)v5 + 5);
  v11 = 0;
  v4 = *(_DWORD *)v5;
  if ( v4 == 4 )
  {
    if ( !sub_4385B0(*((_DWORD *)v5 + 4), *((_DWORD *)v5 + 5)) )
    {
      HeroWindowManager::instance->buttonPressedCode = 0;
      MouseManager::setSpriteIdx(mouseManager, 0);
      return 1;
    }
    v10 = v9 / 32;
    v8 = v7 / 32;
    if ( v10 < 0 )
      v10 = 0;
    if ( v8 < 0 )
      v8 = 0;
    if ( v10 > 14 )
      v10 = 14;
    if ( v8 > 14 )
      v8 = 14;
    if ( *(_DWORD *)&advManager->_2[8] != v10 || *(_DWORD *)&advManager->_2[12] != v8 )
    {
      *(_DWORD *)&advManager->_2[8] = v10;
      *(_DWORD *)&advManager->_2[12] = v8;
      v6 = usedToCheckForBoatByCastle(advManager, v10 + advManager->viewX, v8 + advManager->viewY);
      if ( *(_BYTE *)(v6 + 9) & 0x80 || *(_BYTE *)(v6 + 8) & 8 )
      {
        HeroWindowManager::instance->buttonPressedCode = 0;
        MouseManager::setSpriteIdx(mouseManager, 0);
      }
      else
      {
        HeroWindowManager::instance->buttonPressedCode = 1;
        MouseManager::setSpriteIdx(mouseManager, 4);
      }
    }
  }
  else
  {
    if ( v4 == 512 )
    {
      v3 = *((_DWORD *)v5 + 1);
      if ( v3 == 12 )
      {
        v2 = *((_DWORD *)v5 + 2);
        if ( v2 >= 10 && v2 <= 11 && !(*((_BYTE *)v5 + 13) & 2) && HeroWindowManager::instance->buttonPressedCode == 1 )
          v11 = 1;
      }
      else
      {
        if ( v3 == 13 && *((_DWORD *)v5 + 2) == 30720 )
        {
          HeroWindowManager::instance->buttonPressedCode = 0;
          v11 = 1;
        }
      }
    }
  }
  if ( v11 )
  {
    *((_DWORD *)v5 + 2) = 10;
    *((_DWORD *)v5 + 1) = *((_DWORD *)v5 + 2);
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}

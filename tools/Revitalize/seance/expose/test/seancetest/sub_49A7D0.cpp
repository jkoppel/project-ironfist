signed int __thiscall sub_49A7D0(void *this)
{
  signed int v2; // [sp+1Ch] [bp-8Ch]@57
  int v3; // [sp+24h] [bp-84h]@4
  void *v4; // [sp+28h] [bp-80h]@1
  char v5; // [sp+2Ch] [bp-7Ch]@36
  InputEvent a2; // [sp+48h] [bp-60h]@31
  int v7; // [sp+64h] [bp-44h]@21
  int v8; // [sp+68h] [bp-40h]@21
  int v9; // [sp+6Ch] [bp-3Ch]@29
  float v10; // [sp+88h] [bp-20h]@14
  int v11; // [sp+8Ch] [bp-1Ch]@31
  int v12; // [sp+90h] [bp-18h]@38
  int v13; // [sp+94h] [bp-14h]@42

  v4 = this;
  if ( !SoundManager::songPlaying(soundManager) )
    SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[advManager->field_A6]);
  if ( *(_DWORD *)v4 != 512 )
    return 1;
  v3 = *((_DWORD *)v4 + 1);
  if ( v3 == 12 )
  {
    if ( *((_DWORD *)v4 + 2) == 9
      && (dword_51923C != 12 || mapWidth > 36)
      && (dword_51923C != 6 || mapWidth > 72)
      && (dword_51923C != 4 || mapWidth > 108) )
    {
      switch ( mapHeight )
      {
        case 36:
          v10 = 4.0;
          break;
        case 72:
          v10 = 2.0;
          break;
        case 108:
          v10 = 1.3333;
          break;
        default:
          v10 = 1.0;
          break;
      }
      v8 = *((_DWORD *)v4 + 4);
      v7 = *((_DWORD *)v4 + 5);
      v8 = (signed __int64)((double)(v8 - 480) / v10);
      v7 = (signed __int64)((double)(v7 - 16) / v10);
      dword_52FF5C = v8 - dword_52FF64;
      dword_52FF60 = v7 - dword_52FF64;
      if ( v8 - dword_52FF64 < 0 )
        dword_52FF5C = 0;
      if ( dword_52FF60 < 0 )
        dword_52FF60 = 0;
      if ( dword_52FF68 + dword_52FF5C >= mapWidth )
        dword_52FF60 = mapWidth - dword_52FF68;
      if ( dword_52FF60 + dword_52FF68 >= mapHeight )
        dword_52FF60 = mapHeight - dword_52FF68;
      sub_44AA80((int)advManager, 1, 0);
      sub_499480(advManager);
      v9 = 0;
      while ( v9 != 16 )
      {
        passOnMessages();
        memcpy(&v9, InputManager::nextInputEvent(inputManager, &a2), 0x1Cu);
        memcpy(&v11, &v9, 0x1Cu);
        while ( v9 != 16 && v9 )
        {
          if ( v9 == 4 )
            memcpy(&v11, &v9, 0x1Cu);
          passOnMessages();
          memcpy(&v9, InputManager::nextInputEvent(inputManager, (InputEvent *)&v5), 0x1Cu);
        }
        if ( v11 == 4 )
        {
          if ( v12 < 480 )
            v12 = 480;
          if ( v12 >= 624 )
            v12 = 2 * mapWidth + 479;
          if ( v13 < 16 )
            v13 = 16;
          if ( v13 >= 160 )
            v13 = 2 * mapHeight + 15;
          (*(void (__thiscall **)(MouseManager *))(LODWORD(mouseManager->vtable) + 8))(mouseManager);
          v8 = (signed __int64)((double)(v12 - 480) / v10);
          v7 = (signed __int64)((double)(v13 - 16) / v10);
          dword_52FF5C = v8 - dword_52FF64;
          dword_52FF60 = v7 - dword_52FF64;
          if ( v8 - dword_52FF64 < 0 )
            dword_52FF5C = 0;
          if ( dword_52FF60 < 0 )
            dword_52FF60 = 0;
          if ( dword_52FF68 + dword_52FF5C >= mapWidth )
            dword_52FF5C = mapWidth - dword_52FF68;
          if ( dword_52FF60 + dword_52FF68 >= mapHeight )
            dword_52FF60 = mapHeight - dword_52FF68;
          sub_44AA80((int)advManager, 1, 0);
          sub_499480(advManager);
          v11 = 0;
        }
      }
    }
    return 1;
  }
  if ( v3 == 13 )
  {
    v2 = *((_DWORD *)v4 + 2);
    if ( v2 > 30723 )
    {
      if ( v2 < 30725 || v2 > 30726 )
        return 1;
    }
    else
    {
      if ( v2 < 30720 )
      {
        if ( v2 == 2 )
        {
          sub_4991C0();
          if ( dword_51923C == 12 )
          {
            dword_51923C = 6;
          }
          else
          {
            if ( dword_51923C == 6 )
              dword_51923C = 4;
            else
              dword_51923C = 12;
          }
          sub_499220(advManager, dword_52FF64 + dword_52FF5C, dword_52FF60 + dword_52FF64);
          sub_499480(advManager);
        }
        return 1;
      }
    }
    HeroWindowManager::instance->buttonPressedCode = *((_DWORD *)v4 + 2);
    *((_DWORD *)v4 + 2) = 10;
    *((_DWORD *)v4 + 1) = *((_DWORD *)v4 + 2);
    return 2;
  }
  return 1;
}

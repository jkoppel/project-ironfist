signed int __cdecl sub_4BA3E0()
{
  signed int result; // eax@11
  signed int v1; // [sp+Ch] [bp-40h]@6
  GUIWindow *this; // [sp+1Ch] [bp-30h]@1
  GUIWindow *window; // [sp+20h] [bp-2Ch]@2
  char v4; // [sp+24h] [bp-28h]@18

  debugLog("SCP 1");
  this = (GUIWindow *)operator new(0x44u);
  if ( this )
    window = GUIWindow_constructorFromFile(this, 405, 8, "stpcom.bin");
  else
    window = 0;
  if ( !window )
    fatalOutOfMemoryError();
  debugLog("SCP 2");
  HeroWindowManager::displayWindow(HeroWindowManager::instance, window, (int (__fastcall *)(InputEvent *))sub_4BBB10, 0);
  operator delete(window);
  debugLog("SCP 3");
  v1 = HeroWindowManager::instance->buttonPressedCode;
  if ( v1 <= 30721 )
  {
    if ( v1 == 30721 )
      return 0;
    switch ( v1 )
    {
      case 1:
        *((_DWORD *)&modemComPort + dword_4F7478) = 1;
        break;
      case 2:
        *((_DWORD *)&modemComPort + dword_4F7478) = 2;
        break;
      case 3:
        *((_DWORD *)&modemComPort + dword_4F7478) = 3;
        break;
      case 4:
        *((_DWORD *)&modemComPort + dword_4F7478) = 4;
        break;
      default:
        break;
    }
  }
  debugLog("SCP 4");
  if ( sub_4BA290() )
  {
    debugLog("SCP 5");
    if ( !dword_4F7478 )
    {
      strcpy((char *)&computerWalkSpeed + 174, "ATZ");
      sprintf(globBuf, "%s", &computerWalkSpeed + 174);
      sub_4CAEF0(
        "Please enter any special initialization string required by your modem, or hit 'ENTER' to accept the default.",
        (int)&v4,
        40,
        globBuf,
        0,
        1);
      strcpy((char *)&computerWalkSpeed + 174, &v4);
    }
    propagateSettingChanges();
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

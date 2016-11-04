{
  UINT uIDCheckItem; // [sp+14h] [bp-8h]@4
  UINT uIDCheckItema; // [sp+14h] [bp-8h]@20
  UINT uIDCheckItemb; // [sp+14h] [bp-8h]@36
  UINT v3; // [sp+18h] [bp-4h]@8
  UINT v4; // [sp+18h] [bp-4h]@24

  if ( *(&mainWindows + 7 * gameOrEditorIdx) && globalMenu2 && globalMenu2 == adventureMenu )
  {
    for ( uIDCheckItem = 40016; (signed int)uIDCheckItem <= 40026; ++uIDCheckItem )
      CheckMenuItem(globalMenu2, uIDCheckItem, 0);
    switch ( *(_DWORD *)&musicVolume )
    {
      case 1:
        v3 = 40017;
        break;
      case 2:
        v3 = 40018;
        break;
      case 3:
        v3 = 40019;
        break;
      case 4:
        v3 = 40020;
        break;
      case 5:
        v3 = 40021;
        break;
      case 6:
        v3 = 40022;
        break;
      case 7:
        v3 = 40023;
        break;
      case 8:
        v3 = 40024;
        break;
      case 9:
        v3 = 40025;
        break;
      case 0xA:
        v3 = 40026;
        break;
      default:
        v3 = 40016;
        break;
    }
    CheckMenuItem(globalMenu2, v3, 8u);
    for ( uIDCheckItema = 40028; (signed int)uIDCheckItema <= 40038; ++uIDCheckItema )
      CheckMenuItem(globalMenu2, uIDCheckItema, 0);
    switch ( *(_DWORD *)&soundVolume )
    {
      case 1:
        v4 = 40029;
        break;
      case 2:
        v4 = 40030;
        break;
      case 3:
        v4 = 40031;
        break;
      case 4:
        v4 = 40032;
        break;
      case 5:
        v4 = 40033;
        break;
      case 6:
        v4 = 40034;
        break;
      case 7:
        v4 = 40035;
        break;
      case 8:
        v4 = 40036;
        break;
      case 9:
        v4 = 40037;
        break;
      case 0xA:
        v4 = 40038;
        break;
      default:
        v4 = 40028;
        break;
    }
    CheckMenuItem(globalMenu2, v4, 8u);
    for ( uIDCheckItemb = 40040; (signed int)uIDCheckItemb <= 40044; ++uIDCheckItemb )
      CheckMenuItem(globalMenu2, uIDCheckItemb, 0);
    CheckMenuItem(globalMenu2, 40046u, ((*(_DWORD *)&showRoute < 1u) - 1) & 8);
    CheckMenuItem(globalMenu2, 40047u, (((unsigned int)(1 - *(_DWORD *)&blackoutComputer) < 1) - 1) & 8);
  }
}

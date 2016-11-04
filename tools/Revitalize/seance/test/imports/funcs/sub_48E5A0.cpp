{
  int creatureType; // [sp+14h] [bp-2Ch]@15
  int v3; // [sp+18h] [bp-28h]@15
  int v4; // [sp+1Ch] [bp-24h]@15
  int v5; // [sp+20h] [bp-20h]@15
  int v6; // [sp+24h] [bp-1Ch]@15
  int v7; // [sp+28h] [bp-18h]@15
  int v8; // [sp+2Ch] [bp-14h]@15
  int v9; // [sp+30h] [bp-10h]@15
  int v10; // [sp+34h] [bp-Ch]@15
  int v11; // [sp+38h] [bp-8h]@15
  int v12; // [sp+3Ch] [bp-4h]@1

  v12 = 0;
  switch ( *(_BYTE *)(a2 + 9) & 0x7F )
  {
    case 0xD:
      v12 = 0;
      break;
    case 0xE:
      v12 = 1;
      break;
    case 0x10:
      v12 = 2;
      break;
    case 0xF:
    case 0x41:
      v12 = 3;
      break;
    case 0x11:
      v12 = 4;
      break;
    case 0x3B:
      v12 = 5;
      break;
    case 0x48:
      v12 = 6;
      break;
    case 0x3A:
      v12 = 7;
      break;
    case 0x57:
      v12 = 8;
      break;
    case 0x4E:
      v12 = 9;
      break;
    default:
      break;
  }
  if ( (unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5 )
  {
    creatureType = 1;
    v3 = 11;
    v4 = 0;
    v5 = 21;
    v6 = 21;
    v7 = 20;
    v8 = 38;
    v9 = 12;
    v10 = 29;
    v11 = 47;
    showMessageWindowForEvent(3 * v12 + 23, 2, byte_51854C, -1, 0, -1, 0, -1);
    if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
    {
      if ( ArmyInfo::hasRoomForCreatureType((ArmyInfo *)(a1 + 101), *(&creatureType + v12)) )
      {
        ArmyInfo::addCreatures(
          (ArmyInfo *)(a1 + 101),
          *(&creatureType + v12),
          (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5),
          -1);
        *(_WORD *)(a2 + 4) &= 7u;
      }
      else
      {
        showMessageWindowForEvent(3 * v12 + 24, 1, byte_518550, -1, 0, -1, 0, -1);
      }
    }
  }
  else
  {
    showMessageWindowForEvent(3 * v12 + 25, 1, byte_518548, -1, 0, -1, 0, -1);
  }
}

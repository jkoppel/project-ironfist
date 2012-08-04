{
  signed int result; // eax@52
  int v2; // [sp+18h] [bp-20h]@2
  void *v3; // [sp+1Ch] [bp-1Ch]@1
  signed int v4; // [sp+30h] [bp-8h]@1
  unsigned int v5; // [sp+34h] [bp-4h]@1

  v3 = this;
  v4 = 0;
  v5 = 0;
  if ( *(_DWORD *)this != 512 )
    goto LABEL_40;
  v2 = *((_DWORD *)this + 1);
  if ( v2 == 12 )
    goto LABEL_4;
  if ( v2 != 13 )
  {
    if ( v2 != 14 )
      goto LABEL_40;
    v5 = 1;
LABEL_4:
    if ( *((_BYTE *)this + 13) & 2 )
      v5 = 1;
    switch ( *((_DWORD *)this + 2) )
    {
      case 0x6F:
        if ( !v5 )
          game::DoKnob(gpGame);
        break;
      case 0x6E:
        if ( !v5 && giOverviewItems[giOverviewType] > 4 )
        {
          giOverviewTop[giOverviewType] = 100
                                        * (*((_DWORD *)this + 5) - 27)
                                        / 32100
                                        / (giOverviewItems[giOverviewType] - 3);
          if ( giOverviewTop[giOverviewType] + 3 >= giOverviewItems[giOverviewType] )
            giOverviewTop[giOverviewType] = giOverviewItems[giOverviewType] - 4;
          if ( giOverviewTop[giOverviewType] < 0 )
            giOverviewTop[giOverviewType] = 0;
          game::SetupDynamicStuff(gpGame, 1, 1, 0);
        }
        break;
      case 0x64:
        if ( !v5 )
          goto LABEL_17;
        break;
      case 0x65:
        if ( !v5 )
          goto LABEL_21;
        break;
      default:
        v4 = game::ProcessIconSelect(gpGame, *((_DWORD *)this + 2), v5);
        break;
    }
    goto LABEL_40;
  }
  switch ( *((_DWORD *)this + 2) )
  {
    case 0x23:
LABEL_17:
      if ( giOverviewType )
        game::SetupNewOverviewType(gpGame, 0, 1);
      break;
    case 0x14:
LABEL_21:
      if ( giOverviewType != 1 )
        game::SetupNewOverviewType(gpGame, 1, 1);
      break;
    case 0xA:
      if ( giOverviewTop[giOverviewType] > 0 )
      {
        --giOverviewTop[giOverviewType];
        game::SetupDynamicStuff(gpGame, 1, 1, 0);
      }
      break;
    case 0xB:
      if ( giOverviewItems[giOverviewType] - 4 > giOverviewTop[giOverviewType] )
      {
        ++giOverviewTop[giOverviewType];
        game::SetupDynamicStuff(gpGame, 1, 1, 0);
      }
      break;
    case 0xE:
      gpWindowManager->buttonPressedCode = *((_DWORD *)this + 2);
      v4 = 1;
      break;
    default:
      break;
  }
LABEL_40:
  if ( *(_DWORD *)v3 == 1 )
  {
    switch ( *((_DWORD *)v3 + 1) )
    {
      case 0x49:
        giOverviewTop[giOverviewType] -= 4;
        if ( giOverviewTop[giOverviewType] < 0 )
          giOverviewTop[giOverviewType] = 0;
        game::SetupDynamicStuff(gpGame, 1, 1, 0);
        break;
      case 0x51:
        giOverviewTop[giOverviewType] += 4;
        if ( giOverviewItems[giOverviewType] - 4 < giOverviewTop[giOverviewType] )
          giOverviewTop[giOverviewType] = giOverviewItems[giOverviewType] - 4;
        game::SetupDynamicStuff(gpGame, 1, 1, 0);
        break;
      case 0x47:
        giOverviewTop[giOverviewType] = 0;
        game::SetupDynamicStuff(gpGame, 1, 1, 0);
        break;
      case 0x4F:
        giOverviewTop[giOverviewType] = giOverviewItems[giOverviewType] - 4;
        game::SetupDynamicStuff(gpGame, 1, 1, 0);
        break;
      default:
        break;
    }
  }
  if ( v4 == 1 )
  {
    *((_DWORD *)v3 + 2) = 10;
    *((_DWORD *)v3 + 1) = *((_DWORD *)v3 + 2);
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}
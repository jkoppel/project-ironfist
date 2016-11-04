{
  signed int result; // eax@52
  int v2; // [sp+18h] [bp-20h]@2
  int v3; // [sp+1Ch] [bp-1Ch]@1
  signed int v4; // [sp+30h] [bp-8h]@1
  unsigned int v5; // [sp+34h] [bp-4h]@1

  v3 = this;
  v4 = 0;
  v5 = 0;
  if ( *(_DWORD *)this != 512 )
    goto LABEL_40;
  v2 = *(_DWORD *)(this + 4);
  if ( v2 == 12 )
    goto LABEL_4;
  if ( v2 != 13 )
  {
    if ( v2 != 14 )
      goto LABEL_40;
    v5 = 1;
LABEL_4:
    if ( *(_BYTE *)(this + 13) & 2 )
      v5 = 1;
    switch ( *(_DWORD *)(this + 8) )
    {
      case 0x6F:
        if ( !v5 )
          sub_462A50(gameObject);
        break;
      case 0x6E:
        if ( !v5 && dword_525208[dword_511E64] > 4 )
        {
          dword_511E68[dword_511E64] = 100 * (*(_DWORD *)(this + 20) - 27) / 32100 / (dword_525208[dword_511E64] - 3);
          if ( dword_511E68[dword_511E64] + 3 >= dword_525208[dword_511E64] )
            dword_511E68[dword_511E64] = dword_525208[dword_511E64] - 4;
          if ( dword_511E68[dword_511E64] < 0 )
            dword_511E68[dword_511E64] = 0;
          sub_45FF60(gameObject, 1, 1, 0);
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
        v4 = sub_463250(gameObject, *(_DWORD *)(this + 8), v5);
        break;
    }
    goto LABEL_40;
  }
  switch ( *(_DWORD *)(this + 8) )
  {
    case 0x23:
LABEL_17:
      if ( dword_511E64 )
        sub_462190(gameObject, 0, 1);
      break;
    case 0x14:
LABEL_21:
      if ( dword_511E64 != 1 )
        sub_462190(gameObject, 1, 1);
      break;
    case 0xA:
      if ( dword_511E68[dword_511E64] > 0 )
      {
        --dword_511E68[dword_511E64];
        sub_45FF60(gameObject, 1, 1, 0);
      }
      break;
    case 0xB:
      if ( dword_525208[dword_511E64] - 4 > dword_511E68[dword_511E64] )
      {
        ++dword_511E68[dword_511E64];
        sub_45FF60(gameObject, 1, 1, 0);
      }
      break;
    case 0xE:
      HeroWindowManager::instance->buttonPressedCode = *(_DWORD *)(this + 8);
      v4 = 1;
      break;
    default:
      break;
  }
LABEL_40:
  if ( *(_DWORD *)v3 == 1 )
  {
    switch ( *(_DWORD *)(v3 + 4) )
    {
      case 0x49:
        dword_511E68[dword_511E64] -= 4;
        if ( dword_511E68[dword_511E64] < 0 )
          dword_511E68[dword_511E64] = 0;
        sub_45FF60(gameObject, 1, 1, 0);
        break;
      case 0x51:
        dword_511E68[dword_511E64] += 4;
        if ( dword_525208[dword_511E64] - 4 < dword_511E68[dword_511E64] )
          dword_511E68[dword_511E64] = dword_525208[dword_511E64] - 4;
        sub_45FF60(gameObject, 1, 1, 0);
        break;
      case 0x47:
        dword_511E68[dword_511E64] = 0;
        sub_45FF60(gameObject, 1, 1, 0);
        break;
      case 0x4F:
        dword_511E68[dword_511E64] = dword_525208[dword_511E64] - 4;
        sub_45FF60(gameObject, 1, 1, 0);
        break;
      default:
        break;
    }
  }
  if ( v4 == 1 )
  {
    *(_DWORD *)(v3 + 8) = 10;
    *(_DWORD *)(v3 + 4) = *(_DWORD *)(v3 + 8);
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}

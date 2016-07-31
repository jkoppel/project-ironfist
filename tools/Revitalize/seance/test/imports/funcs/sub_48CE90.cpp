{
  __int16 v2; // [sp+18h] [bp-18h]@1
  int v3; // [sp+1Ch] [bp-14h]@1
  int v4; // [sp+20h] [bp-10h]@11
  int v5; // [sp+24h] [bp-Ch]@2
  int res[2]; // [sp+28h] [bp-8h]@1

  *(_QWORD *)res = stru_5230F8;
  v3 = ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7;
  v2 = (signed __int16)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) >> 3;
  switch ( v3 )
  {
    case 0:
      v5 = 59;
      break;
    case 1:
      v5 = 62;
      break;
    case 2:
      v5 = 63;
      break;
    case 3:
      v5 = 64;
      break;
    case 4:
      v5 = 65;
      break;
    default:
      break;
  }
  if ( v2 )
  {
    playTrackForLocationVisit(*(_BYTE *)(a1 + 9) & 0x7F, v2, (_QWORD *)res);
    showMessageWindowForEvent(-1, 2, (&off_51A8A8)[4 * v3], -1, 0, -1, 0, -1);
    if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
    {
      sub_48D030(a2, v5, (int)&v2);
      v4 = v3 | 8 * v2;
      *(_WORD *)(a1 + 4) = 8 * (v3 | (unsigned __int16)(8 * v2)) | *(_WORD *)(a1 + 4) & 7;
    }
  }
  else
  {
    showMessageWindowForEvent(-1, 1, (&off_51A890)[4 * v3], -1, 0, -1, 0, -1);
  }
}

{
  __int16 result; // ax@10
  signed int v2; // [sp+14h] [bp-Ch]@1
  __int16 v3; // [sp+18h] [bp-8h]@1

  v3 = ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7;
  v2 = (signed int)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) >> 3;
  switch ( ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7 )
  {
    case 0:
      v2 += unseededNextRand(2, 5);
      break;
    case 1:
      v2 += unseededNextRand(2, 5);
      break;
    case 2:
      v2 += unseededNextRand(2, 5);
      break;
    case 3:
      v2 += unseededNextRand(2, 5);
      break;
    case 4:
      v2 += unseededNextRand(2, 5);
      break;
    default:
      break;
  }
  if ( v2 > 1000 )
    LOWORD(v2) = 1000;
  result = *(_WORD *)(a1 + 4) & 7 | 8 * (v3 | 8 * v2);
  *(_WORD *)(a1 + 4) = result;
  return result;
}

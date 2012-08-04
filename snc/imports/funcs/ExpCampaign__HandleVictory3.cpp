{
  int result; // eax@2
  int v2; // [sp+10h] [bp-4h]@1

  v2 = this;
  result = *(_DWORD *)(this + 4) + 1;
  switch ( *(_DWORD *)(this + 4) + 1 )
  {
    case 0:
      PlaySmacker(54);
      result = v2;
      *(_BYTE *)(v2 + 12) = 1;
      break;
    case 1:
      PlaySmacker(55);
      result = v2;
      *(_BYTE *)(v2 + 13) = 1;
      break;
    case 2:
      PlaySmacker(56);
      *(_BYTE *)(v2 + 14) = 1;
      *(_BYTE *)(v2 + 15) = 1;
      result = v2;
      *(_BYTE *)(v2 + 53) = 1;
      break;
    case 3:
      PlaySmacker(57);
      *(_BYTE *)(v2 + 15) = 1;
      result = v2;
      *(_BYTE *)(v2 + 54) = 1;
      break;
    case 4:
      result = PlaySmacker(58);
      break;
    default:
      return result;
  }
  return result;
}
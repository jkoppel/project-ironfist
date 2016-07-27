{
  int result; // eax@2
  int v2; // [sp+10h] [bp-4h]@1

  v2 = this;
  result = *(_DWORD *)(this + 4) + 1;
  switch ( *(_DWORD *)(this + 4) + 1 )
  {
    case 0:
      sub_45A2A0(54);
      result = v2;
      *(_BYTE *)(v2 + 12) = 1;
      break;
    case 1:
      sub_45A2A0(55);
      result = v2;
      *(_BYTE *)(v2 + 13) = 1;
      break;
    case 2:
      sub_45A2A0(56);
      *(_BYTE *)(v2 + 14) = 1;
      *(_BYTE *)(v2 + 15) = 1;
      result = v2;
      *(_BYTE *)(v2 + 53) = 1;
      break;
    case 3:
      sub_45A2A0(57);
      *(_BYTE *)(v2 + 15) = 1;
      result = v2;
      *(_BYTE *)(v2 + 54) = 1;
      break;
    case 4:
      result = sub_45A2A0(58);
      break;
    default:
      return result;
  }
  return result;
}

{
  int result; // eax@2
  int v2; // [sp+10h] [bp-4h]@1

  v2 = this;
  result = *(_DWORD *)(this + 4) + 1;
  switch ( *(_DWORD *)(this + 4) + 1 )
  {
    case 0:
      sub_45A2A0(47);
      result = v2;
      *(_BYTE *)(v2 + 12) = 1;
      break;
    case 1:
      sub_45A2A0(48);
      result = v2;
      *(_BYTE *)(v2 + 13) = 1;
      break;
    case 2:
      sub_45A2A0(49);
      *(_BYTE *)(v2 + 14) = 1;
      result = v2;
      *(_BYTE *)(v2 + 15) = 1;
      break;
    case 3:
      sub_45A2A0(50);
      *(_BYTE *)(v2 + 16) = 1;
      result = v2;
      *(_BYTE *)(v2 + 50) = 1;
      break;
    case 4:
      sub_45A2A0(50);
      *(_BYTE *)(v2 + 16) = 1;
      result = v2;
      *(_BYTE *)(v2 + 51) = 1;
      break;
    case 5:
      sub_45A2A0(51);
      *(_BYTE *)(v2 + 17) = 1;
      result = v2;
      *(_BYTE *)(v2 + 18) = 1;
      break;
    case 6:
      sub_45A2A0(52);
      *(_BYTE *)(v2 + 19) = 1;
      result = v2;
      *(_BYTE *)(v2 + 52) = 1;
      break;
    case 7:
      sub_45A2A0(52);
      *(_BYTE *)(v2 + 19) = 1;
      result = v2;
      *(_BYTE *)(v2 + 44) = 1;
      break;
    case 8:
      result = sub_45A2A0(53);
      break;
    default:
      return result;
  }
  return result;
}

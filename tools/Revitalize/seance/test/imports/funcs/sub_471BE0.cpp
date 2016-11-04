{
  int result; // eax@2
  int v2; // [sp+10h] [bp-4h]@1

  v2 = this;
  result = *(_DWORD *)(this + 4) + 1;
  switch ( *(_DWORD *)(this + 4) + 1 )
  {
    case 0:
      sub_45A2A0(39);
      result = v2;
      *(_BYTE *)(v2 + 12) = 1;
      break;
    case 1:
      sub_45A2A0(40);
      result = v2;
      *(_BYTE *)(v2 + 13) = 1;
      break;
    case 2:
      sub_45A2A0(41);
      *(_BYTE *)(v2 + 14) = 1;
      *(_BYTE *)(v2 + 15) = 1;
      result = v2;
      *(_BYTE *)(v2 + 45) = 1;
      break;
    case 3:
      sub_45A2A0(42);
      *(_BYTE *)(v2 + 16) = 1;
      *(_BYTE *)(v2 + 44) = 1;
      result = v2;
      *(_BYTE *)(v2 + 46) = 1;
      break;
    case 4:
      sub_45A2A0(43);
      result = v2;
      *(_BYTE *)(v2 + 17) = 1;
      break;
    case 5:
      sub_45A2A0(43);
      result = v2;
      *(_BYTE *)(v2 + 17) = 1;
      break;
    case 6:
      sub_45A2A0(44);
      *(_BYTE *)(v2 + 18) = 1;
      *(_BYTE *)(v2 + 19) = 1;
      result = v2;
      *(_BYTE *)(v2 + 47) = 1;
      break;
    case 7:
      sub_45A2A0(45);
      *(_BYTE *)(v2 + 19) = 1;
      *(_BYTE *)(v2 + 49) = 1;
      *(_BYTE *)(v2 + 45) = 0;
      *(_BYTE *)(v2 + 47) = 0;
      result = v2;
      *(_BYTE *)(v2 + 48) = 1;
      break;
    case 8:
      result = sub_45A2A0(46);
      break;
    default:
      return result;
  }
  return result;
}

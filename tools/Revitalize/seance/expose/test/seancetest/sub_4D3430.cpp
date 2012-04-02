int __thiscall sub_4D3430(int this)
{
  int v2; // [sp+Ch] [bp-Ch]@1
  int v3; // [sp+10h] [bp-8h]@1
  int v4; // [sp+14h] [bp-4h]@2

  v3 = this;
  v2 = sub_4D3040((int)&unk_535800, this) - 1;
  switch ( v2 )
  {
    case 10:
      v4 = 259;
      break;
    case 0:
      v4 = 257;
      break;
    case 1:
      v4 = 258;
      break;
    case 2:
      v4 = 1;
      break;
    case 3:
      v4 = sub_4D3040((int)&unk_535C24, v3) + 1;
      break;
    case 4:
      v4 = sub_4D3040((int)&unk_536048, v3) + 3;
      break;
    case 5:
      v4 = sub_4D3040((int)&unk_53646C, v3) + 7;
      break;
    case 6:
      v4 = sub_4D3040((int)&unk_536890, v3) + 15;
      break;
    case 7:
      v4 = sub_4D3040((int)&unk_536CB4, v3) + 31;
      break;
    case 8:
      v4 = sub_4D3040((int)&unk_5370D8, v3) + 63;
      break;
    default:
      v4 = sub_4D3040((int)&unk_5374FC, v3) + 127;
      break;
  }
  return v4;
}

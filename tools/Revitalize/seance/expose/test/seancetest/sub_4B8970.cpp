int __stdcall sub_4B8970(int a1)
{
  __int16 v2; // [sp+18h] [bp-18h]@1
  char v3; // [sp+1Ch] [bp-14h]@8
  int v4; // [sp+20h] [bp-10h]@1
  int v5; // [sp+24h] [bp-Ch]@1
  int v6; // [sp+28h] [bp-8h]@1
  char v7; // [sp+2Ch] [bp-4h]@8

  v4 = ((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) & 7;
  v2 = (signed __int16)(unsigned __int8)((unsigned __int8)(*(_WORD *)(a1 + 4) >> 8) >> -5) >> 3;
  v5 = 0;
  v6 = 0;
  switch ( v4 )
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
  sub_4B36D0(v5, v2, 0, (int)&v3, (int)&v6, (int)&v7);
  dword_532CD4 = 0;
  return v6;
}

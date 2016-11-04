{
  signed int result; // eax@10
  signed int v1; // [sp+10h] [bp-80h]@2
  signed int v2; // [sp+10h] [bp-80h]@6
  int v3; // [sp+14h] [bp-7Ch]@2
  int v4; // [sp+18h] [bp-78h]@2
  int v5; // [sp+1Ch] [bp-74h]@2
  int v6; // [sp+20h] [bp-70h]@2
  int v7; // [sp+24h] [bp-6Ch]@2
  int v8; // [sp+2Ch] [bp-64h]@2
  int v9; // [sp+34h] [bp-5Ch]@2
  char v10; // [sp+38h] [bp-58h]@2

  switch ( dword_4ED2F8 )
  {
    case 0:
      memset(&v3, 0, 0x7Cu);
      v3 = 124;
      v8 = 6;
      v4 = *(_DWORD *)dword_522B90;
      v5 = *(_DWORD *)(dword_522B90 + 4);
      v6 = *(_DWORD *)(dword_522B90 + 8);
      v7 = *(_DWORD *)(dword_522B90 + 12);
      v9 = 2;
      strcpy(&v10, "Heroes 2");
      v1 = (*(int (__cdecl **)(int, int *))(*(_DWORD *)dword_4ED2CC + 80))(dword_4ED2CC, &v3);
      if ( v1 )
        sub_4057C0(v1, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED61C + 16);
      ++dword_4ED2F8;
      goto LABEL_13;
    case 1:
      byte_526CD2 = 0;
      byte_526CD3 = 0;
      ++dword_4ED2F8;
      goto LABEL_13;
    case 2:
      v2 = (*(int (__cdecl **)(int, int *, _DWORD, _DWORD, int *))(*(_DWORD *)dword_4ED2CC + 20))(
             dword_4ED2CC,
             &dword_4ED2D0,
             "Dude",
             "Heroes Player",
             &dword_4ED2DC);
      if ( v2 )
        sub_4057C0(v2, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED61C + 46);
      *(_DWORD *)&dword_522B78 = dword_4ED2D0;
      ++dword_4ED2F8;
      goto LABEL_13;
    case 3:
      sub_404EA0();
      if ( dword_5235D4 <= 1 )
        goto LABEL_13;
      result = 1;
      break;
    default:
LABEL_13:
      result = 0;
      break;
  }
  return result;
}

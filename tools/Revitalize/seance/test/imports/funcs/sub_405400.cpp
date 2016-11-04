{
  signed int result; // eax@3
  signed int v1; // [sp+10h] [bp-A4h]@5
  char v2; // [sp+14h] [bp-A0h]@1
  int v3; // [sp+34h] [bp-80h]@7
  int v4; // [sp+38h] [bp-7Ch]@4
  int v5; // [sp+3Ch] [bp-78h]@4
  int v6; // [sp+40h] [bp-74h]@4
  int v7; // [sp+44h] [bp-70h]@4
  int v8; // [sp+48h] [bp-6Ch]@4
  int v9; // [sp+4Ch] [bp-68h]@14
  int v10; // [sp+50h] [bp-64h]@14
  int v11; // [sp+58h] [bp-5Ch]@14
  char v12; // [sp+5Ch] [bp-58h]@14

  sprintf(&v2, "WFHS %d", dword_4ED2FC);
  sub_4CAA50(&v2);
  switch ( dword_4ED2FC )
  {
    case 0:
      if ( dword_4ED300 )
      {
        --dword_4ED300;
        sleep(100);
        result = 0;
      }
      else
      {
        dword_522B98 = 0;
        memset(&v4, 0, 0x7Cu);
        v4 = 124;
        v5 = *(_DWORD *)dword_522B90;
        v6 = *(_DWORD *)(dword_522B90 + 4);
        v7 = *(_DWORD *)(dword_522B90 + 8);
        v8 = *(_DWORD *)(dword_522B90 + 12);
        dword_522B94 = 0;
        if ( ((unsigned int)((unsigned __int64)dword_4ED304 >> 32) ^ abs(dword_4ED304) & 7)
           - ((unsigned __int64)dword_4ED304 >> 32) == 4 )
          v1 = 5000;
        else
          v1 = 2000;
        v3 = (*(int (__cdecl **)(int, int *, signed int, signed int (__stdcall *)(int, int, int, char), _DWORD, _DWORD))(*(_DWORD *)dword_4ED2CC + 56))(
               dword_4ED2CC,
               &v4,
               v1,
               sub_4046E0,
               0,
               0);
        ++dword_4ED304;
        if ( v3 != -2005466916 )
        {
          if ( v3 )
            sub_4057C0(v3, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED6E0 + 38);
          if ( dword_522B94 > 0 )
          {
            dword_4ED300 = 30;
            ++dword_4ED2FC;
          }
          goto LABEL_37;
        }
        dword_4ED300 = 30;
        result = 0;
      }
      return result;
    case 1:
      memset(&v4, 0, 0x7Cu);
      v4 = 124;
      v10 = 6;
      v5 = *(_DWORD *)dword_522B90;
      v6 = *(_DWORD *)(dword_522B90 + 4);
      v7 = *(_DWORD *)(dword_522B90 + 8);
      v8 = *(_DWORD *)(dword_522B90 + 12);
      v11 = 1;
      v9 = dword_522BA0[dword_522B98];
      strcpy(&v12, "Heroes 2");
      v3 = (*(int (__cdecl **)(int, int *))(*(_DWORD *)dword_4ED2CC + 80))(dword_4ED2CC, &v4);
      if ( v3 )
        sub_4057C0(v3, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED6E0 + 57);
      ++dword_4ED2FC;
      goto LABEL_37;
    case 2:
      v3 = (*(int (__cdecl **)(int, int *, _DWORD, _DWORD, int *))(*(_DWORD *)dword_4ED2CC + 20))(
             dword_4ED2CC,
             &dword_4ED2D0,
             "Dude",
             "Heroes Player",
             &dword_4ED2DC);
      if ( v3 )
        sub_4057C0(v3, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED6E0 + 67);
      ++dword_4ED2FC;
      goto LABEL_37;
    case 3:
      dword_4ED308 = getTickCount();
      dword_522BC8 = 0;
      sub_404C60(0, 2, 0x22u, &unk_526CB8);
      ++dword_4ED2FC;
      goto LABEL_37;
    case 4:
      sub_404EA0();
      if ( dword_522BC8 == 1 )
      {
        ++dword_4ED2FC;
      }
      else
      {
        if ( dword_522BC8 == 2 )
        {
          if ( dword_522B98 + 1 < dword_522B94 )
          {
            dword_4ED2FC = 1;
            ++dword_522B98;
          }
          else
          {
            dword_4ED2FC = 0;
          }
          v3 = (*(int (__cdecl **)(int))(*(_DWORD *)dword_4ED2CC + 16))(dword_4ED2CC);
          if ( v3 )
            sub_4057C0(v3, (int)"F:\\h2xsrc\\Source\\dpnetwin.cpp", word_4ED6E0 + 93);
        }
        else
        {
          if ( getTickCount() > dword_4ED308 + 5000 )
            --dword_4ED2FC;
        }
      }
      goto LABEL_37;
    case 5:
      sub_404EA0();
      if ( !dword_4ED2F0 )
        goto LABEL_37;
      result = 1;
      break;
    default:
LABEL_37:
      result = 0;
      break;
  }
  return result;
}

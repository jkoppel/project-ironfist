bool __thiscall sub_4D55E0(void *this)
{
  void *v2; // [sp+10h] [bp-14h]@1
  int v3; // [sp+14h] [bp-10h]@4
  unsigned int v4; // [sp+18h] [bp-Ch]@4
  int v5; // [sp+1Ch] [bp-8h]@1
  int v6; // [sp+20h] [bp-4h]@1

  v2 = this;
  dword_5347A4 = -1;
  v5 = 0;
  v6 = 100000 * dword_537934 - 20;
  while ( v6 > dword_5347A4 && v5 != 257 )
  {
    v3 = sub_4D5480((FILE *)v2);
    v5 = (unsigned __int16)v3;
    v4 = (unsigned int)v3 >> 16;
    if ( (unsigned __int16)v3 == 257 )
    {
      ++dword_5347A4;
      sub_4D3B90(dword_5347A4, 0x2Au);
    }
    else
    {
      switch ( v4 )
      {
        case 1u:
          ++dword_5347A4;
          sub_4D3B90(dword_5347A4, v3);
          break;
        case 2u:
          ++dword_5347A4;
          sub_4D3B90(dword_5347A4++, v3);
          sub_4D3B90(dword_5347A4, v3);
          break;
        case 3u:
          ++dword_5347A4;
          sub_4D3B90(dword_5347A4++, v3);
          sub_4D3B90(dword_5347A4++, v3);
          sub_4D3B90(dword_5347A4, v3);
          break;
        default:
          ++dword_5347A4;
          sub_4D3B90(dword_5347A4++, v3);
          sub_4D3B90(dword_5347A4++, v3);
          sub_4D3B90(dword_5347A4++, v3);
          sub_4D3B90(dword_5347A4++, v3);
          sub_4D3B90(dword_5347A4, v4 - 4);
          break;
      }
    }
  }
  return v5 == 257;
}

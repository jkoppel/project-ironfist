int __thiscall sub_4C2CA0(void *this, int a2)
{
  int result; // eax@1
  int v3; // ecx@2
  int v4; // ecx@3
  char *v5; // ecx@13
  void *v6; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@4
  signed int j; // [sp+10h] [bp-4h]@10

  v6 = this;
  result = a2;
  if ( *(_DWORD *)(a2 + 7) >= *(_DWORD *)&dword_524A78 )
  {
    v3 = *(_DWORD *)&dword_524A78;
    if ( *(_DWORD *)(a2 + 7) == *(_DWORD *)&dword_524A78 )
    {
      LOBYTE(v3) = *(_BYTE *)(a2 + 10);
      v4 = v3 << 16;
      LOWORD(v4) = *(_WORD *)(a2 + 8);
      sub_4C2550(v6, *(_DWORD *)a2, *(_DWORD *)(a2 + 4), v4);
    }
    else
    {
LABEL_4:
      for ( i = 0; ; ++i )
      {
        if ( i >= 196 )
        {
          for ( j = 0; j < 196; ++j )
          {
            if ( !*((_BYTE *)&byte_523660 + 11 * j) )
            {
              logUpTo7Ints((int)"SQ", *(_DWORD *)(a2 + 7), *(int *)&dword_524A78, -999, -999, -999, -999, -999);
              v5 = (char *)&byte_523660 + 11 * j;
              *(_DWORD *)v5 = *(_DWORD *)a2;
              *((_DWORD *)v5 + 1) = *(_DWORD *)(a2 + 4);
              *((_WORD *)v5 + 4) = *(_WORD *)(a2 + 8);
              v5[10] = *(_BYTE *)(a2 + 10);
              goto LABEL_16;
            }
          }
          sub_4C2FB0(v6, 1, 1);
          goto LABEL_4;
        }
        if ( *((_BYTE *)&byte_523660 + 11 * i) && *(int *)((char *)&dword_523667 + 11 * i) == *(_DWORD *)(a2 + 7) )
          break;
      }
      logUpTo7Ints((int)"OQ", *(_DWORD *)(a2 + 7), *(int *)&dword_524A78, -999, -999, -999, -999, -999);
    }
LABEL_16:
    result = sub_4C2FB0(v6, 0, 1);
  }
  return result;
}

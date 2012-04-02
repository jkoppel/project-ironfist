int __thiscall sub_4C2FB0(void *this, int a2, int a3)
{
  int result; // eax@3
  signed int v4; // ecx@12
  char *v5; // eax@12
  signed int v6; // ecx@22
  char *v7; // eax@22
  void *v8; // [sp+Ch] [bp-1Ch]@1
  signed int v9; // [sp+10h] [bp-18h]@4
  int v10; // [sp+14h] [bp-14h]@1
  signed int i; // [sp+18h] [bp-10h]@4
  signed int j; // [sp+18h] [bp-10h]@17
  signed int v13; // [sp+1Ch] [bp-Ch]@1
  int v14; // [sp+20h] [bp-8h]@4
  signed int v15; // [sp+24h] [bp-4h]@15

  v8 = this;
  v13 = 999;
  v10 = 0;
  while ( v13 > 0 )
  {
    result = a2;
    if ( v10 >= a2 )
      break;
    v9 = -1;
    v14 = 999999999;
    v13 = 0;
    for ( i = 0; i < 196; ++i )
    {
      result = 5 * i;
      if ( *((_BYTE *)&byte_523660 + 11 * i) )
      {
        ++v13;
        result = 5 * i;
        if ( *(int *)((char *)&dword_523667 + 11 * i) < v14 )
        {
          v14 = *(int *)((char *)&dword_523667 + 11 * i);
          result = i;
          v9 = i;
        }
      }
    }
    if ( v9 != -1 )
    {
      --v13;
      if ( a3 )
      {
        v4 = v9;
        v5 = (char *)&byte_523660 + 11 * v9;
        LOBYTE(v4) = v5[10];
        v4 <<= 16;
        LOWORD(v4) = *((_WORD *)v5 + 4);
        sub_4C2550(v8, *(_DWORD *)v5, *((_DWORD *)v5 + 1), v4);
      }
      result = 5 * v9;
      *((_BYTE *)&byte_523660 + 11 * v9) = 0;
      ++v10;
    }
  }
  v15 = 1;
  while ( v15 )
  {
    v15 = 0;
    for ( j = 0; j < 196; ++j )
    {
      result = 5 * j;
      if ( *((_BYTE *)&byte_523660 + 11 * j) )
      {
        result = 5 * j;
        if ( *(int *)((char *)&dword_523667 + 11 * j) == *(_DWORD *)&dword_524A78 )
        {
          if ( a3 )
          {
            v6 = j;
            v7 = (char *)&byte_523660 + 11 * j;
            LOBYTE(v6) = v7[10];
            v6 <<= 16;
            LOWORD(v6) = *((_WORD *)v7 + 4);
            sub_4C2550(v8, *(_DWORD *)v7, *((_DWORD *)v7 + 1), v6);
          }
          result = 5 * j;
          *((_BYTE *)&byte_523660 + 11 * j) = 0;
          v15 = 1;
        }
      }
    }
  }
  return result;
}

int __thiscall sub_4D5480(FILE *this)
{
  int result; // eax@4
  FILE *v2; // [sp+Ch] [bp-14h]@1
  signed int i; // [sp+10h] [bp-10h]@16
  signed int v4; // [sp+14h] [bp-Ch]@5
  int v5; // [sp+18h] [bp-8h]@1
  int v6; // [sp+1Ch] [bp-4h]@6

  v2 = this;
  v5 = getc(this);
  if ( v5 == -1 )
  {
    if ( *_errno() )
      sub_4D5F60();
    result = 65793;
  }
  else
  {
    v4 = 0;
    do
    {
      v6 = getc(v2);
      ++v4;
      ++dword_5347A8;
    }
    while ( v6 == v5 && v4 < 255 );
    if ( v6 == -1 )
    {
      if ( *_errno() )
        sub_4D5F60();
    }
    else
    {
      if ( ungetc(v6, v2) == -1 )
        unknown_libname_27();
    }
    if ( v4 == 1 )
    {
      dword_53792C = (dword_53792C << 8) ^ dword_51F9C0[((unsigned int)dword_53792C >> 24) ^ (unsigned __int8)v5];
      result = v5 | 0x10000;
    }
    else
    {
      for ( i = 1; i <= v4; ++i )
        dword_53792C = (dword_53792C << 8) ^ dword_51F9C0[((unsigned int)dword_53792C >> 24) ^ (unsigned __int8)v5];
      result = v5 | (v4 << 16);
    }
  }
  return result;
}

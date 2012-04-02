signed int __fastcall sub_494940(const char *a1, const char *a2)
{
  signed int result; // eax@7
  const char *v3; // [sp+10h] [bp-1Ch]@1
  signed int i; // [sp+18h] [bp-14h]@1
  char v5; // [sp+1Ch] [bp-10h]@1
  char v6[3]; // [sp+1Dh] [bp-Fh]@4
  char v7; // [sp+20h] [bp-Ch]@1
  char v8[8]; // [sp+24h] [bp-8h]@6

  v3 = a1;
  strncpy(&v5, a2, 4u);
  v7 = 0;
  for ( i = 3; i >= 0; --i )
  {
    if ( *(&v5 + i) != 32 )
    {
      v6[i] = 0;
      break;
    }
  }
  strncpy(v8, v3, 4u);
  v8[strlen(&v5)] = 0;
  if ( _strcmpi(&v5, v8) )
    result = 0;
  else
    result = 1;
  return result;
}

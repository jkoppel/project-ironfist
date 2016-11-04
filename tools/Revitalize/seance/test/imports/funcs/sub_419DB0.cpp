{
  char *result; // eax@2
  char *v3; // [sp+Ch] [bp-1Ch]@1
  const char *v4; // [sp+10h] [bp-18h]@1
  const char *v5; // [sp+14h] [bp-14h]@1
  signed int i; // [sp+18h] [bp-10h]@3
  char v7; // [sp+1Ch] [bp-Ch]@5
  signed int v8; // [sp+20h] [bp-8h]@3
  size_t v9; // [sp+24h] [bp-4h]@3

  v3 = a2;
  v4 = a1;
  v5 = (const char *)sub_4C91C0(a1, 46);
  if ( v5 )
  {
    *v5 = 0;
    v8 = 0;
    v9 = strlen(v4);
    for ( i = 0; (signed int)v9 > i; ++i )
    {
      v7 = v4[i];
      if ( v7 >= 97 && v7 <= 122 )
        v7 -= 32;
      if ( v7 >= 65 && v7 <= 90 || v7 >= 48 && v7 <= 57 || v7 == 95 )
        v3[v8++] = v7;
      if ( v8 >= 8 )
        i = 999;
    }
    *v5 = 46;
    result = strcpy(&v3[v8], v5);
  }
  else
  {
    result = strcpy(v3, v4);
  }
  return result;
}

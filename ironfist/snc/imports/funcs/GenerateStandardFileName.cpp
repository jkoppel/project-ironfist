{
  char *a1a; // [sp+Ch] [bp-1Ch]@1
  char *a2a; // [sp+10h] [bp-18h]@1
  char *v4; // [sp+14h] [bp-14h]@1
  signed int i; // [sp+18h] [bp-10h]@3
  char v6; // [sp+1Ch] [bp-Ch]@5
  signed int v7; // [sp+20h] [bp-8h]@3
  int v8; // [sp+24h] [bp-4h]@3

  a1a = a2;
  a2a = (char *)a1;
  v4 = (char *)FindLastToken(a1, 46);
  if ( v4 )
  {
    *v4 = 0;
    v7 = 0;
    v8 = strlen((int)a2a);
    for ( i = 0; v8 > i; ++i )
    {
      v6 = a2a[i];
      if ( v6 >= 97 && v6 <= 122 )
        v6 -= 32;
      if ( v6 >= 65 && v6 <= 90 || v6 >= 48 && v6 <= 57 || v6 == 95 )
        a1a[v7++] = v6;
      if ( v7 >= 8 )
        i = 999;
    }
    *v4 = 46;
    strcpy(&a1a[v7], v4);
  }
  else
  {
    strcpy(a1a, a2a);
  }
}
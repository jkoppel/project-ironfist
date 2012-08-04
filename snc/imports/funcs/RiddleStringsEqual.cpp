{
  int v2; // eax@6
  const char *v4; // [sp+10h] [bp-1Ch]@1
  signed int i; // [sp+18h] [bp-14h]@1
  char a1a; // [sp+1Ch] [bp-10h]@1
  char v7[3]; // [sp+1Dh] [bp-Fh]@4
  char v8; // [sp+20h] [bp-Ch]@1
  char a2a[8]; // [sp+24h] [bp-8h]@6

  v4 = a1;
  strncpy(&a1a, a2, 4u);
  v8 = 0;
  for ( i = 3; i >= 0; --i )
  {
    if ( *(&a1a + i) != 32 )
    {
      v7[i] = 0;
      break;
    }
  }
  strncpy(a2a, v4, 4u);
  a2a[strlen((int)&a1a)] = 0;
  LOBYTE(v2) = stricmp(&a1a, a2a);
  return v2 == 0;
}
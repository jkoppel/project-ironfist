int __cdecl storeTimeFmt(LCID Locale, int a2)
{
  int v2; // esi@1
  int v3; // esi@1
  int v4; // esi@1
  int v6; // eax@3
  int v7; // edx@4
  int i; // eax@9
  char v9; // cl@10
  int v10; // edx@11
  int j; // eax@13
  char v12; // cl@14
  int v13; // [sp+8h] [bp-Ch]@1
  int v14; // [sp+Ch] [bp-8h]@1
  int v15; // [sp+10h] [bp-4h]@1

  v15 = 0;
  v14 = 0;
  v2 = __getlocaleinfo(0, Locale, 0x23u, (int)&v15);
  v3 = __getlocaleinfo(0, Locale, 0x25u, (int)&v14) | v2;
  v4 = __getlocaleinfo(1, Locale, 0x1Eu, (int)&v13) | v3;
  if ( v4 )
    return v4;
  v6 = malloc(0xDu);
  *(_DWORD *)(a2 + 168) = v6;
  if ( v15 )
  {
    *(_BYTE *)v6 = 72;
    v7 = v6 + 1;
    if ( v14 )
    {
      *(_BYTE *)v7 = 72;
LABEL_8:
      ++v7;
      goto LABEL_9;
    }
  }
  else
  {
    *(_BYTE *)v6 = 104;
    v7 = v6 + 1;
    if ( v14 )
    {
      *(_BYTE *)v7 = 104;
      goto LABEL_8;
    }
  }
LABEL_9:
  for ( i = v13; *(_BYTE *)i; ++v7 )
  {
    v9 = *(_BYTE *)i++;
    *(_BYTE *)v7 = v9;
  }
  *(_BYTE *)v7 = 109;
  v10 = v7 + 1;
  if ( v14 )
    *(_BYTE *)v10++ = 109;
  for ( j = v13; *(_BYTE *)j; ++v10 )
  {
    v12 = *(_BYTE *)j++;
    *(_BYTE *)v10 = v12;
  }
  *(_BYTE *)v10 = 115;
  *(_BYTE *)(v10 + 1) = 115;
  *(_BYTE *)(v10 + 2) = 0;
  free(v13);
  return 0;
}

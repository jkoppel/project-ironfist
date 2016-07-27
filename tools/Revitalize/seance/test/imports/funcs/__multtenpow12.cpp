{
  _UNKNOWN *v3; // esi@1
  signed int v4; // edi@1
  char v5; // al@7
  int v6; // eax@7
  int v7; // edx@8
  __int64 v8; // [sp+Ch] [bp-Ch]@9
  int v9; // [sp+14h] [bp-4h]@9

  v3 = &unk_522780;
  v4 = a2;
  if ( a2 )
  {
    if ( a2 < 0 )
    {
      v4 = -a2;
      v3 = &unk_5228E0;
    }
    if ( !a3 )
      *(_WORD *)a1 = 0;
    while ( v4 )
    {
      v3 = (char *)v3 + 84;
      v5 = v4;
      v4 >>= 3;
      v6 = v5 & 7;
      if ( v6 )
      {
        v7 = (int)((char *)v3 + 12 * v6);
        if ( *(_WORD *)v7 >= 0x8000u )
        {
          v8 = *(_QWORD *)v7;
          v9 = *(_DWORD *)(v7 + 8);
          v7 = (int)&v8;
          --*(_DWORD *)((char *)&v8 + 2);
        }
        __ld12mul(a1, v7);
      }
    }
  }
}

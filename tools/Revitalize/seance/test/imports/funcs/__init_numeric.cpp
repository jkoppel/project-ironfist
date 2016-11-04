{
  LCID v0; // edi@1
  int v1; // ebx@2
  int v2; // ebx@2
  int v3; // ebx@2
  signed int result; // eax@3
  char v5; // al@6
  void *v6; // eax@9
  void *v7; // eax@11
  char v8; // dl@13

  v0 = (unsigned __int16)word_521B5A;
  if ( dword_520FC8 )
  {
    v1 = __getlocaleinfo(1, (unsigned __int16)word_521B5A, 0xEu, (int)&dword_521B24);
    v2 = __getlocaleinfo(1, v0, 0xFu, (int)&dword_521B28) | v1;
    v3 = __getlocaleinfo(1, v0, 0x10u, (int)&dword_521B2C) | v2;
    fix_grouping(dword_521B2C);
    if ( v3 )
    {
      free((BOOL)dword_521B24);
      free((BOOL)dword_521B28);
      free((BOOL)dword_521B2C);
      result = -1;
      dword_521B24 = 0;
      dword_521B28 = 0;
      dword_521B2C = 0;
    }
    else
    {
      if ( *off_5226E8 != &unk_5226B0 )
      {
        free((BOOL)*off_5226E8);
        free((BOOL)off_5226E8[1]);
        free((BOOL)off_5226E8[2]);
      }
      *off_5226E8 = dword_521B24;
      off_5226E8[1] = dword_521B28;
      off_5226E8[2] = dword_521B2C;
      v5 = *(_BYTE *)*off_5226E8;
      dword_5211F4 = 1;
      byte_5211F0 = v5;
      result = 0;
    }
  }
  else
  {
    free((BOOL)dword_521B24);
    free((BOOL)dword_521B28);
    free((BOOL)dword_521B2C);
    dword_521B24 = 0;
    dword_521B28 = 0;
    dword_521B2C = 0;
    *off_5226E8 = (void *)malloc(2u);
    if ( *off_5226E8 )
    {
      *(_WORD *)*off_5226E8 = word_4EB140;
      off_5226E8[1] = (void *)malloc(2u);
      v6 = off_5226E8[1];
      if ( v6 )
      {
        *(_BYTE *)v6 = 0;
        off_5226E8[2] = (void *)malloc(2u);
        v7 = off_5226E8[2];
        if ( v7 )
        {
          *(_BYTE *)v7 = 0;
          result = 0;
          v8 = *(_BYTE *)*off_5226E8;
          dword_5211F4 = 1;
          byte_5211F0 = v8;
        }
        else
        {
          result = -1;
        }
      }
      else
      {
        result = -1;
      }
    }
    else
    {
      result = -1;
    }
  }
  return result;
}

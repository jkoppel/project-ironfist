{
  int result; // eax@18
  int v5; // eax@48
  void *v6; // [sp+Ch] [bp-65Ch]@1
  char v7; // [sp+10h] [bp-658h]@61
  int k; // [sp+204h] [bp-464h]@49
  int i; // [sp+208h] [bp-460h]@27
  char v10; // [sp+20Ch] [bp-45Ch]@45
  struct _WIN32_FIND_DATAA FindFileData; // [sp+214h] [bp-454h]@1
  int v12; // [sp+354h] [bp-314h]@30
  char *a2a; // [sp+358h] [bp-310h]@44
  char a1; // [sp+35Ch] [bp-30Ch]@44
  char v15; // [sp+4BCh] [bp-1ACh]@4
  unsigned __int8 v16; // [sp+4C2h] [bp-1A6h]@7
  unsigned __int8 v17; // [sp+4D7h] [bp-191h]@4
  unsigned __int8 v18; // [sp+4D8h] [bp-190h]@5
  int j; // [sp+660h] [bp-8h]@1
  HANDLE hFindFile; // [sp+664h] [bp-4h]@1

  v6 = this;
  sprintf(gText, "%s%s", a2, a3);
  *(_DWORD *)((char *)v6 + 1042) = 0;
  j = 1;
  hFindFile = FindFirstFileA(gText, &FindFileData);
  if ( hFindFile != (HANDLE)-1 )
  {
    while ( j )
    {
      if ( *(_DWORD *)((char *)v6 + 66) != 1
        || (GetMapHeader((int)FindFileData.cFileName, &v15), v17 <= iLastMsgNumHumanPlayers)
        && v18 >= iLastMsgNumHumanPlayers
        && (giMapSizeFilter == 4 || (unsigned __int8)giMapSizes[giMapSizeFilter] == v16)
        && ShowThisMapGame() )
      {
        if ( *(_DWORD *)((char *)v6 + 66) != 4
          || ((GetMapHeader((int)FindFileData.cFileName, &v15), giMapSizeFilter == 4)
           || (unsigned __int8)giMapSizes[giMapSizeFilter] == v16)
          && ShowThisMap() )
          ++*(_DWORD *)((char *)v6 + 1042);
      }
      j = FindNextFileA(hFindFile, &FindFileData);
    }
    FindClose(hFindFile);
  }
  if ( a4 )
  {
    result = *(_DWORD *)((char *)v6 + 1042);
  }
  else
  {
    *(_DWORD *)((char *)v6 + 670) = operator new(351 * (*(_DWORD *)((char *)v6 + 1042) + 1));
    if ( !*(_DWORD *)((char *)v6 + 670) )
      MemError();
    *(_DWORD *)((char *)v6 + 674) = operator new(5 * *(_DWORD *)((char *)v6 + 1042) + 5);
    if ( !*(_DWORD *)((char *)v6 + 674) )
      MemError();
    if ( *(_DWORD *)((char *)v6 + 66) == 4 || *(_DWORD *)((char *)v6 + 66) == 1 )
    {
      *(_DWORD *)((char *)v6 + 678) = operator new(420 * *(_DWORD *)((char *)v6 + 1042));
      if ( !*(_DWORD *)((char *)v6 + 678) )
        MemError();
    }
    for ( i = 0; *(_DWORD *)((char *)v6 + 1042) > i; ++i )
    {
      strcpy((char *)(351 * i + *(_DWORD *)((char *)v6 + 670)), byte_4EDEAC);
      strcpy((char *)(5 * i + *(_DWORD *)((char *)v6 + 674)), byte_4EDEB0);
    }
    v12 = 0;
    sprintf(gText, "%s%s", a2, a3);
    hFindFile = FindFirstFileA(gText, &FindFileData);
    if ( hFindFile != (HANDLE)-1 )
    {
      for ( j = 1; j; j = FindNextFileA(hFindFile, &FindFileData) )
      {
        if ( *(_DWORD *)((char *)v6 + 66) == 1 )
        {
          GetMapHeader((int)FindFileData.cFileName, &v15);
          if ( v17 > iLastMsgNumHumanPlayers
            || v18 < iLastMsgNumHumanPlayers
            || giMapSizeFilter != 4 && (unsigned __int8)giMapSizes[giMapSizeFilter] != v16 )
            continue;
          if ( !ShowThisMapGame() )
            continue;
        }
        if ( *(_DWORD *)((char *)v6 + 66) == 4 )
        {
          GetMapHeader((int)FindFileData.cFileName, &v15);
          if ( giMapSizeFilter != 4 )
          {
            if ( (unsigned __int8)giMapSizes[giMapSizeFilter] != v16 )
              continue;
          }
          if ( !ShowThisMap() )
            continue;
        }
        strcpy(&a1, FindFileData.cFileName);
        a2a = (char *)FindLastToken(&a1, 46);
        if ( a2a )
        {
          strcpy(&v10, a2a);
          *a2a = 0;
        }
        for ( i = 0; i < v12; ++i )
        {
          LOBYTE(v5) = stricmp(&a1, (char *)(351 * i + *(_DWORD *)((char *)v6 + 670)));
          if ( v5 < 0 )
          {
            for ( k = v12; k > i; --k )
            {
              strcpy(
                (char *)(351 * k + *(_DWORD *)((char *)v6 + 670)),
                (char *)(*(_DWORD *)((char *)v6 + 670) + 351 * (k - 1)));
              strcpy(
                (char *)(5 * k + *(_DWORD *)((char *)v6 + 674)),
                (char *)(*(_DWORD *)((char *)v6 + 674) + 5 * k - 5));
            }
            break;
          }
        }
        strcpy((char *)(351 * i + *(_DWORD *)((char *)v6 + 670)), &a1);
        strcpy((char *)(5 * i + *(_DWORD *)((char *)v6 + 674)), &v10);
        ++v12;
      }
      FindClose(hFindFile);
    }
    if ( *(_DWORD *)((char *)v6 + 66) == 1 || *(_DWORD *)((char *)v6 + 66) == 4 )
    {
      for ( i = 0; i < v12; ++i )
      {
        sprintf(&v7, "%s%s", 351 * i + *(_DWORD *)((char *)v6 + 670), 5 * i + *(_DWORD *)((char *)v6 + 674));
        GetMapHeader((int)&v7, (void *)(420 * i + *(_DWORD *)((char *)v6 + 678)));
      }
    }
    result = *(_DWORD *)((char *)v6 + 1042);
  }
  return result;
}
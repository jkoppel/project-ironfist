{
  int result; // eax@18
  void *v5; // [sp+Ch] [bp-65Ch]@1
  char v6; // [sp+10h] [bp-658h]@61
  int k; // [sp+204h] [bp-464h]@49
  int i; // [sp+208h] [bp-460h]@27
  char v9; // [sp+20Ch] [bp-45Ch]@45
  struct _WIN32_FIND_DATAA FindFileData; // [sp+214h] [bp-454h]@1
  int v11; // [sp+354h] [bp-314h]@30
  char *v12; // [sp+358h] [bp-310h]@44
  char v13; // [sp+35Ch] [bp-30Ch]@44
  char v14; // [sp+4BCh] [bp-1ACh]@4
  unsigned __int8 v15; // [sp+4C2h] [bp-1A6h]@7
  unsigned __int8 v16; // [sp+4D7h] [bp-191h]@4
  unsigned __int8 v17; // [sp+4D8h] [bp-190h]@5
  int j; // [sp+660h] [bp-8h]@1
  HANDLE hFindFile; // [sp+664h] [bp-4h]@1

  v5 = this;
  sprintf(globBuf, "%s%s", a2, a3);
  *(_DWORD *)((char *)v5 + 1042) = 0;
  j = 1;
  hFindFile = FindFirstFileA(globBuf, &FindFileData);
  if ( hFindFile != (HANDLE)-1 )
  {
    while ( j )
    {
      if ( *(_DWORD *)((char *)v5 + 66) != 1
        || (sub_40B430((int)FindFileData.cFileName, &v14), v16 <= dword_5235D4)
        && v17 >= dword_5235D4
        && (dword_4EDE90 == 4 || (unsigned __int8)byte_4F19D0[dword_4EDE90] == v15)
        && sub_40B4D0() )
      {
        if ( *(_DWORD *)((char *)v5 + 66) != 4
          || ((sub_40B430((int)FindFileData.cFileName, &v14), dword_4EDE90 == 4)
           || (unsigned __int8)byte_4F19D0[dword_4EDE90] == v15)
          && unknown_libname_3() )
          ++*(_DWORD *)((char *)v5 + 1042);
      }
      j = FindNextFileA(hFindFile, &FindFileData);
    }
    FindClose(hFindFile);
  }
  if ( a4 )
  {
    result = *(_DWORD *)((char *)v5 + 1042);
  }
  else
  {
    *(_DWORD *)((char *)v5 + 670) = operator new(351 * (*(_DWORD *)((char *)v5 + 1042) + 1));
    if ( !*(_DWORD *)((char *)v5 + 670) )
      fatalOutOfMemoryError();
    *(_DWORD *)((char *)v5 + 674) = operator new(5 * *(_DWORD *)((char *)v5 + 1042) + 5);
    if ( !*(_DWORD *)((char *)v5 + 674) )
      fatalOutOfMemoryError();
    if ( *(_DWORD *)((char *)v5 + 66) == 4 || *(_DWORD *)((char *)v5 + 66) == 1 )
    {
      *(_DWORD *)((char *)v5 + 678) = operator new(420 * *(_DWORD *)((char *)v5 + 1042));
      if ( !*(_DWORD *)((char *)v5 + 678) )
        fatalOutOfMemoryError();
    }
    for ( i = 0; *(_DWORD *)((char *)v5 + 1042) > i; ++i )
    {
      strcpy((char *)(351 * i + *(_DWORD *)((char *)v5 + 670)), byte_4EDEAC);
      strcpy((char *)(5 * i + *(_DWORD *)((char *)v5 + 674)), byte_4EDEB0);
    }
    v11 = 0;
    sprintf(globBuf, "%s%s", a2, a3);
    hFindFile = FindFirstFileA(globBuf, &FindFileData);
    if ( hFindFile != (HANDLE)-1 )
    {
      for ( j = 1; j; j = FindNextFileA(hFindFile, &FindFileData) )
      {
        if ( *(_DWORD *)((char *)v5 + 66) == 1 )
        {
          sub_40B430((int)FindFileData.cFileName, &v14);
          if ( v16 > dword_5235D4
            || v17 < dword_5235D4
            || dword_4EDE90 != 4 && (unsigned __int8)byte_4F19D0[dword_4EDE90] != v15 )
            continue;
          if ( !sub_40B4D0() )
            continue;
        }
        if ( *(_DWORD *)((char *)v5 + 66) == 4 )
        {
          sub_40B430((int)FindFileData.cFileName, &v14);
          if ( dword_4EDE90 != 4 )
          {
            if ( (unsigned __int8)byte_4F19D0[dword_4EDE90] != v15 )
              continue;
          }
          if ( !unknown_libname_3() )
            continue;
        }
        strcpy(&v13, FindFileData.cFileName);
        v12 = (char *)sub_4C91C0(&v13, 46);
        if ( v12 )
        {
          strcpy(&v9, v12);
          *v12 = 0;
        }
        for ( i = 0; i < v11; ++i )
        {
          if ( _strcmpi(&v13, (const char *)(351 * i + *(_DWORD *)((char *)v5 + 670))) < 0 )
          {
            for ( k = v11; k > i; --k )
            {
              strcpy(
                (char *)(351 * k + *(_DWORD *)((char *)v5 + 670)),
                (const char *)(*(_DWORD *)((char *)v5 + 670) + 351 * (k - 1)));
              strcpy(
                (char *)(5 * k + *(_DWORD *)((char *)v5 + 674)),
                (const char *)(*(_DWORD *)((char *)v5 + 674) + 5 * k - 5));
            }
            break;
          }
        }
        strcpy((char *)(351 * i + *(_DWORD *)((char *)v5 + 670)), &v13);
        strcpy((char *)(5 * i + *(_DWORD *)((char *)v5 + 674)), &v9);
        ++v11;
      }
      FindClose(hFindFile);
    }
    if ( *(_DWORD *)((char *)v5 + 66) == 1 || *(_DWORD *)((char *)v5 + 66) == 4 )
    {
      for ( i = 0; i < v11; ++i )
      {
        sprintf(&v6, "%s%s", 351 * i + *(_DWORD *)((char *)v5 + 670), 5 * i + *(_DWORD *)((char *)v5 + 674));
        sub_40B430((int)&v6, (void *)(420 * i + *(_DWORD *)((char *)v5 + 678)));
      }
    }
    result = *(_DWORD *)((char *)v5 + 1042);
  }
  return result;
}

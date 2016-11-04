{
  const WCHAR *v0; // edi@2
  LPSTR v1; // ebx@3
  BOOL result; // eax@6
  const WCHAR *i; // esi@12
  int v4; // esi@15
  DWORD v5; // eax@15
  int v6; // ebp@15
  int v7; // eax@16
  BOOL v8; // ebx@16
  LPSTR j; // ebp@25
  int v10; // ebp@28
  CHAR *v11; // [sp+10h] [bp-4h]@0
  int v12; // [sp+10h] [bp-4h]@28

  if ( dword_52157C )
  {
    v1 = v11;
    v0 = (const WCHAR *)v11;
  }
  else
  {
    v0 = GetEnvironmentStringsW();
    if ( v0 )
    {
      dword_52157C = 1;
      v1 = v11;
    }
    else
    {
      v1 = GetEnvironmentStrings();
      if ( !v1 )
        return 0;
      dword_52157C = 2;
    }
  }
  if ( dword_52157C == 1 )
  {
    if ( v0 || (v0 = GetEnvironmentStringsW()) != 0 )
    {
      for ( i = v0; *i; ++i )
      {
        do
          ++i;
        while ( *i );
      }
      v4 = i - v0 + 1;
      v5 = WideCharToMultiByte(0, 0, v0, v4, 0, 0, 0, 0);
      v6 = v5;
      if ( v5 && (v7 = malloc(v5), (v8 = v7) != 0) )
      {
        if ( !WideCharToMultiByte(0, 0, v0, v4, (LPSTR)v7, v6, 0, 0) )
        {
          free(v8);
          v8 = 0;
        }
        FreeEnvironmentStringsW((LPWSTR)v0);
        result = v8;
      }
      else
      {
        FreeEnvironmentStringsW((LPWSTR)v0);
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    if ( dword_52157C == 2 )
    {
      if ( v1 || (v1 = GetEnvironmentStrings()) != 0 )
      {
        for ( j = v1; *j; ++j )
        {
          do
            ++j;
          while ( *j );
        }
        v10 = j - v1 + 1;
        v12 = malloc(v10);
        if ( v12 )
        {
          memcpy((void *)v12, v1, v10);
          FreeEnvironmentStringsA(v1);
          result = v12;
        }
        else
        {
          FreeEnvironmentStringsA(v1);
          result = 0;
        }
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

int __cdecl parse_cmdline(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax@1
  int i; // ecx@1
  int v7; // edi@1
  int v8; // edx@2
  unsigned __int8 v9; // dl@6
  char v10; // dl@21
  bool v11; // esi@29
  int v12; // edx@36
  signed int v13; // ebx@38
  unsigned int j; // edx@38
  unsigned int v15; // ebp@48
  int v16; // edx@48
  int v17; // ebp@51
  unsigned __int8 v18; // dl@52
  unsigned __int8 v19; // dl@60

  result = a5;
  i = a1;
  v7 = a3;
  *(_DWORD *)a5 = 0;
  *(_DWORD *)a4 = 1;
  if ( a2 )
  {
    v8 = a2;
    a2 += 4;
    *(_DWORD *)v8 = a3;
  }
  if ( *(_BYTE *)a1 == 34 )
  {
    for ( i = a1 + 1; *(_BYTE *)i != 34; ++i )
    {
      if ( !*(_BYTE *)i )
        break;
      if ( byte_521581[*(_BYTE *)i] & 4 )
      {
        ++*(_DWORD *)a5;
        if ( v7 )
        {
          v10 = *(_BYTE *)i++;
          *(_BYTE *)v7++ = v10;
        }
      }
      ++*(_DWORD *)a5;
      if ( v7 )
        *(_BYTE *)v7++ = *(_BYTE *)i;
    }
    ++*(_DWORD *)a5;
    if ( v7 )
      *(_BYTE *)v7++ = 0;
    if ( *(_BYTE *)i == 34 )
      ++i;
  }
  else
  {
    do
    {
      ++*(_DWORD *)a5;
      if ( v7 )
        *(_BYTE *)v7++ = *(_BYTE *)i;
      v9 = *(_BYTE *)i++;
      if ( byte_521581[v9] & 4 )
      {
        ++*(_DWORD *)a5;
        if ( v7 )
          *(_BYTE *)v7++ = *(_BYTE *)i;
        ++i;
      }
      if ( v9 == 32 )
        break;
      if ( !v9 )
        goto LABEL_14;
    }
    while ( v9 != 9 );
    if ( !v9 )
    {
LABEL_14:
      --i;
      goto LABEL_29;
    }
    if ( v7 )
      *(_BYTE *)(v7 - 1) = 0;
  }
LABEL_29:
  v11 = 0;
LABEL_30:
  if ( *(_BYTE *)i )
  {
    while ( *(_BYTE *)i == 32 || *(_BYTE *)i == 9 )
      ++i;
    if ( *(_BYTE *)i )
    {
      if ( a2 )
      {
        v12 = a2;
        a2 += 4;
        *(_DWORD *)v12 = v7;
      }
      ++*(_DWORD *)a4;
      while ( 1 )
      {
        while ( 1 )
        {
          v13 = 1;
          for ( j = 0; *(_BYTE *)i == 92; ++j )
            ++i;
          if ( *(_BYTE *)i == 34 )
          {
            if ( !(j & 1) )
            {
              if ( v11 && *(_BYTE *)(i + 1) == 34 )
                ++i;
              else
                v13 = 0;
              v11 = (unsigned int)v11 < 1;
            }
            j >>= 1;
          }
          v15 = j;
          v16 = j - 1;
          if ( v15 )
          {
            do
            {
              if ( v7 )
                *(_BYTE *)v7++ = 92;
              v17 = v16;
              ++*(_DWORD *)a5;
              --v16;
            }
            while ( v17 );
          }
          v18 = *(_BYTE *)i;
          if ( !*(_BYTE *)i || !v11 && (v18 == 32 || v18 == 9) )
          {
            if ( v7 )
              *(_BYTE *)v7++ = 0;
            ++*(_DWORD *)a5;
            goto LABEL_30;
          }
          if ( v13 )
            break;
LABEL_64:
          ++i;
        }
        if ( !v7 )
        {
          if ( byte_521581[v18] & 4 )
          {
            ++i;
            ++*(_DWORD *)a5;
          }
          ++*(_DWORD *)a5;
          goto LABEL_64;
        }
        if ( byte_521581[v18] & 4 )
        {
          *(_BYTE *)v7 = v18;
          ++i;
          ++v7;
          ++*(_DWORD *)a5;
        }
        v19 = *(_BYTE *)i;
        ++v7;
        ++i;
        *(_BYTE *)(v7 - 1) = v19;
        ++*(_DWORD *)a5;
      }
    }
  }
  if ( a2 )
    *(_DWORD *)a2 = 0;
  ++*(_DWORD *)a4;
  return result;
}

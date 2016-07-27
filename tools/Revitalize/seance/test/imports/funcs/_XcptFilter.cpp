{
  LPVOID v2; // eax@1
  LPVOID v3; // esi@1
  int v4; // eax@1
  void (__cdecl *v5)(_DWORD); // edx@2
  LONG result; // eax@4
  int v7; // edi@7
  int v8; // ebx@8
  int v9; // ecx@9
  int v10; // ebx@11
  int v11; // eax@11

  v2 = _getptd();
  v3 = v2;
  v4 = xcptlookup(a1, *((_DWORD *)v2 + 20));
  if ( v4 && (v5 = *(void (__cdecl **)(_DWORD))(v4 + 8)) != 0 )
  {
    if ( v5 == (void (__cdecl *)(_DWORD))5 )
    {
      *(_DWORD *)(v4 + 8) = 0;
      result = 1;
    }
    else
    {
      if ( v5 == (void (__cdecl *)(_DWORD))1 )
      {
        result = -1;
      }
      else
      {
        v7 = *((_DWORD *)v3 + 21);
        *((_DWORD *)v3 + 21) = ExceptionInfo;
        if ( *(_DWORD *)(v4 + 4) == 8 )
        {
          v8 = dword_521568;
          if ( dword_521568 + dword_52156C > dword_521568 )
          {
            v9 = 12 * dword_521568;
            do
            {
              v9 += 12;
              ++v8;
              *(_DWORD *)(*((_DWORD *)v3 + 20) + v9 - 4) = 0;
            }
            while ( dword_521568 + dword_52156C > v8 );
          }
          v10 = *((_DWORD *)v3 + 22);
          v11 = *(_DWORD *)v4;
          switch ( v11 )
          {
            case -1073741682:
              *((_DWORD *)v3 + 22) = 131;
              break;
            case -1073741680:
              *((_DWORD *)v3 + 22) = 129;
              break;
            case -1073741679:
              *((_DWORD *)v3 + 22) = 132;
              break;
            case -1073741677:
              *((_DWORD *)v3 + 22) = 133;
              break;
            case -1073741683:
              *((_DWORD *)v3 + 22) = 130;
              break;
            case -1073741681:
              *((_DWORD *)v3 + 22) = 134;
              break;
            case -1073741678:
              *((_DWORD *)v3 + 22) = 138;
              break;
          }
          ((void (__cdecl *)(signed int, _DWORD))v5)(8, *((_DWORD *)v3 + 22));
          *((_DWORD *)v3 + 22) = v10;
        }
        else
        {
          *(_DWORD *)(v4 + 8) = 0;
          v5(*(_DWORD *)(v4 + 4));
        }
        result = -1;
        *((_DWORD *)v3 + 21) = v7;
      }
    }
  }
  else
  {
    result = UnhandledExceptionFilter(ExceptionInfo);
  }
  return result;
}

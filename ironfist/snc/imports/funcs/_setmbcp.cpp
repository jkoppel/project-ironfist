{
  UINT v1; // eax@1
  UINT v2; // ebp@1
  signed int result; // eax@2
  unsigned int v4; // eax@5
  char *v5; // esi@10
  char v6; // cl@11
  unsigned int v7; // eax@12
  signed int v8; // eax@15
  LCID v9; // eax@17
  unsigned int v10; // eax@18
  char *i; // esi@19
  char v12; // cl@20
  unsigned int v13; // edx@21
  char v14; // cl@22
  int v15; // ebx@26
  int *v16; // ecx@26
  int v17; // eax@26
  int v18; // ecx@26
  int v19; // [sp+10h] [bp-18h]@5
  struct _cpinfo CPInfo; // [sp+14h] [bp-14h]@8

  _lock(25);
  v1 = getSystemCP(a1);
  v2 = v1;
  if ( __mbcodepage == v1 )
  {
    _unlock(25);
    result = 0;
  }
  else if ( v1 )
  {
    v19 = 0;
    v4 = (unsigned int)&unk_5216A8;
    while ( *(_DWORD *)v4 != v2 )
    {
      v4 += 48;
      ++v19;
      if ( v4 >= (unsigned int)__badioinfo )
      {
        if ( GetCPInfo(v2, &CPInfo) == 1 )
        {
          memset(_mbctype, 0, 0x100u);
          _mbctype[256] = 0;
          if ( CPInfo.MaxCharSize <= 1 )
          {
            v9 = 0;
            __mbcodepage = 0;
          }
          else
          {
            v5 = (char *)CPInfo.LeadByte;
            if ( CPInfo.LeadByte[0] )
            {
              do
              {
                v6 = v5[1];
                if ( !v6 )
                  break;
                v7 = (unsigned __int8)*v5;
                if ( (unsigned __int8)v6 >= v7 )
                {
                  do
                  {
                    byte_521581[v7] |= 4u;
                    ++v7;
                  }
                  while ( (unsigned __int8)v5[1] >= v7 );
                }
                v5 += 2;
              }
              while ( *v5 );
            }
            v8 = 1;
            do
            {
              byte_521581[v8] |= 8u;
              ++v8;
            }
            while ( (unsigned int)v8 < 0xFF );
            __mbcodepage = v2;
            v9 = CPtoLCID(v2);
          }
          __mblcid = v9;
          __mbulinfo = 0;
          *(&__mbulinfo + 1) = 0;
          *(&__mbulinfo + 2) = 0;
          _unlock(25);
          result = 0;
        }
        else if ( dword_52169C )
        {
          setSBCS();
          _unlock(25);
          result = 0;
        }
        else
        {
          _unlock(25);
          result = -1;
        }
        return result;
      }
    }
    v10 = 0;
    memset(_mbctype, 0, 0x100u);
    _mbctype[256] = 0;
    do
    {
      for ( i = (char *)&unk_5216B8 + 8 * (6 * v19 + v10); *i; i += 2 )
      {
        v12 = i[1];
        if ( !v12 )
          break;
        v13 = (unsigned __int8)*i;
        if ( (unsigned __int8)v12 >= v13 )
        {
          v14 = byte_5216A0[v10];
          do
          {
            byte_521581[v13] |= v14;
            ++v13;
          }
          while ( (unsigned __int8)i[1] >= v13 );
        }
      }
      ++v10;
    }
    while ( v10 < 4 );
    __mbcodepage = v2;
    __mblcid = CPtoLCID(v2);
    v15 = dword_5216B0[12 * v19];
    v16 = &dword_5216AC[12 * v19];
    v17 = *v16;
    v18 = v16[2];
    __mbulinfo = v17;
    *(&__mbulinfo + 1) = v15;
    *(&__mbulinfo + 2) = v18;
    _unlock(25);
    result = 0;
  }
  else
  {
    setSBCS();
    _unlock(25);
    result = 0;
  }
  return result;
}
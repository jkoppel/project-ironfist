{
  int v3; // ebx@1
  int v4; // edx@1
  int v5; // esi@1
  int v6; // ebx@2
  signed int result; // eax@3
  int v8; // edi@3
  int v9; // ebp@7
  signed int v10; // eax@12
  signed int v11; // ST04_4@13
  int v12; // ecx@14
  int v13; // ebx@14
  int v14; // ecx@15
  int v15; // [sp+10h] [bp-18h]@1
  int v16; // [sp+14h] [bp-14h]@1
  int v17; // [sp+18h] [bp-10h]@1
  char v18; // [sp+1Ch] [bp-Ch]@5

  v3 = (*(_WORD *)(a1 + 10) & 0x7FFF) - 16383;
  v4 = *(_DWORD *)(a1 + 2);
  v5 = *(_WORD *)(a1 + 10) & 0x8000;
  v15 = *(_DWORD *)(a1 + 6);
  v16 = v4;
  v17 = *(_WORD *)a1 << 16;
  if ( v3 == -16383 )
  {
    v6 = 0;
    if ( _IsZeroMan((int)&v15) )
    {
      result = 0;
      v8 = a3;
    }
    else
    {
      _FillZeroMan((int)&v15);
      v8 = a3;
      result = 2;
    }
  }
  else
  {
    _CopyMan((int)&v18, (int)&v15);
    v8 = a3;
    if ( _RoundMan((int)&v15, *(_DWORD *)(a3 + 8)) )
      ++v3;
    v9 = *(_DWORD *)(a3 + 4);
    if ( *(_DWORD *)(a3 + 4) - *(_DWORD *)(a3 + 8) <= v3 )
    {
      if ( v3 > v9 )
      {
        if ( *(_DWORD *)a3 > v3 )
        {
          v6 = *(_DWORD *)(a3 + 20) + v3;
          v11 = *(_DWORD *)(a3 + 12);
          v15 &= 0x7FFFFFFFu;
          _ShrMan((unsigned int *)&v15, v11);
          result = 0;
        }
        else
        {
          _FillZeroMan((int)&v15);
          v10 = *(_DWORD *)(a3 + 12);
          v15 |= 0x80000000u;
          _ShrMan((unsigned int *)&v15, v10);
          v6 = *(_DWORD *)a3 + *(_DWORD *)(a3 + 20);
          result = 1;
        }
      }
      else
      {
        _CopyMan((int)&v15, (int)&v18);
        _ShrMan((unsigned int *)&v15, v9 - v3);
        _RoundMan((int)&v15, *(_DWORD *)(a3 + 8));
        v6 = 0;
        _ShrMan((unsigned int *)&v15, *(_DWORD *)(a3 + 12) + 1);
        result = 2;
      }
    }
    else
    {
      v6 = 0;
      _FillZeroMan((int)&v15);
      result = 2;
    }
  }
  v12 = *(_DWORD *)(v8 + 16);
  v13 = v15 | (((unsigned int)v5 < 1) - 1) & 0x80000000 | (v6 << (31 - *(_BYTE *)(v8 + 12)));
  if ( v12 == 64 )
  {
    v14 = v16;
    *(_DWORD *)(a2 + 4) = v13;
    *(_DWORD *)a2 = v14;
  }
  else
  {
    if ( v12 == 32 )
      *(_DWORD *)a2 = v13;
  }
  return result;
}

{
  int v3; // eax@1
  DWORD v4; // edi@2
  LONG v5; // ebx@6
  int v6; // eax@8
  int result; // eax@14

  v3 = *(_DWORD *)(a1 + 12);
  if ( !(v3 & 0x83) || (v4 = a3) != 0 && a3 != 1 && a3 != 2 )
  {
    *_errno() = 22;
    result = -1;
  }
  else
  {
    *(_DWORD *)(a1 + 12) = v3 & 0xFFFFFFEF;
    if ( a3 == 1 )
    {
      v4 = 0;
      v5 = _ftell_lk(a1) + a2;
    }
    else
    {
      v5 = a2;
    }
    _flush(a1);
    v6 = *(_DWORD *)(a1 + 12);
    if ( v6 & 0x80 )
    {
      *(_DWORD *)(a1 + 12) = v6 & 0xFFFFFFFC;
    }
    else
    {
      if ( v6 & 1 && v6 & 8 )
      {
        if ( !(BYTE1(v6) & 4) )
          *(_DWORD *)(a1 + 24) = 512;
      }
    }
    result = -((unsigned int)(_lseek(*(_DWORD *)(a1 + 16), v5, v4) + 1) < 1);
  }
  return result;
}

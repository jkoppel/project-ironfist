{
  unsigned int v4; // ebp@1
  int v6; // eax@8
  int v7; // edx@9
  DWORD v8; // ecx@13
  signed int v9; // eax@15
  int v10; // eax@18
  void *v11; // ecx@19
  void *buf; // [sp+10h] [bp-Ch]@1
  int v13; // [sp+14h] [bp-8h]@1
  int v14; // [sp+18h] [bp-4h]@4

  buf = a1;
  v13 = a2 * a3;
  v4 = a2 * a3;
  if ( !(a2 * a3) )
    return 0;
  if ( a4->_flag & 0x10C )
    v14 = a4->_bufsiz;
  else
    v14 = 4096;
  if ( !v13 )
    return a3;
  while ( 1 )
  {
    if ( a4->_flag & 0x10C )
    {
      v6 = a4->_cnt;
      if ( v6 )
      {
        v7 = v4;
        if ( v4 >= v6 )
          v7 = a4->_cnt;
        v4 -= v7;
        memcpy(buf, a4->_ptr, v7);
        a4->_cnt -= v7;
        a4->_ptr += v7;
        buf = (char *)buf + v7;
        goto LABEL_20;
      }
    }
    if ( v14 > v4 )
      break;
    v8 = v4;
    if ( v14 )
      v8 = v4 - v4 % v14;
    v9 = _read(a4->_file, buf, v8);
    if ( !v9 )
    {
      a4->_flag |= 0x10u;
      return (v13 - v4) / a2;
    }
    if ( v9 == -1 )
    {
      a4->_flag |= 0x20u;
      return (v13 - v4) / a2;
    }
    v4 -= v9;
    buf = (char *)buf + v9;
LABEL_20:
    if ( !v4 )
      return a3;
  }
  v10 = _filbuf(a4);
  if ( v10 != -1 )
  {
    v11 = buf;
    --v4;
    buf = (char *)buf + 1;
    *(_BYTE *)v11 = v10;
    v14 = a4->_bufsiz;
    goto LABEL_20;
  }
  return (v13 - v4) / a2;
}

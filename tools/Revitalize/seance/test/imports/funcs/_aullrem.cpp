{
  unsigned __int64 v2; // qtt@2
  int result; // eax@2
  unsigned int v4; // ecx@3
  unsigned int v5; // ebx@3
  unsigned __int64 v6; // qax@3
  unsigned __int8 v7; // cf@4
  unsigned int v8; // eax@5
  int v9; // ecx@5
  unsigned __int64 v10; // qax@5

  if ( HIDWORD(a2) )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = __RCR__(v5, v7);
      v7 = BYTE4(v6) & 1;
      HIDWORD(v6) >>= 1;
      LODWORD(v6) = __RCR__(v6, v7);
    }
    while ( v4 );
    v8 = v6 / v5;
    v9 = HIDWORD(a2) * v8;
    v10 = (unsigned int)a2 * (unsigned __int64)v8;
    v7 = __CFADD__(v9, HIDWORD(v10));
    HIDWORD(v10) += v9;
    if ( v7 || HIDWORD(v10) > HIDWORD(a1) || HIDWORD(v10) >= HIDWORD(a1) && (unsigned int)v10 > (unsigned int)a1 )
      LODWORD(v10) = v10 - a2;
    result = -(v10 - (_DWORD)a1);
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    result = v2 % (unsigned int)a2;
  }
  return result;
}

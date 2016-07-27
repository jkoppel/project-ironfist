{
  unsigned __int64 v3; // qtt@2
  __int64 result; // qax@2
  unsigned int v5; // ecx@3
  unsigned int v6; // ebx@3
  unsigned __int64 v7; // qax@3
  unsigned __int8 v8; // cf@4
  unsigned int v9; // eax@5
  unsigned int v10; // esi@5
  int v11; // ecx@5
  unsigned __int64 v12; // qax@5

  if ( a3 )
  {
    v5 = a3;
    v6 = a2;
    v7 = a1;
    do
    {
      v8 = v5 & 1;
      v5 >>= 1;
      v6 = __RCR__(v6, v8);
      v8 = BYTE4(v7) & 1;
      HIDWORD(v7) >>= 1;
      LODWORD(v7) = __RCR__(v7, v8);
    }
    while ( v5 );
    v9 = v7 / v6;
    v10 = v9;
    v11 = a3 * v9;
    v12 = v9 * (unsigned __int64)a2;
    v8 = __CFADD__(v11, HIDWORD(v12));
    HIDWORD(v12) += v11;
    if ( v8 || HIDWORD(v12) > HIDWORD(a1) || HIDWORD(v12) >= HIDWORD(a1) && (unsigned int)v12 > (unsigned int)a1 )
      --v10;
    result = v10;
  }
  else
  {
    LODWORD(v3) = a1;
    HIDWORD(v3) = HIDWORD(a1) % a2;
    LODWORD(result) = v3 / a2;
    HIDWORD(result) = HIDWORD(a1) / a2;
  }
  return result;
}

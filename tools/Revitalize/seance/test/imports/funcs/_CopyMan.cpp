{
  int result; // eax@1
  int v3; // ecx@1
  signed int v4; // edx@1
  int v5; // esi@2

  result = a2;
  v3 = a1;
  v4 = 3;
  do
  {
    v5 = *(_DWORD *)result;
    result += 4;
    *(_DWORD *)v3 = v5;
    v3 += 4;
    --v4;
  }
  while ( v4 );
  return result;
}

{
  int v2; // eax@1
  unsigned int *v3; // ebx@1
  signed int v4; // ebp@1
  int v5; // edx@1
  unsigned int v6; // edi@2
  int v7; // ST18_4@2
  unsigned int v8; // edi@2
  int v9; // edi@2
  signed int v10; // ecx@3
  int v11; // esi@3
  int result; // eax@3
  int v13; // edx@3
  int v14; // [sp+10h] [bp-10h]@1

  v14 = a2 / 32;
  v2 = (((unsigned __int64)a2 >> 32) ^ abs(a2) & 0x1F) - ((unsigned __int64)a2 >> 32);
  v3 = a1;
  v4 = 3;
  v5 = 0;
  do
  {
    v6 = *v3;
    ++v3;
    v7 = ~(-1 << v2) & v6;
    v8 = v6 >> v2;
    *(v3 - 1) = v8;
    v9 = v5 | v8;
    v5 = v7 << (32 - v2);
    --v4;
    *(v3 - 1) = v9;
  }
  while ( v4 );
  v10 = 2;
  v11 = (int)(a1 + 2);
  result = 4 * v14;
  v13 = (int)&a1[-v14 + 2];
  do
  {
    if ( v14 > v10 )
    {
      *(_DWORD *)v11 = 0;
    }
    else
    {
      result = *(_DWORD *)v13;
      *(_DWORD *)v11 = *(_DWORD *)v13;
    }
    v13 -= 4;
    v11 -= 4;
    --v10;
  }
  while ( v10 >= 0 );
  return result;
}

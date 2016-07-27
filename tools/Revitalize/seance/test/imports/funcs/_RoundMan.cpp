{
  int v2; // ebx@1
  int v3; // esi@4
  int v5; // [sp+14h] [bp-4h]@1

  v5 = 0;
  v2 = 31 - ((((unsigned __int64)a2 >> 32) ^ abs(a2) & 0x1F) - ((unsigned __int64)a2 >> 32));
  if ( (1 << v2) & *(_DWORD *)(a1 + 4 * (a2 / 32)) && !_ZeroTail(a1, a2 + 1) )
    v5 = _IncMan(a1, a2 - 1);
  v3 = a2 / 32 + 1;
  *(_DWORD *)(a1 + 4 * (a2 / 32)) &= -1 << v2;
  if ( v3 < 3 )
    memset((void *)(a1 + 4 * v3), 0, 4 * (3 - v3));
  return v5;
}

signed int __thiscall sub_4C1B30(void *this, signed int a2)
{
  char *v2; // eax@1
  signed int result; // eax@1
  int thisa; // [sp+Ch] [bp-1Ch]@1
  int v5; // [sp+10h] [bp-18h]@2
  int v6; // [sp+14h] [bp-14h]@2
  int v7; // [sp+18h] [bp-10h]@1
  int v8; // [sp+1Ch] [bp-Ch]@1
  int row; // [sp+20h] [bp-8h]@1
  int col; // [sp+24h] [bp-4h]@1

  thisa = (int)this;
  v2 = (char *)gameObject + 250 * curPlayer->_1[0];
  v8 = (int)(v2 + 10180);
  v7 = 0;
  result = sub_456630(this, *(_QWORD *)(v2 + 10205), (int)&col, (int)&row, -1, -1);
  if ( result )
  {
    sub_4BFAC0((AdvManager *)thisa, 1);
    sub_447C20((AdvManager *)thisa, *(_DWORD *)(thisa + 470), *(_DWORD *)(thisa + 474), 0, 1);
    sub_447A00((void *)thisa, 0, 0);
    v5 = usedToCheckForBoatByCastle((AdvManager *)thisa, col, row);
    v6 = usedToCheckForBoatByCastle((AdvManager *)thisa, *(_DWORD *)(v8 + 25), *(_DWORD *)(v8 + 29));
    if ( *(&byte_524758 + curPlayerIdx) )
      sub_492A90((void *)thisa, v5, v6, v8, (signed int)&v7, *(_QWORD *)(v8 + 25), 1, __PAIR__(row, col));
    else
      sub_4932B0(v5, v8, (int)&v7);
    if ( v7 )
    {
      sub_48BA30(thisa, v5, col, row);
      if ( *(&byte_524758 + curPlayerIdx) )
        sub_48F7F0((void *)thisa, 0);
    }
    result = a2;
    *(_DWORD *)a2 = 1;
  }
  return result;
}

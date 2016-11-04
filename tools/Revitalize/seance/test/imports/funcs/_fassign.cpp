{
  int result; // eax@2
  int v4; // ecx@2
  int v5; // [sp+0h] [bp-Ch]@3
  int v6; // [sp+4h] [bp-8h]@2
  int v7; // [sp+8h] [bp-4h]@2

  if ( a1 )
  {
    sub_4E5170((int)&v6, a3);
    result = v6;
    v4 = v7;
    *(_DWORD *)a2 = v6;
    *(_DWORD *)(a2 + 4) = v4;
  }
  else
  {
    result = sub_4E51B0((int)&v5, a3);
    *(_DWORD *)a2 = v5;
  }
  return result;
}

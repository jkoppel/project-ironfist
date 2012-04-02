int __cdecl sub_4D4B10()
{
  int result; // eax@4
  int v1; // [sp+14h] [bp-14h]@5
  int i; // [sp+18h] [bp-10h]@3
  signed int v3; // [sp+1Ch] [bp-Ch]@1
  int v4; // [sp+20h] [bp-8h]@1
  int v5; // [sp+24h] [bp-4h]@5

  v4 = dword_5347A4;
  v3 = 1;
  do
    v3 = 3 * v3 + 1;
  while ( v3 <= dword_5347A4 + 1 );
  do
  {
    v3 /= 3;
    for ( i = v3; ; ++i )
    {
      result = i;
      if ( v4 < i )
        break;
      v5 = *((_DWORD *)dword_51FDC4 + i);
      v1 = i;
      do
      {
        if ( !sub_4D4A50(*((_DWORD *)dword_51FDC4 + v1 - v3), v5) )
          break;
        *((_DWORD *)dword_51FDC4 + v1) = *((_DWORD *)dword_51FDC4 + v1 - v3);
        v1 -= v3;
      }
      while ( v3 - 1 < v1 );
      *((_DWORD *)dword_51FDC4 + v1) = v5;
    }
  }
  while ( v3 != 1 );
  return result;
}

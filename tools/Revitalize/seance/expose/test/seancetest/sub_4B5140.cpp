int __stdcall sub_4B5140(int a1, int a2, __int64 a3, int a4, int a5, signed int a6, int a7, int a8)
{
  int result; // eax@5
  int v9; // [sp+18h] [bp-20h]@2
  char v10; // [sp+1Ch] [bp-1Ch]@4
  char v11; // [sp+20h] [bp-18h]@4
  char v12; // [sp+24h] [bp-14h]@4
  int v13; // [sp+28h] [bp-10h]@4
  char v14; // [sp+2Ch] [bp-Ch]@4
  float v15; // [sp+30h] [bp-8h]@4

  if ( HIDWORD(a3) )
    v9 = *(_BYTE *)(HIDWORD(a3) + 3);
  else
    v9 = -1;
  sub_4AF410(a1, a2, a3, 0, a4, a5, v9, (int)&v15, (int)&v14, (int *)&v12, (int *)&v11, (int *)&v10, &v13);
  v13 = (signed __int64)((double)a6 * v15 + (double)v13);
  if ( v13 > 0 )
  {
    *(_DWORD *)a8 = v13;
    result = a7;
    *(_DWORD *)a7 = 1;
  }
  else
  {
    *(_DWORD *)a8 = 0;
    result = a7;
    *(_DWORD *)a7 = 0;
  }
  return result;
}

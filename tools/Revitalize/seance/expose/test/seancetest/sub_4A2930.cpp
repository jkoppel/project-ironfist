int __stdcall sub_4A2930(int *a1, signed int a2, signed int a3, signed int a4, signed int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // ebx@24
  int v14; // ST28_4@27
  int v15; // eax@27

  if ( a2 < 0 )
    a2 = 0;
  if ( a2 > 639 )
    a2 = 639;
  if ( a3 < 0 )
    a3 = 0;
  if ( a3 > 442 )
    a3 = 442;
  if ( a4 < 0 )
    a4 = 0;
  if ( a4 > 639 )
    a4 = 639;
  if ( a5 < 0 )
    a5 = 0;
  if ( a5 > 442 )
    a5 = 442;
  *a1 = a2;
  a1[1] = a3;
  a1[2] = a4;
  a1[3] = a5;
  a1[4] = a6;
  a1[5] = a7;
  a1[23] = a7;
  a1[24] = a8;
  a1[6] = a9;
  a1[26] = a10;
  a1[27] = a11;
  a1[8] = a12;
  *((float *)a1 + 9) = (double)a2;
  *((float *)a1 + 10) = (double)a3;
  a1[11] = a2;
  a1[12] = a3;
  a1[16] = 0;
  a1[17] = 0;
  a1[21] = a2;
  a1[22] = a3;
  a1[28] = 0;
  a1[29] = a13;
  if ( a9 != 0x12C && a9 != 0x12F )
  {
    v13 = abs(a5 - a3);
    a1[13] = v13 < abs(a4 - a2);
  }
  else
  {
    a1[13] = a2 <= 0 || a2 >= 639;
  }
  v14 = abs(a4 - a2);
  v15 = abs(a5 - a3);
  a1[25] = (signed __int64)sqrt((double)(v15 * v15 + v14 * v14));
  return sub_4A2190((int)a1);
}

int __fastcall sub_4C3190(char a1, char a2, unsigned __int8 a3, unsigned __int8 a4, int a5, char a6, char a7)
{
  int v7; // edx@5
  void *v8; // ecx@5
  int result; // eax@5
  char v10; // [sp+Ch] [bp-14h]@1
  char v11; // [sp+10h] [bp-10h]@1
  char v12; // [sp+14h] [bp-Ch]@5
  char v13; // [sp+15h] [bp-Bh]@5
  unsigned __int8 v14; // [sp+16h] [bp-Ah]@5
  unsigned __int8 v15; // [sp+17h] [bp-9h]@5
  char v16; // [sp+18h] [bp-8h]@5
  char v17; // [sp+19h] [bp-7h]@5
  char v18; // [sp+1Ah] [bp-6h]@5
  int v19; // [sp+1Bh] [bp-5h]@5

  v10 = a2;
  v11 = a1;
  if ( dword_523ED4 && dword_4F7494 )
  {
    if ( a5 == -999 )
      a5 = curPlayerIdx;
    logUpTo7Ints((int)"Send Map Change", a1, a2, a3, a4, -999, -999, -999);
    memset(&v12, 0, 0xBu);
    v12 = v11;
    v13 = v10;
    v14 = a3;
    v15 = a4;
    v18 = a5;
    v17 = a6;
    v16 = a7;
    v19 = (*(_DWORD *)&dword_524A78)++;
    memcpy_0(v8, v7, &byte_532DB8[11], byte_532DB8, 0x21u);
    *(_DWORD *)byte_532DB8 = *(_DWORD *)&v12;
    *(_DWORD *)&byte_532DB8[4] = *(_DWORD *)&v16;
    *(_WORD *)&byte_532DB8[8] = *(_WORD *)((char *)&v19 + 1);
    byte_532DB8[10] = BYTE3(v19);
    result = sub_46E1D0(byte_532DB8, 127, 0x2Cu, 41, 0, 1, -1);
  }
  return result;
}

{
  unsigned __int16 v5; // cx@1
  signed int result; // eax@6
  int v7; // edx@11
  int v8; // edx@14
  int v9; // edx@17
  int v10; // ecx@18
  int v11; // esi@19
  int v12; // esi@22
  signed int v13; // ebp@27
  int v14; // ebx@27
  int v15; // ebx@27
  int v16; // ebx@30
  int v17; // ebp@32
  int v18; // esi@32
  int v19; // ebx@32
  char v20; // al@34
  int v21; // ebx@34
  char v22; // bl@41
  char v23[10]; // [sp+10h] [bp-28h]@19
  unsigned __int16 v24; // [sp+1Ah] [bp-1Eh]@19
  int v25; // [sp+1Ch] [bp-1Ch]@1
  char v26; // [sp+20h] [bp-18h]@1
  char v27; // [sp+21h] [bp-17h]@1
  char v28; // [sp+22h] [bp-16h]@1
  char v29; // [sp+23h] [bp-15h]@1
  char v30; // [sp+24h] [bp-14h]@1
  char v31; // [sp+25h] [bp-13h]@1
  char v32; // [sp+26h] [bp-12h]@1
  char v33; // [sp+27h] [bp-11h]@1
  char v34; // [sp+28h] [bp-10h]@1
  char v35; // [sp+29h] [bp-Fh]@1
  char v36; // [sp+2Ah] [bp-Eh]@1
  char v37; // [sp+2Bh] [bp-Dh]@1
  __int64 v38; // [sp+2Ch] [bp-Ch]@33
  int v39; // [sp+34h] [bp-4h]@33

  v26 = -52;
  v27 = -52;
  v28 = -52;
  v29 = -52;
  v30 = -52;
  v31 = -52;
  v32 = -52;
  v33 = -52;
  v34 = -52;
  v35 = -52;
  v36 = -5;
  v37 = 63;
  v25 = 1;
  v5 = a2 & 0x7FFF;
  if ( a2 & 0x8000 )
    *(_BYTE *)(a5 + 2) = 45;
  else
    *(_BYTE *)(a5 + 2) = 32;
  if ( !v5 && !a1 )
  {
    *(_BYTE *)(a5 + 2) = 32;
    *(_WORD *)a5 = 0;
    result = 1;
    *(_BYTE *)(a5 + 3) = 1;
    *(_BYTE *)(a5 + 4) = 48;
    *(_BYTE *)(a5 + 5) = 0;
    return result;
  }
  if ( v5 == 32767 )
  {
    *(_WORD *)a5 = 1;
    if ( HIDWORD(a1) == -2147483648 && !(_DWORD)a1 || BYTE7(a1) & 0x40 )
    {
      if ( a2 & 0x8000 && a1 == -4611686018427387904i64 )
      {
        v8 = a5 + 4;
        v25 = 0;
        *(_DWORD *)v8 = dword_4EBE78;
        *(_WORD *)(v8 + 4) = *((_WORD *)&dword_4EBE78 + 2);
        *(_BYTE *)(a5 + 3) = 5;
      }
      else
      {
        if ( HIDWORD(a1) != -2147483648 || (_DWORD)a1 )
        {
          v10 = a5 + 4;
          v25 = 0;
          *(_DWORD *)v10 = dword_4EBE68;
          *(_WORD *)(v10 + 4) = *((_WORD *)&dword_4EBE68 + 2);
          *(_BYTE *)(v10 + 6) = *((_BYTE *)&dword_4EBE68 + 6);
          *(_BYTE *)(a5 + 3) = 6;
        }
        else
        {
          v9 = a5 + 4;
          v25 = 0;
          *(_DWORD *)v9 = dword_4EBE70;
          *(_WORD *)(v9 + 4) = *((_WORD *)&dword_4EBE70 + 2);
          *(_BYTE *)(a5 + 3) = 5;
        }
      }
    }
    else
    {
      v7 = a5 + 4;
      v25 = 0;
      *(_DWORD *)v7 = dword_4EBE80;
      *(_WORD *)(v7 + 4) = *((_WORD *)&dword_4EBE80 + 2);
      *(_BYTE *)(v7 + 6) = *((_BYTE *)&dword_4EBE80 + 6);
      *(_BYTE *)(a5 + 3) = 6;
    }
    return v25;
  }
  v24 = a2 & 0x7FFF;
  v11 = (19728 * v5 + 77 * ((v5 >> 8) + 2 * (unsigned __int16)(HIDWORD(a1) >> 24)) - 323162868) >> 16;
  *(_QWORD *)&v23[2] = a1;
  *(_WORD *)v23 = 0;
  __multtenpow12(v23, -(signed __int16)v11, 1);
  if ( v24 >= 0x3FFFu )
  {
    LOWORD(v11) = v11 + 1;
    __ld12mul(v23, &v26);
  }
  *(_WORD *)a5 = v11;
  if ( a4 & 1 )
  {
    v12 = (signed __int16)v11 + a3;
    if ( v12 <= 0 )
    {
      *(_BYTE *)(a5 + 2) = 32;
      *(_WORD *)a5 = 0;
      result = 1;
      *(_BYTE *)(a5 + 3) = 1;
      *(_BYTE *)(a5 + 4) = 48;
      *(_BYTE *)(a5 + 5) = 0;
      return result;
    }
  }
  else
  {
    v12 = a3;
  }
  if ( v12 > 21 )
    v12 = 21;
  v13 = 8;
  v14 = v24;
  v24 = 0;
  v15 = v14 - 16382;
  do
  {
    __shl_12((int)v23);
    --v13;
  }
  while ( v13 );
  if ( v15 < 0 )
  {
    v16 = -v15 & 0xFF;
    if ( v16 > 0 )
    {
      do
      {
        __shr_12((int)v23);
        --v16;
      }
      while ( v16 );
    }
  }
  v17 = a5 + 4;
  v18 = v12 + 1;
  v19 = a5 + 4;
  if ( v18 > 0 )
  {
    do
    {
      ++v19;
      v38 = *(_QWORD *)v23;
      v39 = *(_DWORD *)&v23[8];
      __shl_12((int)v23);
      __shl_12((int)v23);
      __add_12((int)v23, (int)&v38);
      __shl_12((int)v23);
      --v18;
      *(_BYTE *)(v19 - 1) = HIBYTE(v24) + 48;
      HIBYTE(v24) = 0;
    }
    while ( v18 );
  }
  v20 = *(_BYTE *)(v19 - 1);
  v21 = v19 - 2;
  if ( v20 >= 53 )
  {
    if ( v21 < (unsigned int)v17 )
      goto LABEL_50;
    do
    {
      if ( *(_BYTE *)v21 != 57 )
        break;
      *(_BYTE *)v21-- = 48;
    }
    while ( v21 >= (unsigned int)v17 );
    if ( v21 < (unsigned int)v17 )
    {
LABEL_50:
      ++*(_WORD *)a5;
      ++v21;
    }
    ++*(_BYTE *)v21;
    goto LABEL_41;
  }
  if ( v21 >= (unsigned int)v17 )
  {
    do
    {
      if ( *(_BYTE *)v21 != 48 )
        break;
      --v21;
    }
    while ( v21 >= (unsigned int)v17 );
    if ( v21 >= (unsigned int)v17 )
    {
LABEL_41:
      v22 = v21 - (_BYTE)a5 - 3;
      *(_BYTE *)(a5 + 3) = v22;
      *(_BYTE *)(v22 + a5 + 4) = 0;
      return v25;
    }
  }
  *(_WORD *)a5 = 0;
  *(_BYTE *)v17 = 48;
  result = 1;
  *(_BYTE *)(a5 + 2) = 32;
  *(_BYTE *)(a5 + 3) = 1;
  *(_BYTE *)(a5 + 5) = 0;
  return result;
}

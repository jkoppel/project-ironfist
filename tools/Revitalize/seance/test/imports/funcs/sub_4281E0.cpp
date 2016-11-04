{
  int result; // eax@4
  void *v4; // [sp+Ch] [bp-90h]@1
  _DWORD v5; // [sp+10h] [bp-8Ch]@1
  int v6; // [sp+14h] [bp-88h]@15
  signed int i; // [sp+18h] [bp-84h]@9
  signed int j; // [sp+18h] [bp-84h]@12
  int v9; // [sp+1Ch] [bp-80h]@15
  __int16 v10; // [sp+20h] [bp-7Ch]@1
  __int16 v11; // [sp+22h] [bp-7Ah]@1
  __int16 v12; // [sp+24h] [bp-78h]@1
  __int16 v13; // [sp+26h] [bp-76h]@1
  __int16 v14; // [sp+28h] [bp-74h]@1
  __int16 v15; // [sp+2Ah] [bp-72h]@1
  __int16 v16; // [sp+2Ch] [bp-70h]@1
  __int16 v17; // [sp+2Eh] [bp-6Eh]@1
  __int16 v18; // [sp+30h] [bp-6Ch]@1
  __int16 v19; // [sp+32h] [bp-6Ah]@1
  __int16 v20; // [sp+34h] [bp-68h]@1
  __int16 v21; // [sp+36h] [bp-66h]@1
  __int16 v22; // [sp+38h] [bp-64h]@1
  __int16 v23; // [sp+3Ah] [bp-62h]@1
  __int16 v24; // [sp+3Ch] [bp-60h]@1
  __int16 v25; // [sp+3Eh] [bp-5Eh]@1
  __int16 v26; // [sp+40h] [bp-5Ch]@1
  __int16 v27; // [sp+42h] [bp-5Ah]@1
  __int16 v28; // [sp+44h] [bp-58h]@1
  __int16 v29; // [sp+46h] [bp-56h]@1
  __int16 v30; // [sp+48h] [bp-54h]@1
  __int16 v31; // [sp+4Ah] [bp-52h]@1
  __int16 v32; // [sp+4Ch] [bp-50h]@1
  __int16 v33; // [sp+4Eh] [bp-4Eh]@1
  __int16 v34; // [sp+50h] [bp-4Ch]@1
  __int16 v35; // [sp+52h] [bp-4Ah]@1
  __int16 v36; // [sp+54h] [bp-48h]@1
  __int16 v37; // [sp+56h] [bp-46h]@1
  __int16 v38; // [sp+58h] [bp-44h]@1
  __int16 v39; // [sp+5Ah] [bp-42h]@1
  __int16 v40; // [sp+5Ch] [bp-40h]@1
  __int16 v41; // [sp+5Eh] [bp-3Eh]@1
  __int16 v42; // [sp+60h] [bp-3Ch]@1
  __int16 v43; // [sp+62h] [bp-3Ah]@1
  __int16 v44; // [sp+64h] [bp-38h]@1
  __int16 v45; // [sp+66h] [bp-36h]@1
  __int16 v46; // [sp+68h] [bp-34h]@1
  __int16 v47; // [sp+6Ah] [bp-32h]@1
  __int16 v48; // [sp+6Ch] [bp-30h]@1
  __int16 v49; // [sp+6Eh] [bp-2Eh]@1
  __int16 v50; // [sp+70h] [bp-2Ch]@1
  __int16 v51; // [sp+72h] [bp-2Ah]@1
  __int16 v52; // [sp+74h] [bp-28h]@1
  __int16 v53; // [sp+76h] [bp-26h]@1
  __int16 v54; // [sp+78h] [bp-24h]@1
  __int16 v55; // [sp+7Ah] [bp-22h]@1
  __int16 v56; // [sp+7Ch] [bp-20h]@1
  __int16 v57; // [sp+7Eh] [bp-1Eh]@1
  __int16 v58; // [sp+80h] [bp-1Ch]@1
  __int16 v59; // [sp+82h] [bp-1Ah]@1
  __int16 v60; // [sp+84h] [bp-18h]@1
  __int16 v61; // [sp+86h] [bp-16h]@1
  __int16 v62; // [sp+88h] [bp-14h]@1
  __int16 v63; // [sp+8Ah] [bp-12h]@1
  char *v64; // [sp+8Ch] [bp-10h]@1
  int v65; // [sp+90h] [bp-Ch]@1
  bool v66; // [sp+94h] [bp-8h]@2
  bool v67; // [sp+98h] [bp-4h]@5

  v4 = this;
  v64 = (char *)this + 250 * a2 + 10281;
  v5 = 0;
  v10 = 0;
  v11 = 30;
  v12 = 50;
  v13 = 1;
  v14 = 3;
  v15 = 5;
  v16 = 3;
  v17 = 2;
  v18 = 4;
  v19 = 11;
  v20 = 15;
  v21 = 25;
  v22 = 12;
  v23 = 3;
  v24 = 5;
  v25 = 14;
  v26 = 2;
  v27 = 3;
  v28 = 20;
  v29 = 10;
  v30 = 20;
  v31 = 21;
  v32 = 2;
  v33 = 4;
  v34 = 23;
  v35 = 1;
  v36 = 2;
  v37 = 29;
  v38 = 6;
  v39 = 10;
  v40 = 30;
  v41 = 2;
  v42 = 4;
  v43 = 31;
  v44 = 1;
  v45 = 2;
  v46 = 38;
  v47 = 6;
  v48 = 10;
  v49 = 39;
  v50 = 2;
  v51 = 4;
  v52 = 40;
  v53 = 1;
  v54 = 2;
  v55 = 47;
  v56 = 6;
  v57 = 10;
  v58 = 48;
  v59 = 2;
  v60 = 4;
  v61 = 50;
  v62 = 1;
  v63 = 2;
  v65 = 1;
  v66 = unseededNextRand(0, 99) < (((a3 < 1) - 1) & 0x1E) + 50;
  result = unseededNextRand(0, 99);
  v67 = (((a3 < 1) - 1) & 0x28) + 25 > result;
  if ( !v67 )
    v66 = 1;
  for ( i = 0; i < 5; ++i )
  {
    v64[i] = -1;
    result = i;
    *(_WORD *)&v64[2 * i + 5] = -1;
  }
  for ( j = 0; j < 2; ++j )
  {
    result = j;
    if ( *(&v65 + j) )
    {
      v64[v5] = *((_BYTE *)&v10 + 18 * *((_BYTE *)v4 + 250 * a2 + 10203) + 6 * j);
      v9 = 10 * *(&v11 + 9 * *((_BYTE *)v4 + 250 * a2 + 10203) + 3 * j);
      v6 = 10 * *(&v12 + 9 * *((_BYTE *)v4 + 250 * a2 + 10203) + 3 * j) + 9;
      if ( a3 )
        v9 = (v6 + v9) / 2;
      result = unseededNextRand(v9, v6) / 10;
      *(_WORD *)&v64[2 * v5++ + 5] = result;
    }
  }
  return result;
}

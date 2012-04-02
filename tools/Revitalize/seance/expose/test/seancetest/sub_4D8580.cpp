int __fastcall sub_4D8580(Icon *a1, int a2, int a3, int a4, int a5, int a6, signed int a7, int a8, int a9, int a10, int a11)
{
  ICNHeader *v11; // edi@1
  int v12; // ecx@1
  int v13; // esi@1
  int v14; // eax@1
  int v15; // edi@1
  int v16; // ecx@1
  int v17; // eax@5
  int v18; // esi@5
  int v19; // ebp@9
  int result; // eax@10
  int v21; // edx@10
  int v22; // edx@11
  int v23; // esi@15
  int v24; // edi@16
  int v25; // ebx@17
  int v26; // eax@21
  int v27; // eax@25
  int v28; // edi@25
  int v29; // ebx@33
  int v30; // [sp+10h] [bp-4h]@9

  v11 = a1->headersAndImageData;
  v12 = v11[a5].offsetX;
  v13 = (int)&v11[a5];
  v14 = (int)((char *)v11 + v11[a5].off);
  dword_537A24 = v13;
  v15 = *(_WORD *)(v13 + 2);
  dword_537A30 = v14;
  v16 = v12 + a3;
  dword_537A28 = v16;
  dword_537A20 = v15 + a4;
  if ( !a7 )
    goto LABEL_9;
  if ( a8 > dword_537A28 || dword_537A28 + *(_WORD *)(v13 + 4) > a8 + a10 || dword_537A20 < a9 )
  {
    v18 = a11;
    goto LABEL_8;
  }
  v17 = dword_537A20 + *(_WORD *)(v13 + 6);
  v18 = a11;
  if ( v17 > a11 + a9 )
  {
LABEL_8:
    a7 = 1;
    dword_537A3C = a8 + a10 - 1;
    dword_537A40 = a9 + v18 - 1;
    goto LABEL_9;
  }
  a7 = 0;
LABEL_9:
  v19 = *(_DWORD *)(a2 + 22) + *(_WORD *)(a2 + 18) * dword_537A20;
  v30 = *(_WORD *)(a2 + 18);
  while ( 1 )
  {
    while ( 1 )
    {
      result = dword_537A30 + 1;
      dword_537A2C = v16;
      dword_537A30 = result;
      v21 = *(_BYTE *)(result - 1);
      if ( (char)v21 < 0 )
        break;
      dword_537A48 = *(_BYTE *)(result - 1);
      if ( v21 )
      {
        if ( a7 )
        {
          if ( dword_537A20 >= a9 )
          {
            if ( dword_537A20 <= dword_537A40 )
            {
              v26 = v21 + v16;
              if ( a8 < v21 + v16 )
              {
                if ( v16 <= dword_537A3C )
                {
                  if ( v16 < a8 )
                  {
                    if ( v26 > dword_537A3C )
                      v27 = a10;
                    else
                      v27 = v21 + v16 - a8;
                    v28 = v19 + a8;
                  }
                  else
                  {
                    if ( v26 > dword_537A3C )
                    {
                      v28 = v19 + v16;
                      v27 = dword_537A3C - v16 + 1;
                    }
                    else
                    {
                      v27 = v21;
                      v28 = v19 + v16;
                    }
                  }
                  dword_537A34 = v28;
                  dword_537A44 = v27;
                  dword_537A1C = 0;
                  if ( v27 > 0 )
                  {
                    dword_537A1C = v27;
                    do
                    {
                      ++v28;
                      v29 = *(_BYTE *)(v28 - 1);
                      --v27;
                      dword_537A34 = v28;
                      *(_BYTE *)(v28 - 1) = globalColorSubstitutionThing[a6][v29];
                    }
                    while ( v27 );
                  }
                }
              }
            }
          }
        }
        else
        {
          v23 = v19 + v16;
          dword_537A1C = 0;
          dword_537A34 = v19 + v16;
          if ( v21 > 0 )
          {
            v24 = v21;
            dword_537A1C = v21;
            do
            {
              ++v23;
              v25 = *(_BYTE *)(v23 - 1);
              --v24;
              dword_537A34 = v23;
              *(_BYTE *)(v23 - 1) = globalColorSubstitutionThing[a6][v25];
            }
            while ( v24 );
          }
        }
        v16 += v21;
        dword_537A48 = v21;
      }
      else
      {
        v16 = dword_537A28;
        v19 += v30;
        ++dword_537A20;
      }
    }
    dword_537A38 = v19;
    dword_537A48 = v21;
    v22 = v21 & 0x7F;
    if ( !v22 )
      break;
    v16 += v22;
  }
  return result;
}

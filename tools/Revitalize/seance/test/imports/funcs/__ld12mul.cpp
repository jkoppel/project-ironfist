{
  __int16 v2; // cx@1
  __int16 v3; // dx@1
  unsigned __int16 v4; // cx@1
  unsigned __int16 v5; // dx@1
  signed int v6; // eax@1
  signed int v7; // ebx@17
  int v8; // edi@17
  char *v9; // ebp@18
  int v10; // ebx@28
  __int16 v11; // di@28
  int v12; // ecx@46
  int v13; // edx@46
  unsigned __int16 v15; // [sp+10h] [bp-1Ch]@1
  char v16[10]; // [sp+12h] [bp-1Ah]@1
  int v17; // [sp+1Ch] [bp-10h]@1
  int v18; // [sp+20h] [bp-Ch]@16
  int v19; // [sp+24h] [bp-8h]@16
  int v20; // [sp+28h] [bp-4h]@17

  v2 = *(_WORD *)(a1 + 10);
  v3 = *(_WORD *)(a2 + 10);
  *(_QWORD *)&v16[2] = 0i64;
  v17 = 0;
  LOWORD(v6) = (v2 ^ v3) & 0x8000;
  v4 = v2 & 0x7FFF;
  v5 = v3 & 0x7FFF;
  v15 = v6;
  LOWORD(v6) = v4 + v5;
  *(_QWORD *)v16 = (unsigned __int16)(v4 + v5);
  if ( v4 >= 0x7FFFu || v5 >= 0x7FFFu || (unsigned __int16)v6 > 0xBFFDu )
  {
    *(_DWORD *)(a1 + 4) = 0;
    v6 = v15 < 1u ? 2147450880 : -32768;
    *(_DWORD *)a1 = 0;
    *(_DWORD *)(a1 + 8) = v6;
  }
  else
  {
    if ( (unsigned __int16)v6 > 0x3FBFu )
    {
      if ( v4 || (++*(_WORD *)v16, *(_DWORD *)(a1 + 8) & 0x7FFFFFFF) || *(_DWORD *)(a1 + 4) || *(_DWORD *)a1 )
      {
        LOWORD(v6) = 0;
        if ( v5 || (++*(_WORD *)v16, *(_DWORD *)(a2 + 8) & 0x7FFFFFFF) || *(_DWORD *)(a2 + 4) || *(_DWORD *)a2 )
        {
          v19 = 0;
          v18 = 0;
          do
          {
            v7 = 8;
            v8 = 2 * v18;
            v20 = 5 - v18;
            if ( 5 - v18 > 0 )
            {
              v9 = &v16[v19 + 2];
              do
              {
                if ( __addl(*(_DWORD *)v9, *(_WORD *)(v8 + a1) * *(_WORD *)(v7 + a2), v9) )
                  ++*(_WORD *)&v16[v19 + 6];
                v8 += 2;
                v7 -= 2;
                --v20;
              }
              while ( v20 );
            }
            v19 += 2;
            ++v18;
          }
          while ( v18 < 5 );
          *(_WORD *)v16 -= 16382;
          if ( *(_WORD *)v16 <= 0 )
            goto LABEL_51;
          do
          {
            if ( v17 & 0x80000000 )
              break;
            __shl_12((int)&v16[2]);
            --*(_WORD *)v16;
          }
          while ( *(_WORD *)v16 > 0 );
          if ( *(_WORD *)v16 <= 0 )
          {
LABEL_51:
            --*(_WORD *)v16;
            if ( *(_WORD *)v16 >= 0 )
            {
              v10 = *(_DWORD *)&v16[2];
            }
            else
            {
              v10 = *(_DWORD *)&v16[2];
              v11 = -*(_WORD *)v16;
              *(_WORD *)v16 = 0;
              do
              {
                if ( v16[2] & 1 )
                  ++v10;
                __shr_12((int)&v16[2]);
                --v11;
              }
              while ( v11 );
            }
            if ( v10 )
              v16[2] |= 1u;
          }
          if ( *(_WORD *)&v16[2] > 0x8000u )
          {
            if ( *(_DWORD *)&v16[4] == -1 )
            {
              *(_DWORD *)&v16[4] = 0;
              if ( *(_DWORD *)&v16[8] == -1 )
              {
                *(_DWORD *)&v16[8] = 0;
                if ( HIWORD(v17) == -1 )
                {
                  HIWORD(v17) = -32768;
                  ++*(_WORD *)v16;
                }
                else
                {
                  ++HIWORD(v17);
                }
              }
              else
              {
                ++*(_DWORD *)&v16[8];
              }
            }
            else
            {
              ++*(_DWORD *)&v16[4];
            }
          }
          if ( *(_WORD *)v16 < 0x7FFFu )
          {
            v12 = *(_DWORD *)&v16[6];
            *(_WORD *)a1 = *(_WORD *)&v16[4];
            v13 = v17;
            *(_DWORD *)(a1 + 2) = v12;
            LOWORD(v6) = v15 | *(_WORD *)v16;
            *(_DWORD *)(a1 + 6) = v13;
            *(_WORD *)(a1 + 10) = v15 | *(_WORD *)v16;
          }
          else
          {
            *(_DWORD *)(a1 + 4) = 0;
            v6 = v15 < 1u ? 2147450880 : -32768;
            *(_DWORD *)a1 = 0;
            *(_DWORD *)(a1 + 8) = v6;
          }
        }
        else
        {
          *(_DWORD *)(a1 + 8) = 0;
          *(_DWORD *)(a1 + 4) = 0;
          *(_DWORD *)a1 = 0;
        }
      }
      else
      {
        *(_WORD *)(a1 + 10) = 0;
      }
    }
    else
    {
      *(_DWORD *)(a1 + 8) = 0;
      *(_DWORD *)(a1 + 4) = 0;
      *(_DWORD *)a1 = 0;
    }
  }
  return v6;
}

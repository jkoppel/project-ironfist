{
  unsigned __int8 *v3; // eax@1
  unsigned __int8 v4; // bl@1
  char v5; // zf@1
  int v6; // esi@2
  int v7; // edi@2
  signed int v8; // eax@6
  unsigned int v9; // ecx@8
  int v10; // eax@19
  unsigned __int8 *v11; // eax@36
  __int16 v13; // ax@46
  signed int v14; // ebx@53
  int v15; // eax@55
  const WCHAR *v16; // ebp@58
  int v17; // eax@60
  int v18; // eax@63
  int v19; // ecx@64
  signed int v20; // edi@69
  int v21; // eax@70
  int v22; // edx@81
  int v23; // eax@87
  int v24; // eax@104
  signed int v25; // ebx@106
  int v26; // eax@108
  int v27; // edx@116
  int v28; // edi@129
  signed int v29; // eax@129
  int v30; // ebx@129
  int v31; // eax@131
  int v32; // ebx@149
  int v33; // ebp@149
  const WCHAR v34; // ax@150
  int v35; // eax@150
  int v36; // ecx@151
  char v37; // [sp+10h] [bp-248h]@60
  char v38[6]; // [sp+12h] [bp-246h]@79
  int v39; // [sp+18h] [bp-240h]@49
  int v40; // [sp+1Ch] [bp-23Ch]@10
  int v41[2]; // [sp+20h] [bp-238h]@81
  int v42; // [sp+28h] [bp-230h]@1
  unsigned __int64 v43; // [sp+2Ch] [bp-22Ch]@94
  int v44; // [sp+34h] [bp-224h]@10
  int v45; // [sp+38h] [bp-220h]@10
  int i; // [sp+3Ch] [bp-21Ch]@10
  unsigned int v47; // [sp+40h] [bp-218h]@1
  int v48; // [sp+44h] [bp-214h]@77
  int v49; // [sp+48h] [bp-210h]@10
  int v50; // [sp+4Ch] [bp-20Ch]@10
  int v51; // [sp+50h] [bp-208h]@116
  int v52; // [sp+54h] [bp-204h]@116
  char v53[4]; // [sp+58h] [bp-200h]@2
  char v54; // [sp+257h] [bp-1h]@103
  unsigned __int8 *v55; // [sp+260h] [bp+8h]@1

  v3 = a2;
  v55 = a2 + 1;
  v42 = 0;
  v4 = *v3;
  v5 = *v3 == 0;
  v47 = 0;
  if ( !v5 )
  {
    v6 = *(_DWORD *)v53;
    v7 = *(_DWORD *)v53;
    while ( 1 )
    {
      if ( v42 < 0 )
        return v42;
      v8 = (char)v4 < 32 || (char)v4 > 120 ? 0 : *((_BYTE *)&_string_ + (char)v4) & 0xF;
      v9 = (char)(*(&__lookuptable[8 * v8] + v47) >> 4);
      v47 = v9;
      if ( v9 <= 7 )
        break;
LABEL_36:
      v11 = v55++;
      v4 = *v11;
      if ( !*v11 )
        return v42;
    }
    switch ( v9 )
    {
      case 1u:
        v50 = 0;
        v49 = 0;
        v44 = 0;
        v45 = 0;
        v40 = -1;
        v6 = 0;
        i = 0;
        goto LABEL_36;
      case 2u:
        if ( (unsigned int)((char)v4 - 32) <= 0x10 )
        {
          switch ( v4 )
          {
            case 32u:
              v6 |= 2u;
              break;
            case 35u:
              v6 |= 0x80u;
              break;
            case 43u:
              v6 |= 1u;
              break;
            case 45u:
              v6 |= 4u;
              break;
            case 48u:
              v6 |= 8u;
              break;
            default:
              goto LABEL_36;
          }
        }
        goto LABEL_36;
      case 3u:
        if ( v4 == 42 )
        {
          v10 = get_int_arg(&a3);
          v44 = v10;
          if ( v10 < 0 )
          {
            v6 |= 4u;
            v44 = -v10;
          }
        }
        else
        {
          v44 = (char)v4 + 10 * v44 - 48;
        }
        goto LABEL_36;
      case 4u:
        v40 = 0;
        goto LABEL_36;
      case 5u:
        if ( v4 == 42 )
        {
          v40 = get_int_arg(&a3);
          if ( v40 < 0 )
            v40 = -1;
        }
        else
        {
          v40 = (char)v4 + 10 * v40 - 48;
        }
        goto LABEL_36;
      case 6u:
        if ( (unsigned int)((char)v4 - 73) <= 0x2E )
        {
          switch ( v4 )
          {
            case 73u:
              if ( *v55 != 54 || v55[1] != 52 )
              {
                v47 = 0;
                goto $NORMAL_STATE$678;
              }
              v55 += 2;
              v6 |= 0x8000u;
              break;
            default:
              goto LABEL_36;
            case 104u:
              v6 |= 0x20u;
              break;
            case 108u:
              v6 |= 0x10u;
              break;
            case 119u:
              v6 |= 0x800u;
              break;
          }
        }
        goto LABEL_36;
      case 0u:
$NORMAL_STATE$678:
        i = 0;
        if ( HIBYTE(_pctype[v4]) & 0x80 )
        {
          write_char(v4, (int)a1, (int)&v42);
          v4 = *v55++;
        }
        write_char(v4, (int)a1, (int)&v42);
        goto LABEL_36;
      case 7u:
        if ( (unsigned int)((char)v4 - 67) <= 0x35 )
        {
          switch ( v4 )
          {
            case 67u:
              if ( !(v6 & 0x830) )
                v6 |= 0x800u;
              goto LABEL_45;
            case 99u:
LABEL_45:
              if ( v6 & 0x810 )
              {
                v13 = get_short_arg((int)&a3);
                v7 = wctomb((int)v53, v13);
                if ( v7 < 0 )
                  v49 = 1;
              }
              else
              {
                v7 = 1;
                v53[0] = get_int_arg(&a3);
              }
              v39 = (int)v53;
              break;
            case 69u:
            case 71u:
              v50 = 1;
              v4 += 32;
              goto LABEL_49;
            case 101u:
            case 102u:
            case 103u:
LABEL_49:
              v6 |= 0x40u;
              v39 = (int)v53;
              if ( v40 >= 0 )
              {
                if ( !v40 && v4 == 103 )
                  v40 = 1;
              }
              else
              {
                v40 = 6;
              }
              a3 += 8;
              v27 = *(_DWORD *)(a3 - 4);
              v51 = *(_DWORD *)(a3 - 8);
              v52 = v27;
              _cfltcvt_tab(&v51, v53, (char)v4, v40, v50);
              if ( (unsigned __int8)(v6 & 0x80) && !v40 )
                off_520D4C(v53);
              if ( v4 == 103 && !(v6 & 0x80) )
                off_520D44(v53);
              if ( v53[0] == 45 )
              {
                v6 |= 0x100u;
                v39 = (int)&v53[1];
              }
              v7 = strlen((const char *)v39);
              break;
            case 83u:
              if ( !(v6 & 0x830) )
                v6 |= 0x800u;
              goto LABEL_53;
            case 115u:
LABEL_53:
              v14 = 2147483647;
              if ( v40 != -1 )
                v14 = v40;
              v15 = get_int_arg(&a3);
              v39 = v15;
              if ( v6 & 0x810 )
              {
                if ( !v15 )
                  v39 = (int)__wnullstring;
                v16 = (const WCHAR *)v39;
                v7 = 0;
                for ( i = 1; v7 < v14; ++v16 )
                {
                  if ( !*v16 )
                    break;
                  v17 = wctomb((int)&v37, *v16);
                  if ( !v17 )
                    break;
                  v7 += v17;
                }
              }
              else
              {
                if ( !v39 )
                  v39 = (int)__nullstring;
                v28 = v39;
                v29 = v14;
                v30 = v14 - 1;
                if ( v29 )
                {
                  do
                  {
                    if ( !*(_BYTE *)v28 )
                      break;
                    ++v28;
                    v31 = v30--;
                  }
                  while ( v31 );
                }
                v7 = v28 - v39;
              }
              break;
            case 90u:
              v18 = get_int_arg(&a3);
              if ( v18 && (v19 = *(_DWORD *)(v18 + 4)) != 0 )
              {
                if ( v6 & 0x800 )
                {
                  i = 1;
                  v7 = (unsigned int)*(_WORD *)v18 >> 1;
                  v39 = v19;
                }
                else
                {
                  i = 0;
                  v7 = *(_WORD *)v18;
                  v39 = v19;
                }
              }
              else
              {
                v39 = (int)__nullstring;
                v7 = strlen(__nullstring);
              }
              break;
            case 100u:
            case 105u:
              v6 |= 0x40u;
              v20 = 10;
              goto LABEL_80;
            case 110u:
              v21 = get_int_arg(&a3);
              if ( v6 & 0x20 )
                *(_WORD *)v21 = v42;
              else
                *(_DWORD *)v21 = v42;
              v49 = 1;
              break;
            case 111u:
              v20 = 8;
              if ( v6 & 0x80 )
                v6 |= 0x200u;
              goto LABEL_80;
            case 112u:
              v40 = 8;
              goto LABEL_77;
            case 88u:
LABEL_77:
              v48 = 7;
              goto LABEL_78;
            case 117u:
              v20 = 10;
              goto LABEL_80;
            case 120u:
              v48 = 39;
LABEL_78:
              v20 = 16;
              if ( v6 & 0x80 )
              {
                v38[0] = 48;
                v45 = 2;
                v38[1] = v48 + 81;
              }
LABEL_80:
              if ( v6 & 0x8000 )
              {
                v41[0] = get_int64_arg(&a3);
                v41[1] = v22;
                goto LABEL_92;
              }
              if ( v6 & 0x20 )
              {
                if ( v6 & 0x40 )
                {
                  *(_QWORD *)v41 = (signed __int16)get_int_arg(&a3);
                  goto LABEL_92;
                }
                v23 = (unsigned __int16)get_int_arg(&a3);
              }
              else
              {
                if ( v6 & 0x40 )
                {
                  v41[0] = get_int_arg(&a3);
                  *(_QWORD *)v41 = v41[0];
                  goto LABEL_92;
                }
                v23 = get_int_arg(&a3);
              }
              v41[0] = v23;
              v41[1] = 0;
LABEL_92:
              if ( v6 & 0x40 && *(_QWORD *)v41 < 0i64 )
              {
                LODWORD(v43) = -v41[0];
                v6 |= 0x100u;
                HIDWORD(v43) = -*(_QWORD *)v41 >> 32;
              }
              else
              {
                v43 = *(_QWORD *)v41;
              }
              if ( !(v6 & 0x8000) )
                HIDWORD(v43) = 0;
              if ( v40 >= 0 )
                v6 &= 0xFFFFFFF7u;
              else
                v40 = 1;
              if ( !v43 )
                v45 = 0;
              v39 = (int)&v54;
              while ( 1 )
              {
                v24 = v40--;
                if ( v24 <= 0 )
                {
                  if ( !v43 )
                    break;
                }
                *(_QWORD *)v41 = v20;
                v25 = v43 % v20 + 48;
                v43 /= (unsigned __int64)v20;
                if ( v25 > 57 )
                  LOBYTE(v25) = v48 + v25;
                v26 = v39--;
                *(_BYTE *)v26 = v25;
              }
              v7 = (int)(&v54 - v39++);
              if ( v6 & 0x200 && (*(_BYTE *)v39 != 48 || !v7) )
              {
                ++v7;
                --v39;
                *(_BYTE *)v39 = 48;
              }
              break;
            default:
              break;
          }
        }
        if ( v49 )
          goto LABEL_36;
        if ( !(v6 & 0x40) )
          goto LABEL_142;
        if ( v6 & 0x100 )
        {
          v38[0] = 45;
        }
        else if ( v6 & 1 )
        {
          v38[0] = 43;
        }
        else
        {
          if ( !(v6 & 2) )
          {
LABEL_142:
            v41[0] = v44 - v7 - v45;
            if ( !(v6 & 0xC) )
              write_multi_char(0x20u, v41[0], (int)a1, (int)&v42);
            write_string((int)v38, v45, (int)a1, (int)&v42);
            if ( v6 & 8 && !(v6 & 4) )
              write_multi_char(0x30u, v41[0], (int)a1, (int)&v42);
            if ( i && v7 > 0 )
            {
              v32 = v39;
              v33 = v7 - 1;
              do
              {
                v34 = *(_WORD *)v32;
                v32 += 2;
                v35 = wctomb((int)&v38[2], v34);
                if ( v35 <= 0 )
                  break;
                write_string((int)&v38[2], v35, (int)a1, (int)&v42);
                v36 = v33--;
              }
              while ( v36 );
            }
            else
            {
              write_string(v39, v7, (int)a1, (int)&v42);
            }
            if ( v6 & 4 )
              write_multi_char(0x20u, v41[0], (int)a1, (int)&v42);
            goto LABEL_36;
          }
          v38[0] = 32;
        }
        v45 = 1;
        goto LABEL_142;
      default:
        goto LABEL_36;
    }
  }
  return v42;
}
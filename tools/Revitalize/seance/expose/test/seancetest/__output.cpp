int __cdecl _output(FILE *a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 *v3; // eax@1
  unsigned __int8 v4; // bl@1
  char v5; // zf@1
  int v6; // esi@2
  int v7; // edi@2
  signed int v8; // eax@6
  unsigned int v9; // ecx@8
  int v10; // eax@19
  int v11; // eax@36
  wchar_t v13; // ax@46
  signed int v14; // ebx@53
  int v15; // eax@55
  wchar_t *v16; // ebp@58
  int v17; // eax@60
  int v18; // eax@63
  int v19; // ecx@64
  signed int v20; // edi@69
  int v21; // eax@70
  unsigned __int64 v22; // qax@81
  unsigned int v23; // eax@87
  int v24; // eax@105
  signed int v25; // ebx@107
  int v26; // eax@109
  int v27; // edx@117
  int v28; // edi@130
  signed int v29; // eax@130
  int v30; // ebx@130
  int v31; // eax@132
  int v32; // ebx@150
  int v33; // ebp@150
  wchar_t v34; // ax@151
  int v35; // eax@151
  int v36; // ecx@152
  char v37; // [sp+10h] [bp-248h]@60
  char v38[6]; // [sp+12h] [bp-246h]@79
  int v39; // [sp+18h] [bp-240h]@49
  int v40; // [sp+1Ch] [bp-23Ch]@10
  unsigned __int64 v41; // [sp+20h] [bp-238h]@81
  int v42; // [sp+28h] [bp-230h]@1
  unsigned __int64 v43; // [sp+2Ch] [bp-22Ch]@95
  int v44; // [sp+34h] [bp-224h]@10
  int v45; // [sp+38h] [bp-220h]@10
  int i; // [sp+3Ch] [bp-21Ch]@10
  unsigned int v47; // [sp+40h] [bp-218h]@1
  int v48; // [sp+44h] [bp-214h]@77
  int v49; // [sp+48h] [bp-210h]@10
  int v50; // [sp+4Ch] [bp-20Ch]@10
  int v51; // [sp+50h] [bp-208h]@117
  int v52; // [sp+54h] [bp-204h]@117
  char v53[4]; // [sp+58h] [bp-200h]@2
  char v54; // [sp+257h] [bp-1h]@104
  int v55; // [sp+260h] [bp+8h]@1

  v3 = a2;
  v55 = (int)(a2 + 1);
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
      v8 = (char)v4 < 32 || (char)v4 > 120 ? 0 : *((_BYTE *)&byte_4EB148 + (char)v4) & 0xF;
      v9 = (char)(*(&byte_4EB168[8 * v8] + v47) >> 4);
      v47 = v9;
      if ( v9 <= 7 )
        break;
LABEL_36:
      v11 = v55++;
      v4 = *(_BYTE *)v11;
      if ( !*(_BYTE *)v11 )
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
              if ( *(_BYTE *)v55 != 54 || *(_BYTE *)(v55 + 1) != 52 )
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
        if ( *((_BYTE *)off_520FE0 + 2 * v4 + 1) & 0x80 )
        {
          write_char((char)v4, a1, (int)&v42);
          v4 = *(_BYTE *)v55++;
        }
        write_char((char)v4, a1, (int)&v42);
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
                v13 = get_short_arg(&a3);
                v7 = wctomb(v53, v13);
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
              off_520D40(&v51, v53, (char)v4, v40, v50);
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
                  v39 = (int)off_520FD8;
                v16 = (wchar_t *)v39;
                v7 = 0;
                for ( i = 1; v7 < v14; ++v16 )
                {
                  if ( !*v16 )
                    break;
                  v17 = wctomb(&v37, *v16);
                  if ( !v17 )
                    break;
                  v7 += v17;
                }
              }
              else
              {
                if ( !v39 )
                  v39 = (int)off_520FD4;
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
                v39 = (int)off_520FD4;
                v7 = strlen(off_520FD4);
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
                LODWORD(v22) = get_int64_arg(&a3);
                v41 = v22;
                goto LABEL_92;
              }
              if ( v6 & 0x20 )
              {
                if ( v6 & 0x40 )
                {
                  v41 = (signed __int16)get_int_arg(&a3);
                  goto LABEL_92;
                }
                v23 = (unsigned __int16)get_int_arg(&a3);
              }
              else
              {
                if ( v6 & 0x40 )
                {
                  LODWORD(v41) = get_int_arg(&a3);
                  v41 = (signed int)v41;
                  goto LABEL_92;
                }
                v23 = get_int_arg(&a3);
              }
              v41 = v23;
LABEL_92:
              if ( v6 & 0x40 && SHIDWORD(v41) <= 0 && SHIDWORD(v41) < 0 )
              {
                LODWORD(v43) = -(signed int)v41;
                v6 |= 0x100u;
                HIDWORD(v43) = (unsigned __int64)-(signed __int64)v41 >> 32;
              }
              else
              {
                v43 = v41;
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
                v41 = v20;
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
          goto LABEL_143;
        if ( v6 & 0x100 )
        {
          v38[0] = 45;
        }
        else
        {
          if ( v6 & 1 )
          {
            v38[0] = 43;
          }
          else
          {
            if ( !(v6 & 2) )
            {
LABEL_143:
              LODWORD(v41) = v44 - v7 - v45;
              if ( !(v6 & 0xC) )
                write_multi_char(32, v41, a1, (int)&v42);
              write_string((int)v38, v45, a1, (int)&v42);
              if ( v6 & 8 && !(v6 & 4) )
                write_multi_char(48, v41, a1, (int)&v42);
              if ( i && v7 > 0 )
              {
                v32 = v39;
                v33 = v7 - 1;
                do
                {
                  v34 = *(_WORD *)v32;
                  v32 += 2;
                  v35 = wctomb(&v38[2], v34);
                  if ( v35 <= 0 )
                    break;
                  write_string((int)&v38[2], v35, a1, (int)&v42);
                  v36 = v33--;
                }
                while ( v36 );
              }
              else
              {
                write_string(v39, v7, a1, (int)&v42);
              }
              if ( v6 & 4 )
                write_multi_char(32, v41, a1, (int)&v42);
              goto LABEL_36;
            }
            v38[0] = 32;
          }
        }
        v45 = 1;
        goto LABEL_143;
      default:
        goto LABEL_36;
    }
  }
  return v42;
}

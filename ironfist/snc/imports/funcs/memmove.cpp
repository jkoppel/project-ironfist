{
  int v5; // edi@4
  int v6; // esi@4
  void *result; // eax@5
  int v8; // ecx@10
  void *v9; // edi@10
  const void *v10; // esi@10
  unsigned int v11; // ecx@10
  char *v12; // esi@12
  char *v13; // edi@12
  const void *v14; // esi@13
  void *v15; // edi@13
  int v16; // edi@13
  int v17; // esi@13
  const void *v18; // esi@18
  void *v19; // edi@18
  int v20; // edx@19
  const void *v21; // esi@19
  void *v22; // edi@19
  unsigned int v23; // ecx@19

  if ( a3 > a4 && a3 < (char *)a4 + a5 )
  {
    v12 = (char *)a4 + a5;
    v13 = (char *)a3 + a5;
    if ( (unsigned int)((char *)a3 + a5) & 3 )
    {
      v18 = v12 - 1;
      v19 = v13 - 1;
      if ( a5 <= 0xC )
      {
        memcpy(v19, v18, a5);
        result = a3;
      }
      else
      {
        v20 = -a2 & 3;
        memcpy(v19, v18, v20);
        v21 = (char *)v18 + v20 - 3;
        v22 = (char *)v19 + v20 - 3;
        v23 = (a5 - v20) >> 2;
        memcpy(v22, v21, 4 * v23);
        v17 = (int)((char *)v21 + 4 * v23);
        v16 = (int)((char *)v22 + 4 * v23);
        switch ( (a5 - v20) & 3 )
        {
          case 0u:
            goto LABEL_17;
          case 1u:
LABEL_16:
            *(_BYTE *)(v16 + 3) = *(_BYTE *)(v17 + 3);
LABEL_17:
            result = a3;
            break;
          case 2u:
LABEL_15:
            *(_WORD *)(v16 + 2) = *(_WORD *)(v17 + 2);
            result = a3;
            break;
          case 3u:
            goto LABEL_14;
        }
      }
    }
    else
    {
      v14 = v12 - 4;
      v15 = v13 - 4;
      memcpy(v15, v14, 4 * (a5 >> 2));
      v17 = (int)((char *)v14 + 4 * (a5 >> 2));
      v16 = (int)((char *)v15 + 4 * (a5 >> 2));
      switch ( a5 & 3 )
      {
        case 0u:
          goto LABEL_17;
        case 1u:
          goto LABEL_16;
        case 2u:
          goto LABEL_15;
        case 3u:
          break;
      }
LABEL_14:
      *(_WORD *)(v16 + 2) = *(_WORD *)(v17 + 2);
      *(_BYTE *)(v16 + 1) = *(_BYTE *)(v17 + 1);
      result = a3;
    }
  }
  else if ( (unsigned __int8)a3 & 3 )
  {
    if ( a5 <= 0xC )
    {
      memcpy(a3, a4, a5);
      result = a3;
    }
    else
    {
      v8 = -(signed int)a3 & 3;
      memcpy(a3, a4, v8);
      v10 = (char *)a4 + v8;
      v9 = (char *)a3 + v8;
      v11 = (a5 - (-(signed int)a3 & 3)) >> 2;
      memcpy(v9, v10, 4 * v11);
      v6 = (int)((char *)v10 + 4 * v11);
      v5 = (int)((char *)v9 + 4 * v11);
      switch ( (a5 - (-(signed int)a3 & 3)) & 3 )
      {
        case 0u:
          goto LABEL_8;
        case 1u:
LABEL_7:
          *(_BYTE *)v5 = *(_BYTE *)v6;
LABEL_8:
          result = a3;
          break;
        case 2u:
LABEL_6:
          *(_WORD *)v5 = *(_WORD *)v6;
          result = a3;
          break;
        case 3u:
          goto LABEL_5;
      }
    }
  }
  else
  {
    memcpy(a3, a4, 4 * (a5 >> 2));
    v6 = (int)((char *)a4 + 4 * (a5 >> 2));
    v5 = (int)((char *)a3 + 4 * (a5 >> 2));
    switch ( a5 & 3 )
    {
      case 0u:
        goto LABEL_8;
      case 1u:
        goto LABEL_7;
      case 2u:
        goto LABEL_6;
      case 3u:
        break;
    }
LABEL_5:
    *(_WORD *)v5 = *(_WORD *)v6;
    *(_BYTE *)(v5 + 2) = *(_BYTE *)(v6 + 2);
    result = a3;
  }
  return result;
}
{
  int v3; // edx@0
  int v4; // edi@4
  int v5; // esi@4
  void *result; // eax@5
  int v7; // ecx@10
  void *v8; // edi@10
  const void *v9; // esi@10
  unsigned int v10; // ecx@10
  char *v11; // esi@12
  char *v12; // edi@12
  const void *v13; // esi@13
  void *v14; // edi@13
  int v15; // edi@13
  int v16; // esi@13
  const void *v17; // esi@18
  void *v18; // edi@18
  int v19; // edx@19
  const void *v20; // esi@19
  void *v21; // edi@19
  unsigned int v22; // ecx@19

  if ( a1 > a2 && a1 < (char *)a2 + a3 )
  {
    v11 = (char *)a2 + a3;
    v12 = (char *)a1 + a3;
    if ( (unsigned int)((char *)a1 + a3) & 3 )
    {
      v17 = v11 - 1;
      v18 = v12 - 1;
      if ( a3 <= 0xC )
      {
        memcpy(v18, v17, a3);
        result = a1;
      }
      else
      {
        v19 = -v3 & 3;
        memcpy(v18, v17, v19);
        v20 = (char *)v17 + v19 - 3;
        v21 = (char *)v18 + v19 - 3;
        v22 = (a3 - v19) >> 2;
        memcpy(v21, v20, 4 * v22);
        v16 = (int)((char *)v20 + 4 * v22);
        v15 = (int)((char *)v21 + 4 * v22);
        switch ( (a3 - v19) & 3 )
        {
          case 0u:
            goto LABEL_17;
          case 1u:
LABEL_16:
            *(_BYTE *)(v15 + 3) = *(_BYTE *)(v16 + 3);
LABEL_17:
            result = a1;
            break;
          case 2u:
LABEL_15:
            *(_WORD *)(v15 + 2) = *(_WORD *)(v16 + 2);
            result = a1;
            break;
          case 3u:
            goto LABEL_14;
        }
      }
    }
    else
    {
      v13 = v11 - 4;
      v14 = v12 - 4;
      memcpy(v14, v13, 4 * (a3 >> 2));
      v16 = (int)((char *)v13 + 4 * (a3 >> 2));
      v15 = (int)((char *)v14 + 4 * (a3 >> 2));
      switch ( a3 & 3 )
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
      *(_WORD *)(v15 + 2) = *(_WORD *)(v16 + 2);
      *(_BYTE *)(v15 + 1) = *(_BYTE *)(v16 + 1);
      result = a1;
    }
  }
  else if ( (unsigned __int8)a1 & 3 )
  {
    if ( a3 <= 0xC )
    {
      memcpy(a1, a2, a3);
      result = a1;
    }
    else
    {
      v7 = -(signed int)a1 & 3;
      memcpy(a1, a2, v7);
      v9 = (char *)a2 + v7;
      v8 = (char *)a1 + v7;
      v10 = (a3 - (-(signed int)a1 & 3)) >> 2;
      memcpy(v8, v9, 4 * v10);
      v5 = (int)((char *)v9 + 4 * v10);
      v4 = (int)((char *)v8 + 4 * v10);
      switch ( (a3 - (-(signed int)a1 & 3)) & 3 )
      {
        case 0u:
          goto LABEL_8;
        case 1u:
LABEL_7:
          *(_BYTE *)v4 = *(_BYTE *)v5;
LABEL_8:
          result = a1;
          break;
        case 2u:
LABEL_6:
          *(_WORD *)v4 = *(_WORD *)v5;
          result = a1;
          break;
        case 3u:
          goto LABEL_5;
      }
    }
  }
  else
  {
    memcpy(a1, a2, 4 * (a3 >> 2));
    v5 = (int)((char *)a2 + 4 * (a3 >> 2));
    v4 = (int)((char *)a1 + 4 * (a3 >> 2));
    switch ( a3 & 3 )
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
    *(_WORD *)v4 = *(_WORD *)v5;
    *(_BYTE *)(v4 + 2) = *(_BYTE *)(v5 + 2);
    result = a1;
  }
  return result;
}
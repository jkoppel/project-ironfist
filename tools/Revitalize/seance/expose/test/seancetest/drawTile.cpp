char __cdecl drawTile(Tileset *tileset, int idx, Bitmap *targ, int x, int y)
{
  int width; // ebx@1
  unsigned __int8 *curDest; // edi@1
  unsigned int v7; // ecx@1
  int v8; // ebx@1
  int v9; // edx@1
  char *curSrc; // esi@1
  int v11; // eax@3
  const void *v12; // esi@4
  void *v13; // edi@4
  const void *v14; // esi@4
  void *v15; // edi@4
  const void *v16; // esi@4
  void *v17; // edi@4
  const void *v18; // esi@4
  void *v19; // edi@4
  const void *v20; // esi@4
  void *v21; // edi@4
  const void *v22; // esi@4
  void *v23; // edi@4
  const void *v24; // esi@4
  void *v25; // edi@4
  const void *v26; // esi@4
  void *v27; // edi@4
  const void *v28; // esi@4
  void *v29; // edi@4
  const void *v30; // esi@4
  void *v31; // edi@4
  const void *v32; // esi@4
  void *v33; // edi@4
  const void *v34; // esi@4
  void *v35; // edi@4
  const void *v36; // esi@4
  void *v37; // edi@4
  const void *v38; // esi@4
  void *v39; // edi@4
  const void *v40; // esi@4
  void *v41; // edi@4
  int v42; // esi@6
  __int16 v43; // dx@6
  int v44; // edi@10
  int v45; // ebx@10
  unsigned int v46; // edx@10
  unsigned int v47; // ecx@11
  int v48; // esi@12
  int v49; // edi@12
  int v50; // esi@15
  unsigned int v51; // edx@15
  unsigned int v52; // ecx@16
  int v53; // esi@17
  _BYTE *v54; // edi@17
  int idxa; // [sp+14h] [bp+Ch]@1

  width = targ->width;
  curDest = &targ->contents[x] + width * y;
  dword_5206C4 = idx;
  idxa = idx & 0xFFF;
  v7 = tileset->field_12;
  v8 = width - v7;
  HIWORD(v9) = (unsigned int)idxa * (unsigned __int64)(tileset->field_14 * (unsigned int)tileset->field_12) >> 48;
  LOWORD(v9) = tileset->field_14;
  curSrc = (char *)tileset->contents + idxa * tileset->field_14 * tileset->field_12;
  if ( dword_5206C4 & 0x8000 )
  {
    if ( dword_5206C4 & 0x4000 )
    {
      v50 = (int)&curSrc[v7 * v7 - 1];
      v51 = v7 >> 3;
      dword_5206C8 = tileset->field_12;
      do
      {
        v52 = v51;
        do
        {
          LOBYTE(v11) = *(_BYTE *)v50;
          v53 = v50 + 1;
          *curDest = v11;
          v54 = curDest + 1;
          LOBYTE(v11) = *(_BYTE *)v53++;
          *v54++ = v11;
          LOBYTE(v11) = *(_BYTE *)v53++;
          *v54++ = v11;
          LOBYTE(v11) = *(_BYTE *)v53++;
          *v54++ = v11;
          LOBYTE(v11) = *(_BYTE *)v53++;
          *v54++ = v11;
          LOBYTE(v11) = *(_BYTE *)v53++;
          *v54++ = v11;
          LOBYTE(v11) = *(_BYTE *)v53++;
          *v54++ = v11;
          LOBYTE(v11) = *(_BYTE *)v53;
          v50 = v53 + 1;
          *v54 = v11;
          curDest = v54 + 1;
          --v52;
        }
        while ( v52 );
        curDest += v8;
        --dword_5206C8;
      }
      while ( dword_5206C8 );
    }
    else
    {
      v44 = (int)&curDest[v7 - 1];
      dword_5206C8 = v9;
      v45 = v7 + v7 + v8;
      v46 = v7 >> 3;
      do
      {
        v47 = v46;
        do
        {
          LOBYTE(v11) = *curSrc;
          v48 = (int)(curSrc + 1);
          *(_BYTE *)v44 = v11;
          v49 = v44 - 1;
          LOBYTE(v11) = *(_BYTE *)v48++;
          *(_BYTE *)v49-- = v11;
          LOBYTE(v11) = *(_BYTE *)v48++;
          *(_BYTE *)v49-- = v11;
          LOBYTE(v11) = *(_BYTE *)v48++;
          *(_BYTE *)v49-- = v11;
          LOBYTE(v11) = *(_BYTE *)v48++;
          *(_BYTE *)v49-- = v11;
          LOBYTE(v11) = *(_BYTE *)v48++;
          *(_BYTE *)v49-- = v11;
          LOBYTE(v11) = *(_BYTE *)v48++;
          *(_BYTE *)v49-- = v11;
          LOBYTE(v11) = *(_BYTE *)v48;
          curSrc = (char *)(v48 + 1);
          *(_BYTE *)v49 = v11;
          v44 = v49 - 1;
          --v47;
        }
        while ( v47 );
        v44 += v45;
        --dword_5206C8;
      }
      while ( dword_5206C8 );
    }
  }
  else
  {
    if ( dword_5206C4 & 0x4000 )
    {
      v42 = (int)&curSrc[v7 * (v7 - 1)];
      v11 = tileset->field_12;
      v43 = tileset->field_12;
      do
      {
        memcpy(curDest, (const void *)v42, 4 * ((unsigned int)v11 >> 2));
        curDest += 4 * ((unsigned int)v11 >> 2) + v8;
        v42 = v42 + 4 * ((unsigned int)v11 >> 2) - v11 - v11;
        --v43;
      }
      while ( v43 );
    }
    else
    {
      v11 = v7 >> 2;
      do
      {
        memcpy(curDest, curSrc, 4 * v11);
        v12 = &curSrc[4 * v11];
        v13 = &curDest[4 * v11] + v8;
        memcpy(v13, v12, 4 * v11);
        v14 = (char *)v12 + 4 * v11;
        v15 = (char *)v13 + 4 * v11 + v8;
        memcpy(v15, v14, 4 * v11);
        v16 = (char *)v14 + 4 * v11;
        v17 = (char *)v15 + 4 * v11 + v8;
        memcpy(v17, v16, 4 * v11);
        v18 = (char *)v16 + 4 * v11;
        v19 = (char *)v17 + 4 * v11 + v8;
        memcpy(v19, v18, 4 * v11);
        v20 = (char *)v18 + 4 * v11;
        v21 = (char *)v19 + 4 * v11 + v8;
        memcpy(v21, v20, 4 * v11);
        v22 = (char *)v20 + 4 * v11;
        v23 = (char *)v21 + 4 * v11 + v8;
        memcpy(v23, v22, 4 * v11);
        v24 = (char *)v22 + 4 * v11;
        v25 = (char *)v23 + 4 * v11 + v8;
        memcpy(v25, v24, 4 * v11);
        v26 = (char *)v24 + 4 * v11;
        v27 = (char *)v25 + 4 * v11 + v8;
        memcpy(v27, v26, 4 * v11);
        v28 = (char *)v26 + 4 * v11;
        v29 = (char *)v27 + 4 * v11 + v8;
        memcpy(v29, v28, 4 * v11);
        v30 = (char *)v28 + 4 * v11;
        v31 = (char *)v29 + 4 * v11 + v8;
        memcpy(v31, v30, 4 * v11);
        v32 = (char *)v30 + 4 * v11;
        v33 = (char *)v31 + 4 * v11 + v8;
        memcpy(v33, v32, 4 * v11);
        v34 = (char *)v32 + 4 * v11;
        v35 = (char *)v33 + 4 * v11 + v8;
        memcpy(v35, v34, 4 * v11);
        v36 = (char *)v34 + 4 * v11;
        v37 = (char *)v35 + 4 * v11 + v8;
        memcpy(v37, v36, 4 * v11);
        v38 = (char *)v36 + 4 * v11;
        v39 = (char *)v37 + 4 * v11 + v8;
        memcpy(v39, v38, 4 * v11);
        v40 = (char *)v38 + 4 * v11;
        v41 = (char *)v39 + 4 * v11 + v8;
        memcpy(v41, v40, 4 * v11);
        curSrc = (char *)v40 + 4 * v11;
        curDest = (unsigned __int8 *)((char *)v41 + 4 * v11 + v8);
        LOWORD(v9) = v9 - 16;
      }
      while ( (_WORD)v9 );
    }
  }
  return v11;
}

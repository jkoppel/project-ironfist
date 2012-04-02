void __thiscall sub_4C7320(int this)
{
  int a1a; // ebx@1
  int v2; // eax@12
  int v3; // esi@14
  unsigned int v4; // ecx@14
  int v5; // edx@15
  char *v6; // edx@15
  void *v7; // ecx@17
  int v8; // eax@22
  char *v9; // edx@24
  int v10; // edx@26
  int v11; // ecx@27
  int a1; // [sp+10h] [bp-Ch]@17
  char v13; // [sp+14h] [bp-8h]@14
  char v14; // [sp+15h] [bp-7h]@14
  char v15; // [sp+16h] [bp-6h]@14
  char v16; // [sp+17h] [bp-5h]@14
  char v17; // [sp+18h] [bp-4h]@14
  char v18; // [sp+19h] [bp-3h]@14
  char v19; // [sp+1Ah] [bp-2h]@14
  char v20; // [sp+1Bh] [bp-1h]@14

  ++dword_51E410;
  a1a = this;
  if ( HeroWindowManager::instance
    && palette
    && HeroWindowManager::instance->ready == 1
    && (HeroWindowManager::instance->field_56 || this) )
  {
    if ( dword_4F19A0 )
      dword_51E40C = 1 - dword_51E40C;
    else
      dword_51E40C = 1;
    if ( dword_51E40C )
    {
      if ( dword_4F19A0 == 2 )
      {
        dword_51E408 = (((unsigned __int64)(dword_51E408 + 1) >> 32) ^ abs(dword_51E408 + 1) & 7)
                     - ((unsigned __int64)(dword_51E408 + 1) >> 32);
        if ( dword_51E408 < 5 )
          v2 = dword_51E408;
        else
          v2 = 8 - dword_51E408;
        v13 = -104;
        v14 = 67;
        v15 = 89;
        v16 = -75;
        v17 = 112;
        v3 = 0;
        v4 = (unsigned int)&paletteSectionThing;
        v18 = -37;
        v19 = -121;
        v20 = 16;
        do
        {
          v4 += 3;
          v5 = 3 * v2 + (unsigned __int8)*(&v13 + v3++);
          v6 = (char *)palette->contents + 3 * v5;
          *(_WORD *)(v4 - 3) = *(_WORD *)v6;
          *(_BYTE *)(v4 - 1) = v6[2];
        }
        while ( v4 < (unsigned int)((char *)&paletteSectionThing + 24) );
        goto LABEL_31;
      }
      v7 = (char *)&paletteSectionThing + 9;
      LOWORD(a1) = *(_WORD *)((char *)&paletteSectionThing + 9);
      BYTE2(a1) = *((_BYTE *)&paletteSectionThing + 11);
      LOBYTE(v7) = BYTE2(a1);
      memcpy_0(v7, (unsigned __int16)&a1, (char *)&paletteSectionThing + 3, &paletteSectionThing, 9u);
      *(_WORD *)&paletteSectionThing = a1;
      *((_BYTE *)&paletteSectionThing + 2) = BYTE2(a1);
      LOWORD(a1) = *(_WORD *)((char *)&paletteSectionThing + 21);
      BYTE2(a1) = *((_BYTE *)&paletteSectionThing + 23);
      memcpy_0(
        &a1,
        *(_WORD *)((char *)&paletteSectionThing + 21),
        (char *)&paletteSectionThing + 15,
        (char *)&paletteSectionThing + 12,
        9u);
      *((_WORD *)&paletteSectionThing + 6) = a1;
      *((_BYTE *)&paletteSectionThing + 14) = BYTE2(a1);
      LOWORD(a1) = *(_WORD *)((char *)&paletteSectionThing + 51);
      BYTE2(a1) = *((_BYTE *)&paletteSectionThing + 53);
      memcpy_0(
        &a1,
        *(_WORD *)((char *)&paletteSectionThing + 51),
        (char *)&paletteSectionThing + 51,
        (char *)&paletteSectionThing + 54,
        0xCu);
      *(_WORD *)((char *)&paletteSectionThing + 63) = a1;
      *((_BYTE *)&paletteSectionThing + 65) = BYTE2(a1);
      LOWORD(a1) = *(_WORD *)((char *)&paletteSectionThing + 81);
      BYTE2(a1) = *((_BYTE *)&paletteSectionThing + 83);
      memcpy_0(
        &a1,
        *(_WORD *)((char *)&paletteSectionThing + 81),
        (char *)&paletteSectionThing + 75,
        (char *)&paletteSectionThing + 72,
        9u);
      *((_WORD *)&paletteSectionThing + 36) = a1;
      *((_BYTE *)&paletteSectionThing + 74) = BYTE2(a1);
      LOWORD(a1) = *(_WORD *)((char *)&paletteSectionThing + 93);
      BYTE2(a1) = *((_BYTE *)&paletteSectionThing + 95);
      memcpy_0(
        &a1,
        *(_WORD *)((char *)&paletteSectionThing + 93),
        (char *)&paletteSectionThing + 87,
        (char *)&paletteSectionThing + 84,
        9u);
      *((_WORD *)&paletteSectionThing + 42) = a1;
      *((_BYTE *)&paletteSectionThing + 86) = BYTE2(a1);
    }
    if ( !dword_4F19A0 )
    {
      LOWORD(a1) = *(_WORD *)((char *)&paletteSectionThing + 69);
      BYTE2(a1) = *((_BYTE *)&paletteSectionThing + 71);
      memcpy_0(
        &a1,
        *(_WORD *)((char *)&paletteSectionThing + 69),
        (char *)&paletteSectionThing + 69,
        (char *)&paletteSectionThing + 66,
        3u);
      *((_WORD *)&paletteSectionThing + 33) = a1;
      *((_BYTE *)&paletteSectionThing + 68) = BYTE2(a1);
      goto LABEL_31;
    }
    if ( dword_4F19A0 == 1 )
    {
      dword_51E408 = (((unsigned __int64)(dword_51E408 + 1) >> 32) ^ abs(dword_51E408 + 1) & 7)
                   - ((unsigned __int64)(dword_51E408 + 1) >> 32);
      if ( dword_51E408 < 5 )
        v8 = dword_51E408;
      else
        v8 = 8 - dword_51E408;
      v9 = (char *)&palette->contents->colors[4 * v8 + 110];
    }
    else
    {
      if ( dword_4F19A0 != 3 )
        goto LABEL_31;
      v10 = (dword_51E408 + 1) % 6;
      dword_51E408 = v10;
      if ( v10 < 4 )
        v11 = dword_51E408;
      else
        v11 = 6 - v10;
      v9 = (char *)&palette->contents->colors[7 * v11 + 108];
    }
    *((_WORD *)&paletteSectionThing + 33) = *(_WORD *)v9;
    *((_BYTE *)&paletteSectionThing + 68) = v9[2];
LABEL_31:
    memcpy(&palette->contents->colors[214], &paletteSectionThing, 0x54u);
    ++dword_51E414;
    if ( !a1a )
    {
      ++dword_51E418;
      sub_49CFB0(palette->contents);
    }
  }
}

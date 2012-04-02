void __fastcall sub_4CAAC0(const void *a1, void *a2, signed int a3)
{
  int v3; // eax@4
  char *v4; // esi@6
  void *v5; // edi@6
  signed int v6; // ebp@6
  char v7; // cl@7
  __int64 v8; // qax@7
  int v9; // eax@7
  char v10; // al@8
  signed int v11; // [sp+10h] [bp-310h]@3
  int v12; // [sp+14h] [bp-30Ch]@6
  void *v13; // [sp+18h] [bp-308h]@1
  int this; // [sp+1Ch] [bp-304h]@4
  char v15; // [sp+20h] [bp-300h]@1
  signed int v16; // [sp+324h] [bp+4h]@1

  v13 = a2;
  memcpy(&v15, a1, 0x300u);
  v16 = a3 >> 2;
  if ( v16 < 1 )
    v16 = 1;
  v11 = 48;
  do
  {
    this = getTickCount() + 50;
    yieldToGlobalUpdater();
    v3 = 64 - v11 - v16;
    if ( 64 - v11 - v16 < 0 )
      v3 = 0;
    v4 = &v15;
    v5 = v13;
    v6 = 768;
    v12 = (unsigned __int8)byte_51E528[v3];
    do
    {
      v7 = *v4;
      v8 = *(_BYTE *)v5 - (unsigned __int8)*v4;
      v9 = (HIDWORD(v8) ^ v8) - HIDWORD(v8);
      if ( v12 < v9 )
      {
        v10 = v9 - v12;
        if ( *(_BYTE *)v5 - (unsigned __int8)*v4 <= 0 )
          *v4 = v7 - v10;
        else
          *v4 = v7 + v10;
      }
      ++v4;
      v5 = (char *)v5 + 1;
      --v6;
    }
    while ( v6 );
    sub_49CFB0((PaletteContents *)&v15);
    sleepUntilPointer(&this);
    v11 += v16;
  }
  while ( v11 < 64 );
  sub_49CFB0((PaletteContents *)v13);
}

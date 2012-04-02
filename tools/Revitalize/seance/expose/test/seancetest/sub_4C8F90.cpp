int __fastcall sub_4C8F90(signed int a1)
{
  signed int v1; // ebx@1
  Palette *v2; // ebp@1
  Palette *v3; // ecx@1
  signed int v4; // esi@7
  int result; // eax@9
  signed int v6; // edx@13
  RGB *v7; // eax@14
  char *v8; // ecx@14
  char v9; // al@14
  signed int v10; // [sp+10h] [bp-8h]@5
  int this; // [sp+14h] [bp-4h]@11

  v1 = a1;
  v2 = 0;
  v3 = (Palette *)operator new(0x14u);
  if ( v3 )
    v2 = Palette_constructor(v3);
  if ( !v2 )
    fatalOutOfMemoryError();
  v10 = 0;
  if ( !*(&mainWindows + 7 * gameOrEditorIdx + 5) )
    v1 *= 2;
  memcpy(v2->contents, palette->contents, 0x300u);
  v4 = 0;
  while ( 1 )
  {
    if ( v4 < 64 )
      goto LABEL_11;
    result = v10;
    if ( v10 )
      break;
    v4 = 63;
LABEL_11:
    this = getTickCount() + 20;
    yieldToGlobalUpdater();
    if ( v4 == 63 )
      v10 = 1;
    v6 = 0;
    do
    {
      v7 = v2->contents->colors;
      v8 = (char *)v7 + v6;
      v9 = *(&v7->red + v6);
      if ( v9 > 0 )
      {
        if ( v9 <= v1 )
          *v8 = 0;
        else
          *v8 = v9 - v1;
      }
      ++v6;
    }
    while ( v6 < 768 );
    v4 += v1;
    sub_49CFB0(v2->contents);
    sleepUntilPointer(&this);
  }
  if ( v2 )
    result = v2->vtable->cleanUp((AbstractResource *)v2, 1);
  return result;
}

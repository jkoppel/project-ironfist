{
  int v1; // [sp+Ch] [bp-Ch]@3
  void *v2; // [sp+10h] [bp-8h]@1
  signed int v3; // [sp+14h] [bp-4h]@1

  v3 = 0;
  yieldToGlobalUpdater();
  v2 = sub_46E3F0(1);
  if ( v2 && *((_BYTE *)v2 + 5) == 2 )
  {
    v1 = *((_BYTE *)v2 + 6);
    if ( v1 == 1 )
    {
      v3 = sub_42BCA0(
             *(_DWORD *)((char *)v2 + 9),
             *(_DWORD *)((char *)v2 + 13),
             *(_DWORD *)((char *)v2 + 17),
             *(_BYTE *)v2);
    }
    else
    {
      if ( v1 == 32 )
      {
        memcpy(&byte_5247A0, (char *)v2 + 9, 6u);
        byte_526ED8 = *((_BYTE *)v2 + 15);
        byte_526DAC = *((_BYTE *)v2 + 16);
        memcpy(&dword_526CE0, (char *)v2 + 17, 0xCCu);
        dword_524730 = sub_435DC0((void *)dword_523F14);
      }
    }
  }
  return v3;
}

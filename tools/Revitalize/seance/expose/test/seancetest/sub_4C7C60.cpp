void __thiscall sub_4C7C60(HeroWindowManager *this, int flag, signed int a3, Palette *pal)
{
  HeroWindowManager *thisa; // esi@1
  int v5; // edi@6

  thisa = this;
  if ( pal )
    someSortOfPaletteSwap(pal->contents, 0);
  if ( flag )
  {
    if ( flag == 1 )
    {
      dword_532E54 = thisa->field_56;
      thisa->field_56 = 0;
      yieldToGlobalUpdater();
      sub_4C8F90(a3);
      yieldToGlobalUpdater();
    }
    else
    {
      yieldToGlobalUpdater();
    }
  }
  else
  {
    v5 = thisa->field_56;
    thisa->field_56 = 0;
    yieldToGlobalUpdater();
    sub_4C8EA0(a3);
    thisa->field_56 = v5 | dword_532E54;
    yieldToGlobalUpdater();
  }
}

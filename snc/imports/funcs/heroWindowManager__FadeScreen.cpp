{
  heroWindowManager *thisa; // esi@1
  int v5; // edi@6

  thisa = this;
  if ( pal )
    SetPalette(pal->contents, 0);
  if ( flag )
  {
    if ( flag == 1 )
    {
      dword_532E54 = thisa->field_56;
      thisa->field_56 = 0;
      PollSound();
      FadeOut(a3);
      PollSound();
    }
    else
    {
      PollSound();
    }
  }
  else
  {
    v5 = thisa->field_56;
    thisa->field_56 = 0;
    PollSound();
    FadeIn(a3);
    thisa->field_56 = v5 | dword_532E54;
    PollSound();
  }
}
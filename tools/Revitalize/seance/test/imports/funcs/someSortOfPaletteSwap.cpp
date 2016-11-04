{
  memcpy(palette->contents, a1, 0x300u);
  memcpy(&paletteSectionThing, &a1->colors[214], 0x60u);
  if ( a2 )
    sub_49CFB0(palette->contents);
}

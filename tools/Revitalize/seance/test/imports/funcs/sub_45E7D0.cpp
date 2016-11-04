{
  int result; // eax@2
  signed int v3; // eax@3
  int v4; // [sp+Ch] [bp-20h]@2
  int v5; // [sp+10h] [bp-1Ch]@1

  v5 = this;
  if ( *(_BYTE *)(this + 715) )
  {
    result = this;
    v4 = *(_BYTE *)(this + 715);
    switch ( v4 )
    {
      case 1:
        v3 = sub_419C90((void *)this, *(_WORD *)(this + 716), *(_WORD *)(this + 727));
        result = sprintf(
                   a2,
                   "Lose the %s '%s'.",
                   &aCastle[("town" - "castle") & (((*(_BYTE *)(v5 + 100 * v3 + 2923) & 0x40) != 0) - 1)],
                   v5 + 100 * v3 + 2986);
        break;
      case 2:
        result = sprintf(a2, "Lose the hero '%s'.", this + 250 * *(_WORD *)(this + 716) + 10190);
        break;
      case 3:
        result = sprintf(
                   a2,
                   "Fail to win by the end of month %d, week %d, day %d.",
                   (*(_WORD *)&gameObject->_2[1] - 1) / 28 + 1,
                   (*(_WORD *)&gameObject->_2[1] - 28 * ((*(_WORD *)&gameObject->_2[1] - 1) / 28) - 1) / 7 + 1,
                   (*(_WORD *)&gameObject->_2[1] - 1) % 7 + 1);
        break;
    }
  }
  else
  {
    result = sprintf(a2, "Lose all your heroes, towns and castles.");
  }
  return result;
}

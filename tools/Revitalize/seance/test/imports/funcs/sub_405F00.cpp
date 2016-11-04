{
  signed int result; // eax@2
  CreatureStack *thisa; // [sp+Ch] [bp-Ch]@1

  thisa = this;
  if ( checkHexGridIdxBounds(hex) )
  {
    if ( thisa->creature.creature_flags & FLYER )
    {
      result = sub_4012C0(thisa, hex, flag);
    }
    else
    {
      if ( sub_405DB0(thisa, thisa->occupiedHex, hex, thisa->creature.speed, 0, flag) )
      {
        thisa->targetHex = hex;
        result = 1;
      }
      else
      {
        result = 0;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

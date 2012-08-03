{
  signed int result; // eax@2
  army *thisa; // [sp+Ch] [bp-Ch]@1

  thisa = this;
  if ( ValidHex(hex) )
  {
    if ( thisa->creature.creature_flags & FLYER )
    {
      result = army::ValidFlight(thisa, hex, flag);
    }
    else if ( army::FindPath(thisa, thisa->occupiedHex, hex, thisa->creature.speed, 0, flag) )
    {
      thisa->targetHex = hex;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
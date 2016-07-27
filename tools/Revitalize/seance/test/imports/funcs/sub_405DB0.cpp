{
  int result; // eax@3
  int v7; // [sp+Ch] [bp-10h]@9
  CreatureStack *thisa; // [sp+10h] [bp-Ch]@1
  int v9; // [sp+14h] [bp-8h]@6
  char v10; // [sp+18h] [bp-4h]@4

  thisa = this;
  if ( checkHexGridIdxBounds(knownHex) && checkHexGridIdxBounds(targHex) )
  {
    v10 = thisa->creature.speed;
    if ( flying )
      thisa->creature.speed = 99;
    v9 = Pathfinder::doSomething1(pathfinder, knownHex, targHex, thisa, flag, 0);
    if ( !v9 && thisa->creature.creature_flags & 1 && !flag )
    {
      v7 = thisa->facingRight;
      if ( v7 )
      {
        if ( v7 == 1 )
          targHex = CreatureStack::getHexNeighbor(thisa, targHex, 4);
      }
      else
      {
        targHex = CreatureStack::getHexNeighbor(thisa, targHex, 1);
      }
      if ( checkHexGridIdxBounds(targHex) )
        v9 = Pathfinder::doSomething1(pathfinder, knownHex, targHex, thisa, 0, 1);
      else
        v9 = 0;
    }
    thisa->creature.speed = v10;
    result = v9;
  }
  else
  {
    result = 0;
  }
  return result;
}

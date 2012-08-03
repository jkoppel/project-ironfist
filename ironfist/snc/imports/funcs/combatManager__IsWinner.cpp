{
  signed int result; // eax@2
  int i; // [sp+10h] [bp-8h]@5
  signed int v4; // [sp+14h] [bp-4h]@5
  int sidea; // [sp+20h] [bp+8h]@5

  if ( this->field_351F[1 - side] )
  {
    result = 1;
  }
  else if ( this->field_F377[1 - side] )
  {
    result = 1;
  }
  else
  {
    sidea = side ^ 1;
    v4 = 1;
    for ( i = 0; this->numCreatures[sidea] > i; ++i )
    {
      if ( !(this->creatures[sidea][i].creature.creature_flags & DEAD) )
        v4 = 0;
    }
    result = v4;
  }
  return result;
}
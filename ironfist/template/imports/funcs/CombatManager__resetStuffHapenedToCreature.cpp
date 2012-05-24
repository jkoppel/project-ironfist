{
  spellpower_offset j; // [sp+10h] [bp-8h]@3
  signed int i; // [sp+14h] [bp-4h]@1

  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; j < MAX_STACKS; ++j )
    {
      if ( this->creatures[i][j].creature.creature_flags & DEAD )
        this->stuffHappenedToCreature[i][j] = -1;
      else
        this->stuffHappenedToCreature[i][j] = 0;
    }
  }
  this->field_F41F = 0;
  this->field_F423 = 0;
  this->field_F427[0] = 0;
  this->field_F427[1] = 0;
  combatScreenRedrawRectBot = 0;
  combatScreenRedrawRectRight = 0;
  combatScreenRedrawRectLeft = 639;
  combatScreenRedrawRectTop = 442;
}

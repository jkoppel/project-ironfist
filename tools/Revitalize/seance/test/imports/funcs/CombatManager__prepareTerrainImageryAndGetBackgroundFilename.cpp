{
  CombatManager *thisa; // [sp+10h] [bp-8h]@1
  signed int background; // [sp+14h] [bp-4h]@2

  thisa = this;
  this->field_31EA = 1;
  this->combatFieldFringeID = -1;
  switch ( this->terrainType )
  {
    case 0:
      background = 0;
      this->combatFieldFringeID = 13;
      break;
    case TERRAIN_IDX_GRASS:
      if ( sub_476310(this) )
      {
        background = 2;
        thisa->combatFieldFringeID = 12;
      }
      else
      {
        background = 3;
        thisa->combatFieldFringeID = 11;
      }
      break;
    case TERRAIN_IDX_SNOW:
      this->field_31EA = 3;
      if ( sub_476310(this) )
      {
        background = 4;
        thisa->combatFieldFringeID = 6;
      }
      else
      {
        background = 5;
        thisa->combatFieldFringeID = 7;
      }
      break;
    case TERRAIN_IDX_SNOW|TERRAIN_IDX_GRASS:
      background = 6;
      this->combatFieldFringeID = 8;
      break;
    case 4:
      background = 8;
      this->combatFieldFringeID = 5;
      break;
    case 5:
      this->field_31EA = 3;
      background = 10;
      this->combatFieldFringeID = 4;
      break;
    case TERRAIN_IDX_DIRT:
      if ( sub_476310(this) )
      {
        background = 12;
        thisa->combatFieldFringeID = 10;
      }
      else
      {
        background = 13;
        thisa->combatFieldFringeID = 9;
      }
      break;
    case TERRAIN_IDX_WASTELAND:
      this->field_31EA = 3;
      background = 14;
      this->combatFieldFringeID = 3;
      break;
    case 8:
      this->field_31EA = 3;
      background = 16;
      this->combatFieldFringeID = 2;
      break;
    default:
      background = 0;
      break;
  }
  return off_4F38B0[background];
}

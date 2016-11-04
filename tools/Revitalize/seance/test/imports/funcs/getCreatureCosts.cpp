{
  signed int i; // [sp+18h] [bp-4h]@1

  for ( i = 0; i < 7; ++i )
    costs[i] = 0;
  costs[6] = creature_table[creatureType].cost;
  switch ( creatureType )
  {
    case CREATURE_GENIE:
      costs[5] = 1;
      break;
    case CREATURE_PHOENIX:
      costs[1] = 1;
      break;
    case CREATURE_CYCLOPS:
      costs[4] = 1;
      break;
    case CREATURE_GREEN_DRAGON:
    case CREATURE_RED_DRAGON:
      costs[3] = 1;
      break;
    case CREATURE_BLACK_DRAGON:
      costs[3] = 2;
      break;
    case CREATURE_GIANT:
      costs[5] = 1;
      break;
    case CREATURE_TITAN:
      costs[5] = 2;
      break;
    default:
      return;
  }
}

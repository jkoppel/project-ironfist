{
  int trackNum; // [sp+30h] [bp-30h]@1
  char file; // [sp+3Ch] [bp-24h]@1
  int v5; // [sp+5Ch] [bp-4h]@1

  v5 = 22;
  strcpy(&file, byte_5184CC);
  trackNum = -1;
  switch ( locType )
  {
    case LOCATION_WAGON:
    case LOCATION_LEAN_TO:
    case LOCATION_ARCHERS_HOUSE:
    case LOCATION_GOBLIN_HUT:
    case LOCATION_DWARF_COTTAGE:
    case LOCATION_PEASANT_HUT:
    case LOCATION_LOG_CABIN:
    case LOCATION_WATCH_TOWER:
    case LOCATION_TREE_HOUSE:
    case LOCATION_DWARF_CABIN:
    case LOCATION_HALFLING_HOLE:
    case LOCATION_EXCAVATION:
    case LOCATION_CAVE:
      trackNum = 22;
      break;
    case LOCATION_LIGHTHOUSE:
    case LOCATION_XANADU:
      trackNum = 40;
      break;
    case LOCATION_SHRINE_FIRST:
    case LOCATION_SHRINE_SECOND_ORDER:
    case LOCATION_SHRINE_THIRD_ORDER:
      trackNum = 19;
      break;
    case LOCATION_ARTIFACT:
      if ( a2 == 1 )
        trackNum = 19;
      break;
    case LOCATION_SKELETON:
    case LOCATION_WATERWHEEL:
    case LOCATION_WINDMILL:
      trackNum = 19;
      break;
    case LOCATION_DAEMON_CAVE:
      trackNum = 36;
      break;
    case LOCATION_ORACLE:
    case LOCATION_ARTESIAN_SPRING:
    case LOCATION_MAGIC_WELL:
      trackNum = 32;
      break;
    case LOCATION_FAERIE_RING:
    case LOCATION_FOUNTAIN:
    case LOCATION_IDOL:
      trackNum = 101;
      break;
    case LOCATION_BUOY:
    case LOCATION_OASIS:
    case LOCATION_TEMPLE:
    case LOCATION_WATERING_HOLE:
      trackNum = 100;
      break;
    case LOCATION_GAZEBO:
    case LOCATION_TREE_OF_KNOWLEDGE:
    case LOCATION_WITCH_HUT:
      trackNum = 37;
      break;
    case LOCATION_ANCIENT_LAMP:
    case LOCATION_SPHINX:
      trackNum = 33;
      break;
    case LOCATION_GRAVEYARD:
    case LOCATION_SHIPWRECK:
    case LOCATION_ABANDONED_MINE:
    case LOCATION_MAGELLANS_MAPS:
    case LOCATION_DERELICT_SHIP:
    case LOCATION_OBSERVATION_TOWER:
      trackNum = 39;
      break;
    case LOCATION_DRAGON_CITY:
    case LOCATION_PYRAMID:
    case LOCATION_CITY_OF_DEAD:
    case LOCATION_TROLL_BRIDGE:
      trackNum = 31;
      break;
    case LOCATION_OBELISK:
      trackNum = 22;
      break;
    case LOCATION_FORT:
    case LOCATION_STANDING_STONES:
    case LOCATION_WITCH_DOCTORS_HUT:
    case LOCATION_MERCENARY_CAMP:
      trackNum = 38;
      break;
    case LOCATION_DESRT_TENT:
    case LOCATION_HILL_FORT:
      trackNum = 34;
      break;
    case LOCATION_STONE_LITHS:
      trackNum = 1;
      break;
    case LOCATION_WAGON_CAMP:
    case LOCATION_TREE_CITY:
    case LOCATION_MAGIC_GARDEN:
      trackNum = 35;
      break;
    case LOCATION_BARRIER:
      trackNum = 22;
      break;
    case LOCATION_TRAVELLER_TENT:
      trackNum = 22;
      break;
    case LOCATION_ALCHEMIST_TOWER:
      switch ( a2 )
      {
        case 0:
          trackNum = 22;
          break;
        case 1:
          trackNum = 22;
          break;
        case 5:
          trackNum = 101;
          break;
        case 2:
          trackNum = 22;
          break;
        case 6:
          trackNum = 22;
          break;
        case 4:
          trackNum = 22;
          break;
        case 3:
          goto LABEL_36;
      }
      break;
    case LOCATION_EXPANSION_DWELLING:
      trackNum = 22;
      break;
    case LOCATION_JAIL:
      trackNum = 22;
      break;
    default:
      trackNum = -1;
      break;
  }
LABEL_36:
  if ( trackNum != -1 )
  {
    switch ( trackNum )
    {
      case 19:
        strcpy(&file, "treasure.82m");
        break;
      case 22:
        strcpy(&file, "expernce.82m");
        break;
      case 100:
        strcpy(&file, "goodmrle.82m");
        break;
      case 101:
        strcpy(&file, "goodluck.82m");
        break;
      case 102:
        strcpy(&file, "pickup01.82m");
        break;
      case 103:
        strcpy(&file, "h2mine.82m");
        break;
      default:
        SoundManager::couldBePlayCDTrack(soundManager, trackNum);
        break;
    }
    if ( strlen(&file) > 1 )
      *res = playSample(&file);
  }
}

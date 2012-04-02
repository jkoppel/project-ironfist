void __thiscall GameInfo::randomlyFillGarrisonSlot(GameInfo *this, int castleIdx)
{
  int randomQuantity; // [sp+18h] [bp-14h]@7
  int quantity; // [sp+18h] [bp-14h]@15
  signed int factionOffset; // [sp+1Ch] [bp-10h]@7
  int creatureType; // [sp+24h] [bp-8h]@0
  int v7; // [sp+28h] [bp-4h]@4

  if ( (this->castles[castleIdx].field_4 > 0 || this->castles[castleIdx].field_5 > 0)
    && this->castles[castleIdx].ownerIdx < 0 )
  {
    v7 = unseededNextRand(1, 15);
    if ( dword_532C54 / 10 )
      v7 += unseededNextRand(0, dword_532C54 / 10);
    if ( v7 > 5 )
    {
      if ( v7 > 10 )
      {
        if ( v7 > 13 )
        {
          if ( v7 > 15 )
          {
            factionOffset = 50;
            randomQuantity = 1;
          }
          else
          {
            factionOffset = 40;
            randomQuantity = unseededNextRand(1, 3);
          }
        }
        else
        {
          factionOffset = 30;
          randomQuantity = unseededNextRand(3, 5);
        }
      }
      else
      {
        factionOffset = 20;
        randomQuantity = unseededNextRand(5, 7);
      }
    }
    else
    {
      factionOffset = 10;
      randomQuantity = unseededNextRand(8, 15);
    }
    quantity = dword_532C54 / 20 + randomQuantity;
    switch ( factionOffset + this->castles[castleIdx].factionID )
    {
      case 10:
        creatureType = CREATURE_PEASENT;
        break;
      case 20:
        creatureType = CREATURE_ARCHER;
        break;
      case 30:
        creatureType = CREATURE_PIKEMAN;
        break;
      case 40:
        creatureType = CREATURE_SWORDSMAN;
        break;
      case 50:
        creatureType = CREATURE_CAVALRY;
        break;
      case 11:
        creatureType = CREATURE_GOBLIN;
        break;
      case 21:
        creatureType = CREATURE_ORC;
        break;
      case 31:
        creatureType = CREATURE_WOLF;
        break;
      case 41:
        creatureType = CREATURE_OGRE;
        break;
      case 51:
        creatureType = CREATURE_TROLL;
        break;
      case 12:
        creatureType = CREATURE_SPRITE;
        break;
      case 22:
        creatureType = CREATURE_DWARF;
        break;
      case 32:
        creatureType = CREATURE_ELF;
        break;
      case 42:
        creatureType = CREATURE_DRUID;
        break;
      case 52:
        creatureType = CREATURE_UNICORN;
        break;
      case 13:
        creatureType = CREATURE_CENTAUR;
        break;
      case 23:
        creatureType = CREATURE_GARGOYLE;
        break;
      case 33:
        creatureType = CREATURE_GRIFFIN;
        break;
      case 43:
        creatureType = CREATURE_MINOTAUR;
        break;
      case 53:
        creatureType = CREATURE_HYDRA;
        break;
      case 14:
        creatureType = CREATURE_HALFLING;
        break;
      case 24:
        creatureType = CREATURE_BOAR;
        break;
      case 34:
        creatureType = CREATURE_IRON_GOLEM;
        break;
      case 44:
        creatureType = CREATURE_ROC;
        break;
      case 54:
        creatureType = CREATURE_MAGE;
        break;
      case 15:
        creatureType = CREATURE_SKELETON;
        break;
      case 25:
        creatureType = CREATURE_ZOMBIE;
        break;
      case 35:
        creatureType = CREATURE_MUMMY;
        break;
      case 45:
        creatureType = CREATURE_VAMPIRE;
        break;
      case 55:
        creatureType = CREATURE_LICH;
        break;
      case 16:
      case 17:
      case 18:
      case 19:
      case 26:
      case 27:
      case 28:
      case 29:
      case 36:
      case 37:
      case 38:
      case 39:
      case 46:
      case 47:
      case 48:
      case 49:
        break;
    }
    addCreaturesToArmy(&this->castles[castleIdx].garrison, creatureType, quantity, -1);
  }
}

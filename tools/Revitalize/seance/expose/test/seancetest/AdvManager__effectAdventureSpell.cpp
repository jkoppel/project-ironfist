void __fastcall AdvManager::effectAdventureSpell(AdvManager *this, int a2, int spell)
{
  MapTile *tile; // [sp+14h] [bp-14h]@10
  signed int v5; // [sp+18h] [bp-10h]@12
  Hero *hero; // [sp+20h] [bp-8h]@2
  char v7; // [sp+24h] [bp-4h]@5

  if ( curPlayer->_1[0] == -1 )
    hero = 0;
  else
    hero = &gameObject->heroes[curPlayer->_1[0]];
  switch ( spell )
  {
    case SPELL_SET_EARTH_GUARDIAN:
      v7 = 62;
      goto LABEL_10;
    case SPELL_SET_AIR_GUARDIAN:
      v7 = 63;
      goto LABEL_10;
    case SPELL_SET_FIRE_GUARDIAN:
      v7 = 64;
      goto LABEL_10;
    case SPELL_SET_WATER_GUARDIAN:
      v7 = 65;
      goto LABEL_10;
    case SPELL_HAUNT:
      v7 = 59;
LABEL_10:
      tile = AdvManager::getTile(advManager, hero->x, hero->y);
      if ( tile->objType != 151 )
      {
        display_message_window(
          "You must be standing on the entrance to a mine (sawmills and alchemists don't count) to cast this spell.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
        return;
      }
      gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(tile->flags >> 8) >> -5) + 3] = v7;
      v5 = Hero::getPrimarySkill(hero, PRIMARY_SKILL_SPELLPOWER);
      if ( v5 > 51 )
        LOBYTE(v5) = 51;
      gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(tile->flags >> 8) >> -5) + 4] = 4 * v5;
      if ( spell == 60 )
        sub_4212E0(gameObject, (unsigned __int8)((unsigned __int8)(tile->flags >> 8) >> -5), -1);
      goto LABEL_32;
    case SPELL_VIEW_MINES:
    case SPELL_VIEW_RESOURCES:
    case SPELL_VIEW_ARTIFACTS:
    case SPELL_VIEW_TOWNS:
    case SPELL_VIEW_HEROES:
    case SPELL_VIEW_ALL:
      sub_498F20(this, a2, spell, spell == 53, spell == 53);
      goto LABEL_32;
    case SPELL_IDENTIFY:
      this->identifyCast = 1;
      display_message_window("Enemy heroes are now fully identifiable.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      goto LABEL_32;
    case SPELL_SUMMON_BOAT:
      AdvManager::summonBoat(this);
      goto LABEL_32;
    case SPELL_DIMENSION_DOOR:
    case SPELL_TOWN_GATE:
    case SPELL_TOWN_PORTAL:
      if ( *(_DWORD *)&hero->_4[20] )
      {
        if ( *(_DWORD *)&hero->_4[20] >= 225 )
          *(_DWORD *)&hero->_4[20] -= 225;
        else
          *(_DWORD *)&hero->_4[20] = 0;
        AdvManager::involvesSettingPointBars(this, -1, 1, 1);
        if ( spell == SPELL_DIMENSION_DOOR )
          AdvManager::castDimensionDoor(this);
        else
          AdvManager::castTownTransportSpell(this, spell);
LABEL_32:
        if ( spell != 56 && spell != 57 )
        {
          if ( spell != 58 )
            Hero::spendSpellPointsFor(&gameObject->heroes[curPlayer->_1[0]], spell);
        }
      }
      else
      {
        display_message_window(
          "Your hero is too tired to cast this spell today.  Try again tomorrow.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      }
      return;
    case SPELL_VISIONS:
      if ( AdvManager::castVisions(this, (int)hero) )
        goto LABEL_32;
      return;
    default:
      goto LABEL_32;
  }
}

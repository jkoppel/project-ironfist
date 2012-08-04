{
  int v2; // edx@0
  mapCell *tile; // [sp+14h] [bp-14h]@10
  signed int v5; // [sp+18h] [bp-10h]@12
  hero *hro; // [sp+20h] [bp-8h]@2
  char v7; // [sp+24h] [bp-4h]@5

  if ( gpCurPlayer->curHeroIdx == -1 )
    hro = 0;
  else
    hro = &gpGame->heroes[gpCurPlayer->curHeroIdx];
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
      tile = advManager::GetCell(gpAdvManager, hro->x, hro->y);
      if ( tile->objType != 151 )
      {
        NormalDialog(
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
      gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(tile->flags >> 8) >> -5) + 3] = v7;
      v5 = hero::Stats(hro, PRIMARY_SKILL_SPELLPOWER);
      if ( v5 > 51 )
        LOBYTE(v5) = 51;
      gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(tile->flags >> 8) >> -5) + 4] = 4 * v5;
      if ( spell == 60 )
        game::ClaimMine(gpGame, (unsigned __int8)((unsigned __int8)(tile->flags >> 8) >> -5), -1);
      goto LABEL_32;
    case SPELL_VIEW_MINES:
    case SPELL_VIEW_RESOURCES:
    case SPELL_VIEW_ARTIFACTS:
    case SPELL_VIEW_TOWNS:
    case SPELL_VIEW_HEROES:
    case SPELL_VIEW_ALL:
      advManager::ViewWorld(this, v2, spell, spell == 53, spell == 53);
      goto LABEL_32;
    case SPELL_IDENTIFY:
      this->identifyCast = 1;
      NormalDialog("Enemy heroes are now fully identifiable.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      goto LABEL_32;
    case SPELL_SUMMON_BOAT:
      advManager::SummonBoat(this);
      goto LABEL_32;
    case SPELL_DIMENSION_DOOR:
    case SPELL_TOWN_GATE:
    case SPELL_TOWN_PORTAL:
      if ( *(_DWORD *)&hro->field_35 )
      {
        if ( *(_DWORD *)&hro->field_35 >= 225 )
          *(_DWORD *)&hro->field_35 -= 225;
        else
          *(_DWORD *)&hro->field_35 = 0;
        advManager::UpdateHeroLocator(this, -1, 1, 1);
        if ( spell == SPELL_DIMENSION_DOOR )
          advManager::DimensionDoor(this);
        else
          advManager::TownGate(this, spell);
LABEL_32:
        if ( spell != 56 && spell != 57 )
        {
          if ( spell != 58 )
            hero::UseSpell(&gpGame->heroes[gpCurPlayer->curHeroIdx], spell);
        }
      }
      else
      {
        NormalDialog(
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
      if ( advManager::DoVisions(this, (int)hro) )
        goto LABEL_32;
      return;
    default:
      goto LABEL_32;
  }
}
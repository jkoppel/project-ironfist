{
  signed int result; // eax@12
  combatManager *thisa; // [sp+10h] [bp-8h]@1
  CREATURES elemental_type; // [sp+14h] [bp-4h]@6

  thisa = this;
  thisa->current_spell_id = game::ViewSpells(
                              gpGame,
                              thisa->heroes[giCurGeneral],
                              SPELL_CATEGORY_COMBAT,
                              (int (__fastcall *)(struct tag_message *))CombatSpecialHandler,
                              0);
  if ( thisa->current_spell_id == -1 )
  {
LABEL_29:
    result = 0;
  }
  else
  {
    switch ( thisa->current_spell_id )
    {
      case SPELL_EARTHQUAKE:
        if ( thisa->castles[1] )
          goto LABEL_20;
        NormalDialog(
          "An earthquake will do you no good unless there are town walls to damage.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
        goto LABEL_27;
      case SPELL_SUMMON_EARTH_ELEMENTAL:
        elemental_type = CREATURE_EARTH_ELEMENTAL;
        goto LABEL_10;
      case SPELL_SUMMON_AIR_ELEMENTAL:
        elemental_type = CREATURE_AIR_ELEMENTAL;
        goto LABEL_10;
      case SPELL_SUMMON_FIRE_ELEMENTAL:
        elemental_type = CREATURE_FIRE_ELEMENTAL;
        goto LABEL_10;
      case SPELL_SUMMON_WATER_ELEMENTAL:
        elemental_type = CREATURE_WATER_ELEMENTAL;
LABEL_10:
        if ( thisa->summonedCreatureType[thisa->currentActionSide]
          && thisa->summonedCreatureType[thisa->currentActionSide] != elemental_type )
        {
          NormalDialog("You may only summon one type of elemental per combat.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          return 0;
        }
        if ( thisa->numCreatures[thisa->currentActionSide] >= 20 )
        {
          sprintf(
            gText,
            "You already have %d creatures groups in combat and cannot add any more.",
            thisa->numCreatures[thisa->currentActionSide]);
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          return 0;
        }
        if ( !combatManager::SpaceForElementalExists(thisa) )
        {
          sprintf(gText, "There is no open space adjacent to your hero to summon an Elemental to.");
          NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          return 0;
        }
LABEL_20:
        giNextAction = 1;
        giNextActionExtra = thisa->current_spell_id;
        goto LABEL_27;
      case SPELL_MASS_CURE:
      case SPELL_MASS_HASTE:
      case SPELL_MASS_SLOW:
      case SPELL_MASS_BLESS:
      case SPELL_MASS_CURSE:
      case SPELL_HOLY_WORD:
      case SPELL_HOLY_SHOUT:
      case SPELL_MASS_DISPEL:
      case SPELL_ARMAGEDDON:
      case SPELL_ELEMENTAL_STORM:
      case SPELL_DEATH_RIPPLE:
      case SPELL_DEATH_WAVE:
      case SPELL_MASS_SHIELD:
        if ( combatManager::HasValidSpellTarget(thisa, thisa->current_spell_id) )
          goto LABEL_20;
        NormalDialog("That spell will affect no one!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
        return 0;
      case SPELL_MIRROR_IMAGE:
        if ( thisa->numCreatures[thisa->currentActionSide] < 20 )
          goto LABEL_23;
        sprintf(
          gText,
          "You already have %d creatures groups in combat and cannot add any more.",
          thisa->numCreatures[thisa->currentActionSide]);
        NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        return 0;
      default:
LABEL_23:
        if ( !combatManager::HasValidSpellTarget(thisa, thisa->current_spell_id) )
        {
          NormalDialog("That spell will affect no one!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          return 0;
        }
        giNextAction = 1;
        giNextActionExtra = thisa->current_spell_id;
        mouseManager::SetPointer(gpMouseManager, "spelmous.mse", gsSpellInfo[thisa->current_spell_id].spriteIdx, -999);
        heroWindowManager::DoDialog(gpWindowManager, 0, (int (__fastcall *)(tag_message *))HandleCastSpell, 0);
LABEL_27:
        mouseManager::SetPointer(gpMouseManager, "cmbtmous.mse", 0, -999);
        if ( thisa->current_spell_id == -1 )
          goto LABEL_29;
        result = 1;
        break;
    }
  }
  return result;
}
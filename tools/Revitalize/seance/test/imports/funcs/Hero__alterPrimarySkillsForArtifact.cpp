{
  int newSPMax; // [sp+18h] [bp-18h]@45
  signed int i; // [sp+1Ch] [bp-14h]@41
  int primSkillDiffs[4]; // [sp+20h] [bp-10h]@2

  if ( a2 != -1 )
  {
    primSkillDiffs[0] = 0;
    primSkillDiffs[1] = 0;
    primSkillDiffs[2] = 0;
    primSkillDiffs[3] = 0;
    switch ( a2 )
    {
      case ARTIFACT_ULTIMATE_BOOK_OF_KNOWLEDGE:
        primSkillDiffs[3] = 12;
        break;
      case ARTIFACT_ULTIMATE_SWORD_OF_DOMINION:
        primSkillDiffs[0] = 12;
        break;
      case ARTIFACT_ULTIMATE_CLOAK_OF_PROTECTION:
        primSkillDiffs[1] = 12;
        break;
      case ARTIFACT_ULTIMATE_WAND_OF_MAGIC:
        primSkillDiffs[2] = 12;
        break;
      case ARTIFACT_ULTIMATE_SHIELD:
        primSkillDiffs[0] = 6;
        primSkillDiffs[1] = 6;
        break;
      case ARTIFACT_ULTIMATE_STAFF:
        primSkillDiffs[2] = 6;
        primSkillDiffs[3] = 6;
        break;
      case ARTIFACT_ULTIMATE_CROWN:
        primSkillDiffs[0] = 4;
        primSkillDiffs[1] = 4;
        primSkillDiffs[2] = 4;
        primSkillDiffs[3] = 4;
        break;
      case ARTIFACT_ARCANE_NECKLACE_OF_MAGIC:
        primSkillDiffs[2] = 4;
        break;
      case ARTIFACT_CASTERS_BRACELET_OF_MAGIC:
        primSkillDiffs[2] = 2;
        break;
      case ARTIFACT_MAGES_RING_OF_POWER:
        primSkillDiffs[2] = 2;
        break;
      case ARTIFACT_WITCHS_BROACH_OF_MAGIC:
        primSkillDiffs[2] = 3;
        break;
      case ARTIFACT_THUNDER_MACE_OF_DOMINION:
        primSkillDiffs[0] = 1;
        break;
      case ARTIFACT_ARMORED_GAUNTLETS_OF_PROTECTION:
        primSkillDiffs[1] = 1;
        break;
      case ARTIFACT_DEFENDER_HELM_OF_PROTECTION:
        primSkillDiffs[1] = 1;
        break;
      case ARTIFACT_GIANT_FLAIL_OF_DOMINION:
        primSkillDiffs[0] = 1;
        break;
      case ARTIFACT_STEALTH_SHIELD_OF_PROTECTION:
        primSkillDiffs[1] = 2;
        break;
      case ARTIFACT_DRAGON_SWORD_OF_DOMINION:
        primSkillDiffs[0] = 3;
        break;
      case ARTIFACT_POWER_AXE_OF_DOMINION:
        primSkillDiffs[0] = 2;
        break;
      case ARTIFACT_DIVINE_BREASTPLATE_OF_PROTECTION:
        primSkillDiffs[1] = 3;
        break;
      case ARTIFACT_MINOR_SCROLL_OF_KNOWLEDGE:
        primSkillDiffs[3] = 2;
        break;
      case ARTIFACT_MAJOR_SCROLL_OF_KNOWLEDGE:
        primSkillDiffs[3] = 3;
        break;
      case ARTIFACT_SUPERIOR_SCROLL_OF_KNOWLEDGE:
        primSkillDiffs[3] = 4;
        break;
      case ARTIFACT_FOREMOST_SCROLL_OF_KNOWLEDGE:
        primSkillDiffs[3] = 5;
        break;
      case ARTIFACT_SPIKED_HELM:
        primSkillDiffs[0] = 1;
        primSkillDiffs[1] = 1;
        break;
      case ARTIFACT_SPIKED_SHIELD:
        primSkillDiffs[0] = 2;
        primSkillDiffs[1] = 2;
        break;
      case ARTIFACT_WHITE_PEARL:
        primSkillDiffs[2] = 1;
        primSkillDiffs[3] = 1;
        break;
      case ARTIFACT_BLACK_PEARL:
        primSkillDiffs[2] = 2;
        primSkillDiffs[3] = 2;
        break;
      case ARTIFACT_ARM_OF_THE_MARTYR:
        primSkillDiffs[2] = 3;
        break;
      case ARTIFACT_BREASTPLATE_OF_ANDURAN:
        primSkillDiffs[1] = 5;
        break;
      case ARTIFACT_BROACH_OF_SHIELDING:
        primSkillDiffs[2] = -2;
        break;
      case ARTIFACT_BATTLE_GARB_OF_ANDURAN:
        primSkillDiffs[2] = 5;
        primSkillDiffs[1] = 5;
        primSkillDiffs[0] = 5;
        break;
      case ARTIFACT_HELMET_OF_ANDURAN:
        primSkillDiffs[2] = 5;
        break;
      case ARTIFACT_HOLY_HAMMER:
        primSkillDiffs[0] = 5;
        break;
      case ARTIFACT_LEGENDARY_SCEPTER:
        primSkillDiffs[2] = 2;
        primSkillDiffs[0] = 2;
        primSkillDiffs[1] = 2;
        primSkillDiffs[3] = 2;
        break;
      case ARTIFACT_STAFF_OF_WIZARDRY:
        primSkillDiffs[2] = 5;
        break;
      case ARTIFACT_SWORD_BREAKER:
        primSkillDiffs[1] = 4;
        primSkillDiffs[0] = 1;
        break;
      case ARTIFACT_SWORD_OF_ANDURAN:
        primSkillDiffs[0] = 5;
        break;
      case ARTIFACT_GOLDEN_GOOSE:
      case ARTIFACT_MEDAL_OF_VALOR:
      case ARTIFACT_MEDAL_OF_COURAGE:
      case ARTIFACT_MEDAL_OF_HONOR:
      case ARTIFACT_MEDAL_OF_DISTINCTION:
      case ARTIFACT_FIZBIN_OF_MISFOURTUNE:
      case ARTIFACT_BALLISTA_OF_QUICKNESS:
      case ARTIFACT_ENDLESS_SACK_OF_GOLD:
      case ARTIFACT_ENDLESS_BAG_OF_GOLD:
      case ARTIFACT_ENDLESS_PURSE_OF_GOLD:
      case ARTIFACT_NOMAD_BOOTS_OF_MOBILITY:
      case ARTIFACT_TRAVELERS_BOOTS_OF_MOBILITY:
      case ARTIFACT_LUCKY_RABBITS_FOOT:
      case ARTIFACT_GOLDEN_HORSESHOE:
      case ARTIFACT_GAMBLERS_LUCKY_COIN:
      case ARTIFACT_FOUR_LEAF_CLOVER:
      case ARTIFACT_TRUE_COMPASS_OF_MOBILITY:
      case ARTIFACT_SAILORS_ASTROLABE_OF_MOBILITY:
      case ARTIFACT_EVIL_EYE:
      case ARTIFACT_ENCHANTED_HOURGLASS:
      case ARTIFACT_GOLD_WATCH:
      case ARTIFACT_SKULLCAP:
      case ARTIFACT_ICE_CLOAK:
      case ARTIFACT_FIRE_CLOAK:
      case ARTIFACT_LIGHTNING_HELM:
      case ARTIFACT_EVERCOLD_ICICLE:
      case ARTIFACT_EVERHOT_LAVA_ROCK:
      case ARTIFACT_LIGHTNING_ROD:
      case ARTIFACT_SNAKE_RING:
      case ARTIFACT_ANKH:
      case ARTIFACT_BOOK_OF_ELEMENTS:
      case ARTIFACT_ELEMENTAL_RING:
      case ARTIFACT_HOLY_PENDANT:
      case ARTIFACT_PENDANT_OF_FREE_WILL:
      case ARTIFACT_PENDANT_OF_LIFE:
      case ARTIFACT_SERENITY_PENDANT:
      case ARTIFACT_SEEING_EYE_PENDANT:
      case ARTIFACT_KINETIC_PENDANT:
      case ARTIFACT_PENDANT_OF_DEATH:
      case ARTIFACT_WAND_OF_NEGATION:
      case ARTIFACT_GOLDEN_BOW:
      case ARTIFACT_TELESCOPE:
      case ARTIFACT_STATESMANS_QUILL:
      case ARTIFACT_WIZARDS_HAT:
      case ARTIFACT_POWER_RING:
      case ARTIFACT_AMMO_CART:
      case ARTIFACT_TAX_LIEN:
      case ARTIFACT_HIDEOUS_MASK:
      case ARTIFACT_ENDLESS_POUCH_OF_SULFUR:
      case ARTIFACT_ENDLESS_VIAL_OF_MERCURY:
      case ARTIFACT_ENDLESS_POUCH_OF_GEMS:
      case ARTIFACT_ENDLESS_CORD_OF_WOOD:
      case ARTIFACT_ENDLESS_CART_OF_ORE:
      case ARTIFACT_ENDLESS_POUCH_OF_CRYSTAL:
      case ARTIFACT_MAGIC_BOOK:
      case ARTIFACT_SPELL_SCROLL:
      case ARTIFACT_CRYSTAL_BALL:
      case ARTIFACT_HEART_OF_FIRE:
      case ARTIFACT_HEART_OF_ICE:
      case ARTIFACT_MASTHEAD:
      case ARTIFACT_SPHERE_OF_NEGATION:
      case ARTIFACT_SPADE_OF_NECROMANCY:
      case ARTIFACT_BLACK_PEARL|ARTIFACT_ULTIMATE_CLOAK_OF_PROTECTION:
      case ARTIFACT_MAGIC_BOOK|ARTIFACT_ULTIMATE_CLOAK_OF_PROTECTION:
      case ARTIFACT_BLACK_PEARL|ARTIFACT_ULTIMATE_SHIELD:
      case ARTIFACT_MAGIC_BOOK|ARTIFACT_ULTIMATE_SHIELD:
        break;
    }
    for ( i = 0; i < 4; ++i )
    {
      this->primarySkills[i] += ((unsigned int)(losing - 1) < 1 ? -1 : 1) * LOBYTE(primSkillDiffs[i]);
      if ( i == PRIMARY_SKILL_KNOWLEDGE && losing == 1 )
      {
        newSPMax = 10 * Hero::getPrimarySkill(this, PRIMARY_SKILL_KNOWLEDGE);
        if ( this->spellpoints > newSPMax )
          this->spellpoints = newSPMax;
      }
    }
  }
}

#include "base.h"

#include "spell/spells.h"

#include "adventure/adv.h"
#include "adventure/terrain.h"
#include "game/game.h"
#include "gui/dialog.h"
#include "scripting/callback.h"
#include "sound/sound.h"

char *gSpellDesc[] =
{
  "{Fireball}\n\nCauses a giant fireball to strike the selected area, damaging all nearby creatures.",
  "{Fireblast}\n\nAn improved version of fireball, fireblast affects two hexes around the center point of the spell, rather than one.",
  "{Lightning Bolt}\n\nCauses a bolt of electrical energy to strike the selected creature.",
  "{Chain Lightning}\n\nCauses a bolt of electrical energy to strike a selected creature, then strike the nearest creature with half damage, then strike the NEXT nearest creature with half again damage, and so on, until it becomes too weak to be harmful.  Warning:  This spell can hit your own creatures!",
  "{Teleport}\n\nTeleports the creature you select to any open position on the battlefield.",
  "{Cure}\n\nRemoves all negative spells cast upon one of your units, and restores up to 5 HP per level of spell power.",
  "{Mass Cure}\n\nRemoves all negative spells cast upon your forces, and restores up to 5 HP per level of spell power, per creature.",
  "{Resurrect}\n\nResurrects creatures from a damaged or dead unit until end of combat.",
  "{Resurrect True}\n\nResurrects creatures from a damaged or dead unit permanently.",
  "{Haste}\n\nIncreases the speed of any creature by two.",
  "{Mass Haste}\n\nIncreases the speed of all of your creatures by two.",
  "{Slow}\n\nSlows target to half movement rate.",
  "{Mass Slow}\n\nSlows all enemies to half movement rate.",
  "{Blind }\n\nClouds the affected creatures' eyes, preventing them from moving.",
  "{Bless}\n\nCauses the selected creatures to inflict maximum damage.",
  "{Mass Bless}\n\nCauses all of your units to inflict maximum damage.",
  "{Stoneskin}\n\nMagically increases the defense skill of the selected creatures.",
  "{Steelskin}\n\nIncreases the defense skill of the targeted creatures.  This is an improved version of Stoneskin.",
  "{Curse}\n\nCauses the selected creatures to inflict minimum damage.",
  "{Mass Curse}\n\nCauses all enemy troops to inflict minimum damage.",
  "{Holy Word}\n\nDamages all undead in the battle.",
  "{Holy Shout}\n\nDamages all undead in the battle.  This is an improved version of Holy Word.",
  "{Anti-Magic}\n\nPrevents harmful magic against the selected creatures.",
  "{Dispel Magic}\n\nRemoves all magic spells from a single target.",
  "{Mass Dispel}\n\nRemoves all magic spells from all creatures.",
  "{Magic Arrow}\n\nCauses a magic arrow to strike the selected target.",
  "{Berzerker}\n\nCauses a creature to attack its nearest neighbor.",
  "{Armageddon}\n\nHoly terror strikes the battlefield, causing severe damage to all creatures.",
  "{Elemental Storm}\n\nMagical elements pour down on the battlefield, damaging all creatures.",
  "{Meteor Shower}\n\nA rain of rocks strikes an area of the battlefield, damaging all nearby creatures.",
  "{Paralyze}\n\nThe targeted creatures are paralyzed, unable to move or retaliate.",
  "{Hypnotize}\n\nBrings a single enemy unit under your control for one combat round if its hits are less than 25 times the caster's spell power.",
  "{Cold Ray}\n\nDrains body heat from a single enemy unit.",
  "{Cold Ring}\n\nDrains body heat from all units surrounding the center point, but not including the center point.",
  "{Disrupting Ray}\n\nReduces the defense rating of an enemy unit by three.",
  "{Death Ripple}\n\nDamages all living (non-undead) units in the battle.",
  "{Death Wave}\n\nDamages all living (non-undead) units in the battle.  This spell is an improved version of Death Ripple.",
  "{Dragon Slayer}\n\nGreatly increases a unit's attack skill vs. Dragons.",
  "{Blood Lust}\n\nIncreases a unit's attack skill.",
  "{Animate Dead}\n\n'Resurrects' creatures from a damaged or dead undead unit permanently.",
  "{Mirror Image}\n\nCreates an illusionary unit that duplicates one of your existing units.  This illusionary unit does the same damages as the original, but will vanish if it takes any damage.",
  "{Shield}\n\nHalves damage received from ranged attacks for a single unit.",
  "{Mass Shield}\n\nHalves damage received from ranged attacks for all of your units.",
  "{Summon Earth Elemental}\n\nSummons Earth Elementals to fight for your army.",
  "{Summon Air Elemental}\n\nSummons Air Elementals to fight for your army.",
  "{Summon Fire Elemental}\n\nSummons Fire Elementals to fight for your army.",
  "{Summon Water Elemental}\n\nSummons Water Elementals to fight for your army.",
  "{Earthquake}\n\nDamages castle walls.",
  "{View Mines}\n\nCauses all mines across the land to become visible.",
  "{View Resources}\n\nCauses all resources across the land to become visible.",
  "{View Artifacts}\n\nCauses all artifacts across the land to become visible.",
  "{View Towns}\n\nCauses all towns and castles across the land to become visible.",
  "{View Heroes}\n\nCauses all Heroes across the land to become visible.",
  "{View All}\n\nCauses the entire land to become visible.",
  "{Identify Hero}\n\nAllows the caster to view detailed information on enemy Heroes.",
  "{Summon Boat}\n\nSummons the nearest unoccupied, friendly boat to an adjacent shore location.  A friendly boat is one which you just built or were the most recent player to occupy.",
  "{Dimension Door}\n\nAllows the caster to magically transport to a nearby location.",
  "{Town Gate}\n\nReturns the caster to any town or castle currently owned.",
  "{Town Portal}\n\nReturns the hero to the town or castle of choice, provided it is controlled by you.",
  "{Visions}\n\n Visions predicts the likely outcome of an encounter with a neutral army camp.",
  "{Haunt}\n\nHaunts a mine you control with Ghosts.  This mine stops producing resources.  (If I can't keep it, nobody will!)",
  "{Set Earth Guardian}\n\nSets Earth Elementals to guard a mine against enemy armies.",
  "{Set Air Guardian}\n\nSets Air Elementals to guard a mine against enemy armies.",
  "{Set Fire Guardian}\n\nSets Fire Elementals to guard a mine against enemy armies.",
  "{Set Water Guardian}\n\nSets Water Elementals to guard a mine against enemy armies.",
  "{Awareness}\n\nExplores a large area around your hero.",
  "{Shadow Mark}\n\nMarked creature receives 150% damage from your troops for 1 turn",
  "{Marksman Pierce}\n\nTarget creature receives 1000 damage and is dazed for 1 turn",
  "{Plasma Cone}\n\nCreates a cone of hot plasma in the direction of the target",
  "{Force Shield}\n\nCreates a kinetic shield over the target ally",
  "{Mass Force Shield}\n\nCreates a kinetic shield over all allies",
  "{Fire Bomb}\n\nSet an area on fire for 2 turns. Creatures will continue burning for 2 turns after leaving the area",
  "{Implosion Grenade}\n\nFires an indirect projectile that explodes inverted dark matter that will suck any creature adjacent to it together."
};

SSpellInfo gsSpellInfo[] = {
	{"fireball", 3, 8, 0, 500, 9, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"fireball", 4, 9, 0, 750, 15, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"lightblt", 2, 4, 15, 450, 7, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"chainlte", 4, 5, 15, 650, 15, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"telptout", 3, 10, 0, 30, 9, 10, 0x0A0A0A0A, 0x0A, ATTR_COMBAT_SPELL},
	{"cure", 1, 6, 1, 250, 6, 10, 0x0A0A0A0A, 0x0A, ATTR_COMBAT_SPELL},
	{"masscure", 4, 6, 1, 700, 15, 10, 0x0A0A0A0A, 0x0A, ATTR_COMBAT_SPELL},
	{"resurect", 4, 13, 1, 400, 12, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"resurtru", 5, 12, 1, 550, 15, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"haste", 1, 14, 24, 300, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"masshast", 3, 14, 24, 950, 10, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"slow", 1, 1, 2, 350, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"massslow", 4, 1, 2, 1000, 15, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"blind", 2, 21, 28, 500, 6, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"bless", 1, 7, 21, 200, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"massbles", 3, 7, 21, 650, 12, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"stonskin", 1, 31, 30, 300, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"stelskin", 2, 30, 31, 575, 6, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"curse", 1, 3, 29, 200, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"masscurs", 3, 3, 29, 500, 12, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"masscurs", 3, 22, 8, 300, 9, 10, 0x0A0A0A0A, 0, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"masscurs", 4, 23, 8, 450, 12, 10, 0x0A0A0A0A, 0, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"antimagk", 3, 17, 6, 100, 7, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"dipmagk", 1, 18, 7, 275, 5, 10, 0x0A0A0A0A, 0x0A, ATTR_COMBAT_SPELL},
	{"dipmagk", 3, 18, 7, 450, 12, 10, 0x0A0A0A0A, 0x0A,ATTR_COMBAT_SPELL},
	{"magcarow", 1, 38, 0, 200, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"berzerk", 4, 19, 22, 1000, 12, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"armgedn", 5, 16, 0, 2000, 20, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"storm", 4, 11, 0, 1300, 15, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"meteor~1", 4, 24, 0, 1000, 15, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"paralize", 3, 20, 25, 700, 9, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"hypnotiz", 5, 37, 26, 1300, 15, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"coldray", 2, 36, 19, 375, 6, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"coldring", 3, 35, 0, 500, 9, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"disruptr", 2, 34, 0, 500, 7, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"mnrdeath", 2, 29, 13, 300, 6, 0, 0, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"mnrdeath", 3, 28, 13, 450, 10, 0, 0, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"drgnslay", 2, 32, 27, 100, 6, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"bloodlus", 1, 27, 0, 300, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"resurect", 3, 25, 6, 400, 10, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"mirrorim", 5, 26, 0, 800, 25, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"shield", 1, 15, 23, 150, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"shield", 4, 15, 23, 375, 7, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
	{"sumnelm", 5, 56, 0, 1000, 30, 0, 0, 0, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"sumnelm", 5, 57, 0, 1000, 30, 0, 0, 0, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"sumnelm", 5, 58, 0, 1000, 30, 0, 0, 0, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"sumnelm", 5, 59, 0, 1000, 30, 0, 0, 0, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"erthquak", 3, 33, 0, 300, 15, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
	{"", 1, 39, 0, 30, 1, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
	{"", 1, 40, 0, 30, 1, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
	{"", 2, 41, 0, 30, 2, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
	{"", 3, 42, 0, 30, 2, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
	{"", 3, 43, 0, 30, 2, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
	{"", 4, 44, 0, 30, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
	{"", 3, 45, 0, 30, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
	{"", 2, 46, 0, 30, 5, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
	{"", 5, 47, 0, 1500, 10, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
	{"", 4, 48, 0, 30, 10, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
	{"", 5, 49, 0, 30, 20, 0, 0, 0, ATTR_ADVENTURE_SPELL},
	{"", 2, 50, 0, 30, 6, 0, 0, 0, ATTR_ADVENTURE_SPELL},
	{"", 2, 51, 0, 30, 8, 0, 0, 0, ATTR_ADVENTURE_SPELL},
	{"", 4, 52, 0, 700, 15, 0, 0, 0, ATTR_ADVENTURE_SPELL},
	{"", 4, 53, 0, 700, 15, 0, 0, 0, ATTR_ADVENTURE_SPELL},
	{"", 4, 54, 0, 700, 15, 0, 0, 0, ATTR_ADVENTURE_SPELL},
	{"", 4, 55, 0, 700, 15, 0, 0, 0, ATTR_ADVENTURE_SPELL},

	//awareness
	{"", 1, 55, 0, 700, 20, 10, 0x0A0A0A0A, 0x0A, ATTR_ADVENTURE_SPELL},
  //shadow mark
  {"shdwmark", 2, 66, 33, 0, 3, -1, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
  {"mrksmprc", 5, 67, 34, 200, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL | ATTR_DURATIONED_SPELL},
  {"plsmcone", 5, 68, 35, 50, 3, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
  {"forcshld", 2, 69, 36, 500, 7, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
  {"forcshld", 2, 70, 36, 500, 7, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
  {"firebomb", 3, 71, 37, 500, 9, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL},
  {"implgrnd", 3, 72, 38, 500, 9, 10, 0x0A0A0A0A, 0x0A, ATTR_COMMON_SPELL | ATTR_COMBAT_SPELL}
};

#define DD_MOVEMENT_COST 225

int __fastcall GetManaCost(int spell, hero* hro) {
  int cost = GetManaCost_orig(spell, hro);
  auto res = ScriptCallbackResult<int>("OnCalcManaCost", deepbind<hero*>(hro), spell, cost);
  if(res.has_value())
    cost = res.value();
  return cost;
}

int GetManaCost(int spell) {
	return GetManaCost(spell, NULL);
}

void advManager::CastSpell(int spell) {
	if(gpCurPlayer->curHeroIdx == -1)
		return;

	hero* hro = GetCurrentHero();
	switch(spell) {
    case SPELL_DIMENSION_DOOR:
        // CastSpell_orig would always subtract movement points even if it fails
        this->UpdateHeroLocator(-1, 1, 1);
        this->DimensionDoor();
        break;
	case SPELL_AWARENESS:
		gpGame->SetVisibility(hro->x, hro->y, giCurPlayer, 15);
		hro->UseSpell(spell);
		RedrawAdvScreen(1,0);
		break;
	default:
		this->CastSpell_orig(spell);
		break;
	}
}

extern int __fastcall DimensionDoorHandler(tag_message&);

void advManager::DimensionDoor() {
  heroWindow *window = new heroWindow(0, 0, "dimdoor.bin");
  if (window == NULL) {
    MemError();
  }

  hero *hro = &gpGame->heroes[gpCurPlayer->curHeroIdx];

  if (hro->remainingMobility <= 0) {
      H2MessageBox("Your hero is too tired to cast this spell today.  Try again tomorrow.");
      return;
  }

  gpWindowManager->DoDialog(window, DimensionDoorHandler, 0);
  delete window;

  if (gpWindowManager->buttonPressedCode != 1) {
	  this->UpdateRadar(1, 0);
	  return;
  }

  int x = this->viewX + this->xOff;
  int y = this->viewY + this->yOff;
  mapCell *targetCell = this->GetCell(x, y);
  
  bool waterJump = (hro->flags & HERO_AT_SEA) && giGroundToTerrain[targetCell->groundIndex] == TERRAIN_IDX_WATER;
  bool landJump = !(hro->flags & HERO_AT_SEA) && giGroundToTerrain[targetCell->groundIndex] != TERRAIN_IDX_WATER;
  if (waterJump || landJump) {
	gpSoundManager->SwitchAmbientMusic(1);
    this->TeleportTo(hro, x, y, 0, 0);
    gpSoundManager->SwitchAmbientMusic(giTerrainToMusicTrack[this->currentTerrain]);
	
    gpGame->heroes[gpCurPlayer->curHeroIdx].UseSpell(SPELL_DIMENSION_DOOR);
    hro->remainingMobility = max(hro->remainingMobility - DD_MOVEMENT_COST, 0);
  } else {
   H2MessageBox("Dimension Door failed!!!");
   this->UpdateRadar(1, 0);
  }
}
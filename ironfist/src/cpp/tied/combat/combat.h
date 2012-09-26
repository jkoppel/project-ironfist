#ifndef TIED_COMBAT_MANAGER_H
#define TIED_COMBAT_MANAGER_H

#include "tied/gui/gui.h"
#include "tied/graphics.h"
#include "tied/manager.h"
#include "tied/adventure/adv.h"
#include "tied/game/game.h"
#include "tied/resource/resources.h"

#include "tied/combat/creatures.h"

#pragma pack(push, 1)

struct SMonFrameInfo {
	char _[821];
};

class hexcell {
public:
  __int16 centerX;
  __int16 occupyingCreatureBottomY;
  __int16 leftX;
  __int16 topY;
  __int16 rightX;
  __int16 otherY1;
  __int16 otherY2;
  char isBlocked;
  char combatObjIdx;
  char unitOwner;
  signed __int8 stackIdx;
  char isOccupierNonPrimaryHex;
  int numCorpses;
  char corpseOwners[14];
  char corpseStackIndices[14];
  char field_33[14];
  char field_41;
  H2RECT drawingBounds;
  char field_52[16];
};


class army
{
public:
  char mightBeIsAttacking;
  char animatingRangedAttack;
  char mightBeAttackAnimIdx;
  char field_3;
  char field_4;
  char field_5;
  int field_6;
  H2RECT stackSizeDispBounds;
  H2RECT field_1A;
  H2RECT bounds;
  H2RECT effectAnimationBounds;
  int field_4A;
  float field_4E;
  int targetOwner;
  int targetStackIdx;
  int targetNeighborIdx;
  int field_5E;
  int targetHex;
  int probablyIsNeedDrawSpellEffect;
  int mirroredIdx;
  int mirrorIdx;
  int lifespan;
  int creatureIdx;
  int occupiedHex;
  int animationType;
  int animationFrame;
  int facingRight;
  int field_8A;
  int field_8E;
  int initialQuantity;
  int quantity;
  unsigned int previousQuantity;
  int temporaryQty;
  int damage;
  int armyIdx;
  int otherBadLuckThing;
  int speed;
  int field_B2;
  int luckStatus;
  tag_monsterInfo creature;
  __int16 field_D4;
  int damageTakenDuringSomeTimePeriod;
  int hasTakenLosses;
  int dead;
  int spellEnemyCreatureAbilityIsCasting;
  int owningSide;
  int stackIdx;
  int baseFidgetTime;
  int morale;
  int luck;
  int field_FA;
  int yDrawOffset;
  int xDrawOffset;
  int numActiveEffects;
  char effectStrengths[19];
  int field_11D;
  int hitByHydraAttack;
  void *field_125;
  SMonFrameInfo frameInfo;
  icon *creatureIcon;
  icon *missileIcon;
  sample *combatSounds[7];
  
  int FlyTo(int hex);
  int ValidFlight(int hex, int);
  int WalkTo(int hex);
  void MoveTo(int hex);

  void MoveAttack(int targHex, int);
  void MoveAttack_orig(int targHex, int);
};

class combatManager : public baseManager
{
public:
  palette *palette;
  char _1[768];
  char combatMessageRow1[120];
  char combatMessageRow2[120];
  char field_42A[117];
  char field_49F[117];
  hexcell combatGrid[117];
  int terrainType;
  int combatFieldFringeID;
  int field_31E6;
  int field_31EA;
  int field_31EE;
  int combatFieldCoverID;
  icon *combatScreenIcons[15];
  icon *combatObjIcons[8];
  int numCombatObjs;
  __int16 eagleEyeSpellLearned[2];
  int drawBridgePosition;
  int hasMoat;
  char turretStatus[4];
  char wallStatus[4];
  char ballistaDestroyed;
  bitmap *couldBeBitmapForFieldItself;
  bitmap *probablyBitmapForCombatScreen;
  bitmap *bitmap1;
  int zeroedAfterAnimatingDeathAndHolySpells;
  int field_327B;
  town *castles[2];
  hero *heroes[2];
  hero captains;
  int heroSpellpowers[2];
  armyGroup *armies[2];
  int shadedHex;
  char field_339D[2];
  char field_339F[2];
  char field_33A1;
  char field_33A2;
  char field_33A3[2];
  int heroIconIdxRelated[2];
  int countRelatedToSpellAnimation[2];
  int heroType[2];
  int field_33BD[2];
  icon *heroIcon[2];
  icon *heroFlagIcon[2];
  int heroFlagIconIdx[2];
  H2RECT heroBounds[2];
  H2RECT heroFlagBounds[2];
  H2RECT moatPartBounds[9];
  int otherCombatMessageRelatedTime;
  int combatMessageRelatedTime;
  int couldBeShouldResetCombatMessage;
  char _7[100];
  char summonedCreatureType[2];
  int field_351F[2];
  int involvedInBadMorale[2];
  int playerID[2];
  int experienceForDefeating[2];
  int field_353F;
  int field_3543;
  int numCreatures[2];
  army creatures[2][21];
  int otherCurrentSideThing;
  int someSortOfStackIdx;
  int field_F2AB;
  int currentActionSide;
  int field_F2B3;
  int field_F2B7;
  int field_F2BB;
  int field_F2BF;
  int field_F2C3;
  int field_F2C7;
  int field_F2CB;
  int field_F2CF;
  H2RECT catapultBounds;
  H2RECT ballistaBounds;
  H2RECT drawbridgeBounds;
  H2RECT field_F303;
  int probablyCatapultImgIdx[2];
  char _11[8];
  int timesCatapultMustFire[2];
  int timesGarrisonMustFire[2];
  int isCastleBattle;
  char _12[20];
  int zeroedInHandleCatapult1;
  int zeroedInHandleCatapult2;
  float field_F353;
  int field_F357;
  int field_F35B;
  float ghostAndVampireAbilityStrength[2];
  heroWindow *window;
  int field_F36B;
  int field_F36F;
  int field_F373;
  int field_F377[2];
  signed int stuffHappenedToCreature[2][20];
  int field_F41F;
  int field_F423;
  int field_F427[2];
  int field_F42F;
  char _14[160];
  int sideCasualtiesTitleTextWidget[2];
  textWidget *battlefieldCasualtiesTextWidget;
  char _15[116];
  int field_F553;
  int field_F557;
  char _16[28];
  char shouldVanish[2][20];
  char anyStacksShouldVanish;
  char combatBackgroundFilename[13];
  char hexNeighbors[117][6];
  heroWindow *combatEndWindow;
  int current_spell_id;
  int winningSide;

  combatManager();
  void InitNonVisualVars();
  void InitNonVisualVars_orig();

  void HandlePandoraBox(int side);
  void AddArmy(int side, int creat, int qty, int hex, int attrs, int fizzle);
};

extern combatManager* gpCombatManager;

#pragma pack(pop)

#endif
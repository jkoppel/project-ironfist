#ifndef COMBAT_MANAGER_H
#define COMBAT_MANAGER_H

#include <string>
#include <vector>

#include "gui/gui.h"
#include "graphics.h"
#include "manager.h"
#include "adventure/adv.h"
#include "game/game.h"
#include "resource/resources.h"

#include "combat/animation.h"
#include "combat/army.h"
#include "combat/creatures.h"

#define MAX_STACKS 21
#define NUM_HEXES 117

enum BRIDGE_STATUS {
  BRIDGE_OPEN = 0x0,
  BRIDGE_CLOSING_1 = 0x1,
  BRIDGE_CLOSING_2 = 0x2,
  BRIDGE_DESTROYED = 0x3,
  BRIDGE_CLOSED = 0x4,
};

#pragma pack(push, 1)

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
  char stackIdx;
  char occupiersOtherHexIsToLeft;
  int numCorpses;
  char corpseOwners[14];
  char corpseStackIndices[14];
  char corpseOtherHexIsToLeft[14];
  char field_41;
  H2RECT drawingBounds;
  char field_52[16];
};

int __fastcall ValidHex(int);

class combatManager : public baseManager
{
public:
  palette *palette;
  char _1[768];
  char combatMessageRow1[120];
  char combatMessageRow2[120];
  char field_42A[NUM_HEXES];
  char field_49F[NUM_HEXES];
  hexcell combatGrid[NUM_HEXES];
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
  hero captain;
  int heroSpellpowers[2];
  armyGroup *armies[2];
  int shadedHex;
  char field_339D[2];
  char field_339F[2];
  char field_33A1;
  char field_33A2;
  char field_33A3[2];
  int heroAnimationType[2];
  int heroAnimationFrameCount[2];
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
  army creatures[2][MAX_STACKS];
  int otherCurrentSideThing; // activeStackOwner
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
  int limitCreature[2][20];
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
  char hexNeighbors[NUM_HEXES][6];
  heroWindow *combatEndWindow;
  int current_spell_id;
  int winningSide;
 
  combatManager();
  void InitNonVisualVars();
  void InitNonVisualVars_orig();

  void CombatMessage_orig(char *msg, int updateScreen, int keepPrevMessage, int);
  void CombatMessage(char *msg, int updateScreen, int keepPrevMessage, int);
  void CombatMessage(char *msg) { CombatMessage(msg, 1, 1, 0); }

  void UpdateCombatArea();
  void DrawFrame(int redrawAll,int,int,int,int,int,int);

  void HandlePandoraBox(int side);
  void AddArmy(int side, int creat, int qty, int hex, int attrs, int fizzle);

  int FindResurrectArmyIndex(int side, int spell, int hex);
  void Resurrect(int spell, int hex, int spellpower);
  void SummonElemental(int, int);

  void CastSpell(int,int,int,int);

  void ResetLimitCreature();
  void DoBolt(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
  void ClearEffects();
  void PowEffect(int,int,int,int);
  void MakeCreaturesVanish();
  void ArcShot(icon *icn, int fromX, int fromY, int targX, int targY);
  void LowerDoor();
  void TestRaiseDoor();
  int ShotIsThroughWall(int side, signed int occupiedHex, signed int targHex);
  void ModifyDamageForArtifacts(long *, int, hero *, hero *);
  void RippleCreature(int side, int stackIdx, int a4);
  void DoBlast(int hexIdx, int spell);
  void ChainLightning(int targetHex, int power);
  void CastMassSpell(int spell, signed int spellpower);
  void MirrorImage(int hex);
  void SpellMessage(int spell, int hex);
  void ShowSpellMessage(int isCreatureAbility, int spell, army *stack);
  void BloodLustEffect(army *a2, int flagAdditions);
  void TurnToStone(army *stack);
  void Fireball(int hexIdx, int spell);
  void MeteorShower(int);
  void ElementalStorm();
  void Armageddon();
  void Earthquake();
  void DefaultSpell(int hexIdx);
  void ShowSpellCastFailure(army *, int);
  void CheckChangeSelector();
  void ShootMissile(int, int, int, int, float *, icon *);
  int ValidSpellTarget(int spell, int hexIdx);
  void SetupCombat(int arg0, int arg1, hero *h1, armyGroup *a1, town *t, hero *h2, armyGroup *a2, int arg2, int arg3, int arg4);
  void SetupCombat_orig(int arg0, int arg1, hero *h1, armyGroup *a1, town *t, hero *h2, armyGroup *a2, int arg2, int arg3, int arg4);
  void ResetRound_orig();
  void ResetRound();
  int GetGridIndex(int x, int y);
  int GetCommand(int hex);
  void DrawSmallView(int a2, int a3);
  int UpdateGrid(int a, int b);
  void SetupGridForArmy(army *stack);
  void SetupGridForArmy_orig(army *stack);
  void SetCombatDirections(int hexIdx);
  void SetCombatDirections_orig(int hex);
  int ValidHexToStandOn(signed int a2);
};

extern combatManager* gpCombatManager;

extern int gbNoShowCombat;

void __fastcall ModifyFrameInfo(struct SMonFrameInfo *frm, int creature);
bool IsCastleWall(int hexIdx);
bool IsAICombatTurn();
std::vector<COORD> MakeCatapultArc(int numPoints, bool lefttoright, float fromX, float fromY, float targX, float targY);

#pragma pack(pop)

#endif

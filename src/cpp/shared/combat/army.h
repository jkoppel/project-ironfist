#ifndef ARMY_H
#define ARMY_H

#include "combat\/animation.h"
#include "combat/creatures.h"
#include "graphics.h"
#include "resource/resources.h"
#include "spell/spells.h"

#define NUM_SPELL_EFFECTS 19 // don't ever change it for now  

#pragma pack(push, 1)
class army {
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
  char effectStrengths[NUM_SPELL_EFFECTS]; // spell remaining rounds
  int field_11D;
  int hitByHydraAttack;
  void *field_125;
  SMonFrameInfo frameInfo;
  icon *creatureIcon;
  icon *missileIcon;
  sample *combatSounds[7];

  void LoadResources();
  int FlyTo(int hexIdx);
  int ValidFlight(int hex, int);
  int WalkTo(int hex);
  void MoveTo(int hex);

  void MoveAttack(int, int);
  void MoveAttack_orig(int, int);

  int MidX();
  int MidY();
  void DoAttack(int isRetaliation);
  void DoAttack_orig(int isRetaliation);
  void SpecialAttack();
  void SpecialAttack_orig();
  float SpellCastWorkChance(int);
  float SpellCastWorkChance_orig(int);
  void CheckLuck();
  void DamageEnemy(class army *, int *, int *, int, int);
  int SpellCastWorks(int);
  void PowEffect(int, int, int, int);
  void WaitSample(int);
  void CancelSpellType(int);
  int GetAdjacentCellIndex(int, int);
  void ProcessDeath(int a2);
  void DoHydraAttack(int ignored);
  void Walk(signed int dir, int last, int notFirst);
  void DrawToBuffer(int centX, int standingBotY, int a4);
  int Damage(long baseDam, int spell);
  bool IsCloseMove(int toHexIdx);
  void DecrementSpellRounds();
  void CancelIndividualSpell(int effect);
  signed int SetSpellInfluence(int effectType, signed int strength);
  int AddActiveEffect(int effectType, int strength);
  void SpellEffect(int animationIdx, signed int a3, int a4);
  void Cure(int spellpower);
  void DispelGood();
  void InitClean();
  int CanFit(int hex, int mayShiftTwoHexers, int *rearHex);
  int FindPath(int, int, int, int, int);
};

#pragma pack(pop)

#endif
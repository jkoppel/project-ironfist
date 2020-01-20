#ifndef COMBAT_ANIMATION_H
#define COMBAT_ANIMATION_H

#pragma pack(push, 1)

enum ANIMATION_TYPE {
  ANIMATION_TYPE_START_MOVE = 0,
  ANIMATION_TYPE_SUB_START_MOVE = 1,
  ANIMATION_TYPE_MOVE = 2,
  ANIMATION_TYPE_SUB_END_MOVE = 3,
  ANIMATION_TYPE_END_MOVE = 4,
  ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE = 5,
  ANIMATION_TYPE_WALKING = 6,
  ANIMATION_TYPE_STANDING = 7,
  ANIMATION_TYPE_FIDGET_1 = 8,
  ANIMATION_TYPE_FIDGET_2 = 9,
  ANIMATION_TYPE_FIDGET_3 = 10,
  ANIMATION_TYPE_FIDGET_4 = 11,
  ANIMATION_TYPE_FIDGET_5 = 12,
  ANIMATION_TYPE_DYING = 13,
  ANIMATION_TYPE_WINCE = 14,
  ANIMATION_TYPE_WINCE_RETURN = 15,
  ANIMATION_TYPE_MELEE_ATTACK_UPWARDS = 16,
  ANIMATION_TYPE_MELEE_ATTACK_UPWARDS_RETURN = 17,
  ANIMATION_TYPE_TWO_HEX_ATTACK_UPWARDS = 18,
  ANIMATION_TYPE_TWO_HEX_ATTACK_UPWARDS_RETURN = 19,
  ANIMATION_TYPE_MELEE_ATTACK_FORWARDS = 20,
  ANIMATION_TYPE_MELEE_ATTACK_FORWARDS_RETURN = 21,
  ANIMATION_TYPE_TWO_HEX_ATTACK_FORWARDS = 22,
  ANIMATION_TYPE_TWO_HEX_ATTACK_FORWARDS_RETURN = 23,
  ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS = 24,
  ANIMATION_TYPE_MELEE_ATTACK_DOWNWARDS_RETURN = 25,
  ANIMATION_TYPE_TWO_HEX_ATTACK_DOWNWARDS = 26,
  ANIMATION_TYPE_TWO_HEX_ATTACK_DOWNWARDS_RETURN = 27,
  ANIMATION_TYPE_RANGED_ATTACK_UPWARDS = 28,
  ANIMATION_TYPE_RANGED_ATTACK_UPWARDS_RETURN = 29,
  ANIMATION_TYPE_RANGED_ATTACK_FORWARDS = 30,
  ANIMATION_TYPE_RANGED_ATTACK_FORWARDS_RETURN = 31,
  ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS = 32,
  ANIMATION_TYPE_RANGED_ATTACK_DOWNWARDS_RETURN = 33,
};

struct SMonFrameInfo {
  char firstByteIgnored;
  __int16 offsetForBlind[2];
  char startMoveAnimInfoIgnored[16];
  char subStartMoveAnimInfoIgnored[16];
  char mainMoveAnimInfoIgnored[16];
  char subEndMoveAnimInfoIgnored[16];
  char endMoveAnimInfoIgnored[16];
  char fullMoveAnimInfoIgnored[16];
  char moveAnimInfoIgnored[16];
  char numberOfFidgets;
  float fidgetProbabilities[5];
  int fidgetInfoIgnored[5];
  int maxFidgetDelay;
  int stepTime;
  int shootingTime;
  int flightSpeed;
  __int16 projectileStartOffset[3][2];
  char numMissileDirs;
  float projDirAngle[12];
  int stackNumDispXShift[2];
  char animationLengths[34];
  char animationFrameToImgIdx[34][16];
};

enum HERO_ANIMATION_TYPE {
  HERO_STANDING = 0,
  HERO_CAST_MASS = 3,
  HERO_CAST_MASS_RETURN = 4,
  HERO_CAST_FORWARD = 5,
  HERO_CAST_FORWARD_RETURN = 6,
  HERO_CAST_DOWN = 7,
  HERO_CAST_DOWN_RETURN = 8,
  HERO_FIDGET_1 = 9,
  HERO_FIDGET_2 = 10,
  HERO_FIDGET_3 = 11
};

struct SCmbtHero {
  __int16 castXOff;
  __int16 castLowXOff;
  __int16 castYOff;
  __int16 castLowYOff;
  char numFidgets;
  char animationLength[12];
  char frameIndex[12][9];
};

SCmbtHero scmbtHero[];

#pragma pack(pop)

void BuildTeleporterTempWalkSeq(SMonFrameInfo *frm, int last, int notFirst, bool closeMove);
void __fastcall BuildTempWalkSeq(SMonFrameInfo *frm, int last, int notFirst);

#endif
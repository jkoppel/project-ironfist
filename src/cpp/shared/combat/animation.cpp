#include <string.h>
#include "combat/animation.h"

void BuildTeleporterTempWalkSeq(SMonFrameInfo *frm, int last, int notFirst, bool closeMove) {
  frm->animationLengths[ANIMATION_TYPE_WALKING] = 0;
  if (notFirst || !last) {
    if (notFirst) {
      if (frm->animationLengths[ANIMATION_TYPE_SUB_START_MOVE] > 0 && !closeMove) { // middle
        memcpy(
          &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
          frm->animationFrameToImgIdx[ANIMATION_TYPE_SUB_START_MOVE],
          frm->animationLengths[ANIMATION_TYPE_SUB_START_MOVE]);
        memcpy(
          &frm->moveAnimInfoIgnored[frm->animationLengths[6]],
          frm->subStartMoveAnimInfoIgnored,
          frm->animationLengths[ANIMATION_TYPE_SUB_START_MOVE]);
        frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_SUB_START_MOVE];
      }
    } else if (frm->animationLengths[ANIMATION_TYPE_START_MOVE] > 0 && !closeMove) { // first
      memcpy(
        &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->animationFrameToImgIdx,
        frm->animationLengths[ANIMATION_TYPE_START_MOVE]);
      memcpy(
        &frm->moveAnimInfoIgnored[frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->startMoveAnimInfoIgnored,
        frm->animationLengths[ANIMATION_TYPE_START_MOVE]);
      frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_START_MOVE];
    }
    if (frm->animationLengths[ANIMATION_TYPE_MOVE] > 0 && closeMove) { // doesn't matter
      memcpy(
        &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->animationFrameToImgIdx[ANIMATION_TYPE_MOVE],
        frm->animationLengths[ANIMATION_TYPE_MOVE]);
      memcpy(
        &frm->moveAnimInfoIgnored[frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->mainMoveAnimInfoIgnored,
        frm->animationLengths[ANIMATION_TYPE_MOVE]);
      frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_MOVE];
    }
    if (last) { // last
      if (frm->animationLengths[ANIMATION_TYPE_END_MOVE] > 0 && !closeMove) {
        memcpy(
          &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
          frm->animationFrameToImgIdx[ANIMATION_TYPE_END_MOVE],
          frm->animationLengths[ANIMATION_TYPE_END_MOVE]);
        memcpy(
          &frm->moveAnimInfoIgnored[frm->animationLengths[ANIMATION_TYPE_WALKING]],
          frm->endMoveAnimInfoIgnored,
          frm->animationLengths[ANIMATION_TYPE_END_MOVE]);
        frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_END_MOVE];
      }
    } else if (frm->animationLengths[ANIMATION_TYPE_SUB_END_MOVE] > 0) { // middle or first
      memcpy(
        &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->animationFrameToImgIdx[ANIMATION_TYPE_SUB_END_MOVE],
        frm->animationLengths[ANIMATION_TYPE_SUB_END_MOVE]);
      memcpy(
        &frm->moveAnimInfoIgnored[frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->subEndMoveAnimInfoIgnored,
        frm->animationLengths[ANIMATION_TYPE_SUB_END_MOVE]);
      frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_SUB_END_MOVE];
    }
  } else if (frm->animationLengths[ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE] > 0) { // dunno
    memcpy(
      &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
      frm->animationFrameToImgIdx[ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE],
      frm->animationLengths[ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE]);
    memcpy(
      &frm->moveAnimInfoIgnored[frm->animationLengths[ANIMATION_TYPE_WALKING]],
      frm->fullMoveAnimInfoIgnored,
      frm->animationLengths[ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE]);
    frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE];
  }
}

void __fastcall BuildTempWalkSeq(SMonFrameInfo *frm, int last, int notFirst) {
  frm->animationLengths[ANIMATION_TYPE_WALKING] = 0;
  if (notFirst || !last) {
    if (notFirst) {
      if (frm->animationLengths[ANIMATION_TYPE_SUB_START_MOVE] > 0) { // middle
        memcpy(
          &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
          frm->animationFrameToImgIdx[ANIMATION_TYPE_SUB_START_MOVE],
          frm->animationLengths[ANIMATION_TYPE_SUB_START_MOVE]);
        memcpy(
          &frm->moveAnimInfoIgnored[frm->animationLengths[6]],
          frm->subStartMoveAnimInfoIgnored,
          frm->animationLengths[ANIMATION_TYPE_SUB_START_MOVE]);
        frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_SUB_START_MOVE];
      }
    } else if (frm->animationLengths[ANIMATION_TYPE_START_MOVE] > 0) { // first
      memcpy(
        &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->animationFrameToImgIdx,
        frm->animationLengths[ANIMATION_TYPE_START_MOVE]);
      memcpy(
        &frm->moveAnimInfoIgnored[frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->startMoveAnimInfoIgnored,
        frm->animationLengths[ANIMATION_TYPE_START_MOVE]);
      frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_START_MOVE];
    }
    if (frm->animationLengths[ANIMATION_TYPE_MOVE] > 0) { // doesn't matter
      memcpy(
        &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->animationFrameToImgIdx[ANIMATION_TYPE_MOVE],
        frm->animationLengths[ANIMATION_TYPE_MOVE]);
      memcpy(
        &frm->moveAnimInfoIgnored[frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->mainMoveAnimInfoIgnored,
        frm->animationLengths[ANIMATION_TYPE_MOVE]);
      frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_MOVE];
    }
    if (last) { // last
      if (frm->animationLengths[ANIMATION_TYPE_END_MOVE] > 0) {
        memcpy(
          &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
          frm->animationFrameToImgIdx[ANIMATION_TYPE_END_MOVE],
          frm->animationLengths[ANIMATION_TYPE_END_MOVE]);
        memcpy(
          &frm->moveAnimInfoIgnored[frm->animationLengths[ANIMATION_TYPE_WALKING]],
          frm->endMoveAnimInfoIgnored,
          frm->animationLengths[ANIMATION_TYPE_END_MOVE]);
        frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_END_MOVE];
      }
    } else if (frm->animationLengths[ANIMATION_TYPE_SUB_END_MOVE] > 0) { // middle or first
      memcpy(
        &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->animationFrameToImgIdx[ANIMATION_TYPE_SUB_END_MOVE],
        frm->animationLengths[ANIMATION_TYPE_SUB_END_MOVE]);
      memcpy(
        &frm->moveAnimInfoIgnored[frm->animationLengths[ANIMATION_TYPE_WALKING]],
        frm->subEndMoveAnimInfoIgnored,
        frm->animationLengths[ANIMATION_TYPE_SUB_END_MOVE]);
      frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_SUB_END_MOVE];
    }
  } else if (frm->animationLengths[ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE] > 0) { // dunno
    memcpy(
      &frm->animationFrameToImgIdx[ANIMATION_TYPE_WALKING][frm->animationLengths[ANIMATION_TYPE_WALKING]],
      frm->animationFrameToImgIdx[ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE],
      frm->animationLengths[ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE]);
    memcpy(
      &frm->moveAnimInfoIgnored[frm->animationLengths[ANIMATION_TYPE_WALKING]],
      frm->fullMoveAnimInfoIgnored,
      frm->animationLengths[ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE]);
    frm->animationLengths[ANIMATION_TYPE_WALKING] += frm->animationLengths[ANIMATION_TYPE_WHOLE_MOVEMENT_CYCLE];
  }
}

SCmbtHero sCmbtHero[13] = {
	// Knight 
  {
    18,
    8,
    65475,
    65487,
    2,
    { 1, 9, 9, 2, 1, 3, 2, 2, 1, 3, 2, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, 5, 4, 5, 4, 3, 2 },
      { 6, 7, 8, 9, 8, 9, 8, 7, 6 },
      { 10, 11, -1, -1, -1, -1, -1, -1, -1 },
      { 10, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 6, 12, 13, -1, -1, -1, -1, -1, -1 },
      { 12, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 14, -1, -1, -1, -1, -1, -1, -1 },
      { 2, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 15, 16, 17, -1, -1, -1, -1, -1, -1 },
      { 18, 19, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },

	  // Barbarian
  {
    13,
    9,
    65469,
    65480,
    2,
    { 1, 9, 8, 3, 2, 3, 2, 2, 1, 3, 1, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, 5, 4, 5, 4, 3, 2 },
      { 6, 7, 8, 9, 9, 8, 7, 6, -1 },
      { 6, 10, 11, -1, -1, -1, -1, -1, -1 },
      { 10, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 6, 12, 13, -1, -1, -1, -1, -1, -1 },
      { 12, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 6, 14, -1, -1, -1, -1, -1, -1, -1 },
      { 6, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 15, 16, 17, -1, -1, -1, -1, -1, -1 },
      { 18, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },

	  // Sorceress
  {
    19,
    12,
    65474,
    65486,
    2,
    { 1, 9, 5, 3, 2, 3, 2, 2, 1, 3, 1, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, 5, 4, 5, 4, 3, 2 },
      { 6, 7, 8, 7, 6, -1, -1, -1, -1 },
      { 6, 7, 9, -1, -1, -1, -1, -1, -1 },
      { 7, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 6, 10, 11, -1, -1, -1, -1, -1, -1 },
      { 10, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 6, 12, -1, -1, -1, -1, -1, -1, -1 },
      { 6, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 13, 14, 15, -1, -1, -1, -1, -1, -1 },
      { 16, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },

	  // Warlock
  {
    18,
    7,
    65471,
    65486,
    2,
    { 1, 9, 9, 4, 2, 3, 1, 2, 1, 2, 1, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, 5, 4, 5, 4, 3, 2 },
      { 6, 7, 8, 9, 10, 9, 8, 7, 6 },
      { 6, 7, 11, 12, -1, -1, -1, -1, -1 },
      { 11, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 6, 7, 13, -1, -1, -1, -1, -1, -1 },
      { 6, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 6, 14, -1, -1, -1, -1, -1, -1, -1 },
      { 6, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 15, 16, -1, -1, -1, -1, -1, -1, -1 },
      { 6, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },

	  // Wizard
  {
    25,
    22,
    65471,
    65489,
    2,
    { 1, 9, 7, 5, 4, 2, 1, 2, 1, 2, 1, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, 5, 4, 5, 4, 3, 2 },
      { 6, 7, 8, 9, 8, 7, 6, -1, -1 },
      { 6, 10, 11, 12, 13, -1, -1, -1, -1 },
      { 12, 11, 10, 6, -1, -1, -1, -1, -1 },
      { 6, 14, -1, -1, -1, -1, -1, -1, -1 },
      { 6, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 6, 15, -1, -1, -1, -1, -1, -1, -1 },
      { 6, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 16, 17, -1, -1, -1, -1, -1, -1, -1 },
      { 18, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },

	  // Necro
  {
    17,
    10,
    65475,
    65486,
    2,
    { 1, 9, 6, 5, 3, 5, 1, 5, 1, 1, 2, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, 5, 4, 5, 4, 3, 2 },
      { 6, 7, 6, 7, 6, 7, -1, -1, -1 },
      { 7, 8, 9, 10, 11, -1, -1, -1, -1 },
      { 10, 9, 7, -1, -1, -1, -1, -1, -1 },
      { 7, 12, 13, 14, 15, -1, -1, -1, -1 },
      { 7, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 7, 12, 13, 14, 16, -1, -1, -1, -1 },
      { 7, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 17, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 18, 19, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },
  {
    17,
    12,
    65491,
    65505,
    2,
    { 1, 0, 0, 3, 2, 2, 1, 2, 1, 3, 1, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, -1, -1, -1, -1, -1, -1 },
      { 3, 2, -1, -1, -1, -1, -1, -1, -1 },
      { 5, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 5, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 5, 7, -1, -1, -1, -1, -1, -1, -1 },
      { 5, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 8, 9, 8, -1, -1, -1, -1, -1, -1 },
      { 10, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },
  {
    17,
    12,
    65491,
    65505,
    2,
    { 1, 0, 0, 3, 2, 3, 2, 3, 2, 1, 2, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, -1, -1, -1, -1, -1, -1 },
      { 3, 2, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 5, 6, -1, -1, -1, -1, -1, -1 },
      { 5, 2, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 5, 7, -1, -1, -1, -1, -1, -1 },
      { 5, 2, -1, -1, -1, -1, -1, -1, -1 },
      { 8, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 9, 10, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },
  {
    17,
    12,
    65491,
    65505,
    2,
    { 1, 0, 0, 3, 2, 2, 1, 2, 1, 2, 1, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, -1, -1, -1, -1, -1, -1 },
      { 3, 2, -1, -1, -1, -1, -1, -1, -1 },
      { 5, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 5, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 5, 7, -1, -1, -1, -1, -1, -1, -1 },
      { 5, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 8, 9, -1, -1, -1, -1, -1, -1, -1 },
      { 10, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },
  {
    17,
    12,
    65491,
    65505,
    1,
    { 1, 0, 0, 3, 2, 2, 1, 2, 1, 3, 0, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, -1, -1, -1, -1, -1, -1 },
      { 3, 2, -1, -1, -1, -1, -1, -1, -1 },
      { 5, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 5, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 5, 7, -1, -1, -1, -1, -1, -1, -1 },
      { 5, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 8, 9, 10, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },
  {
    17,
    12,
    65491,
    65505,
    2,
    { 1, 0, 0, 3, 2, 2, 1, 2, 1, 1, 2, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, -1, -1, -1, -1, -1, -1 },
      { 3, 2, -1, -1, -1, -1, -1, -1, -1 },
      { 5, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 5, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 5, 7, -1, -1, -1, -1, -1, -1, -1 },
      { 5, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 8, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 9, 10, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },
  {
    17,
    12,
    65491,
    65505,
    2,
    { 1, 0, 0, 3, 2, 2, 1, 2, 1, 1, 2, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 2, 3, 4, -1, -1, -1, -1, -1, -1 },
      { 3, 2, -1, -1, -1, -1, -1, -1, -1 },
      { 5, 6, -1, -1, -1, -1, -1, -1, -1 },
      { 5, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 5, 7, -1, -1, -1, -1, -1, -1, -1 },
      { 5, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 8, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 9, 10, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },

  // Cyborg
  {
    18,
    8,
    -61,
    -49,
    1,
    { 1, 0, 0, 2, 1, 2, 1, 2, 1, 1, 0, 0 },
    {
      { 1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 10, 11, -1, -1, -1, -1, -1, -1, -1 },
      { 10, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 10, 11, -1, -1, -1, -1, -1, -1, -1 },
      { 10, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 10, 11, -1, -1, -1, -1, -1, -1, -1 },
      { 10, -1, -1, -1, -1, -1, -1, -1, -1 },
      { 10, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      { -1, -1, -1, -1, -1, -1, -1, -1, -1 }
    }
  },
};
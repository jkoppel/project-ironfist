{
  CreatureStack *thisa; // [sp+10h] [bp-60h]@1
  unsigned int quant; // [sp+14h] [bp-5Ch]@86
  char str; // [sp+18h] [bp-58h]@88
  int v7; // [sp+24h] [bp-4Ch]@78
  int numPosEffects; // [sp+28h] [bp-48h]@64
  bool hexInFrontClear; // [sp+2Ch] [bp-44h]@53
  int inRedrawZone; // [sp+30h] [bp-40h]@75
  int hexInFront; // [sp+34h] [bp-3Ch]@46
  int v12; // [sp+38h] [bp-38h]@55
  int numNegEffects; // [sp+3Ch] [bp-34h]@64
  int a11; // [sp+40h] [bp-30h]@3
  int offsetY; // [sp+44h] [bp-2Ch]@62
  int i; // [sp+48h] [bp-28h]@64
  int v17; // [sp+4Ch] [bp-24h]@91
  int xa; // [sp+50h] [bp-20h]@46
  int offsetX; // [sp+54h] [bp-1Ch]@91
  char *paletteSubstitution; // [sp+58h] [bp-18h]@29
  bool v21; // [sp+5Ch] [bp-14h]@6
  int v22; // [sp+60h] [bp-10h]@10
  int v23; // [sp+64h] [bp-Ch]@10
  int v24; // [sp+68h] [bp-8h]@3
  int v25; // [sp+6Ch] [bp-4h]@10
  int x; // [sp+78h] [bp+8h]@8
  int y; // [sp+7Ch] [bp+Ch]@8

  thisa = this;
  if ( !combatManager->field_F357 && !combatGraphicsOff )
  {
    v24 = 0;
    a11 = 0;
    v21 = this->animationType == 7 || this->animationType >= 8 && this->animationType <= 12;
    y = this->yDrawOffset + standingBotY;
    x = this->xDrawOffset + centX;
    if ( this->animationType == ANIMATION_TYPE_WALKING && !(this->creature.creature_flags & FLYER) )
    {
      v25 = this->form.animationLengths[this->animationType];
      v22 = 42 * this->animationFrame / v25;
      v23 = 22 * this->animationFrame / v25;
      if ( !this->field_8A || this->field_8A == 5 )
      {
        y -= v22;
        dword_4F5474 = -v22;
      }
      if ( this->field_8A == 2 || this->field_8A == 3 )
      {
        y += v22;
        dword_4F5474 = v22;
      }
      if ( !this->field_8A || this->field_8A == 2 )
        x -= v23;
      if ( this->field_8A == 5 || this->field_8A == 3 )
        x += v23;
    }
    if ( !dword_4F38A0 && v21 && this->numActiveEffects > 0 )
      a11 = 237;
    if ( this->occupiedHex == combatManager->field_F2BB && combatManager->field_F2B7 == 1 )
      a11 = 236;
    paletteSubstitution = 0;
    if ( this->effectStrengths[11] )
    {
      paletteSubstitution = petrifyPaletteTransform;
    }
    else
    {
      if ( HIBYTE(this->creature.creature_flags) & ATTR_BLOODLUST_RED )
      {
        paletteSubstitution = bloodlustPaletteTransform;
      }
      else
      {
        if ( HIBYTE(this->creature.creature_flags) & ATTR_BROWN )
        {
          paletteSubstitution = brownPaletteTransform;
        }
        else
        {
          if ( HIBYTE(this->creature.creature_flags) & ATTR_PETRIFY_GRAY )
          {
            paletteSubstitution = petrifyPaletteTransform;
          }
          else
          {
            if ( HIBYTE(this->creature.creature_flags) & ATTR_MIRROR_IMAGE )
              paletteSubstitution = mirrorImagePaletteTransform;
          }
        }
      }
    }
    if ( !a4 )
      Icon::drawToScreenAndSetRectBounds(
        this->creatureIcon,
        x,
        y,
        this->form.animationFrameToImgIdx[this->animationType][this->animationFrame],
        &this->bounds,
        this->facingRight < 1u,
        a11,
        paletteSubstitution,
        this->field_125);
    if ( v21 && combatManager->field_F2BF && LODWORD(thisa->field_4E) )
    {
      if ( thisa->creature.creature_flags & TWO_HEXER )
      {
        if ( thisa->facingRight == 1 )
        {
          xa = x + 53;
          hexInFront = thisa->occupiedHex + 2;
        }
        else
        {
          xa = x - 73;
          hexInFront = thisa->occupiedHex - 2;
        }
      }
      else
      {
        if ( thisa->facingRight == 1 )
        {
          xa = x + 9;
          hexInFront = thisa->occupiedHex + 1;
        }
        else
        {
          xa = x - 29;
          hexInFront = thisa->occupiedHex - 1;
        }
      }
      hexInFrontClear = combatManager->combatGrid[hexInFront].unitOwner != -1;
      v12 = thisa->form.stackNumDispXShift[1 - thisa->facingRight];
      if ( hexInFrontClear && v12 > 0 )
        v12 = 0;
      if ( thisa->facingRight == 1 )
        xa += v12;
      else
        xa -= v12;
      if ( thisa->facingRight == 1 )
        offsetY = y - 11;
      else
        offsetY = y - 23;
      numPosEffects = 0;
      numNegEffects = 0;
      for ( i = 0; i < 15; ++i )
      {
        if ( thisa->effectStrengths[i] )
        {
          switch ( i )
          {
            case EFFECT_HASTE:
            case EFFECT_BLESS:
            case EFFECT_DRAGON_SLAYER:
            case EFFECT_BLOOD_LUST:
            case EFFECT_SHIELD:
            case EFFECT_ANTI_MAGIC:
            case EFFECT_STONESKIN:
            case EFFECT_STEELSKIN:
              ++numPosEffects;
              break;
            default:
              ++numNegEffects;
              break;
          }
        }
      }
      if ( dword_4F38A0 && v21 && thisa->numActiveEffects > 0 )
      {
        if ( dword_4F38A0 == 1 )
        {
          inRedrawZone = Icon::drawToScreenAndSetRectBounds(
                           combatManager->combatScreenIcons[1],
                           xa,
                           offsetY,
                           11,
                           &thisa->stackSizeDispBounds,
                           0,
                           237,
                           0,
                           0);
        }
        else
        {
          v7 = 2;
          if ( numPosEffects <= 0 || numNegEffects <= 0 )
          {
            if ( numNegEffects > 0 )
              v7 += 2;
          }
          else
          {
            ++v7;
          }
          inRedrawZone = Icon::drawToScreenAndSetRectBounds(
                           combatManager->combatScreenIcons[1],
                           xa,
                           offsetY,
                           v7 + 10,
                           &thisa->stackSizeDispBounds,
                           0,
                           0,
                           0,
                           0);
        }
      }
      else
      {
        inRedrawZone = Icon::drawToScreenAndSetRectBounds(
                         combatManager->combatScreenIcons[1],
                         xa,
                         offsetY,
                         10,
                         &thisa->stackSizeDispBounds,
                         0,
                         0,
                         0,
                         0);
      }
      if ( inRedrawZone )
      {
        if ( thisa->previousQuantity == -1 )
          quant = thisa->quantity;
        else
          quant = thisa->previousQuantity;
        sprintf(&str, "%d", quant);
        Font::drawString(smallFont, &str, xa, offsetY + 2, 20, 12, 1, 1);
      }
    }
    if ( thisa->probablyIsNeedDrawSpellEffect && !a4 )
    {
      offsetX = x;
      v17 = CreatureStack::getNextEffectAnimationBottomY(thisa);
      if ( thisa->animationType == 14 || thisa->animationType == 15 )
      {
        if ( thisa->facingRight == 1 )
          offsetX -= 4;
        else
          offsetX += 4;
      }
      if ( thisa->creature.creature_flags & TWO_HEXER )
      {
        if ( thisa->facingRight == 1 )
          offsetX += 22;
        else
          offsetX -= 22;
      }
      if ( nextCreatureEffectAnimationIdx == ANIM_SHIELD_IDX )
      {
        if ( thisa->facingRight == 1 )
          offsetX = CreatureStack::getRightBound(thisa);
        else
          offsetX = CreatureStack::getLeftBound(thisa);
      }
      if ( nextCreatureEffectAnimationIdx == ANIM_BLIND_IDX )
      {
        offsetX = x + thisa->form.xOffsetForBlind * ((unsigned int)(thisa->facingRight - 1) < 1 ? 1 : -1);
        v17 = y + thisa->form.yOffsetForBlind;
      }
      Icon::drawToScreenAndSetRectBounds(
        nextCreatureEffectAnimation,
        offsetX,
        v17 + thisa->field_FA,
        spellEffectAnimImgIdx,
        &thisa->effectAnimationBounds,
        1 - thisa->facingRight,
        0,
        0,
        0);
    }
  }
}

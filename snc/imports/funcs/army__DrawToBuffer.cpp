{
  unsigned int quant; // [sp+14h] [bp-5Ch]@83
  char str; // [sp+18h] [bp-58h]@85
  int v7; // [sp+24h] [bp-4Ch]@75
  int numPosEffects; // [sp+28h] [bp-48h]@61
  bool hexInFrontClear; // [sp+2Ch] [bp-44h]@52
  int inRedrawZone; // [sp+30h] [bp-40h]@72
  int hexInFront; // [sp+34h] [bp-3Ch]@46
  int v12; // [sp+38h] [bp-38h]@52
  int numNegEffects; // [sp+3Ch] [bp-34h]@61
  int a11; // [sp+40h] [bp-30h]@3
  int offsetY; // [sp+44h] [bp-2Ch]@59
  int i; // [sp+48h] [bp-28h]@61
  int v17; // [sp+4Ch] [bp-24h]@88
  int xa; // [sp+50h] [bp-20h]@46
  int offsetX; // [sp+54h] [bp-1Ch]@88
  char *paletteSubstitution; // [sp+58h] [bp-18h]@29
  bool v21; // [sp+5Ch] [bp-14h]@6
  int v22; // [sp+60h] [bp-10h]@10
  int v23; // [sp+64h] [bp-Ch]@10
  int v24; // [sp+68h] [bp-8h]@3
  int walkLen; // [sp+6Ch] [bp-4h]@10
  int x; // [sp+78h] [bp+8h]@8
  int y; // [sp+7Ch] [bp+Ch]@8

  if ( !gpCombatManager->field_F357 && !gbNoShowCombat )
  {
    v24 = 0;
    a11 = 0;
    v21 = this->animationType == 7 || this->animationType >= 8 && this->animationType <= 12;
    y = this->yDrawOffset + standingBotY;
    x = this->xDrawOffset + centX;
    if ( this->animationType == ANIMATION_TYPE_WALKING && !(this->creature.creature_flags & FLYER) )
    {
      walkLen = this->gap_129[this->animationType + 243];
      v22 = 42 * this->animationFrame / walkLen;
      v23 = 22 * this->animationFrame / walkLen;
      if ( !this->field_8A || this->field_8A == 5 )
      {
        y -= v22;
        giWalkingYMod = -v22;
      }
      if ( this->field_8A == 2 || this->field_8A == 3 )
      {
        y += v22;
        giWalkingYMod = v22;
      }
      if ( !this->field_8A || this->field_8A == 2 )
        x -= v23;
      if ( this->field_8A == 5 || this->field_8A == 3 )
        x += v23;
    }
    if ( !giSpellEffectShowType && v21 && this->numActiveEffects > 0 )
      a11 = 237;
    if ( this->occupiedHex == gpCombatManager->field_F2BB && gpCombatManager->field_F2B7 == 1 )
      a11 = 236;
    paletteSubstitution = 0;
    if ( this->effectStrengths[11] )
    {
      paletteSubstitution = gColorTableGray;
    }
    else if ( HIBYTE(this->creature.creature_flags) & ATTR_BLOODLUST_RED )
    {
      paletteSubstitution = gColorTableRed;
    }
    else if ( HIBYTE(this->creature.creature_flags) & ATTR_BROWN )
    {
      paletteSubstitution = gColorTableDarkBrown;
    }
    else if ( HIBYTE(this->creature.creature_flags) & ATTR_PETRIFY_GRAY )
    {
      paletteSubstitution = gColorTableGray;
    }
    else if ( HIBYTE(this->creature.creature_flags) & ATTR_MIRROR_IMAGE )
    {
      paletteSubstitution = gColorTableLighten;
    }
    if ( !a4 )
      icon::CombatClipDrawToBuffer(
        this->creatureIcon,
        x,
        y,
        *(&this->gap_129[16 * this->animationType + 277] + this->animationFrame),
        &this->bounds,
        this->facingRight < 1u,
        a11,
        paletteSubstitution,
        (int)this->field_125);
    if ( v21 && gpCombatManager->field_F2BF && LODWORD(this->field_4E) )
    {
      if ( this->creature.creature_flags & TWO_HEXER )
      {
        if ( this->facingRight == 1 )
        {
          xa = x + 53;
          hexInFront = this->occupiedHex + 2;
        }
        else
        {
          xa = x - 73;
          hexInFront = this->occupiedHex - 2;
        }
      }
      else if ( this->facingRight == 1 )
      {
        xa = x + 9;
        hexInFront = this->occupiedHex + 1;
      }
      else
      {
        xa = x - 29;
        hexInFront = this->occupiedHex - 1;
      }
      hexInFrontClear = gpCombatManager->combatGrid[hexInFront].unitOwner != -1;
      v12 = *(_DWORD *)&this->gap_129[4 * (1 - this->facingRight) + 235];
      if ( hexInFrontClear && v12 > 0 )
        v12 = 0;
      if ( this->facingRight == 1 )
        xa += v12;
      else
        xa -= v12;
      if ( this->facingRight == 1 )
        offsetY = y - 11;
      else
        offsetY = y - 23;
      numPosEffects = 0;
      numNegEffects = 0;
      for ( i = 0; i < 15; ++i )
      {
        if ( this->effectStrengths[i] )
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
      if ( giSpellEffectShowType && v21 && this->numActiveEffects > 0 )
      {
        if ( giSpellEffectShowType == 1 )
        {
          inRedrawZone = icon::CombatClipDrawToBuffer(
                           gpCombatManager->combatScreenIcons[1],
                           xa,
                           offsetY,
                           11,
                           &this->stackSizeDispBounds,
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
          inRedrawZone = icon::CombatClipDrawToBuffer(
                           gpCombatManager->combatScreenIcons[1],
                           xa,
                           offsetY,
                           v7 + 10,
                           &this->stackSizeDispBounds,
                           0,
                           0,
                           0,
                           0);
        }
      }
      else
      {
        inRedrawZone = icon::CombatClipDrawToBuffer(
                         gpCombatManager->combatScreenIcons[1],
                         xa,
                         offsetY,
                         10,
                         &this->stackSizeDispBounds,
                         0,
                         0,
                         0,
                         0);
      }
      if ( inRedrawZone )
      {
        if ( this->previousQuantity == -1 )
          quant = this->quantity;
        else
          quant = this->previousQuantity;
        sprintf(&str, "%d", quant);
        font::DrawBoundedString(smallFont, &str, xa, offsetY + 2, 20, 12, 1, 1);
      }
    }
    if ( this->probablyIsNeedDrawSpellEffect && !a4 )
    {
      offsetX = x;
      v17 = army::GetPowBaseY(this);
      if ( this->animationType == 14 || this->animationType == 15 )
      {
        if ( this->facingRight == 1 )
          offsetX -= 4;
        else
          offsetX += 4;
      }
      if ( this->creature.creature_flags & TWO_HEXER )
      {
        if ( this->facingRight == 1 )
          offsetX += 22;
        else
          offsetX -= 22;
      }
      if ( gCurLoadedSpellEffect == ANIM_SHIELD_IDX )
      {
        if ( this->facingRight == 1 )
          offsetX = army::RightX(this);
        else
          offsetX = army::LeftX(this);
      }
      if ( gCurLoadedSpellEffect == ANIM_BLIND_IDX )
      {
        offsetX = x + *(_WORD *)&this->gap_129[1] * ((unsigned int)(this->facingRight - 1) < 1 ? 1 : -1);
        v17 = y + *(_WORD *)&this->gap_129[3];
      }
      icon::CombatClipDrawToBuffer(
        gCurLoadedSpellIcon,
        offsetX,
        v17 + this->field_FA,
        gCurSpellEffectFrame,
        &this->effectAnimationBounds,
        1 - this->facingRight,
        0,
        0,
        0);
    }
  }
}
{
  double v1; // st7@75
  int v2; // ST34_4@85
  signed __int64 result; // qax@97
  CombatManager *thisa; // [sp+20h] [bp-50h]@1
  float v5; // [sp+24h] [bp-4Ch]@73
  float v6; // [sp+28h] [bp-48h]@73
  signed int j; // [sp+2Ch] [bp-44h]@8
  signed int k; // [sp+2Ch] [bp-44h]@67
  char creatureShouldDoSomeAnimation[2][20]; // [sp+30h] [bp-40h]@8
  float l; // [sp+58h] [bp-18h]@73
  int i; // [sp+5Ch] [bp-14h]@1
  int v12; // [sp+60h] [bp-10h]@1
  CreatureStack *v13; // [sp+64h] [bp-Ch]@1
  int v14[2]; // [sp+68h] [bp-8h]@26

  thisa = this;
  CombatManager::couldBeResetCombatMessage(this);
  v13 = 0;
  v12 = 0;
  CombatManager::resetStuffHapenedToCreature(combatManager);
  for ( i = 0; i < 2; ++i )
  {
    if ( thisa->heroFlagIcon[i] )
    {
      if ( thisa->heroes[i] )
        thisa->heroFlagIconIdx[i] = (thisa->heroFlagIconIdx[i] + 1) % 5;
      ++thisa->field_F427[i];
    }
  }
  memset(creatureShouldDoSomeAnimation, 0, 0x28u);
  for ( j = 0; j < 2; ++j )
  {
    for ( i = 0; combatManager->numCreatures[j] > i; ++i )
    {
      v13 = &combatManager->creatures[j][i];
      if ( !(combatManager->creatures[j][i].creature.creature_flags & DEAD)
        && !v13->effectStrengths[6]
        && !v13->effectStrengths[2]
        && !v13->effectStrengths[11]
        && (v13->animationType >= 8 && v13->animationType <= 12
         || v13->animationType == 7 && v13->timeToFidget + v13->form.fidgetTimeRelated < getTickCount()) )
      {
        ++v12;
        ++creatureShouldDoSomeAnimation[j][i];
        ++thisa->stuffHappenedToCreature[j][i];
      }
    }
  }
  for ( i = 0; i < 2; ++i )
  {
    v14[i] = -1;
    if ( thisa->heroIcon[i] )
    {
      if ( thisa->heroIconIdxRelated[i] != 1
        && thisa->heroIconIdxRelated[i] != 2
        && thisa->heroIconIdxRelated[i] != 9
        && thisa->heroIconIdxRelated[i] != 10
        && thisa->heroIconIdxRelated[i] != 11 )
      {
        if ( thisa->heroIconIdxRelated[i] || *(&thisa->field_33A1 + i) || !thisa->field_339D[i] )
        {
          if ( thisa->heroIconIdxRelated[i] || thisa->field_33A3[i] || !thisa->field_339F[i] )
          {
            if ( !thisa->heroIconIdxRelated[i] && thisa->field_33BD[i] + 4500 < getTickCount() )
            {
              if ( byte_4F4C30[thisa->heroType[i]][0] <= 1 )
                v14[i] = 9;
              else
                v14[i] = unseededNextRand(0, byte_4F4C30[thisa->heroType[i]][0] - 1) + 9;
              *(&thisa->field_F41F + i) = 1;
            }
          }
          else
          {
            if ( thisa->playerID[thisa->currentActionSide] != -1
              && *(&byte_524758 + thisa->playerID[thisa->currentActionSide]) )
            {
              thisa->field_339F[i] = 0;
              thisa->field_339D[i] = thisa->field_339F[i];
              thisa->field_33A3[i] = 1;
              if ( byte_4F4C30[thisa->heroType[i]][3] > 0 )
              {
                v14[i] = 2;
                *(&thisa->field_F41F + i) = 1;
              }
            }
            else
            {
              thisa->field_339F[i] = 0;
              thisa->field_339D[i] = thisa->field_339F[i];
            }
          }
        }
        else
        {
          if ( thisa->playerID[thisa->currentActionSide] != -1
            && *(&byte_524758 + thisa->playerID[thisa->currentActionSide]) )
          {
            thisa->field_339F[i] = 0;
            thisa->field_339D[i] = thisa->field_339F[i];
            *(&thisa->field_33A1 + i) = 1;
            if ( byte_4F4C30[thisa->heroType[i]][2] > 0 )
            {
              v14[i] = 1;
              *(&thisa->field_F41F + i) = 1;
            }
          }
          else
          {
            thisa->field_339F[i] = 0;
            thisa->field_339D[i] = thisa->field_339F[i];
          }
        }
      }
      else
      {
        *(&thisa->field_F41F + i) = 1;
      }
    }
  }
  if ( thisa->heroIcon[0] )
    thisa->field_F41F = 1;
  if ( thisa->heroIcon[1] )
    thisa->field_F423 = 1;
  if ( v12 || thisa->field_F41F || thisa->field_F423 || thisa->field_F427[0] || thisa->field_F427[1] )
  {
    CombatManager::drawBattlefield(combatManager, 0, 1, 1, 1, 75, 1, 1);
    for ( k = 0; k < 2; ++k )
    {
      for ( i = 0; combatManager->numCreatures[k] > i; ++i )
      {
        v13 = &combatManager->creatures[k][i];
        if ( creatureShouldDoSomeAnimation[k][i] )
        {
          if ( v13->animationType == 7 )
          {
            v5 = (double)unseededNextRand(1, 100) / 100.0;
            v6 = 0.0;
            LODWORD(v13->field_4A) = v13->form.field_75[0] - 1;
            for ( l = 0.0; v13->form.field_75[0] - 1 > SLODWORD(l); ++LODWORD(l) )
            {
              v1 = *(float *)&v13->form.field_75[4 * LODWORD(l) + 1] + v6;
              v6 = v1;
              if ( v1 > v5 )
              {
                v13->field_4A = l;
                LODWORD(l) = 99;
              }
            }
            v13->animationType = LODWORD(v13->field_4A) + 8;
            v13->animationFrame = 0;
          }
          else
          {
            ++v13->animationFrame;
            if ( !v13->form.fidgetTimeRelated && v13->form.field_75[0] == 1 && unseededNextRand(0, 100) < 8 )
              --v13->animationFrame;
            if ( v13->form.animationLengths[LODWORD(v13->field_4A) + 8] <= v13->animationFrame )
            {
              v13->animationType = 7;
              v13->animationFrame = 0;
              v13->timeToFidget = getTickCount();
              if ( v13->form.fidgetTimeRelated > 0 )
              {
                v2 = unseededNextRand(0, v13->form.fidgetTimeRelated);
                v13->timeToFidget = (signed __int64)((double)v2 * 0.5
                                                   - (double)v13->form.fidgetTimeRelated * 0.25
                                                   + (double)v13->timeToFidget);
              }
            }
          }
        }
      }
    }
    for ( i = 0; i < 2; ++i )
    {
      if ( *(&thisa->field_F41F + i) )
      {
        if ( v14[i] == -1 )
        {
          ++thisa->countRelatedToSpellAnimation[i];
          if ( byte_4F4C30[thisa->heroType[i]][thisa->heroIconIdxRelated[i] + 1] <= thisa->countRelatedToSpellAnimation[i] )
          {
            thisa->heroIconIdxRelated[i] = 0;
            thisa->countRelatedToSpellAnimation[i] = 0;
            thisa->field_33BD[i] = getTickCount();
          }
        }
        else
        {
          thisa->heroIconIdxRelated[i] = v14[i];
          thisa->countRelatedToSpellAnimation[i] = 0;
        }
      }
    }
    CombatManager::drawBattlefield(thisa, 1, 1, 0, 0, 75, 1, 1);
  }
  result = (signed __int64)((double)getTickCount() + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 150.0);
  nextCombatAnimationTime = result;
  return result;
}

{
  int v4; // eax@40
  CreatureStack *result; // eax@45
  CombatManager *thisa; // [sp+10h] [bp-40h]@1
  CreatureStack *creat; // [sp+14h] [bp-3Ch]@4
  int v8; // [sp+18h] [bp-38h]@9
  int v9; // [sp+20h] [bp-30h]@9
  int spriteIdx; // [sp+28h] [bp-28h]@11
  int spriteIdxa; // [sp+28h] [bp-28h]@35
  int a4; // [sp+2Ch] [bp-24h]@31
  int a3; // [sp+30h] [bp-20h]@31
  signed int v14; // [sp+34h] [bp-1Ch]@9
  int v15; // [sp+3Ch] [bp-14h]@4
  signed int v16; // [sp+40h] [bp-10h]@9
  signed int v17; // [sp+44h] [bp-Ch]@4
  Icon *res; // [sp+48h] [bp-8h]@35
  signed int v19; // [sp+4Ch] [bp-4h]@4

  thisa = this;
  if ( this->heroes[this->currentActionSide] && Hero::hasArtifact(this->heroes[this->currentActionSide], ARTIFACT_ANKH) )
    spellpower *= 2;
  v17 = CombatManager::getCorpseStackIdx(thisa, thisa->currentActionSide, spell, hex);
  creat = &thisa->creatures[thisa->currentActionSide][v17];
  v19 = 0;
  v15 = thisa->creatures[thisa->currentActionSide][v17].quantity;
  creat->quantity += 50 * spellpower / thisa->creatures[thisa->currentActionSide][v17].creature.hp;
  if ( creat->initialQuantity < creat->quantity )
    creat->quantity = creat->initialQuantity;
  if ( spell == 7 )
    creat->anAmountToLose += creat->quantity - v15;
  if ( v15 <= 0 )
  {
    v8 = -1;
    v14 = -1;
    v16 = 1;
    v9 = hex;
    while ( v16 )
    {
      for ( spriteIdx = 0; thisa->combatGrid[v9].numCorpses > spriteIdx; ++spriteIdx )
      {
        if ( *(&thisa->combatGrid[0].corpseOwners[99 * v9] + spriteIdx - v9) == thisa->currentActionSide )
        {
          if ( *(&thisa->combatGrid[0].corpseStackIndices[99 * v9] + spriteIdx - v9) == v17 )
          {
            v14 = spriteIdx;
            if ( !v19 )
            {
              if ( *(&thisa->combatGrid[0].field_33[99 * v9] + spriteIdx - v9) == 1 )
              {
                v8 = v9 - 1;
              }
              else
              {
                if ( !*(&thisa->combatGrid[0].field_33[99 * v9] + spriteIdx - v9) )
                  v8 = v9 + 1;
              }
            }
          }
        }
        if ( v14 != -1 )
        {
          thisa->combatGrid[v9].unitOwner = *(&thisa->combatGrid[0].corpseOwners[99 * v9] + spriteIdx - v9);
          thisa->combatGrid[v9].stackIdx = *(&thisa->combatGrid[0].corpseStackIndices[99 * v9] + spriteIdx - v9);
          thisa->combatGrid[v9].notPrimarySquareOfTwoHexer = *(&thisa->combatGrid[0].field_33[99 * v9] + spriteIdx - v9);
          if ( thisa->combatGrid[v9].numCorpses == spriteIdx + 1 )
          {
            *(&thisa->combatGrid[0].corpseOwners[99 * v9] + spriteIdx - v9) = -1;
            *(&thisa->combatGrid[0].corpseStackIndices[99 * v9] + spriteIdx - v9) = -1;
          }
          else
          {
            *(&thisa->combatGrid[0].corpseOwners[99 * v9] + spriteIdx - v9) = *(&thisa->combatGrid[0].corpseOwners[99 * v9]
                                                                              + spriteIdx
                                                                              + 1
                                                                              - v9);
            *(&thisa->combatGrid[0].corpseStackIndices[99 * v9] + spriteIdx - v9) = *(&thisa->combatGrid[0].corpseStackIndices[99 * v9]
                                                                                    + spriteIdx
                                                                                    + 1
                                                                                    - v9);
          }
        }
      }
      --thisa->combatGrid[v9].numCorpses;
      if ( v19 )
      {
        v16 = 0;
      }
      else
      {
        if ( v8 == -1 )
        {
          v16 = 0;
        }
        else
        {
          v9 = v8;
          v19 = 1;
          v14 = -1;
        }
      }
    }
  }
  a3 = CreatureStack::getCenterX(creat);
  a4 = CreatureStack::getCenterY(creat);
  if ( creat->quantity - v15 <= 1 )
    sprintf(globBuf, "%d %s rises from the dead!", creat->quantity - v15, creatureSingularNames[creat->creatureIdx]);
  else
    sprintf(globBuf, "%d %s rise from the dead!", creat->quantity - v15, creaturePluralNames[creat->creatureIdx]);
  CombatManager::displayCombatMessage(thisa, globBuf, 1, 1, 0);
  if ( !combatGraphicsOff )
  {
    res = ResourceManager::getIconByFilename(resourceManager, "yinyang.icn");
    for ( spriteIdxa = 0; spriteIdxa < 22; ++spriteIdxa )
    {
      animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 75.0);
      rasterize(res, HeroWindowManager::instance->screenBuffer, a3, a4, spriteIdxa, 1, 0, 0, 0x280u, 443, 0);
      sub_4C3D60(thisa);
      creat->facingRight = 1 - creat->owningSide;
      if ( creat->animationType == 13 )
      {
        if ( spriteIdxa < 18 )
        {
          v4 = creat->form.animationLengths[13] - 1;
          if ( v4 >= 17 - spriteIdxa )
            v4 = 17 - spriteIdxa;
          creat->animationFrame = v4;
        }
        else
        {
          creat->animationType = 7;
          creat->animationFrame = 0;
        }
      }
      CombatManager::drawBattlefield(thisa, 0, 0, 0, 0, 75, 1, 1);
      sleepUntilPointer(&animationFrameSwitchTime);
    }
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res);
  }
  CombatManager::drawBattlefield(thisa, 1, 0, 0, 0, 75, 1, 1);
  result = creat;
  *(_DWORD *)&result->creature.creature_flags &= 0xFFEFu;
  return result;
}

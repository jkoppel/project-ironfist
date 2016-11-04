{
  CombatManager *thisa; // [sp+20h] [bp-A0h]@1
  signed int v3; // [sp+24h] [bp-9Ch]@110
  char *v4; // [sp+28h] [bp-98h]@95
  int a1; // [sp+2Ch] [bp-94h]@95
  char v6; // [sp+30h] [bp-90h]@92
  char v7; // [sp+31h] [bp-8Fh]@92
  char v8; // [sp+32h] [bp-8Eh]@92
  char v9; // [sp+33h] [bp-8Dh]@92
  char v10; // [sp+34h] [bp-8Ch]@92
  char v11; // [sp+35h] [bp-8Bh]@92
  char v12; // [sp+36h] [bp-8Ah]@92
  char v13; // [sp+37h] [bp-89h]@92
  char v14; // [sp+38h] [bp-88h]@92
  int v15; // [sp+3Ch] [bp-84h]@92
  bool v16; // [sp+40h] [bp-80h]@15
  int v17; // [sp+44h] [bp-7Ch]@8
  int v18; // [sp+48h] [bp-78h]@12
  int attack; // [sp+4Ch] [bp-74h]@8
  Castle *v20; // [sp+50h] [bp-70h]@8
  int numArchers; // [sp+54h] [bp-6Ch]@8
  int v22[2]; // [sp+58h] [bp-68h]@1
  int v23[2]; // [sp+60h] [bp-60h]@1
  int v24; // [sp+68h] [bp-58h]@1
  int v25; // [sp+6Ch] [bp-54h]@1
  CreatureStack *stack; // [sp+74h] [bp-4Ch]@1
  int v27[2]; // [sp+78h] [bp-48h]@1
  signed int hexIdx; // [sp+80h] [bp-40h]@108
  int v29[2]; // [sp+84h] [bp-3Ch]@1
  int v30; // [sp+8Ch] [bp-34h]@1
  int v31; // [sp+90h] [bp-30h]@1
  int v32; // [sp+94h] [bp-2Ch]@1
  int v33; // [sp+98h] [bp-28h]@1
  int v34; // [sp+9Ch] [bp-24h]@1
  int v35[2]; // [sp+A0h] [bp-20h]@1
  int v36; // [sp+A8h] [bp-18h]@41
  int v37; // [sp+ACh] [bp-14h]@1
  int v38[2]; // [sp+B0h] [bp-10h]@1
  int stackBmask[2]; // [sp+B8h] [bp-8h]@1

  thisa = this;
  this->field_F2B7 = 0;
  stack = &thisa->creatures[thisa->otherCurrentSideThing][this->someSortOfStackIdx];
  v34 = 0;
  v37 = 1 - this->currentActionSide;
  v22[this->currentActionSide] = sub_46C0B0(this, this->currentActionSide);
  v22[v37] = sub_46C0B0(thisa, v37);
  v23[thisa->currentActionSide] = sub_46BF70(thisa, thisa->currentActionSide);
  v23[v37] = sub_46BF70(thisa, v37);
  v38[thisa->currentActionSide] = sub_46C170(thisa, thisa->currentActionSide);
  v38[v37] = sub_46C170(thisa, v37);
  stackBmask[thisa->currentActionSide] = sub_46C350(thisa, thisa->currentActionSide);
  stackBmask[v37] = sub_46C350(thisa, v37);
  v27[thisa->currentActionSide] = sub_46C4A0(thisa, thisa->currentActionSide);
  v27[v37] = sub_46C4A0(thisa, v37);
  v35[thisa->currentActionSide] = sub_46C590(thisa, thisa->currentActionSide);
  v35[v37] = sub_46C590(thisa, v37);
  v29[thisa->currentActionSide] = sub_46CAB0(thisa, thisa->currentActionSide, v23[thisa->currentActionSide]);
  v29[v37] = sub_46CAB0(thisa, v37, v23[v37]);
  v25 = sub_46CAB0(
          thisa,
          thisa->currentActionSide,
          v35[thisa->currentActionSide] | v27[thisa->currentActionSide] | stackBmask[thisa->currentActionSide] | v38[thisa->currentActionSide] | v23[thisa->currentActionSide]);
  v24 = (v25 + 4) / 5;
  v32 = 0;
  v31 = 0;
  v33 = sub_46CAB0(thisa, thisa->currentActionSide, v23[thisa->currentActionSide]);
  v30 = sub_46CAB0(thisa, v37, v23[v37]);
  if ( thisa->isCastleBattle )
  {
    if ( !thisa->heroes[0]->secondarySkillLevel[1] && !Hero::hasArtifact(thisa->heroes[0], ARTIFACT_GOLDEN_BOW) )
    {
      if ( thisa->currentActionSide )
        v30 /= 2;
      else
        v33 /= 2;
    }
    if ( !thisa->ballistaDestroyed )
    {
      v20 = thisa->castles[1];
      Castle::retrieveBallistaStats(thisa->castles[1], &numArchers, &attack);
      v17 = 0;
      if ( thisa->turretStatus[0] == 1 )
        v17 += numArchers / 2;
      if ( thisa->turretStatus[3] == 1 )
        v17 += numArchers / 2;
      numArchers += v17;
      v18 = (signed __int64)(((double)attack * 0.1 + 1.0) * (double)(300 * numArchers));
      v16 = !thisa->heroes[0]
         || !Hero::hasArtifact(thisa->heroes[0], ARTIFACT_GOLDEN_BOW) && !thisa->heroes[0]->secondarySkillLevel[1];
      if ( thisa->currentActionSide == 1 )
        v33 += v18;
      else
        v30 += v18;
    }
  }
  if ( thisa->heroes[thisa->currentActionSide] )
    v33 = (signed __int64)((double)v33 * archeryBonus[thisa->heroes[thisa->currentActionSide]->secondarySkillLevel[1]]);
  if ( thisa->heroes[1 - thisa->currentActionSide] )
    v30 = (signed __int64)((double)v30
                         * archeryBonus[thisa->heroes[1 - thisa->currentActionSide]->secondarySkillLevel[1]]);
  if ( (v25 + 4) / 5 < v33 )
    v32 = 1;
  if ( v33 < v30 )
    v31 = 1;
  if ( stack->creature.creature_flags & 4 )
  {
    if ( stack->creature.shots <= 0 )
      v34 = 3;
    else
      v34 = 1;
  }
  else
  {
    if ( stack->creature.creature_flags & 2 )
      v34 = 2;
    else
      v34 = 3;
  }
  if ( v34 == 1 )
  {
    if ( sub_46CD40(thisa, (int)stack) )
      goto LABEL_104;
    if ( stack->creatureIdx != 54 && stack->creatureIdx != 55 )
    {
      v36 = sub_46C670(thisa, v37, v22[v37]);
      if ( v36 == -1 )
      {
        v36 = sub_46C670(thisa, v37, v23[v37]);
        if ( v36 == -1 )
        {
          v36 = sub_46C670(thisa, v37, v38[v37]);
          if ( v36 == -1 )
          {
            if ( stackBmask[v37]
              && (v36 = CombatManager::findBestDistanceHPTradeoffStack(thisa, stack, v37, stackBmask[v37]), v36 != -1) )
            {
              couldBeCreatureActionType = 2;
              notTargetForAISpell = thisa->creatures[v37][v36].occupiedHex;
            }
            else
            {
              v36 = sub_46C670(thisa, v37, v27[v37]);
              if ( v36 == -1 )
              {
                v36 = sub_46C670(thisa, v37, v35[v37]);
                if ( v36 == -1 )
                  goto LABEL_103;
                couldBeCreatureActionType = 2;
                notTargetForAISpell = thisa->creatures[v37][v36].occupiedHex;
              }
              else
              {
                couldBeCreatureActionType = 2;
                notTargetForAISpell = thisa->creatures[v37][v36].occupiedHex;
              }
            }
          }
          else
          {
            couldBeCreatureActionType = 2;
            notTargetForAISpell = thisa->creatures[v37][v36].occupiedHex;
          }
        }
        else
        {
          couldBeCreatureActionType = 2;
          notTargetForAISpell = thisa->creatures[v37][v36].occupiedHex;
        }
      }
      else
      {
        couldBeCreatureActionType = 2;
        notTargetForAISpell = thisa->creatures[v37][v36].occupiedHex;
      }
    }
    else
    {
      sub_46BC40(thisa, (int)stack);
    }
  }
  else
  {
    if ( v34 == 2 )
    {
      if ( !v32 || v31 )
      {
        if ( !sub_46CB80(thisa, (int)stack, v37, v22[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v23[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v38[v37])
          && !sub_46CB80(thisa, (int)stack, v37, stackBmask[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v27[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v35[v37]) )
          goto LABEL_103;
      }
      else
      {
        if ( !sub_46CB80(thisa, (int)stack, v37, v22[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v23[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v38[v37])
          && !sub_46CB80(thisa, (int)stack, v37, stackBmask[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v27[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v35[v37]) )
          goto LABEL_103;
      }
    }
    else
    {
      if ( v34 != 3 )
      {
LABEL_103:
        couldBeCreatureActionType = 3;
        goto LABEL_104;
      }
      if ( !v32 || v31 )
      {
        if ( !sub_46CB80(thisa, (int)stack, v37, v22[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v23[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v38[v37])
          && !sub_46CB80(thisa, (int)stack, v37, stackBmask[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v27[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v35[v37])
          && !sub_46D110(thisa, stack, v37, v23[v37])
          && !sub_46D110(thisa, stack, v37, stackBmask[v37])
          && !sub_46D110(thisa, stack, v37, v38[v37])
          && !sub_46D110(thisa, stack, v37, v27[v37])
          && !sub_46D110(thisa, stack, v37, v35[v37]) )
        {
          v6 = 8;
          v7 = 21;
          v8 = 33;
          v9 = 46;
          v10 = 58;
          v11 = 72;
          v12 = 85;
          v13 = 99;
          v14 = 112;
          v15 = stack->occupiedHex / 13;
          if ( thisa->currentActionSide )
            goto LABEL_103;
          if ( !thisa->isCastleBattle )
            goto LABEL_103;
          if ( (unsigned __int8)*(&v6 + v15) <= stack->occupiedHex )
            goto LABEL_103;
          a1 = (unsigned __int8)*(&v6 + v15);
          v4 = (char *)&combatManager->combatGrid[a1];
          if ( !checkHexGridIdxBounds((unsigned __int8)*(&v6 + v15)) || v4[16] != -1 || v4[14] )
            goto LABEL_103;
          couldBeCreatureActionType = 2;
          notTargetForAISpell = a1;
        }
      }
      else
      {
        if ( !sub_46CB80(thisa, (int)stack, v37, v22[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v23[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v38[v37])
          && !sub_46CB80(thisa, (int)stack, v37, stackBmask[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v27[v37])
          && !sub_46CB80(thisa, (int)stack, v37, v35[v37])
          && !sub_46CED0(thisa, (int)stack, thisa->currentActionSide, v23[thisa->currentActionSide]) )
          couldBeCreatureActionType = 3;
      }
    }
  }
LABEL_104:
  if ( couldBeCreatureActionType == 2
    && notTargetForAISpell > 0
    && notTargetForAISpell < 117
    && combatManager->combatGrid[notTargetForAISpell].unitOwner == -1 )
  {
    for ( hexIdx = 0; hexIdx < 6; ++hexIdx )
    {
      v3 = CreatureStack::getHexNeighbor(stack, notTargetForAISpell, hexIdx);
      if ( v3 > 0 && v3 < 117 && combatManager->combatGrid[v3].unitOwner == 1 - thisa->currentActionSide )
      {
        notTargetForAISpell = v3;
        return;
      }
    }
  }
}

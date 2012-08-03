void __userpurge CombatManager::castMeteorShower(CombatManager *this<ecx>, int ebx0<ebx>, int hexIdx)
{
  CombatManager *thisa; // [sp+10h] [bp-3Ch]@1
  Icon *res; // [sp+14h] [bp-38h]@6
  CreatureStack *stack; // [sp+18h] [bp-34h]@2
  int imageIdx; // [sp+1Ch] [bp-30h]@8
  signed int a2; // [sp+20h] [bp-2Ch]@20
  signed int neighborIdx; // [sp+24h] [bp-28h]@2
  signed int neighborIdxa; // [sp+24h] [bp-28h]@6
  signed int neighborIdxb; // [sp+24h] [bp-28h]@13
  int hexes[7]; // [sp+28h] [bp-24h]@2
  int baseDam; // [sp+44h] [bp-8h]@13
  int hurtAnyone; // [sp+48h] [bp-4h]@13

  thisa = this;
  if ( checkHexGridIdxBounds(hexIdx) )
  {
    stack = &thisa->creatures[thisa->currentActionSide][thisa->someSortOfStackIdx];
    hexes[0] = hexIdx;
    for ( neighborIdx = 0; neighborIdx < 6; ++neighborIdx )
      hexes[neighborIdx + 1] = getHexNeighbor(hexIdx, neighborIdx);
    if ( !combatGraphicsOff )
    {
      res = ResourceManager::getIconByFilename(resourceManager, "meteor.icn");
      for ( neighborIdxa = 0; neighborIdxa < 2; ++neighborIdxa )
      {
        for ( imageIdx = 0; imageIdx < 10; ++imageIdx )
        {
          animationFrameSwitchTime = (signed __int64)((double)getTickCount()
                                                    + combatSpeedPercentages[*(_DWORD *)&combatSpeed] * 112.5);
          CombatManager::drawBattlefield(thisa, 0, 0, 0, 0, 75, 1, 1);
          Icon::drawToScreenAndSetRectBounds(
            res,
            thisa->combatGrid[hexIdx].centerX,
            thisa->combatGrid[hexIdx].occupyingCreatureBottomY - 17,
            imageIdx,
            0,
            0,
            0,
            0,
            0);
          sub_4C3D60(thisa);
          sleepUntilPointer(&animationFrameSwitchTime);
        }
      }
      ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)res);
    }
    baseDam = 25 * thisa->heroSpellpowers[thisa->currentActionSide];
    zero_out_stack_affected_list();
    hurtAnyone = 0;
    for ( neighborIdxb = 0; neighborIdxb < 7; ++neighborIdxb )
    {
      if ( hexes[neighborIdxb] != -1 )
      {
        if ( thisa->combatGrid[hexes[neighborIdxb]].unitOwner != -1 )
        {
          stack = &thisa->creatures[thisa->combatGrid[hexes[neighborIdxb]].unitOwner][thisa->combatGrid[hexes[neighborIdxb]].stackIdx];
          if ( CreatureStack::rollSpellSucceeds(stack, SPELL_METEOR_SHOWER) )
          {
            if ( !stack_affected_by_aoe[thisa->combatGrid[hexes[neighborIdxb]].unitOwner][thisa->combatGrid[hexes[neighborIdxb]].stackIdx] )
            {
              stack_affected_by_aoe[thisa->combatGrid[hexes[neighborIdxb]].unitOwner][thisa->combatGrid[hexes[neighborIdxb]].stackIdx] = 1;
              if ( !stack->damageTakenDuringSomeTimePeriod )
              {
                a2 = baseDam;
                if ( stack->creatureIdx == CREATURE_EARTH_ELEMENTAL )
                  a2 = 2 * baseDam;
                CreatureStack::takeDamage(stack, a2, SPELL_METEOR_SHOWER);
                hurtAnyone = 1;
              }
            }
          }
        }
      }
    }
    if ( hurtAnyone )
    {
      sprintf(globBuf, "The meteor shower does %d damage.", baseDam);
      CombatManager::displayCombatMessage(thisa, globBuf, 1, 1, 0);
      CreatureStack::doAttackAndDamageTakenAnimations(stack, -1, 1, -1, -1);
    }
  }
}

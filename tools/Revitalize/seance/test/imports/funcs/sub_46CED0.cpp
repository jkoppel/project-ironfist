{
  signed int result; // eax@2
  char v5; // ST3C_1@11
  void *thisa; // [sp+Ch] [bp-20h]@1
  int v7; // [sp+10h] [bp-1Ch]@12
  int v8; // [sp+14h] [bp-18h]@12
  int targHex; // [sp+18h] [bp-14h]@3
  int targHexa; // [sp+18h] [bp-14h]@6
  signed int v11; // [sp+20h] [bp-Ch]@3
  signed int v12; // [sp+24h] [bp-8h]@1

  thisa = this;
  *(_DWORD *)(a2 + 82) = -1;
  *(_DWORD *)(a2 + 86) = -1;
  v12 = CombatManager::findBestDistanceHPTradeoffStack((CombatManager *)this, (CreatureStack *)a2, a3, a4);
  if ( v12 == -1 )
  {
    result = 0;
  }
  else
  {
    v11 = 1;
    targHex = *(_DWORD *)((char *)thisa + 24234 * a3 + 1154 * v12 + 13769);
    if ( *((_BYTE *)thisa + 24234 * a3 + 1154 * v12 + 13855) & 1 )
      v11 = 2;
    if ( *(_DWORD *)(a2 + 134) == 1 )
      targHexa = v11 + targHex;
    else
      targHexa = targHex - v11;
    if ( targHexa % 13 != 12 && targHexa % 13 )
    {
      v5 = *(_BYTE *)(a2 + 197);
      *(_BYTE *)(a2 + 197) = 127;
      Pathfinder::doSomething1(pathfinder, *(_DWORD *)(a2 + 122), targHexa, (CreatureStack *)a2, 1, 0);
      *(_BYTE *)(a2 + 197) = v5;
      if ( pathfinder->field_8 <= 0 )
      {
        result = sub_46D110((CombatManager *)thisa, (CreatureStack *)a2, a3, a4);
      }
      else
      {
        couldBeCreatureActionType = 2;
        v7 = *(_BYTE *)(a2 + 197);
        v8 = pathfinder->field_8 - 1;
        notTargetForAISpell = *(_DWORD *)(a2 + 122);
        while ( v8 >= 0 && v7 )
        {
          notTargetForAISpell = CreatureStack::getHexNeighbor(
                                  (CreatureStack *)a2,
                                  notTargetForAISpell,
                                  *((_BYTE *)&pathfinder->field_2418 + v8--));
          --v7;
          if ( notTargetForAISpell > 0 )
          {
            if ( pathfindingRelatedArray[notTargetForAISpell] )
              v7 = 0;
          }
        }
        result = 1;
      }
    }
    else
    {
      result = sub_46D110((CombatManager *)thisa, (CreatureStack *)a2, a3, a4);
    }
  }
  return result;
}

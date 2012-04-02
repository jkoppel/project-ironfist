signed int __thiscall CombatManager::checkCombatOver(CombatManager *this, InputEvent *evt)
{
  CombatManager *thisa; // [sp+Ch] [bp-14h]@1
  signed int v4; // [sp+10h] [bp-10h]@15
  signed int i; // [sp+18h] [bp-8h]@15
  signed int combatOver; // [sp+1Ch] [bp-4h]@1

  thisa = this;
  combatOver = 0;
  if ( CombatManager::defeatedOpponent(this, this->currentActionSide) )
  {
    combatOver = 1;
    if ( CombatManager::defeatedOpponent(thisa, 1 - thisa->currentActionSide) )
      thisa->winningSide = -1;
    else
      thisa->winningSide = thisa->currentActionSide;
  }
  else
  {
    if ( CombatManager::defeatedOpponent(thisa, 1 - thisa->currentActionSide) )
    {
      combatOver = 1;
      thisa->winningSide = 1 - thisa->currentActionSide;
    }
    else
    {
      if ( thisa->field_F377[0] || thisa->field_F377[1] )
      {
        combatOver = 1;
        isRetreating = 1;
        if ( thisa->field_F377[0] )
          thisa->winningSide = 1;
        else
          thisa->winningSide = 0;
      }
    }
  }
  if ( combatOver && thisa->winningSide != -1 )
  {
    v4 = 0;
    for ( i = 0; i < 20; ++i )
    {
      if ( thisa->creatures[thisa->winningSide][i].creatureIdx != -1
        && thisa->creatures[thisa->winningSide][i].quantity > 0 )
      {
        if ( !(HIBYTE(thisa->creatures[thisa->winningSide][i].creature.creature_flags) & 8) )
          v4 = 1;
      }
    }
    if ( !v4 )
      thisa->winningSide = -1;
  }
  if ( combatOver )
  {
    CombatManager::winBattle(thisa, thisa->winningSide);
    if ( !combatGraphicsOff )
    {
      evt->eventCode = 0x4000u;
      evt->xCoordOrKeycode = 1;
    }
  }
  return combatOver;
}

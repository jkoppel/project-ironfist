signed int __thiscall CombatManager::summonElemental(CombatManager *this, CREATURES creatureId, int strength)
{
  CombatManager *thisa; // [sp+Ch] [bp-1Ch]@1
  char squaresAroundCaster[2][3]; // [sp+10h] [bp-18h]@1
  int hex; // [sp+18h] [bp-10h]@1
  int i; // [sp+1Ch] [bp-Ch]@4
  CreatureStack *v8; // [sp+20h] [bp-8h]@9
  int tryFirst; // [sp+24h] [bp-4h]@1

  thisa = this;
  *(_WORD *)squaresAroundCaster[0] = 6926;
  squaresAroundCaster[0][2] = 40;
  *(_WORD *)squaresAroundCaster[1] = 6155;
  squaresAroundCaster[1][2] = 37;
  tryFirst = nextRandomInt(0, 2);
  hex = -1;
  if ( thisa->heroes[thisa->currentActionSide]
    && Hero::hasArtifact(thisa->heroes[thisa->currentActionSide], ARTIFACT_BOOK_OF_ELEMENTS) )
    strength *= 2;
  for ( i = 0; i < 3; ++i )
  {
    if ( thisa->combatGrid[squaresAroundCaster[thisa->currentActionSide][(i + tryFirst) % 3]].unitOwner == -1 )
      hex = squaresAroundCaster[thisa->currentActionSide][(i + tryFirst) % 3];
  }
  thisa->summonedCreatureType[thisa->currentActionSide] = creatureId;
  CombatManager::createSummonedStack(thisa, thisa->currentActionSide, creatureId, 3 * strength, hex, 0, 1);
  v8 = &thisa->creatures[thisa->combatGrid[hex].unitOwner][thisa->combatGrid[hex].stackIdx];
  *(_DWORD *)&v8->creature.creature_flags |= 0x800u;
  Hero::hasArtifact(thisa->heroes[thisa->currentActionSide], ARTIFACT_ENCHANTED_HOURGLASS);
  return Hero::hasArtifact(thisa->heroes[thisa->currentActionSide], ARTIFACT_WIZARDS_HAT);
}

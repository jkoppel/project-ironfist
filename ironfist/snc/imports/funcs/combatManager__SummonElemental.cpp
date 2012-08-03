{
  char squaresAroundCaster[2][3]; // [sp+10h] [bp-18h]@1
  int hex; // [sp+18h] [bp-10h]@1
  int i; // [sp+1Ch] [bp-Ch]@4
  army *v8; // [sp+20h] [bp-8h]@9
  int tryFirst; // [sp+24h] [bp-4h]@1

  squaresAroundCaster[0][0] = 14;
  squaresAroundCaster[0][1] = 27;
  squaresAroundCaster[0][2] = 40;
  squaresAroundCaster[1][0] = 11;
  squaresAroundCaster[1][1] = 24;
  squaresAroundCaster[1][2] = 37;
  tryFirst = SRandom(0, 2);
  hex = -1;
  if ( this->heroes[this->currentActionSide]
    && hero::HasArtifact(this->heroes[this->currentActionSide], ARTIFACT_BOOK_OF_ELEMENTS) )
    strength *= 2;
  for ( i = 0; i < 3; ++i )
  {
    if ( this->combatGrid[squaresAroundCaster[this->currentActionSide][(i + tryFirst) % 3]].unitOwner == -1 )
      hex = squaresAroundCaster[this->currentActionSide][(i + tryFirst) % 3];
  }
  this->summonedCreatureType[this->currentActionSide] = creatureId;
  combatManager::AddArmy(this, this->currentActionSide, creatureId, 3 * strength, hex, 0, 1);
  v8 = &this->creatures[this->combatGrid[hex].unitOwner][this->combatGrid[hex].stackIdx];
  *(_DWORD *)&v8->creature.creature_flags |= 0x800u;
  hero::HasArtifact(this->heroes[this->currentActionSide], ARTIFACT_ENCHANTED_HOURGLASS);
  return hero::HasArtifact(this->heroes[this->currentActionSide], ARTIFACT_WIZARDS_HAT);
}
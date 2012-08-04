{
  int v3; // [sp+14h] [bp-A0h]@22
  char v4; // [sp+18h] [bp-9Ch]@22
  char v5; // [sp+19h] [bp-9Bh]@22
  char v6; // [sp+1Ah] [bp-9Ah]@22
  char v7; // [sp+1Bh] [bp-99h]@22
  char v8; // [sp+1Ch] [bp-98h]@22
  char v9; // [sp+1Dh] [bp-97h]@22
  int v10; // [sp+20h] [bp-94h]@22
  int v11; // [sp+24h] [bp-90h]@92
  int numSpellsOfLevel[5]; // [sp+28h] [bp-8Ch]@52
  int k; // [sp+3Ch] [bp-78h]@52
  int j; // [sp+40h] [bp-74h]@50
  int spell; // [sp+44h] [bp-70h]@87
  int randNum; // [sp+48h] [bp-6Ch]@63
  bool hasAdventureSpellAtLevel; // [sp+4Ch] [bp-68h]@81
  int a3; // [sp+50h] [bp-64h]@6
  char spellPresent[68]; // [sp+54h] [bp-60h]@50
  int tries; // [sp+98h] [bp-1Ch]@86 MAPDST
  int v21; // [sp+9Ch] [bp-18h]@5
  int i; // [sp+A4h] [bp-10h]@9
  int castleIdx; // [sp+A8h] [bp-Ch]@1
  town *castle; // [sp+ACh] [bp-8h]@5
  int v25; // [sp+B0h] [bp-4h]@5

  for ( castleIdx = 0; castleIdx < 72; ++castleIdx )
  {
    if ( this->castles[castleIdx].field_36 )
    {
      castle = &this->castles[castleIdx];
      v25 = *(_WORD *)&this->castles[castleIdx]._2[2];
      v21 = *((_DWORD *)ppMapExtra + v25);
      if ( *(_BYTE *)v21 == -1 )
        a3 = -1;
      else
        a3 = gcColorToPlayerPos[*(_BYTE *)v21];
      game::ClaimTown(this, castleIdx, a3, 0);
      castle->_2[1] = a3;
      if ( *(_BYTE *)(v21 + 7) )
      {
        for ( i = 0; i < 5; ++i )
        {
          castle->garrison.quantities[i] = *(_WORD *)(v21 + 2 * i + 13);
          if ( castle->garrison.quantities[i] <= 0 )
            castle->garrison.creatureTypes[i] = -1;
          else
            castle->garrison.creatureTypes[i] = *(_BYTE *)(i + v21 + 8);
        }
      }
      else
      {
        for ( i = 0; i < 5; ++i )
        {
          castle->garrison.quantities[i] = 0;
          castle->garrison.creatureTypes[i] = -1;
        }
        game::GiveTroopsToNeutralTown(this, castleIdx);
        game::GiveTroopsToNeutralTown(this, castleIdx);
        game::GiveTroopsToNeutralTown(this, castleIdx);
        game::GiveTroopsToNeutralTown(this, castleIdx);
      }
      if ( *(_BYTE *)(v21 + 1) )
      {
        castle->buildingsBuiltFlags = castle->buildingsBuiltFlags & 0x60 | *(_DWORD *)(v21 + 2) & gTownEligibleBuildMask[castle->factionID];
        castle->mageGuildLevel = *(_BYTE *)(v21 + 6);
      }
      else
      {
        v3 = 33620225;
        v4 = 1;
        v5 = 1;
        v6 = 1;
        v7 = 2;
        v8 = 1;
        v9 = 2;
        v10 = *((_BYTE *)&v3 + Random(0, 99) / 10);
        castle->buildingsBuiltFlags |= 0x80000u;
        if ( !gbHumanPlayer[castle->ownerIdx] && v10 == 1 && Random(1, 10) < 4 )
          ++v10;
        --v10;
        if ( v10 )
        {
          castle->buildingsBuiltFlags |= 0x100000u;
          --v10;
        }
        castle->mageGuildLevel = 0;
      }
      for ( i = 25; i <= 30; ++i )
      {
        if ( (1 << i) & castle->buildingsBuiltFlags )
        {
          if ( i == 30 )
            castle->buildingsBuiltFlags &= 0xDEFFFFFFu;
          else
            castle->buildingsBuiltFlags &= -1 - (1 << (i - 5));
        }
      }
      for ( i = 19; i <= 30; ++i )
      {
        if ( (1 << i) & castle->buildingsBuiltFlags )
          *(_WORD *)&castle[-1].name[2 * i + 5] = gMonsterDatabase[LOBYTE((&gTownObjNames[3 * castle->factionID + 27])[i + 1])].growth;
      }
      if ( castle->buildingsBuiltFlags & 1 )
      {
        for ( i = 1; castle->mageGuildLevel >= i; ++i )
        {
          castle->mageGuildSpells[4][i + 3] = mageGuildSpellsForLevel[i];
          if ( castle->factionID == 4 && BYTE1(castle->buildingsBuiltFlags) & 0x20 )
            ++castle->mageGuildSpells[4][i + 3];
        }
      }
      if ( *(_BYTE *)(v21 + 23) )
        castle->buildingsBuiltFlags |= 0x8000u;
      castle->mayNotBeUpgradedToCastle = *(_BYTE *)(v21 + 40);
      strcpy(castle->name, (char *)(v21 + 25));
      memset(spellPresent, 0, 0x41u);
      for ( j = 0; j < 5; ++j )
      {
        numSpellsOfLevel[j] = 0;
        for ( k = 0; k < 4; ++k )
          castle->mageGuildSpells[j][k] = -1;
      }
      if ( castle->factionID == FACTION_NECROMANCER && castle->ownerIdx != -1 && !gbHumanPlayer[castle->ownerIdx] )
      {
        if ( Random(0, 100) >= 50 )
          k = SPELL_DEATH_WAVE;
        else
          k = SPELL_DEATH_RIPPLE;
        j = gsSpellInfo[k].level - 1;
        castle->mageGuildSpells[j][numSpellsOfLevel[j]++] = k;
      }
      randNum = Random(0, 100);
      if ( randNum >= 25 )
      {
        if ( randNum >= 50 )
        {
          if ( randNum >= 75 )
            k = SPELL_CURE;
          else
            k = SPELL_ANTI_MAGIC;
        }
        else
        {
          k = SPELL_MASS_DISPEL;
        }
      }
      else
      {
        k = SPELL_DISPEL_MAGIC;
      }
      j = gsSpellInfo[k].level - 1;
      castle->mageGuildSpells[j][numSpellsOfLevel[j]++] = k;
      randNum = Random(0, 100);
      if ( randNum >= 20 )
      {
        if ( randNum >= 40 )
        {
          if ( randNum >= 60 )
          {
            if ( randNum >= 80 )
              k = SPELL_COLD_RING;
            else
              k = SPELL_COLD_RAY;
          }
          else
          {
            k = SPELL_FIREBALL;
          }
        }
        else
        {
          k = SPELL_LIGHTNING_BOLT;
        }
      }
      else
      {
        k = SPELL_MAGIC_ARROW;
      }
      j = gsSpellInfo[k].level - 1;
      castle->mageGuildSpells[j][numSpellsOfLevel[j]++] = k;
      for ( j = 0; j < 5; ++j )
      {
        hasAdventureSpellAtLevel = 0;
        for ( k = 0; k < 4; ++k )
        {
          if ( castle->mageGuildSpells[j][k] == -1 )
          {
            tries = 0;
            while ( 1 )
            {
              for ( spell = Random(0, 64); gsSpellInfo[spell].level - 1 != j; spell = Random(0, 64) )
                ;
              if ( castle->ownerIdx == -1 || gbHumanPlayer[castle->ownerIdx] )
                v11 = 1500;
              else
                v11 = *(_WORD *)&gsSpellInfo[spell].appearingChance
                    * ((unsigned __int8)(gsSpellInfo[spell].attributes & 1) < 1u ? 1 : 4)
                    + 50;
              if ( spell == SPELL_DIMENSION_DOOR )
                v11 = 1500;
              if ( hasAdventureSpellAtLevel != 1 || !(gsSpellInfo[spell].attributes & ATTR_ADVENTURE_SPELL) )
              {
                if ( *(&gsSpellInfo[spell].field_F + castle->factionID) >= Random(0, 10) )
                {
                  ++tries;
                  if ( tries <= 500 )
                  {
                    if ( !spellPresent[spell] && Random(1, 1500) <= v11 )
                      break;
                  }
                }
              }
            }
            if ( gsSpellInfo[spell].attributes & ATTR_ADVENTURE_SPELL )
              ++hasAdventureSpellAtLevel;
            castle->mageGuildSpells[j][k] = spell;
            spellPresent[spell] = 1;
          }
          else
          {
            spellPresent[castle->mageGuildSpells[j][k]] = 1;
          }
        }
      }
      BaseFree(*((void **)ppMapExtra + v25), (int)"F:\\h2xsrc\\Source\\GAME.CPP", word_4EF67C + 238);
      *((_DWORD *)ppMapExtra + v25) = 0;
    }
  }
}
{
  char *v1; // ST2C_4@31
  int v2; // [sp+14h] [bp-2Ch]@1
  int v3; // [sp+24h] [bp-1Ch]@30
  char *v4; // [sp+28h] [bp-18h]@1
  char *thisa; // [sp+2Ch] [bp-14h]@0
  char *v6; // [sp+30h] [bp-10h]@3
  signed int i; // [sp+38h] [bp-8h]@12
  signed int j; // [sp+38h] [bp-8h]@34
  signed int l; // [sp+38h] [bp-8h]@57
  signed int k; // [sp+3Ch] [bp-4h]@46

  v2 = this;
  v4 = (char *)&unk_512A40
     + 120 * *(_DWORD *)this
     + 15 * *(_DWORD *)(this + 4)
     + 5 * *(_BYTE *)(*(_DWORD *)(this + 4) + this + 55);
  memset(&gameObject->_3[375], 0, 0x41u);
  sprintf(gameObject->_5, "CAMP%d_%02d.HXC", *(_DWORD *)v2 + 1, *(_DWORD *)(v2 + 4) + 1);
  gameObject->_5[20] = 0;
  if ( !*(_DWORD *)(v2 + 4) )
    *(_WORD *)(v2 + 28) = 0;
  strcpy(byte_524740, gameObject->_5);
  sub_40B430((int)gameObject->_5, &gameObject->_1[676]);
  sub_41B5F0(gameObject, "origdata.bin", 1, 0);
  sub_45AA00((int)gameObject, 0);
  gameObject->difficulty = *(&byte_512C20[8 * *(_DWORD *)v2] + *(_DWORD *)(v2 + 4));
  gameObject->numPlayers = gameObject->_1[702];
  sub_41C580(gameObject, byte_524740);
  v6 = (char *)gameObject->players;
  switch ( *v4 )
  {
    case 0:
      *(_DWORD *)&v6[4 * *(_WORD *)(v4 + 1) + 143] += *(_WORD *)(v4 + 3);
      break;
    case 1:
      if ( gameObject->players[0].numHeroes > 0 )
        grantArtifact(&gameObject->heroes[gameObject->players[0].heroesOwned[0]], (ARTIFACT)*(_WORD *)(v4 + 1), 0, -1);
      break;
    case 2:
      if ( gameObject->players[0].numHeroes > 0 )
        gameObject->heroes[gameObject->players[0].heroesOwned[0]].spellsLearned[*(_WORD *)(v4 + 1)] = 1;
      break;
    case 3:
      if ( gameObject->players[0].numHeroes > 0 )
      {
        for ( i = 0; gameObject->players[0].numHeroes > i; ++i )
        {
          thisa = (char *)&gameObject->heroes[v6[i + 4]];
          if ( *(_DWORD *)v2 != 3 || *(_DWORD *)(v2 + 4) != 3 )
          {
            if ( *(_DWORD *)v2 != 3 || *(_DWORD *)(v2 + 4) != 2 || gameObject->heroes[v6[i + 4]].heroID == 67 )
              break;
          }
          else
          {
            if ( gameObject->heroes[v6[i + 4]].heroID == 65 )
              break;
          }
        }
        Hero::setSecondarySkillLevel((Hero *)thisa, *(_WORD *)(v4 + 1), *(_WORD *)(v4 + 3));
      }
      break;
    case 4:
      if ( gameObject->players[0].numHeroes > 0 )
        ArmyInfo::addCreatures(
          &gameObject->heroes[gameObject->players[0].heroesOwned[0]].army,
          *(_WORD *)(v4 + 1),
          *(_WORD *)(v4 + 3),
          -1);
      break;
    case 5:
      gameObject->players[0]._3[0] = v4[1];
      break;
    case 6:
      v3 = dword_523F1C;
      dword_523F1C = 1;
      if ( gameObject->players[0].numHeroes > 0 )
      {
        v1 = (char *)&gameObject->heroes[gameObject->players[0].heroesOwned[0]];
        *(_DWORD *)(v1 + 57) += *(_WORD *)(v4 + 1);
        Hero::checkForLevelUp(&gameObject->heroes[v6[4]]);
      }
      dword_523F1C = v3;
      break;
    case 9:
      if ( gameObject->players[0].numHeroes > 0 )
      {
        for ( j = 0; ; ++j )
        {
          if ( gameObject->players[0].numHeroes > j )
          {
            thisa = (char *)&gameObject->heroes[v6[j + 4]];
            if ( *(_DWORD *)v2 == 3 )
            {
              if ( *(_DWORD *)(v2 + 4) == 2 && gameObject->heroes[v6[j + 4]].heroID != 67 )
                continue;
            }
          }
          break;
        }
        thisa[*(_WORD *)(v4 + 1) + 63] += *(_WORD *)(v4 + 3);
      }
      break;
    case 0xA:
      if ( gameObject->players[0].numHeroes > 0 )
        grantArtifact(
          &gameObject->heroes[gameObject->players[0].heroesOwned[0]],
          ARTIFACT_SPELL_SCROLL,
          0,
          *(_WORD *)(v4 + 1));
      break;
    case 7:
      break;
  }
  for ( k = 0; k < 11; ++k )
  {
    if ( *(_BYTE *)(k + v2 + 44) )
    {
      switch ( k )
      {
        case 1:
          if ( v6[1] > 0 )
            grantArtifact(&gameObject->heroes[v6[4]], ARTIFACT_BREASTPLATE_OF_ANDURAN, 0, -1);
          break;
        case 3:
          if ( v6[1] > 0 )
            grantArtifact(&gameObject->heroes[v6[4]], ARTIFACT_HELMET_OF_ANDURAN, 0, -1);
          break;
        case 4:
          for ( l = 0; l < 54; ++l )
          {
            if ( gameObject->heroes[l].heroID == 61 )
              Hero::delete(&gameObject->heroes[l], 0);
          }
          break;
        case 5:
          if ( v6[1] > 0 )
            grantArtifact(&gameObject->heroes[v6[4]], ARTIFACT_BATTLE_GARB_OF_ANDURAN, 0, -1);
          break;
        case 8:
          if ( v6[1] > 0 )
            grantArtifact(&gameObject->heroes[v6[4]], ARTIFACT_LEGENDARY_SCEPTER, 0, -1);
          break;
        case 9:
          if ( v6[1] > 0 )
            gameObject->heroes[v6[4]].spellsLearned[61] = 1;
          break;
        case 10:
          if ( v6[1] > 0 )
            grantArtifact(&gameObject->heroes[v6[4]], ARTIFACT_SPHERE_OF_NEGATION, 0, -1);
          break;
        case 0:
        case 2:
        case 6:
        case 7:
          continue;
      }
    }
  }
  isRetreating = 1;
}

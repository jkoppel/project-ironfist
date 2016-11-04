{
  int v1; // ecx@18
  char *result; // eax@67
  int v3; // ST34_4@74
  double v5; // [sp+14h] [bp-30h]@61
  Hero *v6; // [sp+1Ch] [bp-28h]@88
  Hero *thisa; // [sp+24h] [bp-20h]@74
  int v8; // [sp+28h] [bp-1Ch]@74
  signed int v9; // [sp+2Ch] [bp-18h]@10
  signed int v10; // [sp+30h] [bp-14h]@10
  signed int i; // [sp+34h] [bp-10h]@3
  signed int j; // [sp+34h] [bp-10h]@57
  signed int k; // [sp+34h] [bp-10h]@68
  signed int playerIdx; // [sp+38h] [bp-Ch]@1
  signed int playerIdxa; // [sp+38h] [bp-Ch]@7
  signed int playerIdxb; // [sp+38h] [bp-Ch]@20
  int playerIdxc; // [sp+38h] [bp-Ch]@23
  signed int playerIdxd; // [sp+38h] [bp-Ch]@29
  signed int playerIdxe; // [sp+38h] [bp-Ch]@52
  signed int playerIdxf; // [sp+38h] [bp-Ch]@55
  signed int playerIdxg; // [sp+38h] [bp-Ch]@66
  signed int playerIdxh; // [sp+38h] [bp-Ch]@72
  signed int playerIdxi; // [sp+38h] [bp-Ch]@83
  int v24; // [sp+3Ch] [bp-8h]@74
  int v25; // [sp+3Ch] [bp-8h]@88

  for ( playerIdx = 0; gameObject->numPlayers > playerIdx; ++playerIdx )
  {
    for ( i = 0; i < 7; ++i )
      *(_DWORD *)&gameObject->players[playerIdx]._4[4 * i + 60] = -this->players[playerIdx].resources[i];
  }
  memset(&this->_7[72], 0, 9u);
  for ( playerIdxa = 0; playerIdxa < 144; ++playerIdxa )
  {
    if ( this->_8[7 * playerIdxa + 1] != -1 )
    {
      v9 = this->_8[7 * playerIdxa + 2];
      v10 = 0;
      if ( v9 == 2 )
      {
        v10 = 2;
      }
      else
      {
        if ( this->_8[7 * playerIdxa + 2] )
        {
          if ( v9 != 6 )
            v10 = 1;
        }
        else
        {
          v10 = 2;
        }
      }
      if ( v9 != 6 && v9 <= 6 )
      {
        v1 = 283 * this->_8[7 * playerIdxa + 1] + 4 * v9;
        *(int *)((char *)this->players[0].resources + v1) += v10;
      }
    }
  }
  for ( playerIdxb = 0; playerIdxb < 72; ++playerIdxb )
    ++this->castles[playerIdxb].field_55;
  for ( playerIdxc = 0; this->numPlayers > playerIdxc; ++playerIdxc )
  {
    this->players[playerIdxc].resources[3] += Player::quantityOfArtifactOwned(
                                                &this->players[playerIdxc],
                                                ARTIFACT_ENDLESS_POUCH_OF_SULFUR);
    this->players[playerIdxc].resources[1] += Player::quantityOfArtifactOwned(
                                                &this->players[playerIdxc],
                                                ARTIFACT_ENDLESS_VIAL_OF_MERCURY);
    this->players[playerIdxc].resources[5] += Player::quantityOfArtifactOwned(
                                                &this->players[playerIdxc],
                                                ARTIFACT_ENDLESS_POUCH_OF_GEMS);
    this->players[playerIdxc].resources[0] += Player::quantityOfArtifactOwned(
                                                &this->players[playerIdxc],
                                                ARTIFACT_ENDLESS_CORD_OF_WOOD);
    this->players[playerIdxc].resources[2] += Player::quantityOfArtifactOwned(
                                                &this->players[playerIdxc],
                                                ARTIFACT_ENDLESS_CART_OF_ORE);
    this->players[playerIdxc].resources[4] += Player::quantityOfArtifactOwned(
                                                &this->players[playerIdxc],
                                                ARTIFACT_ENDLESS_POUCH_OF_CRYSTAL);
    this->players[playerIdxc].resources[6] += GameInfo::computePlayerIncome(this, playerIdxc);
  }
  if ( byte_5304A0 && sub_470560(&unk_530450, 2) )
    this->players[0].resources[0] += 2;
  for ( playerIdxd = 0; this->numPlayers > playerIdxd; ++playerIdxd )
  {
    if ( !dword_524810[playerIdxd] )
    {
      if ( gameObject->difficulty >= 2 )
      {
        ++this->players[playerIdxd].resources[0];
        ++this->players[playerIdxd].resources[2];
      }
      if ( gameObject->difficulty >= 3 && this->day >= 1 && this->day <= 6 )
        ++*(_DWORD *)&this->players[playerIdxd].castlesOwned[4 * this->day + 68];
      if ( gameObject->difficulty >= 4 && this->day >= 1 && this->day <= 6 )
        ++*(_DWORD *)&this->players[playerIdxd].castlesOwned[4 * this->day + 68];
      if ( gameObject->players[playerIdxd].personality == 1 && this->day >= 1 && this->day <= 6 )
        ++*(_DWORD *)&this->players[playerIdxd].castlesOwned[4 * this->day + 68];
    }
  }
  ++this->day;
  dword_532C54 = this->day + 7 * (this->week - 1) + 28 * (this->month - 1);
  if ( !dword_4EF268 )
  {
    if ( this->day > 7 )
    {
      this->day = 1;
      sub_4251E0(this);
    }
    if ( this->week > 4 )
    {
      this->week = 1;
      sub_426D20((int)this);
    }
  }
  for ( playerIdxe = 0; playerIdxe < 54; ++playerIdxe )
    *(_DWORD *)&this->heroes[playerIdxe].flags1 &= 0xFFFEFFFFu;
  for ( playerIdxf = 0; gameObject->numPlayers > playerIdxf; ++playerIdxf )
  {
    for ( j = 0; j < 6; ++j )
    {
      if ( this->playerHandicap[playerIdxf] )
      {
        if ( this->playerHandicap[playerIdxf] == 1 )
          v5 = 0.15;
        else
          v5 = 0.3;
        this->players[playerIdxf].resources[j] -= (signed __int64)((double)(this->players[playerIdxf].resources[j]
                                                                          + *(_DWORD *)&gameObject->players[playerIdxf]._4[4 * j + 60])
                                                                 * v5);
      }
    }
  }
  for ( playerIdxg = 0; ; ++playerIdxg )
  {
    result = (char *)gameObject->numPlayers;
    if ( (signed int)result <= playerIdxg )
      break;
    for ( k = 0; k < 7; ++k )
      *(_DWORD *)&gameObject->players[playerIdxg]._4[4 * k + 60] += this->players[playerIdxg].resources[k];
  }
  for ( playerIdxh = 0; playerIdxh < 54; ++playerIdxh )
  {
    thisa = &this->heroes[playerIdxh];
    v3 = thisa->spellpoints;
    v24 = 10 * Hero::getPrimarySkill(thisa, PRIMARY_SKILL_KNOWLEDGE);
    v8 = this->heroes[playerIdxh].secondarySkillLevel[8] + 1 + v3;
    if ( Hero::hasArtifact(thisa, ARTIFACT_POWER_RING) )
      v8 += 2;
    if ( v8 > v24 )
      v8 = v24;
    if ( thisa->spellpoints < v8 )
      thisa->spellpoints = v8;
    result = (char *)&this->heroes[playerIdxh];
    if ( this->heroes[playerIdxh].flags2 & 0x10 )
    {
      result = (char *)(*(_DWORD *)&this->heroes[playerIdxh].flags1 - 4096);
      *(_DWORD *)&this->heroes[playerIdxh].flags1 = result;
    }
  }
  for ( playerIdxi = 0; playerIdxi < 72; ++playerIdxi )
  {
    result = (char *)&this->castles[playerIdxi];
    if ( this->castles[playerIdxi].buildingsBuiltFlags & 1 )
    {
      result = (char *)this->castles[playerIdxi].visitingHeroIdx;
      if ( result != (char *)-1 )
      {
        v6 = &this->heroes[this->castles[playerIdxi].visitingHeroIdx];
        v25 = 10 * Hero::getPrimarySkill(v6, PRIMARY_SKILL_KNOWLEDGE);
        result = (char *)v6->spellpoints;
        if ( (signed int)result < v25 )
        {
          result = (char *)v25;
          v6->spellpoints = v25;
        }
      }
    }
  }
  return result;
}

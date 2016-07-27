{
  int v6; // ebx@87
  Castle *v7; // eax@91
  Castle *castle; // [sp+74h] [bp-120h]@96
  Spell v10; // [sp+78h] [bp-11Ch]@0
  float v11; // [sp+7Ch] [bp-118h]@102
  signed int v12; // [sp+80h] [bp-114h]@107
  int v13; // [sp+80h] [bp-114h]@113
  float v14; // [sp+84h] [bp-110h]@102
  signed int v15; // [sp+88h] [bp-10Ch]@120
  int v16[46]; // [sp+8Ch] [bp-108h]@115
  Spell v17; // [sp+144h] [bp-50h]@101
  int v18; // [sp+148h] [bp-4Ch]@111
  int v19; // [sp+14Ch] [bp-48h]@87
  int v20; // [sp+150h] [bp-44h]@91
  int v21; // [sp+154h] [bp-40h]@98
  int v22; // [sp+158h] [bp-3Ch]@80
  int attack; // [sp+15Ch] [bp-38h]@80
  int numArchers; // [sp+160h] [bp-34h]@80
  float v25; // [sp+164h] [bp-30h]@1
  int v26; // [sp+168h] [bp-2Ch]@1
  float v27; // [sp+16Ch] [bp-28h]@17
  Spell i; // [sp+170h] [bp-24h]@120
  Spell spell; // [sp+174h] [bp-20h]@12
  int v30; // [sp+178h] [bp-1Ch]@1
  float v31; // [sp+17Ch] [bp-18h]@1
  float v32; // [sp+180h] [bp-14h]@1
  int fightValue; // [sp+184h] [bp-10h]@15
  Castle *this; // [sp+188h] [bp-Ch]@1
  int v35; // [sp+18Ch] [bp-8h]@1
  int v36; // [sp+190h] [bp-4h]@1

  v35 = 0;
  v30 = 0;
  v26 = 0;
  v31 = 0.89999998;
  v25 = 1.1;
  v32 = 0.75;
  v36 = 1036831949;
  this = 0;
  if ( a6 )
  {
    if ( Hero::hasArtifact(hero, ARTIFACT_BALLISTA_OF_QUICKNESS)
      || Hero::hasSpell(hero, SPELL_EARTHQUAKE)
      || hero->secondarySkillLevel[10] )
    {
      v25 = 1.05;
      v32 = 0.94999999;
    }
    if ( hero->secondarySkillLevel[1] || Hero::hasArtifact(hero, ARTIFACT_GOLDEN_BOW) )
      v31 = 1.05;
  }
  if ( a4 )
  {
    this = &gameObject->castles[a5];
    if ( !(gameObject->castles[a5].buildingsBuiltFlags & 0x40) )
      a4 = 0;
  }
  for ( spell = 0; (signed int)spell < 5; ++spell )
  {
    if ( army->creatureTypes[spell] != -1 )
    {
      fightValue = army->quantities[spell] * creature_table[army->creatureTypes[spell]].fight_value;
      if ( a3 )
      {
        if ( army->quantities[spell] <= 500 )
        {
          if ( army->quantities[spell] <= 300 )
          {
            if ( army->quantities[spell] <= 180 )
            {
              if ( army->quantities[spell] <= 140 )
              {
                if ( army->quantities[spell] <= 100 )
                {
                  if ( army->quantities[spell] <= 75 )
                  {
                    if ( army->quantities[spell] <= 50 )
                    {
                      if ( army->quantities[spell] <= 35 )
                      {
                        if ( army->quantities[spell] <= 23 )
                        {
                          if ( army->quantities[spell] <= 16 )
                          {
                            if ( army->quantities[spell] <= 11 )
                            {
                              if ( army->quantities[spell] <= 8 )
                              {
                                if ( army->quantities[spell] <= 5 )
                                {
                                  if ( army->quantities[spell] <= 3 )
                                  {
                                    if ( army->quantities[spell] <= 2 )
                                    {
                                      if ( army->quantities[spell] <= 2 )
                                        v27 = -0.57999998;
                                      else
                                        v27 = -0.40000001;
                                    }
                                    else
                                    {
                                      v27 = -0.30000001;
                                    }
                                  }
                                  else
                                  {
                                    v27 = -0.1;
                                  }
                                }
                                else
                                {
                                  v27 = 0.0;
                                }
                              }
                              else
                              {
                                v27 = 0.20999999;
                              }
                            }
                            else
                            {
                              v27 = 0.31999999;
                            }
                          }
                          else
                          {
                            v27 = 0.5;
                          }
                        }
                        else
                        {
                          v27 = 0.75;
                        }
                      }
                      else
                      {
                        v27 = 1.0;
                      }
                    }
                    else
                    {
                      v27 = 1.4;
                    }
                  }
                  else
                  {
                    v27 = 1.63;
                  }
                }
                else
                {
                  v27 = 2.0999999;
                }
              }
              else
              {
                v27 = 2.4200001;
              }
            }
            else
            {
              v27 = 3.0799999;
            }
          }
          else
          {
            v27 = 3.9000001;
          }
        }
        else
        {
          v27 = 4.4000001;
        }
        if ( creature_table[army->creatureTypes[spell]].creature_flags & SHOOTER
          || army->creatureTypes[spell] == CREATURE_VAMPIRE
          || army->creatureTypes[spell] == CREATURE_VAMPIRE_LORD
          || army->creatureTypes[spell] == CREATURE_SPRITE
          || army->creatureTypes[spell] == CREATURE_ROGUE
          || army->creatureTypes[spell] == CREATURE_HYDRA
          || army->creatureTypes[spell] == CREATURE_TROLL )
        {
          v27 = v27 * 0.7;
        }
        else
        {
          if ( army->creatureTypes[spell] == 14 )
          {
            v27 = v27 * 0.85;
          }
          else
          {
            if ( army->creatureTypes[spell] == 31 || army->creatureTypes[spell] == 59 )
              v27 = v27 * 1.2;
          }
        }
        fightValue = (signed __int64)((v27 + 1.0) * (double)fightValue);
        if ( a4 )
        {
          if ( creature_table[army->creatureTypes[spell]].creature_flags & 4 )
            fightValue = (signed __int64)((double)fightValue * 1.18);
          if ( creature_table[army->creatureTypes[spell]].creature_flags & 2 )
            fightValue = (signed __int64)((double)fightValue * 0.95);
        }
        if ( creature_table[army->creatureTypes[spell]].creature_flags & 4 && hero && hero->secondarySkillLevel[1] )
          fightValue = (signed __int64)((double)fightValue * flt_4F3B00[hero->secondarySkillLevel[1]]);
        if ( a6 )
        {
          if ( creature_table[army->creatureTypes[spell]].creature_flags & 4 )
            fightValue = (signed __int64)((double)fightValue * v31);
          if ( creature_table[army->creatureTypes[spell]].creature_flags & 2 )
            fightValue = (signed __int64)((double)fightValue * v25);
          else
            fightValue = (signed __int64)((double)fightValue * v32);
        }
      }
      v35 += fightValue;
    }
  }
  if ( a4 )
  {
    v22 = 0;
    Castle::retrieveBallistaStats(this, &numArchers, &attack);
    if ( BYTE1(this->buildingsBuiltFlags) & 1 )
      v22 += numArchers >> 1;
    if ( BYTE1(this->buildingsBuiltFlags) & 2 )
      v22 += numArchers >> 1;
    numArchers += v22;
    v26 = (signed __int64)(((double)attack * 0.1 + 1.0) * (double)(400 * numArchers));
  }
  if ( a3 && hero )
  {
    v6 = Hero::getPrimarySkill(hero, 0);
    v19 = Hero::getPrimarySkill(hero, PRIMARY_SKILL_DEFENSE) + v6 + 20;
    if ( v19 < 0 )
      v19 = 0;
    if ( v19 > 40 )
      v19 = 40;
    v35 = (signed __int64)((double)v35 * flt_4F28B0[v19]);
    v26 = (signed __int64)((double)v26 * flt_4F28B0[v19]);
    v7 = sub_498B70(hero);
    v20 = ArmyInfo::computeMorale(&hero->army, hero, v7, 0);
    if ( v20 <= 0 )
    {
      if ( v20 < 0 )
        v35 = v35 * (v20 + 24) / 24;
    }
    else
    {
      v35 = v35 * (v20 + 48) / 48;
    }
    if ( a4 )
      castle = this;
    else
      castle = 0;
    v21 = computeLuck(hero, 0, castle);
    if ( v21 )
      v35 = v35 * (v21 + 16) / 16;
    if ( hero->spellpoints >= 3 )
    {
      v17 = 0;
      if ( Hero::getPrimarySkill(hero, PRIMARY_SKILL_SPELLPOWER) > 10 )
      {
        v14 = *(float *)&dword_4F2AC0;
        v11 = *(float *)&dword_4F2A90;
      }
      else
      {
        v14 = *(float *)&dword_4F2A98[Hero::getPrimarySkill(hero, PRIMARY_SKILL_SPELLPOWER)];
        v11 = *(float *)&dword_4F2A68[Hero::getPrimarySkill(hero, PRIMARY_SKILL_SPELLPOWER)];
      }
      for ( spell = 0; (signed int)spell < 46; ++spell )
      {
        if ( Hero::hasSpell(hero, spell) )
        {
          v12 = *(_WORD *)&spell_table[spell].appearingChance;
          if ( spell_table[spell].attributes & 8 )
          {
            v12 = (signed __int64)((double)v12 * v14);
          }
          else
          {
            if ( spell_table[spell].attributes & 1 )
              v12 = (signed __int64)((double)v12 * v11);
          }
          v18 = hero->spellpoints / getSpellCost(spell, hero);
          if ( v18 > 10 )
            v18 = 10;
          v13 = (signed __int64)((double)v12 * flt_4F2A38[v18]);
          if ( v13 <= 0 )
            v13 = 1;
          v16[v17++] = v13;
        }
      }
      for ( spell = 0; (signed int)spell < 7 && spell < v17; ++spell )
      {
        v15 = 0;
        for ( i = 0; v17 > i; ++i )
        {
          if ( v16[i] > v15 )
          {
            v15 = v16[i];
            v10 = i;
          }
        }
        v30 = (signed __int64)((double)v15 * flt_4F2AC8[spell] + (double)v30);
        v16[v10] = 0;
      }
    }
  }
  if ( 2 * v35 >= v30 )
  {
    if ( (double)v30 <= (double)v35 * 1.5 )
    {
      if ( v35 < v30 )
        v30 = (signed __int64)((double)v35 * 0.75);
    }
    else
    {
      v30 = v35;
    }
  }
  else
  {
    v30 = (signed __int64)((double)v35 * 1.25);
  }
  if ( 2 * v35 >= v26 )
  {
    if ( (double)v26 <= (double)v35 * 1.5 )
    {
      if ( v35 < v26 )
        v26 = (signed __int64)((double)v35 * 0.9);
    }
    else
    {
      v26 = (signed __int64)((double)v35 * 1.25);
    }
  }
  else
  {
    v26 = (signed __int64)((double)v35 * 1.5);
  }
  if ( debugLogLevel == 9 )
    logUpTo7Ints((int)"FV3", v35, v30, v26, 0, 0, -999, -999);
  v35 += v30;
  v35 += v26;
  return v35;
}

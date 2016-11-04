{
  bool result; // eax@2
  Hero *v2; // esi@16
  __int16 v3; // fps@62
  unsigned __int8 v4; // c0@62
  unsigned __int8 v5; // c3@62
  CombatManager *thisa; // [sp+2Ch] [bp-148h]@1
  signed int v7; // [sp+34h] [bp-140h]@21
  signed int i; // [sp+38h] [bp-13Ch]@13
  int v9; // [sp+40h] [bp-134h]@43
  float v10; // [sp+44h] [bp-130h]@62
  signed int j; // [sp+48h] [bp-12Ch]@18
  signed int k; // [sp+48h] [bp-12Ch]@21
  signed int l; // [sp+48h] [bp-12Ch]@36
  ArmyInfo thisb; // [sp+4Ch] [bp-128h]@13
  Hero *v15; // [sp+5Ch] [bp-118h]@16
  ArmyInfo *army; // [sp+60h] [bp-114h]@16
  int v17[2]; // [sp+64h] [bp-110h]@35
  int v18; // [sp+6Ch] [bp-108h]@33
  int v19; // [sp+70h] [bp-104h]@68
  float v20; // [sp+74h] [bp-100h]@46
  Hero hero; // [sp+78h] [bp-FCh]@13

  thisa = this;
  if ( this->castles[this->currentActionSide] )
  {
    result = 0;
  }
  else
  {
    if ( this->heroes[this->currentActionSide] )
    {
      if ( this->heroes[this->currentActionSide]->field_E7[0] )
      {
        result = 0;
      }
      else
      {
        if ( gameObject->winConditionType != 2
          || this->heroes[this->currentActionSide]->field_2 != gameObject->winConditionArgument )
        {
          if ( gameObject->players[this->heroes[this->currentActionSide]->probablyOwnerIdx].numCastles
            || gameObject->players[this->heroes[this->currentActionSide]->probablyOwnerIdx].numHeroes != 1 )
          {
            Hero_constructor(&hero);
            ArmyInfo_constructor(&thisb);
            for ( i = 0; i < 2; ++i )
            {
              if ( thisa->heroes[i] )
              {
                v2 = thisa->heroes[i];
                memcpy(&hero, v2, 0xF8u);
                *(_WORD *)&hero.scrollSpell[12] = *(_WORD *)&v2->scrollSpell[12];
                v15 = &hero;
                army = &hero.army;
              }
              else
              {
                army = &thisb;
                v15 = 0;
              }
              for ( j = 0; j < 5; ++j )
              {
                army->creatureTypes[j] = -1;
                army->quantities[j] = 0;
              }
              v7 = 0;
              for ( k = 0; k < 20; ++k )
              {
                if ( thisa->creatures[i][k].creatureIdx >= 0 && thisa->creatures[i][k].quantity > 0 )
                {
                  army->creatureTypes[v7] = LOBYTE(thisa->creatures[i][k].creatureIdx);
                  if ( thisa->creatures[i][k].creature.creature_flags & 0x80 )
                    army->quantities[v7] = thisa->creatures[i][k].quantity;
                  else
                    army->quantities[v7] = (signed __int64)((double)thisa->creatures[i][k].quantity * 1.2);
                  ++v7;
                }
                if ( v7 >= 5 )
                  k = 999;
              }
              *(&v18 + i) = getArmyStrength(army, v15, 1, 0, 0, 0);
              if ( thisa->castles[i] )
                *(&v18 + i) = (signed __int64)((double)*(&v18 + i) * 1.1);
              v17[i] = 0;
              if ( v15 )
              {
                for ( l = 0; l < 14; ++l )
                {
                  if ( v15->artifacts[l] >= 0 && v15->artifacts[l] < 37 )
                    v17[i] += dword_4F2050[v15->artifacts[l]];
                }
              }
            }
            *(&v18 + 1 - thisa->currentActionSide) = (signed __int64)((double)*(&v18 + 1 - thisa->currentActionSide)
                                                                    * 1.1);
            v9 = v17[thisa->currentActionSide];
            if ( v17[thisa->currentActionSide] >= 1000 || thisa->heroes[thisa->currentActionSide]->experience >= 2000 )
            {
              v20 = 0.16;
              if ( v9 <= 10000 )
              {
                if ( v9 <= 5000 )
                {
                  if ( v9 > 0 )
                    v20 = v20 + 0.04;
                }
                else
                {
                  v20 = v20 + 0.05;
                }
              }
              else
              {
                v20 = v20 + 0.06;
              }
              if ( *(&v18 + thisa->currentActionSide) <= 40000 )
              {
                if ( *(&v18 + thisa->currentActionSide) <= 30000 )
                {
                  if ( *(&v18 + thisa->currentActionSide) <= 15000 )
                  {
                    if ( *(&v18 + thisa->currentActionSide) <= 5000 )
                    {
                      if ( *(&v18 + thisa->currentActionSide) > 2500 )
                        v20 = v20 - 0.02;
                    }
                    else
                    {
                      v20 = v20 - 0.04;
                    }
                  }
                  else
                  {
                    v20 = v20 - 0.06;
                  }
                }
                else
                {
                  v20 = v20 - 0.08;
                }
              }
              else
              {
                v20 = v20 - (double)(*(&v18 + thisa->currentActionSide) / 20000);
              }
              v20 = v20 - (double)(4 - (signed int)gameObject->difficulty) * 0.015;
              UNDEF(v3);
              v10 = (double)(thisa->heroes[thisa->currentActionSide]->experience / 200000);
              if ( !(v4 | v5) )
                v10 = 0.029999999;
              v20 = v20 + v10;
              if ( !thisa->currentActionSide )
                v20 = v20 - 0.06;
              if ( v20 > 0.16 )
                v20 = 0.16;
              result = (double)*(&v18 + thisa->currentActionSide) / (double)(v18 + v19) < v20;
            }
            else
            {
              result = 0;
            }
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          result = 0;
        }
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

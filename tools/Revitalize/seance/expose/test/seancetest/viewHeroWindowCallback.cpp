signed int __thiscall viewHeroWindowCallback(InputEvent *this)
{
  signed int result; // eax@6
  char v2; // al@48
  int v3; // ST7C_4@49
  int v4; // ST58_4@49
  __int16 v5; // ST94_2@79
  signed int v6; // eax@100
  int v7; // [sp+10h] [bp-5Ch]@21
  int v8; // [sp+14h] [bp-58h]@19
  int v9; // [sp+18h] [bp-54h]@14
  int v10; // [sp+1Ch] [bp-50h]@9
  InputEvent *thisa; // [sp+20h] [bp-4Ch]@1
  int a7; // [sp+24h] [bp-48h]@62
  int v13; // [sp+54h] [bp-18h]@92
  int a13; // [sp+58h] [bp-14h]@50
  signed int v15; // [sp+60h] [bp-Ch]@1
  char v16; // [sp+64h] [bp-8h]@73
  signed int a2; // [sp+68h] [bp-4h]@2

  thisa = this;
  v15 = 0;
  if ( BYTE1(this->inputTypeBitmask) & 2 )
    a2 = 1;
  else
    a2 = 0;
  if ( this->eventCode == 4 )
  {
    HeroWindowManager::handleInputThunk(HeroWindowManager::instance, this);
    if ( HeroWindowManager::instance->field_5E == thisa->yCoord )
    {
      result = 1;
    }
    else
    {
      HeroWindowManager::instance->field_5E = thisa->yCoord;
      sub_4966D0((Hero *)thisa);
      result = 1;
    }
    return result;
  }
  if ( this->eventCode == 2 )
  {
    v10 = this->xCoordOrKeycode;
    if ( v10 == 42 || v10 == 54 )
    {
      HeroWindowManager::instance->field_5E = -1;
      sub_4D1570();
    }
  }
  if ( thisa->eventCode == 1 )
  {
    v9 = thisa->xCoordOrKeycode;
    if ( v9 == 42 || v9 == 54 )
    {
      HeroWindowManager::instance->field_5E = -1;
      sub_4D1570();
    }
  }
  if ( thisa->eventCode == 512 )
  {
    v8 = thisa->xCoordOrKeycode;
    if ( v8 == 12 )
      goto LABEL_112;
    if ( v8 == 13 )
    {
      if ( !a2 )
      {
        v7 = thisa->yCoord;
        if ( v7 > 30720 )
        {
          if ( v7 == 30723 && Hero::dismissButtonPressed(viewedHero) )
            v15 = 1;
        }
        else
        {
          if ( v7 == 30720 )
          {
            v15 = 1;
          }
          else
          {
            if ( v7 >= 300 && v7 <= 301 && viewedHero->probablyOwnerIdx == curPlayerIdx && curPlayer->numHeroes > 1 )
            {
              viewedHero = &gameObject->heroes[curPlayer->heroesOwned[(sub_42D980((int)curPlayer, viewedHero->field_2)
                                                                     + curPlayer->numHeroes
                                                                     + ((unsigned int)(thisa->yCoord - 300) < 1 ? -1 : 1))
                                                                    % curPlayer->numHeroes]];
              sub_497B90();
              sub_497920();
            }
          }
        }
      }
      goto LABEL_107;
    }
    if ( v8 == 14 )
    {
LABEL_112:
      switch ( thisa->yCoord )
      {
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
          displayPrimarySkillDescription(thisa->yCoord - 81, a2);
          break;
        case 0xC8:
        case 0xC9:
        case 0xCA:
          sub_434D70((int)viewedHero, (unsigned int)a2 < 1 ? 1 : 4);
          break;
        case 0xCB:
        case 0xCC:
        case 0xCD:
          sub_435370((int)viewedHero, (unsigned int)a2 < 1 ? 1 : 4);
          break;
        case 0xD6:
          if ( a2 )
          {
            display_message_window(
              "{Spread Formation}\n\n'Spread' combat formation spreads your armies from the top to the bottom of the battlefield, with at least one empty space between each army.",
              4,
              -1,
              -1,
              -1,
              0,
              -1,
              0,
              -1,
              0);
          }
          else
          {
            *(_DWORD *)&viewedHero->flags1 &= 0xFFFF7FFFu;
            sub_497B90();
            sub_497920();
          }
          break;
        case 0xD8:
          if ( a2 )
          {
            display_message_window(
              "{Grouped Formation}\n\n'Grouped' combat formation bunches your army together in the center of your side of the battlefield.",
              4,
              -1,
              -1,
              -1,
              0,
              -1,
              0,
              -1,
              0);
          }
          else
          {
            *(_DWORD *)&viewedHero->flags1 |= 0x8000u;
            sub_497B90();
            sub_497920();
          }
          break;
        case 0xD3:
        case 0xD4:
          v2 = Hero::getPrimarySkill(viewedHero, PRIMARY_SKILL_KNOWLEDGE);
          sprintf(
            globBuf,
            "{Spell Points}\n\n%s currently has %d spell points out of a maximum of %d.  The maximum number of spell points is 10 times your knowledge.  It is occasionally possible to have more than your maximum spell points via special events.",
            viewedHero->name,
            viewedHero->spellpoints,
            10 * v2);
          display_message_window(globBuf, (unsigned int)a2 < 1 ? 1 : 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 0xCE:
        case 0xCF:
          v3 = levelForXP(viewedHero->experience);
          v4 = experienceForLevel(v3 + 1);
          sprintf(globBuf, "{Level %d}\n\nCurrent experience %d\nNext level %d", v3, viewedHero->experience, v4);
          display_message_window(globBuf, (unsigned int)a2 < 1 ? 1 : 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 0x66:
        case 0x67:
        case 0x68:
        case 0x69:
        case 0x6A:
          a13 = thisa->yCoord - 102;
          if ( a2 || dword_523428 != -1 )
          {
            if ( (!a2 || viewedHero->army.creatureTypes[a13] == -1) && (a2 || thisa->yCoord - 102 != dword_523428) )
            {
              if ( a2 || !townManager->field_15A )
              {
                if ( !a2 )
                {
                  v16 = viewedHero->army.creatureTypes[a13];
                  if ( thisa->inputTypeBitmask & 3
                    && (viewedHero->army.creatureTypes[a13] == -1
                     || viewedHero->army.creatureTypes[dword_523428] == viewedHero->army.creatureTypes[a13]) )
                  {
                    split_stack(a13, dword_523428);
                  }
                  else
                  {
                    if ( viewedHero->army.creatureTypes[dword_523428] == viewedHero->army.creatureTypes[a13] )
                    {
                      viewedHero->army.quantities[a13] += viewedHero->army.quantities[dword_523428];
                      viewedHero->army.quantities[dword_523428] = 0;
                      viewedHero->army.creatureTypes[dword_523428] = -1;
                    }
                    else
                    {
                      viewedHero->army.creatureTypes[a13] = viewedHero->army.creatureTypes[dword_523428];
                      viewedHero->army.creatureTypes[dword_523428] = v16;
                      v5 = viewedHero->army.quantities[a13];
                      viewedHero->army.quantities[a13] = viewedHero->army.quantities[dword_523428];
                      viewedHero->army.quantities[dword_523428] = v5;
                    }
                  }
                  dword_523428 = -1;
                  sub_4951F0(viewedHero);
                }
              }
              else
              {
                if ( viewedHero->army.creatureTypes[a13] != -1 )
                {
                  dword_523428 = thisa->yCoord - 102;
                  sub_4951F0(viewedHero);
                }
              }
            }
            else
            {
              a7 = a2 || townManager->field_15A == 1 || ArmyInfo::getNumStacks(&viewedHero->army) == 1;
              GameInfo::showStackInfo(
                gameObject,
                119,
                20,
                (CREATURES)viewedHero->army.creatureTypes[a13],
                viewedHero->army.quantities[a13],
                0,
                a7,
                1u,
                a2,
                viewedHero,
                0,
                &viewedHero->army,
                a13);
              if ( !a2 )
                dword_523428 = -1;
              sub_497B90();
              sub_497920();
            }
          }
          else
          {
            if ( viewedHero->army.creatureTypes[a13] != -1 )
            {
              dword_523428 = thisa->yCoord - 102;
              sub_4951F0(viewedHero);
            }
          }
          if ( !a2 )
          {
            HeroWindowManager::instance->field_5E = -1;
            sub_4966D0((Hero *)thisa);
          }
          break;
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
          if ( viewedHero->spellsLearned[thisa->yCoord + 45] != -1 )
          {
            if ( a2 || viewedHero->spellsLearned[thisa->yCoord + 45] != 81 )
              displayArtifactDescription(
                (ARTIFACT)viewedHero->spellsLearned[thisa->yCoord + 45],
                a2,
                viewedHero->artifacts[thisa->yCoord + 3]);
            else
              GameInfo::open_spellbook(gameObject, viewedHero, SPELL_CATEGORY_ALL, (int)sub_422530, 1);
          }
          break;
        default:
          if ( thisa->yCoord < 400 || thisa->yCoord >= 408 )
          {
            if ( thisa->yCoord < 408 || thisa->yCoord >= 416 )
            {
              if ( thisa->yCoord < 416 || thisa->yCoord >= 424 )
                break;
              v13 = thisa->yCoord - 416;
            }
            else
            {
              v13 = thisa->yCoord - 408;
            }
          }
          else
          {
            v13 = thisa->yCoord - 400;
          }
          if ( viewedHero->numSecSkillsKnown > v13 )
          {
            v6 = sub_498B10(viewedHero, v13);
            Hero::showSecondarySkillDecription(viewedHero, (SECONDARY_SKILL)v6, a2);
          }
          break;
      }
    }
  }
LABEL_107:
  if ( v15 )
  {
    HeroWindowManager::instance->buttonPressedCode = thisa->yCoord;
    thisa->yCoord = 10;
    thisa->xCoordOrKeycode = thisa->yCoord;
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}

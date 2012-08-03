{
  signed int result; // eax@3
  char v2; // al@45
  int v3; // ST7C_4@46
  int v4; // ST58_4@46
  __int16 v5; // ST94_2@76
  signed int v6; // eax@97
  int v7; // [sp+10h] [bp-5Ch]@18
  int v8; // [sp+14h] [bp-58h]@16
  int v9; // [sp+18h] [bp-54h]@11
  int v10; // [sp+1Ch] [bp-50h]@6
  tag_message *thisa; // [sp+20h] [bp-4Ch]@1
  int a7; // [sp+24h] [bp-48h]@59
  int v13; // [sp+54h] [bp-18h]@89
  int a13; // [sp+58h] [bp-14h]@47
  signed int v15; // [sp+60h] [bp-Ch]@1
  char v16; // [sp+64h] [bp-8h]@70
  bool a2; // [sp+68h] [bp-4h]@1

  thisa = this;
  v15 = 0;
  a2 = (BYTE1(this->inputTypeBitmask) & 2) != 0;
  if ( this->eventCode == 4 )
  {
    heroWindowManager::ConvertToHover(gpWindowManager, this);
    if ( gpWindowManager->field_5E == thisa->yCoord )
    {
      result = 1;
    }
    else
    {
      gpWindowManager->field_5E = thisa->yCoord;
      UpdateHeroScreenStatusBar((hero *)thisa);
      result = 1;
    }
    return result;
  }
  if ( this->eventCode == 2 )
  {
    v10 = this->xCoordOrKeycode;
    if ( v10 == 42 || v10 == 54 )
    {
      gpWindowManager->field_5E = -1;
      inputManager::ForceMouseMove();
    }
  }
  if ( thisa->eventCode == 1 )
  {
    v9 = thisa->xCoordOrKeycode;
    if ( v9 == 42 || v9 == 54 )
    {
      gpWindowManager->field_5E = -1;
      inputManager::ForceMouseMove();
    }
  }
  if ( thisa->eventCode == 512 )
  {
    v8 = thisa->xCoordOrKeycode;
    if ( v8 == 12 )
      goto LABEL_109;
    if ( v8 == 13 )
    {
      if ( !a2 )
      {
        v7 = thisa->yCoord;
        if ( v7 > 30720 )
        {
          if ( v7 == 30723 && hero::Dismiss(gpHVHero) )
            v15 = 1;
        }
        else if ( v7 == 30720 )
        {
          v15 = 1;
        }
        else if ( v7 >= 300 && v7 <= 301 && gpHVHero->probablyOwnerIdx == giCurPlayer && gpCurPlayer->numHeroes > 1 )
        {
          gpHVHero = &gpGame->heroes[gpCurPlayer->heroesOwned[(game::HeroIDToHeroPos(
                                                                 (int)gpCurPlayer,
                                                                 gpHVHero->couldBeHeroIdx)
                                                             + gpCurPlayer->numHeroes
                                                             + ((unsigned int)(thisa->yCoord - 300) < 1 ? -1 : 1))
                                                            % gpCurPlayer->numHeroes]];
          SetupHeroView();
          RedrawHeroScreen();
        }
      }
      goto LABEL_104;
    }
    if ( v8 == 14 )
    {
LABEL_109:
      switch ( thisa->yCoord )
      {
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
          hero::ViewStat(thisa->yCoord - 81, a2);
          break;
        case 0xC8:
        case 0xC9:
        case 0xCA:
          game::ShowMoraleInfo((int)gpHVHero, (unsigned int)a2 < 1 ? 1 : 4);
          break;
        case 0xCB:
        case 0xCC:
        case 0xCD:
          game::ShowLuckInfo((int)gpHVHero, (unsigned int)a2 < 1 ? 1 : 4);
          break;
        case 0xD6:
          if ( a2 )
          {
            NormalDialog(
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
            *(_DWORD *)&gpHVHero->flags1 &= 0xFFFF7FFFu;
            SetupHeroView();
            RedrawHeroScreen();
          }
          break;
        case 0xD8:
          if ( a2 )
          {
            NormalDialog(
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
            *(_DWORD *)&gpHVHero->flags1 |= 0x8000u;
            SetupHeroView();
            RedrawHeroScreen();
          }
          break;
        case 0xD3:
        case 0xD4:
          v2 = hero::Stats(gpHVHero, PRIMARY_SKILL_KNOWLEDGE);
          sprintf(
            gText,
            "{Spell Points}\n\n%s currently has %d spell points out of a maximum of %d.  The maximum number of spell points is 10 times your knowledge.  It is occasionally possible to have more than your maximum spell points via special events.",
            gpHVHero->name,
            gpHVHero->spellpoints,
            10 * v2);
          NormalDialog(gText, (unsigned int)a2 < 1 ? 1 : 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 0xCE:
        case 0xCF:
          v3 = hero::GetLevel(gpHVHero->experience);
          v4 = hero::GetExperience(v3 + 1);
          sprintf(gText, "{Level %d}\n\nCurrent experience %d\nNext level %d", v3, gpHVHero->experience, v4);
          NormalDialog(gText, (unsigned int)a2 < 1 ? 1 : 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 0x66:
        case 0x67:
        case 0x68:
        case 0x69:
        case 0x6A:
          a13 = thisa->yCoord - 102;
          if ( a2 || giHeroScreenSrcIndex != -1 )
          {
            if ( (!a2 || gpHVHero->army.creatureTypes[a13] == -1) && (a2 || thisa->yCoord - 102 != giHeroScreenSrcIndex) )
            {
              if ( a2 || !gpTownManager->field_15A )
              {
                if ( !a2 )
                {
                  v16 = gpHVHero->army.creatureTypes[a13];
                  if ( thisa->inputTypeBitmask & 3
                    && (gpHVHero->army.creatureTypes[a13] == -1
                     || gpHVHero->army.creatureTypes[giHeroScreenSrcIndex] == gpHVHero->army.creatureTypes[a13]) )
                  {
                    DoHeroSplit(a13, giHeroScreenSrcIndex);
                  }
                  else if ( gpHVHero->army.creatureTypes[giHeroScreenSrcIndex] == gpHVHero->army.creatureTypes[a13] )
                  {
                    gpHVHero->army.quantities[a13] += gpHVHero->army.quantities[giHeroScreenSrcIndex];
                    gpHVHero->army.quantities[giHeroScreenSrcIndex] = 0;
                    gpHVHero->army.creatureTypes[giHeroScreenSrcIndex] = -1;
                  }
                  else
                  {
                    gpHVHero->army.creatureTypes[a13] = gpHVHero->army.creatureTypes[giHeroScreenSrcIndex];
                    gpHVHero->army.creatureTypes[giHeroScreenSrcIndex] = v16;
                    v5 = gpHVHero->army.quantities[a13];
                    gpHVHero->army.quantities[a13] = gpHVHero->army.quantities[giHeroScreenSrcIndex];
                    gpHVHero->army.quantities[giHeroScreenSrcIndex] = v5;
                  }
                  giHeroScreenSrcIndex = -1;
                  hero::HeroScreenUpdate(gpHVHero);
                }
              }
              else if ( gpHVHero->army.creatureTypes[a13] != -1 )
              {
                giHeroScreenSrcIndex = thisa->yCoord - 102;
                hero::HeroScreenUpdate(gpHVHero);
              }
            }
            else
            {
              a7 = a2 || gpTownManager->field_15A == 1 || armyGroup::GetNumArmies(&gpHVHero->army) == 1;
              game::ViewArmy(
                gpGame,
                119,
                20,
                (CREATURES)gpHVHero->army.creatureTypes[a13],
                gpHVHero->army.quantities[a13],
                0,
                a7,
                1u,
                a2,
                gpHVHero,
                0,
                &gpHVHero->army,
                a13);
              if ( !a2 )
                giHeroScreenSrcIndex = -1;
              SetupHeroView();
              RedrawHeroScreen();
            }
          }
          else if ( gpHVHero->army.creatureTypes[a13] != -1 )
          {
            giHeroScreenSrcIndex = thisa->yCoord - 102;
            hero::HeroScreenUpdate(gpHVHero);
          }
          if ( !a2 )
          {
            gpWindowManager->field_5E = -1;
            UpdateHeroScreenStatusBar((hero *)thisa);
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
          if ( gpHVHero->spellsLearned[thisa->yCoord + 45] != -1 )
          {
            if ( a2 || gpHVHero->spellsLearned[thisa->yCoord + 45] != 81 )
              hero::ViewArtifact(
                (ARTIFACT)gpHVHero->spellsLearned[thisa->yCoord + 45],
                a2,
                gpHVHero->artifacts[thisa->yCoord + 3]);
            else
              game::ViewSpells(gpGame, gpHVHero, 2, (int (__fastcall *)(struct tag_message *))ViewSpecialHandler, 1);
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
          if ( gpHVHero->numSecSkillsKnown > v13 )
          {
            v6 = hero::GetNthSS(gpHVHero, v13);
            hero::DoSSLevelDialog(gpHVHero, (SECONDARY_SKILL)v6, a2);
          }
          break;
      }
    }
  }
LABEL_104:
  if ( v15 )
  {
    gpWindowManager->buttonPressedCode = thisa->yCoord;
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
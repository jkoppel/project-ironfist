{
  __int16 v4; // ax@78
  __int16 v5; // ax@78
  __int16 v6; // ax@78
  char v7; // al@107
  unsigned __int16 v8; // ax@141
  __int16 v9; // ax@142
  __int16 v10; // ax@142
  __int16 v11; // ax@142
  __int16 v12; // ax@177
  int v13; // ST28_4@177
  __int16 v14; // ax@177
  __int16 v15; // ax@177
  int v16; // ST38_4@177
  __int16 v17; // ax@177
  __int16 v18; // ax@183
  __int16 v19; // ax@184
  int v20; // ST2C_4@184
  __int16 v21; // ax@184
  __int16 v22; // ax@184
  int v23; // ST38_4@184
  __int16 v24; // ax@184
  unsigned __int16 v25; // ax@191
  __int16 v26; // ax@195
  __int16 v27; // ax@195
  int v28; // ebx@306
  char v29; // al@335
  int v30; // ebx@349
  int v31; // ebx@364
  __int16 v32; // ax@370
  __int16 v33; // ax@370
  __int16 v34; // ax@413
  int v35; // eax@402
  int v36; // eax@409
  __int16 v37; // ax@436
  unsigned __int16 v38; // ax@438
  __int16 v39; // ax@453
  unsigned __int16 v40; // ax@441
  unsigned __int16 v41; // ax@444
  unsigned __int16 v42; // ax@445
  unsigned __int16 v43; // ax@454
  unsigned __int16 v44; // ax@461
  unsigned __int16 v45; // ax@472
  unsigned __int16 v46; // ax@483
  char v47; // al@497
  signed int v48; // [sp+14h] [bp-33Ch]@306
  advManager *thisa; // [sp+24h] [bp-32Ch]@1
  int v50; // [sp+2Ch] [bp-324h]@230
  int amt; // [sp+30h] [bp-320h]@227
  heroWindow *thisb; // [sp+38h] [bp-318h]@324
  char msg[4]; // [sp+44h] [bp-30Ch]@494
  int v54; // [sp+238h] [bp-118h]@482
  int v55; // [sp+23Ch] [bp-114h]@471
  void *v56; // [sp+240h] [bp-110h]@417
  signed int level; // [sp+244h] [bp-10Ch]@306
  int xp; // [sp+248h] [bp-108h]@306
  signed int a13; // [sp+24Ch] [bp-104h]@275
  int v60; // [sp+250h] [bp-100h]@123
  int v61; // [sp+254h] [bp-FCh]@118
  int maxSP; // [sp+258h] [bp-F8h]@113
  int v63; // [sp+25Ch] [bp-F4h]@107
  int a8; // [sp+260h] [bp-F0h]@16
  int a7; // [sp+264h] [bp-ECh]@16
  signed int img1Type; // [sp+268h] [bp-E8h]@16
  signed int a6; // [sp+26Ch] [bp-E4h]@16
  int v68; // [sp+270h] [bp-E0h]@10
  char *v69; // [sp+274h] [bp-DCh]@120
  int v70; // [sp+278h] [bp-D8h]@343
  signed int type; // [sp+27Ch] [bp-D4h]@226
  int a2a; // [sp+280h] [bp-D0h]@325
  int v73; // [sp+284h] [bp-CCh]@379
  int i; // [sp+288h] [bp-C8h]@343
  int j; // [sp+28Ch] [bp-C4h]@345
  int a5; // [sp+290h] [bp-C0h]@370
  unsigned int v77; // [sp+294h] [bp-BCh]@370
  unsigned int v78; // [sp+298h] [bp-B8h]@436
  void *v79; // [sp+29Ch] [bp-B4h]@415
  int v80; // [sp+2A0h] [bp-B0h]@419
  int v81; // [sp+2A4h] [bp-ACh]@7
  int v82; // [sp+2A8h] [bp-A8h]@127
  int v83; // [sp+2ACh] [bp-A4h]@370
  GUIMessage evt; // [sp+2B0h] [bp-A0h]@329
  int locType; // [sp+2CCh] [bp-84h]@1
  int v86; // [sp+2ECh] [bp-64h]@1
  char a1; // [sp+2F0h] [bp-60h]@10
  int v88; // [sp+324h] [bp-2Ch]@34
  int v89; // [sp+328h] [bp-28h]@34
  int v90; // [sp+32Ch] [bp-24h]@1
  int a2; // [sp+330h] [bp-20h]@10
  int v92; // [sp+334h] [bp-1Ch]@424
  int v93; // [sp+338h] [bp-18h]@34
  hero *hero; // [sp+33Ch] [bp-14h]@1
  sample_resource res; // [sp+340h] [bp-10h]@1
  int a3a[2]; // [sp+348h] [bp-8h]@1

  thisa = this;
  hero = &gpGame->heroes[gpCurPlayer->curHeroIdx];
  locType = loc->objType & 0x7F;
  v86 = 0;
  v90 = 0;
  res = NULL_SAMPLE2;
  mouseManager::ShowColorPointer(gpMouseManager);
  mouseManager::SetPointer(gpMouseManager, 0);
  *(_QWORD *)a3a = NULL_SAMPLE2;
  switch ( locType )
  {
    case LOCATION_TRADING_POST:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      DoTradingPost(0, 1045220557);
      goto LABEL_511;
    case LOCATION_MAGIC_GARDEN:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(
          -1,
          1,
          "{Magic Garden}\n\nYou catch a leprechaun foolishly sleeping amidst a cluster of magic mushrooms.  In exchange for his freedom, he guides you to a small pot filled with precious things.",
          (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1,
          (unsigned int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 7 < 1 ? 500 : 5,
          -1,
          0,
          -1);
        advManager::GiveResource(
          thisa,
          hero,
          (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1,
          (unsigned int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 7 < 1 ? 500 : 5);
        loc->flags &= 7u;
      }
      else
      {
        advManager::EventWindow(
          -1,
          1,
          "{Magic Garden}\n\nYou've found a magic garden, the kind of place that leprechauns and faeries like to cavort in, but there is no one here today.  Perhaps you should try again next week.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_511;
    case LOCATION_SPHINX:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      v81 = *((_DWORD *)ppMapExtra + (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5));
      if ( *(_BYTE *)v81 )
      {
        sprintf(
          gText,
          "\"I have a riddle for you,\" the Sphinx says.  \"Answer correctly, and you shall be rewarded.  Answer incorrectly, and you shall be eaten.  Do you accept the challenge?\"");
        NormalDialog(gText, 2, -1, -1, -1, 0, -1, 0, -1, 0);
        if ( gpWindowManager->buttonPressedCode == 0x7805 )
        {
          sprintf(gText, "The Sphinx asks you the following riddle:\n\n'%s'\n\nYour answer?", v81 + 136);
          GetDataEntry(gText, (int)&a1, 12, 0, 0, 1);
          v68 = 0;
          for ( a2 = 0; *(_BYTE *)(v81 + 31) > a2; ++a2 )
          {
            if ( RiddleStringsEqual(&a1, (const char *)(13 * a2 + v81 + 32)) )
              v68 = 1;
          }
          if ( v68 )
          {
            img1Type = -1;
            a6 = 0;
            a7 = -1;
            a8 = 0;
            for ( a2 = 0; a2 < 7; ++a2 )
            {
              gpGame->players[giCurPlayer].resources[a2] += *(_DWORD *)(v81 + 4 * a2 + 1);
              if ( gpGame->players[giCurPlayer].resources[a2] < 0 )
                gpGame->players[giCurPlayer].resources[a2] = 0;
              if ( *(_DWORD *)(v81 + 4 * a2 + 1) )
              {
                if ( img1Type != -1 )
                {
                  a7 = img1Type;
                  a8 = a6;
                }
                img1Type = a2;
                a6 = *(_DWORD *)(v81 + 4 * a2 + 1);
              }
            }
            if ( *(_WORD *)(v81 + 29) != -1 && hero::NumArtifacts(hero) < 14 )
            {
              GiveArtifact(hero, (ARTIFACT)*(_WORD *)(v81 + 29), 1, -1);
              if ( img1Type != -1 )
              {
                a7 = img1Type;
                a8 = a6;
              }
              img1Type = 7;
              a6 = *(_WORD *)(v81 + 29);
            }
            NormalDialog(
              "Looking somewhat disappointed, the Sphinx sighs.  You've answered my riddle so here's your reward.  Now begone.",
              1,
              -1,
              -1,
              img1Type,
              a6,
              a7,
              a8,
              -1,
              0);
            *(_BYTE *)v81 = 0;
          }
          else
          {
            NormalDialog(
              "\"You guessed incorrectly,\" the Sphinx says, smiling.  The Sphinx swipes at you with a paw, knocking you to the ground.  Another blow makes the world go black, and you know no more.",
              1,
              -1,
              -1,
              -1,
              0,
              -1,
              0,
              -1,
              0);
            advManager::HeroLoses((int)thisa, (int)hero);
          }
        }
      }
      else
      {
        NormalDialog(
          "{Sphinx}\n\nYou come across a giant Sphinx.  The Sphinx remains strangely quiet.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      }
      goto LABEL_511;
    case LOCATION_OBSERVATION_TOWER:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      NormalDialog(
        "{Observation Tower}\n\nFrom the observation tower, you are able to see distant lands.",
        1,
        -1,
        -1,
        -1,
        0,
        -1,
        0,
        -1,
        0);
      game::SetVisibility(a4, a4_4, giCurPlayer, 20);
      advManager::CompleteDraw(thisa, 0);
      advManager::UpdateScreen(thisa, 0, 0);
      goto LABEL_511;
    case LOCATION_HILL_FORT:
      v93 = -1;
      v88 = -1;
      v89 = -1;
      if ( hero::CreatureTypeCount(hero, CREATURE_OGRE) )
        v89 = CREATURE_OGRE;
      if ( hero::CreatureTypeCount(hero, CREATURE_ORC) )
      {
        if ( v89 == -1 )
          v89 = CREATURE_ORC;
        else
          v88 = CREATURE_ORC;
      }
      if ( hero::CreatureTypeCount(hero, CREATURE_DWARF) )
      {
        if ( v89 == -1 )
        {
          v89 = CREATURE_DWARF;
        }
        else if ( v88 == -1 )
        {
          v88 = CREATURE_DWARF;
        }
        else
        {
          v93 = CREATURE_DWARF;
        }
      }
      if ( v89 == -1 )
      {
        advManager::EventWindow(
          -1,
          1,
          "{Hill Fort}\n\nAn unusual alliance of Orcs, Ogres, and Dwarves offer to train (upgrade) any such troops brought to them.  Unfortunately, you have none with you.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        hero::UpgradeCreatures(hero, CREATURE_OGRE, CREATURE_OGRE_LORD);
        hero::UpgradeCreatures(hero, CREATURE_ORC, CREATURE_ORC_CHIEF);
        hero::UpgradeCreatures(hero, CREATURE_DWARF, CREATURE_BATTLE_DWARF);
        if ( v93 == -1 )
        {
          if ( v88 == -1 )
            sprintf(
              gText,
              "{Hill Fort}\n\nAll of the %s you have in your army have been trained by the battle masters of the fort.  Your army now contains %s.",
              gArmyNamesPlural[v89],
              gArmyNamesPlural[v89 + 1]);
          else
            sprintf(
              gText,
              "{Hill Fort}\n\nAll of the %s and %s you have in your army have been trained by the battle masters of the fort.  Your army now contains %s and %s.",
              gArmyNamesPlural[v89],
              gArmyNamesPlural[v88],
              gArmyNamesPlural[v89 + 1],
              gArmyNamesPlural[v88 + 1]);
        }
        else
        {
          sprintf(
            gText,
            "{Hill Fort}\n\n All of the %s, %s and %s you have in your army have been trained by the battle masters of the fort.  Your army now contains %s, %s, and %s.",
            gArmyNamesPlural[v89],
            gArmyNamesPlural[v88],
            gArmyNamesPlural[v93],
            gArmyNamesPlural[v89 + 1],
            gArmyNamesPlural[v88 + 1],
            gArmyNamesPlural[v93 + 1]);
        }
        advManager::EventWindow(-1, 1, gText, 18, v89 + 1, (unsigned int)(v88 + 1) < 1 ? -1 : 18, v88 + 1, -1);
      }
      goto LABEL_511;
    case LOCATION_FREEMANS_FOUNDRY:
      v93 = -1;
      v88 = -1;
      v89 = -1;
      if ( hero::CreatureTypeCount(hero, CREATURE_PIKEMAN) )
        v89 = 3;
      if ( hero::CreatureTypeCount(hero, CREATURE_SWORDSMAN) )
      {
        if ( v89 == -1 )
          v89 = 5;
        else
          v88 = 5;
      }
      if ( hero::CreatureTypeCount(hero, CREATURE_IRON_GOLEM) )
      {
        if ( v89 == -1 )
        {
          v89 = 40;
        }
        else if ( v88 == -1 )
        {
          v88 = 40;
        }
        else
        {
          v93 = 40;
        }
      }
      if ( v89 == -1 )
      {
        advManager::EventWindow(
          -1,
          1,
          "{Freeman's Foundry}\n\nA blacksmith working at the foundry offers to convert all Pikemen and Swordsmen's weapons brought to him from iron to steel. He also says that he knows a process that will convert Iron Golems into Steel Golems.  Unfortunately, you have none of these troops in your army, so he can't help you.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        hero::UpgradeCreatures(hero, 3, 4);
        hero::UpgradeCreatures(hero, 5, 6);
        hero::UpgradeCreatures(hero, 40, 41);
        if ( v93 == -1 )
        {
          if ( v88 == -1 )
            sprintf(
              gText,
              "{Freeman's Foundry}\n\nAll of your %s have been upgraded into %s.",
              gArmyNamesPlural[v89],
              gArmyNamesPlural[v89 + 1]);
          else
            sprintf(
              gText,
              "{Freeman's Foundry}\n\nAll of your %s and %s have been upgraded into %s and %s.",
              gArmyNamesPlural[v89],
              gArmyNamesPlural[v88],
              gArmyNamesPlural[v89 + 1],
              gArmyNamesPlural[v88 + 1]);
        }
        else
        {
          sprintf(
            gText,
            "{Freeman's Foundry}\n\nAll of your  %s, %s and %s have been upgraded into %s, %s, and %s.",
            gArmyNamesPlural[v89],
            gArmyNamesPlural[v88],
            gArmyNamesPlural[v93],
            gArmyNamesPlural[v89 + 1],
            gArmyNamesPlural[v88 + 1],
            gArmyNamesPlural[v93 + 1]);
        }
        advManager::EventWindow(-1, 1, gText, 18, v89 + 1, (unsigned int)(v88 + 1) < 1 ? -1 : 18, v88 + 1, -1);
      }
      goto LABEL_511;
    case LOCATION_SEA_CHEST:
      if ( ((unsigned __int16)(loc->flags >> 3) >> 8) & 1 && hero::NumArtifacts(hero) < 14 )
      {
        v4 = loc->flags >> 3;
        sprintf(
          gText,
          "{Chest}\n\nAfter spending hours trying to fish the chest out of the sea, you open it and find 1000 gold and the %s",
          gArtifactNames[(unsigned __int8)v4]);
        v5 = loc->flags >> 3;
        NormalDialog(gText, 1, -1, -1, 7, (unsigned __int8)v5, 6, 1000, -1, 0);
        v6 = loc->flags >> 3;
        GiveArtifact(hero, (ARTIFACT)(unsigned __int8)v6, 1, -1);
        advManager::GiveResource(thisa, hero, 6, 1000);
      }
      else if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        NormalDialog(
          "{Chest}\n\nAfter spending hours trying to fish the chest out of the sea, you open it and find 1500 gold pieces.",
          1,
          -1,
          -1,
          6,
          1500,
          -1,
          0,
          -1,
          0);
        advManager::GiveResource(thisa, hero, 6, 1500);
      }
      else
      {
        NormalDialog(
          "{Chest}\n\nAfter spending hours trying to fish the chest out of the sea, you open it, only to find it empty.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      }
      v90 = 1;
      v86 = 1;
      goto LABEL_511;
    case LOCATION_FLOTSAM:
      switch ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) )
      {
        case 0u:
          NormalDialog("{Flotsam}\n\nYou search through the flotsam, but find nothing.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 1u:
          NormalDialog(
            "{Flotsam}\n\nYou search through the flotsam, and find some wood.",
            1,
            -1,
            -1,
            0,
            5,
            -1,
            0,
            -1,
            0);
          advManager::GiveResource(thisa, hero, 0, 5);
          break;
        case 2u:
          NormalDialog(
            "{Flotsam}\n\nYou search through the flotsam, and find some wood and some gold.",
            1,
            -1,
            -1,
            0,
            5,
            6,
            200,
            -1,
            0);
          advManager::GiveResource(thisa, hero, 0, 5);
          advManager::GiveResource(thisa, hero, 6, 200);
          break;
        case 3u:
          NormalDialog(
            "{Flotsam}\n\nYou search through the flotsam and find some wood and some gold.",
            1,
            -1,
            -1,
            0,
            10,
            6,
            500,
            -1,
            0);
          advManager::GiveResource(thisa, hero, 0, 10);
          advManager::GiveResource(thisa, hero, 6, 500);
          break;
        default:
          break;
      }
      v90 = 1;
      v86 = 1;
      goto LABEL_511;
    case LOCATION_SHIPWRECK_SURVIVOR:
      if ( hero::NumArtifacts(hero) >= 14 )
      {
        NormalDialog(
          "{Shipwreck Survivor}\n\nYou've pulled a shipwreck survivor from certain death in an unforgiving ocean.  Grateful, he says, \"I would give you an artifact as a reward, but you're all full.\"",
          1,
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
        sprintf(
          gText,
          "{Shipwreck Survivor}\n\nYou've pulled a shipwreck survivor from certain death in an unforgiving ocean.  Grateful, he rewards you for your act of kindness by giving you the %s.",
          gArtifactNames[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
        NormalDialog(gText, 1, -1, -1, 7, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), -1, 0, -1, 0);
        GiveArtifact(hero, (ARTIFACT)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), 1, -1);
      }
      v90 = 1;
      v86 = 1;
      goto LABEL_511;
    case LOCATION_MAGELLANS_MAPS:
      if ( gpCurPlayer->resources[6] >= 1000 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        NormalDialog(
          "{Magellan's Maps}\n\nA retired captain living on this refurbished fishing platform offers to sell you maps of the sea he made in his younger days for 1,000 gold.  Do you wish to buy the maps?",
          2,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
        if ( gpWindowManager->buttonPressedCode == 30725 )
        {
          gpCurPlayer->resources[6] -= 1000;
          game::MakeAllWaterVisible(gpGame, giCurPlayer);
          advManager::CompleteDraw(thisa, 0);
          advManager::UpdateScreen(thisa, 0, 0);
        }
      }
      else
      {
        NormalDialog(
          "{Magellan's Maps}\n\nThe captain sighs.  \"You don't have enough money, eh?  You can't expect me to give my maps away for free!\"",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      }
      goto LABEL_511;
    case LOCATION_WITCH_HUT:
      if ( hero->secondarySkillLevel[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)] )
      {
        sprintf(
          gText,
          "{Witch's Hut}\n\nYou approach the hut and observe a witch inside studying an ancient tome on %s.  As you approach, she turns and speaks.  \"You already know that which I would teach you. I can help you no further.\"",
          gSecondarySkills[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
        NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
      }
      else if ( hero->numSecSkillsKnown < 8 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        sprintf(
          gText,
          "{Witch's Hut}\n\nAn ancient and immortal witch living in a hut with bird's legs for stilts teaches you %s for her own inscrutable purposes.",
          gSecondarySkills[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
        advManager::EventWindow(
          -1,
          1,
          gText,
          17,
          3 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
          -1,
          0,
          -1);
        hero::GiveSS(hero, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), 1);
      }
      else
      {
        sprintf(
          gText,
          "{Witch's Hut}\n\nYou approach the hut and observe a witch inside studying an ancient tome on %s.  As you approach, she turns and focuses her one glass eye on you.  \"You already know everything you deserve to learn!\" the witch screeches. \"NOW GET OUT OF MY HOUSE!\"",
          gSecondarySkills[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
        NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
      }
      goto LABEL_511;
    case LOCATION_ARTESIAN_SPRING:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        loc->flags &= 7u;
        v7 = hero::Stats(hero, PRIMARY_SKILL_KNOWLEDGE);
        v63 = 10 * v7;
        if ( hero->spellpoints < 20 * v7 )
        {
          NormalDialog(
            "{Artesian Spring}\n\nA drink from the spring fills your blood with magic!  You have twice your normal spell points in reserve.",
            1,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
          hero->spellpoints = 2 * v63;
        }
        else
        {
          NormalDialog(
            "{Artesian Spring}\n\nA drink at the spring is supposed to give you twice your normal spell points, but you are already at that level.",
            1,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
        }
      }
      else
      {
        NormalDialog(
          "{Artesian Spring}\n\nThe spring only refills once a week, and someone's already been here this week.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      }
      goto LABEL_511;
    case LOCATION_MAGIC_WELL:
      if ( hero->flags2 & HERO_VISITED_WELL )
      {
        NormalDialog(
          "{Magic Well}\n\nA second drink at the well in one day will not help you.",
          1,
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
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        loc->flags &= 7u;
        maxSP = 10 * hero::Stats(hero, PRIMARY_SKILL_KNOWLEDGE);
        if ( hero->spellpoints < maxSP )
        {
          NormalDialog(
            "{Magic Well}\n\nA drink from the well has restored your spell points to maximum.",
            1,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
          *(_DWORD *)&hero->flags1 |= 0x1000u;
          hero->spellpoints = maxSP;
        }
        else
        {
          NormalDialog(
            "{Magic Well}\n\nA drink at the well is supposed to restore your spell points, but you are already at maximum.",
            1,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
        }
      }
      goto LABEL_511;
    case LOCATION_ARMY_CAMP|LOCATION_SKELETON:
      if ( hero->flags1 & 0x80 )
      {
        *(_DWORD *)&hero->flags1 &= 0xFFFFFF7Fu;
        *(_DWORD *)&hero->field_35 = 0;
        HIBYTE(hero->field_2B) = LOBYTE(thisa->field_27E);
        thisa->field_27A = hero->factionID;
        thisa->field_282 = advManager::GetCursorBaseFrame(thisa->field_27E);
        thisa->field_272 = 1;
        res = LoadPlaySample("killfade.82m");
        heroWindowManager::SaveFizzleSource(gpWindowManager, 192, 192, 96, 96);
        advManager::CompleteDraw(thisa, thisa->viewX, thisa->viewY, 0, 1);
        heroWindowManager::FizzleForward(gpWindowManager, 192, 192, 96, 96, -1, 0, 0);
        WaitEndSample(-1, res);
        advManager::CheckAdjacentMon(thisa, (signed int)&v61);
      }
      goto LABEL_511;
    case LOCATION_BOAT:
      v69 = &gpGame->probablyArtifactGeneratedRandomly[8 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)
                                                     + 103];
      game::RestoreCell(-1, -1, (unsigned __int8)v69[4], (unsigned __int8)v69[5], (int)loc, 2);
      *(_DWORD *)&hero->flags1 |= HERO_AT_SEA;
      *(_DWORD *)&hero->field_35 = 0;
      v69[6] = hero->couldBeHeroIdx;
      v69[7] = hero->probablyOwnerIdx;
      thisa->field_27A = 6;
      thisa->field_27E = v69[3];
      thisa->field_282 = advManager::GetCursorBaseFrame(thisa->field_27E);
      thisa->field_272 = 1;
      advManager::CompleteDraw(thisa, thisa->viewX, thisa->viewY, 0, 1);
      advManager::UpdateScreen(thisa, 0, 0);
      goto LABEL_511;
    case LOCATION_MINE:
      if ( gpGame->_8[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 1008] == giCurPlayer )
        goto LABEL_511;
      if ( gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 3] == -1 )
        goto LABEL_126;
      v60 = advManager::CombatMonsterEvent(
              thisa,
              hero,
              (CREATURES)gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 3],
              gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 4],
              loc,
              a4,
              a4_4,
              0,
              a4,
              a4_4,
              -1,
              0,
              0,
              -1,
              0,
              0);
      if ( !v60 )
      {
        gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 3] = -1;
        hero::CheckLevel(hero);
LABEL_126:
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        if ( gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 2] == 6 )
        {
          v82 = 1000;
        }
        else if ( gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 2] == 2 )
        {
          v82 = 2;
        }
        else
        {
          v82 = 1;
        }
        advManager::EventWindow(
          gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 2] + 59,
          1,
          byte_514A64,
          gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 2],
          -v82,
          -1,
          0,
          -1);
        goto LABEL_136;
      }
      goto LABEL_511;
    case LOCATION_ALCHEMIST_LAB:
      if ( gpGame->_8[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 1008] == giCurPlayer )
        goto LABEL_511;
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::EventWindow(0, 1, byte_514A68, 1, -1, -1, 0, -1);
      goto LABEL_136;
    case LOCATION_SAWMILL:
      if ( gpGame->_8[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 1008] != giCurPlayer )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(73, 1, byte_514A6C, 0, -2, -1, 0, -1);
LABEL_136:
        game::ClaimMine(gpGame, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), giCurPlayer);
      }
      goto LABEL_511;
    case LOCATION_LIGHTHOUSE:
      if ( gpGame->_8[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 1008] != giCurPlayer )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        game::ClaimMine(gpGame, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), giCurPlayer);
        advManager::EventWindow(58, 1, byte_514A70, -1, 0, -1, 0, -1);
      }
      goto LABEL_511;
    case LOCATION_TREASURE_CHEST:
      if ( !(((unsigned __int16)(loc->flags >> 3) >> 8) & 1) )
        goto LABEL_143;
      if ( hero::NumArtifacts(hero) < 14 )
      {
        v9 = loc->flags >> 3;
        sprintf(
          gText,
          "{Chest}\n\nAfter scouring the area, you fall upon a hidden chest, containing the ancient artifact '%s'",
          gArtifactNames[(unsigned __int8)v9]);
        v10 = loc->flags >> 3;
        NormalDialog(gText, 1, -1, -1, 7, (unsigned __int8)v10, -1, 0, -1, 0);
        v11 = loc->flags >> 3;
        GiveArtifact(hero, (ARTIFACT)(unsigned __int8)v11, 1, -1);
      }
      else
      {
        v8 = loc->flags & 7;
        LOBYTE(v8) = v8 | 0x10;
        loc->flags = v8;
LABEL_143:
        advManager::EventWindow(
          -1,
          2,
          "{Chest}\n\nAfter scouring the area, you fall upon a hidden treasure cache.  You may take the gold or distribute the gold to the peasants for experience.  Do you wish to keep the gold?",
          6,
          500 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
          14,
          125 * (4 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 4),
          1);
        if ( gpWindowManager->buttonPressedCode == 30725 )
          advManager::GiveResource(thisa, hero, 6, 500 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5));
        else
          advManager::GiveExperience(
            hero,
            125 * (4 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 4),
            0);
      }
      v86 = 1;
      v90 = 1;
      hero::CheckLevel(hero);
      goto LABEL_511;
    case LOCATION_BUOY:
      if ( hero->flags1 & 2 )
      {
        advManager::EventWindow(2, 1, byte_514B94, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        *(_DWORD *)&hero->flags1 |= 2u;
        ++hero->_5[1];
        advManager::EventWindow(3, 1, byte_514B98, 12, 0, -1, 0, -1);
      }
      goto LABEL_511;
    case LOCATION_FAERIE_RING:
      if ( hero->flags1 & 0x10 )
      {
        advManager::EventWindow(12, 1, byte_514B9C, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        *(_DWORD *)&hero->flags1 |= 0x10u;
        ++hero->_5[2];
        advManager::EventWindow(13, 1, byte_514BA0, 10, 0, -1, 0, -1);
      }
      goto LABEL_511;
    case LOCATION_IDOL:
      if ( hero->flags2 & 0x20 )
      {
        advManager::EventWindow(
          -1,
          1,
          "{Idol}\n\nYou've found an ancient and weathered stone idol.  It is supposed to grant luck to visitors, but since the stars are already smiling upon you, it does nothing.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        *(_DWORD *)&hero->flags1 |= 0x2000u;
        ++hero->_5[2];
        advManager::EventWindow(
          -1,
          1,
          "{Idol}\n\nYou've found an ancient and weathered stone idol.  Kissing it is supposed to be lucky, so you do.  The stone is very cold to the touch.",
          10,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_511;
    case LOCATION_FOUNTAIN:
      if ( hero->flags1 & 4 )
      {
        advManager::EventWindow(15, 1, byte_514CDC, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        *(_DWORD *)&hero->flags1 |= 4u;
        ++hero->_5[2];
        advManager::EventWindow(16, 1, byte_514CE0, 10, 0, -1, 0, -1);
      }
      goto LABEL_511;
    case LOCATION_WATERING_HOLE:
      if ( hero->flags2 & 2 )
      {
        advManager::EventWindow(
          -1,
          1,
          "{Watering Hole}\n\nThe drink at the watering hole is refreshing, but offers no further benefit.  The watering hole might help again if you fought a battle first.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        *(_DWORD *)&hero->flags1 |= 0x200u;
        ++hero->_5[1];
        *(_DWORD *)&hero->field_31 += 400;
        *(_DWORD *)&hero->field_35 += 400;
        advManager::EventWindow(
          -1,
          1,
          "{Watering Hole}\n\nA drink at the watering hole fills your troops with strength and lifts their spirits.  You can travel a bit further today.",
          12,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_511;
    case LOCATION_OASIS:
      if ( hero->flags1 & 8 )
      {
        advManager::EventWindow(
          -1,
          1,
          "{Oasis}\n\nThe drink at the oasis is refreshing, but offers no further benefit.  The oasis might help again if you fought a battle first.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        *(_DWORD *)&hero->flags1 |= 8u;
        ++hero->_5[1];
        *(_DWORD *)&hero->field_31 += 800;
        *(_DWORD *)&hero->field_35 += 800;
        advManager::EventWindow(
          -1,
          1,
          "{Oasis}\n\nA drink at the oasis fills your troops with strength and lifts their spirits.  You can travel a bit further today.",
          12,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_511;
    case LOCATION_TEMPLE:
      if ( hero->flags2 & 1 )
      {
        NormalDialog(
          "{Temple}\n\nIt doesn't help to pray twice before a battle.  Come back after you've fought.",
          1,
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
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        *(_DWORD *)&hero->flags1 |= 0x100u;
        hero->_5[1] += 2;
        NormalDialog(
          "{Temple}\n\nA visit and a prayer at the temple raises the morale of your troops.",
          1,
          -1,
          -1,
          12,
          0,
          12,
          0,
          -1,
          0);
      }
      goto LABEL_511;
    case LOCATION_LEAN_TO:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        v12 = loc->flags >> 3;
        v13 = (v12 & 0xF0u) >> 4;
        v14 = loc->flags >> 3;
        NormalDialog(
          "{Lean To}\n\nYou've found an abandoned lean-to.  Poking about, you discover some resources hidden nearby.",
          1,
          -1,
          -1,
          (v14 & 0xF) - 1,
          v13,
          -1,
          0,
          -1,
          0);
        v15 = loc->flags >> 3;
        v16 = (v15 & 0xF0u) >> 4;
        v17 = loc->flags >> 3;
        advManager::GiveResource(thisa, hero, (v17 & 0xF) - 1, v16);
        loc->flags &= 7u;
      }
      else
      {
        NormalDialog(
          "{Lean To}\n\nThe lean-to is long abandoned.  There is nothing of value here.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      }
      goto LABEL_511;
    case LOCATION_WAGON:
      if ( !((unsigned __int8)(loc->flags >> 8) >> -5) )
        goto LABEL_180;
      if ( (loc->flags >> 3) & 0x80 )
      {
        if ( hero::NumArtifacts(hero) == 14 )
        {
LABEL_180:
          advManager::EventWindow(
            -1,
            1,
            "{Wagon}\n\nYou come across an old wagon left by a trader who didn't quite make it to safe terrain.  Unfortunately, others have found it first, and the wagon is empty.",
            -1,
            0,
            -1,
            0,
            -1);
          loc->flags &= 7u;
        }
        else
        {
          playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
          v18 = loc->flags >> 3;
          a2 = v18 & 0x7F;
          sprintf(
            gText,
            "{Wagon}\n\nYou come across an old wagon left by a trader who didn't quite make it to safe terrain.  Searching inside, you find the '%s'.",
            gArtifactNames[v18 & 0x7F]);
          advManager::EventWindow(-1, 1, gText, 7, a2, -1, 0, -1);
          GiveArtifact(hero, (ARTIFACT)a2, 1, -1);
          loc->flags &= 7u;
        }
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        v19 = loc->flags >> 3;
        v20 = (v19 & 0xF0u) >> 4;
        v21 = loc->flags >> 3;
        advManager::EventWindow(
          -1,
          1,
          "{Wagon}\n\nYou come across an old wagon left by a trader who didn't quite make it to safe terrain.  Inside, you find some of the wagon's cargo still intact.",
          (v21 & 0xF) - 1,
          v20,
          -1,
          0,
          -1);
        v22 = loc->flags >> 3;
        v23 = (v22 & 0xF0u) >> 4;
        v24 = loc->flags >> 3;
        advManager::GiveResource(thisa, hero, (v24 & 0xF) - 1, v23);
        loc->flags &= 7u;
      }
      goto LABEL_511;
    case LOCATION_SKELETON:
      if ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) == 1 )
      {
        advManager::EventWindow(93, 1, byte_515240, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        if ( hero::NumArtifacts(hero) == 14 )
        {
          sprintf(gText, "%s.", "Treasure");
          advManager::EventWindow(-1, 1, gText, 6, 1000, -1, 0, -1);
          advManager::GiveResource(thisa, hero, 6, 1000);
        }
        else
        {
          a2 = (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 2;
          sprintf(gText, "%s %s", gEventText[94], gArtifactNames[a2]);
          GiveArtifact(hero, (ARTIFACT)a2, 1, -1);
          advManager::EventWindow(-1, 1, gText, 7, a2, -1, 0, -1);
        }
        v25 = loc->flags & 7;
        LOBYTE(v25) = v25 | 8;
        loc->flags = v25;
      }
      goto LABEL_511;
    case LOCATION_CAMPFIRE:
      v26 = loc->flags >> 3;
      advManager::EventWindow(
        14,
        1,
        byte_51525C,
        6,
        100 * ((signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) >> 4),
        v26 & 0xF,
        (signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) >> 4,
        -1);
      advManager::GiveResource(
        thisa,
        hero,
        6,
        100 * ((signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) >> 4));
      v27 = loc->flags >> 3;
      advManager::GiveResource(
        thisa,
        hero,
        v27 & 0xF,
        (signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) >> 4);
      v86 = 1;
      v90 = 1;
      advManager::SetEnvironmentOrigin(thisa, thisa->viewX + 7, thisa->viewY + 7, 1);
      goto LABEL_511;
    case LOCATION_XANADU:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[28] )
      {
        NormalDialog(
          "{Xanadu}\n\nRecognizing you, the butler refuses to admit you.  \"The master,\" he says, \"will not see the same student twice.\"",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
      }
      else if ( hero->oldLevel + 2 * hero->secondarySkillLevel[4] < 10 )
      {
        NormalDialog(
          "{Xanadu}\n\nThe butler opens the door and looks you up and down.  \"You are neither famous nor diplomatic enough to be admitted to see my master,\" he sniffs.  \"Come back when you think yourself worthy.\"",
          1,
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
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        NormalDialog(
          "{Xanadu}\n\nThe butler admits you to see the master of the house.  He trains you in the four skills a hero should know.",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
        ++hero->primarySkills[0];
        ++hero->primarySkills[1];
        ++hero->primarySkills[3];
        ++hero->primarySkills[2];
        *(_DWORD *)&hero->_5[28] |= 1 << (loc->flags >> 3);
      }
      goto LABEL_511;
    case LOCATION_FORT:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[8] )
      {
        NormalDialog(
          "{Fort}\n\n \"I'm sorry sir,\" The leader of the soldiers says, \"but you already know everything we have to teach.\"",
          1,
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
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        NormalDialog(
          "{Fort}\n\n The soldiers living in the fort teach you a few new defensive tricks.",
          1,
          -1,
          -1,
          25,
          101,
          -1,
          0,
          -1,
          0);
        ++hero->primarySkills[1];
        *(_DWORD *)&hero->_5[8] |= 1 << (loc->flags >> 3);
      }
      goto LABEL_511;
    case LOCATION_STANDING_STONES:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[20] )
      {
        NormalDialog(
          "{Standing Stones}\n\nYou've found a group of Druids worshipping at one of their strange stone edifices.  Silently, the Druids turn you away, indicating they have nothing new to teach you.",
          1,
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
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        NormalDialog(
          "{Standing Stones}\n\nYou've found a group of Druids worshipping at one of their strange stone edifices.  Silently, they teach you new ways to cast spells.",
          1,
          -1,
          -1,
          25,
          102,
          -1,
          0,
          -1,
          0);
        ++hero->primarySkills[2];
        *(_DWORD *)&hero->_5[20] |= 1 << (loc->flags >> 3);
      }
      goto LABEL_511;
    case LOCATION_WITCH_DOCTORS_HUT:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[12] )
      {
        NormalDialog(
          "{Witch Doctor's Hut}\n\n\"Go 'way!\", the witch doctor barks, \"you know all I know.\"",
          1,
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
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        NormalDialog(
          "{Witch Doctor's Hut}\n\nAn Orcish witch doctor living in the hut deepens your knowledge of magic by showing you how to cast stones, read portents, and decipher the intricacies of chicken entrails.",
          1,
          -1,
          -1,
          25,
          103,
          -1,
          0,
          -1,
          0);
        ++hero->primarySkills[3];
        *(_DWORD *)&hero->_5[12] |= 1 << (loc->flags >> 3);
      }
      goto LABEL_511;
    case LOCATION_MERCENARY_CAMP:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[16] )
      {
        NormalDialog(
          "{Mercenary Camp}\n\nYou've come upon a mercenary camp practicing their tactics.  \"You're too advanced for us,\" the mercenary captain says.  \"We can teach nothing more.\"",
          1,
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
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        NormalDialog(
          "{Mercenary Camp}\n\nYou've come upon a mercenary camp practicing their tactics.  The mercenaries welcome you and your troops and invite you to train with them.",
          1,
          -1,
          -1,
          25,
          100,
          -1,
          0,
          -1,
          0);
        ++hero->primarySkills[0];
        *(_DWORD *)&hero->_5[16] |= 1 << (loc->flags >> 3);
      }
      goto LABEL_511;
    case LOCATION_GAZEBO:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[4] )
      {
        advManager::EventWindow(17, 1, byte_515894, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(18, 1, byte_515898, 14, 1000, -1, 0, -1);
        advManager::GiveExperience(hero, 1000, 0);
        *(_DWORD *)&hero->_5[4] |= 1 << (loc->flags >> 3);
        hero::CheckLevel(hero);
      }
      goto LABEL_511;
    case LOCATION_WATERWHEEL:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(
          60,
          1,
          byte_5158A0,
          6,
          500 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
          -1,
          0,
          -1);
        advManager::GiveResource(thisa, hero, 6, 500 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5));
        loc->flags &= 7u;
      }
      else
      {
        advManager::EventWindow(59, 1, byte_51589C, -1, 0, -1, 0, -1);
      }
      goto LABEL_511;
    case LOCATION_RESOURCE:
      type = (signed int)HIBYTE(loc->field_2) >> 1;
      if ( type == 6 )
        amt = 100 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
      else
        amt = (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
      advManager::GiveResource(thisa, hero, type, amt);
      strcpy(&a1, gResourceNames[type]);
      a1 += 32;
      sprintf(gText, gEventText[72], &a1);
      if ( type == 6 )
        v50 = 100 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
      else
        v50 = (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
      BVResMsg(gText, type, v50);
      v86 = 1;
      v90 = 1;
      goto LABEL_511;
    case LOCATION_WINDMILL:
      if ( (signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) > 6 )
      {
        advManager::EventWindow(86, 1, byte_5158A8, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(
          87,
          1,
          byte_5158A4,
          (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
          2,
          -1,
          0,
          -1);
        advManager::GiveResource(thisa, hero, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), 2);
        loc->flags = loc->flags & 7 | 0x318;
      }
      goto LABEL_511;
    case LOCATION_ANCIENT_LAMP:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::EventWindow(19, 2, byte_5158AC, -1, 0, -1, 0, -1);
      if ( gpWindowManager->buttonPressedCode == 30725 )
      {
        advManager::RecruitEvent(thisa, hero, 60, loc);
        if ( !((unsigned __int8)(loc->flags >> 8) >> -5) )
        {
          v86 = 1;
          v90 = 1;
        }
      }
      goto LABEL_511;
    case LOCATION_TREE_CITY:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(
          -1,
          2,
          "{Tree City}\n\nSome of the Sprites living in the tree city are willing to join your army for a price.  Do you want to recruit Sprites?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( gpWindowManager->buttonPressedCode == 30725 )
          advManager::RecruitEvent(thisa, hero, 20, loc);
      }
      else
      {
        advManager::EventWindow(
          -1,
          1,
          "{Tree City}\n\nYou've found a Sprite Tree City.  Unfortunately, none of the Sprites living there wish to join an army.  Maybe next week.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_511;
    case LOCATION_RUINS:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(
          -1,
          2,
          "{Ruins}\n\nYou've found some Medusas living in the ruins.  They are willing to join your army for a price.  Do you want to recruit Medusas?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( gpWindowManager->buttonPressedCode == 30725 )
          advManager::RecruitEvent(thisa, hero, CREATURE_MEDUSA, loc);
      }
      else
      {
        advManager::EventWindow(
          -1,
          1,
          "{Ruins}\n\nYou search the ruins, but the Medusas that used to live here are gone.  Perhaps there will be more next week.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_511;
    case LOCATION_TROLL_BRIDGE:
      if ( !((unsigned __int8)(loc->flags >> 8) >> -5) )
      {
        advManager::EventWindow(
          -1,
          1,
          "{Troll Bridge}\n\nYou've found one of those bridges that Trolls are so fond of living under, but there are none here.  Perhaps there will be some next week.",
          -1,
          0,
          -1,
          0,
          -1);
        goto LABEL_511;
      }
      if ( ((unsigned __int16)(loc->flags >> 3) >> 8) & 1 )
      {
        advManager::EventWindow(
          -1,
          2,
          "{Troll Bridge}\n\nTrolls living under the bridge challenge you.  Will you fight them?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( gpWindowManager->buttonPressedCode != 30725 )
          goto LABEL_511;
        if ( advManager::CombatMonsterEvent(
               thisa,
               hero,
               CREATURE_TROLL,
               12,
               loc,
               a4,
               a4_4,
               0,
               a4,
               a4_4,
               18,
               8,
               2,
               -1,
               0,
               0) )
          goto LABEL_511;
        hero::CheckLevel(hero);
        loc->flags = loc->flags & 7 | 8 * ((unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 256);
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(
          -1,
          2,
          "{Troll Bridge}\n\nA few Trolls remain, cowering under the bridge.  They approach you and offer to join your forces as mercenaries.  Do you want to buy any Trolls?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( gpWindowManager->buttonPressedCode != 30725 )
          goto LABEL_511;
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(
          -1,
          2,
          "{Troll Bridge}\n\nSome Trolls living under a bridge are willing to join your army, but for a price.  Do you want to recruit Trolls?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( gpWindowManager->buttonPressedCode != 30725 )
          goto LABEL_511;
      }
      advManager::RecruitEvent(thisa, hero, 17, loc);
      goto LABEL_511;
    case LOCATION_CITY_OF_DEAD:
      if ( !((unsigned __int8)(loc->flags >> 8) >> -5) )
      {
        advManager::EventWindow(
          -1,
          1,
          "{City of the Dead}\n\nThe City of the Dead is empty of life, and empty of unlife as well.  Perhaps some undead will move in next week.",
          -1,
          0,
          -1,
          0,
          -1);
        goto LABEL_511;
      }
      if ( ((unsigned __int16)(loc->flags >> 3) >> 8) & 1 )
      {
        advManager::EventWindow(
          -1,
          2,
          "{City of the Dead}\n\nYou've found the ruins of an ancient city, now inhabited solely by the undead.  Will you search?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( gpWindowManager->buttonPressedCode != 30725 )
          goto LABEL_511;
        if ( advManager::CombatMonsterEvent(
               thisa,
               hero,
               CREATURE_VAMPIRE_LORD,
               10,
               loc,
               a4,
               a4_4,
               0,
               a4,
               a4_4,
               48,
               40,
               2,
               55,
               5,
               1) )
          goto LABEL_511;
        hero::CheckLevel(hero);
        loc->flags = loc->flags & 7 | 8 * ((unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 256);
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(
          -1,
          2,
          "{City of the Dead}\n\nSome of the surviving Liches are impressed by your victory over their fellows, and offer to join you for a price.  Do you want to recruit Liches?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( gpWindowManager->buttonPressedCode != 30725 )
          goto LABEL_511;
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(
          -1,
          2,
          "{City of the Dead}\n\nSome Liches living here are willing to join your army for a price.  Do you want to recruit Liches?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( gpWindowManager->buttonPressedCode != 30725 )
          goto LABEL_511;
      }
      advManager::RecruitEvent(thisa, hero, 55, loc);
      goto LABEL_511;
    case LOCATION_DRAGON_CITY:
      if ( !((unsigned __int8)(loc->flags >> 8) >> -5) )
      {
        advManager::EventWindow(
          -1,
          1,
          "{Dragon City}\n\nThe Dragon city has no Dragons willing to join you this week.  Perhaps a Dragon will become available next week.",
          -1,
          0,
          -1,
          0,
          -1);
        goto LABEL_511;
      }
      if ( !(((unsigned __int16)(loc->flags >> 3) >> 8) & 1) )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(
          -1,
          2,
          "{Dragon City}\n\nThe Dragon city is willing to offer some Dragons for your army for a price.  Do you wish to recruit Dragons?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( gpWindowManager->buttonPressedCode != 30725 )
          goto LABEL_511;
        goto LABEL_284;
      }
      advManager::EventWindow(
        -1,
        2,
        "{Dragon City}\n\nYou stand before the Dragon City, a place off-limits to mere humans.  Do you wish to violate this rule and challenge the Dragons to a fight?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( gpWindowManager->buttonPressedCode == 30725 )
      {
        a13 = 1;
        if ( gbInCampaign && gpGame->field_2 == 1 && gpGame->field_4 == 6 )
          a13 = 2;
        if ( !advManager::CombatMonsterEvent(
                thisa,
                hero,
                CREATURE_GREEN_DRAGON,
                3 * a13,
                loc,
                a4,
                a4_4,
                0,
                a4,
                a4_4,
                36,
                a13,
                1,
                37,
                a13,
                1) )
        {
          CheckEndGame(0, 1);
          if ( !gbGameOver )
          {
            hero::CheckLevel(hero);
            loc->flags = loc->flags & 7 | 8 * ((unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 256);
            playTrackForLocationVisit(
              locType,
              (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
              (_QWORD *)a3a);
            advManager::EventWindow(
              -1,
              2,
              "{Dragon City}\n\nHaving defeated the Dragon champions, the city's leaders agree to supply some Dragons to your army for a price.  Do you wish to recruit Dragons?",
              -1,
              0,
              -1,
              0,
              -1);
            if ( gpWindowManager->buttonPressedCode == 30725 )
            {
LABEL_284:
              advManager::RecruitEvent(thisa, hero, 36, loc);
              goto LABEL_511;
            }
          }
        }
      }
LABEL_511:
      advManager::UpdateRadar((int)thisa, 1, 0);
      advManager::UpdateHeroLocators(thisa, 1, 1);
      advManager::UpdateTownLocators(thisa, 1, 1);
      advManager::UpdBottomView(thisa, 1, 1, 1);
      if ( v86 )
      {
        advManager::EraseObj((mapCell *)thisa, (int)loc, a4, a4_4);
        advManager::FizzleCenter(thisa, v90);
      }
      else
      {
        advManager::CompleteDraw(thisa, 0);
      }
      advManager::UpdateScreen(thisa, 0, 0);
      soundManager::SwitchAmbientMusic(gpSoundManager, (unsigned __int8)giTerrainToMusicTrack[thisa->currentTerrain]);
      WaitEndSample(-1, *(sample_resource *)a3a);
      CheckEndGame(0, 0);
      return;
    case LOCATION_WAGON_CAMP:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(84, 2, byte_516138, -1, 0, -1, 0, -1);
        if ( gpWindowManager->buttonPressedCode == 30725 )
          advManager::RecruitEvent(thisa, hero, 57, loc);
      }
      else
      {
        advManager::EventWindow(83, 1, byte_516134, -1, 0, -1, 0, -1);
      }
      goto LABEL_511;
    case LOCATION_DESRT_TENT:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        advManager::EventWindow(82, 2, byte_516140, -1, 0, -1, 0, -1);
        if ( gpWindowManager->buttonPressedCode == 30725 )
          advManager::RecruitEvent(thisa, hero, 58, loc);
      }
      else
      {
        advManager::EventWindow(81, 1, byte_51613C, -1, 0, -1, 0, -1);
      }
      goto LABEL_511;
    case LOCATION_ARCHERS_HOUSE:
    case LOCATION_GOBLIN_HUT:
    case LOCATION_DWARF_COTTAGE:
    case LOCATION_PEASANT_HUT:
    case LOCATION_LOG_CABIN:
    case LOCATION_WATCH_TOWER:
    case LOCATION_TREE_HOUSE:
    case LOCATION_DWARF_CABIN:
    case LOCATION_HALFLING_HOLE:
    case LOCATION_EXCAVATION:
    case LOCATION_CAVE:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::HouseEvent((int)hero, (int)loc);
      goto LABEL_511;
    case LOCATION_ARMY_CAMP:
      advManager::PlayerMonsterInteract(
        thisa,
        (int)loc,
        (int)loc,
        (int)hero,
        (signed int)&v86,
        __PAIR__(a4_4, a4),
        0,
        __PAIR__(a4_4, a4));
      goto LABEL_511;
    case LOCATION_OBELISK:
      if ( gpGame->field_6236[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 278] & (1 << hero->probablyOwnerIdx) )
      {
        advManager::EventWindow(69, 1, byte_516148, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        gpGame->field_6236[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 278] |= 1 << hero->probablyOwnerIdx;
        advManager::EventWindow(68, 1, byte_516144, -1, 0, -1, 0, -1);
        advManager::ViewPuzzle(thisa);
      }
      goto LABEL_511;
    case LOCATION_TREE_OF_KNOWLEDGE:
      if ( (1 << ((loc->flags >> 3) & 0x1F)) & *(_DWORD *)&hero->_5[24] )
      {
        NormalDialog(
          "{Tree of Knowledge}\n\nUpon your approach, the tree opens its eyes in delight.  \"It is good to see you, my student.  I hope my teachings have helped you.\"",
          1,
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
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        level = hero::GetLevel(hero->experience);
        v28 = hero::GetExperience(level + 1);
        xp = v28 - hero::GetExperience(level);
        v48 = (signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) >> 6;
        switch ( v48 )
        {
          case 1:
            NormalDialog(
              "{Tree of Knowledge}\n\nUpon your approach, the tree opens its eyes in delight.  \"Ahh, an adventurer!  Allow me to teach you a little of what I have learned over the ages.\"",
              1,
              -1,
              -1,
              14,
              -1,
              -1,
              0,
              -1,
              0);
            advManager::GiveExperience(hero, xp, 0);
            *(_DWORD *)&hero->_5[24] |= 1 << (((unsigned __int8)(loc->flags >> 8) >> -5) & 0x1F);
            break;
          case 2:
            if ( gpCurPlayer->resources[6] < 2000 )
            {
              NormalDialog(
                "{Tree of Knowledge}\n\nTears brim in the eyes of the tree.  \"I need 2000 gold.\" it whispers. (sniff)  \"Well, come back when you can pay me.\"",
                1,
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
              NormalDialog(
                "{Tree of Knowledge}\n\nUpon your approach, the tree opens its eyes in delight.  \"Ahh, an adventurer! I will be happy to teach you a little of what I have learned over the ages for a mere 2000 gold.\"  (Just bury it around my roots.)",
                2,
                -1,
                -1,
                14,
                -1,
                -1,
                0,
                -1,
                0);
              if ( gpWindowManager->buttonPressedCode == 30725 )
              {
                gpCurPlayer->resources[6] -= 2000;
                advManager::GiveExperience(hero, xp, 0);
                *(_DWORD *)&hero->_5[24] |= 1 << (((unsigned __int8)(loc->flags >> 8) >> -5) & 0x1F);
              }
            }
            break;
          case 3:
            if ( gpCurPlayer->resources[5] < 10 )
            {
              NormalDialog(
                "{Tree of Knowledge}\n\nTears brim in the eyes of the tree.  \"I need 10 gems.\" it whispers. (sniff)  \"Well, come back when you can pay me.\"",
                1,
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
              NormalDialog(
                "{Tree of Knowledge}\n\nAhh, an adventurer! I will be happy to teach you a little of what I have learned over the ages for a mere 10 gems.\"  (Just bury it around my roots.)",
                2,
                -1,
                -1,
                14,
                -1,
                -1,
                0,
                -1,
                0);
              if ( gpWindowManager->buttonPressedCode == 30725 )
              {
                gpCurPlayer->resources[5] -= 10;
                advManager::GiveExperience(hero, xp, 0);
                *(_DWORD *)&hero->_5[24] |= 1 << (((unsigned __int8)(loc->flags >> 8) >> -5) & 0x1F);
              }
            }
            break;
        }
      }
      hero::CheckLevel(hero);
      goto LABEL_511;
    case LOCATION_ORACLE:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::EventWindow(74, 1, byte_516540, -1, 0, -1, 0, -1);
      thisb = (heroWindow *)operator new(68);
      if ( thisb )
        a2a = (int)heroWindow::heroWindow(thisb, 0, 0, "thiefwin.bin");
      else
        a2a = 0;
      if ( !a2a )
        MemError();
      SetWinText((heroWindow *)a2a, 14);
      townManager::SetupThievesGuild((heroWindow *)a2a, 99);
      strcpy(gText, "Shrine - Player Rankings");
      evt.eventCode = INPUT_GUI_MESSAGE_CODE;
      evt.messageType = GUI_MESSAGE_SET_CONTENTS;
      evt.fieldID = 0;
      evt.payload = gText;
      heroWindow::BroadcastMessage((heroWindow *)a2a, (Event *)&evt);
      heroWindowManager::DoDialog(gpWindowManager, (heroWindow *)a2a, TrueFalseDialogHandler, 0);
      operator delete((void *)a2a);
      advManager::RedrawAdvScreen(thisa, 1, 0);
      goto LABEL_511;
    case LOCATION_SHRINE_FIRST:
      sprintf(
        gText,
        "%s'%s'.  ",
        "{Shrine of the 1st Circle}\n\nYou come across a small shrine attended by a group of novice acolytes.  In exchange for your protection, they agree to teach you a simple spell - ",
        dword_4F6ABC[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
      goto LABEL_333;
    case LOCATION_SHRINE_SECOND_ORDER:
      sprintf(
        gText,
        "%s'%s'.  ",
        "{Shrine of the 2nd Circle}\n\nYou come across an ornate shrine attended by a group of rotund friars.  In exchange for your protection, they agree to teach you a spell - ",
        dword_4F6ABC[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
      goto LABEL_333;
    case LOCATION_SHRINE_THIRD_ORDER:
      sprintf(
        gText,
        "%s'%s'.  ",
        "{Shrine of the 3rd Circle}\n\nYou come across a lavish shrine attended by a group of high priests.  In exchange for your protection, they agree to teach you a sophisticated spell - ",
        dword_4F6ABC[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
LABEL_333:
      if ( hero::HasArtifact(hero, ARTIFACT_MAGIC_BOOK) )
      {
        if ( gsSpellInfo[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1].level > hero->secondarySkillLevel[7]
                                                                                                + 2 )
        {
          strcat(
            gText,
            "Unfortunately, you do not have the wisdom to understand the spell, and you are unable to learn it.  ");
          advManager::EventWindow(-1, 1, gText, -1, 0, -1, 0, -1);
        }
        else
        {
          playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
          v29 = hero::Stats(hero, PRIMARY_SKILL_KNOWLEDGE);
          hero::AddSpell(hero, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1, v29);
          advManager::EventWindow(
            -1,
            1,
            gText,
            8,
            (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1,
            -1,
            0,
            -1);
        }
      }
      else
      {
        strcat(gText, "Unfortunately, you have no Magic Book to record the spell with.");
        advManager::EventWindow(-1, 1, gText, -1, 0, -1, 0, -1);
      }
      goto LABEL_511;
    case LOCATION_TOWN:
      advManager::TownEvent((int)thisa, (int)loc, __PAIR__(a4_4, a4));
      goto LABEL_511;
    case LOCATION_WHIRLPOOL:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::DoWhirlpool((int)hero);
      goto LABEL_343;
    case LOCATION_STONE_LITHS:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
LABEL_343:
      v70 = 0;
      for ( i = 0; i < MAP_HEIGHT; ++i )
      {
        for ( j = 0; MAP_WIDTH > j; ++j )
        {
          if ( *(&gpGame->map.tiles[j].objType + 12 * i * gpGame->map.width) == (unsigned __int8)((unsigned __int8)locType | 0x80) )
          {
            if ( *((_BYTE *)&gpGame->map.tiles[j].field_2 + 12 * i * gpGame->map.width + 1) == HIBYTE(loc->field_2) )
            {
              v30 = abs(j - a4);
              if ( abs(i - a4_4) + v30 > ((unsigned int)(locType - 36) < 1 ? 1 : 3) )
                ++v70;
            }
          }
        }
      }
      if ( v70 < 1 )
        goto LABEL_511;
      if ( v70 > 1 )
        v70 = Random(1, v70);
      i = 0;
LABEL_357:
      if ( i < MAP_HEIGHT )
      {
        for ( j = 0; ; ++j )
        {
          if ( MAP_WIDTH <= j )
          {
            ++i;
            goto LABEL_357;
          }
          if ( *(&gpGame->map.tiles[j].objType + 12 * i * gpGame->map.width) == (unsigned __int8)((unsigned __int8)locType | 0x80)
            && *((_BYTE *)&gpGame->map.tiles[j].field_2 + 12 * i * gpGame->map.width + 1) == HIBYTE(loc->field_2)
            && (j != a4 || i != a4_4) )
          {
            v31 = abs(j - a4);
            if ( abs(i - a4_4) + v31 > ((unsigned int)(locType - 36) < 1 ? 1 : 3) )
            {
              --v70;
              if ( v70 <= 0 )
                break;
            }
          }
        }
      }
      advManager::StopCursor(thisa, 1);
      advManager::TeleportTo(gpAdvManager, hero, j, i, 1, 0);
      goto LABEL_511;
    case LOCATION_ARTIFACT:
      v32 = loc->flags >> 3;
      v77 = (v32 & 0xF0u) >> 4;
      a5 = (signed int)HIBYTE(loc->field_2) >> 1;
      v33 = loc->flags >> 3;
      v83 = v33 & 0x7F;
      if ( hero::NumArtifacts(hero) == 14 )
      {
        NormalDialog("You cannot pick up this artifact, you already have a full load!", 1, -1, -1, -1, 0, -1, 0, -1, 0);
        goto LABEL_511;
      }
      if ( xIsPlayingExpansionCampaign && ExpCampaign::IsSpecialGoldenBow((int)&xCampaign, a4, a4_4) )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        strcpy(
          gText,
          "The fabled golden bow of the elves lies here in the dust.  You take it and journey back to the elven towns.  They shower you with their graciousness and the king promises that his people will aid you whenever you seek help.");
        advManager::EventWindow(-1, 1, gText, 7, a5, -1, 0, -1);
        GiveArtifact(hero, (ARTIFACT)a5, 1, (unsigned __int8)(loc->flags >> 8) >> -5);
        v86 = 1;
        v90 = 1;
        goto LABEL_511;
      }
      if ( a5 == 86 )
      {
        playTrackForLocationVisit(locType, 1, (_QWORD *)a3a);
        xTheSpell = (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
        advManager::EventWindow(-1, 1, *(&artifact_events + 86), 7, 86, -1, 0, -1);
        GiveArtifact(hero, ARTIFACT_SPELL_SCROLL, 1, (unsigned __int8)(loc->flags >> 8) >> -5);
        v86 = 1;
        v90 = 1;
        goto LABEL_511;
      }
      if ( ((unsigned __int16)(loc->flags >> 3) >> 8) & 1 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        if ( v83 == 57 )
        {
          NormalDialog(
            "{Artifact}\n\nYou come upon an ancient artifact.  As you reach for it, a pack of Rogues leap out of the brush to guard their stolen loot.",
            1,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
          v73 = 50;
        }
        else
        {
          v73 = 1;
          sprintf(
            gText,
            "{Artifact}\n\nThrough a clearing you observe an ancient artifact.  Unfortunately, it's guarded by a nearby %s.  Do you want to fight the %s for the artifact?",
            gArmyNames[v83],
            gArmyNames[v83]);
          NormalDialog(gText, 2, -1, -1, -1, 0, -1, 0, -1, 0);
          if ( gpWindowManager->buttonPressedCode != 30725 )
          {
            NormalDialog(
              "Discretion is the better part of valor, and you decide to avoid this fight for today.",
              1,
              -1,
              -1,
              -1,
              0,
              -1,
              0,
              -1,
              0);
            goto LABEL_511;
          }
        }
        if ( advManager::CombatMonsterEvent(
               thisa,
               hero,
               (CREATURES)v83,
               v73,
               loc,
               a4,
               a4_4,
               0,
               a4,
               a4_4,
               -1,
               0,
               0,
               -1,
               0,
               0) )
          goto LABEL_511;
        hero::CheckLevel(hero);
        sprintf(gText, "Victorious, you take your prize, the %s", gArtifactNames[a5]);
        NormalDialog(gText, 1, -1, -1, 7, (signed int)HIBYTE(loc->field_2) >> 1, -1, 0, -1, 0);
LABEL_392:
        GiveArtifact(hero, (ARTIFACT)a5, 1, -1);
        v86 = 1;
        v90 = 1;
      }
      else
      {
        v34 = loc->flags >> 3;
        switch ( v34 & 0xF )
        {
          case 4:
            if ( hero->secondarySkillLevel[7] )
              goto LABEL_391;
            sprintf(
              gText,
              "{Artifact}\n\nYou've found the humble dwelling of a withered hermit.  The hermit tells you that he is willing to give the %s to the first wise person he meets.",
              gArtifactNames[a5]);
            NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
            break;
          case 5:
            if ( hero->secondarySkillLevel[6] )
              goto LABEL_391;
            sprintf(
              gText,
              "{Artifact}\n\nYou've come across the spartan quarters of a retired soldier.  The soldier tells you that he is willing to pass on the %s to the first true leader he meets.",
              gArtifactNames[a5]);
            NormalDialog(gText, 1, -1, -1, -1, 0, -1, 0, -1, 0);
            break;
          case 1:
LABEL_391:
            playTrackForLocationVisit(
              locType,
              (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
              (_QWORD *)a3a);
            advManager::EventWindow(-1, 1, (&artifact_events)[4 * a5], 7, a5, -1, 0, -1);
            goto LABEL_392;
          case 3:
            playTrackForLocationVisit(
              locType,
              (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
              (_QWORD *)a3a);
            sprintf(
              gText,
              "{Artifact}\n\nA leprechaun offers you the %s for the small price of 2000 gold.  Do you wish to buy this artifact?",
              gArtifactNames[a5]);
            advManager::EventWindow(-1, 2, gText, 7, a5, -1, 0, -1);
            if ( gpWindowManager->buttonPressedCode == 30725 )
            {
              if ( gpGame->players[hero->probablyOwnerIdx].resources[6] >= 2000 )
              {
                gpGame->players[hero->probablyOwnerIdx].resources[6] -= 2000;
                goto LABEL_392;
              }
              NormalDialog(
                "You try to pay the leprechaun, but realize that you can't afford it.  The leprechaun stamps his foot and ignores you.",
                1,
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
              NormalDialog(
                "Insulted by your refusal of his generous offer, the leprechaun stamps his foot and ignores you.",
                1,
                -1,
                -1,
                -1,
                0,
                -1,
                0,
                -1,
                0);
            }
            break;
          case 6:
            playTrackForLocationVisit(
              locType,
              (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
              (_QWORD *)a3a);
            sprintf(&a1, gResourceNames[v77]);
            a1 += 32;
            sprintf(
              gText,
              "{Artifact}\n\nA leprechaun offers you the %s for the small price of 2500 gold and 3 %s.  Do you wish to buy this artifact?",
              gArtifactNames[a5],
              &a1);
            NormalDialog(gText, 2, -1, -1, 7, a5, -1, 0, -1, 0);
            if ( gpWindowManager->buttonPressedCode == 30725 )
            {
              if ( gpGame->players[hero->probablyOwnerIdx].resources[6] >= 2500
                && gpGame->players[hero->probablyOwnerIdx].resources[v77] >= 3 )
              {
                gpGame->players[hero->probablyOwnerIdx].resources[6] -= 2500;
                v35 = 283 * hero->probablyOwnerIdx + 4 * v77;
                *(int *)((char *)gpGame->players[0].resources + v35) -= 3;
                goto LABEL_392;
              }
              NormalDialog(
                "You try to pay the leprechaun, but realize that you can't afford it.  The leprechaun stamps his foot and ignores you.",
                1,
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
              NormalDialog(
                "Insulted by your refusal of his generous offer, the leprechaun stamps his foot and ignores you.",
                1,
                -1,
                -1,
                -1,
                0,
                -1,
                0,
                -1,
                0);
            }
            break;
          case 7:
            playTrackForLocationVisit(
              locType,
              (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
              (_QWORD *)a3a);
            sprintf(&a1, gResourceNames[v77]);
            a1 += 32;
            sprintf(
              gText,
              "{Artifact}\n\nA leprechaun offers you the %s for the small price of 3000 gold and 5 %s.  Do you wish to buy this artifact?",
              gArtifactNames[a5],
              &a1);
            NormalDialog(gText, 2, -1, -1, 7, a5, -1, 0, -1, 0);
            if ( gpWindowManager->buttonPressedCode == 30725 )
            {
              if ( gpGame->players[hero->probablyOwnerIdx].resources[6] >= 3000
                && gpGame->players[hero->probablyOwnerIdx].resources[v77] >= 5 )
              {
                gpGame->players[hero->probablyOwnerIdx].resources[6] -= 3000;
                v36 = 283 * hero->probablyOwnerIdx + 4 * v77;
                *(int *)((char *)gpGame->players[0].resources + v36) -= 5;
                goto LABEL_392;
              }
              NormalDialog(
                "You try to pay the leprechaun, but realize that you can't afford it.  The leprechaun stamps his foot and ignores you.",
                1,
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
              NormalDialog(
                "Insulted by your refusal of his generous offer, the leprechaun stamps his foot and ignores you.",
                1,
                -1,
                -1,
                -1,
                0,
                -1,
                0,
                -1,
                0);
            }
            break;
          default:
            break;
        }
      }
      hero::CheckLevel(hero);
      goto LABEL_511;
    case LOCATION_HERO:
      advManager::DemobilizeCurrHero(thisa);
      v79 = &gpGame->heroes[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)];
      if ( *((_BYTE *)v79 + 3) == giCurPlayer )
      {
        advManager::HeroSwap(thisa, (int)hero, (int)v79);
      }
      else
      {
        v56 = 0;
        if ( *(_WORD *)((char *)v79 + 45) == 163 )
        {
          v56 = &gpGame->castles[*(_WORD *)((char *)v79 + 47)];
          *((_BYTE *)v56 + 23) = *((_BYTE *)v79 + 2);
        }
        v80 = advManager::DoCombat(
                thisa,
                __PAIR__(a4_4, a4),
                (int)hero,
                &hero->army,
                (int)v56,
                (int)v79,
                (char *)v79 + 101,
                a4,
                a4_4,
                -1,
                1);
        if ( !v80 && v56 )
          game::ClaimTown(gpGame, *(_BYTE *)v56, giCurPlayer, 0);
      }
      goto LABEL_511;
    case LOCATION_BOTTLE:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        v92 = *((_DWORD *)ppMapExtra + (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5));
        if ( (unsigned int)strlen(v92 + 9) <= 1 )
          advManager::EventWindow(-1, 1, (&off_4F70C8)[4 * (unsigned __int8)((char)a4 % -4)], -1, 0, -1, 0, -1);
        else
          advManager::EventWindow(-1, 1, (const char *)(v92 + 9), -1, 0, -1, 0, -1);
      }
      v90 = 1;
      v86 = 1;
      goto LABEL_511;
    case LOCATION_SIGN:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        v92 = *((_DWORD *)ppMapExtra + (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5));
        if ( (unsigned int)strlen(v92 + 9) <= 1 )
          advManager::EventWindow(-1, 1, (&off_4F70C8)[4 * (unsigned __int8)((char)a4 % -4)], -1, 0, -1, 0, -1);
        else
          advManager::EventWindow(-1, 1, (const char *)(v92 + 9), -1, 0, -1, 0, -1);
      }
      goto LABEL_511;
    case LOCATION_DAEMON_CAVE:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::EventWindow(
        -1,
        2,
        "{Daemon Cave}\n\nThe entrance to the cave is dark, and a foul, sulfurous smell issues from the cave mouth.  Will you enter?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( gpWindowManager->buttonPressedCode != 30726 )
      {
        if ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) == 1 )
        {
          advManager::EventWindow(
            -1,
            1,
            "Except for evidence of a terrible battle, the cave is empty.",
            -1,
            0,
            -1,
            0,
            -1);
        }
        else
        {
          v37 = loc->flags >> 3;
          v78 = ((v37 & 0xF0u) >> 4) + 62;
          sprintf(
            gText,
            "You find a powerful and grotesque Demon in the cave.  \"Today,\" it rasps, \"you will fight and surely die.  But I will give you a choice of deaths.  You may fight me, or you may fight my servants.  Do you prefer to fight my servants?\"");
          advManager::EventWindow(-1, 2, gText, -1, 0, -1, 0, -1);
          if ( gpWindowManager->buttonPressedCode == 30725 )
          {
            if ( !advManager::CombatMonsterEvent(
                    thisa,
                    hero,
                    (CREATURES)v78,
                    8,
                    loc,
                    a4,
                    a4_4,
                    0,
                    a4,
                    a4_4,
                    -1,
                    0,
                    0,
                    -1,
                    0,
                    0) )
            {
              hero::CheckLevel(hero);
              NormalDialog(
                "Upon defeating the daemon's servants, you find a hidden cache with 2500 gold.",
                1,
                -1,
                -1,
                6,
                2500,
                -1,
                0,
                -1,
                0);
              advManager::GiveResource(thisa, hero, 6, 2500);
              v38 = loc->flags & 7;
              LOBYTE(v38) = v38 | 8;
              loc->flags = v38;
            }
          }
          else
          {
            v39 = loc->flags >> 3;
            switch ( v39 & 0xF )
            {
              case 2:
                advManager::GiveExperience(hero, 1000, 0);
                advManager::EventWindow(
                  -1,
                  1,
                  "The Demon screams its challenge and attacks!  After a short, desperate battle, you slay the monster and receive 1,000 experience points.",
                  14,
                  1000,
                  -1,
                  0,
                  -1);
                v40 = loc->flags & 7;
                LOBYTE(v40) = v40 | 8;
                loc->flags = v40;
                hero::CheckLevel(hero);
                break;
              case 3:
                if ( hero::NumArtifacts(hero) == 14 || game::GetRandomArtifactId(gpGame, 14, 1) == -1 )
                  goto LABEL_445;
                advManager::GiveExperience(hero, 1000, 0);
                a2 = advManager::GiveRandomArtifact(hero);
                sprintf(
                  gText,
                  "The Demon screams its challenge and attacks!  After a short, desperate battle, you slay the monster and find the %s in the back of the cave.",
                  gArtifactNames[a2]);
                advManager::EventWindow(-1, 1, gText, 7, a2, 14, 1000, -1);
                v41 = loc->flags & 7;
                LOBYTE(v41) = v41 | 8;
                loc->flags = v41;
                hero::CheckLevel(hero);
                break;
              case 4:
LABEL_445:
                advManager::EventWindow(
                  -1,
                  1,
                  "The Demon screams its challenge and attacks!  After a short, desperate battle, you slay the monster and receive 1,000 experience points and 2,500 gold.",
                  6,
                  2500,
                  14,
                  1000,
                  -1);
                advManager::GiveExperience(hero, 1000, 0);
                advManager::GiveResource(thisa, hero, 6, 2500);
                v42 = loc->flags & 7;
                LOBYTE(v42) = v42 | 8;
                loc->flags = v42;
                hero::CheckLevel(hero);
                break;
              case 5:
                advManager::EventWindow(
                  -1,
                  2,
                  "The Demon leaps upon you and has its claws at your throat before you can even draw your sword.  \"Your life is mine,\" it says.  \"I will sell it back to you for 2,500 gold.\"",
                  -1,
                  0,
                  -1,
                  0,
                  -1);
                if ( gpWindowManager->buttonPressedCode == 30725 )
                {
                  if ( gpGame->players[hero->probablyOwnerIdx].resources[6] >= 2500 )
                  {
                    gpGame->players[hero->probablyOwnerIdx].resources[6] -= 2500;
                  }
                  else
                  {
                    advManager::EventWindow(
                      -1,
                      1,
                      "Seeing that you do not have 2500 gold, the demon slashes you with its claws, and the last thing you see is a red haze.",
                      -1,
                      0,
                      -1,
                      0,
                      -1);
                    advManager::HeroLoses((int)thisa, (int)hero);
                  }
                }
                else
                {
                  advManager::HeroLoses((int)thisa, (int)hero);
                }
                break;
              default:
                break;
            }
            v43 = loc->flags & 7;
            LOBYTE(v43) = v43 | 8;
            loc->flags = v43;
          }
        }
      }
      goto LABEL_511;
    case LOCATION_SHIPWRECK:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::EventWindow(
        -1,
        2,
        "{Shipwreck}\n\nThe rotting hulk of a great pirate ship creaks eerily as it is pushed against the rocks.  Do you wish to search the shipwreck?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( gpWindowManager->buttonPressedCode == 30725 )
      {
        if ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) == 1 )
        {
          advManager::EventWindow(
            -1,
            1,
            "Upon defeating the Ghosts you spend several hours sifting through the debris and find nothing.  Such a despicable act reduces your army's morale.",
            13,
            0,
            -1,
            0,
            -1);
          if ( !(hero->flags1 & 0x40) )
          {
            *(_DWORD *)&hero->flags1 |= 0x40u;
            --hero->_5[1];
          }
        }
        else if ( advManager::GhostEvent(
       thisa,
       hero,
       loc,
       "Upon defeating the Ghosts you sift through the debris and find something!",
       __PAIR__(a4_4, a4)) )
        {
          v44 = loc->flags & 7;
          LOBYTE(v44) = v44 | 8;
          loc->flags = v44;
        }
      }
      goto LABEL_511;
    case LOCATION_GRAVEYARD:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::EventWindow(20, 2, byte_517684, -1, 0, -1, 0, -1);
      if ( gpWindowManager->buttonPressedCode == 30725 )
      {
        if ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) == 1 )
        {
          advManager::EventWindow(21, 1, byte_517688, 13, 0, -1, 0, -1);
          if ( !(hero->flags1 & 0x20) )
          {
            *(_DWORD *)&hero->flags1 |= 0x20u;
            --hero->_5[1];
          }
        }
        else
        {
          v55 = (int)advManager::GetCell(
                       thisa,
                       a4 - normalDirTable[4 * HIBYTE(hero->field_2B)],
                       a4_4 - byte_4F1DC1[4 * HIBYTE(hero->field_2B)]);
          if ( advManager::ZombieEvent(thisa, hero, (mapCell *)v55, gEventText[22], a4, a4_4) )
          {
            v45 = loc->flags & 7;
            LOBYTE(v45) = v45 | 8;
            loc->flags = v45;
          }
        }
      }
      goto LABEL_511;
    case LOCATION_DERELICT_SHIP:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::EventWindow(
        -1,
        2,
        "{Derelict Ship}\n\nThe rotting hulk of a great pirate ship creaks eerily as it is pushed against the rocks.  Do you wish to search the ship?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( gpWindowManager->buttonPressedCode == 30725 )
      {
        if ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) == 1 )
        {
          advManager::EventWindow(
            -1,
            1,
            "Upon defeating the Skeletons you spend several hours sifting through the debris and find nothing.  Such a despicable act reduces your army's morale.",
            13,
            0,
            -1,
            0,
            -1);
          if ( !(hero->flags2 & 4) )
          {
            *(_DWORD *)&hero->flags1 |= 0x400u;
            --hero->_5[1];
          }
        }
        else
        {
          v54 = (int)advManager::GetCell(
                       thisa,
                       a4 - normalDirTable[4 * HIBYTE(hero->field_2B)],
                       a4_4 - byte_4F1DC1[4 * HIBYTE(hero->field_2B)]);
          if ( advManager::SkeletonEvent(
                 (int)thisa,
                 (int)hero,
                 v54,
                 "Upon defeating the Skeletons you sift through the debris and find something!",
                 __PAIR__(a4_4, a4)) )
          {
            v46 = loc->flags & 7;
            LOBYTE(v46) = v46 | 8;
            loc->flags = v46;
          }
        }
      }
      goto LABEL_511;
    case LOCATION_PYRAMID:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::EventWindow(
        -1,
        2,
        "You come upon the pyramid of a great and ancient king.  You are tempted to search it for treasure, but all the old stories warn of fearful curses and undead guardians.  Will you search?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( gpWindowManager->buttonPressedCode == 30725 )
      {
        if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
        {
          if ( !advManager::CombatMonsterEvent(
                  thisa,
                  hero,
                  CREATURE_ROYAL_MUMMY,
                  30,
                  loc,
                  a4,
                  a4_4,
                  0,
                  a4,
                  a4_4,
                  53,
                  20,
                  2,
                  -1,
                  0,
                  0) )
          {
            hero::CheckLevel(hero);
            sprintf(
              msg,
              "%s'%s'.  ",
              "Upon defeating the monsters, you decipher an ancient glyph on the wall, telling the secret of the spell - ",
              dword_4F6ABC[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
            if ( hero::HasArtifact(hero, ARTIFACT_MAGIC_BOOK) )
            {
              if ( hero->secondarySkillLevel[7] < 3 )
              {
                strcat(
                  msg,
                  "  Unfortunately, you do not have the wisdom to understand the spell, and you are unable to learn it.  ");
                advManager::EventWindow(-1, 1, msg, -1, 0, -1, 0, -1);
              }
              else
              {
                v47 = hero::Stats(hero, PRIMARY_SKILL_KNOWLEDGE);
                hero::AddSpell(hero, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1, v47);
                advManager::EventWindow(
                  -1,
                  1,
                  msg,
                  8,
                  (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1,
                  -1,
                  0,
                  -1);
              }
            }
            else
            {
              strcat(msg, "  Unfortunately, you have no Magic Book to record the spell with.");
              advManager::EventWindow(-1, 1, msg, -1, 0, -1, 0, -1);
            }
            loc->flags &= 7u;
          }
        }
        else
        {
          NormalDialog(
            "You come upon the pyramid of a great and ancient king.  Routine exploration reveals that the pyramid is completely empty.",
            1,
            -1,
            -1,
            11,
            0,
            11,
            0,
            -1,
            0);
          if ( !(hero->flags2 & 0x40) )
          {
            *(_DWORD *)&hero->flags1 |= 0x4000u;
            hero->_5[2] -= 2;
          }
        }
      }
      goto LABEL_511;
    case LOCATION_ABANDONED_MINE:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      advManager::EventWindow(
        -1,
        2,
        "You come upon an abandoned gold mine.  The mine appears to be haunted.  Do you wish to enter?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( gpWindowManager->buttonPressedCode == 30725
        && !advManager::CombatMonsterEvent(
              thisa,
              hero,
              (CREATURES)gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 3],
              gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 4],
              loc,
              a4,
              a4_4,
              0,
              a4,
              a4_4,
              -1,
              0,
              0,
              -1,
              0,
              0) )
      {
        hero::CheckLevel(hero);
        advManager::EventWindow(
          -1,
          1,
          "You beat the Ghosts and are able to restore the mine to production.",
          -1,
          0,
          -1,
          0,
          -1);
        game::ConvertObject(gpGame, a4 - 2, a4_4 - 1, a4 + 1, a4_4 - 1, 56, 0, 4, 26, 104, 64, 23);
        game::ConvertObject(gpGame, a4 - 2, a4_4, a4 + 1, a4_4, 56, 5, 9, 26, 109, 64, 23);
        game::ConvertObject(gpGame, a4 - 2, a4_4 - 1, a4 + 1, a4_4 - 1, 51, 0, 3, 32, 75, 64, 23);
        game::ConvertObject(gpGame, a4 - 2, a4_4, a4 + 1, a4_4, 51, 4, 7, 32, 80, 64, 23);
        game::ConvertObject(gpGame, a4, a4_4, a4, a4_4, 29, 5, 5, 29, 4, 64, 23);
        gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 2] = 6;
        gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 3] = -1;
        gpGame->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 4] = 0;
        game::ClaimMine(gpGame, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), giCurPlayer);
      }
      goto LABEL_511;
    case LOCATION_BARRIER:
      v86 = advManager::BarrierEvent(loc, hero);
      goto LABEL_511;
    case LOCATION_TRAVELLER_TENT:
      advManager::PasswordEvent(loc, hero);
      goto LABEL_511;
    case LOCATION_ALCHEMIST_TOWER:
      advManager::GenericSiteEvent(thisa, (int)loc, hero);
      goto LABEL_511;
    case LOCATION_EXPANSION_DWELLING:
      advManager::RecruitSiteEvent((int)loc, (int)hero);
      goto LABEL_511;
    case LOCATION_JAIL:
      advManager::JailEvent(thisa, (int)loc, (int)hero, a4, a4_4);
      goto LABEL_511;
    case LOCATION_ROAD:
    case LOCATION_EVENT:
    case LOCATION_WELL:
    case LOCATION_WINDMILL|LOCATION_SKELETON:
    case LOCATION_RANDOM_ARTIFACT:
    case LOCATION_RANDOM_RESOURCE:
    case LOCATION_RANDOM_MONSTER:
    case LOCATION_RANDOM_TOWN:
    case LOCATION_RANDOM_CASTLE:
    case LOCATION_RANDOM_TOWN|LOCATION_SIGN:
    case LOCATION_RANDOM_MONSTER_WEAK:
    case LOCATION_RANDOM_MONSTER_MEDIUM:
    case LOCATION_RANDOM_MONSTER_STRONG:
    case LOCATION_RANDOM_MONSTER_VERY_STRONG:
    case LOCATION_RANDOM_HERO:
    case LOCATION_NOTHING_SPECIAL:
    case LOCATION_NOTHING_SPECIAL|LOCATION_ALCHEMIST_LAB:
    case LOCATION_TAR_PIT:
    case LOCATION_STREAM:
    case LOCATION_TREES:
    case LOCATION_MOUNTAINS:
    case LOCATION_VOLCANO:
    case LOCATION_FLOWERS:
    case LOCATION_ROCK:
    case LOCATION_LAKE:
    case LOCATION_MANDRAKE:
    case LOCATION_DEAD_TREE:
    case LOCATION_STUMP:
    case LOCATION_CRATER:
    case LOCATION_CACTUS:
    case LOCATION_MOUND:
    case LOCATION_DUNE:
    case LOCATION_LAVA_POOL:
    case LOCATION_SHRUB:
    case LOCATION_HOLE:
    case LOCATION_OUTCROPPING:
    case LOCATION_RANDOM_ARTIFACT_TREASURE:
    case LOCATION_RANDOM_ARTIFACT_MINOR:
    case LOCATION_RANDOM_ARTIFACT_MAJOR:
      goto LABEL_511;
  }
}
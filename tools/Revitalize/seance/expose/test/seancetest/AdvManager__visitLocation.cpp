void __thiscall AdvManager::visitLocation(AdvManager *ecx0, MapTile *loc, __int64 a4)
{
  __int16 v3; // ax@78
  __int16 v4; // ax@78
  __int16 v5; // ax@78
  char v6; // al@106
  unsigned __int16 v7; // ax@140
  __int16 v8; // ax@141
  __int16 v9; // ax@141
  __int16 v10; // ax@141
  __int16 v11; // ax@176
  int v12; // ST28_4@176
  __int16 v13; // ax@176
  __int16 v14; // ax@176
  int v15; // ST38_4@176
  __int16 v16; // ax@176
  __int16 v17; // ax@182
  __int16 v18; // ax@183
  int v19; // ST2C_4@183
  __int16 v20; // ax@183
  __int16 v21; // ax@183
  int v22; // ST38_4@183
  __int16 v23; // ax@183
  unsigned __int16 v24; // ax@189
  __int16 v25; // ax@193
  __int16 v26; // ax@193
  int v27; // ebx@304
  char v28; // al@333
  int v29; // ebx@347
  int v30; // ebx@361
  __int16 v31; // ax@367
  __int16 v32; // ax@367
  __int16 v33; // ax@410
  int v34; // eax@399
  int v35; // eax@406
  __int16 v36; // ax@433
  unsigned __int16 v37; // ax@435
  __int16 v38; // ax@450
  unsigned __int16 v39; // ax@438
  unsigned __int16 v40; // ax@441
  unsigned __int16 v41; // ax@442
  unsigned __int16 v42; // ax@451
  unsigned __int16 v43; // ax@458
  unsigned __int16 v44; // ax@469
  unsigned __int16 v45; // ax@480
  char v46; // al@494
  signed int v47; // [sp+14h] [bp-33Ch]@304
  AdvManager *thisa; // [sp+24h] [bp-32Ch]@1
  int v49; // [sp+2Ch] [bp-324h]@228
  int amt; // [sp+30h] [bp-320h]@225
  GUIWindow *this; // [sp+38h] [bp-318h]@322
  char msg[4]; // [sp+44h] [bp-30Ch]@491
  int v53; // [sp+238h] [bp-118h]@479
  int v54; // [sp+23Ch] [bp-114h]@468
  void *v55; // [sp+240h] [bp-110h]@414
  signed int level; // [sp+244h] [bp-10Ch]@304
  int xp; // [sp+248h] [bp-108h]@304
  int v58; // [sp+24Ch] [bp-104h]@273
  int v59; // [sp+250h] [bp-100h]@122
  int v60; // [sp+254h] [bp-FCh]@117
  int maxSP; // [sp+258h] [bp-F8h]@112
  int v62; // [sp+25Ch] [bp-F4h]@106
  int a8; // [sp+260h] [bp-F0h]@16
  int a7; // [sp+264h] [bp-ECh]@16
  signed int img1Type; // [sp+268h] [bp-E8h]@16
  signed int a6; // [sp+26Ch] [bp-E4h]@16
  int v67; // [sp+270h] [bp-E0h]@10
  char *v68; // [sp+274h] [bp-DCh]@119
  int v69; // [sp+278h] [bp-D8h]@341
  signed int type; // [sp+27Ch] [bp-D4h]@224
  int a2a; // [sp+280h] [bp-D0h]@323
  int v72; // [sp+284h] [bp-CCh]@376
  unsigned int i; // [sp+288h] [bp-C8h]@341
  unsigned int j; // [sp+28Ch] [bp-C4h]@343
  int a5; // [sp+290h] [bp-C0h]@367
  unsigned int v76; // [sp+294h] [bp-BCh]@367
  int v77; // [sp+298h] [bp-B8h]@433
  void *v78; // [sp+29Ch] [bp-B4h]@412
  int v79; // [sp+2A0h] [bp-B0h]@416
  int v80; // [sp+2A4h] [bp-ACh]@7
  int v81; // [sp+2A8h] [bp-A8h]@126
  int v82; // [sp+2ACh] [bp-A4h]@367
  GUIMessage evt; // [sp+2B0h] [bp-A0h]@327
  int locType; // [sp+2CCh] [bp-84h]@1
  int v85; // [sp+2ECh] [bp-64h]@1
  char v86; // [sp+2F0h] [bp-60h]@10
  int v87; // [sp+324h] [bp-2Ch]@34
  int v88; // [sp+328h] [bp-28h]@34
  int v89; // [sp+32Ch] [bp-24h]@1
  int a2; // [sp+330h] [bp-20h]@10
  int v91; // [sp+334h] [bp-1Ch]@421
  int v92; // [sp+338h] [bp-18h]@34
  Hero *hero; // [sp+33Ch] [bp-14h]@1
  sample_resource res; // [sp+340h] [bp-10h]@1
  int a3a[2]; // [sp+348h] [bp-8h]@1

  thisa = ecx0;
  hero = &gameObject->heroes[curPlayer->_1[0]];
  locType = loc->objType & 0x7F;
  v85 = 0;
  v89 = 0;
  res = stru_5230F8;
  MouseManager::enableCursor(mouseManager);
  MouseManager::setSpriteIdx(mouseManager, 0);
  *(_QWORD *)a3a = stru_5230F8;
  switch ( locType )
  {
    case LOCATION_TRADING_POST:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      sub_40EDB0(0, 1045220557);
      goto LABEL_508;
    case LOCATION_MAGIC_GARDEN:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(
          -1,
          1,
          "{Magic Garden}\n\nYou catch a leprechaun foolishly sleeping amidst a cluster of magic mushrooms.  In exchange for his freedom, he guides you to a small pot filled with precious things.",
          (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1,
          (unsigned int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 7 < 1 ? 500 : 5,
          -1,
          0,
          -1);
        grantResource(
          hero,
          (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1,
          (unsigned int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 7 < 1 ? 500 : 5);
        loc->flags &= 7u;
      }
      else
      {
        showMessageWindowForEvent(
          -1,
          1,
          "{Magic Garden}\n\nYou've found a magic garden, the kind of place that leprechauns and faeries like to cavort in, but there is no one here today.  Perhaps you should try again next week.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_508;
    case LOCATION_SPHINX:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      v80 = *((_DWORD *)dword_524784 + (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5));
      if ( *(_BYTE *)v80 )
      {
        sprintf(
          globBuf,
          "\"I have a riddle for you,\" the Sphinx says.  \"Answer correctly, and you shall be rewarded.  Answer incorrectly, and you shall be eaten.  Do you accept the challenge?\"");
        display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
        if ( HeroWindowManager::instance->buttonPressedCode == 0x7805 )
        {
          sprintf(globBuf, "The Sphinx asks you the following riddle:\n\n'%s'\n\nYour answer?", v80 + 136);
          sub_4CAEF0(globBuf, (int)&v86, 12, 0, 0, 1);
          v67 = 0;
          for ( a2 = 0; *(_BYTE *)(v80 + 31) > a2; ++a2 )
          {
            if ( sub_494940(&v86, (const char *)(13 * a2 + v80 + 32)) )
              v67 = 1;
          }
          if ( v67 )
          {
            img1Type = -1;
            a6 = 0;
            a7 = -1;
            a8 = 0;
            for ( a2 = 0; a2 < 7; ++a2 )
            {
              gameObject->players[curPlayerIdx].resources[a2] += *(_DWORD *)(v80 + 4 * a2 + 1);
              if ( gameObject->players[curPlayerIdx].resources[a2] < 0 )
                gameObject->players[curPlayerIdx].resources[a2] = 0;
              if ( *(_DWORD *)(v80 + 4 * a2 + 1) )
              {
                if ( img1Type != -1 )
                {
                  a7 = img1Type;
                  a8 = a6;
                }
                img1Type = a2;
                a6 = *(_DWORD *)(v80 + 4 * a2 + 1);
              }
            }
            if ( *(_WORD *)(v80 + 29) != -1 && Hero::numArtifacts(hero) < 14 )
            {
              grantArtifact(hero, (ARTIFACT)*(_WORD *)(v80 + 29), 1, -1);
              if ( img1Type != -1 )
              {
                a7 = img1Type;
                a8 = a6;
              }
              img1Type = 7;
              a6 = *(_WORD *)(v80 + 29);
            }
            display_message_window(
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
            *(_BYTE *)v80 = 0;
          }
          else
          {
            display_message_window(
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
            sub_48F630((int)thisa, (int)hero);
          }
        }
      }
      else
      {
        display_message_window(
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
      goto LABEL_508;
    case LOCATION_OBSERVATION_TOWER:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      display_message_window(
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
      explore(a4, SHIDWORD(a4), curPlayerIdx, 20);
      sub_448110(thisa, 0);
      sub_447A00(thisa, 0, 0);
      goto LABEL_508;
    case LOCATION_HILL_FORT:
      v92 = -1;
      v87 = -1;
      v88 = -1;
      if ( Hero::numStacksOfCreatureType(hero, CREATURE_OGRE) )
        v88 = CREATURE_OGRE;
      if ( Hero::numStacksOfCreatureType(hero, CREATURE_ORC) )
      {
        if ( v88 == -1 )
          v88 = CREATURE_ORC;
        else
          v87 = CREATURE_ORC;
      }
      if ( Hero::numStacksOfCreatureType(hero, CREATURE_DWARF) )
      {
        if ( v88 == -1 )
        {
          v88 = CREATURE_DWARF;
        }
        else
        {
          if ( v87 == -1 )
            v87 = CREATURE_DWARF;
          else
            v92 = CREATURE_DWARF;
        }
      }
      if ( v88 == -1 )
      {
        showMessageWindowForEvent(
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
        Hero::transmuteStacks(hero, CREATURE_OGRE, CREATURE_OGRE_LORD);
        Hero::transmuteStacks(hero, CREATURE_ORC, CREATURE_ORC_CHIEF);
        Hero::transmuteStacks(hero, CREATURE_DWARF, CREATURE_BATTLE_DWARF);
        if ( v92 == -1 )
        {
          if ( v87 == -1 )
            sprintf(
              globBuf,
              "{Hill Fort}\n\nAll of the %s you have in your army have been trained by the battle masters of the fort.  Your army now contains %s.",
              creaturePluralNames[v88],
              creaturePluralNames[v88 + 1]);
          else
            sprintf(
              globBuf,
              "{Hill Fort}\n\nAll of the %s and %s you have in your army have been trained by the battle masters of the fort.  Your army now contains %s and %s.",
              creaturePluralNames[v88],
              creaturePluralNames[v87],
              creaturePluralNames[v88 + 1],
              creaturePluralNames[v87 + 1]);
        }
        else
        {
          sprintf(
            globBuf,
            "{Hill Fort}\n\n All of the %s, %s and %s you have in your army have been trained by the battle masters of the fort.  Your army now contains %s, %s, and %s.",
            creaturePluralNames[v88],
            creaturePluralNames[v87],
            creaturePluralNames[v92],
            creaturePluralNames[v88 + 1],
            creaturePluralNames[v87 + 1],
            creaturePluralNames[v92 + 1]);
        }
        showMessageWindowForEvent(-1, 1, globBuf, 18, v88 + 1, (unsigned int)(v87 + 1) < 1 ? -1 : 18, v87 + 1, -1);
      }
      goto LABEL_508;
    case LOCATION_FREEMANS_FOUNDRY:
      v92 = -1;
      v87 = -1;
      v88 = -1;
      if ( Hero::numStacksOfCreatureType(hero, CREATURE_PIKEMAN) )
        v88 = 3;
      if ( Hero::numStacksOfCreatureType(hero, CREATURE_SWORDSMAN) )
      {
        if ( v88 == -1 )
          v88 = 5;
        else
          v87 = 5;
      }
      if ( Hero::numStacksOfCreatureType(hero, CREATURE_IRON_GOLEM) )
      {
        if ( v88 == -1 )
        {
          v88 = 40;
        }
        else
        {
          if ( v87 == -1 )
            v87 = 40;
          else
            v92 = 40;
        }
      }
      if ( v88 == -1 )
      {
        showMessageWindowForEvent(
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
        Hero::transmuteStacks(hero, 3, 4);
        Hero::transmuteStacks(hero, 5, 6);
        Hero::transmuteStacks(hero, 40, 41);
        if ( v92 == -1 )
        {
          if ( v87 == -1 )
            sprintf(
              globBuf,
              "{Freeman's Foundry}\n\nAll of your %s have been upgraded into %s.",
              creaturePluralNames[v88],
              creaturePluralNames[v88 + 1]);
          else
            sprintf(
              globBuf,
              "{Freeman's Foundry}\n\nAll of your %s and %s have been upgraded into %s and %s.",
              creaturePluralNames[v88],
              creaturePluralNames[v87],
              creaturePluralNames[v88 + 1],
              creaturePluralNames[v87 + 1]);
        }
        else
        {
          sprintf(
            globBuf,
            "{Freeman's Foundry}\n\nAll of your  %s, %s and %s have been upgraded into %s, %s, and %s.",
            creaturePluralNames[v88],
            creaturePluralNames[v87],
            creaturePluralNames[v92],
            creaturePluralNames[v88 + 1],
            creaturePluralNames[v87 + 1],
            creaturePluralNames[v92 + 1]);
        }
        showMessageWindowForEvent(-1, 1, globBuf, 18, v88 + 1, (unsigned int)(v87 + 1) < 1 ? -1 : 18, v87 + 1, -1);
      }
      goto LABEL_508;
    case LOCATION_SEA_CHEST:
      if ( ((unsigned __int16)(loc->flags >> 3) >> 8) & 1 && Hero::numArtifacts(hero) < 14 )
      {
        v3 = loc->flags >> 3;
        sprintf(
          globBuf,
          "{Chest}\n\nAfter spending hours trying to fish the chest out of the sea, you open it and find 1000 gold and the %s",
          artifactNames[(unsigned __int8)v3]);
        v4 = loc->flags >> 3;
        display_message_window(globBuf, 1, -1, -1, 7, (unsigned __int8)v4, 6, 1000, -1, 0);
        v5 = loc->flags >> 3;
        grantArtifact(hero, (ARTIFACT)(unsigned __int8)v5, 1, -1);
        grantResource(hero, 6, 1000);
      }
      else
      {
        if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
        {
          display_message_window(
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
          grantResource(hero, 6, 1500);
        }
        else
        {
          display_message_window(
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
      }
      v89 = 1;
      v85 = 1;
      goto LABEL_508;
    case LOCATION_FLOTSAM:
      switch ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) )
      {
        case 0u:
          display_message_window(
            "{Flotsam}\n\nYou search through the flotsam, but find nothing.",
            1,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
          break;
        case 1u:
          display_message_window(
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
          grantResource(hero, 0, 5);
          break;
        case 2u:
          display_message_window(
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
          grantResource(hero, 0, 5);
          grantResource(hero, 6, 200);
          break;
        case 3u:
          display_message_window(
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
          grantResource(hero, 0, 10);
          grantResource(hero, 6, 500);
          break;
        default:
          break;
      }
      v89 = 1;
      v85 = 1;
      goto LABEL_508;
    case LOCATION_SHIPWRECK_SURVIVOR:
      if ( Hero::numArtifacts(hero) >= 14 )
      {
        display_message_window(
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
          globBuf,
          "{Shipwreck Survivor}\n\nYou've pulled a shipwreck survivor from certain death in an unforgiving ocean.  Grateful, he rewards you for your act of kindness by giving you the %s.",
          artifactNames[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
        display_message_window(
          globBuf,
          1,
          -1,
          -1,
          7,
          (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
          -1,
          0,
          -1,
          0);
        grantArtifact(hero, (ARTIFACT)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), 1, -1);
      }
      v89 = 1;
      v85 = 1;
      goto LABEL_508;
    case LOCATION_MAGELLANS_MAPS:
      if ( curPlayer->resources[6] >= 1000 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        display_message_window(
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
        if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
        {
          curPlayer->resources[6] -= 1000;
          GameInfo::exploreAllWater(gameObject, curPlayerIdx);
          sub_448110(thisa, 0);
          sub_447A00(thisa, 0, 0);
        }
      }
      else
      {
        display_message_window(
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
      goto LABEL_508;
    case LOCATION_WITCH_HUT:
      if ( hero->secondarySkillLevel[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)] )
      {
        sprintf(
          globBuf,
          "{Witch's Hut}\n\nYou approach the hut and observe a witch inside studying an ancient tome on %s.  As you approach, she turns and speaks.  \"You already know that which I would teach you. I can help you no further.\"",
          secondary_skill_names[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
        display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
      }
      else
      {
        if ( hero->numSecSkillsKnown < 8 )
        {
          playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
          sprintf(
            globBuf,
            "{Witch's Hut}\n\nAn ancient and immortal witch living in a hut with bird's legs for stilts teaches you %s for her own inscrutable purposes.",
            secondary_skill_names[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
          showMessageWindowForEvent(
            -1,
            1,
            globBuf,
            17,
            3 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
            -1,
            0,
            -1);
          Hero::learnSecondarySkill(hero, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), 1);
        }
        else
        {
          sprintf(
            globBuf,
            "{Witch's Hut}\n\nYou approach the hut and observe a witch inside studying an ancient tome on %s.  As you approach, she turns and focuses her one glass eye on you.  \"You already know everything you deserve to learn!\" the witch screeches. \"NOW GET OUT OF MY HOUSE!\"",
            secondary_skill_names[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
        }
      }
      goto LABEL_508;
    case LOCATION_ARTESIAN_SPRING:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        loc->flags &= 7u;
        v6 = Hero::getPrimarySkill(hero, PRIMARY_SKILL_KNOWLEDGE);
        v62 = 10 * v6;
        if ( hero->spellpoints < 20 * v6 )
        {
          display_message_window(
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
          hero->spellpoints = 2 * v62;
        }
        else
        {
          display_message_window(
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
        display_message_window(
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
      goto LABEL_508;
    case LOCATION_MAGIC_WELL:
      if ( hero->flags2 & HERO_VISITED_WELL )
      {
        display_message_window(
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
        maxSP = 10 * Hero::getPrimarySkill(hero, PRIMARY_SKILL_KNOWLEDGE);
        if ( hero->spellpoints < maxSP )
        {
          display_message_window(
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
          display_message_window(
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
      goto LABEL_508;
    case LOCATION_ARMY_CAMP|LOCATION_SKELETON:
      if ( hero->flags1 & 0x80 )
      {
        *(_DWORD *)&hero->flags1 &= 0xFFFFFF7Fu;
        *(_DWORD *)&hero->_4[20] = 0;
        hero->_4[11] = LOBYTE(thisa->field_27E);
        thisa->field_27A = hero->factionID;
        thisa->field_282 = sub_4C0550(thisa->field_27E);
        thisa->field_272 = 1;
        res = playSample("killfade.82m");
        HeroWindowManager::resetSomeBMP(HeroWindowManager::instance, 192, 192, 96, 96);
        sub_447C20(thisa, thisa->viewX, thisa->viewY, 0, 1);
        sub_4C7E00(HeroWindowManager::instance, 192, 192, 96, 96, -1, 0, 0);
        waitForSampleToFinish(-1, res);
        sub_4C1B30(thisa, (signed int)&v60);
      }
      goto LABEL_508;
    case LOCATION_BOAT:
      v68 = &gameObject->probablyArtifactGeneratedRandomly[8
                                                         * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)
                                                         + 103];
      sub_42CC90(-1, -1, (unsigned __int8)v68[4], (unsigned __int8)v68[5], (int)loc, 2);
      *(_DWORD *)&hero->flags1 |= HERO_AT_SEA;
      *(_DWORD *)&hero->_4[20] = 0;
      v68[6] = hero->field_2;
      v68[7] = hero->probablyOwnerIdx;
      thisa->field_27A = 6;
      thisa->field_27E = v68[3];
      thisa->field_282 = sub_4C0550(thisa->field_27E);
      thisa->field_272 = 1;
      sub_447C20(thisa, thisa->viewX, thisa->viewY, 0, 1);
      sub_447A00(thisa, 0, 0);
      goto LABEL_508;
    case LOCATION_MINE:
      if ( gameObject->_8[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 1008] == curPlayerIdx )
        goto LABEL_508;
      if ( gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 3] == -1 )
        goto LABEL_125;
      v59 = sub_48E820(
              thisa,
              (int)hero,
              gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 3],
              gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 4],
              (int)loc,
              a4,
              0,
              a4,
              -1,
              0,
              0,
              -1,
              0,
              0);
      if ( !v59 )
      {
        gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 3] = -1;
        Hero::checkForLevelUp(hero);
LABEL_125:
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        if ( gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 2] == 6 )
        {
          v81 = 1000;
        }
        else
        {
          if ( gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 2] == 2 )
            v81 = 2;
          else
            v81 = 1;
        }
        showMessageWindowForEvent(
          gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 2] + 59,
          1,
          byte_514A64,
          gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 2],
          -v81,
          -1,
          0,
          -1);
        goto LABEL_135;
      }
      goto LABEL_508;
    case LOCATION_ALCHEMIST_LAB:
      if ( gameObject->_8[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 1008] == curPlayerIdx )
        goto LABEL_508;
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      showMessageWindowForEvent(0, 1, byte_514A68, 1, -1, -1, 0, -1);
      goto LABEL_135;
    case LOCATION_SAWMILL:
      if ( gameObject->_8[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 1008] != curPlayerIdx )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(73, 1, byte_514A6C, 0, -2, -1, 0, -1);
LABEL_135:
        sub_4212E0(gameObject, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), curPlayerIdx);
      }
      goto LABEL_508;
    case LOCATION_LIGHTHOUSE:
      if ( gameObject->_8[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 1008] != curPlayerIdx )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        sub_4212E0(gameObject, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), curPlayerIdx);
        showMessageWindowForEvent(58, 1, byte_514A70, -1, 0, -1, 0, -1);
      }
      goto LABEL_508;
    case LOCATION_TREASURE_CHEST:
      if ( !(((unsigned __int16)(loc->flags >> 3) >> 8) & 1) )
        goto LABEL_142;
      if ( Hero::numArtifacts(hero) < 14 )
      {
        v8 = loc->flags >> 3;
        sprintf(
          globBuf,
          "{Chest}\n\nAfter scouring the area, you fall upon a hidden chest, containing the ancient artifact '%s'",
          artifactNames[(unsigned __int8)v8]);
        v9 = loc->flags >> 3;
        display_message_window(globBuf, 1, -1, -1, 7, (unsigned __int8)v9, -1, 0, -1, 0);
        v10 = loc->flags >> 3;
        grantArtifact(hero, (ARTIFACT)(unsigned __int8)v10, 1, -1);
      }
      else
      {
        v7 = loc->flags & 7;
        LOBYTE(v7) = v7 | 0x10;
        loc->flags = v7;
LABEL_142:
        showMessageWindowForEvent(
          -1,
          2,
          "{Chest}\n\nAfter scouring the area, you fall upon a hidden treasure cache.  You may take the gold or distribute the gold to the peasants for experience.  Do you wish to keep the gold?",
          6,
          500 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
          14,
          125 * (4 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 4),
          1);
        if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
          grantResource(hero, 6, 500 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5));
        else
          giveXPToHero(hero, 125 * (4 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 4), 0);
      }
      v85 = 1;
      v89 = 1;
      Hero::checkForLevelUp(hero);
      goto LABEL_508;
    case LOCATION_BUOY:
      if ( hero->flags1 & 2 )
      {
        showMessageWindowForEvent(2, 1, byte_514B94, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        *(_DWORD *)&hero->flags1 |= 2u;
        ++hero->_5[1];
        showMessageWindowForEvent(3, 1, byte_514B98, 12, 0, -1, 0, -1);
      }
      goto LABEL_508;
    case LOCATION_FAERIE_RING:
      if ( hero->flags1 & 0x10 )
      {
        showMessageWindowForEvent(12, 1, byte_514B9C, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        *(_DWORD *)&hero->flags1 |= 0x10u;
        ++hero->_5[2];
        showMessageWindowForEvent(13, 1, byte_514BA0, 10, 0, -1, 0, -1);
      }
      goto LABEL_508;
    case LOCATION_IDOL:
      if ( hero->flags2 & 0x20 )
      {
        showMessageWindowForEvent(
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
        showMessageWindowForEvent(
          -1,
          1,
          "{Idol}\n\nYou've found an ancient and weathered stone idol.  Kissing it is supposed to be lucky, so you do.  The stone is very cold to the touch.",
          10,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_508;
    case LOCATION_FOUNTAIN:
      if ( hero->flags1 & 4 )
      {
        showMessageWindowForEvent(15, 1, byte_514CDC, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        *(_DWORD *)&hero->flags1 |= 4u;
        ++hero->_5[2];
        showMessageWindowForEvent(16, 1, byte_514CE0, 10, 0, -1, 0, -1);
      }
      goto LABEL_508;
    case LOCATION_WATERING_HOLE:
      if ( hero->flags2 & 2 )
      {
        showMessageWindowForEvent(
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
        *(_DWORD *)&hero->_4[16] += 400;
        *(_DWORD *)&hero->_4[20] += 400;
        showMessageWindowForEvent(
          -1,
          1,
          "{Watering Hole}\n\nA drink at the watering hole fills your troops with strength and lifts their spirits.  You can travel a bit further today.",
          12,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_508;
    case LOCATION_OASIS:
      if ( hero->flags1 & 8 )
      {
        showMessageWindowForEvent(
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
        *(_DWORD *)&hero->_4[16] += 800;
        *(_DWORD *)&hero->_4[20] += 800;
        showMessageWindowForEvent(
          -1,
          1,
          "{Oasis}\n\nA drink at the oasis fills your troops with strength and lifts their spirits.  You can travel a bit further today.",
          12,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_508;
    case LOCATION_TEMPLE:
      if ( hero->flags2 & 1 )
      {
        display_message_window(
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
        display_message_window(
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
      goto LABEL_508;
    case LOCATION_LEAN_TO:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        v11 = loc->flags >> 3;
        v12 = (v11 & 0xF0u) >> 4;
        v13 = loc->flags >> 3;
        display_message_window(
          "{Lean To}\n\nYou've found an abandoned lean-to.  Poking about, you discover some resources hidden nearby.",
          1,
          -1,
          -1,
          (v13 & 0xF) - 1,
          v12,
          -1,
          0,
          -1,
          0);
        v14 = loc->flags >> 3;
        v15 = (v14 & 0xF0u) >> 4;
        v16 = loc->flags >> 3;
        grantResource(hero, (v16 & 0xF) - 1, v15);
        loc->flags &= 7u;
      }
      else
      {
        display_message_window(
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
      goto LABEL_508;
    case LOCATION_WAGON:
      if ( !((unsigned __int8)(loc->flags >> 8) >> -5) )
        goto LABEL_179;
      if ( (loc->flags >> 3) & 0x80 )
      {
        if ( Hero::numArtifacts(hero) == 14 )
        {
LABEL_179:
          showMessageWindowForEvent(
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
          v17 = loc->flags >> 3;
          a2 = v17 & 0x7F;
          sprintf(
            globBuf,
            "{Wagon}\n\nYou come across an old wagon left by a trader who didn't quite make it to safe terrain.  Searching inside, you find the '%s'.",
            artifactNames[v17 & 0x7F]);
          showMessageWindowForEvent(-1, 1, globBuf, 7, a2, -1, 0, -1);
          grantArtifact(hero, (ARTIFACT)a2, 1, -1);
          loc->flags &= 7u;
        }
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        v18 = loc->flags >> 3;
        v19 = (v18 & 0xF0u) >> 4;
        v20 = loc->flags >> 3;
        showMessageWindowForEvent(
          -1,
          1,
          "{Wagon}\n\nYou come across an old wagon left by a trader who didn't quite make it to safe terrain.  Inside, you find some of the wagon's cargo still intact.",
          (v20 & 0xF) - 1,
          v19,
          -1,
          0,
          -1);
        v21 = loc->flags >> 3;
        v22 = (v21 & 0xF0u) >> 4;
        v23 = loc->flags >> 3;
        grantResource(hero, (v23 & 0xF) - 1, v22);
        loc->flags &= 7u;
      }
      goto LABEL_508;
    case LOCATION_SKELETON:
      if ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) == 1 )
      {
        showMessageWindowForEvent(93, 1, byte_515240, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        if ( Hero::numArtifacts(hero) == 14 )
        {
          sprintf(globBuf, "%s.", "Treasure");
          showMessageWindowForEvent(-1, 1, globBuf, 6, 1000, -1, 0, -1);
          grantResource(hero, 6, 1000);
        }
        else
        {
          a2 = (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 2;
          sprintf(globBuf, "%s %s", adventureMapLocationMessages[94], artifactNames[a2]);
          grantArtifact(hero, (ARTIFACT)a2, 1, -1);
          showMessageWindowForEvent(-1, 1, globBuf, 7, a2, -1, 0, -1);
        }
        v24 = loc->flags & 7;
        LOBYTE(v24) = v24 | 8;
        loc->flags = v24;
      }
      goto LABEL_508;
    case LOCATION_CAMPFIRE:
      v25 = loc->flags >> 3;
      showMessageWindowForEvent(
        14,
        1,
        byte_51525C,
        6,
        100 * ((signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) >> 4),
        v25 & 0xF,
        (signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) >> 4,
        -1);
      grantResource(hero, 6, 100 * ((signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) >> 4));
      v26 = loc->flags >> 3;
      grantResource(hero, v26 & 0xF, (signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) >> 4);
      v85 = 1;
      v89 = 1;
      sub_452F60(thisa, thisa->viewX + 7, thisa->viewY + 7, 1);
      goto LABEL_508;
    case LOCATION_XANADU:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[28] )
      {
        display_message_window(
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
      else
      {
        if ( hero->oldLevel + 2 * hero->secondarySkillLevel[4] < 10 )
        {
          display_message_window(
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
          display_message_window(
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
      }
      goto LABEL_508;
    case LOCATION_FORT:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[8] )
      {
        display_message_window(
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
        display_message_window(
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
      goto LABEL_508;
    case LOCATION_STANDING_STONES:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[20] )
      {
        display_message_window(
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
        display_message_window(
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
      goto LABEL_508;
    case LOCATION_WITCH_DOCTORS_HUT:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[12] )
      {
        display_message_window(
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
        display_message_window(
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
      goto LABEL_508;
    case LOCATION_MERCENARY_CAMP:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[16] )
      {
        display_message_window(
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
        display_message_window(
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
      goto LABEL_508;
    case LOCATION_GAZEBO:
      if ( (1 << (loc->flags >> 3)) & *(_DWORD *)&hero->_5[4] )
      {
        showMessageWindowForEvent(17, 1, byte_515894, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(18, 1, byte_515898, 14, 1000, -1, 0, -1);
        giveXPToHero(hero, 1000, 0);
        *(_DWORD *)&hero->_5[4] |= 1 << (loc->flags >> 3);
        Hero::checkForLevelUp(hero);
      }
      goto LABEL_508;
    case LOCATION_WATERWHEEL:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(
          60,
          1,
          byte_5158A0,
          6,
          500 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
          -1,
          0,
          -1);
        grantResource(hero, 6, 500 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5));
        loc->flags &= 7u;
      }
      else
      {
        showMessageWindowForEvent(59, 1, byte_51589C, -1, 0, -1, 0, -1);
      }
      goto LABEL_508;
    case LOCATION_RESOURCE:
      type = (signed int)HIBYTE(loc->field_2) >> 1;
      if ( type == 6 )
        amt = 100 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
      else
        amt = (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
      grantResource(hero, type, amt);
      strcpy(&v86, resourceNames[type]);
      v86 += 32;
      sprintf(globBuf, adventureMapLocationMessages[72], &v86);
      if ( type == 6 )
        v49 = 100 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
      else
        v49 = (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
      sub_435D20(globBuf, type, v49);
      v85 = 1;
      v89 = 1;
      goto LABEL_508;
    case LOCATION_WINDMILL:
      if ( (signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) > 6 )
      {
        showMessageWindowForEvent(86, 1, byte_5158A8, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(
          87,
          1,
          byte_5158A4,
          (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
          2,
          -1,
          0,
          -1);
        grantResource(hero, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), 2);
        loc->flags = loc->flags & 7 | 0x318;
      }
      goto LABEL_508;
    case LOCATION_ANCIENT_LAMP:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      showMessageWindowForEvent(19, 2, byte_5158AC, -1, 0, -1, 0, -1);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
      {
        recruitCreaturesFromMapLocation(hero, 60, loc);
        if ( !((unsigned __int8)(loc->flags >> 8) >> -5) )
        {
          v85 = 1;
          v89 = 1;
        }
      }
      goto LABEL_508;
    case LOCATION_TREE_CITY:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(
          -1,
          2,
          "{Tree City}\n\nSome of the Sprites living in the tree city are willing to join your army for a price.  Do you want to recruit Sprites?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
          recruitCreaturesFromMapLocation(hero, 20, loc);
      }
      else
      {
        showMessageWindowForEvent(
          -1,
          1,
          "{Tree City}\n\nYou've found a Sprite Tree City.  Unfortunately, none of the Sprites living there wish to join an army.  Maybe next week.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_508;
    case LOCATION_RUINS:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(
          -1,
          2,
          "{Ruins}\n\nYou've found some Medusas living in the ruins.  They are willing to join your army for a price.  Do you want to recruit Medusas?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
          recruitCreaturesFromMapLocation(hero, CREATURE_MEDUSA, loc);
      }
      else
      {
        showMessageWindowForEvent(
          -1,
          1,
          "{Ruins}\n\nYou search the ruins, but the Medusas that used to live here are gone.  Perhaps there will be more next week.",
          -1,
          0,
          -1,
          0,
          -1);
      }
      goto LABEL_508;
    case LOCATION_TROLL_BRIDGE:
      if ( !((unsigned __int8)(loc->flags >> 8) >> -5) )
      {
        showMessageWindowForEvent(
          -1,
          1,
          "{Troll Bridge}\n\nYou've found one of those bridges that Trolls are so fond of living under, but there are none here.  Perhaps there will be some next week.",
          -1,
          0,
          -1,
          0,
          -1);
        goto LABEL_508;
      }
      if ( ((unsigned __int16)(loc->flags >> 3) >> 8) & 1 )
      {
        showMessageWindowForEvent(
          -1,
          2,
          "{Troll Bridge}\n\nTrolls living under the bridge challenge you.  Will you fight them?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
          goto LABEL_508;
        if ( sub_48E820(thisa, (int)hero, 17, 12, (int)loc, a4, 0, a4, 18, 8, 2, -1, 0, 0) )
          goto LABEL_508;
        Hero::checkForLevelUp(hero);
        loc->flags = loc->flags & 7 | 8 * ((unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 256);
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(
          -1,
          2,
          "{Troll Bridge}\n\nA few Trolls remain, cowering under the bridge.  They approach you and offer to join your forces as mercenaries.  Do you want to buy any Trolls?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
          goto LABEL_508;
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(
          -1,
          2,
          "{Troll Bridge}\n\nSome Trolls living under a bridge are willing to join your army, but for a price.  Do you want to recruit Trolls?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
          goto LABEL_508;
      }
      recruitCreaturesFromMapLocation(hero, 17, loc);
      goto LABEL_508;
    case LOCATION_CITY_OF_DEAD:
      if ( !((unsigned __int8)(loc->flags >> 8) >> -5) )
      {
        showMessageWindowForEvent(
          -1,
          1,
          "{City of the Dead}\n\nThe City of the Dead is empty of life, and empty of unlife as well.  Perhaps some undead will move in next week.",
          -1,
          0,
          -1,
          0,
          -1);
        goto LABEL_508;
      }
      if ( ((unsigned __int16)(loc->flags >> 3) >> 8) & 1 )
      {
        showMessageWindowForEvent(
          -1,
          2,
          "{City of the Dead}\n\nYou've found the ruins of an ancient city, now inhabited solely by the undead.  Will you search?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
          goto LABEL_508;
        if ( sub_48E820(thisa, (int)hero, 53, 10, (int)loc, a4, 0, a4, 48, 40, 2, 55, 5, 1) )
          goto LABEL_508;
        Hero::checkForLevelUp(hero);
        loc->flags = loc->flags & 7 | 8 * ((unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 256);
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(
          -1,
          2,
          "{City of the Dead}\n\nSome of the surviving Liches are impressed by your victory over their fellows, and offer to join you for a price.  Do you want to recruit Liches?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
          goto LABEL_508;
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(
          -1,
          2,
          "{City of the Dead}\n\nSome Liches living here are willing to join your army for a price.  Do you want to recruit Liches?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
          goto LABEL_508;
      }
      recruitCreaturesFromMapLocation(hero, 55, loc);
      goto LABEL_508;
    case LOCATION_DRAGON_CITY:
      if ( !((unsigned __int8)(loc->flags >> 8) >> -5) )
      {
        showMessageWindowForEvent(
          -1,
          1,
          "{Dragon City}\n\nThe Dragon city has no Dragons willing to join you this week.  Perhaps a Dragon will become available next week.",
          -1,
          0,
          -1,
          0,
          -1);
        goto LABEL_508;
      }
      if ( !(((unsigned __int16)(loc->flags >> 3) >> 8) & 1) )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(
          -1,
          2,
          "{Dragon City}\n\nThe Dragon city is willing to offer some Dragons for your army for a price.  Do you wish to recruit Dragons?",
          -1,
          0,
          -1,
          0,
          -1);
        if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
          goto LABEL_508;
        goto LABEL_282;
      }
      showMessageWindowForEvent(
        -1,
        2,
        "{Dragon City}\n\nYou stand before the Dragon City, a place off-limits to mere humans.  Do you wish to violate this rule and challenge the Dragons to a fight?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
      {
        v58 = 1;
        if ( loadOrNewGameSelected && gameObject->field_2 == 1 && gameObject->field_4 == 6 )
          v58 = 2;
        if ( !sub_48E820(thisa, (int)hero, 35, 3 * v58, (int)loc, a4, 0, a4, 36, v58, 1, 37, v58, 1) )
        {
          checkGameEnd(0, 1);
          if ( !dword_4EF268 )
          {
            Hero::checkForLevelUp(hero);
            loc->flags = loc->flags & 7 | 8 * ((unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 256);
            playTrackForLocationVisit(
              locType,
              (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
              (_QWORD *)a3a);
            showMessageWindowForEvent(
              -1,
              2,
              "{Dragon City}\n\nHaving defeated the Dragon champions, the city's leaders agree to supply some Dragons to your army for a price.  Do you wish to recruit Dragons?",
              -1,
              0,
              -1,
              0,
              -1);
            if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
            {
LABEL_282:
              recruitCreaturesFromMapLocation(hero, 36, loc);
              goto LABEL_508;
            }
          }
        }
      }
LABEL_508:
      sub_44AA80((int)thisa, 1, 0);
      AdvManager::heroSelectionGUIStuff(thisa, 1, 1);
      sub_44D170(thisa, 1, 1);
      sub_44D440(thisa, 1, 1, 1);
      if ( v85 )
      {
        sub_48BA30((int)thisa, (int)loc, a4, SHIDWORD(a4));
        sub_48F7F0(thisa, v89);
      }
      else
      {
        sub_448110(thisa, 0);
      }
      sub_447A00(thisa, 0, 0);
      SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[thisa->field_A6]);
      waitForSampleToFinish(-1, *(sample_resource *)a3a);
      checkGameEnd(0, 0);
      return;
    case LOCATION_WAGON_CAMP:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(84, 2, byte_516138, -1, 0, -1, 0, -1);
        if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
          recruitCreaturesFromMapLocation(hero, 57, loc);
      }
      else
      {
        showMessageWindowForEvent(83, 1, byte_516134, -1, 0, -1, 0, -1);
      }
      goto LABEL_508;
    case LOCATION_DESRT_TENT:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        showMessageWindowForEvent(82, 2, byte_516140, -1, 0, -1, 0, -1);
        if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
          recruitCreaturesFromMapLocation(hero, 58, loc);
      }
      else
      {
        showMessageWindowForEvent(81, 1, byte_51613C, -1, 0, -1, 0, -1);
      }
      goto LABEL_508;
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
      sub_48E5A0((int)hero, (int)loc);
      goto LABEL_508;
    case LOCATION_ARMY_CAMP:
      sub_492A90(thisa, (int)loc, (int)loc, (int)hero, (signed int)&v85, a4, 0, a4);
      goto LABEL_508;
    case LOCATION_OBELISK:
      if ( gameObject->field_6236[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 278] & (1 << hero->probablyOwnerIdx) )
      {
        showMessageWindowForEvent(69, 1, byte_516148, -1, 0, -1, 0, -1);
      }
      else
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        gameObject->field_6236[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 278] |= 1 << hero->probablyOwnerIdx;
        showMessageWindowForEvent(68, 1, byte_516144, -1, 0, -1, 0, -1);
        sub_456C40(thisa);
      }
      goto LABEL_508;
    case LOCATION_TREE_OF_KNOWLEDGE:
      if ( (1 << ((loc->flags >> 3) & 0x1F)) & *(_DWORD *)&hero->_5[24] )
      {
        display_message_window(
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
        level = levelForXP(hero->experience);
        v27 = experienceForLevel(level + 1);
        xp = v27 - experienceForLevel(level);
        v47 = (signed int)(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) >> 6;
        switch ( v47 )
        {
          case 1:
            display_message_window(
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
            giveXPToHero(hero, xp, 0);
            *(_DWORD *)&hero->_5[24] |= 1 << (((unsigned __int8)(loc->flags >> 8) >> -5) & 0x1F);
            break;
          case 2:
            if ( curPlayer->resources[6] < 2000 )
            {
              display_message_window(
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
              display_message_window(
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
              if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
              {
                curPlayer->resources[6] -= 2000;
                giveXPToHero(hero, xp, 0);
                *(_DWORD *)&hero->_5[24] |= 1 << (((unsigned __int8)(loc->flags >> 8) >> -5) & 0x1F);
              }
            }
            break;
          case 3:
            if ( curPlayer->resources[5] < 10 )
            {
              display_message_window(
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
              display_message_window(
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
              if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
              {
                curPlayer->resources[5] -= 10;
                giveXPToHero(hero, xp, 0);
                *(_DWORD *)&hero->_5[24] |= 1 << (((unsigned __int8)(loc->flags >> 8) >> -5) & 0x1F);
              }
            }
            break;
        }
      }
      Hero::checkForLevelUp(hero);
      goto LABEL_508;
    case LOCATION_ORACLE:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      showMessageWindowForEvent(74, 1, byte_516540, -1, 0, -1, 0, -1);
      this = (GUIWindow *)operator new(0x44u);
      if ( this )
        a2a = (int)GUIWindow_constructorFromFile(this, 0, 0, "thiefwin.bin");
      else
        a2a = 0;
      if ( !a2a )
        fatalOutOfMemoryError();
      setOptionsScreenTitles((GUIWindow *)a2a, 14);
      populateThievesGuildWindow((GUIWindow *)a2a, 99);
      strcpy(globBuf, "Shrine - Player Rankings");
      evt.eventCode = INPUT_GUI_MESSAGE_CODE;
      evt.messageType = GUI_MESSAGE_SET_CONTENTS;
      evt.fieldID = 0;
      evt.payload = globBuf;
      GUIWindow::processMessage((GUIWindow *)a2a, (Event *)&evt);
      HeroWindowManager::displayWindow(HeroWindowManager::instance, (GUIWindow *)a2a, sub_432E90, 0);
      operator delete((void *)a2a);
      sub_4506B0(thisa, 1, 0);
      goto LABEL_508;
    case LOCATION_SHRINE_FIRST:
      sprintf(
        globBuf,
        "%s'%s'.  ",
        "{Shrine of the 1st Circle}\n\nYou come across a small shrine attended by a group of novice acolytes.  In exchange for your protection, they agree to teach you a simple spell - ",
        dword_4F6ABC[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
      goto LABEL_331;
    case LOCATION_SHRINE_SECOND_ORDER:
      sprintf(
        globBuf,
        "%s'%s'.  ",
        "{Shrine of the 2nd Circle}\n\nYou come across an ornate shrine attended by a group of rotund friars.  In exchange for your protection, they agree to teach you a spell - ",
        dword_4F6ABC[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
      goto LABEL_331;
    case LOCATION_SHRINE_THIRD_ORDER:
      sprintf(
        globBuf,
        "%s'%s'.  ",
        "{Shrine of the 3rd Circle}\n\nYou come across a lavish shrine attended by a group of high priests.  In exchange for your protection, they agree to teach you a sophisticated spell - ",
        dword_4F6ABC[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
LABEL_331:
      if ( Hero::hasArtifact(hero, ARTIFACT_MAGIC_BOOK) )
      {
        if ( spell_table[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1].level > hero->secondarySkillLevel[7]
                                                                                                + 2 )
        {
          strcat(
            globBuf,
            "Unfortunately, you do not have the wisdom to understand the spell, and you are unable to learn it.  ");
          showMessageWindowForEvent(-1, 1, globBuf, -1, 0, -1, 0, -1);
        }
        else
        {
          playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
          v28 = Hero::getPrimarySkill(hero, PRIMARY_SKILL_KNOWLEDGE);
          Hero::learnSpell(hero, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1, v28);
          showMessageWindowForEvent(
            -1,
            1,
            globBuf,
            8,
            (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1,
            -1,
            0,
            -1);
        }
      }
      else
      {
        strcat(globBuf, "Unfortunately, you have no Magic Book to record the spell with.");
        showMessageWindowForEvent(-1, 1, globBuf, -1, 0, -1, 0, -1);
      }
      goto LABEL_508;
    case LOCATION_TOWN:
      sub_48D2F0((int)thisa, (int)loc, a4);
      goto LABEL_508;
    case LOCATION_WHIRLPOOL:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      sub_48F6B0((int)hero);
      goto LABEL_341;
    case LOCATION_STONE_LITHS:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
LABEL_341:
      v69 = 0;
      for ( i = 0; (signed int)i < mapHeight; ++i )
      {
        for ( j = 0; mapWidth > (signed int)j; ++j )
        {
          if ( *(&gameObject->map.tiles[j].objType + 12 * i * gameObject->map.width) == (unsigned __int8)((unsigned __int8)locType | 0x80) )
          {
            if ( *((_BYTE *)&gameObject->map.tiles[j].field_2 + 12 * i * gameObject->map.width + 1) == HIBYTE(loc->field_2) )
            {
              v29 = abs(j - a4);
              if ( abs(i - HIDWORD(a4)) + v29 > ((unsigned int)(locType - 36) < 1 ? 1 : 3) )
                ++v69;
            }
          }
        }
      }
      if ( v69 < 1 )
        goto LABEL_508;
      if ( v69 > 1 )
        v69 = unseededNextRand(1, v69);
      i = 0;
LABEL_355:
      if ( (signed int)i < mapHeight )
      {
        for ( j = 0; ; ++j )
        {
          if ( mapWidth <= (signed int)j )
          {
            ++i;
            goto LABEL_355;
          }
          if ( *(&gameObject->map.tiles[j].objType + 12 * i * gameObject->map.width) == (unsigned __int8)((unsigned __int8)locType | 0x80) )
          {
            if ( *((_BYTE *)&gameObject->map.tiles[j].field_2 + 12 * i * gameObject->map.width + 1) == HIBYTE(loc->field_2) )
            {
              if ( __PAIR__(i, j) != a4 )
              {
                v30 = abs(j - a4);
                if ( abs(i - HIDWORD(a4)) + v30 > ((unsigned int)(locType - 36) < 1 ? 1 : 3) )
                {
                  --v69;
                  if ( v69 <= 0 )
                    break;
                }
              }
            }
          }
        }
      }
      sub_4BFAC0(thisa, 1);
      sub_453A20(advManager, (int)hero, __PAIR__(i, j), 1, 0);
      goto LABEL_508;
    case LOCATION_ARTIFACT:
      v31 = loc->flags >> 3;
      v76 = (v31 & 0xF0u) >> 4;
      a5 = (signed int)HIBYTE(loc->field_2) >> 1;
      v32 = loc->flags >> 3;
      v82 = v32 & 0x7F;
      if ( Hero::numArtifacts(hero) == 14 )
      {
        display_message_window(
          "You cannot pick up this artifact, you already have a full load!",
          1,
          -1,
          -1,
          -1,
          0,
          -1,
          0,
          -1,
          0);
        goto LABEL_508;
      }
      if ( byte_5304A0 && sub_472960((int)&unk_530450, a4, SHIDWORD(a4)) )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        strcpy(
          globBuf,
          "The fabled golden bow of the elves lies here in the dust.  You take it and journey back to the elven towns.  They shower you with their graciousness and the king promises that his people will aid you whenever you seek help.");
        showMessageWindowForEvent(-1, 1, globBuf, 7, a5, -1, 0, -1);
        grantArtifact(hero, (ARTIFACT)a5, 1, (unsigned __int8)(loc->flags >> 8) >> -5);
        v85 = 1;
        v89 = 1;
        goto LABEL_508;
      }
      if ( a5 == 86 )
      {
        playTrackForLocationVisit(locType, 1, (_QWORD *)a3a);
        dword_5304CC = (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5);
        showMessageWindowForEvent(-1, 1, *(&artifact_events + 86), 7, 86, -1, 0, -1);
        grantArtifact(hero, ARTIFACT_SPELL_SCROLL, 1, (unsigned __int8)(loc->flags >> 8) >> -5);
        v85 = 1;
        v89 = 1;
        goto LABEL_508;
      }
      if ( ((unsigned __int16)(loc->flags >> 3) >> 8) & 1 )
      {
        playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
        if ( v82 == 57 )
        {
          display_message_window(
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
          v72 = 50;
        }
        else
        {
          v72 = 1;
          sprintf(
            globBuf,
            "{Artifact}\n\nThrough a clearing you observe an ancient artifact.  Unfortunately, it's guarded by a nearby %s.  Do you want to fight the %s for the artifact?",
            creatureSingularNames[v82],
            creatureSingularNames[v82]);
          display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
          if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
          {
            display_message_window(
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
            goto LABEL_508;
          }
        }
        if ( sub_48E820(thisa, (int)hero, v82, v72, (int)loc, a4, 0, a4, -1, 0, 0, -1, 0, 0) )
          goto LABEL_508;
        Hero::checkForLevelUp(hero);
        sprintf(globBuf, "Victorious, you take your prize, the %s", artifactNames[a5]);
        display_message_window(globBuf, 1, -1, -1, 7, (signed int)HIBYTE(loc->field_2) >> 1, -1, 0, -1, 0);
LABEL_389:
        grantArtifact(hero, (ARTIFACT)a5, 1, -1);
        v85 = 1;
        v89 = 1;
      }
      else
      {
        v33 = loc->flags >> 3;
        switch ( v33 & 0xF )
        {
          case 4:
            if ( hero->secondarySkillLevel[7] )
              goto LABEL_388;
            sprintf(
              globBuf,
              "{Artifact}\n\nYou've found the humble dwelling of a withered hermit.  The hermit tells you that he is willing to give the %s to the first wise person he meets.",
              artifactNames[a5]);
            display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
            break;
          case 5:
            if ( hero->secondarySkillLevel[6] )
              goto LABEL_388;
            sprintf(
              globBuf,
              "{Artifact}\n\nYou've come across the spartan quarters of a retired soldier.  The soldier tells you that he is willing to pass on the %s to the first true leader he meets.",
              artifactNames[a5]);
            display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
            break;
          case 1:
LABEL_388:
            playTrackForLocationVisit(
              locType,
              (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
              (_QWORD *)a3a);
            showMessageWindowForEvent(-1, 1, (&artifact_events)[4 * a5], 7, a5, -1, 0, -1);
            goto LABEL_389;
          case 3:
            playTrackForLocationVisit(
              locType,
              (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5),
              (_QWORD *)a3a);
            sprintf(
              globBuf,
              "{Artifact}\n\nA leprechaun offers you the %s for the small price of 2000 gold.  Do you wish to buy this artifact?",
              artifactNames[a5]);
            showMessageWindowForEvent(-1, 2, globBuf, 7, a5, -1, 0, -1);
            if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
            {
              if ( gameObject->players[hero->probablyOwnerIdx].resources[6] >= 2000 )
              {
                gameObject->players[hero->probablyOwnerIdx].resources[6] -= 2000;
                goto LABEL_389;
              }
              display_message_window(
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
              display_message_window(
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
            sprintf(&v86, resourceNames[v76]);
            v86 += 32;
            sprintf(
              globBuf,
              "{Artifact}\n\nA leprechaun offers you the %s for the small price of 2500 gold and 3 %s.  Do you wish to buy this artifact?",
              artifactNames[a5],
              &v86);
            display_message_window(globBuf, 2, -1, -1, 7, a5, -1, 0, -1, 0);
            if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
            {
              if ( gameObject->players[hero->probablyOwnerIdx].resources[6] >= 2500
                && gameObject->players[hero->probablyOwnerIdx].resources[v76] >= 3 )
              {
                gameObject->players[hero->probablyOwnerIdx].resources[6] -= 2500;
                v34 = 283 * hero->probablyOwnerIdx + 4 * v76;
                *(int *)((char *)gameObject->players[0].resources + v34) -= 3;
                goto LABEL_389;
              }
              display_message_window(
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
              display_message_window(
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
            sprintf(&v86, resourceNames[v76]);
            v86 += 32;
            sprintf(
              globBuf,
              "{Artifact}\n\nA leprechaun offers you the %s for the small price of 3000 gold and 5 %s.  Do you wish to buy this artifact?",
              artifactNames[a5],
              &v86);
            display_message_window(globBuf, 2, -1, -1, 7, a5, -1, 0, -1, 0);
            if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
            {
              if ( gameObject->players[hero->probablyOwnerIdx].resources[6] >= 3000
                && gameObject->players[hero->probablyOwnerIdx].resources[v76] >= 5 )
              {
                gameObject->players[hero->probablyOwnerIdx].resources[6] -= 3000;
                v35 = 283 * hero->probablyOwnerIdx + 4 * v76;
                *(int *)((char *)gameObject->players[0].resources + v35) -= 5;
                goto LABEL_389;
              }
              display_message_window(
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
              display_message_window(
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
      Hero::checkForLevelUp(hero);
      goto LABEL_508;
    case LOCATION_HERO:
      sub_450880(thisa);
      v78 = &gameObject->heroes[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)];
      if ( *((_BYTE *)v78 + 3) == curPlayerIdx )
      {
        sub_48C430(thisa, (int)hero, (int)v78);
      }
      else
      {
        v55 = 0;
        if ( *(_WORD *)((char *)v78 + 45) == 163 )
        {
          v55 = &gameObject->castles[*(_WORD *)((char *)v78 + 47)];
          *((_BYTE *)v55 + 23) = *((_BYTE *)v78 + 2);
        }
        v79 = sub_4938B0(
                thisa,
                a4,
                (int)hero,
                &hero->army,
                (int)v55,
                (int)v78,
                (char *)v78 + 101,
                a4,
                SBYTE4(a4),
                -1,
                1);
        if ( !v79 && v55 )
          sub_420F30(gameObject, *(_BYTE *)v55, curPlayerIdx, 0);
      }
      goto LABEL_508;
    case LOCATION_BOTTLE:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        v91 = *((_DWORD *)dword_524784 + (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5));
        if ( strlen((const char *)(v91 + 9)) <= 1 )
          showMessageWindowForEvent(-1, 1, (&off_4F70C8)[4 * (unsigned __int8)((char)a4 % -4)], -1, 0, -1, 0, -1);
        else
          showMessageWindowForEvent(-1, 1, (const char *)(v91 + 9), -1, 0, -1, 0, -1);
      }
      v89 = 1;
      v85 = 1;
      goto LABEL_508;
    case LOCATION_SIGN:
      if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
      {
        v91 = *((_DWORD *)dword_524784 + (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5));
        if ( strlen((const char *)(v91 + 9)) <= 1 )
          showMessageWindowForEvent(-1, 1, (&off_4F70C8)[4 * (unsigned __int8)((char)a4 % -4)], -1, 0, -1, 0, -1);
        else
          showMessageWindowForEvent(-1, 1, (const char *)(v91 + 9), -1, 0, -1, 0, -1);
      }
      goto LABEL_508;
    case LOCATION_DAEMON_CAVE:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      showMessageWindowForEvent(
        -1,
        2,
        "{Daemon Cave}\n\nThe entrance to the cave is dark, and a foul, sulfurous smell issues from the cave mouth.  Will you enter?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( HeroWindowManager::instance->buttonPressedCode != 30726 )
      {
        if ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) == 1 )
        {
          showMessageWindowForEvent(
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
          v36 = loc->flags >> 3;
          v77 = ((v36 & 0xF0u) >> 4) + 62;
          sprintf(
            globBuf,
            "You find a powerful and grotesque Demon in the cave.  \"Today,\" it rasps, \"you will fight and surely die.  But I will give you a choice of deaths.  You may fight me, or you may fight my servants.  Do you prefer to fight my servants?\"");
          showMessageWindowForEvent(-1, 2, globBuf, -1, 0, -1, 0, -1);
          if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
          {
            if ( !sub_48E820(thisa, (int)hero, v77, 8, (int)loc, a4, 0, a4, -1, 0, 0, -1, 0, 0) )
            {
              Hero::checkForLevelUp(hero);
              display_message_window(
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
              grantResource(hero, 6, 2500);
              v37 = loc->flags & 7;
              LOBYTE(v37) = v37 | 8;
              loc->flags = v37;
            }
          }
          else
          {
            v38 = loc->flags >> 3;
            switch ( v38 & 0xF )
            {
              case 2:
                giveXPToHero(hero, 1000, 0);
                showMessageWindowForEvent(
                  -1,
                  1,
                  "The Demon screams its challenge and attacks!  After a short, desperate battle, you slay the monster and receive 1,000 experience points.",
                  14,
                  1000,
                  -1,
                  0,
                  -1);
                v39 = loc->flags & 7;
                LOBYTE(v39) = v39 | 8;
                loc->flags = v39;
                Hero::checkForLevelUp(hero);
                break;
              case 3:
                if ( Hero::numArtifacts(hero) == 14 || GameInfo::randomArtifact(gameObject, 14, 1) == -1 )
                  goto LABEL_442;
                giveXPToHero(hero, 1000, 0);
                a2 = Hero::acquireRandomArtifact(hero);
                sprintf(
                  globBuf,
                  "The Demon screams its challenge and attacks!  After a short, desperate battle, you slay the monster and find the %s in the back of the cave.",
                  artifactNames[a2]);
                showMessageWindowForEvent(-1, 1, globBuf, 7, a2, 14, 1000, -1);
                v40 = loc->flags & 7;
                LOBYTE(v40) = v40 | 8;
                loc->flags = v40;
                Hero::checkForLevelUp(hero);
                break;
              case 4:
LABEL_442:
                showMessageWindowForEvent(
                  -1,
                  1,
                  "The Demon screams its challenge and attacks!  After a short, desperate battle, you slay the monster and receive 1,000 experience points and 2,500 gold.",
                  6,
                  2500,
                  14,
                  1000,
                  -1);
                giveXPToHero(hero, 1000, 0);
                grantResource(hero, 6, 2500);
                v41 = loc->flags & 7;
                LOBYTE(v41) = v41 | 8;
                loc->flags = v41;
                Hero::checkForLevelUp(hero);
                break;
              case 5:
                showMessageWindowForEvent(
                  -1,
                  2,
                  "The Demon leaps upon you and has its claws at your throat before you can even draw your sword.  \"Your life is mine,\" it says.  \"I will sell it back to you for 2,500 gold.\"",
                  -1,
                  0,
                  -1,
                  0,
                  -1);
                if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
                {
                  if ( gameObject->players[hero->probablyOwnerIdx].resources[6] >= 2500 )
                  {
                    gameObject->players[hero->probablyOwnerIdx].resources[6] -= 2500;
                  }
                  else
                  {
                    showMessageWindowForEvent(
                      -1,
                      1,
                      "Seeing that you do not have 2500 gold, the demon slashes you with its claws, and the last thing you see is a red haze.",
                      -1,
                      0,
                      -1,
                      0,
                      -1);
                    sub_48F630((int)thisa, (int)hero);
                  }
                }
                else
                {
                  sub_48F630((int)thisa, (int)hero);
                }
                break;
              default:
                break;
            }
            v42 = loc->flags & 7;
            LOBYTE(v42) = v42 | 8;
            loc->flags = v42;
          }
        }
      }
      goto LABEL_508;
    case LOCATION_SHIPWRECK:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      showMessageWindowForEvent(
        -1,
        2,
        "{Shipwreck}\n\nThe rotting hulk of a great pirate ship creaks eerily as it is pushed against the rocks.  Do you wish to search the shipwreck?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
      {
        if ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) == 1 )
        {
          showMessageWindowForEvent(
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
        else
        {
          if ( sub_48E2A0(
                 thisa,
                 hero,
                 loc,
                 "Upon defeating the Ghosts you sift through the debris and find something!",
                 a4) )
          {
            v43 = loc->flags & 7;
            LOBYTE(v43) = v43 | 8;
            loc->flags = v43;
          }
        }
      }
      goto LABEL_508;
    case LOCATION_GRAVEYARD:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      showMessageWindowForEvent(20, 2, byte_517684, -1, 0, -1, 0, -1);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
      {
        if ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) == 1 )
        {
          showMessageWindowForEvent(21, 1, byte_517688, 13, 0, -1, 0, -1);
          if ( !(hero->flags1 & 0x20) )
          {
            *(_DWORD *)&hero->flags1 |= 0x20u;
            --hero->_5[1];
          }
        }
        else
        {
          v54 = usedToCheckForBoatByCastle(
                  thisa,
                  a4 - byte_4F1DC0[4 * hero->_4[11]],
                  HIDWORD(a4) - byte_4F1DC1[4 * hero->_4[11]]);
          if ( sub_48E000((int)thisa, (int)hero, v54, adventureMapLocationMessages[22], a4) )
          {
            v44 = loc->flags & 7;
            LOBYTE(v44) = v44 | 8;
            loc->flags = v44;
          }
        }
      }
      goto LABEL_508;
    case LOCATION_DERELICT_SHIP:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      showMessageWindowForEvent(
        -1,
        2,
        "{Derelict Ship}\n\nThe rotting hulk of a great pirate ship creaks eerily as it is pushed against the rocks.  Do you wish to search the ship?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
      {
        if ( (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) == 1 )
        {
          showMessageWindowForEvent(
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
          v53 = usedToCheckForBoatByCastle(
                  thisa,
                  a4 - byte_4F1DC0[4 * hero->_4[11]],
                  HIDWORD(a4) - byte_4F1DC1[4 * hero->_4[11]]);
          if ( sub_48DD90(
                 (int)thisa,
                 (int)hero,
                 v53,
                 "Upon defeating the Skeletons you sift through the debris and find something!",
                 a4) )
          {
            v45 = loc->flags & 7;
            LOBYTE(v45) = v45 | 8;
            loc->flags = v45;
          }
        }
      }
      goto LABEL_508;
    case LOCATION_PYRAMID:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      showMessageWindowForEvent(
        -1,
        2,
        "You come upon the pyramid of a great and ancient king.  You are tempted to search it for treasure, but all the old stories warn of fearful curses and undead guardians.  Will you search?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
      {
        if ( (unsigned __int8)(loc->flags >> 8) >> -5 )
        {
          if ( !sub_48E820(thisa, (int)hero, 51, 30, (int)loc, a4, 0, a4, 53, 20, 2, -1, 0, 0) )
          {
            Hero::checkForLevelUp(hero);
            sprintf(
              msg,
              "%s'%s'.  ",
              "Upon defeating the monsters, you decipher an ancient glyph on the wall, telling the secret of the spell - ",
              dword_4F6ABC[(unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5)]);
            if ( Hero::hasArtifact(hero, ARTIFACT_MAGIC_BOOK) )
            {
              if ( hero->secondarySkillLevel[7] < 3 )
              {
                strcat(
                  msg,
                  "  Unfortunately, you do not have the wisdom to understand the spell, and you are unable to learn it.  ");
                showMessageWindowForEvent(-1, 1, msg, -1, 0, -1, 0, -1);
              }
              else
              {
                v46 = Hero::getPrimarySkill(hero, PRIMARY_SKILL_KNOWLEDGE);
                Hero::learnSpell(hero, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) - 1, v46);
                showMessageWindowForEvent(
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
              showMessageWindowForEvent(-1, 1, msg, -1, 0, -1, 0, -1);
            }
            loc->flags &= 7u;
          }
        }
        else
        {
          display_message_window(
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
      goto LABEL_508;
    case LOCATION_ABANDONED_MINE:
      playTrackForLocationVisit(locType, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), (_QWORD *)a3a);
      showMessageWindowForEvent(
        -1,
        2,
        "You come upon an abandoned gold mine.  The mine appears to be haunted.  Do you wish to enter?",
        -1,
        0,
        -1,
        0,
        -1);
      if ( HeroWindowManager::instance->buttonPressedCode == 30725
        && !sub_48E820(
              thisa,
              (int)hero,
              gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 3],
              gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 4],
              (int)loc,
              a4,
              0,
              a4,
              -1,
              0,
              0,
              -1,
              0,
              0) )
      {
        Hero::checkForLevelUp(hero);
        showMessageWindowForEvent(
          -1,
          1,
          "You beat the Ghosts and are able to restore the mine to production.",
          -1,
          0,
          -1,
          0,
          -1);
        sub_4270A0(gameObject, a4 - 2, HIDWORD(a4) - 1, a4 + 1, HIDWORD(a4) - 1, 56, 0, 4, 26, 104, 64, 23);
        sub_4270A0(gameObject, a4 - 2, SHIDWORD(a4), a4 + 1, SHIDWORD(a4), 56, 5, 9, 26, 109, 64, 23);
        sub_4270A0(gameObject, a4 - 2, HIDWORD(a4) - 1, a4 + 1, HIDWORD(a4) - 1, 51, 0, 3, 32, 75, 64, 23);
        sub_4270A0(gameObject, a4 - 2, SHIDWORD(a4), a4 + 1, SHIDWORD(a4), 51, 4, 7, 32, 80, 64, 23);
        sub_4270A0(gameObject, a4, SHIDWORD(a4), a4, SHIDWORD(a4), 29, 5, 5, 29, 4, 64, 23);
        gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 2] = 6;
        gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 3] = -1;
        gameObject->_8[7 * (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5) + 4] = 0;
        sub_4212E0(gameObject, (unsigned __int8)((unsigned __int8)(loc->flags >> 8) >> -5), curPlayerIdx);
      }
      goto LABEL_508;
    case LOCATION_BARRIER:
      v85 = sub_48C4C0(loc, hero);
      goto LABEL_508;
    case LOCATION_TRAVELLER_TENT:
      visitTravellerTent(loc, hero);
      goto LABEL_508;
    case LOCATION_ALCHEMIST_TOWER:
      sub_48C770(thisa, (int)loc, hero);
      goto LABEL_508;
    case LOCATION_EXPANSION_DWELLING:
      sub_48CE90((int)loc, (int)hero);
      goto LABEL_508;
    case LOCATION_JAIL:
      visit_jail(thisa, (int)loc, (int)hero, a4, SHIDWORD(a4));
      goto LABEL_508;
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
      goto LABEL_508;
  }
}

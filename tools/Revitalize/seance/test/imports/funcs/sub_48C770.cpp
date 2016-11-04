{
  void *v3; // [sp+14h] [bp-4Ch]@1
  int xp; // [sp+18h] [bp-48h]@44
  int v5; // [sp+1Ch] [bp-44h]@46
  signed int v6; // [sp+20h] [bp-40h]@47
  char v7; // [sp+24h] [bp-3Ch]@55
  int y; // [sp+30h] [bp-30h]@33
  MapTile *v9; // [sp+34h] [bp-2Ch]@35
  signed int i; // [sp+3Ch] [bp-24h]@2
  signed int j; // [sp+3Ch] [bp-24h]@13
  signed int k; // [sp+3Ch] [bp-24h]@44
  int a2; // [sp+40h] [bp-20h]@1
  int x; // [sp+48h] [bp-18h]@31
  int v15; // [sp+4Ch] [bp-14h]@1
  int a3[2]; // [sp+54h] [bp-Ch]@1
  int v17; // [sp+5Ch] [bp-4h]@25

  v3 = ecx0;
  v15 = 0;
  *(_QWORD *)a3 = stru_5230F8;
  a2 = ((unsigned __int8)(*(_WORD *)(arg0 + 4) >> 8) >> -5) & 0x3F;
  switch ( ((unsigned __int8)(*(_WORD *)(arg0 + 4) >> 8) >> -5) & 0x3F )
  {
    case 0:
      for ( i = 0; i < 14; ++i )
      {
        if ( artifactHasNegatives((ARTIFACT)this->artifacts[i]) )
          ++v15;
      }
      if ( v15 )
      {
        playTrackForLocationVisit(*(_BYTE *)(arg0 + 9) & 0x7F, a2, (_QWORD *)a3);
        if ( v15 == 1 )
          sprintf(
            globBuf,
            "As you enter the Alchemist's Tower, a hobbled, graying man in a brown cloak makes his way towards you.  He checks your pack, and sees that you have 1 cursed item.  For 750 gold, the alchemist will remove it for you.  Do you pay?");
        else
          sprintf(
            globBuf,
            "As you enter the Alchemist's Tower, a hobbled, graying man in a brown cloak makes his way towards you.  He checks your pack, and sees that you have %d cursed items.  For 750 gold,  the alchemist will remove them for you.  Do you pay?",
            v15);
        display_message_window(globBuf, 2, -1, -1, -1, 0, -1, 0, -1, 0);
        if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
        {
          if ( curPlayer->resources[6] < 750 )
          {
            display_message_window(
              "You hear a voice from behind the locked door, \"You don't have enough gold to pay for my services.\"",
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
            for ( j = 0; j < 14; ++j )
            {
              if ( artifactHasNegatives((ARTIFACT)this->artifacts[j]) )
              {
                Hero::alterPrimarySkillsForArtifact(this, (ARTIFACT)this->artifacts[j], 1);
                this->artifacts[j] = -1;
              }
            }
            curPlayer->resources[6] -= 750;
          }
        }
      }
      else
      {
        display_message_window(
          "You hear a voice from high above in the tower, \"Go away! I can't help you!\"",
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
    case 1:
      if ( this->flags3 & 0x40 )
      {
        display_message_window("The Arena guards turn you away.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      }
      else
      {
        playTrackForLocationVisit(*(_BYTE *)(arg0 + 9) & 0x7F, a2, (_QWORD *)a3);
        *(_DWORD *)&this->flags1 |= 0x400000u;
        v17 = sub_463740();
        ++this->primarySkills[v17];
      }
      break;
    case 5:
      if ( this->flags3 & 0x10 )
      {
        display_message_window(
          "The mermaids silently entice you to return later and be blessed again.",
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
        playTrackForLocationVisit(*(_BYTE *)(arg0 + 9) & 0x7F, a2, (_QWORD *)a3);
        *(_DWORD *)&this->flags1 |= 0x100000u;
        ++this->_5[2];
        showMessageWindowForEvent(
          -1,
          1,
          "The magical, soothing beauty of the Mermaids reaches you and your crew.  Just for a moment, you forget your worries and bask in the beauty of the moment.  The mermaids charms bless you with increased luck for your next combat.",
          10,
          0,
          -1,
          0,
          -1);
      }
      break;
    case 2:
      playTrackForLocationVisit(*(_BYTE *)(arg0 + 9) & 0x7F, a2, (_QWORD *)a3);
      display_message_window(
        "You enter a rickety hut and talk to the magician who lives there.  He tells you of places near and far which may aid you in your journeys.",
        1,
        -1,
        -1,
        -1,
        0,
        -1,
        0,
        -1,
        0);
      for ( x = 0; mapWidth > x; ++x )
      {
        for ( y = 0; y < mapHeight; ++y )
        {
          v9 = &gameObject->map.tiles[y * gameObject->map.width] + x;
          if ( (v9->objType & 0x7F) == 122 && (((unsigned __int8)(v9->flags >> 8) >> -5) & 7) == 3 )
          {
            explore(x, y, curPlayerIdx, 10);
            sub_448110((AdvManager *)v3, 0);
            sub_447A00(v3, 0, 0);
          }
        }
      }
      break;
    case 3:
      display_message_window("This eye seems to be intently studying its surroundings.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      break;
    case 6:
      if ( this->flags3 & 0x20 )
      {
        display_message_window(
          "You have your crew stop up their ears with wax before the sirens' eerie song has any chance of luring them to a watery grave.",
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
        xp = 0;
        for ( k = 0; k < 5; ++k )
        {
          v5 = this->army.creatureTypes[k];
          if ( v5 != -1 )
          {
            v6 = this->army.quantities[k];
            if ( v6 > 1 )
            {
              this->army.quantities[k] = (signed __int64)((double)v6 * 0.7);
              xp += creature_table[v5].hp * (v6 - this->army.quantities[k]);
            }
          }
        }
        if ( xp )
        {
          playTrackForLocationVisit(*(_BYTE *)(arg0 + 9) & 0x7F, a2, (_QWORD *)a3);
          sprintf(
            globBuf,
            "An eerie wailing song emanates from the sirens perched upon the rocks.  Many of your crew fall under its spell, and dive into the water where they drown.  You are now wiser for the visit, and gain %d experience.",
            xp);
          display_message_window(globBuf, 1, -1, -1, -1, 0, -1, 0, -1, 0);
          giveXPToHero(this, xp, 1);
        }
        else
        {
          display_message_window(
            "As the sirens sing their eerie song, your small, determined army manages to overcome the urge to dive headlong into the sea.",
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
        *(_DWORD *)&this->flags1 |= 0x200000u;
      }
      break;
    case 4:
      v7 = 0;
      if ( !(this->flags3 & 0x80) )
      {
        *(_DWORD *)&this->flags1 |= 0x800000u;
        *(_DWORD *)&this->_4[16] += 400;
        *(_DWORD *)&this->_4[20] += 400;
        v7 = 1;
      }
      if ( Hero::numStacksOfCreatureType(this, 7) )
      {
        Hero::transmuteStacks(this, 7, 8);
        v7 |= 2u;
      }
      if ( v7 )
        playTrackForLocationVisit(*(_BYTE *)(arg0 + 9) & 0x7F, a2, (_QWORD *)a3);
      sprintf(globBuf, (&off_51A8C8)[4 * v7]);
      if ( v7 & 2 )
        showMessageWindowForEvent(-1, 1, globBuf, 18, 8, -1, 0, -1);
      else
        showMessageWindowForEvent(-1, 1, globBuf, -1, 0, -1, 0, -1);
      break;
    default:
      return;
  }
}

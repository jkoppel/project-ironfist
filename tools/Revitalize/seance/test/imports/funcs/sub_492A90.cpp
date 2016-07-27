{
  GUIWindow *result; // eax@20
  void *v9; // [sp+14h] [bp-14Ch]@1
  char v10; // [sp+18h] [bp-148h]@69
  int v11; // [sp+144h] [bp-1Ch]@57
  signed int img1Arg; // [sp+148h] [bp-18h]@63
  int v13; // [sp+14Ch] [bp-14h]@1
  float v14; // [sp+150h] [bp-10h]@1
  int creatureType; // [sp+154h] [bp-Ch]@1
  GUIWindow *v16; // [sp+158h] [bp-8h]@78
  __int16 quantity[2]; // [sp+15Ch] [bp-4h]@1

  v9 = this;
  MouseManager::enableCursor(mouseManager);
  creatureType = *(_BYTE *)(a2 + 3);
  v13 = ((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) & 0;
  *(_DWORD *)quantity = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5);
  v14 = (double)getArmyStrength((ArmyInfo *)(a4 + 101), (Hero *)a4, 0, 0, 0, 0)
      / (double)(*(_DWORD *)quantity * creature_table[creatureType].fight_value);
  if ( loadOrNewGameSelected
    && (gameObject->_1[121] && (creatureType == 21 || creatureType == 22)
     || gameObject->_1[129] && (creatureType == 15 || creatureType == 16)
     || gameObject->_1[130] && (creatureType == 35 || creatureType == 36 || creatureType == 37)) )
  {
    if ( ArmyInfo::hasRoomForCreatureType((ArmyInfo *)(a4 + 101), creatureType) )
    {
      if ( creatureType != 21 && creatureType != 22 )
      {
        if ( creatureType != 15 && creatureType != 16 )
          display_message_window(
            "The dragons, snarling and growling, agree to join forces with you, their 'Ally'.",
            1,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
        else
          display_message_window(
            "The ogres recognize you as the Dwarfbane and lumber over to join you.",
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
          "The dwarves recognize their allies and gladly join your forces.",
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
      ArmyInfo::addCreatures((ArmyInfo *)(a4 + 101), creatureType, quantity[0], -1);
      result = (GUIWindow *)a5;
      *(_DWORD *)a5 = 1;
    }
    else
    {
      if ( creatureType != 21 && creatureType != 22 )
      {
        if ( creatureType != 15 && creatureType != 16 )
          display_message_window(
            "The dragons see you and call out.  \"Our alliance with Archibald compels us to join you.  Unfortunately you have no room.  A pity!\"  They quickly scatter.",
            1,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
        else
          display_message_window(
            "The ogres give you a grunt of recognition, \"Archibald's allies may pass.\"",
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
          "The dwarves hail you, \"Any friend of Roland is a friend of ours.  You may pass.\"",
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
      result = (GUIWindow *)a5;
      *(_DWORD *)a5 = 1;
    }
    return result;
  }
  if ( loadOrNewGameSelected && gameObject->_1[128] && (creatureType == 21 || creatureType == 22) )
  {
    display_message_window("\"The Dwarfbane!!!!, run for your lives.\"", 1, -1, -1, -1, 0, -1, 0, -1, 0);
    result = (GUIWindow *)a5;
    *(_DWORD *)a5 = 1;
    return result;
  }
  if ( byte_5304A0 && sub_470560(&unk_530450, 0) && (creatureType == 23 || creatureType == 24) )
  {
    *(_DWORD *)a5 = 1;
    if ( ArmyInfo::hasRoomForCreatureType((ArmyInfo *)(a4 + 101), creatureType) )
    {
      display_message_window(
        "As you approach the group of elves, their leader calls them all to attention.  He shouts to them, \"Who of you is brave enough to join this fearless ally of ours?\"  The group explodes with cheers as they run to join your ranks.",
        1,
        -1,
        -1,
        -1,
        0,
        -1,
        0,
        -1,
        0);
      result = (GUIWindow *)ArmyInfo::addCreatures((ArmyInfo *)(a4 + 101), creatureType, quantity[0], -1);
    }
    else
    {
      result = display_message_window(
                 "The elves stand at attention as you approach.  Their leader calls to you and says, \"Let us not impede your progress, ally!  Move on, and may victory be yours.\"",
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
    return result;
  }
  if ( !ArmyInfo::hasRoomForCreatureType((ArmyInfo *)(a4 + 101), creatureType)
    || v14 <= 2.0
    || Hero::hasArtifact((Hero *)a4, ARTIFACT_HIDEOUS_MASK)
    || creatureType == 59
    || creatureType == 62
    || creatureType == 63
    || creatureType == 64
    || creatureType == 65 )
    goto LABEL_86;
  if ( v13 )
  {
    sprintf(globBuf, adventureMapLocationMessages[66], creaturePluralNames[creatureType]);
    showMessageWindowForEvent(-1, 2, globBuf, -1, 0, -1, 0, -1);
    if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
    {
      ArmyInfo::addCreatures((ArmyInfo *)(a4 + 101), creatureType, quantity[0], -1);
      result = (GUIWindow *)a5;
      *(_DWORD *)a5 = 1;
      return result;
    }
    showMessageWindowForEvent(67, 1, byte_518974, -1, 0, -1, 0, -1);
    goto LABEL_78;
  }
  if ( !*(_BYTE *)(a4 + 120) )
  {
LABEL_86:
    if ( v14 <= 5.0 )
      goto LABEL_78;
LABEL_76:
    sprintf(
      globBuf,
      "The %s, awed by the power of your forces, begin to scatter.  Do you wish to pursue and engage them?",
      creaturePluralNames[creatureType]);
    showMessageWindowForEvent(-1, 2, globBuf, -1, 0, -1, 0, -1);
    if ( HeroWindowManager::instance->buttonPressedCode != 30725 )
    {
      result = (GUIWindow *)a5;
      *(_DWORD *)a5 = 1;
      return result;
    }
    goto LABEL_78;
  }
  if ( *(_BYTE *)(a4 + 120) == 3 )
  {
    v11 = *(_DWORD *)quantity;
  }
  else
  {
    if ( *(_BYTE *)(a4 + 120) == 2 )
      v11 = *(_DWORD *)quantity / 2;
    else
      v11 = *(_DWORD *)quantity / 4;
  }
  if ( !v11 )
    v11 = 1;
  img1Arg = *(_DWORD *)quantity * creature_table[creatureType].cost;
  if ( gameObject->players[*(_BYTE *)(a4 + 3)].resources[6] >= img1Arg )
  {
    if ( *(_DWORD *)quantity == 1 )
    {
      sprintf(
        globBuf,
        "The %s is swayed by your diplomatic tongue, and offers to join your army for the sum of %d gold.  Do you accept?",
        creatureSingularNames[creatureType],
        img1Arg);
    }
    else
    {
      sprintf(globBuf, "The creatures are swayed by your diplomatic tongue, and make you an offer:\n\n");
      if ( *(_DWORD *)quantity == v11 )
        sprintf(
          &v10,
          "All %d of the %s will join your army for the sum of %d gold.  Do you accept?",
          *(_DWORD *)quantity,
          creaturePluralNames[creatureType],
          img1Arg);
      else
        sprintf(
          &v10,
          "%d of the %d %s will join your army, and the rest will leave you alone, for the sum of %d gold.  Do you accept?",
          v11,
          *(_DWORD *)quantity,
          creaturePluralNames[creatureType],
          img1Arg);
      strcat(globBuf, &v10);
    }
    display_message_window(globBuf, 2, -1, -1, 6, img1Arg, -1, 0, -1, 0);
    if ( HeroWindowManager::instance->buttonPressedCode == 30725 )
    {
      ArmyInfo::addCreatures((ArmyInfo *)(a4 + 101), creatureType, v11, -1);
      *(_DWORD *)a5 = 1;
      result = (GUIWindow *)img1Arg;
      gameObject->players[*(_BYTE *)(a4 + 3)].resources[6] -= img1Arg;
      return result;
    }
    showMessageWindowForEvent(67, 1, byte_518AFC, -1, 0, -1, 0, -1);
    goto LABEL_78;
  }
  if ( v14 > 5.0 )
    goto LABEL_76;
LABEL_78:
  result = (GUIWindow *)sub_48E820(
                          (AdvManager *)v9,
                          a4,
                          creatureType,
                          *(signed int *)quantity,
                          a3,
                          a6,
                          0,
                          a8,
                          -1,
                          0,
                          0,
                          -1,
                          0,
                          0);
  v16 = result;
  if ( !result || v16 == (GUIWindow *)-1 )
  {
    result = (GUIWindow *)a5;
    *(_DWORD *)a5 = 1;
  }
  return result;
}

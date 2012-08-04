{
  heroWindow *result; // eax@20
  void *thisa; // [sp+14h] [bp-14Ch]@1
  char v10; // [sp+18h] [bp-148h]@69
  int v11; // [sp+144h] [bp-1Ch]@57
  signed int img1Arg; // [sp+148h] [bp-18h]@63
  int v13; // [sp+14Ch] [bp-14h]@1
  float v14; // [sp+150h] [bp-10h]@1
  int a3a; // [sp+154h] [bp-Ch]@1
  heroWindow *v16; // [sp+158h] [bp-8h]@78
  __int16 a4a[2]; // [sp+15Ch] [bp-4h]@1

  thisa = this;
  mouseManager::ShowColorPointer(gpMouseManager);
  a3a = *(_BYTE *)(a2 + 3);
  v13 = ((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5) & 0;
  *(_DWORD *)a4a = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a2 + 4) >> 8) >> -5);
  v14 = (double)philAI::FightValueOfStack((armyGroup *)(a4 + 101), (hero *)a4, 0, 0, 0, 0)
      / (double)(*(_DWORD *)a4a * gMonsterDatabase[a3a].fight_value);
  if ( gbInCampaign
    && (gpGame->_1[121] && (a3a == 21 || a3a == 22)
     || gpGame->_1[129] && (a3a == 15 || a3a == 16)
     || gpGame->_1[130] && (a3a == 35 || a3a == 36 || a3a == 37)) )
  {
    if ( armyGroup::CanJoin((armyGroup *)(a4 + 101), a3a) )
    {
      if ( a3a != 21 && a3a != 22 )
      {
        if ( a3a != 15 && a3a != 16 )
          NormalDialog(
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
          NormalDialog(
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
        NormalDialog("The dwarves recognize their allies and gladly join your forces.", 1, -1, -1, -1, 0, -1, 0, -1, 0);
      }
      armyGroup::Add((armyGroup *)(a4 + 101), a3a, a4a[0], -1);
      result = (heroWindow *)a5;
      *(_DWORD *)a5 = 1;
    }
    else
    {
      if ( a3a != 21 && a3a != 22 )
      {
        if ( a3a != 15 && a3a != 16 )
          NormalDialog(
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
          NormalDialog(
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
        NormalDialog(
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
      result = (heroWindow *)a5;
      *(_DWORD *)a5 = 1;
    }
    return result;
  }
  if ( gbInCampaign && gpGame->_1[128] && (a3a == 21 || a3a == 22) )
  {
    NormalDialog("\"The Dwarfbane!!!!, run for your lives.\"", 1, -1, -1, -1, 0, -1, 0, -1, 0);
    result = (heroWindow *)a5;
    *(_DWORD *)a5 = 1;
    return result;
  }
  if ( xIsPlayingExpansionCampaign && ExpCampaign::HasAward(&xCampaign, 0) && (a3a == 23 || a3a == 24) )
  {
    *(_DWORD *)a5 = 1;
    if ( armyGroup::CanJoin((armyGroup *)(a4 + 101), a3a) )
    {
      NormalDialog(
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
      result = (heroWindow *)armyGroup::Add((armyGroup *)(a4 + 101), a3a, a4a[0], -1);
    }
    else
    {
      result = NormalDialog(
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
  if ( !armyGroup::CanJoin((armyGroup *)(a4 + 101), a3a)
    || v14 <= 2.0
    || hero::HasArtifact((hero *)a4, ARTIFACT_HIDEOUS_MASK)
    || a3a == 59
    || a3a == 62
    || a3a == 63
    || a3a == 64
    || a3a == 65 )
    goto LABEL_86;
  if ( v13 )
  {
    sprintf(gText, gEventText[66], gArmyNamesPlural[a3a]);
    advManager::EventWindow(-1, 2, gText, -1, 0, -1, 0, -1);
    if ( gpWindowManager->buttonPressedCode == 30725 )
    {
      armyGroup::Add((armyGroup *)(a4 + 101), a3a, a4a[0], -1);
      result = (heroWindow *)a5;
      *(_DWORD *)a5 = 1;
      return result;
    }
    advManager::EventWindow(67, 1, byte_518974, -1, 0, -1, 0, -1);
    goto LABEL_78;
  }
  if ( !*(_BYTE *)(a4 + 120) )
  {
LABEL_86:
    if ( v14 <= 5.0 )
      goto LABEL_78;
LABEL_76:
    sprintf(
      gText,
      "The %s, awed by the power of your forces, begin to scatter.  Do you wish to pursue and engage them?",
      gArmyNamesPlural[a3a]);
    advManager::EventWindow(-1, 2, gText, -1, 0, -1, 0, -1);
    if ( gpWindowManager->buttonPressedCode != 30725 )
    {
      result = (heroWindow *)a5;
      *(_DWORD *)a5 = 1;
      return result;
    }
    goto LABEL_78;
  }
  if ( *(_BYTE *)(a4 + 120) == 3 )
  {
    v11 = *(_DWORD *)a4a;
  }
  else if ( *(_BYTE *)(a4 + 120) == 2 )
  {
    v11 = *(_DWORD *)a4a / 2;
  }
  else
  {
    v11 = *(_DWORD *)a4a / 4;
  }
  if ( !v11 )
    v11 = 1;
  img1Arg = *(_DWORD *)a4a * gMonsterDatabase[a3a].cost;
  if ( gpGame->players[*(_BYTE *)(a4 + 3)].resources[6] >= img1Arg )
  {
    if ( *(_DWORD *)a4a == 1 )
    {
      sprintf(
        gText,
        "The %s is swayed by your diplomatic tongue, and offers to join your army for the sum of %d gold.  Do you accept?",
        gArmyNames[a3a],
        img1Arg);
    }
    else
    {
      sprintf(gText, "The creatures are swayed by your diplomatic tongue, and make you an offer:\n\n");
      if ( *(_DWORD *)a4a == v11 )
        sprintf(
          &v10,
          "All %d of the %s will join your army for the sum of %d gold.  Do you accept?",
          *(_DWORD *)a4a,
          gArmyNamesPlural[a3a],
          img1Arg);
      else
        sprintf(
          &v10,
          "%d of the %d %s will join your army, and the rest will leave you alone, for the sum of %d gold.  Do you accept?",
          v11,
          *(_DWORD *)a4a,
          gArmyNamesPlural[a3a],
          img1Arg);
      strcat(gText, &v10);
    }
    NormalDialog(gText, 2, -1, -1, 6, img1Arg, -1, 0, -1, 0);
    if ( gpWindowManager->buttonPressedCode == 30725 )
    {
      armyGroup::Add((armyGroup *)(a4 + 101), a3a, v11, -1);
      *(_DWORD *)a5 = 1;
      result = (heroWindow *)img1Arg;
      gpGame->players[*(_BYTE *)(a4 + 3)].resources[6] -= img1Arg;
      return result;
    }
    advManager::EventWindow(67, 1, byte_518AFC, -1, 0, -1, 0, -1);
    goto LABEL_78;
  }
  if ( v14 > 5.0 )
    goto LABEL_76;
LABEL_78:
  result = (heroWindow *)advManager::CombatMonsterEvent(
                           (advManager *)thisa,
                           (hero *)a4,
                           (CREATURES)a3a,
                           *(signed int *)a4a,
                           (mapCell *)a3,
                           a6,
                           SHIDWORD(a6),
                           0,
                           a8,
                           SHIDWORD(a8),
                           -1,
                           0,
                           0,
                           -1,
                           0,
                           0);
  v16 = result;
  if ( !result || v16 == (heroWindow *)-1 )
  {
    result = (heroWindow *)a5;
    *(_DWORD *)a5 = 1;
  }
  return result;
}
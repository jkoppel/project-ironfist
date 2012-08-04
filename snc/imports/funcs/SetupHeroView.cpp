{
  char v0; // al@17
  town *v1; // eax@18
  town *v2; // eax@41
  char v3; // al@70
  char v4; // al@73
  int v5; // [sp+Ch] [bp-58h]@73
  signed int v6; // [sp+10h] [bp-54h]@1
  int evt; // [sp+14h] [bp-50h]@3
  int v8; // [sp+18h] [bp-4Ch]@3
  int v9; // [sp+1Ch] [bp-48h]@3
  int v10; // [sp+2Ch] [bp-38h]@3
  SECONDARY_SKILL skill; // [sp+30h] [bp-34h]@73
  PRIMARY_SKILL v12; // [sp+34h] [bp-30h]@27
  PRIMARY_SKILL a2; // [sp+38h] [bp-2Ch]@6
  int v14; // [sp+3Ch] [bp-28h]@18
  PRIMARY_SKILL v15; // [sp+40h] [bp-24h]@18
  int v16; // [sp+44h] [bp-20h]@41
  int this; // [sp+48h] [bp-1Ch]@85
  int v18; // [sp+50h] [bp-14h]@85

  v6 = gbNoDismiss;
  if ( gpHVHero->occupiedObjType == 163 )
    v6 = 1;
  evt = INPUT_GUI_MESSAGE_CODE;
  sprintf(gText, "%s the %s", gpHVHero->name, (&gAlignmentNames)[4 * gpHVHero->factionID]);
  v8 = 3;
  v9 = 2;
  v10 = (int)gText;
  heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  if ( gpHVHero->probablyOwnerIdx != giCurPlayer || gpCurPlayer->numHeroes == 1 )
  {
    v8 = 5;
    v10 = 4096;
    v9 = 300;
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
    v9 = 301;
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
    v8 = 6;
    v10 = 2;
    v9 = 300;
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
    v9 = 301;
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  }
  v8 = 6;
  v10 = 4;
  for ( a2 = 0; (signed int)a2 < 5; ++a2 )
  {
    v9 = a2 + 81;
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
    v9 = a2 + 102;
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  }
  if ( v6 || gpTownManager->field_15A || !gpCurPlayer->numCastles && gpCurPlayer->numHeroes == 1 )
    v8 = 6;
  else
    v8 = 5;
  v9 = 30723;
  v10 = 6;
  heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  sprintf(gText, "port%04d.icn", gpHVHero->heroID);
  v8 = 9;
  v9 = 65;
  v10 = (int)gText;
  heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  v8 = 3;
  for ( a2 = 0; (signed int)a2 < 4; ++a2 )
  {
    v0 = hero::Stats(gpHVHero, a2);
    sprintf(gText, "%d", v0);
    v9 = a2 + 76;
    v10 = (int)gText;
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  }
  v1 = hero::GetOccupiedTown(gpHVHero);
  v14 = game::GetLuck(gpHVHero, 0, v1);
  v15 = abs(v14);
  if ( (signed int)v15 <= 0 )
    v15 = 1;
  for ( a2 = 0; (signed int)a2 < 3; ++a2 )
  {
    if ( a2 < v15 )
      v8 = 5;
    else
      v8 = 6;
    if ( a2 == 1 && v14 )
    {
      v12 = 0;
    }
    else if ( a2 || !v14 )
    {
      v12 = a2;
    }
    else
    {
      v12 = 1;
    }
    v9 = v12 + 203;
    v10 = 6;
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  }
  for ( a2 = 0; (signed int)a2 < 3; ++a2 )
  {
    v8 = 4;
    v9 = a2 + 203;
    if ( v14 >= 0 )
    {
      if ( v14 )
        v10 = 2;
      else
        v10 = 6;
    }
    else
    {
      v10 = 3;
    }
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  }
  v2 = hero::GetOccupiedTown(gpHVHero);
  v16 = armyGroup::GetMorale(&gpHVHero->army, gpHVHero, v2, 0);
  v15 = abs(v16);
  if ( (signed int)v15 <= 0 )
    v15 = 1;
  for ( a2 = 0; (signed int)a2 < 3; ++a2 )
  {
    if ( a2 < v15 )
      v8 = 5;
    else
      v8 = 6;
    if ( a2 == 1 && v16 )
    {
      v12 = 0;
    }
    else if ( a2 || !v16 )
    {
      v12 = a2;
    }
    else
    {
      v12 = 1;
    }
    v9 = v12 + 200;
    v10 = 6;
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  }
  for ( a2 = 0; (signed int)a2 < 3; ++a2 )
  {
    v8 = 4;
    v9 = a2 + 200;
    if ( v16 >= 0 )
    {
      if ( v16 )
        v10 = 4;
      else
        v10 = 7;
    }
    else
    {
      v10 = 5;
    }
    heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  }
  sprintf(gText, "%d", gpHVHero->experience);
  v8 = 3;
  v9 = 207;
  v10 = (int)gText;
  heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  if ( gpHVHero->flags2 & 0x80 )
    v8 = 6;
  else
    v8 = 5;
  v9 = 213;
  v10 = 4;
  heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  if ( gpHVHero->flags2 & 0x80 )
    v8 = 5;
  else
    v8 = 6;
  v9 = 215;
  v10 = 4;
  heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  v3 = hero::Stats(gpHVHero, PRIMARY_SKILL_KNOWLEDGE);
  sprintf(gText, "%d/%d", gpHVHero->spellpoints, 10 * v3);
  v8 = 3;
  v9 = 212;
  v10 = (int)gText;
  heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  sprintf(gText, "crest.icn");
  v8 = 9;
  v9 = 86;
  heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  v8 = 4;
  v9 = 86;
  v10 = gpCurPlayer->color;
  heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
  hero::UpdateArmies(gpHVHero);
  for ( a2 = 0; (signed int)a2 < 8; ++a2 )
  {
    if ( gpHVHero->numSecSkillsKnown <= a2 )
    {
      v9 = a2 + 400;
      v8 = 4;
      v10 = 0;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v8 = 6;
      v9 = a2 + 408;
      v10 = 6;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v8 = 6;
      v9 = a2 + 416;
      v10 = 6;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
    }
    else
    {
      skill = hero::GetNthSS(gpHVHero, a2);
      v9 = a2 + 400;
      v8 = 4;
      v10 = skill + 1;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v8 = 5;
      v9 = a2 + 408;
      v10 = 6;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v8 = 5;
      v9 = a2 + 416;
      v10 = 6;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v8 = 3;
      v9 = a2 + 408;
      v10 = (int)gSecondarySkills[skill];
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v8 = 3;
      v9 = a2 + 416;
      v4 = hero::GetSSLevel(gpHVHero, skill);
      v5 = v4 - gpHVHero->secondarySkillLevel[skill];
      if ( v5 <= 0 )
        sprintf(gText, "%s", secondarySkillLevels[gpHVHero->secondarySkillLevel[skill]]);
      else
        sprintf(gText, "%s+%d", secondarySkillLevels[gpHVHero->secondarySkillLevel[skill]], v5);
      v10 = (int)gText;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
    }
  }
  for ( a2 = 0; (signed int)a2 < 14; ++a2 )
  {
    v9 = a2 + 20;
    if ( gpHVHero->artifacts[a2] == -1 )
    {
      v8 = 4;
      v10 = 0;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v8 = 6;
      v10 = 2;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
    }
    else
    {
      v8 = 5;
      v10 = 2;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
      v8 = 4;
      v10 = gpHVHero->artifacts[a2] + 1;
      heroWindow::BroadcastMessage(heroWin, (Event *)&evt);
    }
  }
  this = 512;
  v18 = -1;
  UpdateHeroScreenStatusBar((hero *)&this);
}
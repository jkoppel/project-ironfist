void __cdecl sub_497B90()
{
  char v0; // al@17
  Castle *v1; // eax@18
  Castle *v2; // eax@41
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

  v6 = dword_52FF34;
  if ( *(_WORD *)&viewedHero->_4[12] == 163 )
    v6 = 1;
  evt = INPUT_GUI_MESSAGE_CODE;
  sprintf(globBuf, "%s the %s", viewedHero->name, (&off_4F5AF8)[4 * viewedHero->factionID]);
  v8 = 3;
  v9 = 2;
  v10 = (int)globBuf;
  GUIWindow::processMessage(heroWindow, (Event *)&evt);
  if ( viewedHero->probablyOwnerIdx != curPlayerIdx || curPlayer->numHeroes == 1 )
  {
    v8 = 5;
    v10 = 4096;
    v9 = 300;
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
    v9 = 301;
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
    v8 = 6;
    v10 = 2;
    v9 = 300;
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
    v9 = 301;
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
  }
  v8 = 6;
  v10 = 4;
  for ( a2 = 0; (signed int)a2 < 5; ++a2 )
  {
    v9 = a2 + 81;
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
    v9 = a2 + 102;
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
  }
  if ( v6 || townManager->field_15A || !curPlayer->numCastles && curPlayer->numHeroes == 1 )
    v8 = 6;
  else
    v8 = 5;
  v9 = 30723;
  v10 = 6;
  GUIWindow::processMessage(heroWindow, (Event *)&evt);
  sprintf(globBuf, "port%04d.icn", viewedHero->heroID);
  v8 = 9;
  v9 = 65;
  v10 = (int)globBuf;
  GUIWindow::processMessage(heroWindow, (Event *)&evt);
  v8 = 3;
  for ( a2 = 0; (signed int)a2 < 4; ++a2 )
  {
    v0 = Hero::getPrimarySkill(viewedHero, a2);
    sprintf(globBuf, "%d", v0);
    v9 = a2 + 76;
    v10 = (int)globBuf;
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
  }
  v1 = sub_498B70(viewedHero);
  v14 = computeLuck(viewedHero, 0, v1);
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
    else
    {
      if ( a2 || !v14 )
        v12 = a2;
      else
        v12 = 1;
    }
    v9 = v12 + 203;
    v10 = 6;
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
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
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
  }
  v2 = sub_498B70(viewedHero);
  v16 = ArmyInfo::computeMorale(&viewedHero->army, viewedHero, v2, 0);
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
    else
    {
      if ( a2 || !v16 )
        v12 = a2;
      else
        v12 = 1;
    }
    v9 = v12 + 200;
    v10 = 6;
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
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
    GUIWindow::processMessage(heroWindow, (Event *)&evt);
  }
  sprintf(globBuf, "%d", viewedHero->experience);
  v8 = 3;
  v9 = 207;
  v10 = (int)globBuf;
  GUIWindow::processMessage(heroWindow, (Event *)&evt);
  if ( viewedHero->flags2 & 0x80 )
    v8 = 6;
  else
    v8 = 5;
  v9 = 213;
  v10 = 4;
  GUIWindow::processMessage(heroWindow, (Event *)&evt);
  if ( viewedHero->flags2 & 0x80 )
    v8 = 5;
  else
    v8 = 6;
  v9 = 215;
  v10 = 4;
  GUIWindow::processMessage(heroWindow, (Event *)&evt);
  v3 = Hero::getPrimarySkill(viewedHero, PRIMARY_SKILL_KNOWLEDGE);
  sprintf(globBuf, "%d/%d", viewedHero->spellpoints, 10 * v3);
  v8 = 3;
  v9 = 212;
  v10 = (int)globBuf;
  GUIWindow::processMessage(heroWindow, (Event *)&evt);
  sprintf(globBuf, "crest.icn");
  v8 = 9;
  v9 = 86;
  GUIWindow::processMessage(heroWindow, (Event *)&evt);
  v8 = 4;
  v9 = 86;
  v10 = curPlayer->color;
  GUIWindow::processMessage(heroWindow, (Event *)&evt);
  sub_4952A0(viewedHero);
  for ( a2 = 0; (signed int)a2 < 8; ++a2 )
  {
    if ( viewedHero->numSecSkillsKnown <= a2 )
    {
      v9 = a2 + 400;
      v8 = 4;
      v10 = 0;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
      v8 = 6;
      v9 = a2 + 408;
      v10 = 6;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
      v8 = 6;
      v9 = a2 + 416;
      v10 = 6;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
    }
    else
    {
      skill = sub_498B10(viewedHero, a2);
      v9 = a2 + 400;
      v8 = 4;
      v10 = skill + 1;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
      v8 = 5;
      v9 = a2 + 408;
      v10 = 6;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
      v8 = 5;
      v9 = a2 + 416;
      v10 = 6;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
      v8 = 3;
      v9 = a2 + 408;
      v10 = (int)secondary_skill_names[skill];
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
      v8 = 3;
      v9 = a2 + 416;
      v4 = Hero::getSecondarySkillLevelWithBonii(viewedHero, skill);
      v5 = v4 - viewedHero->secondarySkillLevel[skill];
      if ( v5 <= 0 )
        sprintf(globBuf, "%s", secondarySkillLevels[viewedHero->secondarySkillLevel[skill]]);
      else
        sprintf(globBuf, "%s+%d", secondarySkillLevels[viewedHero->secondarySkillLevel[skill]], v5);
      v10 = (int)globBuf;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
    }
  }
  for ( a2 = 0; (signed int)a2 < 14; ++a2 )
  {
    v9 = a2 + 20;
    if ( viewedHero->artifacts[a2] == -1 )
    {
      v8 = 4;
      v10 = 0;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
      v8 = 6;
      v10 = 2;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
    }
    else
    {
      v8 = 5;
      v10 = 2;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
      v8 = 4;
      v10 = viewedHero->artifacts[a2] + 1;
      GUIWindow::processMessage(heroWindow, (Event *)&evt);
    }
  }
  this = 512;
  v18 = -1;
  sub_4966D0((Hero *)&this);
}

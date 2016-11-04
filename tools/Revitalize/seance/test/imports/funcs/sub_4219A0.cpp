{
  int result; // eax@9
  signed int v2; // eax@17
  signed int v3; // eax@18
  int v4; // [sp+Ch] [bp-30h]@1
  int spell; // [sp+10h] [bp-2Ch]@13
  int evt; // [sp+18h] [bp-24h]@1
  int v7; // [sp+1Ch] [bp-20h]@4
  int v8; // [sp+20h] [bp-1Ch]@6
  int v9; // [sp+30h] [bp-Ch]@6
  int i; // [sp+34h] [bp-8h]@9
  int v11; // [sp+38h] [bp-4h]@1

  v4 = this;
  evt = 512;
  v11 = **(_WORD **)(this + 26093);
  if ( v11 > 999 )
    v11 = 999;
  memset(&evt, 0, 0x1Cu);
  evt = 512;
  if ( v11 <= 99 )
    v7 = 6;
  else
    v7 = 5;
  v8 = 7;
  v9 = 6;
  GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
  evt = 512;
  if ( v11 <= 9 )
    v7 = 6;
  else
    v7 = 5;
  v8 = 8;
  v9 = 6;
  GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
  sprintf(globBuf, "%d", v11 / 100 % 10);
  evt = 512;
  v7 = 3;
  v8 = 7;
  v9 = (int)globBuf;
  GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
  sprintf(globBuf, "%d", v11 / 10 % 10);
  evt = 512;
  v7 = 3;
  v8 = 8;
  v9 = (int)globBuf;
  GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
  sprintf(globBuf, "%d", v11 % 10);
  evt = 512;
  v7 = 3;
  v8 = 9;
  v9 = (int)globBuf;
  result = GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
  for ( i = 0; i < 12; ++i )
  {
    if ( i + *(_DWORD *)(v4 + 4 * *(_DWORD *)(v4 + 26097) + 26101) < *(_DWORD *)(v4 + 4 * *(_DWORD *)(v4 + 26097) + 26109) )
    {
      evt = 512;
      v7 = 5;
      v8 = i + 30;
      v9 = 2;
      GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
      spell = Hero::getKthSpellKnown(
                *(Hero **)(v4 + 26093),
                *(_DWORD *)(v4 + 26097),
                i + *(_DWORD *)(v4 + 4 * *(_DWORD *)(v4 + 26097) + 26101) + 1);
      evt = 512;
      v7 = 8;
      v8 = i + 30;
      if ( getSpellCost(spell, *(Hero **)(v4 + 26093)) <= **(_WORD **)(v4 + 26093) )
        v9 = 1;
      else
        v9 = 3;
      GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
      if ( Font::numLinesNeededToDisplay(smallFont, spell_names[spell], 78) == 1 )
      {
        v2 = getSpellCost(spell, *(Hero **)(v4 + 26093));
        sprintf(globBuf, "%s\n[%d]", spell_names[spell], v2);
      }
      else
      {
        v3 = getSpellCost(spell, *(Hero **)(v4 + 26093));
        sprintf(globBuf, "%s [%d]", spell_names[spell], v3);
      }
      evt = 512;
      v7 = 3;
      v8 = i + 30;
      v9 = (int)globBuf;
      GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
      evt = 512;
      v7 = 5;
      v8 = i + 30;
      v9 = 6;
      GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
      evt = 512;
      v7 = 5;
      v8 = i + 100;
      v9 = 2;
      GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
      evt = 512;
      v7 = 4;
      v8 = i + 100;
      v9 = spell_table[spell].spriteIdx;
      GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
      evt = 512;
      v7 = 5;
      v8 = i + 100;
      v9 = 6;
      result = GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
    }
    else
    {
      evt = 512;
      v7 = 6;
      v8 = i + 100;
      v9 = 6;
      GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
      evt = 512;
      v7 = 6;
      v8 = i + 30;
      v9 = 6;
      result = GUIWindow::processMessage(*(GUIWindow **)(v4 + 26089), (Event *)&evt);
    }
  }
  return result;
}

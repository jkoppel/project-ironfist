{
  int result; // eax@50
  void *v2; // [sp+Ch] [bp-Ch]@1
  signed int k; // [sp+10h] [bp-8h]@13
  signed int l; // [sp+10h] [bp-8h]@16
  signed int m; // [sp+10h] [bp-8h]@19
  signed int ii; // [sp+10h] [bp-8h]@37
  signed int i; // [sp+14h] [bp-4h]@1
  signed int j; // [sp+14h] [bp-4h]@11
  signed int n; // [sp+14h] [bp-4h]@35
  signed int jj; // [sp+14h] [bp-4h]@41
  signed int kk; // [sp+14h] [bp-4h]@44

  v2 = this;
  sub_4356E0();
  *(_DWORD *)&dword_52478C = 0;
  *(_WORD *)v2 = 1;
  dword_524A74 = 0;
  *(_DWORD *)&dword_52343C = 0;
  *(_DWORD *)&dword_523448 = 0;
  *(_DWORD *)&dword_523F10 = 0;
  *((_BYTE *)v2 + 25501) = 0;
  sub_4C2F30();
  *(_DWORD *)&dword_524A78 = 1;
  strcpy((char *)v2 + 330, "NEWGAME");
  *((_BYTE *)v2 + 1166) = 4;
  *((_BYTE *)v2 + 1167) = 0;
  memset((char *)v2 + 1168, 0, 6u);
  *((_WORD *)v2 + 589) = 1;
  *((_WORD *)v2 + 588) = *((_WORD *)v2 + 589);
  *((_WORD *)v2 + 587) = *((_WORD *)v2 + 588);
  dword_532C54 = 1;
  for ( i = 0; i < 6; ++i )
  {
    strcpy((char *)v2 + 4 * i + 25469, byte_4EF30C);
    if ( dword_5235D4 <= i )
    {
      *(&byte_524758 + i) = 0;
      dword_524810[i] = 0;
    }
    else
    {
      *(&byte_524758 + i) = !i || dword_524778 == 2;
      dword_524810[i] = 1;
    }
    memset((char *)v2 + 283 * i + 1180, 0, 0x11Bu);
    *((_BYTE *)v2 + 283 * i + 1180) = i;
    *((_BYTE *)v2 + 283 * i + 1181) = 0;
    *((_BYTE *)v2 + 283 * i + 1248) = 0;
    *((_BYTE *)v2 + 283 * i + 1247) = -1;
    *((_BYTE *)v2 + 283 * i + 1199) = 0;
    memset((char *)v2 + 283 * i + 1192, -1, 2u);
    memset((char *)v2 + 283 * i + 1184, -1, 8u);
    memset((char *)v2 + 283 * i + 1251, -1, 0x48u);
  }
  *((_BYTE *)v2 + 2898) = 0;
  advManager->field_2A6 = 0;
  memset((char *)v2 + 23680, -1, 0x36u);
  for ( j = 0; j < 54; ++j )
  {
    memset((char *)v2 + 250 * j + 10180, 0, 0xFAu);
    memset((char *)v2 + 250 * j + 10328, 0, 0x41u);
    memset((char *)v2 + 250 * j + 10393, -1, 0xEu);
    *((_BYTE *)v2 + 250 * j + 10222) = -1;
    *((_BYTE *)v2 + 250 * j + 10221) = *((_BYTE *)v2 + 250 * j + 10222);
    *((_BYTE *)v2 + 250 * j + 10182) = j;
    *((_BYTE *)v2 + 250 * j + 10204) = j;
    *((_BYTE *)v2 + 250 * j + 10183) = -1;
    *((_BYTE *)v2 + 250 * j + 10224) = 2;
    strcpy((char *)v2 + 250 * j + 10190, (&hero_names)[4 * j]);
    *((_BYTE *)v2 + 250 * j + 10203) = j / 9;
    for ( k = 0; k < 5; ++k )
      *((_BYTE *)v2 + 250 * j + k + 10243) = *(&hero_starting_stats[*((_BYTE *)v2 + 250 * j + 10203)].attack + k);
    for ( l = 0; l < 5; ++l )
      *((_BYTE *)v2 + 250 * j + l + 10281) = -1;
    *(_DWORD *)((char *)v2 + 250 * j + 10217) = -1;
    *(_DWORD *)((char *)v2 + 250 * j + 10213) = *(_DWORD *)((char *)v2 + 250 * j + 10217);
    *(_WORD *)((char *)v2 + 250 * j + 10241) = 1;
    *((_WORD *)v2 + 125 * j + 5090) = 10
                                    * Hero::getPrimarySkill(
                                        (Hero *)((char *)v2 + 250 * j + 10180),
                                        PRIMARY_SKILL_KNOWLEDGE);
    *(_DWORD *)((char *)v2 + 250 * j + 10324) = 0;
    for ( m = 0; m < 14; ++m )
    {
      *((_BYTE *)v2 + 250 * j + m + 10296) = 0;
      *((_BYTE *)v2 + 250 * j + m + 10310) = 0;
    }
    if ( !*((_BYTE *)v2 + 250 * j + 10203) )
    {
      Hero::learnSecondarySkill((Hero *)((char *)v2 + 250 * j + 10180), 6, 1);
      Hero::learnSecondarySkill((Hero *)((char *)v2 + 250 * j + 10180), 10, 1);
    }
    if ( *((_BYTE *)v2 + 250 * j + 10203) == 2 )
    {
      *((_BYTE *)v2 + 250 * j + 10393) = 81;
      Hero::learnSecondarySkill((Hero *)((char *)v2 + 250 * j + 10180), 5, 2);
      Hero::learnSecondarySkill((Hero *)((char *)v2 + 250 * j + 10180), 7, 1);
    }
    if ( *((_BYTE *)v2 + 250 * j + 10203) == 1 )
      Hero::learnSecondarySkill((Hero *)((char *)v2 + 250 * j + 10180), 0, 2);
    if ( *((_BYTE *)v2 + 250 * j + 10203) == 3 )
    {
      *((_BYTE *)v2 + 250 * j + 10393) = 81;
      Hero::learnSecondarySkill((Hero *)((char *)v2 + 250 * j + 10180), 3, 2);
      Hero::learnSecondarySkill((Hero *)((char *)v2 + 250 * j + 10180), 7, 1);
    }
    if ( *((_BYTE *)v2 + 250 * j + 10203) == 4 )
    {
      *((_BYTE *)v2 + 250 * j + 10393) = 81;
      Hero::learnSecondarySkill((Hero *)((char *)v2 + 250 * j + 10180), 7, 2);
    }
    if ( *((_BYTE *)v2 + 250 * j + 10203) == 5 )
    {
      *((_BYTE *)v2 + 250 * j + 10393) = 81;
      Hero::learnSecondarySkill((Hero *)((char *)v2 + 250 * j + 10180), 7, 1);
      Hero::learnSecondarySkill((Hero *)((char *)v2 + 250 * j + 10180), 12, 1);
    }
  }
  memset((char *)v2 + 10099, -1, 0x48u);
  for ( n = 0; n < 72; ++n )
  {
    memset((char *)v2 + 100 * n + 2899, 0, 0x64u);
    *((_BYTE *)v2 + 100 * n + 2953) = 0;
    *((_BYTE *)v2 + 100 * n + 2899) = n;
    *((_BYTE *)v2 + 100 * n + 2900) = -1;
    *((_BYTE *)v2 + 100 * n + 2902) = n / 9;
    *((_BYTE *)v2 + 100 * n + 2922) = -1;
    for ( ii = 0; ii < 5; ++ii )
      *((_BYTE *)v2 + 100 * n + ii + 2907) = -1;
  }
  for ( jj = 0; jj < 144; ++jj )
    memset((char *)v2 + 7 * jj + 23734, -1, 7u);
  memset((char *)v2 + 24742, -1, 0x90u);
  for ( kk = 0; kk < 48; ++kk )
  {
    memset((char *)v2 + 8 * kk + 24989, 0, 8u);
    *((_BYTE *)v2 + 8 * kk + 24989) = kk;
    *((_BYTE *)v2 + 8 * kk + 24995) = -1;
  }
  memset((char *)v2 + 10171, 0, 9u);
  memset((char *)v2 + 25373, -1, 0x30u);
  *((_BYTE *)v2 + 25494) = -1;
  *((_BYTE *)v2 + 25493) = *((_BYTE *)v2 + 25494);
  memset((char *)v2 + 25421, 0, 0x30u);
  strcpy(&gameObject->_1[325], "NEWGAME");
  curPlayerIdx = 0;
  curPlayer = gameObject->players;
  byte_532C5C = 1;
  for ( dword_523EDC = 0; !*(&byte_524758 + dword_523EDC); dword_523EDC = (dword_523EDC + 1) % *((_BYTE *)v2 + 1166) )
    ;
  byte_5306F0 = 1 << dword_523EDC;
  sub_444550(advManager, 0, -1);
  result = *(&byte_524758 + curPlayerIdx);
  dword_524C14 = *(&byte_524758 + curPlayerIdx);
  return result;
}

{
  int v18; // [sp+10h] [bp-5Ch]@13
  int i; // [sp+18h] [bp-54h]@17
  int j; // [sp+18h] [bp-54h]@48
  int k; // [sp+18h] [bp-54h]@52
  signed int l; // [sp+18h] [bp-54h]@55
  int m; // [sp+18h] [bp-54h]@60
  signed int n; // [sp+18h] [bp-54h]@77
  signed int ii; // [sp+18h] [bp-54h]@80
  int v26[5]; // [sp+1Ch] [bp-50h]@79
  int v27; // [sp+30h] [bp-3Ch]@84
  int v28[5]; // [sp+34h] [bp-38h]@79
  int v29; // [sp+48h] [bp-24h]@9
  int v30; // [sp+4Ch] [bp-20h]@11
  int v31; // [sp+50h] [bp-1Ch]@55
  int v32; // [sp+58h] [bp-14h]@62
  int v33; // [sp+5Ch] [bp-10h]@66
  int v34; // [sp+60h] [bp-Ch]@64
  int v35; // [sp+64h] [bp-8h]@66
  int v36; // [sp+68h] [bp-4h]@71

  advManager::DemobilizeCurrHero(this);
  if ( a9 == -1 )
  {
    a9 = a6;
    a10 = a7;
  }
  else
  {
    *(_QWORD *)&this->field_2B2 = __PAIR__(a10, a9);
    this->field_2BA = a2->x < a9;
    if ( advManager::ComboDraw(this, 0) )
      advManager::UpdateScreen(this, 0, 0);
    this->field_2B2 = -1;
  }
  memset(gpMonGroup, 0xFFu, 5u);
  memset((char *)gpMonGroup + 5, 0, 0xAu);
  v29 = 5 - a13 - a16;
  if ( v29 < 1 )
    v29 = 1;
  v30 = 0;
  SRand(a9 + a10);
  if ( v29 == 5 && !(gMonsterDatabase[creat].creature_flags & 4) )
  {
    v18 = SRandom(0, 100);
    if ( v18 >= 25 )
    {
      if ( v18 < 50 )
        v29 = 4;
    }
    else
    {
      v29 = 3;
    }
  }
  for ( i = 0; i < v29; ++i )
  {
    if ( v29 >> 1 != i
      || creat != CREATURE_ARCHER
      && creat != CREATURE_PIKEMAN
      && creat != CREATURE_SWORDSMAN
      && creat != CREATURE_CAVALRY
      && creat != CREATURE_PALADIN
      && creat != CREATURE_ORC
      && creat != CREATURE_OGRE
      && creat != CREATURE_TROLL
      && creat != CREATURE_DWARF
      && creat != CREATURE_ELF
      && creat != CREATURE_DRUID
      && creat != CREATURE_MINOTAUR
      && creat != CREATURE_GREEN_DRAGON
      && creat != CREATURE_RED_DRAGON
      && creat != CREATURE_IRON_GOLEM
      && creat != CREATURE_MAGE
      && creat != CREATURE_GIANT
      && creat != CREATURE_ZOMBIE
      && creat != CREATURE_MUMMY
      && creat != CREATURE_VAMPIRE
      && creat != CREATURE_LICH
      || SRandom(0, 100) >= 50
      || a12
      || a15 )
      *((_BYTE *)gpMonGroup + i + v30) = creat;
    else
      *((_BYTE *)gpMonGroup + i + v30) = creat + 1;
    *(_WORD *)((char *)gpMonGroup + 2 * (i + v30) + 5) = (unsigned int)(a4 / v29) + (a4 % v29 > i);
  }
  v30 += v29;
  if ( a13 )
  {
    v29 = a13;
    for ( j = 0; j < v29; ++j )
    {
      *((_BYTE *)gpMonGroup + j + v30) = a11;
      *(_WORD *)((char *)gpMonGroup + 2 * (j + v30) + 5) = (unsigned int)(a12 / v29) + (a12 % v29 > j);
    }
  }
  v30 += v29;
  if ( a16 )
  {
    v29 = a16;
    for ( k = 0; k < v29; ++k )
    {
      *((_BYTE *)gpMonGroup + k + v30) = a14;
      *(_WORD *)((char *)gpMonGroup + 2 * (k + v30) + 5) = (unsigned int)(a15 / v29) + (a12 % v29 > k);
    }
  }
  v31 = v29;
  for ( l = 0; l < 5; ++l )
  {
    if ( (signed int)*(_WORD *)((char *)gpMonGroup + 2 * l + 5) <= 0 )
      *((_BYTE *)gpMonGroup + l) = -1;
  }
  for ( m = 0; m < 5; ++m )
    *(&v32 + m) = m;
  switch ( v31 )
  {
    case 1:
      v34 = 0;
      v32 = 2;
      break;
    case 2:
      v33 = 1;
      v35 = 0;
      v32 = 3;
      break;
    case 3:
      v32 = 3;
      v33 = 0;
      v34 = 1;
      v35 = 2;
      break;
    default:
      if ( a16 != 1 || a13 != 1 )
      {
        if ( a16 != 1 || a13 != 2 )
        {
          if ( a13 == 2 )
          {
            v33 = 4;
            v36 = 1;
          }
        }
        else
        {
          v33 = 2;
          v34 = 4;
          v35 = 3;
          v36 = 1;
        }
      }
      else
      {
        v33 = 4;
        v36 = 1;
      }
      break;
  }
  for ( n = 0; n < 5; ++n )
  {
    v28[n] = *((_BYTE *)gpMonGroup + n);
    v26[n] = *(_WORD *)((char *)gpMonGroup + 2 * n + 5);
  }
  for ( ii = 0; ii < 5; ++ii )
  {
    *((_BYTE *)gpMonGroup + ii) = LOBYTE(v28[*(&v32 + ii)]);
    *(_WORD *)((char *)gpMonGroup + 2 * ii + 5) = v26[*(&v32 + ii)];
  }
  if ( a8 )
    v27 = advManager::DoCombat(this, __PAIR__(a10, a9), 0, gpMonGroup, 0, (int)a2, &a2->army, a6, a7, a9 + a10, 1);
  else
    v27 = advManager::DoCombat(this, __PAIR__(a10, a9), (int)a2, &a2->army, 0, 0, gpMonGroup, a6, a7, a9 + a10, 1);
  advManager::MobilizeCurrHero(this, 0);
  return v27;
}
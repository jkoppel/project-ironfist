void __stdcall sub_4B3FE0(int a1, int a2, int a3, int a4)
{
  double v4; // st7@32
  float v5; // [sp+30h] [bp-44h]@33
  int this; // [sp+3Ch] [bp-38h]@9
  signed int v7; // [sp+40h] [bp-34h]@36
  PRIMARY_SKILL skill; // [sp+44h] [bp-30h]@11
  signed int skilla; // [sp+44h] [bp-30h]@17
  signed int skillb; // [sp+44h] [bp-30h]@37
  int v11; // [sp+48h] [bp-2Ch]@26
  signed int i; // [sp+4Ch] [bp-28h]@6
  float v13; // [sp+50h] [bp-24h]@32
  int v14; // [sp+54h] [bp-20h]@11
  int v15; // [sp+58h] [bp-1Ch]@25
  int v16; // [sp+5Ch] [bp-18h]@39
  float v17; // [sp+60h] [bp-14h]@25
  int v18; // [sp+64h] [bp-10h]@26
  int v19; // [sp+68h] [bp-Ch]@32
  int v20; // [sp+6Ch] [bp-8h]@32
  float v21; // [sp+70h] [bp-4h]@35

  *(_DWORD *)a4 = 0;
  if ( !a3 || *(_BYTE *)(a1 + 2) == dword_530734 || *(_BYTE *)(a2 + 2) == dword_530734 )
  {
    if ( !a3 )
    {
      *(_WORD *)(a1 + 4) = dword_532C54;
      *(_BYTE *)(a1 + 6) = *(_BYTE *)(a2 + 2);
      *(_WORD *)(a2 + 4) = dword_532C54;
      *(_BYTE *)(a2 + 6) = *(_BYTE *)(a1 + 2);
    }
    for ( i = 0; i < 2; ++i )
    {
      if ( i )
        this = a2;
      else
        this = a1;
      *(&v14 + i) = 0;
      for ( skill = 0; (signed int)skill < 4; ++skill )
      {
        if ( (signed int)skill < 2 || Hero::hasArtifact((Hero *)this, ARTIFACT_MAGIC_BOOK) )
          *(&v14 + i) += 800 * Hero::getPrimarySkill((Hero *)this, skill);
      }
      for ( skilla = 0; skilla < 14; ++skilla )
      {
        if ( skilla != 13 && *(_BYTE *)(skilla + this + 116) )
          *(&v14 + i) += *(&dword_4F1F3C[3 * skilla] + *(_BYTE *)(this + skilla + 116));
      }
    }
    v17 = (double)v14 / (double)(v14 + v15);
    if ( v15 >= v14 )
    {
      v18 = a2;
      v11 = a1;
      v17 = 1.0 - v17;
    }
    else
    {
      v18 = a1;
      v11 = a2;
    }
    if ( a3 && *(_BYTE *)(v11 + 2) == dword_530734 && v17 < 0.6 )
      v11 = v18;
    v19 = getArmyStrength((ArmyInfo *)(v18 + 101), 0, 0, 0, 0, 0);
    v20 = getArmyStrength((ArmyInfo *)(v11 + 101), 0, 0, 0, 0, 0);
    v4 = (double)v19 / (double)(v20 + v19);
    v13 = v4;
    if ( v4 > 0.69999999 )
      v5 = v13 - 0.69999999;
    else
      v5 = 0.69999999 - v13;
    v21 = v5;
    if ( v5 >= 0.15 )
    {
      v7 = (signed __int64)((double)(v20 + v19) * v21 * *(float *)&curPlayer->_4[100]);
      if ( a3 )
      {
        for ( skillb = 0; skillb < 14; ++skillb )
        {
          v16 = *(_BYTE *)(skillb + v11 + 213);
          if ( v16 != -1 && v16 != 81 )
            v7 += dword_4F2050[v16];
        }
      }
      else
      {
        sub_48F450(v11, v18);
        if ( v13 <= 0.69999999 )
          sub_4B4C50(v11 + 101, (void *)(v18 + 101), 1, 1, v20, v19, (signed __int64)((double)(v20 + v19) * v21));
        else
          sub_4B4C50(v18 + 101, (void *)(v11 + 101), 1, 1, v19, v20, (signed __int64)((double)(v20 + v19) * v21));
        sub_4AC280();
      }
      *(_DWORD *)a4 = (signed __int64)((double)v7 * 0.1);
    }
  }
}

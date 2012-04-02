int __stdcall sub_4B8F20(int a1, int a2)
{
  int result; // eax@2
  char v3; // [sp+1Ch] [bp-38h]@16
  char v4; // [sp+20h] [bp-34h]@16
  char v5; // [sp+24h] [bp-30h]@16
  char v6; // [sp+28h] [bp-2Ch]@16
  int v7; // [sp+2Ch] [bp-28h]@3
  int i; // [sp+30h] [bp-24h]@8
  float v9; // [sp+34h] [bp-20h]@16
  int v10; // [sp+38h] [bp-1Ch]@3
  int v11; // [sp+40h] [bp-14h]@16
  int v12; // [sp+44h] [bp-10h]@7
  int v13; // [sp+4Ch] [bp-8h]@16

  if ( Hero::numArtifacts(dword_51D5BC) == 14 )
  {
    result = 0;
  }
  else
  {
    v10 = 0;
    v7 = dword_4F2050[a1];
    if ( a1 == 86 )
    {
      if ( Hero::hasSpell(dword_51D5BC, (Spell)a2) )
        result = v7;
      else
        result = v7 + *(_WORD *)&spell_table[a2].appearingChance;
    }
    else
    {
      v12 = v7;
      if ( BYTE1(a2) & 1 )
      {
        for ( i = 0; i < 5; ++i )
        {
          *((_BYTE *)dword_5247BC + i) = a2;
          if ( *((_BYTE *)dword_5247BC + i) == 57 )
          {
            *(_WORD *)((char *)dword_5247BC + 2 * i + 5) = 10;
          }
          else
          {
            if ( i )
              *(_WORD *)((char *)dword_5247BC + 2 * i + 5) = 0;
            else
              *(_WORD *)((char *)dword_5247BC + 5) = 1;
          }
        }
        sub_4AF410(
          (int)&dword_51D5BC->army,
          (int)dword_51D5BC,
          (unsigned int)dword_5247BC,
          0,
          0,
          0,
          -1,
          (int)&v9,
          (int)&v6,
          (int *)&v5,
          (int *)&v4,
          (int *)&v3,
          &v13);
        v11 = (signed __int64)((double)dword_4F2050[a1] * v9 + (double)v13);
        if ( v11 < 0 )
          v11 = 0;
        v10 = v11;
      }
      else
      {
        switch ( a2 & 0xF )
        {
          case 1:
            v10 = v12;
            break;
          case 4:
            if ( dword_51D5BC->secondarySkillLevel[7] )
              v10 = v12;
            else
              v10 = 0;
            break;
          case 5:
            if ( dword_51D5BC->secondarySkillLevel[6] )
              v10 = v12;
            else
              v10 = 0;
            break;
          case 3:
            v10 = sub_4B5310(a1, 2000, 0, 0);
            break;
          case 6:
            v10 = sub_4B5310(a1, 2500, (a2 & 0xF0u) >> 4, 3);
            break;
          case 7:
            v10 = sub_4B5310(a1, 3000, (a2 & 0xF0u) >> 4, 5);
            break;
          case 2:
            break;
        }
      }
      result = v10;
    }
  }
  return result;
}

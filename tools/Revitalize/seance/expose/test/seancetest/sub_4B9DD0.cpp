int __stdcall sub_4B9DD0(int a1, int a2, int a3, int a4, int a5)
{
  __int64 v5; // ST08_8@25
  float v7; // [sp+2Ch] [bp-28h]@31
  int v8; // [sp+30h] [bp-24h]@24
  char v9; // [sp+34h] [bp-20h]@25
  char v10; // [sp+38h] [bp-1Ch]@25
  char v11; // [sp+3Ch] [bp-18h]@25
  char v12; // [sp+40h] [bp-14h]@25
  float v13; // [sp+44h] [bp-10h]@25
  int v14; // [sp+48h] [bp-Ch]@1
  Castle *this; // [sp+4Ch] [bp-8h]@1
  int v16; // [sp+50h] [bp-4h]@25

  v14 = 0;
  this = &gameObject->castles[a1];
  if ( gameObject->_7[a1] == dword_51D5BC->probablyOwnerIdx )
  {
    if ( this->visitingHeroIdx == -1 )
    {
      v14 = 0;
      if ( dword_532C54 - *(_WORD *)&dword_51D5BC->_2[3] >= 4 || dword_51D5BC->_2[5] != this->idx )
      {
        sub_4B43E0((int)dword_51D5BC, (signed int)this, 1, (int)&v14);
        v14 = (signed __int64)((double)v14 * *(float *)&dword_5304E8[dword_51D5BC->field_2]);
      }
    }
    else
    {
      if ( a4 )
        v14 = -500;
      else
        v14 = 0;
    }
    dword_532CD4 = 0;
  }
  else
  {
    if ( sub_4B8CB0(gameObject->_7[a1]) )
    {
      if ( a4 )
        v14 = -1500;
      else
        v14 = 0;
    }
    else
    {
      if ( !*(_DWORD *)&dword_52478C || gameObject->_7[a1] < 0 || dword_524810[gameObject->_7[a1]] )
      {
        if ( gameObject->difficulty >= 3
          || 40 - 8 * gameObject->difficulty <= dword_532C54
          || (unsigned __int8)(*(&tileExplored[a2] + a3 * mapWidth) & byte_532C5C) )
        {
          v8 = sub_4B2650((int)this);
          if ( gameObject->castles[a1].visitingHeroIdx == -1 )
          {
            if ( Castle::hasGarrison(this) )
            {
              sub_4AF410(
                (int)&dword_51D5BC->army,
                (int)dword_51D5BC,
                (unsigned int)&this->garrison,
                0,
                1,
                a1,
                this->ownerIdx,
                (int)&v13,
                (int)&v12,
                (int *)&v11,
                (int *)&v10,
                (int *)&v9,
                &v16);
            }
            else
            {
              v13 = 1.0;
              v16 = 0;
            }
          }
          else
          {
            HIDWORD(v5) = (char *)gameObject + 250 * this->visitingHeroIdx + 10180;
            LODWORD(v5) = (char *)gameObject + 250 * this->visitingHeroIdx + 10281;
            sub_4AF410(
              (int)&dword_51D5BC->army,
              (int)dword_51D5BC,
              v5,
              (int)&this->garrison,
              1,
              a1,
              this->ownerIdx,
              (int)&v13,
              (int)&v12,
              (int *)&v11,
              (int *)&v10,
              (int *)&v9,
              &v16);
          }
          *(_DWORD *)a5 = (signed __int64)(v13 * 100.0);
          if ( this->ownerIdx >= 0 )
          {
            if ( dword_524810[this->ownerIdx] )
              v7 = *(float *)&dword_51D5C0;
            else
              v7 = *(float *)&dword_51D5C4;
            v8 = (signed __int64)(((double)(5 - (signed int)gameObject->numPlayers) * 0.25 + 0.9) * v7 * (double)v8);
          }
          v14 = (signed __int64)((double)v8 * v13 + (double)v16);
          if ( gameObject->_7[a1] != -1 )
            dword_532CD0 = 0;
        }
        else
        {
          v14 = 0;
        }
      }
      else
      {
        v14 = 0;
      }
    }
  }
  if ( this->ownerIdx != -1 && dword_524810[this->ownerIdx] && v14 > 200 )
  {
    if ( curPlayer->personality )
      v14 = (signed __int64)((double)v14 * 1.3);
    else
      v14 = (signed __int64)((double)v14 * 1.6);
  }
  return v14;
}

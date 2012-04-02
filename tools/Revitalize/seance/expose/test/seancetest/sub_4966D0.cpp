void __thiscall sub_4966D0(Hero *this)
{
  Castle *v1; // eax@4
  Castle *v2; // eax@6
  Castle *v3; // eax@10
  Castle *v4; // eax@12
  char *v5; // ST0C_4@59
  signed int v6; // eax@59
  signed int v7; // [sp+Ch] [bp-10h]@1
  int a2; // [sp+14h] [bp-8h]@51
  int v9; // [sp+18h] [bp-4h]@20

  v7 = *(_DWORD *)&this->_2[4];
  if ( v7 > 84 )
  {
    if ( v7 > 106 )
    {
      if ( v7 > 205 )
      {
        if ( v7 > 212 )
        {
          if ( v7 > 30720 )
          {
            if ( v7 != 30723 )
              goto LABEL_49;
            sprintf(globBuf, off_4F63B8, viewedHero->name, (&off_4F5AF8)[4 * viewedHero->factionID]);
          }
          else
          {
            if ( v7 == 30720 )
            {
              strcpy(globBuf, off_4F63BC);
            }
            else
            {
              if ( v7 == 214 )
              {
                sprintf(globBuf, off_4F63D4);
              }
              else
              {
                if ( v7 != 216 )
                  goto LABEL_49;
                sprintf(globBuf, off_4F63D8);
              }
            }
          }
          goto LABEL_87;
        }
        if ( v7 >= 211 )
        {
          sprintf(globBuf, off_4F63D0);
          goto LABEL_87;
        }
        if ( v7 >= 206 && v7 <= 207 )
        {
          sprintf(globBuf, off_4F639C);
          goto LABEL_87;
        }
      }
      else
      {
        if ( v7 >= 203 )
        {
          v3 = sub_498B70(viewedHero);
          if ( computeLuck(viewedHero, 0, v3) <= 0 )
          {
            v4 = sub_498B70(viewedHero);
            if ( computeLuck(viewedHero, 0, v4) )
              sprintf(globBuf, off_4F6398);
            else
              sprintf(globBuf, off_4F6394);
          }
          else
          {
            sprintf(globBuf, off_4F6390);
          }
          goto LABEL_87;
        }
        if ( v7 >= 200 && v7 <= 202 )
        {
          v1 = sub_498B70(viewedHero);
          if ( ArmyInfo::computeMorale(&viewedHero->army, viewedHero, v1, 0) <= 0 )
          {
            v2 = sub_498B70(viewedHero);
            if ( ArmyInfo::computeMorale(&viewedHero->army, viewedHero, v2, 0) )
              sprintf(globBuf, off_4F638C);
            else
              sprintf(globBuf, off_4F6388);
          }
          else
          {
            sprintf(globBuf, off_4F6384);
          }
          goto LABEL_87;
        }
      }
LABEL_49:
      if ( *(_DWORD *)&this->_2[4] < 400 || *(_DWORD *)&this->_2[4] >= 408 )
      {
        if ( *(_DWORD *)&this->_2[4] < 408 || *(_DWORD *)&this->_2[4] >= 416 )
        {
          if ( *(_DWORD *)&this->_2[4] < 416 || *(_DWORD *)&this->_2[4] >= 424 )
            goto LABEL_60;
          a2 = *(_DWORD *)&this->_2[4] - 416;
        }
        else
        {
          a2 = *(_DWORD *)&this->_2[4] - 408;
        }
      }
      else
      {
        a2 = *(_DWORD *)&this->_2[4] - 400;
      }
      if ( viewedHero->numSecSkillsKnown > a2 )
      {
        v5 = secondary_skill_names[sub_498B10(viewedHero, a2)];
        v6 = sub_498B10(viewedHero, a2);
        sprintf(globBuf, off_4F63CC, secondarySkillLevels[viewedHero->secondarySkillLevel[v6]], v5);
        goto LABEL_87;
      }
LABEL_60:
      strcpy(globBuf, off_4F63C0);
      goto LABEL_87;
    }
    if ( v7 >= 102 )
    {
      v9 = *(_DWORD *)&this->_2[4] - 102;
      if ( dword_523428 == -1 )
      {
        if ( viewedHero->army.creatureTypes[v9] == -1 )
          strcpy(globBuf, off_4F63A4);
        else
          sprintf(globBuf, off_4F63A0, creatureSingularNames[viewedHero->army.creatureTypes[v9]]);
      }
      else
      {
        if ( dword_523428 == v9 )
        {
          sprintf(globBuf, off_4F63A0, creatureSingularNames[viewedHero->army.creatureTypes[v9]]);
        }
        else
        {
          if ( townManager->field_15A )
          {
            if ( viewedHero->army.creatureTypes[v9] == -1 )
              strcpy(globBuf, off_4F63A4);
            else
              sprintf(globBuf, off_4F63A0, creatureSingularNames[viewedHero->army.creatureTypes[v9]]);
          }
          else
          {
            if ( viewedHero->army.creatureTypes[v9] == -1 )
            {
              if ( this->name[2] & 3 )
                sprintf(globBuf, off_4F63C8, creaturePluralNames[viewedHero->army.creatureTypes[dword_523428]]);
              else
                sprintf(globBuf, off_4F63A8, creatureSingularNames[viewedHero->army.creatureTypes[dword_523428]]);
            }
            else
            {
              if ( viewedHero->army.creatureTypes[v9] == viewedHero->army.creatureTypes[dword_523428] )
                sprintf(globBuf, off_4F63C4, creaturePluralNames[viewedHero->army.creatureTypes[v9]]);
              else
                sprintf(
                  globBuf,
                  off_4F63AC,
                  creatureSingularNames[viewedHero->army.creatureTypes[dword_523428]],
                  creatureSingularNames[viewedHero->army.creatureTypes[v9]]);
            }
          }
        }
      }
    }
    else
    {
      if ( v7 != 85 )
        goto LABEL_49;
      sprintf(globBuf, off_4F6380);
    }
  }
  else
  {
    if ( v7 >= 81 )
    {
      sprintf(globBuf, off_4F637C, off_4F5994[*(_DWORD *)&this->_2[4]]);
    }
    else
    {
      if ( v7 < 20 || v7 > 33 )
        goto LABEL_49;
      if ( viewedHero->spellsLearned[*(_DWORD *)&this->_2[4] + 45] == -1 )
      {
        sprintf(globBuf, off_4F63A4);
      }
      else
      {
        if ( viewedHero->spellsLearned[*(_DWORD *)&this->_2[4] + 45] == 81 )
          strcpy(globBuf, off_4F63B0);
        else
          sprintf(globBuf, off_4F63B4, artifactNames[viewedHero->spellsLearned[*(_DWORD *)&this->_2[4] + 45]]);
      }
    }
  }
LABEL_87:
  sub_495160(globBuf);
}

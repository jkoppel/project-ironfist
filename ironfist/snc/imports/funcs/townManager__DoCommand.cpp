{
  __int16 v2; // ST4C_2@23
  int result; // eax@27
  int thisa; // [sp+10h] [bp-14h]@1
  int a7; // [sp+14h] [bp-10h]@9
  hero *hro; // [sp+18h] [bp-Ch]@4
  int i; // [sp+20h] [bp-4h]@16

  thisa = (int)this;
  switch ( a2 )
  {
    case 0:
      this->field_DE = this->field_D6;
      this->field_E2 = this->field_DA;
      this->field_DE->drawBorder = this->field_E2;
      strip::Draw((int)this->field_DE);
      break;
    case 1:
      if ( this->field_D6 == this->visitingArmyDisplay )
        hro = &gpGame->heroes[this->castle->visitingHeroIdx];
      else
        hro = 0;
      a7 = this->field_15A == 1
        || this->field_D6 == this->visitingArmyDisplay && armyGroup::GetNumArmies(this->field_D6->army) == 1;
      game::ViewArmy(
        gpGame,
        119,
        20,
        (CREATURES)*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(thisa + 214) + 128) + *(_DWORD *)(thisa + 218)),
        *(_WORD *)(*(_DWORD *)(*(_DWORD *)(thisa + 214) + 128) + 2 * *(_DWORD *)(thisa + 218) + 5),
        *(_DWORD *)(thisa + 54),
        a7,
        1u,
        0,
        hro,
        0,
        *(armyGroup **)(*(_DWORD *)(thisa + 214) + 128),
        *(_DWORD *)(thisa + 218));
      bankBox::Update(*(bankBox **)(thisa + 238), 1);
      if ( gpWindowManager->buttonPressedCode == 30722 )
      {
        *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(thisa + 214) + 128) + *(_DWORD *)(thisa + 218)) = -1;
        *(_WORD *)(*(_DWORD *)(*(_DWORD *)(thisa + 214) + 128) + 2 * *(_DWORD *)(thisa + 218) + 5) = 0;
      }
      townManager::ResetStrips(thisa);
      break;
    case 2:
      if ( this->field_E6 != this->field_DE
        && this->field_DE->army->creatureTypes[this->field_E2] != this->field_E6->army->creatureTypes[this->field_EA] )
      {
        for ( i = 0;
              i < 5 && this->field_DE->army->creatureTypes[this->field_E2] != this->field_E6->army->creatureTypes[i];
              ++i )
          ;
        if ( i < 5 )
          this->field_EA = i;
      }
      this->field_E6->army->quantities[this->field_EA] += this->field_DE->army->quantities[this->field_E2];
      this->field_DE->army->creatureTypes[this->field_E2] = -1;
      this->field_DE->army->quantities[this->field_E2] = 0;
      townManager::ResetStrips((int)this);
      break;
    case 3:
      v2 = this->field_E6->army->quantities[this->field_EA];
      this->field_E6->army->quantities[this->field_EA] = this->field_DE->army->quantities[this->field_E2];
      this->field_DE->army->quantities[this->field_E2] = v2;
      LOBYTE(v2) = this->field_E6->army->creatureTypes[this->field_EA];
      this->field_E6->army->creatureTypes[this->field_EA] = this->field_DE->army->creatureTypes[this->field_E2];
      this->field_DE->army->creatureTypes[this->field_E2] = v2;
      townManager::ResetStrips((int)this);
      break;
    case 4:
      HeroView(this->castle->visitingHeroIdx, 1, 0);
      townManager::RedrawTownScreen((townManager *)thisa);
      heroWindowManager::FadeScreen(gpWindowManager, 0, 8, 0);
      break;
    case 5:
      townManager::SplitArmy(this);
      townManager::ResetStrips(thisa);
      break;
    default:
      break;
  }
  result = thisa;
  *(_DWORD *)(thisa + 322) = -1;
  return result;
}
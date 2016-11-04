{
  __int16 v2; // ST4C_2@23
  int result; // eax@27
  int thisa; // [sp+10h] [bp-14h]@1
  int a7; // [sp+14h] [bp-10h]@9
  Hero *a10; // [sp+18h] [bp-Ch]@4
  signed int i; // [sp+20h] [bp-4h]@16

  thisa = this;
  switch ( a2 )
  {
    case 0:
      *(_DWORD *)(this + 222) = *(_DWORD *)(this + 214);
      *(_DWORD *)(this + 226) = *(_DWORD *)(this + 218);
      *(_DWORD *)(*(_DWORD *)(this + 222) + 40) = *(_DWORD *)(this + 226);
      sub_409210(*(_DWORD *)(this + 222));
      break;
    case 1:
      if ( *(_DWORD *)(this + 214) == *(_DWORD *)(this + 210) )
        a10 = &gameObject->heroes[*(_BYTE *)(*(_DWORD *)(this + 54) + 23)];
      else
        a10 = 0;
      a7 = *(_DWORD *)(this + 346) == 1
        || *(_DWORD *)(this + 214) == *(_DWORD *)(this + 210)
        && ArmyInfo::getNumStacks(*(ArmyInfo **)(*(_DWORD *)(this + 214) + 128)) == 1;
      GameInfo::showStackInfo(
        gameObject,
        119,
        20,
        (CREATURES)*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(thisa + 214) + 128) + *(_DWORD *)(thisa + 218)),
        *(_WORD *)(*(_DWORD *)(*(_DWORD *)(thisa + 214) + 128) + 2 * *(_DWORD *)(thisa + 218) + 5),
        *(_DWORD *)(thisa + 54),
        a7,
        1u,
        0,
        a10,
        0,
        *(ArmyInfo **)(*(_DWORD *)(thisa + 214) + 128),
        *(_DWORD *)(thisa + 218));
      Bankbox::refreshCaptions(*(Bankbox **)(thisa + 238), 1);
      if ( HeroWindowManager::instance->buttonPressedCode == 30722 )
      {
        *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(thisa + 214) + 128) + *(_DWORD *)(thisa + 218)) = -1;
        *(_WORD *)(*(_DWORD *)(*(_DWORD *)(thisa + 214) + 128) + 2 * *(_DWORD *)(thisa + 218) + 5) = 0;
      }
      sub_4148D0(thisa);
      break;
    case 2:
      if ( *(_DWORD *)(this + 230) != *(_DWORD *)(this + 222)
        && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 222) + 128) + *(_DWORD *)(this + 226)) != *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 230) + 128) + *(_DWORD *)(this + 234)) )
      {
        for ( i = 0;
              i < 5
           && *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 222) + 128) + *(_DWORD *)(this + 226)) != *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 230) + 128) + i);
              ++i )
          ;
        if ( i < 5 )
          *(_DWORD *)(this + 234) = i;
      }
      *(_WORD *)(*(_DWORD *)(*(_DWORD *)(this + 230) + 128) + 2 * *(_DWORD *)(this + 234) + 5) += *(_WORD *)(*(_DWORD *)(*(_DWORD *)(this + 222) + 128) + 2 * *(_DWORD *)(this + 226) + 5);
      *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 222) + 128) + *(_DWORD *)(this + 226)) = -1;
      *(_WORD *)(*(_DWORD *)(*(_DWORD *)(this + 222) + 128) + 2 * *(_DWORD *)(this + 226) + 5) = 0;
      sub_4148D0(this);
      break;
    case 3:
      v2 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)(this + 230) + 128) + 2 * *(_DWORD *)(this + 234) + 5);
      *(_WORD *)(*(_DWORD *)(*(_DWORD *)(this + 230) + 128) + 2 * *(_DWORD *)(this + 234) + 5) = *(_WORD *)(*(_DWORD *)(*(_DWORD *)(this + 222) + 128) + 2 * *(_DWORD *)(this + 226) + 5);
      *(_WORD *)(*(_DWORD *)(*(_DWORD *)(this + 222) + 128) + 2 * *(_DWORD *)(this + 226) + 5) = v2;
      LOBYTE(v2) = *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 230) + 128) + *(_DWORD *)(this + 234));
      *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 230) + 128) + *(_DWORD *)(this + 234)) = *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 222) + 128)
                                                                                                  + *(_DWORD *)(this + 226));
      *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 222) + 128) + *(_DWORD *)(this + 226)) = v2;
      sub_4148D0(this);
      break;
    case 4:
      sub_497970(*(_BYTE *)(*(_DWORD *)(this + 54) + 23), 1, 0);
      TownManager::paint((TownManager *)thisa);
      sub_4C7C60(HeroWindowManager::instance, 0, 8, 0);
      break;
    case 5:
      sub_414520((void *)this);
      sub_4148D0(thisa);
      break;
    default:
      break;
  }
  result = thisa;
  *(_DWORD *)(thisa + 322) = -1;
  return result;
}

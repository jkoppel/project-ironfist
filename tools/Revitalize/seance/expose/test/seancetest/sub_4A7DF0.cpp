HeroWindowManager *__thiscall sub_4A7DF0(int this, int a2, int a3)
{
  HeroWindowManager *result; // eax@48

  if ( a2 )
  {
    switch ( a3 )
    {
      case 0:
        sub_45A2A0(19);
        break;
      case 1:
        sub_45A2A0(20);
        break;
      case 2:
        sub_45A2A0(21);
        break;
      case 3:
        sub_45A2A0(22);
        break;
      case 4:
        if ( *(_BYTE *)(this + 12 * *(_BYTE *)(this + 3) + 8) )
          sub_45A2A0(24);
        else
          sub_45A2A0(23);
        sub_45A2A0(25);
        break;
      case 5:
        if ( *(_BYTE *)(this + 3) == 1 )
          sub_45A2A0(26);
        else
          sub_45A2A0(27);
        break;
      case 6:
        sub_45A2A0(28);
        break;
      case 7:
        if ( *(_BYTE *)(this + 12 * *(_BYTE *)(this + 2) + 11) )
          sub_45A2A0(30);
        else
          sub_45A2A0(29);
        break;
      case 8:
        sub_45A2A0(31);
        break;
      case 9:
        sub_45A2A0(32);
        break;
      case 10:
        sub_45A2A0(33);
        break;
      case 11:
      case 12:
        if ( *(_BYTE *)(this + 12 * *(_BYTE *)(this + 3) + 8) )
          sub_45A2A0(24);
        else
          sub_45A2A0(23);
        sub_45A2A0(25);
        break;
      default:
        break;
    }
  }
  else
  {
    switch ( a3 )
    {
      case 0:
        sub_45A2A0(5);
        break;
      case 1:
        sub_45A2A0(6);
        break;
      case 2:
        sub_45A2A0(7);
        break;
      case 3:
        if ( *(_BYTE *)(this + 12 * *(_BYTE *)(this + 3) + 7) )
          sub_45A2A0(9);
        else
          sub_45A2A0(8);
        break;
      case 4:
        sub_45A2A0(10);
        break;
      case 5:
        if ( *(_BYTE *)(this + 3) )
          sub_45A2A0(12);
        else
          sub_45A2A0(11);
        break;
      case 6:
        sub_45A2A0(13);
        break;
      case 7:
        sub_45A2A0(14);
        break;
      case 8:
        sub_45A2A0(15);
        break;
      case 9:
        sub_45A2A0(16);
        break;
      case 11:
      case 12:
        sub_45A2A0(10);
        break;
      default:
        break;
    }
  }
  result = HeroWindowManager::instance;
  HeroWindowManager::instance->field_56 = 1;
  return result;
}

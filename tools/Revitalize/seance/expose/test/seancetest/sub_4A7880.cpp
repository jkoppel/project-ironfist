signed int __thiscall sub_4A7880(GameInfo *this)
{
  int v2; // [sp+Ch] [bp-18h]@48
  signed int i; // [sp+1Ch] [bp-8h]@39
  signed int j; // [sp+20h] [bp-4h]@41

  memset(&this->_1[157], 0, 0x18u);
  if ( this->field_2 )
  {
    switch ( this->field_4 + 1 )
    {
      case 0:
        sub_45A2A0(19);
        this->_1[169] = 1;
        break;
      case 1:
        sub_45A2A0(20);
        this->_1[170] = 1;
        break;
      case 2:
        sub_45A2A0(21);
        this->_1[171] = 1;
        this->_1[172] = 1;
        break;
      case 3:
        sub_45A2A0(23);
        sub_45A2A0(25);
        this->_1[173] = 1;
        this->_1[180] = 1;
        this->_1[127] = 1;
        break;
      case 4:
        sub_45A2A0(24);
        sub_45A2A0(25);
        this->_1[173] = 1;
        this->_1[180] = 1;
        this->_1[128] = 1;
        this->_1[129] = 1;
        break;
      case 5:
        if ( this->field_3 == 1 )
          sub_45A2A0(26);
        else
          sub_45A2A0(27);
        this->_1[174] = 1;
        break;
      case 6:
        sub_45A2A0(28);
        this->_1[175] = 1;
        this->_1[176] = 1;
        break;
      case 7:
        sub_45A2A0(30);
        this->_1[176] = 1;
        this->_1[130] = 1;
        break;
      case 8:
        sub_45A2A0(31);
        this->_1[177] = 1;
        this->_1[178] = 1;
        break;
      case 9:
        sub_45A2A0(33);
        this->_1[179] = 1;
        this->_1[131] = 1;
        break;
      case 10:
        sub_45A2A0(33);
        this->_1[179] = 1;
        this->_1[132] = 1;
        break;
      case 11:
        sub_45A2A0(34);
        this->_1[131] = 0;
        this->_1[132] = 0;
        break;
      default:
        break;
    }
  }
  else
  {
    switch ( this->field_4 + 1 )
    {
      case 0:
        sub_45A2A0(5);
        this->_1[157] = 1;
        break;
      case 1:
        sub_45A2A0(6);
        this->_1[158] = 1;
        break;
      case 2:
        sub_45A2A0(7);
        this->_1[159] = 1;
        this->_1[160] = 1;
        break;
      case 3:
        sub_45A2A0(9);
        this->_1[160] = 1;
        this->_1[121] = 1;
        break;
      case 4:
        sub_45A2A0(10);
        this->_1[161] = 1;
        this->_1[168] = 1;
        break;
      case 5:
        if ( this->field_3 )
          sub_45A2A0(12);
        else
          sub_45A2A0(11);
        this->_1[162] = 1;
        break;
      case 6:
        sub_45A2A0(13);
        this->_1[163] = 1;
        this->_1[164] = 1;
        this->_1[122] = 1;
        break;
      case 7:
        sub_45A2A0(15);
        this->_1[165] = 1;
        this->_1[124] = 1;
        break;
      case 8:
        sub_45A2A0(15);
        this->_1[165] = 1;
        this->_1[126] = 1;
        break;
      case 9:
        sub_45A2A0(16);
        this->_1[166] = 1;
        break;
      case 10:
        sub_45A2A0(18);
        break;
      default:
        break;
    }
  }
  if ( this->field_4 != 10 && (gameObject->field_4 != 9 || gameObject->field_2) )
  {
    this->field_4 = -1;
    for ( i = 0; i < 2; ++i )
    {
      for ( j = 0; j < 11; ++j )
      {
        if ( *(&this->_1[12 * i + 157] + j) )
        {
          *((_WORD *)&gameObject->_1[24 * i + 24] + j) = *(_WORD *)&this->_1[181];
          if ( this->field_4 == -1 )
          {
            this->field_2 = i;
            this->field_4 = j;
          }
        }
      }
    }
    sub_4A8140(gameObject, 0, 0);
    v2 = HeroWindowManager::instance->buttonPressedCode;
    if ( v2 == 30721 )
      return 0;
    if ( v2 == 30722 )
      return 1;
  }
  return 0;
}

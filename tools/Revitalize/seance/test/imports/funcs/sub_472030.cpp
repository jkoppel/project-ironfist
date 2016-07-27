{
  HeroWindowManager *result; // eax@7

  switch ( *(_DWORD *)this )
  {
    case 0:
      sub_4720C0((int)this);
      break;
    case 1:
      sub_4721C0((int)this);
      break;
    case 2:
      sub_4722A0((int)this);
      break;
    case 3:
      sub_472350((int)this);
      break;
    default:
      break;
  }
  result = HeroWindowManager::instance;
  HeroWindowManager::instance->field_56 = 1;
  return result;
}

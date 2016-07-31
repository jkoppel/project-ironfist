{
  int v6; // [sp+Ch] [bp-Ch]@1

  v6 = (unsigned __int8)((unsigned __int8)(*(_WORD *)(a3 + 4) >> 8) >> -5);
  switch ( v6 )
  {
    case 2:
      if ( !sub_48E820((AdvManager *)this, a2, 47, 25, a3, a5, 0, a5, -1, 0, 0, -1, 0, 0) )
      {
        showMessageWindowForEvent(-1, 1, a4, 6, 500, -1, 0, -1);
        grantResource((Hero *)a2, 6, 500);
        Hero::checkForLevelUp((Hero *)a2);
        return 1;
      }
      break;
    case 3:
      if ( !sub_48E820((AdvManager *)this, a2, 47, 50, a3, a5, 0, a5, -1, 0, 0, -1, 0, 0) )
      {
        showMessageWindowForEvent(-1, 1, a4, 6, 1000, -1, 0, -1);
        grantResource((Hero *)a2, 6, 1000);
        Hero::checkForLevelUp((Hero *)a2);
        return 1;
      }
      break;
    case 4:
      if ( !sub_48E820((AdvManager *)this, a2, 47, 100, a3, a5, 0, a5, -1, 0, 0, -1, 0, 0) )
      {
        showMessageWindowForEvent(-1, 1, a4, 6, 2000, -1, 0, -1);
        grantResource((Hero *)a2, 6, 2000);
        Hero::checkForLevelUp((Hero *)a2);
        return 1;
      }
      break;
    default:
      if ( !sub_48E820((AdvManager *)this, a2, 47, 200, a3, a5, 0, a5, -1, 0, 0, -1, 0, 0) )
      {
        showMessageWindowForEvent(-1, 1, a4, 6, 5000, -1, 0, -1);
        grantResource((Hero *)a2, 6, 5000);
        Hero::checkForLevelUp((Hero *)a2);
        return 1;
      }
      break;
  }
  return 0;
}

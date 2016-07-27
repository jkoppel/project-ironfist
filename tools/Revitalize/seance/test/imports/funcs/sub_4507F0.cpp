{
  Player *result; // eax@1

  sub_450880((AdvManager *)this);
  result = curPlayer;
  curPlayer->_1[0] = -1;
  return result;
}

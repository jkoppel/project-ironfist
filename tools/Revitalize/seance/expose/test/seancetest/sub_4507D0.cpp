Player *__cdecl sub_4507D0()
{
  Player *result; // eax@1

  result = curPlayer;
  LOBYTE(curPlayer->field_45) = -1;
  return result;
}

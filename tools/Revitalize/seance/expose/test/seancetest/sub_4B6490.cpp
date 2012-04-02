Player *__cdecl sub_4B6490()
{
  Player *result; // eax@1
  signed int v1; // [sp+10h] [bp-4h]@1

  result = (Player *)curPlayer->numHeroes;
  v1 = curPlayer->numHeroes;
  if ( v1 < 4 )
  {
    result = curPlayer;
    if ( curPlayer->resources[6] >= 2500 )
    {
      if ( !dword_532C58 )
        ++v1;
    }
  }
  LODWORD(qword_50EAA8) = qword_50EAA8 + 1;
  if ( v1 == 1 )
  {
    LODWORD(qword_50EAA8) = qword_50EAA8 + 1;
    LODWORD(qword_50EAA8) = qword_50EAA8 + 1;
  }
  if ( v1 == 2 && (_DWORD)qword_50EAA8 != 1 )
    LODWORD(qword_50EAA8) = qword_50EAA8 + 1;
  if ( v1 == 3 && ((_DWORD)qword_50EAA8 == 3 || (_DWORD)qword_50EAA8 == 6) )
    LODWORD(qword_50EAA8) = qword_50EAA8 + 1;
  if ( (signed int)qword_50EAA8 > 9 )
    LODWORD(qword_50EAA8) = 9;
  return result;
}

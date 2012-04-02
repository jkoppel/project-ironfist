Castle *__thiscall sub_498B70(Hero *this)
{
  Castle *result; // eax@2

  if ( *(_WORD *)&this->_4[12] == 163 )
    result = &gameObject->castles[*(_WORD *)&this->_4[14]];
  else
    result = 0;
  return result;
}

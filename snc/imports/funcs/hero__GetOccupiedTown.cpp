{
  town *result; // eax@2

  if ( this->occupiedObjType == 163 )
    result = &gpGame->castles[this->occupiedObjVal];
  else
    result = 0;
  return result;
}
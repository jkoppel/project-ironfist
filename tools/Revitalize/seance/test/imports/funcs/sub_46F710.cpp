{
  void **result; // eax@5

  if ( *this )
    operator delete(*this);
  *this = 0;
  if ( this[1] )
    operator delete(this[1]);
  this[1] = 0;
  result = this;
  this[4] = 0;
  return result;
}

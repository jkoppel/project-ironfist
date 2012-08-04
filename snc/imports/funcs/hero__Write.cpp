{
  signed int result; // eax@2

  if ( expansion )
    result = _write(fd, this, sizeof(hero));
  else
    result = _write(fd, this, offsetof(hero, scrollSpell));
  return result;
}
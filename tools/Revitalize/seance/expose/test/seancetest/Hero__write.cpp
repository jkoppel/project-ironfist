signed int __thiscall Hero::write(Hero *this, int fd, char expansion)
{
  signed int result; // eax@2

  if ( expansion )
    result = _write(fd, this, 250);
  else
    result = _write(fd, this, 236);
  return result;
}

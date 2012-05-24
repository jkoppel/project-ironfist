signed int __thiscall Hero::read(Hero *this, int fd, char expansion)
{
  signed int result; // eax@2

  if ( expansion )
    result = _read(fd, this, 250u);
  else
    result = _read(fd, this, 236u);
  return result;
}

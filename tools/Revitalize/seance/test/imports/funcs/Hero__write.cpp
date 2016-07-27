{
  int result; // eax@2

  if ( expansion )
    result = _write(fd, this, 250u);
  else
    result = _write(fd, this, 236u);
  return result;
}

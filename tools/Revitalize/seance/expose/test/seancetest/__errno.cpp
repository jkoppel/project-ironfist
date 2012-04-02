int *__cdecl _errno()
{
  return (int *)(_getptd() + 8);
}

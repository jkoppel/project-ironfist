unsigned __int32 *__cdecl __doserrno()
{
  return (unsigned __int32 *)(_getptd() + 12);
}

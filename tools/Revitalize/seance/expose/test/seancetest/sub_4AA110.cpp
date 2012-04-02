signed int __cdecl sub_4AA110()
{
  signed int result; // eax@2

  dword_51D4A8 = AIL_redbook_open(0);
  if ( dword_51D4A8 )
    result = 1;
  else
    result = 0;
  return result;
}

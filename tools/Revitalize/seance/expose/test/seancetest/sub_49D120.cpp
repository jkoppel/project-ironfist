signed int __cdecl sub_49D120()
{
  signed int result; // eax@2

  if ( graphicsLibraryToUse == 1 )
    result = sub_49C4F0();
  else
    result = sub_49ADD0();
  return result;
}

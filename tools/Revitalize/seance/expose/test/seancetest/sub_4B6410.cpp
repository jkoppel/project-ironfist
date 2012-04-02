signed int __stdcall sub_4B6410(void *a1, int a2, int a3, float a4)
{
  signed int result; // eax@2

  if ( a4 >= 0.99 )
  {
    if ( a2 )
      sub_48F630((int)advManager, a2);
    else
      ArmyInfo::randomlyKillCreatures((ArmyInfo *)a1, a4);
    result = 1;
  }
  else
  {
    ArmyInfo::randomlyKillCreatures((ArmyInfo *)a1, a4);
    result = 0;
  }
  return result;
}

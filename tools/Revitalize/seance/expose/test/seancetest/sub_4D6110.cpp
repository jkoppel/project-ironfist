bool __thiscall sub_4D6110(const char *this)
{
  bool result; // eax@2
  const char *v2; // [sp+Ch] [bp-8h]@1
  unsigned int v3; // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = strlen(this);
  if ( (signed int)v3 > 3 )
    result = v2[v3 - 3] == 46 && v2[v3 - 2] == 110 && v2[v3 - 1] == 119;
  else
    result = 0;
  return result;
}

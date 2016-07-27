{
  int result; // eax@8
  int v1; // [sp+Ch] [bp-Ch]@4
  int v2; // [sp+Ch] [bp-Ch]@10
  signed int v3; // [sp+10h] [bp-8h]@3

  if ( dword_4F7494 )
  {
    v3 = -1;
    if ( gameObject->couldBePlayerAlive[curPlayerIdx] )
    {
      v1 = (curPlayerIdx + 1) % 6;
      while ( v1 != curPlayerIdx )
      {
        if ( !gameObject->couldBePlayerAlive[v1] && dword_524810[v1] )
        {
          result = *(&byte_524758 + v1);
          dword_523ED4 = *(&byte_524758 + v1);
          return result;
        }
      }
    }
    v2 = (curPlayerIdx + 1) % 6;
    while ( v2 != curPlayerIdx )
    {
      v2 = (v2 + 1) % 6;
      if ( !gameObject->couldBePlayerAlive[v2] && dword_524810[v2] )
        v3 = v2;
    }
    result = *(&byte_524758 + v3);
    dword_523ED4 = *(&byte_524758 + v3);
  }
  else
  {
    dword_523ED4 = 1;
  }
  return result;
}

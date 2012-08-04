{
  int result; // eax@2
  float v3; // ST24_4@4
  int v4; // [sp+1Ch] [bp-10h]@1
  int v5; // [sp+24h] [bp-8h]@1
  int v6; // [sp+28h] [bp-4h]@1

  v5 = 0;
  v6 = 10 * a2 * hero::Stats((hero *)a1, PRIMARY_SKILL_KNOWLEDGE);
  v4 = v6 - *(_WORD *)a1;
  if ( v4 > 0 )
  {
    if ( v4 > 0 )
    {
      v3 = (double)v4 / (double)v6;
      v5 = (signed __int64)((double)(5 * v4) * v3);
    }
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}
{
  signed int result; // eax@6
  signed int v3; // [sp+10h] [bp-4h]@1

  v3 = philAI::MaxBuyableCreatures(a1);
  if ( v3 > 1 )
    v3 >>= 1;
  if ( a2 < v3 )
    v3 = a2;
  if ( v3 <= 1 )
    result = 0;
  else
    result = v3;
  return result;
}
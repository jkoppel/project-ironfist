{
  __int16 v1; // fps@1
  char v2; // c0@1
  float v4; // [sp+14h] [bp-4h]@1

  UNDEF(v1);
  v4 = 1.0 - philAI::TurnsToBuy(a1) * 0.15000001;
  if ( v2 )
    v4 = 0.0;
  return v4;
}
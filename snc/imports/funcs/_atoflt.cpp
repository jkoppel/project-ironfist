{
  int v2; // ecx@0
  int result; // eax@1
  int v4; // [sp+Ch] [bp-4h]@1

  v4 = v2;
  LOWORD(result) = com_snd(0, 1u, &v4, 0);
  return result;
}
bool __stdcall sub_4C0840(int a1, int a2)
{
  int v3; // [sp+10h] [bp-8h]@1
  int v4; // [sp+14h] [bp-4h]@1

  v4 = byte_4F1DC0[4 * a2];
  v3 = byte_4F1DC1[4 * a2];
  return (*(&byte_524758 + curPlayerIdx) || !*(_DWORD *)&blackoutComputer)
      && (sub_456B40(*(_DWORD *)(a1 + 25), *(_DWORD *)(a1 + 29), byte_5306F0)
       || sub_456B40(v4 + *(_DWORD *)(a1 + 25), v3 + *(_DWORD *)(a1 + 29), byte_5306F0));
}

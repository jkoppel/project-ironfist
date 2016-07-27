{
  int result; // eax@10
  int a3a; // [sp+28h] [bp-8h]@6
  int a2a; // [sp+2Ch] [bp-4h]@2

  if ( a2 )
  {
    a2a = *((_WORD *)this + 49 * *(_DWORD *)(a2 + 122) + 650) - (*(_DWORD *)(a2 + 134) < 1u ? 123 : 80);
    if ( a2a < 0 )
      a2a = 0;
    if ( a2a + 488 > 640 )
      a2a = 151;
    a3a = *((_WORD *)this + 49 * *(_DWORD *)(a2 + 122) + 651) - 164;
    if ( a3a < 0 )
      a3a = 0;
    if ( a3a + 229 > 460 )
      a3a = 230;
    result = GameInfo::showStackInfo(
               gameObject,
               a2a,
               a3a,
               *(CREATURES *)(a2 + 118),
               *(_DWORD *)(a2 + 150),
               *(_DWORD *)((char *)this + 4 * *(_DWORD *)(a2 + 230) + 12927),
               1,
               *(_DWORD *)(a2 + 134),
               a3,
               *(Hero **)((char *)this + 4 * *(_DWORD *)(a2 + 230) + 12935),
               a2,
               *(ArmyInfo **)((char *)this + 4 * *(_DWORD *)(a2 + 230) + 13201),
               0);
  }
  return result;
}

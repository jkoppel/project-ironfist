{
  char v0; // [sp+Ch] [bp-Ch]@3
  char v1; // [sp+Dh] [bp-Bh]@3
  char v2; // [sp+Eh] [bp-Ah]@3
  char v3; // [sp+Fh] [bp-9h]@3
  char v4; // [sp+10h] [bp-8h]@3
  int v5; // [sp+14h] [bp-4h]@4

  if ( dword_4F7498 && dword_4F7494 )
  {
    v0 = dword_523F14;
    v1 = dword_524730;
    v2 = dword_523ED4;
    v3 = 0;
    v4 = 0;
    if ( dword_523F14 )
      v5 = 0;
    else
      v5 = 1;
    debugLog("HRSE1");
    sub_46E1D0(&v0, v5, 7u, 31, 0, 0, 2);
    debugLog("HRSE2");
    sleep(500);
  }
}

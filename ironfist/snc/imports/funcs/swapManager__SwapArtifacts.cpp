{
  signed int v1; // eax@8
  char v2; // al@8
  int v3; // [sp+Ch] [bp-34h]@1
  int evt; // [sp+10h] [bp-30h]@3
  int v5; // [sp+14h] [bp-2Ch]@8
  int v6; // [sp+18h] [bp-28h]@8
  char *v7; // [sp+28h] [bp-18h]@8
  int i; // [sp+2Ch] [bp-14h]@3
  int j; // [sp+30h] [bp-10h]@5
  ARTIFACT a2; // [sp+34h] [bp-Ch]@1
  char v11; // [sp+38h] [bp-8h]@1
  ARTIFACT v12; // [sp+3Ch] [bp-4h]@1

  v3 = this;
  a2 = *(_BYTE *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 70) + 62) + *(_DWORD *)(this + 78) + 213);
  v12 = *(_BYTE *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 74) + 62) + *(_DWORD *)(this + 82) + 213);
  GiveTakeArtifactStat(*(hero **)(this + 4 * *(_DWORD *)(this + 70) + 62), a2, 1);
  GiveTakeArtifactStat(*(hero **)(v3 + 4 * *(_DWORD *)(v3 + 74) + 62), v12, 1);
  *(_BYTE *)(*(_DWORD *)(v3 + 4 * *(_DWORD *)(v3 + 70) + 62) + *(_DWORD *)(v3 + 78) + 213) = v12;
  *(_BYTE *)(*(_DWORD *)(v3 + 4 * *(_DWORD *)(v3 + 74) + 62) + *(_DWORD *)(v3 + 82) + 213) = a2;
  v11 = *(_BYTE *)(*(_DWORD *)(v3 + 4 * *(_DWORD *)(v3 + 70) + 62) + *(_DWORD *)(v3 + 78) + 236);
  *(_BYTE *)(*(_DWORD *)(v3 + 4 * *(_DWORD *)(v3 + 70) + 62) + *(_DWORD *)(v3 + 78) + 236) = *(_BYTE *)(*(_DWORD *)(v3 + 4 * *(_DWORD *)(v3 + 74) + 62) + *(_DWORD *)(v3 + 82) + 236);
  *(_BYTE *)(*(_DWORD *)(v3 + 4 * *(_DWORD *)(v3 + 74) + 62) + *(_DWORD *)(v3 + 82) + 236) = v11;
  GiveTakeArtifactStat(*(hero **)(v3 + 4 * *(_DWORD *)(v3 + 70) + 62), v12, 0);
  GiveTakeArtifactStat(*(hero **)(v3 + 4 * *(_DWORD *)(v3 + 74) + 62), a2, 0);
  hero::CheckAnduranPieces(*(hero **)(v3 + 4 * *(_DWORD *)(v3 + 70) + 62), 1);
  hero::CheckAnduranPieces(*(hero **)(v3 + 4 * *(_DWORD *)(v3 + 74) + 62), 1);
  if ( a2 == 102 || v12 == 102 )
  {
    evt = 512;
    for ( i = 0; i < 2; ++i )
    {
      for ( j = 0; j < 8; ++j )
      {
        if ( *(_DWORD *)(*(_DWORD *)(v3 + 4 * i + 62) + 144) > j )
        {
          v5 = 3;
          v6 = j + 8 * i + 216;
          v7 = gText;
          v1 = hero::GetNthSS(*(hero **)(v3 + 4 * i + 62), j);
          v2 = hero::GetSSLevel(*(hero **)(v3 + 4 * i + 62), (SECONDARY_SKILL)v1);
          sprintf(gText, "%d", v2);
          heroWindow::BroadcastMessage(*(heroWindow **)(v3 + 54), (Event *)&evt);
        }
      }
    }
  }
}
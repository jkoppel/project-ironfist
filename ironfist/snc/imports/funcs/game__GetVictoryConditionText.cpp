{
  signed int v2; // ST24_4@3
  int v3; // [sp+10h] [bp-E0h]@1
  char v4; // [sp+1Ch] [bp-D4h]@10
  char v5; // [sp+80h] [bp-70h]@10
  int v6; // [sp+E4h] [bp-Ch]@3
  bool v7; // [sp+E8h] [bp-8h]@10

  v3 = this;
  if ( *(_BYTE *)(this + 710) )
  {
    switch ( *(_BYTE *)(this + 710) )
    {
      case 1:
        v2 = game::GetTownId((void *)this, *(_WORD *)(this + 713), *(_WORD *)(this + 725));
        v6 = v3 + 100 * v2 + 2899;
        sprintf(
          a2,
          "Capture the %s '%s'",
          &aCastle_0[("town" - "castle") & (((*(_BYTE *)(v3 + 100 * v2 + 2923) & 0x40) != 0) - 1)],
          v3 + 100 * v2 + 2986);
        break;
      case 2:
        sprintf(a2, "Defeat the hero '%s'", this + 250 * *(_WORD *)(this + 713) + 10190);
        break;
      case 3:
        if ( *(_WORD *)(this + 713) )
          sprintf(a2, "Find the %s", dword_4F55F4[*(_WORD *)(this + 713)]);
        else
          sprintf(a2, "Find the ultimate artifact");
        break;
      case 5:
        sprintf(a2, "Accumulate %d gold", 1000 * *(_WORD *)(this + 713));
        break;
      case 4:
        v7 = game::GetSideDesc(this, &v5, 0, *(_WORD *)(this + 713) - 1);
        game::GetSideDesc(v3, &v4, *(_WORD *)(v3 + 713), *(_BYTE *)(v3 + 707) - 1);
        if ( v7 )
          sprintf(a2, "%s must defeat %s", &v5, &v4);
        else
          sprintf(a2, "%s must defeat %s", &v4, &v5);
        break;
      default:
        break;
    }
    if ( *(_BYTE *)(v3 + 710) != 4 && *(_BYTE *)(v3 + 712) )
      strcat(a2, ", or you may win by defeating all enemy heroes and capturing all enemy towns and castles.");
    else
      strcat(a2, L".");
  }
  else
  {
    strcpy(a2, "Defeat all enemy heroes and capture all enemy towns and castles.");
  }
}
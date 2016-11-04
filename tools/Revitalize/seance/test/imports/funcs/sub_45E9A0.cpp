{
  signed int v2; // ST24_4@3
  char *result; // eax@17
  int v4; // [sp+10h] [bp-E0h]@1
  char v5; // [sp+1Ch] [bp-D4h]@10
  char v6; // [sp+80h] [bp-70h]@10
  int v7; // [sp+E4h] [bp-Ch]@3
  bool v8; // [sp+E8h] [bp-8h]@10

  v4 = this;
  if ( *(_BYTE *)(this + 710) )
  {
    switch ( *(_BYTE *)(this + 710) )
    {
      case 1:
        v2 = sub_419C90((void *)this, *(_WORD *)(this + 713), *(_WORD *)(this + 725));
        v7 = v4 + 100 * v2 + 2899;
        sprintf(
          a2,
          "Capture the %s '%s'",
          &aCastle_0[("town" - "castle") & (((*(_BYTE *)(v4 + 100 * v2 + 2923) & 0x40) != 0) - 1)],
          v4 + 100 * v2 + 2986);
        break;
      case 2:
        sprintf(a2, "Defeat the hero '%s'", this + 250 * *(_WORD *)(this + 713) + 10190);
        break;
      case 3:
        if ( *(_WORD *)(this + 713) )
          sprintf(a2, "Find the %s", unk_4F55F4[*(_WORD *)(this + 713)]);
        else
          sprintf(a2, "Find the ultimate artifact");
        break;
      case 5:
        sprintf(a2, "Accumulate %d gold", 1000 * *(_WORD *)(this + 713));
        break;
      case 4:
        v8 = sub_45ECA0(this, &v6, 0, *(_WORD *)(this + 713) - 1);
        sub_45ECA0(v4, &v5, *(_WORD *)(v4 + 713), *(_BYTE *)(v4 + 707) - 1);
        if ( v8 )
          sprintf(a2, "%s must defeat %s", &v6, &v5);
        else
          sprintf(a2, "%s must defeat %s", &v5, &v6);
        break;
      default:
        break;
    }
    if ( *(_BYTE *)(v4 + 710) != 4 && *(_BYTE *)(v4 + 712) )
      result = strcat(a2, ", or you may win by defeating all enemy heroes and capturing all enemy towns and castles.");
    else
      result = strcat(a2, L".");
  }
  else
  {
    result = strcpy(a2, "Defeat all enemy heroes and capture all enemy towns and castles.");
  }
  return result;
}

{
  int v3; // [sp+Ch] [bp-138h]@1
  char v4; // [sp+10h] [bp-134h]@1
  int attack; // [sp+13Ch] [bp-8h]@1
  int numArchers; // [sp+140h] [bp-4h]@1

  v3 = this;
  Castle::retrieveBallistaStats(*(Castle **)(this + 12931), &numArchers, &attack);
  sprintf(globBuf, "Ballista");
  strcpy(&v4, byte_50E800);
  if ( *(_BYTE *)(v3 + 12906) )
  {
    sprintf(&v4, "\n\nThe %s is destroyed.", "Ballista");
  }
  else
  {
    if ( attack <= 0 )
      sprintf(&v4, "\n\nThe %s fires with the strength of %d Archers.", "Ballista", numArchers);
    else
      sprintf(
        &v4,
        "\n\nThe %s fires with the strength of %d Archers, each with a +%d bonus to their attack skill.",
        "Ballista",
        numArchers,
        attack);
  }
  strcat(globBuf, &v4);
  strcpy(&v4, byte_50E8D0);
  if ( *(_BYTE *)(*(_DWORD *)(v3 + 12931) + 25) & 1 )
  {
    if ( *(_BYTE *)(v3 + 12898) == 2 )
    {
      sprintf(&v4, "\n\nThe %s is destroyed.", "Left Turret");
    }
    else
    {
      if ( *(_BYTE *)(v3 + 12898) == 1 )
      {
        if ( attack <= 0 )
          sprintf(&v4, "\n\nThe %s fires with the strength of %d Archers.", "Left Turret", numArchers / 2);
        else
          sprintf(
            &v4,
            "\n\nThe %s fires with the strength of %d Archers, each with a +%d bonus to their attack skill.",
            "Left Turret",
            numArchers / 2,
            attack);
      }
    }
    strcat(globBuf, &v4);
  }
  if ( *(_BYTE *)(*(_DWORD *)(v3 + 12931) + 25) & 2 )
  {
    strcpy(&v4, byte_50E9A0);
    if ( *(_BYTE *)(v3 + 12901) == 2 )
    {
      sprintf(&v4, "\n\nThe %s is destroyed.", "Right Turret");
    }
    else
    {
      if ( *(_BYTE *)(v3 + 12901) == 1 )
      {
        if ( attack <= 0 )
          sprintf(&v4, "\n\nThe %s fires with the strength of %d Archers.", "Right Turret", numArchers / 2);
        else
          sprintf(
            &v4,
            "\n\nThe %s fires with the strength of %d Archers, each with a +%d bonus to their attack skill.",
            "Right Turret",
            numArchers / 2,
            attack);
      }
    }
    strcat(globBuf, &v4);
  }
  return display_message_window(globBuf, a2 < 1 ? 1 : 4, -1, -1, -1, 0, -1, 0, -1, 0);
}

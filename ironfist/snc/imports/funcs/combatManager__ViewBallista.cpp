{
  char buf[300]; // [sp+10h] [bp-134h]@1
  int attack; // [sp+13Ch] [bp-8h]@1
  int numArchers; // [sp+140h] [bp-4h]@1

  town::CalcNumLevelArchers(this->castles[1], &numArchers, &attack);
  sprintf(gText, "Ballista");
  strcpy(buf, byte_50E800);
  if ( this->ballistaDestroyed )
  {
    sprintf(buf, "\n\nThe %s is destroyed.", "Ballista");
  }
  else if ( attack <= 0 )
  {
    sprintf(buf, "\n\nThe %s fires with the strength of %d Archers.", "Ballista", numArchers);
  }
  else
  {
    sprintf(
      buf,
      "\n\nThe %s fires with the strength of %d Archers, each with a +%d bonus to their attack skill.",
      "Ballista",
      numArchers,
      attack);
  }
  strcat(gText, buf);
  strcpy(buf, byte_50E8D0);
  if ( BYTE1(this->castles[1]->buildingsBuiltFlags) & 1 )
  {
    if ( this->turretStatus[0] == 2 )
    {
      sprintf(buf, "\n\nThe %s is destroyed.", "Left Turret");
    }
    else if ( this->turretStatus[0] == 1 )
    {
      if ( attack <= 0 )
        sprintf(buf, "\n\nThe %s fires with the strength of %d Archers.", "Left Turret", numArchers / 2);
      else
        sprintf(
          buf,
          "\n\nThe %s fires with the strength of %d Archers, each with a +%d bonus to their attack skill.",
          "Left Turret",
          numArchers / 2,
          attack);
    }
    strcat(gText, buf);
  }
  if ( BYTE1(this->castles[1]->buildingsBuiltFlags) & 2 )
  {
    strcpy(buf, byte_50E9A0);
    if ( this->turretStatus[3] == 2 )
    {
      sprintf(buf, "\n\nThe %s is destroyed.", "Right Turret");
    }
    else if ( this->turretStatus[3] == 1 )
    {
      if ( attack <= 0 )
        sprintf(buf, "\n\nThe %s fires with the strength of %d Archers.", "Right Turret", numArchers / 2);
      else
        sprintf(
          buf,
          "\n\nThe %s fires with the strength of %d Archers, each with a +%d bonus to their attack skill.",
          "Right Turret",
          numArchers / 2,
          attack);
    }
    strcat(gText, buf);
  }
  return NormalDialog(gText, a2 < 1 ? 1 : 4, -1, -1, -1, 0, -1, 0, -1, 0);
}
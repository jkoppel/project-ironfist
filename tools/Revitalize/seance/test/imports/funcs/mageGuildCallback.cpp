{
  signed int result; // eax@14
  int spell; // ST0C_4@15
  int v3; // [sp+Ch] [bp-28h]@2
  signed int col; // [sp+18h] [bp-1Ch]@13
  signed int rowTimesFour; // [sp+2Ch] [bp-8h]@3

  if ( evt->eventCode != 512 )
    goto LABEL_22;
  v3 = evt->xCoordOrKeycode;
  if ( v3 != 12 && v3 != 14 )
    goto LABEL_22;
  rowTimesFour = -1;
  if ( evt->yCoord >= 10 && evt->yCoord < 30 )
    rowTimesFour = evt->yCoord - 10;
  if ( evt->yCoord >= 40 && evt->yCoord < 60 )
    rowTimesFour = evt->yCoord - 40;
  if ( evt->yCoord >= 70 && evt->yCoord < 90 )
    rowTimesFour = evt->yCoord - 70;
  if ( rowTimesFour == -1 )
  {
LABEL_22:
    result = sub_432A10(evt);
  }
  else
  {
    col = (((unsigned __int64)rowTimesFour >> 32) ^ abs(rowTimesFour) & 3) - ((unsigned __int64)rowTimesFour >> 32);
    if ( townManager->castle->numSpellsOfLevel[rowTimesFour / 4] > col )
    {
      spell = townManager->castle->mageGuildSpells[rowTimesFour / 4][col];
      display_message_window(
        spell_descriptions[spell],
        (evt->inputTypeBitmask & 0x200u) < 1 ? 1 : 4,
        -1,
        -1,
        8,
        spell,
        -1,
        0,
        -1,
        0);
      result = 1;
    }
    else
    {
      result = 1;
    }
  }
  return result;
}

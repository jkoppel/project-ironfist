{
  signed int result; // eax@6
  int v2; // [sp+14h] [bp-14h]@10
  int v3; // [sp+18h] [bp-10h]@8
  tag_message *thisa; // [sp+1Ch] [bp-Ch]@1
  signed int v5; // [sp+20h] [bp-8h]@9
  signed int v6; // [sp+24h] [bp-4h]@9

  thisa = this;
  if ( !soundManager::MusicPlaying(gpSoundManager) && gpAdvManager->ready == 1 )
    soundManager::SwitchAmbientMusic(
      gpSoundManager,
      (unsigned __int8)giTerrainToMusicTrack[gpAdvManager->currentTerrain]);
  if ( giDialogTimeout && KBTickCount() > giDialogTimeout )
  {
    thisa->eventCode = 512;
    gpWindowManager->buttonPressedCode = thisa->yCoord;
    thisa->yCoord = 10;
    thisa->xCoordOrKeycode = thisa->yCoord;
    giDialogTimeout = 0;
    return 2;
  }
  if ( thisa->eventCode != INPUT_GUI_MESSAGE_CODE )
    return 1;
  v3 = thisa->xCoordOrKeycode;
  if ( v3 == 12 )
    goto LABEL_9;
  if ( v3 != 13 )
  {
    if ( v3 != 14 )
      return 1;
LABEL_9:
    v6 = -1;
    v5 = -1;
    if ( BYTE1(thisa->inputTypeBitmask) & 2 )
    {
      v2 = thisa->yCoord;
      if ( v2 == 7700 )
      {
        v6 = giResType1;
        v5 = giResExtra1;
      }
      else if ( v2 == 7701 )
      {
        v6 = giResType2;
        v5 = giResExtra2;
      }
      switch ( v6 )
      {
        case 10:
          NormalDialog(cLuckInfo, 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 11:
          NormalDialog(off_4F6428, 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 12:
          NormalDialog(cMoraleInfo, 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 13:
          NormalDialog(off_4F68A0, 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 14:
          NormalDialog(
            "{Experience}\n\nExperience allows your heroes to go up levels, increasing their primary and secondary skills.",
            4,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
          break;
        case 7:
          if ( v5 == 86 )
          {
            sprintf(gText, gArtifactDesc[86], gSpellNames[xTheSpell]);
            NormalDialog(gText, 4, -1, -1, -1, 0, -1, 0, -1, 0);
          }
          else
          {
            NormalDialog(gArtifactDesc[v5], 4, -1, -1, -1, 0, -1, 0, -1, 0);
          }
          break;
        case 8:
          NormalDialog(gSpellDesc[v5], 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 17:
          NormalDialog((&cSecSkillDesc[3 * (v5 / 3)])[4 * (v5 % 3)], 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 25:
          NormalDialog(gStatDesc[v5], 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
          NormalDialog(
            "{Resources}\n\nThere are seven resources in Heroes 2, used to build and improves castles, purchase troops and recruit heroes.  Gold is the most common, required for virtually everything.  Wood and ore are used for most buildings.  Gems, Mercury, Sulfur and Crystal are rare magical resources used for the most powerful creatures and buildings.",
            4,
            -1,
            -1,
            -1,
            0,
            -1,
            0,
            -1,
            0);
          break;
        default:
          return 1;
      }
    }
    return 1;
  }
  switch ( thisa->yCoord )
  {
    case 0x7800:
    case 0x7801:
    case 0x7802:
    case 0x7803:
    case 0x7805:
    case 0x7806:
    case 0x7807:
    case 0x7808:
      gpWindowManager->buttonPressedCode = thisa->yCoord;
      thisa->yCoord = 10;
      thisa->xCoordOrKeycode = thisa->yCoord;
      giDialogTimeout = 0;
      result = 2;
      break;
    case 0x7804:
      return 1;
  }
  return result;
}
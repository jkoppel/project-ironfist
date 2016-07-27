{
  signed int result; // eax@6
  int v2; // [sp+14h] [bp-14h]@10
  int v3; // [sp+18h] [bp-10h]@8
  InputEvent *thisa; // [sp+1Ch] [bp-Ch]@1
  signed int v5; // [sp+20h] [bp-8h]@9
  signed int v6; // [sp+24h] [bp-4h]@9

  thisa = this;
  if ( !SoundManager::songPlaying(soundManager) && advManager->ready == 1 )
    SoundManager::couldBePlayCDTrack(soundManager, (unsigned __int8)byte_4F4B90[advManager->field_A6]);
  if ( dword_4F1CB4 && getTickCount() > dword_4F1CB4 )
  {
    thisa->eventCode = 512;
    HeroWindowManager::instance->buttonPressedCode = thisa->yCoord;
    thisa->yCoord = 10;
    thisa->xCoordOrKeycode = thisa->yCoord;
    dword_4F1CB4 = 0;
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
        v6 = dword_524228;
        v5 = dword_524788;
      }
      else
      {
        if ( v2 == 7701 )
        {
          v6 = dword_524230;
          v5 = dword_524790;
        }
      }
      switch ( v6 )
      {
        case 10:
          display_message_window(off_4F6420, 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 11:
          display_message_window(off_4F6428, 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 12:
          display_message_window(off_4F6898, 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 13:
          display_message_window(off_4F68A0, 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 14:
          display_message_window(
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
            sprintf(globBuf, artifact_descriptions[86], spell_names[dword_5304CC]);
            display_message_window(globBuf, 4, -1, -1, -1, 0, -1, 0, -1, 0);
          }
          else
          {
            display_message_window(artifact_descriptions[v5], 4, -1, -1, -1, 0, -1, 0, -1, 0);
          }
          break;
        case 8:
          display_message_window(spell_descriptions[v5], 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 17:
          display_message_window(
            (&secondarySkillDescriptions[3 * (v5 / 3)])[4 * (v5 % 3)],
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
        case 25:
          display_message_window(primary_skill_descriptions[v5], 4, -1, -1, -1, 0, -1, 0, -1, 0);
          break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
          display_message_window(
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
      HeroWindowManager::instance->buttonPressedCode = thisa->yCoord;
      thisa->yCoord = 10;
      thisa->xCoordOrKeycode = thisa->yCoord;
      dword_4F1CB4 = 0;
      result = 2;
      break;
    case 0x7804:
      return 1;
  }
  return result;
}

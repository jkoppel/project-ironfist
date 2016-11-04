{
  SoundManager *result; // eax@1
  int v1; // [sp+0h] [bp-10h]@0

  sub_4035A0(soundManager, 1, v1);
  SoundManager::couldBePlayCDTrack(soundManager, 28);
  result = soundManager;
  soundManager->field_688 = 0;
  return result;
}

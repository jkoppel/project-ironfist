void *__thiscall winScenario(void *this)
{
  int v1; // eax@2
  __int16 v2; // ax@4
  int v3; // eax@4
  int v4; // eax@5
  __int16 v5; // ax@11
  int v7; // [sp+0h] [bp-33Ch]@0
  void *v8; // [sp+Ch] [bp-330h]@1
  char v9; // [sp+10h] [bp-32Ch]@2
  int v10; // [sp+30h] [bp-30Ch]@1
  int v11; // [sp+34h] [bp-308h]@1
  char v12; // [sp+3Ch] [bp-300h]@1

  v8 = this;
  MouseManager::disableCursor(mouseManager);
  memcpy(&v12, palette->contents, 0x300u);
  HeroWindowManager::instance->field_56 = 0;
  dword_4F55F0 = (char *)KBAlloc(0x1F4u, "F:\\h2xsrc\\Source\\KB.CPP", word_50D9D4 + 9);
  v11 = sub_42CAA0(dword_532C54);
  v10 = v11 * gameObject->field_0 / 100;
  SoundManager::otherPlayTrack(soundManager, -1, 0, -1, v7);
  if ( v8 == (void *)1 )
  {
    v1 = sub_4357C0(v10, 1);
    sprintf(&v9, creatureSingularNames[v1]);
  }
  else
  {
    if ( v8 == (void *)2 )
    {
      v2 = sub_472850((int)&unk_530450);
      v3 = sub_4357C0(v2, 2);
      sprintf(&v9, creatureSingularNames[v3]);
    }
    else
    {
      v4 = sub_4357C0(*(_WORD *)&gameObject->_1[181], v8);
      sprintf(&v9, creatureSingularNames[v4]);
    }
  }
  v9 -= 32;
  if ( gameObject->_10[32] )
    sprintf(&v9, "Cheater!!!");
  if ( v8 == (void *)1 )
  {
    sprintf(
      dword_4F55F0,
      "Congratulations!\n\nDays: %d\nBase Score: %d\nDifficulty: %d\n\nScore: %d\n\nRating:\n%s\n",
      dword_532C54,
      v11,
      gameObject->field_0,
      v10,
      &v9);
  }
  else
  {
    if ( v8 == (void *)2 )
    {
      v5 = sub_472850((int)&unk_530450);
      sprintf(dword_4F55F0, "Congratulations!\n\nDays: %d\n\nRating:\n%s\n", v5, &v9);
    }
    else
    {
      sprintf(dword_4F55F0, "Congratulations!\n\nDays: %d\n\nRating:\n%s\n", *(_WORD *)&gameObject->_1[181], &v9);
    }
  }
  sub_45A2A0(2);
  memcpy(palette->contents, dword_524234->contents, 0x300u);
  sub_436EA0(palette->contents, &v12);
  memcpy(dword_524234->contents, &v12, 0x300u);
  memcpy(palette->contents, dword_524234->contents, 0x300u);
  MouseManager::enableCursor(mouseManager);
  sub_435860(v10, dword_532C54, gameObject->field_0, 1, &gameObject->_3[13]);
  KBFree(dword_4F55F0, (int)"F:\\h2xsrc\\Source\\KB.CPP", word_50D9D4 + 78);
  dword_4F55F0 = 0;
  HeroWindowManager::instance->field_56 = 1;
  return memcpy(palette->contents, dword_524234->contents, 0x300u);
}

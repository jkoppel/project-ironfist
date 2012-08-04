{
  advManager::TeleportTo(gpAdvManager, gpCurAIHero, a1, SHIDWORD(a1), 0, 0);
  if ( *(_DWORD *)&gpCurAIHero->field_35 >= 225 )
    *(_DWORD *)&gpCurAIHero->field_35 -= 225;
  else
    *(_DWORD *)&gpCurAIHero->field_35 = 0;
  hero::UseSpell(gpCurAIHero, 56);
}
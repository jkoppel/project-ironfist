void __thiscall sub_4DC890(int this)
{
  __int16 v1; // ax@1

  v1 = *(_WORD *)(this + 20);
  if ( v1 != 8 )
  {
    if ( v1 != 512 )
      Bitmap::colorSubstituteRectangle(
        HeroWindowManager::instance->screenBuffer,
        (signed __int16)(*(_WORD *)(*(_DWORD *)(this + 4) + 40) + *(_WORD *)(this + 24)),
        (signed __int16)(*(_WORD *)(*(_DWORD *)(this + 4) + 44) + *(_WORD *)(this + 26)),
        *(_WORD *)(this + 28),
        *(_WORD *)(this + 30),
        0);
  }
}

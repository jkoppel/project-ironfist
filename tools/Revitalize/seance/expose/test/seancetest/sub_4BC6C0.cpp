signed int __thiscall sub_4BC6C0(void *this)
{
  signed int result; // eax@13
  void *v2; // [sp+10h] [bp-8h]@1
  signed int v3; // [sp+14h] [bp-4h]@1

  v2 = this;
  v3 = 0;
  yieldToGlobalUpdater();
  if ( *(_DWORD *)v2 == 512
    && *((_DWORD *)v2 + 1) == 13
    && (*((_DWORD *)v2 + 2) > 0 && *((_DWORD *)v2 + 2) <= 1000 || *((_DWORD *)v2 + 2) == 30721) )
    v3 = 1;
  if ( v3 || dword_4F19A8 != -1 )
  {
    HeroWindowManager::instance->buttonPressedCode = *((_DWORD *)v2 + 2);
    *((_DWORD *)v2 + 2) = 10;
    *((_DWORD *)v2 + 1) = *((_DWORD *)v2 + 2);
    if ( dword_4F19A8 != -1 )
      HeroWindowManager::instance->buttonPressedCode = 30721;
    result = 2;
  }
  else
  {
    sub_4398D0();
    result = 1;
  }
  return result;
}

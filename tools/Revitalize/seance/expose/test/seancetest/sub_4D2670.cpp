_UNKNOWN *__thiscall sub_4D2670(void *this)
{
  void *v2; // [sp+Ch] [bp-8h]@1

  v2 = this;
  if ( dword_537928 )
    unknown_libname_27();
  dword_537928 = 1;
  unk_537938 = v2;
  *((_DWORD *)&unk_537938 + 1) = 0;
  *((_DWORD *)&unk_537938 + 2) = 0;
  *((_BYTE *)&unk_537938 + 12) = 114;
  return &unk_537938;
}

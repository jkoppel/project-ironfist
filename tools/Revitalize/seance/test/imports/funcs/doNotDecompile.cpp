{
  int v0; // edx@0
  __int16 v1; // cx@0
  signed __int16 v3; // bx@2

  if ( *(_BYTE *)(v0 + 14) == 5 )
  {
    HIBYTE(v3) = ((unsigned __int8)(*(_WORD *)(_EBP - 164) >> 8) | 2) & 0xFE;
    LOBYTE(v3) = 63;
  }
  else
  {
    v3 = 4927;
  }
  *(_WORD *)(_EBP - 162) = v3;
  __asm { fldcw   word ptr [ebp-0A2h] }
  _EBX = &unk_521ADC;
  __asm { fxam }
  *(_DWORD *)(_EBP - 148) = v0;
  __asm { fstsw   word ptr [ebp-0A0h] }
  *(_BYTE *)(_EBP - 144) = 0;
  LOBYTE(v1) = __ROL__((char)(2 * *(_BYTE *)(_EBP - 159)) >> 1, 1);
  _AL = v1 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))(_AL + v0 + 16))(v1 & 0x404);
}

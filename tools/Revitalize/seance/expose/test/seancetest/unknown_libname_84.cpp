// Microsoft VisualC 2-8/net runtime
int __usercall unknown_libname_84<eax>(int a1<edx>, int a2<ebp>, __int16 a3<fpstat>, double _ST6<st1>, double a5<st0>, char a6, char a7, char a8)
{
  signed __int16 v8; // bx@2
  __int16 v10; // fps@4
  char v12; // cl@4
  __int16 v13; // cx@4
  char v16; // ah@4

  if ( *(_BYTE *)(a1 + 14) == 5 )
  {
    HIBYTE(v8) = ((unsigned __int8)(*(_WORD *)(a2 - 164) >> 8) | 2) & 0xFE;
    LOBYTE(v8) = 63;
  }
  else
  {
    v8 = 4927;
  }
  *(_WORD *)(a2 - 162) = v8;
  _EBX = &unk_521ADC;
  __asm { fxam }
  *(_DWORD *)(a2 - 148) = a1;
  *(_WORD *)(a2 - 160) = a3;
  *(_BYTE *)(a2 - 144) = 0;
  UNDEF(v10);
  _ST6 = a5;
  v12 = *(_BYTE *)(a2 - 159);
  __asm { fxam }
  *(_WORD *)(a2 - 160) = v10;
  HIBYTE(v13) = __ROL__((char)(2 * *(_BYTE *)(a2 - 159)) >> 1, 1);
  _AL = HIBYTE(v13) & 0xF;
  __asm { xlat }
  v16 = _AL;
  LOBYTE(v13) = __ROL__((char)(2 * v12) >> 1, 1);
  _AL = v13 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))((char)(4 * v16 | _AL) + a1 + 16))(v13 & 0x404);
}

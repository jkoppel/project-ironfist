AdvManager *__thiscall sub_4BFAC0(AdvManager *this, int a2)
{
  int v2; // ST14_4@4
  AdvManager *result; // eax@5
  AdvManager *thisa; // [sp+Ch] [bp-8h]@1

  thisa = this;
  if ( a2 )
  {
    dword_51E180 = 1;
    this->field_282 = sub_4C0550(this->field_27E);
    thisa->field_286 = 0;
    dword_51E1BC = 0;
    dword_51E1B4 = 0;
    dword_51E1B8 = 0;
  }
  thisa->field_28A = 0;
  if ( *(_DWORD *)&thisa->field_292[4] != -1 )
  {
    v2 = *thisa->field_AE
       + 12 * (thisa->viewX + *(_DWORD *)&thisa->field_292[4])
       + 12 * thisa->field_AE[2] * (thisa->viewY + *(_DWORD *)&thisa->field_292[12]);
    *(_BYTE *)(v2 + 8) &= 0xBFu;
    *(_DWORD *)&thisa->field_292[12] = -1;
    *(_DWORD *)&thisa->field_292[4] = *(_DWORD *)&thisa->field_292[12];
  }
  result = thisa;
  thisa->field_28E = 0;
  return result;
}

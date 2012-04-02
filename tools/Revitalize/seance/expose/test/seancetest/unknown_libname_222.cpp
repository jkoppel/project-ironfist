// Microsoft VisualC 2-8/net runtime
void __usercall unknown_libname_222(int a1<ecx>, double a2<st0>)
{
  char v2; // dl@4
  _BYTE v3[12]; // [sp+0h] [bp-34h]@0
  int v4; // [sp+Ch] [bp-28h]@0
  _BYTE *v5; // [sp+10h] [bp-24h]@0
  __int16 v6; // [sp+20h] [bp-14h]@0

  *(double *)v3 = a2;
  if ( *(_DWORD *)&v3[6] & 0x7FFF0000 )
  {
    unknown_libname_211(a1, 0, LODWORD(a2), *(unsigned __int64 *)&a2 >> 32, *(int *)&v3[8], v4, v5);
  }
  else
  {
    if ( a2 != 0.0 )
    {
      v2 = 2;
      if ( (v6 & 0x7FFFu) > 0x7FBE )
      {
        *(double *)v3 = a2 * dbl_5223A4;
      }
      else
      {
        v2 = 3;
        *(double *)v3 = a2 * dbl_5223A4;
      }
      unknown_libname_211(
        a1,
        v2,
        *(_BYTE **)v3,
        *(int *)&v3[4],
        *(int *)&v3[8],
        SLODWORD(a2),
        (_BYTE *)(*(unsigned __int64 *)&a2 >> 32));
    }
  }
}

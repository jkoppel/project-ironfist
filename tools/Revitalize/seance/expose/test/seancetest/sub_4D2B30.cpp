void __thiscall sub_4D2B30(void *this)
{
  int v1; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  v1 = (int)this;
  dword_534FF0 = 0;
  dword_534FF4 = 33554432;
  dword_534FEC = 0;
  for ( i = 1; i <= 26; ++i )
    dword_534FEC = sub_4D27E0(v1) + 2 * dword_534FEC;
}

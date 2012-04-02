int __thiscall sub_4D2AE0(void *this)
{
  int result; // eax@3
  int v2; // [sp+Ch] [bp-8h]@1
  signed int i; // [sp+10h] [bp-4h]@1

  v2 = (int)this;
  for ( i = 26; i >= 1; --i )
    result = sub_4D2A50(v2, ((unsigned int)dword_534FF0 >> (i - 1)) & 1);
  return result;
}

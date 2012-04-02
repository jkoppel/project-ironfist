int __fastcall sub_4D2A50(int a1, char a2)
{
  int result; // eax@1
  char v3; // [sp+Ch] [bp-8h]@1
  int v4; // [sp+10h] [bp-4h]@1

  v3 = a2;
  v4 = a1;
  result = sub_4D2750(a1, a2);
  while ( dword_5347AC )
  {
    result = sub_4D2750(v4, 1 - v3);
    --dword_5347AC;
  }
  return result;
}

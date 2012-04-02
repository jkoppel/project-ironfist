void __thiscall sub_4C2E60(void *this, const void *a2)
{
  void *v2; // [sp+Ch] [bp-18h]@1
  int v3; // [sp+14h] [bp-10h]@3
  void *buf; // [sp+18h] [bp-Ch]@1
  signed int i; // [sp+1Ch] [bp-8h]@1

  v2 = this;
  buf = KBAlloc(0x2Cu, "F:\\h2xsrc\\Source\\CURSOR.CPP", word_51E33C + 7);
  memcpy(buf, a2, 0x2Cu);
  for ( i = 3; i >= 0; --i )
  {
    v3 = (int)((char *)buf + 11 * i);
    if ( *((_BYTE *)buf + 11 * i) )
    {
      if ( *(_DWORD *)(v3 + 7) >= *(_DWORD *)&dword_524A78 )
        sub_4C2CA0(v2, v3);
    }
  }
  KBFree(buf, (int)"F:\\h2xsrc\\Source\\CURSOR.CPP", word_51E33C + 25);
}

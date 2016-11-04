{
  char result; // al@1
  int v2; // [sp+14h] [bp-8h]@1
  int v3; // [sp+18h] [bp-4h]@3

  v2 = a1;
  result = (_BYTE)a1 << 6;
  if ( (*((_BYTE *)&byte_52F868 + 64 * a1) & 0x7F) == 21 )
  {
    switch ( byte_52F869[64 * a1] )
    {
      case 0:
        v3 = (int)KBAlloc(
                    (unsigned __int16)word_52F870[32 * a1] + 11,
                    "F:\\h2xsrc\\Source\\netwin.cpp",
                    word_513050 + 16);
        if ( v3 )
        {
          *(_WORD *)(v3 + 8) = word_52F870[32 * v2];
          *(_BYTE *)(v3 + 10) = v2;
          memcpy((void *)(v3 + 11), (char *)&unk_527850 + 4096 * v2, *(_WORD *)(v3 + 8));
          EnterCriticalSection(&CriticalSection);
          sub_4BC7B0((int)&unk_527838, v3);
          LeaveCriticalSection(&CriticalSection);
        }
        result = sub_474010(v2);
        break;
      case 8:
      case 0xA:
      case 0x18:
        result = a1;
        byte_512EC4[a1] &= 0xFEu;
        break;
      default:
        result = sub_474010(a1);
        break;
    }
  }
  return result;
}

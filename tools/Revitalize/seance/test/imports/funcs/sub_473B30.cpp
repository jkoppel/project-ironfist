{
  int v1; // eax@3
  int v3; // [sp+Ch] [bp-4h]@1

  v3 = a1;
  if ( (unsigned __int8)byte_52F899[64 * a1] != 255 )
  {
    memset((char *)&byte_52F868 + 64 * a1, 0, 0x40u);
    *((_BYTE *)&byte_52F868 + 64 * v3) = -93;
    byte_52F86B[64 * v3] = byte_512EC0;
    word_52F870[32 * v3] = 4096;
    dword_52F86C[16 * v3] = (int)((char *)&unk_527850 + 4096 * v3);
    dword_52F894[16 * v3] = (int)sub_473BF0;
    Netbios((PNCB)&byte_52F868 + v3);
  }
  v1 = v3 << 6;
  LOBYTE(v1) = byte_52F899[64 * v3];
  return v1 & 0xFFFF00FF;
}

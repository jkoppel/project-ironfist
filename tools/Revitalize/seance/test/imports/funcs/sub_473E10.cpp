{
  const void *v2; // ST18_4@1
  int v3; // ST1C_4@1
  int v4; // eax@1

  v2 = a2;
  v3 = a1;
  memset((char *)&byte_52F868 + 64 * a1, 0, 0x40u);
  memcpy((char *)&byte_52F868 + 64 * v3 + 10, v2, 0x10u);
  memcpy((char *)&byte_52F868 + 64 * v3 + 26, &dword_52FA68[16 * (unsigned __int8)byte_512EBC], 0x10u);
  *((_BYTE *)&byte_52F868 + 64 * v3) = -111;
  byte_52F899[64 * v3] = -1;
  dword_52F894[16 * v3] = (int)sub_473EE0;
  byte_52F898[64 * v3] = byte_512EB4;
  byte_512EAC = 0;
  LOBYTE(v4) = Netbios((PNCB)&byte_52F868 + v3);
  return v4 & 0xFFFF00FF;
}

{
  DWORD ModemStat; // [sp+14h] [bp-4h]@2

  return dword_532CF0[24 * a1] != -1
      && GetCommModemStatus((HANDLE)dword_532CF0[24 * a1], &ModemStat)
      && ModemStat & 0x10
      && ModemStat & 0x80;
}
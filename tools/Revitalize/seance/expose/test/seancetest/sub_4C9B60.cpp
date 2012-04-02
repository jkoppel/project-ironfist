int __cdecl sub_4C9B60()
{
  memset(&computerWalkSpeed, 0, 412u);
  *(&computerWalkSpeed + 412) = 0;
  readRegistryEntries();
  sprintf(byte_52497A, "RMT%sRL.BIN", &uniqueSystemID);
  sprintf(byte_524987, "RMT%sRC.BIN", &uniqueSystemID);
  sprintf(byte_524994, "RMT%sRD.BIN", &uniqueSystemID);
  sprintf(byte_5249A1, "RMT%sSL.BIN", &uniqueSystemID);
  sprintf(byte_5249AE, "RMT%sSC.BIN", &uniqueSystemID);
  return sprintf(byte_5249BB, "RMT%sSD.BIN", &uniqueSystemID);
}

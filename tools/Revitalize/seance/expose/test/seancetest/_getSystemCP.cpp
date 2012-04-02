UINT __cdecl getSystemCP(UINT a1)
{
  UINT result; // eax@1

  dword_52169C = 0;
  result = a1;
  switch ( a1 )
  {
    case 0xFFFFFFFEu:
      dword_52169C = 1;
      result = GetOEMCP();
      break;
    case 0xFFFFFFFDu:
      dword_52169C = 1;
      result = GetACP();
      break;
    case 0xFFFFFFFCu:
      dword_52169C = 1;
      result = CodePage;
      break;
  }
  return result;
}

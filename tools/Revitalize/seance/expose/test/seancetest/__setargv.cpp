int __cdecl _setargv()
{
  LPSTR v0; // esi@1
  int v1; // edi@3
  int result; // eax@5
  int v3; // [sp+8h] [bp-8h]@3
  int v4; // [sp+Ch] [bp-4h]@3

  v0 = Filename;
  GetModuleFileNameA(0, Filename, 0x104u);
  dword_520B70 = (int)Filename;
  if ( *lpCmdLine )
    v0 = lpCmdLine;
  parse_cmdline(v0, 0, 0, &v3, &v4);
  v1 = malloc(v4 + 4 * v3);
  if ( !v1 )
    _amsg_exit(8);
  parse_cmdline(v0, v1, v1 + 4 * v3, &v3, &v4);
  result = v3 - 1;
  dword_520B58 = v1;
  dword_520B54 = v3 - 1;
  return result;
}

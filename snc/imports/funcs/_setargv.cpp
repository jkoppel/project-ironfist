{
  LPSTR v0; // esi@1
  char **v1; // edi@3
  int result; // eax@5
  int v3; // [sp+8h] [bp-8h]@3
  int v4; // [sp+Ch] [bp-4h]@3

  v0 = Filename;
  GetModuleFileNameA(0, Filename, 0x104u);
  _pgmptr = Filename;
  if ( *_acmdln )
    v0 = _acmdln;
  parse_cmdline(v0, 0, 0, &v3, &v4);
  v1 = (char **)malloc(v4 + 4 * v3);
  if ( !v1 )
    _amsg_exit(8);
  parse_cmdline(v0, v1, &v1[v3], &v3, &v4);
  result = v3 - 1;
  __argv = v1;
  __argc = v3 - 1;
  return result;
}
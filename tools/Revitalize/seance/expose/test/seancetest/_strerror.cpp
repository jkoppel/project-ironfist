char *__cdecl strerror(int a1)
{
  int v1; // esi@1
  void *v2; // eax@2
  char *v3; // edx@2
  int v4; // eax@4

  v1 = _getptd();
  if ( *(_DWORD *)(v1 + 36) || (v2 = malloc(0x86u), v3 = (char *)&unk_537BC0, (*(_DWORD *)(v1 + 36) = v2) != 0) )
    v3 = *(char **)(v1 + 36);
  v4 = a1;
  if ( a1 < 0 || dword_5212B0 <= a1 )
    v4 = dword_5212B0;
  strcpy(v3, (const char *)*(&lpBuffer + v4));
  return v3;
}

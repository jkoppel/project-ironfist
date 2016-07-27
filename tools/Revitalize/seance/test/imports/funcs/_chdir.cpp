{
  signed int result; // eax@6
  unsigned __int32 v2; // eax@9
  const CHAR Name; // [sp+0h] [bp-10Ch]@7
  char v4; // [sp+1h] [bp-10Bh]@7
  char v5; // [sp+2h] [bp-10Ah]@7
  char v6; // [sp+3h] [bp-109h]@7
  CHAR Value; // [sp+4h] [bp-108h]@2
  char v8; // [sp+5h] [bp-107h]@5

  if ( !SetCurrentDirectoryA(lpPathName) || !GetCurrentDirectoryA(0x105u, &Value) )
    goto LABEL_12;
  if ( (Value == 92 || Value == 47) && Value == v8 )
    return 0;
  Name = 61;
  v4 = _mbctoupper((unsigned __int8)Value);
  v5 = 58;
  v6 = 0;
  if ( SetEnvironmentVariableA(&Name, &Value) )
  {
    result = 0;
  }
  else
  {
LABEL_12:
    v2 = ((int (__cdecl *)(_DWORD))GetLastError)(*(_DWORD *)&Name);
    _dosmaperr(v2);
    result = -1;
  }
  return result;
}

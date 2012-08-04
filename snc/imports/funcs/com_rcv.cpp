{
  __int16 result; // ax@10
  unsigned __int16 v4; // [sp+Ch] [bp-24h]@1
  __int16 v5; // [sp+10h] [bp-20h]@1
  DWORD nNumberOfBytesToRead; // [sp+14h] [bp-1Ch]@5
  struct _COMSTAT Stat; // [sp+1Ch] [bp-14h]@2
  DWORD NumberOfBytesRead; // [sp+28h] [bp-8h]@8
  DWORD Errors; // [sp+2Ch] [bp-4h]@2

  v4 = a2;
  v5 = a1;
  if ( dword_532CF0[24 * a1] == -1 )
    goto LABEL_14;
  if ( !ClearCommError((HANDLE)dword_532CF0[24 * a1], &Errors, &Stat) )
    ShutdownComError("Clear communications error queue");
  nNumberOfBytesToRead = Stat.cbInQue > v4 ? v4 : Stat.cbInQue;
  if ( nNumberOfBytesToRead )
  {
    if ( !ReadFile((HANDLE)dword_532CF0[24 * v5], lpBuffer, nNumberOfBytesToRead, &NumberOfBytesRead, 0) )
      ShutdownComError("Read communications data");
    result = NumberOfBytesRead;
  }
  else
  {
LABEL_14:
    result = 0;
  }
  return result;
}
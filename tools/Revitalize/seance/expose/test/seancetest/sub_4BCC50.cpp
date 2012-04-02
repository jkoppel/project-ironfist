signed __int16 __fastcall sub_4BCC50(unsigned __int8 a1, DWORD a2, int a3)
{
  signed __int16 result; // ax@9
  DWORD v4; // [sp+10h] [bp-50h]@1
  unsigned __int8 v5; // [sp+14h] [bp-4Ch]@1
  struct _COMMTIMEOUTS CommTimeouts; // [sp+18h] [bp-48h]@27
  CHAR FileName; // [sp+2Ch] [bp-34h]@10
  struct _DCB aDCB; // [sp+38h] [bp-28h]@12
  int v9; // [sp+54h] [bp-Ch]@23
  int i; // [sp+58h] [bp-8h]@1

  v4 = a2;
  v5 = a1;
  for ( i = 0; i < 2; ++i )
    dword_532CF0[24 * i] = -1;
  for ( i = 0; i < 2 && dword_532CF0[24 * i] != -1; ++i )
    ;
  if ( i < 2 )
  {
    wsprintfA(&FileName, "COM%d", a1);
    dword_532CF0[24 * i] = (int)CreateFileA(&FileName, 0xC0000000u, 0, 0, 3u, 0, 0);
    if ( dword_532CF0[24 * i] == -1 )
    {
      sprintf(globBuf, "Opening COM%d", v5);
      sub_4BC8B0(globBuf);
      result = -1;
    }
    else
    {
      aDCB.DCBlength = 28;
      GetCommState((HANDLE)dword_532CF0[24 * i], &aDCB);
      memcpy(&dword_532CF8[24 * i], &aDCB, 0x1Cu);
      GetCommTimeouts((HANDLE)dword_532CF0[24 * i], (LPCOMMTIMEOUTS)&dword_532CF0[24 * i + 9]);
      switch ( v4 )
      {
        case 1u:
          aDCB.BaudRate = 2400;
          break;
        case 2u:
          aDCB.BaudRate = 4800;
          break;
        case 3u:
          aDCB.BaudRate = 9600;
          break;
        case 4u:
          aDCB.BaudRate = 19200;
          break;
        case 5u:
          aDCB.BaudRate = 38400;
          break;
        default:
          aDCB.BaudRate = v4;
          break;
      }
      aDCB.fDummy2 &= 0xFFFFFFFDu;
      aDCB.fDummy2 |= 4u;
      if ( a3 )
        aDCB.fDummy2 |= 8u;
      else
        aDCB.fDummy2 &= 0xFFFFFFF7u;
      aDCB.fDummy2 = aDCB.fDummy2 & 0xFFFFFFDF | 0x10;
      aDCB.fDummy2 &= 0xFFFFFDFFu;
      aDCB.fDummy2 &= 0xFFFFFEFFu;
      aDCB.fDummy2 &= 0xFFFFF7FFu;
      aDCB.fDummy2 = aDCB.fDummy2 & 0xFFFFEFFF | 0x2000;
      aDCB.fDummy2 |= 0x4000u;
      aDCB.ByteSize = 8;
      aDCB.Parity = 0;
      aDCB.StopBits = 0;
      v9 = SetupComm((HANDLE)dword_532CF0[24 * i], 0x2000u, 0x1000u);
      if ( !v9 )
        sub_4BC8B0("Initialize communications paramaters");
      v9 = SetCommState((HANDLE)dword_532CF0[24 * i], &aDCB);
      if ( !v9 )
        sub_4BC8B0("Configure communications device");
      CommTimeouts.ReadIntervalTimeout = -1;
      CommTimeouts.ReadTotalTimeoutConstant = 0;
      CommTimeouts.ReadTotalTimeoutMultiplier = 0;
      CommTimeouts.WriteTotalTimeoutConstant = 0;
      CommTimeouts.WriteTotalTimeoutMultiplier = 0;
      v9 = SetCommTimeouts((HANDLE)dword_532CF0[24 * i], &CommTimeouts);
      if ( !v9 )
        sub_4BC8B0("Set communications timeouts");
      sub_4BC880((int)&dword_532D40[24 * i], 0);
      sub_4BC880((int)&dword_532D48[24 * i], 0);
      result = i;
    }
  }
  else
  {
    result = -1;
  }
  return result;
}

{
  int v1; // ST24_4@8
  int v2; // eax@8
  int v4; // ecx@14
  int v5; // ecx@15
  void *v6; // [sp+10h] [bp-14h]@1
  char v7; // [sp+1Ah] [bp-Ah]@0
  int v8; // [sp+1Ch] [bp-8h]@5
  int v9; // [sp+20h] [bp-4h]@1

  v6 = this;
  v9 = (int)sub_46E3F0(1);
  if ( v9 && (*(_BYTE *)(v9 + 5) == 2 || *(_BYTE *)(v9 + 5) == 3) )
  {
    switch ( *(_BYTE *)(v9 + 6) )
    {
      case 1:
        v8 = *(_DWORD *)(v9 + 21);
        if ( !sub_42BCA0(*(_DWORD *)(v9 + 9), *(_DWORD *)(v9 + 13), *(_DWORD *)(v9 + 17), *(_BYTE *)v9) )
          terminate(0);
        if ( v8 )
        {
          LOBYTE(v1) = *(_BYTE *)v9;
          v2 = sub_435DC0((void *)*(_BYTE *)v9);
          *(_WORD *)((char *)&v1 + 1) = (unsigned __int8)v2;
          BYTE3(v1) = 1;
          LOBYTE(v2) = v7;
          v2 <<= 16;
          LOWORD(v2) = 257;
          sub_439380(v1, v2);
        }
        sub_455AB0(v6);
        return 0;
      case 11:
        sub_435F20((const char *)(v9 + 9), (void *)*(_BYTE *)v9);
        return 0;
      case 21:
        if ( dword_4F7474 )
          return v9;
        sub_4936E0(v6, v9);
        break;
      case 31:
        debugLog("Receive Remote Player Exit");
        LOBYTE(v4) = *(_BYTE *)(v9 + 15);
        v4 <<= 16;
        LOWORD(v4) = *(_WORD *)(v9 + 13);
        sub_439380(*(_DWORD *)(v9 + 9), v4);
        return 0;
      case 33:
        debugLog("Host Reports Player Exit");
        LOBYTE(v5) = *(_BYTE *)(v9 + 15);
        v5 <<= 16;
        LOWORD(v5) = *(_WORD *)(v9 + 13);
        sub_438FA0(*(_BYTE *)v9, 0, *(_DWORD *)(v9 + 9), v5);
        return 0;
      case 41:
        sub_4C2E60(v6, (const void *)(v9 + 9));
        return 0;
      default:
        return v9;
    }
  }
  return 0;
}

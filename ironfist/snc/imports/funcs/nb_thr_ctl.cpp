{
  signed int v0; // [sp+Ch] [bp-58h]@17
  signed int v1; // [sp+50h] [bp-14h]@15
  int a1; // [sp+54h] [bp-10h]@10
  signed int v3; // [sp+58h] [bp-Ch]@1
  int i; // [sp+5Ch] [bp-8h]@4

  v3 = 1;
  if ( WaitForMultipleObjects(9u, &hObject, 0, 0) != 258 )
  {
    if ( !WaitForSingleObject(hObject, 0) )
      ResetEvent(hObject);
    for ( i = 0; i < 5; ++i )
    {
      if ( !WaitForSingleObject(*(&hHandle + i), 0) )
      {
        ResetEvent(*(&hHandle + i));
        sub_474230(i);
      }
    }
    while ( 1 )
    {
      while ( 1 )
      {
        if ( !v3 )
          return;
        EnterCriticalSection(&stru_52FAD8);
        a1 = pop_node((int)&unk_527808);
        if ( !a1 )
          a1 = pop_node((int)&unk_527848);
        LeaveCriticalSection(&stru_52FAD8);
        if ( a1 )
          break;
        v3 = 0;
      }
      memset(&pncb, 0, 0x40u);
      byte_52FA2A = *((_BYTE *)&byte_527840 + *(_BYTE *)(a1 + 10));
      if ( (unsigned __int8)byte_52FA2A != 255 )
        break;
LABEL_29:
      BaseFree((void *)a1, (int)"F:\\h2xsrc\\Source\\netwin.cpp", word_512FBC + 96);
    }
    memcpy(Dest, (const void *)(a1 + 11), *(_WORD *)(a1 + 8));
    dword_52FA2C = (int)Dest;
    word_52FA30 = *(_WORD *)(a1 + 8);
    pncb.ncb_command = 20;
    byte_52FA58 = byte_512EB4;
    v1 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( v1 )
          goto LABEL_29;
        v0 = thunk_Netbios(&pncb);
        if ( v0 <= 8 )
          break;
        if ( v0 == 10 || v0 == 24 )
        {
LABEL_20:
          byte_512EC4[*(_BYTE *)(a1 + 10)] &= 0xFEu;
        }
        else if ( v0 == 255 )
        {
          ProcessAssert(0, "F:\\h2xsrc\\Source\\netwin.cpp", word_512FBC + 83);
        }
      }
      if ( v0 == 8 )
        goto LABEL_20;
      if ( !v0 )
        v1 = 1;
    }
  }
}
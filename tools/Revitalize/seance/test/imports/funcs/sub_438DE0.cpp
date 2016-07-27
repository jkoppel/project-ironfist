{
  int v1; // eax@5
  int v2; // ST1C_4@5
  char v3; // [sp+16h] [bp-2h]@0

  if ( dword_524730 == a1 )
  {
    if ( !sub_42B410(gameObject, (dword_523F14 + 1) % dword_5235D4, 1, 0) )
      terminate(0);
    sub_46D360();
  }
  else
  {
    v1 = a1;
    LOBYTE(v2) = *((_BYTE *)&byte_5247A0 + a1);
    *(_WORD *)((char *)&v2 + 1) = (unsigned __int8)a1;
    BYTE3(v2) = 0;
    LOBYTE(v1) = v3;
    v1 <<= 16;
    LOWORD(v1) = 1;
    sub_439380(v2, v1);
  }
}

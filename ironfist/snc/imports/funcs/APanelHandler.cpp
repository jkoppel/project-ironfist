{
  signed int result; // eax@26
  int v2; // [sp+Ch] [bp-18h]@18
  int v3; // [sp+14h] [bp-10h]@5
  void *v4; // [sp+18h] [bp-Ch]@1
  signed int v5; // [sp+1Ch] [bp-8h]@5
  signed int v6; // [sp+20h] [bp-4h]@1

  v4 = this;
  v6 = 0;
  if ( *(_DWORD *)this == 512 )
  {
    if ( *((_BYTE *)this + 13) & 2 )
    {
      if ( *((_DWORD *)this + 1) == 12 || *((_DWORD *)this + 1) == 14 )
      {
        v5 = -1;
        v3 = *((_DWORD *)this + 2);
        if ( v3 <= 30720 )
        {
          if ( v3 == 30720 )
          {
            v5 = 4;
          }
          else
          {
            switch ( v3 )
            {
              case 1:
                v5 = 0;
                break;
              case 2:
                v5 = 1;
                break;
              case 3:
                v5 = 2;
                break;
              case 4:
                v5 = 3;
                break;
              default:
                break;
            }
          }
        }
        if ( v5 >= 0 )
          NormalDialog(gEventText[v5 + 110], 4, -1, -1, -1, 0, -1, 0, -1, 0);
      }
    }
    else if ( *((_DWORD *)this + 1) == 13 )
    {
      v2 = *((_DWORD *)this + 2);
      if ( v2 >= 1 && (v2 <= 4 || v2 == 30720) )
        v6 = 1;
    }
  }
  if ( v6 )
  {
    gpWindowManager->buttonPressedCode = *((_DWORD *)v4 + 2);
    *((_DWORD *)v4 + 2) = 10;
    *((_DWORD *)v4 + 1) = *((_DWORD *)v4 + 2);
    result = 2;
  }
  else
  {
    result = 1;
  }
  return result;
}
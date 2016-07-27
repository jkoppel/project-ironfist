{
  signed int result; // eax@2
  HMODULE v1; // eax@3
  HMODULE v2; // ebx@3
  int (*v3)(void); // eax@7
  int v4; // ebp@9
  FARPROC v5; // edi@13
  FARPROC v6; // esi@15
  signed int v7; // ebx@17
  int v8; // eax@19
  int v9; // eax@23
  int v10; // eax@26
  int v11; // [sp+10h] [bp-14h]@9
  FARPROC v12; // [sp+14h] [bp-10h]@5
  int v13; // [sp+18h] [bp-Ch]@9
  int v14; // [sp+1Ch] [bp-8h]@24
  int v15; // [sp+20h] [bp-4h]@1

  v15 = 0;
  if ( _ms_p5_test_fdiv() )
  {
    result = 1;
  }
  else
  {
    v1 = GetModuleHandleA("KERNEL32");
    v2 = v1;
    if ( v1 )
    {
      v12 = GetProcAddress(v1, "GetProcessAffinityMask");
      if ( v12 )
      {
        v3 = GetProcAddress(v2, "GetCurrentProcess");
        if ( v3 )
        {
          v4 = v3();
          if ( ((int (__stdcall *)(int, int *, int *))v12)(v4, &v13, &v11) )
          {
            if ( v11 == 1 )
            {
              result = 0;
            }
            else
            {
              v5 = GetProcAddress(v2, "SetThreadAffinityMask");
              if ( v5 )
              {
                v6 = GetProcAddress(v2, "GetCurrentThread");
                if ( v6 )
                {
                  v7 = 0;
                  while ( 1 )
                  {
                    if ( (1 << v7) & v11 )
                    {
                      v8 = ((int (__stdcall *)(signed int))v6)(1 << v7);
                      ((void (__stdcall *)(int))v5)(v8);
                      if ( _ms_p5_test_fdiv() )
                        break;
                    }
                    ++v7;
                    if ( v7 >= 32 )
                      goto LABEL_23;
                  }
                  v15 = 1;
LABEL_23:
                  v9 = ((int (__stdcall *)(int))v6)(v13);
                  if ( !((int (__stdcall *)(int))v5)(v9) )
                  {
                    if ( !((int (__stdcall *)(int, int *, int *))v12)(v4, &v14, &v11) )
                      v14 = v13;
                    v10 = ((int (__stdcall *)(int))v6)(v14);
                    ((void (__stdcall *)(int))v5)(v10);
                  }
                  result = v15;
                }
                else
                {
                  result = 0;
                }
              }
              else
              {
                result = 0;
              }
            }
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

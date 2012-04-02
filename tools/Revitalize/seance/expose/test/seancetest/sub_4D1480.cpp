int __fastcall sub_4D1480(signed int a1, signed int a2, int a3)
{
  int result; // eax@1
  int v4; // [sp-4h] [bp-Ch]@12

  result = dword_51F6F4;
  if ( !dword_51F6F4 )
  {
    result = 28 * gameOrEditorIdx;
    if ( !*(&mainWindows + 7 * gameOrEditorIdx + 5) || a3 )
    {
      if ( *(BOOL *)((char *)&mainWindows + result + 24) )
      {
        dword_51F6F4 = 1;
        if ( a3 || a1 >= 0 && a1 < 640 && a2 >= 0 && a2 < 480 )
        {
          if ( dword_51F6EC )
          {
            dword_51F6EC = 0;
            MouseManager::setSpriteIdx(mouseManager, 1000);
          }
          result = dword_51F6F0;
          if ( dword_51F6F0 == dword_4F19B0 )
            goto LABEL_18;
          v4 = 1;
        }
        else
        {
          result = dword_51F6EC;
          if ( dword_51F6EC )
            goto LABEL_18;
          dword_51F6EC = 1;
          dword_51F6F0 = dword_4F19B0;
          if ( !dword_4F19B0 )
            goto LABEL_18;
          v4 = 0;
        }
        result = sub_4CEB90(mouseManager, v4);
LABEL_18:
        dword_51F6F4 = 0;
        return result;
      }
    }
  }
  return result;
}

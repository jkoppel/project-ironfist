int __fastcall sub_4AA7B0(int a1, int a2)
{
  int result; // eax@2
  int v3; // [sp+Ch] [bp-14h]@1
  int v4; // [sp+14h] [bp-Ch]@5
  int v5; // [sp+18h] [bp-8h]@5
  int v6; // [sp+1Ch] [bp-4h]@5

  v3 = a2;
  if ( getTickCount() > dword_51D5C8 + 15 || (result = getTickCount(), result > animationFrameSwitchTime) )
  {
    passOnMessages();
    yieldToGlobalUpdater();
    if ( getTickCount() > animationFrameSwitchTime )
    {
      if ( !v3 )
      {
        v4 = dword_524C14;
        v6 = *(_DWORD *)&advManager->_2[0];
        v5 = *(_DWORD *)&advManager->_2[4];
        dword_4F2AE4 = 1;
        dword_524C14 = !*(_DWORD *)&blackoutComputer && !dword_4F7494;
        if ( !dword_524C14 )
          dword_523F0C = 1;
        if ( sub_451D70(advManager, *(_DWORD *)&advManager->_2[0], *(_DWORD *)&advManager->_2[4], 0) )
          sub_447A00(advManager, 0, 0);
        else
          sub_44D440(advManager, 0, 1, 1);
        dword_524C14 = v4;
        dword_4F2AE4 = 0;
        dword_523F0C = 0;
        *(_DWORD *)&advManager->_2[0] = v6;
        *(_DWORD *)&advManager->_2[4] = v5;
      }
      animationFrameSwitchTime = getTickCount() + 120;
    }
    result = getTickCount();
    dword_51D5C8 = result;
  }
  return result;
}

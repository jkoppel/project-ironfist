void __cdecl _unlock(int a1)
{
  LeaveCriticalSection(*(&dword_520D58 + a1));
}

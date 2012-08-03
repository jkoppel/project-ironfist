{
  signed int result; // eax@2

  if ( a2 == 272 )
  {
    result = 1;
  }
  else
  {
    if ( a2 == 273 )
    {
      if ( a3 == 1 )
        EndDialog(hDlg, 1);
    }
    PollSound();
    result = 0;
  }
  return result;
}
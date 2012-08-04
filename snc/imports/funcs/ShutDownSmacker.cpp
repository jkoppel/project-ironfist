{
  int result; // eax@2

  if ( smk1 )
    result = SmackClose(smk1);
  smk1 = 0;
  if ( smk2 )
    result = SmackClose(smk2);
  smk2 = 0;
  return result;
}
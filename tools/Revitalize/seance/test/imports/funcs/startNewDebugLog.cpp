{
  int v0; // ebx@2
  char v1[500]; // [sp+Ch] [bp-1F4h]@3

  if ( debugLogLevel >= 2 )
  {
    v0 = _open("KB.LOG", 17153, 128);
    if ( v0 != -1 )
    {
      strcpy(v1, "===========New Log==========");
      *(_WORD *)&v1[strlen(v1)] = word_51EFC8;
      _write(v0, v1, strlen(v1));
      _close(v0);
    }
  }
}

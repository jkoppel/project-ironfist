{
  void *v1; // ST24_4@1
  char *v2; // eax@1
  char thisa; // [sp+10h] [bp-3ECh]@1
  int v4; // [sp+204h] [bp-1F8h]@1
  char prefix; // [sp+208h] [bp-1F4h]@1

  v1 = this;
  v4 = *_errno();
  v2 = strerror(v4);
  sprintf(&prefix, "File Error %s", v2);
  logUpTo7Ints((int)&prefix, v4, -999, -999, -999, -999, -999, -999);
  sprintf(&thisa, "Error opening file %s!", v1);
  terminate(&thisa);
}

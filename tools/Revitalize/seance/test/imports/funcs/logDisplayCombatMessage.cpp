{
  char str; // [sp+10h] [bp-2BCh]@1

  sprintf(&str, "NC: %s", msg);
  debugLog(&str);
}

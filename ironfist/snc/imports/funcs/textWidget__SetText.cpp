{
  __int16 result; // ax@1
  textWidget *thisa; // ebx@1
  unsigned int len; // esi@4
  unsigned int v5; // ecx@6

  result = this->field_14;
  thisa = this;
  if ( result == 512 || result == 16384 )
  {
    len = (unsigned __int16)strlen(str);
    if ( strlen(thisa->content) < len )
    {
      BaseFree(thisa->content, (int)"F:\\h2xsrc\\Base\\TEXTWDGT.CPP", 211);
      thisa->content = (char *)BaseAlloc(len + 5, "F:\\h2xsrc\\Base\\TEXTWDGT.CPP", 212);
    }
    v5 = strlen(str) + 1;
    result = v5;
    memcpy(thisa->content, str, v5);
  }
  else
  {
    this->content = (char *)str;
  }
  return result;
}
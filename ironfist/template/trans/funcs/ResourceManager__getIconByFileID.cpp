{
  Icon *icon;

  icon = (Icon *)this->findLoadedFile(fileID);
  if ( icon )
  {
    ++icon->referenceCount;
  }
  else
  {
    icon = new Icon;
    if ( icon )
      icon = Icon_constructor(icon, fileID);
    else
      icon = NULL;
    this->prependFileLinkedListNode((AbstractResource *)icon);
  }
  return icon;
}

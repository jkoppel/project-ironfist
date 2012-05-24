Icon *__thiscall ResourceManager::getIconByFileID(ResourceManager *this, int fileID)
{
  Icon *icon; // eax@2 MAPDST

  icon = (Icon *)ResourceManager::findLoadedFile(this, fileID);
  if ( icon )
  {
    ++icon->referenceCount;
  }
  else
  {
    icon = (Icon *)operator new(sizeof(Icon));
    if ( icon )
      icon = Icon_constructor(icon, fileID);
    else
      icon = NULL;
    ResourceManager::prependFileLinkedListNode(this, (AbstractResource *)icon);
  }
  return icon;
}

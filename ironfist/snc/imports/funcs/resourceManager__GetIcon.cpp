{
  icon *icon; // eax@2 MAPDST

  icon = (icon *)resourceManager::Query(this, fileID);
  if ( icon )
  {
    ++icon->referenceCount;
  }
  else
  {
    icon = (icon *)operator new(sizeof(icon));
    if ( icon )
      icon = icon::icon(icon, fileID);
    else
      icon = NULL;
    resourceManager::AddResource(this, (resource *)icon);
  }
  return icon;
}
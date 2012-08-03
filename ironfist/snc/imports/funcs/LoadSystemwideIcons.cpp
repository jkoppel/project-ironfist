{
  icon *result; // eax@1

  gBuyBuildIcons = resourceManager::GetIcon(gpResourceManager, "buybuild.icn");
  result = resourceManager::GetIcon(gpResourceManager, "system.icn");
  gSystemIcons = result;
  return result;
}
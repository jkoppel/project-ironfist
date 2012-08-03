{
  icon *icn; // ST20_4@2
  unsigned int bmpHash; // eax@3

  if ( isICN )
  {
    icn = resourceManager::GetIcon(this, filename);
    icon::DrawToBuffer(icn, 0, 0, 0, 0);
    resourceManager::Dispose(this, (resource *)icn);
  }
  else
  {
    bmpHash = resourceManager::MakeId(this, filename, 1);
    resourceManager::PointToFile(this, bmpHash);
    resourceManager::ReadWord(this);
    resourceManager::ReadWord(this);
    resourceManager::ReadWord(this);
    resourceManager::ReadBlock(this, screenBuf->contents, screenBuf->width * screenBuf->height);
  }
}
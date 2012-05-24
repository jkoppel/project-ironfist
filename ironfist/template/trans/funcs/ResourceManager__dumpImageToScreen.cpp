{
  Icon *icn; // ST20_4@2
  unsigned int bmpHash; // eax@3

  if ( isICN )
  {
    icn = this->getIconByFilename(filename);
    Icon::drawToScreen(icn, 0, 0, 0, 0);
    this->reduceReferenceCountToResource((AbstractResource *)icn);
  }
  else
  {
    bmpHash = this->setResource(filename, 1);
    this->pointToFile(bmpHash);
    this->readShort();
    this->readShort();
    this->readShort();
    this->readFromCurrentFile(screenBuf->contents, screenBuf->width * screenBuf->height);
  }
}

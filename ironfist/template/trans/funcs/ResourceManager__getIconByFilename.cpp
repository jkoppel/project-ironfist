{
  unsigned int hash;

  hash = this->setResource(filename, 1);
  return this->getIconByFileID(hash);
}

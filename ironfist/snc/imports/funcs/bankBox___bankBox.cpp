{
  bankBox *thisa; // ST10_4@1

  thisa = this;
  heroWindowManager::RemoveWindow(gpWindowManager, this->window);
  return operator delete(thisa->window);
}
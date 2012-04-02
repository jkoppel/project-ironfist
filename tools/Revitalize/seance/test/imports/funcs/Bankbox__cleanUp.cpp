{
  Bankbox *thisa; // ST10_4@1

  thisa = this;
  HeroWindowManager::removeWindow(HeroWindowManager::instance, this->window);
  return operator delete(thisa->window);
}

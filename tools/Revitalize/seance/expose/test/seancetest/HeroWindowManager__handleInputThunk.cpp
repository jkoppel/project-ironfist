int __thiscall HeroWindowManager::handleInputThunk(HeroWindowManager *this, InputEvent *a2)
{
  return this->vtable->handleInput((AbstractManager *)this, a2);
}

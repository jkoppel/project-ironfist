void __thiscall Font_destructor(Font *this)
{
  Font *v1; // ST10_4@1

  v1 = this;
  this->vtable = &Font_vtable;
  ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)this->icon);
  AbstractResource_destructor(v1);
}

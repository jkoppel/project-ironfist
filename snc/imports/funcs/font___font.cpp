{
  font *v1; // ST10_4@1

  v1 = this;
  this->vtable = &font::_vftable_;
  resourceManager::Dispose(gpResourceManager, (resource *)this->icon);
  resource::_resource(v1);
}
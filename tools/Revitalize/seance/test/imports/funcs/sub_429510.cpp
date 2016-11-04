{
  Icon *v0; // ST34_4@2

  if ( !advManager->field_37A )
  {
    advManager->field_37A = 1;
    v0 = ResourceManager::getIconByFilename(resourceManager, "herologo.icn");
    rasterize(v0, HeroWindowManager::instance->screenBuffer, 480, 16, 0, 0, 0, 0, 0x280u, 480, 0);
    HeroWindowManager::redrawRectangle(HeroWindowManager::instance, 480, 16, 0x90u, 144);
    ResourceManager::reduceReferenceCountToResource(resourceManager, (AbstractResource *)v0);
  }
}

{
  icon *v0; // ST34_4@2

  if ( !gpAdvManager->field_37A )
  {
    gpAdvManager->field_37A = 1;
    v0 = resourceManager::GetIcon(gpResourceManager, "herologo.icn");
    IconToBitmap(v0, gpWindowManager->screenBuffer, 480, 16, 0, 0, 0, 0, 0x280u, 480, 0);
    heroWindowManager::UpdateScreenRegion(gpWindowManager, 480, 16, 0x90u, 144);
    resourceManager::Dispose(gpResourceManager, (resource *)v0);
  }
}
{
  heroWindowManager *v1; // esi@1
  char filename; // [sp+4h] [bp-10h]@1

  v1 = this;
  sprintf(&filename, "SHOT%04d.PCX", this->numScreenshots);
  CreatePCXFile(&filename, v1->screenBuffer->contents, 640, 480, gPalette->contents);
  ++v1->numScreenshots;
  return inputManager::Flush(gpInputManager);
}
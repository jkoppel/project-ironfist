{
  heroWindowManager *v1; // esi@1
  resource *v2; // ecx@1
  int result; // eax@2

  v1 = this;
  v2 = (resource *)this->someBMP;
  if ( v2 )
    result = v2->vtable->cleanUp(v2, 1);
  v1->someBMP = 0;
  return result;
}
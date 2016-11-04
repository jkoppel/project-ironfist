{
  Sample *thisa; // ebx@1
  int fileID; // eax@1
  signed int v7; // ebp@1
  signed int v8; // eax@1
  int fileIDa; // ST0C_4@10
  size_t v10; // eax@10
  unsigned int size; // esi@10
  void *v12; // eax@10
  int fileIDb; // ecx@10
  char v15[32]; // [sp+10h] [bp-20h]@1

  thisa = this;
  fileID = ResourceManager::setResource(resourceManager, filename, 1);
  AbstractResource_constructor((AbstractResource *)thisa, RESOURCE_TYPE_SAMPLE, fileID, 1, NULL);
  v7 = 2;
  thisa->vtable = &Sample_vtable;
  thisa->codeThing = a3;
  thisa->field_28 = a4;
  thisa->loopCount = a5;
  strcpy(v15, filename);
  _strrev(v15);
  v8 = 0;
  do
  {
    switch ( v15[v8] )
    {
      case '1':
        thisa->playbackRate = 11025;
        break;
      case '2':
        thisa->playbackRate = 22050;
        break;
      case '4':
        thisa->playbackRate = 44100;
        break;
      case '6':
        thisa->sampleType = 1;
        break;
      case '8':
        thisa->sampleType = 0;
        break;
      case 'M':
      case 'm':
        v7 = 0;
        break;
      default:
        break;
    }
    ++v8;
  }
  while ( v8 < 3 );
  fileIDa = thisa->fileID;
  thisa->sampleType += v7;
  v10 = ResourceManager::getFileSize(resourceManager, fileIDa);
  size = v10;
  v12 = KBAlloc(v10, "F:\\h2xsrc\\Base\\SAMPLE.CPP", 57);
  fileIDb = thisa->fileID;
  thisa->contents = v12;
  thisa->nbytes = size;
  ResourceManager::pointToFile(resourceManager, fileIDb);
  ResourceManager::readFromCurrentFile(resourceManager, thisa->contents, size);
  return thisa;
}

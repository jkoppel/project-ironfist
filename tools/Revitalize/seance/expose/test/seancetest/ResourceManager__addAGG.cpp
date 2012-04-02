signed int __thiscall ResourceManager::addAGG(ResourceManager *this, const char *filename)
{
  signed int result; // eax@2
  size_t v3; // ST1C_4@5
  ResourceManager *v4; // [sp+Ch] [bp-10h]@1
  __int16 buf; // [sp+14h] [bp-8h]@5
  int v6; // [sp+18h] [bp-4h]@3

  v4 = this;
  if ( this->numOpenAGGFiles < SEEK_END )
  {
    v6 = _open(filename, O_BINARY);
    if ( v6 == -1 )
    {
      sprintf(globBuf, "Can't open file: %s", filename);
      terminate(globBuf);
      result = 3;
    }
    else
    {
      v4->curHandleIdx = v4->numOpenAGGFiles++;
      v4->fileDescriptors[v4->curHandleIdx] = v6;
      _read(v4->fileDescriptors[v4->curHandleIdx], &buf, 2u);
      v4->numberOfFilesInAGG[v4->curHandleIdx] = buf;
      v3 = 12 * v4->numberOfFilesInAGG[v4->curHandleIdx];
      v4->aggContentInfo[v4->curHandleIdx] = (FileInAGGInfo *)KBAlloc(v3, "F:\\h2xsrc\\Base\\RESMGR.CPP", 542);
      _read(v4->fileDescriptors[v4->curHandleIdx], v4->aggContentInfo[v4->curHandleIdx], v3);
      result = 0;
    }
  }
  else
  {
    sprintf(globBuf, "Only %d .AGG files can be used at once.", SEEK_END);
    terminate(globBuf);
    result = 3;
  }
  return result;
}

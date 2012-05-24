MANAGER_RETURN_CODE __thiscall ResourceManager::addAGG(ResourceManager *this, const char *filename)
{
  MANAGER_RETURN_CODE result; // eax@2
  int headerSize; // ST1C_4@5
  __int16 numFiles; // [sp+14h] [bp-8h]@5
  int fd; // [sp+18h] [bp-4h]@3

  if ( this->numOpenAGGFiles < NUM_AGG_FILES )
  {
    fd = _open(filename, O_BINARY);
    if ( fd == -1 )
    {
      sprintf(globBuf, "Can't open file: %s", filename);
      terminate(globBuf);
      result = MANAGER_FAILED;
    }
    else
    {
      this->curHandleIdx = this->numOpenAGGFiles++;
      this->fileDescriptors[this->curHandleIdx] = fd;
      _read(this->fileDescriptors[this->curHandleIdx], &numFiles, 2u);
      this->numberOfFilesInAGG[this->curHandleIdx] = numFiles;
      headerSize = 12 * this->numberOfFilesInAGG[this->curHandleIdx];
      this->aggContentInfo[this->curHandleIdx] = (FileInAGGInfo *)KBAlloc(
                                                                    headerSize,
                                                                    "F:\\h2xsrc\\Base\\RESMGR.CPP",
                                                                    542);
      _read(this->fileDescriptors[this->curHandleIdx], this->aggContentInfo[this->curHandleIdx], headerSize);
      result = MANAGER_SUCCESS;
    }
  }
  else
  {
    sprintf(globBuf, "Only %d .AGG files can be used at once.", NUM_AGG_FILES);
    terminate(globBuf);
    result = MANAGER_FAILED;
  }
  return result;
}

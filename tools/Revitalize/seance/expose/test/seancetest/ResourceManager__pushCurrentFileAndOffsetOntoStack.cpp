int __thiscall ResourceManager::pushCurrentFileAndOffsetOntoStack(ResourceManager *this)
{
  ResourceManager *v1; // ST10_4@1
  int result; // eax@1

  v1 = this;
  fileOffsetStack[indexOfFileOffsetStack] = getFileOffset(this->fileDescriptors[this->curHandleIdx]);
  result = v1->curHandleIdx;
  handleIndicesStack[indexOfFileOffsetStack++] = result;
  return result;
}

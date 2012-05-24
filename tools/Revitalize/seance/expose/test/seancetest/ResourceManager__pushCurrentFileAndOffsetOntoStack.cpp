void __thiscall ResourceManager::pushCurrentFileAndOffsetOntoStack(ResourceManager *this)
{
  fileOffsetStack[indexOfFileOffsetStack] = getFileOffset(this->fileDescriptors[this->curHandleIdx]);
  handleIndicesStack[indexOfFileOffsetStack++] = this->curHandleIdx;
}

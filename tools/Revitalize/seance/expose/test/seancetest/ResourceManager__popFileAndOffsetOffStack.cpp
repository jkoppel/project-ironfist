__int32 __thiscall ResourceManager::popFileAndOffsetOffStack(ResourceManager *this)
{
  --indexOfFileOffsetStack;
  this->curHandleIdx = handleIndicesStack[indexOfFileOffsetStack];
  return _lseek(this->fileDescriptors[this->curHandleIdx], fileOffsetStack[indexOfFileOffsetStack], SEEK_SET);
}

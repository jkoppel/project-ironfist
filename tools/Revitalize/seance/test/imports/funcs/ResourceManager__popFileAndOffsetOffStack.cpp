{
  --indexOfFileOffsetStack;
  this->curHandleIdx = handleIndicesStack[indexOfFileOffsetStack];
  return _lseek(this->fileDescriptors[this->curHandleIdx], fileOffsetStack[indexOfFileOffsetStack], SEEK_SET);
}

{
  --indexOfFileOffsetStack;
  this->curHandleIdx = handleIndicesStack[indexOfFileOffsetStack];
  _lseek(this->fileDescriptors[this->curHandleIdx], fileOffsetStack[indexOfFileOffsetStack], SEEK_SET);
}

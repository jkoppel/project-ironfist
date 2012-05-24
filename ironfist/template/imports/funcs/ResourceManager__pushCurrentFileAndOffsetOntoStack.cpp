{
  fileOffsetStack[indexOfFileOffsetStack] = getFileOffset(this->fileDescriptors[this->curHandleIdx]);
  handleIndicesStack[indexOfFileOffsetStack++] = this->curHandleIdx;
}

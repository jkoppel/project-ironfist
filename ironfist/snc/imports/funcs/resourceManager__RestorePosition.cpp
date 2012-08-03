{
  --iSaveCtr;
  this->curHandleIdx = lastAggZ[iSaveCtr];
  _lseek(this->fileDescriptors[this->curHandleIdx], lastPositionZ[iSaveCtr], SEEK_SET);
}
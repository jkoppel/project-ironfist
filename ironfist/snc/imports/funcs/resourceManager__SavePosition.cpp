{
  lastPositionZ[iSaveCtr] = tell(this->fileDescriptors[this->curHandleIdx]);
  lastAggZ[iSaveCtr++] = this->curHandleIdx;
}
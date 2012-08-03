void __fastcall CreatureForm::constructWalkingAnimationFromComponents(CreatureForm *this, int last, int notFirst)
{
  this->animationLengths[6] = 0;
  if ( notFirst || !last )
  {
    if ( notFirst )
    {
      if ( this->animationLengths[1] > 0 )
      {
        memcpy(
          &this->animationFrameToImgIdx[6][this->animationLengths[6]],
          this->animationFrameToImgIdx[1],
          this->animationLengths[1]);
        memcpy(&this->anim6info[this->animationLengths[6]], this->anim1Info, this->animationLengths[1]);
        this->animationLengths[6] += this->animationLengths[1];
      }
    }
    else
    {
      if ( this->animationLengths[0] > 0 )
      {
        memcpy(
          &this->animationFrameToImgIdx[6][this->animationLengths[6]],
          this->animationFrameToImgIdx,
          this->animationLengths[0]);
        memcpy(&this->anim6info[this->animationLengths[6]], this->liftAnimInfo, this->animationLengths[0]);
        this->animationLengths[6] += this->animationLengths[0];
      }
    }
    if ( this->animationLengths[2] > 0 )
    {
      memcpy(
        &this->animationFrameToImgIdx[6][this->animationLengths[6]],
        this->animationFrameToImgIdx[2],
        this->animationLengths[2]);
      memcpy(&this->anim6info[this->animationLengths[6]], this->flyAnimInfo, this->animationLengths[2]);
      this->animationLengths[6] += this->animationLengths[2];
    }
    if ( last )
    {
      if ( this->animationLengths[4] > 0 )
      {
        memcpy(
          &this->animationFrameToImgIdx[6][this->animationLengths[6]],
          this->animationFrameToImgIdx[4],
          this->animationLengths[4]);
        memcpy(&this->anim6info[this->animationLengths[6]], this->landAnimInfo, this->animationLengths[4]);
        this->animationLengths[6] += this->animationLengths[4];
      }
    }
    else
    {
      if ( this->animationLengths[3] > 0 )
      {
        memcpy(
          &this->animationFrameToImgIdx[6][this->animationLengths[6]],
          this->animationFrameToImgIdx[3],
          this->animationLengths[3]);
        memcpy(&this->anim6info[this->animationLengths[6]], this->anim3Info, this->animationLengths[3]);
        this->animationLengths[6] += this->animationLengths[3];
      }
    }
  }
  else
  {
    if ( this->animationLengths[5] > 0 )
    {
      memcpy(
        &this->animationFrameToImgIdx[6][this->animationLengths[6]],
        this->animationFrameToImgIdx[5],
        this->animationLengths[5]);
      memcpy(&this->anim6info[this->animationLengths[6]], this->anim5Info, this->animationLengths[5]);
      this->animationLengths[6] += this->animationLengths[5];
    }
  }
}

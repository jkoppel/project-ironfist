void __fastcall CreatureForm::doSomething(CreatureForm *form, int a2, int a3)
{
  int a2a; // [sp+Ch] [bp-8h]@1
  CreatureForm *forma; // [sp+10h] [bp-4h]@1

  a2a = a2;
  forma = form;
  form->animationLengths[6] = 0;
  if ( a3 || !a2 )
  {
    if ( a3 )
    {
      if ( form->animationLengths[1] > 0 )
      {
        memcpy(
          &form->animationFrameToImgIdx[6][form->animationLengths[6]],
          form->animationFrameToImgIdx[1],
          form->animationLengths[1]);
        memcpy(&forma->field_65[forma->animationLengths[6]], forma->anim1Info, forma->animationLengths[1]);
        forma->animationLengths[6] += forma->animationLengths[1];
      }
    }
    else
    {
      if ( form->animationLengths[0] > 0 )
      {
        memcpy(
          &form->animationFrameToImgIdx[6][form->animationLengths[6]],
          form->animationFrameToImgIdx,
          form->animationLengths[0]);
        memcpy(&forma->field_65[forma->animationLengths[6]], forma->liftAnimInfo, forma->animationLengths[0]);
        forma->animationLengths[6] += forma->animationLengths[0];
      }
    }
    if ( forma->animationLengths[2] > 0 )
    {
      memcpy(
        &forma->animationFrameToImgIdx[6][forma->animationLengths[6]],
        forma->animationFrameToImgIdx[2],
        forma->animationLengths[2]);
      memcpy(&forma->field_65[forma->animationLengths[6]], forma->flyAnimInfo, forma->animationLengths[2]);
      forma->animationLengths[6] += forma->animationLengths[2];
    }
    if ( a2a )
    {
      if ( forma->animationLengths[4] > 0 )
      {
        memcpy(
          &forma->animationFrameToImgIdx[6][forma->animationLengths[6]],
          forma->animationFrameToImgIdx[4],
          forma->animationLengths[4]);
        memcpy(&forma->field_65[forma->animationLengths[6]], forma->landAnimInfo, forma->animationLengths[4]);
        forma->animationLengths[6] += forma->animationLengths[4];
      }
    }
    else
    {
      if ( forma->animationLengths[3] > 0 )
      {
        memcpy(
          &forma->animationFrameToImgIdx[6][forma->animationLengths[6]],
          forma->animationFrameToImgIdx[3],
          forma->animationLengths[3]);
        memcpy(&forma->field_65[forma->animationLengths[6]], forma->anim3Info, forma->animationLengths[3]);
        forma->animationLengths[6] += forma->animationLengths[3];
      }
    }
  }
  else
  {
    if ( form->animationLengths[5] > 0 )
    {
      memcpy(
        &form->animationFrameToImgIdx[6][form->animationLengths[6]],
        form->animationFrameToImgIdx[5],
        form->animationLengths[5]);
      memcpy(&forma->field_65[forma->animationLengths[6]], forma->anim5Info, forma->animationLengths[5]);
      forma->animationLengths[6] += forma->animationLengths[5];
    }
  }
}

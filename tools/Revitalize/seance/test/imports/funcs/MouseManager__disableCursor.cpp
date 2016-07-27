{
  int v1; // eax@1

  v1 = this->cursorDisabled + 1;
  this->cursorDisabled = v1;
  if ( v1 == 1 )
    sub_4CE410(this, 1);
}

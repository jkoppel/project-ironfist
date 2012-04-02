Hero *__thiscall sub_495CC0(Hero *this)
{
  Hero *result; // eax@23

  *(_WORD *)&this->_2[3] = -99;
  *(_WORD *)&this->_2[0] = -99;
  if ( this->flags1 & 0x20 )
  {
    ++this->_5[1];
    *(_DWORD *)&this->flags1 -= 32;
  }
  if ( this->flags1 & 0x40 )
  {
    ++this->_5[1];
    *(_DWORD *)&this->flags1 -= 64;
  }
  if ( this->flags1 & 2 )
  {
    --this->_5[1];
    *(_DWORD *)&this->flags1 -= 2;
  }
  if ( this->flags1 & 8 )
  {
    --this->_5[1];
    *(_DWORD *)&this->flags1 -= 8;
  }
  if ( this->flags2 & 1 )
  {
    this->_5[1] -= 2;
    *(_DWORD *)&this->flags1 -= 256;
  }
  if ( this->flags1 & 0x10 )
  {
    --this->_5[2];
    *(_DWORD *)&this->flags1 -= 16;
  }
  if ( this->flags2 & 0x20 )
  {
    --this->_5[2];
    *(_DWORD *)&this->flags1 -= 8192;
  }
  if ( this->flags1 & 4 )
  {
    --this->_5[2];
    *(_DWORD *)&this->flags1 -= 4;
  }
  if ( this->flags2 & 2 )
  {
    --this->_5[1];
    *(_DWORD *)&this->flags1 -= 512;
  }
  if ( this->flags2 & 4 )
  {
    ++this->_5[1];
    *(_DWORD *)&this->flags1 -= 1024;
  }
  if ( this->flags2 & 0x40 )
  {
    this->_5[2] += 2;
    *(_DWORD *)&this->flags1 -= 16384;
  }
  result = this;
  if ( this->flags3 & 0x10 )
  {
    --this->_5[2];
    result = (Hero *)(*(_DWORD *)&this->flags1 - 1048576);
    *(_DWORD *)&this->flags1 = result;
  }
  return result;
}

{
  palette *pal; // eax@2 MAPDST
  unsigned int fileID; // [sp+14h] [bp-8h]@1

  fileID = this->MakeId(filename, 1);
  pal = this->Query(fileID);
  if ( pal )
  {
    ++pal->referenceCount;
  }
  else
  {
    pal = new palette(fileID);
    this->AddResource((resource *)pal);
  }
  return pal;
}

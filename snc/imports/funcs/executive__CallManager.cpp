{
  baseManager *v2; // ebx@1
  executive *v3; // edi@1

  v2 = this->currentManager;
  v3 = this;
  executive::RemoveManager(this, this->currentManager);
  if ( executive::AddManager(v3, man, -1) )
    ShutDown("Can't add manager!");
  executive::MainLoop(v3);
  executive::RemoveManager(v3, man);
  if ( executive::AddManager(v3, v2, -1) )
    ShutDown("Can't add manager!");
  v3->currentManager = v2;
}
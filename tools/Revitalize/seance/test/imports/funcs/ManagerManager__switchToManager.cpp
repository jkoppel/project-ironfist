{
  AbstractManager *v2; // ebx@1
  ManagerManager *v3; // edi@1

  v2 = this->currentManager;
  v3 = this;
  ManagerManager__removeManager(this, this->currentManager);
  if ( ManagerManager::addManager(v3, man, -1) )
    terminate("Can't add manager!");
  ManagerManager::sendInputToManagers(v3);
  ManagerManager__removeManager(v3, man);
  if ( ManagerManager::addManager(v3, v2, -1) )
    terminate("Can't add manager!");
  v3->currentManager = v2;
}

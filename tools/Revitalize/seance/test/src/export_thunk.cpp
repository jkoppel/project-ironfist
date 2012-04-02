extern "C" ResourceManager * __fastcall ResourceManager__constructor(ResourceManager * __this,int ) {
	__this->constructor();
}
extern "C" void __fastcall ResourceManager__destructor(ResourceManager * __this,int ) {
	__this->destructor();
}
extern "C" unsigned int __fastcall ResourceManager__setResource(ResourceManager * __this,int , const char * filename, int  useEvilersion) {
	__this->setResource(filename,useEvilersion);
}
extern "C" signed int __fastcall ResourceManager__addAGG(ResourceManager * __this,int , const char * filename) {
	__this->addAGG(filename);
}
extern "C" int __fastcall SoundManager__initialize(SoundManager * __this,int , int  a2) {
	__this->initialize(a2);
}

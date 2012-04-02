#ifndef EXPORT
#define EXPORT

#include "resource\resources.h"

extern "C" void* __cdecl op_new(unsigned int x) {
	return operator new(x);
}

extern "C" void __cdecl op_del(void* x) {
	operator delete(x);
}

extern "C" ResourceManager* __fastcall ResourceManager_constructor_exp(ResourceManager *__this) {
	return ResourceManager_constructor(__this);
}

extern "C" unsigned int __fastcall ResourceManager__setResource(ResourceManager * __this,int , const char * filename, int  useEvilersion) {
	return __this->setResource(filename,useEvilersion);
}
extern "C" MANAGER_RETURN_CODE __fastcall ResourceManager__addAGG(ResourceManager * __this,int , const char * filename) {
	return __this->addAGG(filename);
}

extern "C" void __fastcall ResourceManager__dumpImageToScreen(ResourceManager * __this,int ,  char * filename, Bitmap * screenBuf, int  isICN) {
	__this->dumpImageToScreen(filename,screenBuf,isICN);
}
extern "C" AbstractResource * __fastcall ResourceManager__findLoadedFile(ResourceManager * __this,int , unsigned int  fileHash) {
	return __this->findLoadedFile(fileHash);
}
extern "C" void __fastcall ResourceManager__freeAllResources(ResourceManager * __this,int ) {
	__this->freeAllResources();
}
extern "C" Bitmap * __fastcall ResourceManager__getBitmapByFilename(ResourceManager * __this,int ,  char * filename) {
	return __this->getBitmapByFilename(filename);
}
extern "C" int __fastcall ResourceManager__getFileSize(ResourceManager * __this,int , int  fileHash) {
	return __this->getFileSize(fileHash);
}
extern "C" Font * __fastcall ResourceManager__getFontByFilename(ResourceManager * __this,int , const char * filename) {
	return __this->getFontByFilename(filename);
}
extern "C" Icon * __fastcall ResourceManager__getIconByFileID(ResourceManager * __this,int , int  fileID) {
	return __this->getIconByFileID(fileID);
}
extern "C" Icon * __fastcall ResourceManager__getIconByFilename(ResourceManager * __this,int ,  char * filename) {
	return __this->getIconByFilename(filename);
}
extern "C" Palette * __fastcall ResourceManager__getPal(ResourceManager * __this,int , const char * file) {
	return __this->getPal(file);
}
extern "C" Sample * __fastcall ResourceManager__getSampleByFilename(ResourceManager * __this,int ,  char * filename) {
	return __this->getSampleByFilename(filename);
}
extern "C" Sequence * __fastcall ResourceManager__getSequenceByFilename(ResourceManager * __this,int ,  char * filename) {
	return __this->getSequenceByFilename(filename);
}
extern "C" Tileset * __fastcall ResourceManager__getTilesetByFilename(ResourceManager * __this,int ,  char * filename) {
	return __this->getTilesetByFilename(filename);
}
extern "C" MANAGER_RETURN_CODE __fastcall ResourceManager__handleInput(ResourceManager * __this,int , InputEvent * a1) {
	return __this->handleInput(a1);
}
extern "C" MANAGER_RETURN_CODE __fastcall ResourceManager__initialize(ResourceManager * __this,int , int  idx) {
	return __this->initialize(idx);
}
extern "C" signed int __fastcall ResourceManager__pointToFile(ResourceManager * __this,int , int  id) {
	return __this->pointToFile(id);
}
extern "C" void __fastcall ResourceManager__popFileAndOffsetOffStack(ResourceManager * __this,int ) {
	__this->popFileAndOffsetOffStack();
}
extern "C" void __fastcall ResourceManager__prependFileLinkedListNode(ResourceManager * __this,int , AbstractResource * res) {
	__this->prependFileLinkedListNode(res);
}
extern "C" void __fastcall ResourceManager__pushCurrentFileAndOffsetOntoStack(ResourceManager * __this,int ) {
	__this->pushCurrentFileAndOffsetOntoStack();
}
extern "C" void __fastcall ResourceManager__readFromCurrentFile(ResourceManager * __this,int , void * buf, DWORD  ntoread) {
	__this->readFromCurrentFile(buf,ntoread);
}
extern "C" int __fastcall ResourceManager__readInt(ResourceManager * __this,int ) {
	return __this->readInt();
}
extern "C" void __fastcall ResourceManager__readNexDOSFilename(ResourceManager * __this,int , char * buf) {
	__this->readNexDOSFilename(buf);
}
extern "C" __int16 __fastcall ResourceManager__readShort(ResourceManager * __this,int ) {
	return __this->readShort();
}
extern "C" void __fastcall ResourceManager__reduceReferenceCountToResource(ResourceManager * __this,int , AbstractResource * res) {
	__this->reduceReferenceCountToResource(res);
}

extern "C" void __fastcall ResourceManager__removeFileFromList(ResourceManager * __this,int , AbstractResource * fil) {
	__this->removeFileFromList(fil);
}

#endif
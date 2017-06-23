#include<fcntl.h>
#include<io.h>
#include<string.h>
#include<stdio.h>

#include "base.h"

#include "resourceManager.h"

extern char* EXPANSION_AGGREGATE_NAME;
extern char* DEFAULT_AGGREGATE_NAME;

extern int iSaveCtr;
extern long lastPositionZ[];
extern int lastAggZ[];

int resourceManager::Open(int idx) {
	if(LoadAggregateHeader(".\\DATA\\ironfist.agg")) {
		return MANAGER_FAILED;
	} /*else if(LoadAggregateHeader(EXPANSION_AGGREGATE_NAME)) {
		return MANAGER_FAILED;
	}*/ else if (LoadAggregateHeader(DEFAULT_AGGREGATE_NAME)) {
		return MANAGER_FAILED;
	} else {
		this->type = MANAGER_TYPE_RESOURCE_MAMANGER;
		this->idx = idx;
		this->ready = 1;
		strcpy_s(this->name, _countof(this->name), "resourceManager");
		this->firstLoadedResource = NULL;
		return MANAGER_SUCCESS;
	}
}

resourceManager::resourceManager() {
  this->ready = 0;
  this->firstLoadedResource = NULL;
  this->expunging = 0;
  strcpy_s(this->resourceToLoad, _countof(this->resourceToLoad), "");
  this->fileID = 0;
  for(int i = 0; i < NUM_AGG_FILES; i++) {
    this->fileDescriptors[i] = -1;
    this->aggContentInfo[i] = NULL;
    this->numberOfFilesInAGG[i] = 0;
  }
  this->numOpenAGGFiles = 0;
  this->curHandleIdx = 0;
}

void resourceManager::Close() {
	if(this->ready) {
		Expunge();
		this->firstLoadedResource = 0;
		for(int i = 0; i < NUM_AGG_FILES; ++i) {
			if(this->aggContentInfo[i])
				FREE(this->aggContentInfo[i]);
			if(this->fileDescriptors[i] != -1) {
				_close(this->fileDescriptors[i]);
				this->fileDescriptors[i] = -1;
			}
		}
		this->numOpenAGGFiles = 0;
		this->ready = 0;
	}
}

int resourceManager::Main(tag_message& msg) {
	return MANAGER_SUCCESS;
}

palette* resourceManager::GetPalette(char* filename) {
	palette *pal;
	unsigned int fileID;

	fileID = MakeId(filename, 1);
	pal = (palette *)Query(fileID);
	if(pal) {
		++pal->referenceCount;
	} else {
		pal = new palette(fileID);
		AddResource(pal);
	}
	return pal;
}

tileset* resourceManager::GetTileset(char* filename) {
	unsigned int hash = MakeId(filename, 1);
	tileset *tiles = (tileset*)Query(hash);
	if(tiles) {
		++tiles->referenceCount;
	} else {
		tiles = new tileset(hash);
		AddResource(tiles);
	}
	return tiles;
}

#ifndef EDITOR

sample* resourceManager::GetSample(const std::string &filename) {
	return this->GetSample((char*)filename.c_str());
}

sample* resourceManager::GetSample(char* filename) {
	unsigned int hash = MakeId(filename, 1);
	sample *samp = (sample*)Query(hash);
	if(samp) {
		++samp->referenceCount;
	} else {
		samp = new sample(filename, 0, 127, 1);
		AddResource(samp);
	}
	return samp;
}

MIDIWrap* resourceManager::GetMIDIWrap(char* filename) {
	unsigned int hash = MakeId(filename, 1);
	MIDIWrap *mid = (MIDIWrap*)Query(hash);
	if(mid) {
		++mid->referenceCount;
	} else {
		mid = new MIDIWrap(filename);
		AddResource(mid);
	}
	return mid;
}

#endif


void resourceManager::Dispose(resource* res) {
	if(!this->expunging) {
		if(res != NULL) {
			--res->referenceCount;
			if (res->referenceCount <= 0) {
				RemoveResource(res);
				if(res != NULL) {
					delete res;
				}
			}
		}
	}
}

void resourceManager::AddResource(resource* res) {
	if(this->firstLoadedResource) {
		res->next = this->firstLoadedResource;
		this->firstLoadedResource = res;
	} else {
		this->firstLoadedResource = res;
		this->firstLoadedResource->next = NULL;
	}
}

void resourceManager::Expunge() {
	resource *res;
	resource *next;

	this->expunging = 1;
	for(res = this->firstLoadedResource; res; res = next) {
		next = res->next;
		RemoveResource(res);
		if(res) {
			delete res;
			//res->vtable->scalarDeletingDestructor(res, 1);
		}
	}
	this->expunging = 0;
}

resource* resourceManager::Query(unsigned long hash) {
	resource *cur;
	for(cur = this->firstLoadedResource; cur && cur->fileID != hash; cur = cur->next)
		;
	return cur;
}

void resourceManager::RemoveResource(resource* res) {
	if(this->firstLoadedResource == res) {
		this->firstLoadedResource = res->next;
	} else {
		resource *cur;
		for(cur = this->firstLoadedResource; cur != NULL && cur->next != res; cur = cur->next)
			;
		if(cur)
			cur->next = res->next;
	}
}

int resourceManager::LoadAggregateHeader(char* filename) {
	int headerSize;
	__int16 numFiles; 
	int fd;

	if(this->numOpenAGGFiles < NUM_AGG_FILES) {
		fd = _open(filename, O_BINARY);
		if(fd == -1) {
			sprintf(gText, "Can't open file: %s", filename);
			ShutDown(gText);
			return MANAGER_FAILED;
		} else {
			this->curHandleIdx = this->numOpenAGGFiles++;
			this->fileDescriptors[this->curHandleIdx] = fd;
			_read(fd, &numFiles, sizeof(numFiles));
			this->numberOfFilesInAGG[this->curHandleIdx] = numFiles;
			headerSize = sizeof(AggregateHeader) * numFiles;
			this->aggContentInfo[this->curHandleIdx] = (AggregateHeader *)ALLOC(headerSize);
			_read(fd, this->aggContentInfo[this->curHandleIdx], headerSize);
			return MANAGER_SUCCESS;
		}
	} else {
		sprintf(gText, "Only %d .AGG files can be used at once.", NUM_AGG_FILES);
		ShutDown(gText);
		return MANAGER_FAILED;
	}
}

void resourceManager::PointToFile(unsigned long hash) {
	int filIdx = -1;

	char found = 0;
	for(int i = 0; i < NUM_AGG_FILES ; i++) {
		if(this->aggContentInfo[i]) {
			for(filIdx = 0; filIdx < this->numberOfFilesInAGG[i]; filIdx++) {
				if(this->aggContentInfo[i][filIdx].id == hash) {
					found = 1;
					this->curHandleIdx = i;
					break;
				}
			}
		}
		if(found)
			break;
	}

	if(!found) {
		sprintf(
			gText,
			"ResMgr::PointToFile failure!  ThisFileId:%d  LastFileId:%d  LastFileName:%s",
			hash,
			this->fileID,
			this->resourceToLoad);
		ShutDown(gText);
	}

	_lseek(this->fileDescriptors[this->curHandleIdx], this->aggContentInfo[this->curHandleIdx][filIdx].off, SEEK_SET);
}

unsigned long resourceManager::GetFileSize(unsigned long hash) {
	char found;
	int containingAGG;
	int filIdx;

	found = 0;
	for(int i = 0; i < NUM_AGG_FILES ; i++) {
		if(this->aggContentInfo[i]) {
			for(filIdx = 0; filIdx < this->numberOfFilesInAGG[i]; filIdx++) {
				if (this->aggContentInfo[i][filIdx].id == hash) {
					found = 1;
					containingAGG = i;
					break;
				}
			}
		}
		if(found)
			break;
	}
	if(!found) {
		sprintf(
			gText,
			"ResMgr::PointToFile failure!  ThisFileId:%d  LastFileId:%d  LastFileName:%s",
			hash,
			this->fileID,
			this->resourceToLoad);
		ShutDown(gText);
	}
	return this->aggContentInfo[containingAGG][filIdx].length;
}

void resourceManager::SavePosition() {
	lastPositionZ[iSaveCtr] = _tell(this->fileDescriptors[this->curHandleIdx]);
	lastAggZ[iSaveCtr] = this->curHandleIdx;
	iSaveCtr++;
}

void resourceManager::RestorePosition() {
	--iSaveCtr;
	this->curHandleIdx = lastAggZ[iSaveCtr];
	_lseek(this->fileDescriptors[this->curHandleIdx], lastPositionZ[iSaveCtr], SEEK_SET);
}

short resourceManager::ReadWord() {
	__int16 w;
	ASSERT(this->fileDescriptors[this->curHandleIdx] != -1);
	_read(this->fileDescriptors[this->curHandleIdx], &w, sizeof(__int16));
	return w;
}

long resourceManager::ReadLong() {
	int n;
	ASSERT(this->fileDescriptors[this->curHandleIdx] != -1);
	_read(this->fileDescriptors[this->curHandleIdx], &n, sizeof(int));
	return n;
}

unsigned long resourceManager::MakeId(char* filename, int allowEvil) {
  strcpy(this->resourceToLoad, filename);
	this->fileID = MAKEFILEID(this->resourceToLoad);
	return this->fileID;
}

void resourceManager::Read13(signed char* buf) {
	ReadBlock(buf, MAX_FILENAME_LENGTH);
}

void resourceManager::ReadBlock(signed char* buf, unsigned long n) {
	ASSERT(this->fileDescriptors[this->curHandleIdx] != -1);
	PollSound();

	int nread = _read(this->fileDescriptors[this->curHandleIdx], buf, n);

	if(nread != n) {
		int* err = _errno();
		sprintf(
			gText,
			"File error - bytes read %d, bytes requested %d, errno %d, last file '%s'",
			nread,
			n,
			*err,
			this->resourceToLoad);
		LogStr(gText);
	}
	PollSound();
}

unsigned long __fastcall MAKEFILEID(char *str) {
  std::string tmp(str);
  int v2 = 0;
  unsigned __int32 fileID = 0;
  for (int i = strlen(str) - 1; i >= 0; i--) {
    char c = tmp[i];
    if (c >= 'a' && c <= 'z')
      tmp[i] = toupper(c);
    v2 += tmp[i];
    fileID = v2 + tmp[i] + 32 * fileID + (fileID >> 25);
  }
  return fileID;
}
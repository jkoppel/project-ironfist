#include "adventure/map.h"
#include "editor/editor.h"

#include "base.h"

extern unsigned __int16 gpRumorIndices[];
extern unsigned __int16 gpEventDataIndices[];
extern int __fastcall HasExtraObjectData(int);

void __fastcall DeleteExtraObjectData(unsigned int idx) {
    delete gpEditManager->mapExtra[idx];

    if (gpEditManager->nMapExtra > idx + 1) {
        memmove(
            &gpEditManager->mapExtra[idx],
            &gpEditManager->mapExtra[idx + 1],
            sizeof(void*) * (gpEditManager->nMapExtra - (idx + 1)));

        memmove(
            &gpEditManager->lenMapExtra[idx],
            &gpEditManager->lenMapExtra[idx + 1],
            sizeof(__int16) * (gpEditManager->nMapExtra - (idx + 1)));
    }

    gpEditManager->nMapExtra--;

    for (int i = 0; i < gpMapHeader.numRumors; i++) {
        if (gpRumorIndices[i] >= idx) {
            gpRumorIndices[i]--;
        }
    }

    for (int i = 0; i < gpMapHeader.numEvents; i++) {
        if (gpEventDataIndices[i] >= idx) {
            gpEventDataIndices[i]--;
        }
    }

    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            mapCell *cell = &gpMap.tiles[j * gpMap.width + i];
            if (HasExtraObjectData(cell->objType) && cell->extraInfo >= idx) {
                cell->extraInfo--;
            }
        }
    }
}
#include "adventure/map.h"

int MapCellVisible(int x, int y, int player) {
    return (mapRevealed[y * MAP_WIDTH + x] & (1 << player)) != 0;
}

void RevealMapCell(int x, int y, int player) {
    mapRevealed[y * MAP_WIDTH + x] |= (1 << player);
}
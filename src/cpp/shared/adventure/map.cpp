#include "adventure/map.h"

int MapCellVisible(int x, int y, int player) {
    return (mapRevealed[y * MAP_WIDTH + x] & (1 << player)) != 0;
}

void RevealMapCell(int x, int y, int player) {
    mapRevealed[y * MAP_WIDTH + x] |= (1 << player);
}

static const int MAP_CELL_TILE_FLIP_MASK = MAP_CELL_FLIP_HORIZONTALLY | MAP_CELL_FLIP_VERTICALLY;

void mapCell::SetTileFlip(__int8 flip) {
  this->flags = (this->flags & ~MAP_CELL_TILE_FLIP_MASK) | flip;
}
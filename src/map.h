#pragma once
#include "tile.h"

typedef struct {
    int rows;
    int cols;
    tile_t **tiles;
} map_t;

map_t *generate_map(int rows, int cols);
void print_map(map_t *map);
void destroy_map(map_t *map);

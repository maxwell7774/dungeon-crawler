#pragma once
#include "player.h"
#include "tile.h"
#include "enemy.h"

typedef struct {
    int rows;
    int cols;
    tile_t **tiles;
    int enemies_count;
    int enemies_capacity;
    enemy_t *enemies;
    player_t *player;
} map_t;

map_t *generate_map(int rows, int cols);
void print_map(map_t *map);
void destroy_map(map_t *map);
void spawn_enemies(map_t *map);

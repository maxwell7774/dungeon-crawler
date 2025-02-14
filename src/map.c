#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "enemy.h"
#include "tile.h"

map_t *generate_map(int rows, int cols) {
    map_t *map = malloc(sizeof(map_t));
    if(map == NULL) {
        return NULL;
    }

    map->rows = rows;
    map->cols = cols;
    map->enemies_capacity = 10;
    map->enemies_count = 0;

    enemy_t *enemies = malloc(sizeof(enemy_t));
    if(enemies == NULL) {
        free(map);
        return NULL;
    }

    printf("MAP CREATED\n");
    tile_t **tiles = malloc(rows * sizeof(tile_t *));
    if(tiles == NULL) {
        free(map);
        return NULL;
    }
    srand(time(NULL));
    
    for(int i = 0; i < rows; i++) {
        tile_t *row = malloc(cols * sizeof(tile_t));
        if(row == NULL) {
            for(int j = 0; j < i; j++) {
                free(tiles[j]);
            }
            free(tiles);
            free(map);
            return NULL;
        }
        for(int j = 0; j < cols; j++) {
            if(i == 0 || i == rows-1 || j == 0 || j == cols-1) {
                row[j].is_wall = true;
                row[j].sprite = 'O';
            }
            else {
                int random = rand() % 11;
                if(random < 2) {
                    row[j].is_wall = true;
                    row[j].sprite = 'O';
                }
                else {
                    random = rand() % 4;
                    row[j].is_wall = false;
                    row[j].sprite = ' ';
                }
            }
        }
        tiles[i] = row;
    }

    map->tiles = tiles;

    return map;
}

void spawn_enemies(map_t *map) {
    for(int i = 0; i < map->rows; i++) {
        for(int j = 0; j < map->cols; j++) {
            int random = rand() % 6;
            if(random < 3) {
                enemy_t enemy = {
                    .x = j,
                    .y = i,
                    .sprite = 'Z',
                    .health = 20,
                    .attack = 5,
                    .defense = 7,
                    .type = ZOMBIE
                };

                if(map->enemies_count == map->enemies_capacity) {
                    map->enemies_capacity *= 2;
                    enemy_t *enemies = realloc(map->enemies, map->enemies_capacity * sizeof(enemy_t));
                    if(enemies == NULL) {
                        destroy_map(map);
                    }
                    map->enemies = enemies;
                }
                map->enemies[map->enemies_count] = enemy;
                map->enemies_count++;
            }
        }
    }
}

void print_map(map_t *map) {
    for(int i = 0; i < map->rows; i++) {
        for(int j = 0; j < map->cols; j++) {
            printf("%c", map->tiles[i][j].sprite);
            if(j != map->cols-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void destroy_map(map_t *map) {
    for(int i = 0; i < map->rows; i++) {
        free(map->tiles[i]);
    }
    free(map->tiles);
    free(map->enemies);
    free(map->player);
    free(map);
    printf("MAP DESTROYED");
}

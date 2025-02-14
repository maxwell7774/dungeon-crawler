#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "tile.h"

map_t *generate_map(int rows, int cols) {
    map_t *map = malloc(sizeof(map_t));
    if(map == NULL) {
        return NULL;
    }

    map->rows = rows;
    map->cols = cols;

    printf("MAP CREATED\n");
    tile_t **tiles = malloc(rows * sizeof(tile_t *));
    if(tiles == NULL) {
        free(map);
        return NULL;
    }
    
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
                row[j].is_wall = false;
                row[j].sprite = ' ';
            }
        }
        tiles[i] = row;
    }

    map->tiles = tiles;

    return map;
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
    free(map);
    printf("MAP DESTROYED");
}

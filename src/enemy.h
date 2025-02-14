#pragma once

typedef enum {
    ZOMBIE,
    SKELETON,
} enemy_type_t;

typedef struct {
    int x;
    int y;
    int health;
    int attack;
    int defense;
    char sprite;
    enemy_type_t type;
} enemy_t;

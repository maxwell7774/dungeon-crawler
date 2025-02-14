#include "map.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Welcome to my dungeon crawler!\n");

    map_t *map = generate_map(5, 10);
    print_map(map);

    bool is_running = false;
    while(is_running) {

    }

    return 0;
}
